//---------------------------------------------------------------------------*
//                                                                           *
//                      File 'goil_code_generation.h'                        *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                      june 12th, 2009, at 14h47'14"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_code_generation_DEFINED
#define goil_code_generation_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/C_GGS_Object.h"
#include "galgas/GGS_location.h"
#include "galgas/GGS_lbool.h"
#include "galgas/GGS_lchar.h"
#include "galgas/GGS_lstring.h"
#include "galgas/GGS_ldouble.h"
#include "galgas/GGS_luint.h"
#include "galgas/GGS_lsint.h"
#include "galgas/GGS_luint64.h"
#include "galgas/GGS_lsint64.h"
#include "galgas/GGS_stringset.h"
#include "galgas/GGS_binaryset.h"
#include "galgas/GGS_filewrapper.h"
#include "galgas/predefined_types.h"
#include "galgas/AC_galgas_class.h"
#include "galgas/AC_galgas_domain.h"
#include "galgas/AC_galgas_mapindex.h"
#include "galgas/AC_galgas_map.h"
#include "galgas/AC_galgas_listmap.h"
#include "galgas/AC_galgas_list.h"
#include "galgas/AC_galgas_sortedlist.h"

//---------------------------------------------------------------------------*

#include "galgas/C_Lexique.h"

// Include imported semantics
#include "cfg_types.h"
#include "config_type.h"
#include "goil_app_generation.h"
#include "goil_code_msg_gen.h"
#include "goil_code_schedtable_gen.h"
#include "goil_env_verification.h"
#include "goil_mp_generation.h"
#include "goil_options.h"
#include "goil_proc_generation.h"
#include "goil_routines.h"
#include "goil_semantic_types.h"
#include "goil_targets.h"
#include "goil_types_app.h"
#include "goil_types_os.h"
#include "goil_types_task.h"
#include "it_table_generation.h"
#include "trace_description.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                         Routine 'init_prefixes'                           *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_init_prefixes (C_Compiler &,
                                GGS_prefix_map  & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                         Routine 'generate_flags'                          *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_flags (C_Compiler &,
                                const GGS_os_config  ,
                                GGS_os_obj  ,
                                GGS_task_map  ,
                                GGS_isr_map  ,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                    Function 'trampoline_target_name'                      *
//                                                                           *
//---------------------------------------------------------------------------*

GGS_string function_trampoline_target_name (C_Compiler & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                  Routine 'updateTemplateWithStringList'                   *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_updateTemplateWithStringList (C_Compiler &,
                                const GGS_lstringlist  ,
                                const GGS_string ,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       Routine 'generate_makefile'                         *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_makefile (C_Compiler &,
                                GGS_os_obj  ,
                                GGS_string ,
                                GGS_string  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      Routine 'generate_signed_type'                       *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_signed_type (C_Compiler &,
                                GGS_uint64  ,
                                GGS_string ,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                     Routine 'generate_unsigned_type'                      *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_unsigned_type (C_Compiler &,
                                GGS_uint64  ,
                                GGS_string ,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       Routine 'generate_mask_type'                        *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_mask_type (C_Compiler &,
                                GGS_uint64  ,
                                GGS_string ,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                         Routine 'generate_types'                          *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_types (C_Compiler &,
                                GGS_task_map  ,
                                GGS_isr_map  ,
                                GGS_alarm_map  ,
                                GGS_counter_map  ,
                                GGS_resource_map  ,
                                GGS_scheduletable_map  ,
                                GGS_app_map  ,
                                GGS_uint  ,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      Routine 'generate_timing_prot'                       *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_timing_prot (C_Compiler &,
                                GGS_task_map  ,
                                GGS_resource_map  ,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                        Routine 'generate_alarms'                          *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_alarms (C_Compiler &,
                                GGS_alarm_map  ,
                                GGS_string_map  ,
                                GGS_string &,
                                GGS_string &,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                  Routine 'compute_actual_task_priority'                   *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_compute_actual_task_priority (C_Compiler &,
                                GGS_task_map  ,
                                GGS_prio_map  &,
                                GGS_uint  & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                  Routine 'compute_actual_isr_priority'                    *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_compute_actual_isr_priority (C_Compiler &,
                                GGS_isr_map  ,
                                GGS_prio_map  &,
                                GGS_uint  ,
                                GGS_uint  & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      Routine 'compute_rez_priority'                       *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_compute_rez_priority (C_Compiler &,
                                GGS_resource_map  ,
                                GGS_task_map  ,
                                GGS_prio_map  ,
                                GGS_isr_map  ,
                                GGS_prio_map  ,
                                GGS_prio_map  &,
                                GGS_string_map  & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       Routine 'compute_ready_list'                        *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_compute_ready_list (C_Compiler &,
                                GGS_prio_map  ,
                                GGS_prio_map  ,
                                GGS_prio_map  ,
                                GGS_uint  ,
                                GGS_uint  ,
                                GGS_prio_list  & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      Routine 'compute_app_for_obj'                        *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_compute_app_for_obj (C_Compiler &,
                                GGS_app_map  ,
                                GGS_string_map  & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                         Routine 'generate_tasks'                          *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_tasks (C_Compiler &,
                                GGS_config  ,
                                GGS_task_map  ,
                                GGS_app_map  ,
                                GGS_resource_map  ,
                                GGS_prio_map  ,
                                GGS_string_map  ,
                                GGS_string &,
                                GGS_string &,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                         Routine 'generate_isrs'                           *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_isrs (C_Compiler &,
                                GGS_config  ,
                                GGS_isr_map  ,
                                GGS_app_map  ,
                                GGS_resource_map  ,
                                GGS_prio_map  ,
                                GGS_string_map  ,
                                GGS_string &,
                                GGS_string &,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       Routine 'generate_counters'                         *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_counters (C_Compiler &,
                                GGS_counter_map  ,
                                GGS_string_map  ,
                                GGS_string &,
                                GGS_string &,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       Routine 'generate_resources'                        *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_resources (C_Compiler &,
                                GGS_resource_map  ,
                                GGS_prio_map  ,
                                GGS_string_map  ,
                                GGS_string_map  ,
                                GGS_string &,
                                GGS_string &,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                        Routine 'generate_events'                          *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_events (C_Compiler &,
                                GGS_event_map  ,
                                GGS_task_map  ,
                                GGS_string &,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      Routine 'generate_ready_list'                        *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_ready_list (C_Compiler &,
                                GGS_os_obj  ,
                                GGS_uint  ,
                                GGS_prio_list  ,
                                GGS_string &,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                          Routine 'generate_all'                           *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_all (C_Compiler &,
                                const GGS_root_obj   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*

#endif