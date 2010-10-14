#include "tpl_os.h"
#include "tpl_app_config.h"

FUNC(int, AUTOMATIC) main()
{
//		tpl_disable_interrupts ();
		serial_init();
		serial_puts ("bootstrap finished, starting Trampoline...");
		serial_puts (" GO!\n");
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}
FUNC(void, AUTOMATIC) ProtectionHook(StatusType error)
{
}

FUNC(void, AUTOMATIC) ErrorHook(StatusType error)
{
}

DeclareTask (t2);

TASK(t1)
{
	serial_puts ("t1 starts t2\n");
	ActivateTask (t2);
	serial_puts ("t1 will terminate\n");
	TerminateTask();
}

TASK(t4)
{
	serial_puts ("t4 says hello\n");
	TerminateTask ();
}

TASK(t3)
{
	serial_puts ("t3 starts t4\n");
	ActivateTask (t4);
	serial_puts ("t3 will terminate\n");
	TerminateTask ();
}

TASK(t2)
{
	serial_puts ("t2 starts t3\n");
	ActivateTask (t3);
	serial_puts ("t2 will terminate\n");
	TerminateTask ();
}

