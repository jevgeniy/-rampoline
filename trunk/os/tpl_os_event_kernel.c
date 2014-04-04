/**
 * @file tpl_os_event_kernel.c
 *
 * @section desc File description
 *
 * Trampoline Event Management implementation file
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Copyright ESEO for function and data structures documentation
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os_definitions.h"
#include "tpl_os_error.h"
#include "tpl_os_errorhook.h"
#include "tpl_os_kernel.h"
#include "tpl_os_task_kernel.h"
#include "tpl_machine_interface.h"
#include "tpl_trace.h"

#if WITH_AUTOSAR == YES
#include "tpl_as_isr_kernel.h"
#include "tpl_as_protec_hook.h"
#endif

#if WITH_MEMORY_PROTECTION == YES
#include "tpl_os_mem_prot.h"
#endif

#include "tpl_os_event_kernel.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * tpl_set_event_service.
 */
FUNC(tpl_status, OS_CODE) tpl_set_event_service(
  CONST(tpl_task_id, AUTOMATIC)       task_id,
  CONST(tpl_event_mask, AUTOMATIC)    event)
{
  GET_CURRENT_CORE_ID(core_id)
  GET_PROC_CORE_ID(task_id, proc_core_id)

  VAR(tpl_status, AUTOMATIC) result = E_OK;
	
  LOCK_KERNEL()
	
  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)
	
  STORE_SERVICE(OSServiceId_SetEvent)
  STORE_TASK_ID(task_id)
  STORE_EVENT_MASK(event)
  
  CHECK_TASK_ID_ERROR(task_id,result)
	
  /* check access right */
  CHECK_ACCESS_RIGHTS_TASK_ID(core_id, task_id,result)

  /*  checks the task is an extended one  */
  CHECK_NOT_EXTENDED_TASK_ERROR(task_id,result)
  /*  checks the task is not in the SUSPENDED state   */
  CHECK_SUSPENDED_TASK_ERROR(task_id,result)
  
#if EXTENDED_TASK_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  result = tpl_set_event(task_id, event);
  if (result == E_OK && TPL_KERN(proc_core_id).need_schedule)
  {
    tpl_schedule_from_running(CORE_ID_OR_NOTHING(proc_core_id));
    SWITCH_CONTEXT(CORE_ID_OR_NOTHING(proc_core_id))
  }
  IF_NO_EXTENDED_ERROR_END()
#endif
  
  PROCESS_ERROR(result)
  
  UNLOCK_KERNEL()
  
  return result;
}


/*
 * tpl_clear_event_service
 */
FUNC(tpl_status, OS_CODE) tpl_clear_event_service(
  CONST(tpl_event_mask, AUTOMATIC) event)
{
  VAR(tpl_status, AUTOMATIC) result = E_OK;
  
  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)
  
  STORE_SERVICE(OSServiceId_ClearEvent)
  STORE_EVENT_MASK(event)

  /*  ClearEvent cannot be called from ISR level  */
  CHECK_TASK_CALL_LEVEL_ERROR(result)
  /*  checks the calling task is an extended one  */
  CHECK_NOT_EXTENDED_RUNNING_ERROR(result)
  
#if EXTENDED_TASK_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
    tpl_task_events_table[tpl_kern.running_id]->evt_set &=
      (tpl_event_mask)(~event);
  IF_NO_EXTENDED_ERROR_END()
#endif

  PROCESS_ERROR(result)
  
  UNLOCK_KERNEL()
  
  return result;
}

/*
 * tpl_get_event_service
 */
FUNC(tpl_status, OS_CODE) tpl_get_event_service(
  CONST(tpl_task_id, AUTOMATIC)                       task_id,
  CONSTP2VAR(tpl_event_mask, AUTOMATIC, OS_APPL_DATA) event)
{
  GET_CURRENT_CORE_ID(core_id)

  VAR(tpl_status, AUTOMATIC) result = E_OK;
  
  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  STORE_SERVICE(OSServiceId_GetEvent)
  STORE_TASK_ID(task_id)
  STORE_EVENT_MASK_REF(event)
  
  CHECK_TASK_ID_ERROR(task_id,result)
  	
  /* check access right */
  CHECK_ACCESS_RIGHTS_TASK_ID(core_id, task_id, result)
	
  /*  checks the task is an extended one  */
  CHECK_NOT_EXTENDED_TASK_ERROR(task_id,result)
  /*  checks the task is not in the SUSPENDED state   */
  CHECK_SUSPENDED_TASK_ERROR(task_id,result)
  
  /* check event is in an authorized memory region */
  CHECK_DATA_LOCATION(event, result);
  
#if EXTENDED_TASK_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  *event = tpl_task_events_table[task_id]->evt_set;
  IF_NO_EXTENDED_ERROR_END()
#endif
  
  PROCESS_ERROR(result)
  
  UNLOCK_KERNEL()
  
  return result;
}

/*
 * tpl_wait_event_service
 */
FUNC(tpl_status, OS_CODE) tpl_wait_event_service(
  CONST(tpl_event_mask, AUTOMATIC) event)
{
  GET_CURRENT_CORE_ID(core_id)

  VAR(tpl_status, AUTOMATIC) result = E_OK;

  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  STORE_SERVICE(OSServiceId_WaitEvent)
  STORE_EVENT_MASK(event)
  
  /*  WaitEvent cannot be called from ISR level  */
  CHECK_TASK_CALL_LEVEL_ERROR(result)
  /*  checks the calling task is an extended one  */
  CHECK_NOT_EXTENDED_RUNNING_ERROR(result)
  /*  checks the task does not occupied resource(s)   */
  CHECK_RUNNING_OWNS_REZ_ERROR(core_id, result)
  
#if EXTENDED_TASK_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  
  /* all the evt_wait is overidden. */
  tpl_task_events_table[TPL_KERN(core_id).running_id]->evt_wait = event;
  /* block the task if needed */
  tpl_block();

  IF_NO_EXTENDED_ERROR_END()
#endif

  PROCESS_ERROR(result)
  
  UNLOCK_KERNEL()
  
  return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_event_kernel.c */
