/**
 * @file tpl_as_action.c
 *
 * @section descr File description
 *
 * Trampoline autosar extension. extra action to increment
 * a counter. Implementation
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 *
 */

#include "tpl_as_action.h"
#include "tpl_os_alarm_kernel.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

#include <stdio.h>

/**
 *  action function for action by incrementing counter
 */
FUNC(tpl_status, OS_CODE) tpl_action_increment_counter(
    P2CONST(tpl_action, AUTOMATIC, OS_APPL_CONST) action)
{
    /*
     * A tpl_action * is cast to a tpl_increment_counter_action *
     * This violate MISRA rule 45. However, since the
     * first member of tpl_increment_counter_action is a tpl_action
     * This cast behaves correctly.
     */
    return tpl_counter_tick(
        ((const tpl_increment_counter_action *)action)->counter
    );
}

/**
 *  action function for action by finalizing the scheduletable
 *
 *  The schedule table is finished                                 
 *  Test whether a schedule table has been nextified or not     
*/
FUNC(tpl_status, OS_CODE) tpl_action_finalize_schedule_table(
	P2CONST(tpl_action, AUTOMATIC, OS_APPL_CONST) action)
{
	/*
	 * A tpl_action * is cast to a tpl_finalize_schedule_table_action *
	 * This violate MISRA rule 45. However, since the
	 * first member of tpl_finalize_schedule_table_action is a tpl_action
	 * This cast behaves correctly.
	 */
	P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) st =
		&(((P2CONST(tpl_finalize_schedule_table_action, AUTOMATIC, OS_APPL_CONST))action)->schedule_table->b_desc);		
	
	P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA) schedtable =
		(P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA))st->stat_part;
	
	/*  MISRA RULE 45 VIOLATION: a tpl_time_obj* is cast to a
	 tpl_schedtable*. This cast behaves correctly because the
	 first member of tpl_schedula_table is a tpl_time_obj            */
	P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA) next =
		((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->next;
	
	/*  Process the current expiry point                                    */
    VAR(tpl_status, AUTOMATIC) need_resched = NO_SPECIAL_CODE;
		
	P2VAR(tpl_action, AUTOMATIC, OS_APPL_DATA)  action_desc;
    VAR(tpl_action_count, AUTOMATIC)  i;
	
	VAR(tpl_tick, AUTOMATIC) before;
	
	/*  Get the remaining time to fill the current schedule table
	 period. This time is stored in the offset of the first expiry
	 point                                                           */
	before = (schedtable->expiry)[0]->offset;
	
	/*  Reset the cycle of the time object                                  */
	st->cycle = 0;
	
	/*  Reset the index                                                 */
	/*  MISRA RULE 45 VIOLATION: a tpl_time_obj* is cast to a
	 tpl_schedtable*. This cast behaves correctly because the
	 first memberof tpl_schedule_table is a tpl_time_obj             */
	((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->index = 0;
	
	if (next != NULL) {
		/*  Get the next expiry point                                        */
		P2VAR(tpl_expiry_point, AUTOMATIC, OS_APPL_DATA) next_ep =
			((P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA))next->b_desc.stat_part)->expiry[0];

		/*  reset the state of the current schedule table               */
		st->state = SCHEDULETABLE_STOPPED;
		
		/*  There is a next schedule table set, start it                */
		next->b_desc.date = next->b_desc.stat_part->counter->current_date + before;
		
		/* if first expiry point in the next ST is at offset=0, launch it directly  */
		if(next_ep->offset == 0)
		{
			/*launch all the actions of the expiry point*/
			for (i = 0; i < next_ep->count; i++)
			{
				action_desc = (next_ep->actions)[i];
				need_resched |= TRAMPOLINE_STATUS_MASK & (action_desc->action)(action_desc);
			}
			
			/*should do a synchronisation if needed*/
			
			/*Increment index because the first one has just been launched*/
			next->index = 1;
		}
		
		/*  MISRA RULE 45 VIOLATION: a tpl_schedtable* is cast to a
		 tpl_time_obj*. This cast behaves correctly because the
		 first member of tpl_schedule_table is a tpl_time_obj            */
		((tpl_time_obj *)next)->state = SCHEDULETABLE_RUNNING;
		tpl_insert_time_obj((tpl_time_obj *)next);
	}
	else if (schedtable->periodic == TRUE) {
		/*  No next schedule table but the current table is periodic    */
		st->cycle = before;
		
		/* if first expiry point in the next ST is at offset=0, launch it directly  */
		if(schedtable->expiry[0]->offset == 0)
		{
			/*launch all the actions of the expiry point*/
			for (i = 0; i < schedtable->expiry[0]->count; i++)
			{
				action_desc = (schedtable->expiry[0]->actions)[i];
				need_resched |= TRAMPOLINE_STATUS_MASK & (action_desc->action)(action_desc);
			}
			
			/*should do a synchronisation if needed*/
			/* reset the offset of last expiry point to its default value,
			 because adjustment for synchronisation of this expiry point has been done */
			(schedtable->expiry)[schedtable->expiry[0]->count]->sync_offset = (schedtable->expiry)[schedtable->expiry[0]->count]->offset;
			
			/*Increment index because the first one has just been launched*/
			((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->index = 1;
			
			/*  if offset=0, save the next offset in cycle */
			st->cycle = schedtable->expiry[1]->offset;
		}
	}
	else {
		/*  reset the state of the current schedule table               */
		st->state = SCHEDULETABLE_STOPPED;
	}
	
	return need_resched;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_as_action.c */