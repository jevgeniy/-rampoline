/**
 * @file tpl_os_internal_types.h
 *
 * @section descr File description
 *
 * Trampoline internal types. These types are not intended
 * to be used in an application.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
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

#ifndef TPL_OS_INTERNAL_TYPES_H
#define TPL_OS_INTERNAL_TYPES_H

#include "tpl_os_std_types.h"
#include "tpl_os_custom_types.h"
#include "tpl_machine.h"
#include "tpl_compiler.h"

/**
 * @typedef tpl_task_id
 *
 * tpl_task_id is an alias of tpl_proc_id.
 * -1 means INVALID_TASK
 */
typedef tpl_proc_id tpl_task_id ;

/**
 * @typedef tpl_isr_id
 *
 * tpl_isr_id is an alias of tpl_proc_id.
 * -1 means INVALID_ISR
 */
typedef tpl_proc_id tpl_isr_id ;

#ifdef WITH_AUTOSAR
/**
 * @typedef tpl_counter_kind
 *
 * Kind (hardware or software) of a counter
 */
typedef u8 tpl_counter_kind;
#endif

/**
 * @typedef tpl_bool
 *
 * Standard bool declaration. Values can be #TRUE or #FALSE.
 */
typedef u8 tpl_bool;

/**
 * @typedef tpl_status
 *
 * This type is used for return
 * status of services (ie one of the result
 * codes specified below).
 *
 * It is binary compatible with OSEK StatusType, provided
 * Trampoline specific codes are removed (via #OSEK_STATUS_MASK
 * AND-mask).
 *
 * @see #OSEK_STATUS_MASK
 * @see #StatusType
 */
typedef u8 tpl_status;

/**
 * @typedef tpl_proc_state
 *
 * This type represents the state of a task or ISR2.
 *
 * See page 16+ of the OSEK/VDX 2.2.2 spec
 *
 * Value can be one of :
 * - #AUTOSTART
 * - #RUNNING
 * - #READY
 * - #SUSPENDED
 * - #WAITING (only for ECC1 or ECC2 conformance classes)
 * but also :
 * - #READY_AND_NEW that means a task is in the ready list before running
 *   for the first time and its context needs to be initialized.
 */
typedef u8 tpl_proc_state;

/**
 * @struct ALARM_BASE_TYPE
 *
 * This structure is defined as paragraph 13.6.1 of OSEK/VDX spec
 *
 * @see AlarmBaseType
 */
struct ALARM_BASE_TYPE {
    VAR(tpl_tick, TYPEDEF)  maxallowedvalue; /**< maximum possible allowed
                                                  count values in tick        */
    VAR(tpl_tick, TYPEDEF)  ticksperbase;    /**< number of ticks required to
                                                  reach a counter-specific
                                                  (significant) unit          */
    VAR(tpl_tick, TYPEDEF)  mincycle;        /**< smallest allowed value for
                                                  the cycle parameter of
                                                  SetRelAlarm/SetAbsAlarm
                                                  (only for systems with
                                                  extended status)            */
};

/**
 * @typedef tpl_alarm_base
 *
 * This is an alias for the structure #ALARM_BASE_TYPE
 *
 * @see #ALARM_BASE_TYPE
 * @see #AlarmBaseType
 */
typedef struct ALARM_BASE_TYPE tpl_alarm_base;

/**
 * @typedef tpl_application_mode
 *
 * Identifies an application mode
 *
 * @see #AppModeType
 */
typedef u8 tpl_application_mode;

/**
 * @typedef tpl_callback_func
 *
 * This type is used for various
 * callback function type in Trampoline.
 */
typedef P2FUNC(void, OS_APPL_CODE, tpl_callback_func)(void);

#endif /* TPL_OS_INTERNAL_TYPES_H */

/* End of file tpl_os_internal_type.h */
