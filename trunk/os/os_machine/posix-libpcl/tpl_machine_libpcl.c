/*
 * Trampoline OS
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline posix signals and libpcl process machine dependent stuffs
 *
 */

#include "tpl_machine.h"
#include "tpl_os_generated_configuration.h"
#include "tpl_os_internal_types.h"
#include "tpl_viper_interface.h"
#include "tpl_os_it_kernel.h"
#include "tpl_os.h"
#include "tpl_machine_interface.h"
#include "tpl_os_application_def.h" /* define NO_ISR if needed. */
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
#include "tpl_as_timing_protec.h"
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#ifdef WITH_AUTOSAR
#include "tpl_as_isr_kernel.h"
#include "tpl_os_kernel.h" /* for tpl_running_obj */
#endif /* WITH_AUTOSAR */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <pcl.h>
#include <assert.h>
#include <sched.h>
#include <pcl.h>

tpl_context idle_task_context = 0;

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
static tpl_watchdog_expire_function tpl_watchdog_callback;

static struct timeval startup_time;

tpl_time tpl_get_local_current_date ()
{
  struct timeval time;
  tpl_time result;
  
  gettimeofday (&time, NULL);
  result = ((time.tv_sec - startup_time.tv_sec) % 2000) * (1000 * 1000) + 
     (time.tv_usec - startup_time.tv_usec);
  
  return result;
}

void tpl_set_watchdog (tpl_time delay, tpl_watchdog_expire_function function)
{
  struct itimerval timer;
  
  /* prepare callback reference */
  tpl_watchdog_callback = function;
  
  /* configure and start the timer */
  timer.it_value.tv_sec = delay / (1000 * 1000);
  timer.it_value.tv_usec = delay % (1000 * 1000);
  timer.it_interval.tv_sec = delay / (1000 * 1000);
  timer.it_interval.tv_usec = delay % (1000 * 1000);
  setitimer (ITIMER_REAL, &timer, NULL);
}

void tpl_cancel_watchdog ()
{
  struct itimerval timer;
  
  /* remove the callback */
  tpl_watchdog_callback = NULL;
  
  /* disable the timer */
  timer.it_value.tv_sec = 0;
  timer.it_value.tv_usec = 0;
  timer.it_interval.tv_sec = 1;
  timer.it_interval.tv_usec = 0;
  setitimer (ITIMER_REAL, &timer, NULL);
}
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */

#ifdef WITH_AUTOSAR_STACK_MONITORING
u8 tpl_check_stack_pointer (tpl_exec_common *this_exec_obj)
{
  return 1;
}

u8 tpl_check_stack_footprint (tpl_exec_common *this_exec_obj)
{
  return 1;
}
#endif /* WITH_AUTOSAR_STACK_MONITORING */

/*
 * table which stores the signals used for interrupt
 * handlers.
 */
#ifndef NO_ISR
	extern int signal_for_isr_id[ISR_COUNT];
#endif
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  const int signal_for_watchdog = SIGALRM;
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#if (defined WITH_AUTOSAR && !defined NO_SCHEDTABLE) || (!defined NO_ALARM)
	const int signal_for_counters = SIGUSR2;
#endif

/*
 * The signal set corresponding to the enabled interrupts
 */
sigset_t    signal_set;

/** fonction that calls the system function tpl_counter_tick() 
 * for each counter declared in the application.
 * tpl_call_counter_tick() is application dependant and is 
 * generated by the OIL compiler (goil).
 */
void tpl_call_counter_tick();


volatile static u32 tpl_locking_depth = 0;
static sigset_t tpl_saved_state;
/**
 * Enable all interrupts
 *
 * see paragraph 13.3.2.1 page 54 of OSEK/VDX 2.2.2 spec
 *
 * @see #DisableAllInterrupts
 */
void EnableAllInterrupts(void)
{
    if (sigprocmask(SIG_SETMASK,&tpl_saved_state,NULL) == -1)
    {
        perror("EnableAllInterrupts failed");
        exit(-1);
    }
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    tpl_disable_all_isr_lock_monitor (tpl_running_obj);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
}

/**
 * Disable all interrupts
 *
 * see paragraph 13.3.2.2 page 55 of OSEK/VDX 2.2.2 spec
 *
 * @see #EnableAllInterrupts
 */
void DisableAllInterrupts(void)
{
    if (sigprocmask(SIG_BLOCK,&signal_set,&tpl_saved_state) == -1)
    {
        perror("DisableAllInterrupts failed");
        exit(-1);
    }
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    tpl_start_all_isr_lock_monitor (tpl_running_obj);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
}

/** 
 * Resume all interrupts
 *
 * see paragraph 13.3.2.3 page 55 of OSEK/VDX 2.2.2 spec
 *
 * @see #SuspendAllInterrupts
 */
void ResumeAllInterrupts(void)
{
    tpl_locking_depth--;
    
    if (tpl_locking_depth == 0)
    {
        if (sigprocmask(SIG_UNBLOCK,&signal_set,NULL) == -1)
        {
            perror("ResumeAllInterrupts failed");
            exit(-1);
        }
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
        tpl_disable_all_isr_lock_monitor (tpl_running_obj);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
    }
}

/**
 * Suspend all interrupts
 *
 * see paragraph 13.3.2.4 page 56 of OSEK/VDX 2.2.2 spec
 *
 * @see #ResumeAllInterrupts
 */
void SuspendAllInterrupts(void)
{
    if (sigprocmask(SIG_BLOCK,&signal_set,NULL) == -1)
    {
        perror("SuspendAllInterrupts failed");
        exit(-1);
    }
    
    
    tpl_locking_depth++;
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    if (tpl_locking_depth == 1)
    {
      tpl_start_all_isr_lock_monitor (tpl_running_obj);
    }
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
}

/** 
 * Resume category 2 interrupts
 *
 * see paragraph 13.3.2.5 page 56 of OSEK/VDX 2.2.2 spec
 * 
 * @see #SuspendOSInterrupts
 */
void ResumeOSInterrupts(void)
{
    tpl_locking_depth--;
    
    if (tpl_locking_depth == 0)
    {
        if (sigprocmask(SIG_UNBLOCK,&signal_set,NULL) == -1)
        {
            perror("ResumeAllInterrupts failed");
            exit(-1);
        }
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
        tpl_disable_os_isr_lock_monitor (tpl_running_obj);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
    }
}

/**
 * Suspend category 2 interrupts
 *
 * see paragraph 13.3.2.6 page 57 of OSEK/VDX 2.2.2 spec
 *
 * @see #ResumeOSInterrupts
 */
void SuspendOSInterrupts(void)
{
    if (sigprocmask(SIG_BLOCK,&signal_set,NULL) == -1)
    {
        perror("SuspendAllInterrupts failed");
        exit(-1);
    }
    
    tpl_locking_depth++;
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    if (tpl_locking_depth == 1)
    {
      tpl_start_os_isr_lock_monitor (tpl_running_obj); 
    }
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
}

/*
 * The signal handler used when interrupts are enabled
 */
void tpl_signal_handler(int sig)
{
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  struct itimerval timer;
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
  
#ifndef NO_ISR
    unsigned int id;
#endif /* NO_ISR */
#ifndef NO_ALARM
    if (signal_for_counters == sig) tpl_call_counter_tick();
#endif /* NO_ALARM */
#if (defined WITH_AUTOSAR && !defined NO_SCHEDTABLE) || (!defined NO_ALARM)
    if (signal_for_counters == sig) tpl_call_counter_tick();
#endif /*(defined WITH_AUTOSAR && !defined NO_SCHEDTABLE) || ... */
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    if (sig == SIGALRM)
    {
      /* disable the interval timer (one shot) */
      timer.it_value.tv_sec = 0;
      timer.it_value.tv_usec = 0;
      timer.it_interval.tv_sec = 1;
      timer.it_interval.tv_usec = 0;
      setitimer (ITIMER_REAL, &timer, NULL);
      
      if (tpl_watchdog_callback != NULL)
      {
        if (tpl_watchdog_callback ())
          tpl_schedule((u8)FROM_IT_LEVEL);
      }
    }    
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#ifndef NO_ISR
    for (id = 0; id < ISR_COUNT; id++)
    {
        if (signal_for_isr_id[id] == sig)
        {
            tpl_central_interrupt_handler(id);
        }
    }
#endif /* NO_ISR */
}

/*
 * tpl_sleep is used by the idle task
 */
void tpl_sleep(void)
{
    while (1) 
      sched_yield();
}

static tpl_exec_static my_tpl_sleep = {
    NULL,
    {NULL, 0},
    tpl_sleep,
    NULL,
    0,
    0,
    0,
    0,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* no timing protection
       for the idle task :D */  NULL
#endif
};

extern void viper_kill(void);

void tpl_shutdown(void)
{
	/* remove ITs */
	if (sigprocmask(SIG_BLOCK,&signal_set,NULL) == -1)
    {
        perror("tpl_shutdown failed");
        exit(-1);
    }
    
    viper_kill();
    /* sleep forever */
    exit(0);
}

volatile int x = 0;
int cnt = 0;
/*
 * tpl_get_task_lock is used to lock a critical section 
 * around the task management in the os.
 */
void tpl_get_task_lock(void)
{
    /*
     * block the handling of signals
     */
	/*  fprintf(stderr, "%d-lock\n", cnt++);*/
    if (sigprocmask(SIG_BLOCK,&signal_set,NULL) == -1)
    {
        perror("tpl_get_lock failed");
        exit(-1);
    }
    x++;
    tpl_locking_depth++;
    
    if (x > 1) printf("** lock ** X=%d\n",x);
    assert( 0 <= x && x <= 1);
}

/*
 * tpl_release_task_lock is used to unlock a critical section
 * around the task management in the os.
 */
void tpl_release_task_lock(void)
{
    x--;
    if (x < 0) printf("** unlock ** X=%d\n",x);
    assert(0 <= x && x <= 1);
    /*  fprintf(stderr, "%d-unlock\n", cnt++);*/
    
    tpl_locking_depth--;

    if (tpl_locking_depth == 0)
    {
        if (sigprocmask(SIG_UNBLOCK,&signal_set,NULL) == -1) {
            perror("tpl_release_lock failed");
            exit(-1);
        }
    }
}



void tpl_switch_context(
    tpl_context *old_context,
    tpl_context *new_context)
{
	assert( *new_context != co_current() );
    tpl_release_task_lock();  
    if( *new_context == &idle_task_context )
    {
        /* idle_task activation */
        co_call( idle_task_context );
    }
    else co_call( *new_context );
    tpl_get_task_lock(); 
}


void tpl_switch_context_from_it(
    tpl_context *old_context,
    tpl_context *new_context)
{
    assert( *new_context != co_current() );
    if( *new_context == &idle_task_context )
    {
        /* idle_task activation */
        co_call( idle_task_context );
    }
    else co_call( *new_context );
}

#define CO_MIN_SIZE (4*8*(4 * 1024))


void tpl_osek_func_stub( void* data )
{
    tpl_exec_function func = ((tpl_exec_static*)data)->entry;
    tpl_exec_obj_type type = ((tpl_exec_static*)data)->type;
  
    /* Avoid signal blocking due to a previous call to tpl_init_context in a OS_ISR2 context. */
    if (sigprocmask(SIG_UNBLOCK,&signal_set,NULL) == -1) {
        perror("tpl_osek_func_stub failed");
        exit(-1);
    }
    
    /* printf("** unlock (tpl_osek_func_stub) ** X=%d\n",x) ; */
  
    (*func)();
    
    if (type == IS_ROUTINE) {
        TerminateISR2();
    }
    else {
        fprintf(stderr, "[OSEK/VDX Spec. 2.2.3 Sec. 4.7] Ending the task without a call to TerminateTask or ChainTask is strictly forbidden and causes undefined behaviour.\n");
        exit(1);
    }
}


static coroutine_t previous_old_co = NULL;

void tpl_init_context(tpl_exec_common *exec_obj)
{
    coroutine_t old_co;
    coroutine_t* co = &(exec_obj->static_desc->context);
    tpl_stack* stack = &(exec_obj->static_desc->stack);

    /* This is the entry func passed as data */
    void* data = (void*) exec_obj->static_desc; 
    int stacksize = stack->stack_size;
    void* stackaddr = stack->stack_zone;  
  
    old_co = *co;
  
    assert( stacksize > 0 );
    assert( stackaddr != NULL );
    assert( data != NULL );
  

    if( stacksize < CO_MIN_SIZE )
    {
        /* co_create will fail if stacksize is < 4096 */
        stacksize = stacksize < CO_MIN_SIZE ? CO_MIN_SIZE : stacksize ;
    }
  
    stackaddr = NULL; /* co_create automatically allocate stack data using malloc. */  
    
    *co = co_create(tpl_osek_func_stub, data, stackaddr, stacksize);
  
    assert( *co != NULL );
    assert( *co != old_co );
  
    /* If old_co != NULL, we should garbage it soon. */
    if( old_co != NULL )
    {
        if( previous_old_co != NULL )
/*        co_delete( previous_old_co ); */
        previous_old_co = old_co;
    }
}

void quit(int n)
{
    ShutdownOS(E_OK);  
}

/*
 * tpl_init_machine init the virtual processor hosted in
 * a Unix process
 */
void tpl_init_machine(void)
{
#ifndef NO_ISR
    int id;
#endif
    
    struct sigaction sa;

    /*printf("start viper.\n");*/
    tpl_viper_init();
  
    signal(SIGINT, quit);
    signal(SIGHUP, quit);

    sigemptyset(&signal_set);
    sigemptyset(&tpl_saved_state);
    
    /*
     * init a signal mask to block all signals (aka interrupts)
     */
#ifndef NO_ISR
    for (id = 0; id < ISR_COUNT; id++) {
        sigaddset(&signal_set,signal_for_isr_id[id]);
    }
#endif
#ifndef NO_ALARM
    sigaddset(&signal_set,signal_for_counters);
#endif
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    sigaddset(&signal_set,signal_for_watchdog);
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#if (defined WITH_AUTOSAR && !defined NO_SCHEDTABLE) || (!defined NO_ALARM)
    sigaddset(&signal_set,signal_for_counters);
#endif /*(defined WITH_AUTOSAR && !defined NO_SCHEDTABLE) || ... */


    /*
     * init the sa structure to install the handler
     */
    sa.sa_handler = tpl_signal_handler;
    sa.sa_mask = signal_set;
    sa.sa_flags = SA_RESTART;
    /*
     * Install the signal handler used to emulate interruptions
     */
#ifndef NO_ISR
    for (id = 0; id < ISR_COUNT; id++) {
        sigaction(signal_for_isr_id[id],&sa,NULL);
    }
#endif
#ifndef NO_ALARM
    sigaction(signal_for_counters,&sa,NULL);
#endif
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    sigaction(signal_for_watchdog,&sa,NULL);
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#if (defined WITH_AUTOSAR && !defined NO_SCHEDTABLE) || (!defined NO_ALARM)
    sigaction(signal_for_counters,&sa,NULL);
#endif /*(defined WITH_AUTOSAR && !defined NO_SCHEDTABLE) || ... */
    
    idle_task_context = co_create( tpl_osek_func_stub, (void*)&my_tpl_sleep, NULL, CO_MIN_SIZE );
    assert( idle_task_context != NULL );
    
    /*
     * block the handling of signals
     */
    /*if (sigprocmask(SIG_BLOCK,&signal_set,NULL) == -1) {
        perror("tpl_init_machine failed");
        exit(-1);
    }
    */
#ifndef NO_ALARM
    tpl_viper_start_auto_timer(signal_for_counters,50000);  /* 50 ms */
#endif
#ifdef WITH_AUTOSAR
#ifndef NO_SCHEDTABLE
    #ifdef NO_ALARM
    tpl_viper_start_auto_timer(signal_for_counters,50000);  /* 50 ms */
    #endif
#endif
#endif

    /*
     * unblock the handling of signals
     */
    /*if (sigprocmask(SIG_UNBLOCK,&signal_set,NULL) == -1) {
        perror("tpl_init_machine failed");
        exit(-1);
    }
	*/
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    gettimeofday (&startup_time, NULL);  
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
}


