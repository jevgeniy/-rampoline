//---------------------------------------------------------------------------*
//                                                                           *
//                           File 'defaults.cpp'                             *
//                        Generated by version 1.8.3                         *
//                       june 3rd, 2009, at 15h13'4"                         *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 491
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "defaults.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "defaults.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of routine "check_custom_field"               *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_check_custom_field (C_Compiler & _inLexique,
                                GGS_ident_map  & var_cas_others,
                                GGS_lstring   var_cas_field,
                                GGS_imp_type   var_cas_f_def COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_check_custom_field at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  if (((var_cas_others.reader_hasKey (_inLexique, var_cas_field.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (39)) COMMA_SOURCE_FILE_AT_LINE (39)))._operator_not ()).isBuiltAndTrue ()) {
    { const GGS_imp_type _var_1271 = var_cas_f_def ; // CAST instruction
      if (_var_1271.getPtr () != NULL) {
        macroValidPointer (_var_1271.getPtr ()) ;
        if (typeid (cPtr_uint32_type) == typeid (* (_var_1271.getPtr ()))) {
          const GGS_uint32_type var_cas_f (_var_1271.getPtr ()) ;
          var_cas_others.modifier_put (_inLexique, var_cas_field, var_cas_f.reader_def_val (_inLexique COMMA_SOURCE_FILE_AT_LINE (42)) COMMA_SOURCE_FILE_AT_LINE (42)) ;
        }else if (typeid (cPtr_sint32_type) == typeid (* (_var_1271.getPtr ()))) {
          const GGS_sint32_type var_cas_f (_var_1271.getPtr ()) ;
          var_cas_others.modifier_put (_inLexique, var_cas_field, var_cas_f.reader_def_val (_inLexique COMMA_SOURCE_FILE_AT_LINE (43)) COMMA_SOURCE_FILE_AT_LINE (43)) ;
        }else if (typeid (cPtr_uint64_type) == typeid (* (_var_1271.getPtr ()))) {
          const GGS_uint64_type var_cas_f (_var_1271.getPtr ()) ;
          var_cas_others.modifier_put (_inLexique, var_cas_field, var_cas_f.reader_def_val (_inLexique COMMA_SOURCE_FILE_AT_LINE (44)) COMMA_SOURCE_FILE_AT_LINE (44)) ;
        }else if (typeid (cPtr_sint64_type) == typeid (* (_var_1271.getPtr ()))) {
          const GGS_sint64_type var_cas_f (_var_1271.getPtr ()) ;
          var_cas_others.modifier_put (_inLexique, var_cas_field, var_cas_f.reader_def_val (_inLexique COMMA_SOURCE_FILE_AT_LINE (45)) COMMA_SOURCE_FILE_AT_LINE (45)) ;
        }else{
        }
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_check_custom_field\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//                 Implementation of routine "check_range"                   *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_check_range (C_Compiler & _inLexique,
                                GGS_basic_type   var_cas_var,
                                GGS_imp_type   var_cas_def COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_check_range at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  { const GGS_basic_type _var_1773 = var_cas_var ; // CAST instruction
    if (_var_1773.getPtr () != NULL) {
      macroValidPointer (_var_1773.getPtr ()) ;
      if (typeid (cPtr_uint32_class) == typeid (* (_var_1773.getPtr ()))) {
        const GGS_uint32_class var_cas_ui (_var_1773.getPtr ()) ;
        { const GGS_imp_type _var_1699 = var_cas_def ; // CAST instruction
          if (_var_1699.getPtr () != NULL) {
            macroValidPointer (_var_1699.getPtr ()) ;
            if (typeid (cPtr_uint32_type) == typeid (* (_var_1699.getPtr ()))) {
              const GGS_uint32_type var_cas_d (_var_1699.getPtr ()) ;
              ::routine_check_uint32_range (_inLexique,  var_cas_d.reader_set (_inLexique COMMA_SOURCE_FILE_AT_LINE (62)),  var_cas_ui.reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (62)),  var_cas_ui.reader_value (_inLexique COMMA_SOURCE_FILE_AT_LINE (62)) COMMA_SOURCE_FILE_AT_LINE (62)) ;
            }else{
              var_cas_def.reader_loc (_inLexique COMMA_SOURCE_FILE_AT_LINE (64)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string ("Internal error") COMMA_SOURCE_FILE_AT_LINE (65)) ;
            }
          }
        }
      }else{
        var_cas_var.reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (67)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string ("Internal error") COMMA_SOURCE_FILE_AT_LINE (68)) ;
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_check_range\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//        Implementation of routine "verify_and_set_tasks_defaults"          *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_verify_and_set_tasks_defaults (C_Compiler & _inLexique,
                                GGS_task_map  & var_cas_tasks,
                                GGS_implementation_spec   var_cas_spec COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_verify_and_set_tasks_defaults at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_task_map  var_cas_tp ;
  var_cas_tp = var_cas_tasks ;
  {
    GGS_task_map::cEnumerator enumerator_2043 (var_cas_tp, true) ;
    const GGS_task_map::cElement * operand_2043 = NULL ;
    while (((operand_2043 = enumerator_2043.nextObject ()))) {
      macroValidPointer (operand_2043) ;
      GGS_task_obj  automatic_var_0 ;
      var_cas_tasks.modifier_del (_inLexique, operand_2043->mKey, automatic_var_0 COMMA_SOURCE_FILE_AT_LINE (82)) ;
      GGS_ident_map  var_cas_others ;
      var_cas_others = operand_2043->mInfo.task.reader_others (_inLexique COMMA_SOURCE_FILE_AT_LINE (83)) ;
      {
        GGS_implementation_spec::cEnumerator enumerator_2174 (var_cas_spec, true) ;
        const GGS_implementation_spec::cElement * operand_2174 = NULL ;
        while (((operand_2174 = enumerator_2174.nextObject ()))) {
          macroValidPointer (operand_2174) ;
          if (((operand_2174->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (85)))._operator_isEqual (GGS_string ("PRIORITY"))).isBuiltAndTrue ()) {
            ::routine_check_range (_inLexique,  operand_2043->mInfo.task.reader_priority (_inLexique COMMA_SOURCE_FILE_AT_LINE (86)),  operand_2174->mInfo.type COMMA_SOURCE_FILE_AT_LINE (86)) ;
          }else if (((operand_2174->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (87)))._operator_isEqual (GGS_string (""))).isBuiltAndTrue ()) {
          }else if (((operand_2174->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (88)))._operator_isEqual (GGS_string (""))).isBuiltAndTrue ()) {
          }else if (((operand_2174->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (89)))._operator_isEqual (GGS_string (""))).isBuiltAndTrue ()) {
          }else if (((operand_2174->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (90)))._operator_isEqual (GGS_string (""))).isBuiltAndTrue ()) {
          }else if (((operand_2174->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (91)))._operator_isEqual (GGS_string (""))).isBuiltAndTrue ()) {
          }else if (((operand_2174->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (92)))._operator_isEqual (GGS_string (""))).isBuiltAndTrue ()) {
          }else{
            ::routine_check_custom_field (_inLexique,  var_cas_others,  operand_2174->mKey,  operand_2174->mInfo.type COMMA_SOURCE_FILE_AT_LINE (94)) ;
          }
        }
      }
      GGS_task_obj  var_cas_updated_task ;
      var_cas_updated_task = GGS_task_obj ::constructor_new (_inLexique, operand_2043->mInfo.task.reader_desc (_inLexique COMMA_SOURCE_FILE_AT_LINE (98)), operand_2043->mInfo.task.reader_priority (_inLexique COMMA_SOURCE_FILE_AT_LINE (99)), operand_2043->mInfo.task.reader_schedule (_inLexique COMMA_SOURCE_FILE_AT_LINE (100)), operand_2043->mInfo.task.reader_activation (_inLexique COMMA_SOURCE_FILE_AT_LINE (101)), operand_2043->mInfo.task.reader_autostart (_inLexique COMMA_SOURCE_FILE_AT_LINE (102)), operand_2043->mInfo.task.reader_resources (_inLexique COMMA_SOURCE_FILE_AT_LINE (103)), operand_2043->mInfo.task.reader_events (_inLexique COMMA_SOURCE_FILE_AT_LINE (104)), operand_2043->mInfo.task.reader_messages (_inLexique COMMA_SOURCE_FILE_AT_LINE (105)), operand_2043->mInfo.task.reader_acc_apps (_inLexique COMMA_SOURCE_FILE_AT_LINE (106)), operand_2043->mInfo.task.reader_timing_prot (_inLexique COMMA_SOURCE_FILE_AT_LINE (107)), var_cas_others COMMA_HERE) ;
      var_cas_tasks.modifier_put (_inLexique, operand_2043->mKey, var_cas_updated_task COMMA_SOURCE_FILE_AT_LINE (110)) ;
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_verify_and_set_tasks_defaults\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//         Implementation of routine "verify_and_set_isrs_defaults"          *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_verify_and_set_isrs_defaults (C_Compiler & _inLexique,
                                GGS_isr_map  & var_cas_isrs,
                                GGS_implementation_spec   var_cas_spec COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_verify_and_set_isrs_defaults at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_isr_map  var_cas_ip ;
  var_cas_ip = var_cas_isrs ;
  {
    GGS_isr_map::cEnumerator enumerator_3389 (var_cas_ip, true) ;
    const GGS_isr_map::cElement * operand_3389 = NULL ;
    while (((operand_3389 = enumerator_3389.nextObject ()))) {
      macroValidPointer (operand_3389) ;
      GGS_isr_obj  automatic_var_1 ;
      var_cas_isrs.modifier_del (_inLexique, operand_3389->mKey, automatic_var_1 COMMA_SOURCE_FILE_AT_LINE (125)) ;
      GGS_ident_map  var_cas_others ;
      var_cas_others = operand_3389->mInfo.isr.reader_other_fields (_inLexique COMMA_SOURCE_FILE_AT_LINE (126)) ;
      {
        GGS_implementation_spec::cEnumerator enumerator_3522 (var_cas_spec, true) ;
        const GGS_implementation_spec::cElement * operand_3522 = NULL ;
        while (((operand_3522 = enumerator_3522.nextObject ()))) {
          macroValidPointer (operand_3522) ;
          if (((operand_3522->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (128)))._operator_isEqual (GGS_string ("PRIORITY"))).isBuiltAndTrue ()) {
            _inLexique.printMessage (GGS_string ("PRIORITY!\n") COMMA_SOURCE_FILE_AT_LINE (129)) ;
          }else if (((operand_3522->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (130)))._operator_isEqual (GGS_string (""))).isBuiltAndTrue ()) {
          }else if (((operand_3522->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (131)))._operator_isEqual (GGS_string (""))).isBuiltAndTrue ()) {
          }else if (((operand_3522->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (132)))._operator_isEqual (GGS_string (""))).isBuiltAndTrue ()) {
          }else if (((operand_3522->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (133)))._operator_isEqual (GGS_string (""))).isBuiltAndTrue ()) {
          }else if (((operand_3522->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (134)))._operator_isEqual (GGS_string (""))).isBuiltAndTrue ()) {
          }else if (((operand_3522->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (135)))._operator_isEqual (GGS_string (""))).isBuiltAndTrue ()) {
          }else{
            ::routine_check_custom_field (_inLexique,  var_cas_others,  operand_3522->mKey,  operand_3522->mInfo.type COMMA_SOURCE_FILE_AT_LINE (137)) ;
          }
        }
      }
      GGS_isr_obj  var_cas_updated_isr ;
      var_cas_updated_isr = GGS_isr_obj ::constructor_new (_inLexique, operand_3389->mInfo.isr.reader_desc (_inLexique COMMA_SOURCE_FILE_AT_LINE (141)), operand_3389->mInfo.isr.reader_category (_inLexique COMMA_SOURCE_FILE_AT_LINE (142)), operand_3389->mInfo.isr.reader_priority (_inLexique COMMA_SOURCE_FILE_AT_LINE (143)), operand_3389->mInfo.isr.reader_resources (_inLexique COMMA_SOURCE_FILE_AT_LINE (144)), operand_3389->mInfo.isr.reader_messages (_inLexique COMMA_SOURCE_FILE_AT_LINE (145)), operand_3389->mInfo.isr.reader_acc_apps (_inLexique COMMA_SOURCE_FILE_AT_LINE (146)), operand_3389->mInfo.isr.reader_timing_prot (_inLexique COMMA_SOURCE_FILE_AT_LINE (147)), var_cas_others COMMA_HERE) ;
      var_cas_isrs.modifier_put (_inLexique, operand_3389->mKey, var_cas_updated_isr COMMA_SOURCE_FILE_AT_LINE (150)) ;
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_verify_and_set_isrs_defaults\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of routine "add_system_counter"               *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_add_system_counter (C_Compiler & _inLexique,
                                GGS_root_obj  & var_cas_cpu COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_add_system_counter at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_counter_map  var_cas_counters ;
  var_cas_counters = var_cas_cpu.reader_counters (_inLexique COMMA_SOURCE_FILE_AT_LINE (164)) ;
  GGS_counter_obj  var_cas_sys_cnt ;
  GGS_lstringlist  var_cas_all_apps ;
  var_cas_all_apps = var_cas_cpu.reader_applis (_inLexique COMMA_SOURCE_FILE_AT_LINE (166)).reader_keyList (_inLexique COMMA_SOURCE_FILE_AT_LINE (166)) ;
  {
    GGS_app_map::cEnumerator enumerator_4672 (var_cas_cpu.reader_applis (_inLexique COMMA_SOURCE_FILE_AT_LINE (167)), true) ;
    const GGS_app_map::cElement * operand_4672 = NULL ;
    while (((operand_4672 = enumerator_4672.nextObject ()))) {
      macroValidPointer (operand_4672) ;
      var_cas_all_apps._addAssign_operation (operand_4672->mKey) ;
    }
  }
  if ((var_cas_counters.reader_hasKey (_inLexique, GGS_string ("SystemCounter") COMMA_SOURCE_FILE_AT_LINE (171))).isBuiltAndTrue ()) {
    var_cas_counters.modifier_del (_inLexique, GGS_lstring ::constructor_new (_inLexique, GGS_string ("SystemCounter"), GGS_location (_inLexique) COMMA_HERE), var_cas_sys_cnt COMMA_SOURCE_FILE_AT_LINE (172)) ;
    { const GGS_basic_type _var_4995 = var_cas_sys_cnt.reader_max_allowed_value (_inLexique COMMA_SOURCE_FILE_AT_LINE (173)) ; // CAST instruction
      if (_var_4995.getPtr () != NULL) {
        macroValidPointer (_var_4995.getPtr ()) ;
        if (typeid (cPtr_void) == typeid (* (_var_4995.getPtr ()))) {
          var_cas_sys_cnt.modifier_setMax_allowed_value (_inLexique, GGS_uint32_class ::constructor_new (_inLexique, GGS_location (_inLexique), GGS_uint (32767U) COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (175)) ;
        }else{
        }
      }
    }
    { const GGS_basic_type _var_5147 = var_cas_sys_cnt.reader_ticks_per_base (_inLexique COMMA_SOURCE_FILE_AT_LINE (178)) ; // CAST instruction
      if (_var_5147.getPtr () != NULL) {
        macroValidPointer (_var_5147.getPtr ()) ;
        if (typeid (cPtr_void) == typeid (* (_var_5147.getPtr ()))) {
          var_cas_sys_cnt.modifier_setTicks_per_base (_inLexique, GGS_uint32_class ::constructor_new (_inLexique, GGS_location (_inLexique), GGS_uint (1U) COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (180)) ;
        }else{
        }
      }
    }
    { const GGS_basic_type _var_5289 = var_cas_sys_cnt.reader_min_cycle (_inLexique COMMA_SOURCE_FILE_AT_LINE (183)) ; // CAST instruction
      if (_var_5289.getPtr () != NULL) {
        macroValidPointer (_var_5289.getPtr ()) ;
        if (typeid (cPtr_void) == typeid (* (_var_5289.getPtr ()))) {
          var_cas_sys_cnt.modifier_setMin_cycle (_inLexique, GGS_uint32_class ::constructor_new (_inLexique, GGS_location (_inLexique), GGS_uint (1U) COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (185)) ;
        }else{
        }
      }
    }
    if (((var_cas_sys_cnt.reader_source (_inLexique COMMA_SOURCE_FILE_AT_LINE (188)).reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (188)))._operator_isEqual (GGS_string (""))).isBuiltAndTrue ()) {
      var_cas_sys_cnt.reader_source (_inLexique COMMA_SOURCE_FILE_AT_LINE (189)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticWarning (_inLexique, GGS_string ("SystemCounter has no interrupt source") COMMA_SOURCE_FILE_AT_LINE (189)) ;
    }
    if ((GGS_bool (_inLexique.boolOptionValueFromKeys ("goil_options", "autosar_on" COMMA_SOURCE_FILE_AT_LINE (191)))).isBuiltAndTrue ()) {
      if (((var_cas_sys_cnt.reader_acc_apps (_inLexique COMMA_SOURCE_FILE_AT_LINE (193)).reader_length (_inLexique COMMA_SOURCE_FILE_AT_LINE (193)))._operator_isEqual (GGS_uint (0U))).isBuiltAndTrue ()) {
        var_cas_sys_cnt.modifier_setAcc_apps (_inLexique, var_cas_all_apps COMMA_SOURCE_FILE_AT_LINE (194)) ;
      }
      { const GGS_counter_type _var_5801 = var_cas_sys_cnt.reader_type (_inLexique COMMA_SOURCE_FILE_AT_LINE (196)) ; // CAST instruction
        if (_var_5801.getPtr () != NULL) {
          macroValidPointer (_var_5801.getPtr ()) ;
          if (typeid (cPtr_software_counter) == typeid (* (_var_5801.getPtr ()))) {
            const GGS_software_counter var_cas_sc (_var_5801.getPtr ()) ;
            var_cas_sc.reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (198)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string ("Incompatible TYPE for SystemCounter") COMMA_SOURCE_FILE_AT_LINE (199)) ;
          }else{
          }
        }
      }
    }
  }else{
    GGS_hardware_counter  var_cas_type ;
    var_cas_type = GGS_hardware_counter ::constructor_new (_inLexique, GGS_location (_inLexique), GGS_void_driver ::constructor_new (_inLexique, GGS_location (_inLexique) COMMA_HERE), GGS_time_constants ::constructor_emptyList () COMMA_HERE) ;
    var_cas_sys_cnt = GGS_counter_obj ::constructor_new (_inLexique, GGS_lstring ::constructor_new (_inLexique, GGS_string ("Predefined SystemCounter"), GGS_location (_inLexique) COMMA_HERE), GGS_uint32_class ::constructor_new (_inLexique, GGS_location (_inLexique), GGS_uint (32767U) COMMA_HERE), GGS_uint32_class ::constructor_new (_inLexique, GGS_location (_inLexique), GGS_uint (1U) COMMA_HERE), GGS_uint32_class ::constructor_new (_inLexique, GGS_location (_inLexique), GGS_uint (1U) COMMA_HERE), GGS_lstring ::constructor_new (_inLexique, GGS_string (""), GGS_location (_inLexique) COMMA_HERE), var_cas_all_apps, var_cas_type, GGS_lstring ::constructor_new (_inLexique, GGS_string (""), GGS_location (_inLexique) COMMA_HERE) COMMA_HERE) ;
  }
  var_cas_counters.modifier_put (_inLexique, GGS_lstring ::constructor_new (_inLexique, GGS_string ("SystemCounter"), GGS_location (_inLexique) COMMA_HERE), var_cas_sys_cnt COMMA_SOURCE_FILE_AT_LINE (216)) ;
  var_cas_cpu.modifier_setCounters (_inLexique, var_cas_counters COMMA_SOURCE_FILE_AT_LINE (218)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_add_system_counter\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//                 Implementation of routine "set_defaults"                  *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_set_defaults (C_Compiler & _inLexique,
                                const GGS_implementation   var_cas_imp,
                                GGS_root_obj  & var_cas_cpu COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_set_defaults at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  if ((var_cas_imp.reader_hasKey (_inLexique, GGS_string ("task") COMMA_SOURCE_FILE_AT_LINE (226))).isBuiltAndTrue ()) {
    GGS_task_map  var_cas_tasks ;
    var_cas_tasks = var_cas_cpu.reader_tasks (_inLexique COMMA_SOURCE_FILE_AT_LINE (227)) ;
    GGS_implementation_spec  var_cas_spec ;
    const GGS_implementation  _temp_6794 = var_cas_imp ;
    if (_temp_6794.isBuilt ()) {
      _temp_6794 (HERE)->method_get (_inLexique, GGS_lstring ::constructor_new (_inLexique, GGS_string ("task"), GGS_location (_inLexique) COMMA_HERE), var_cas_spec COMMA_SOURCE_FILE_AT_LINE (229)) ;
    }
    ::routine_verify_and_set_tasks_defaults (_inLexique,  var_cas_tasks,  var_cas_spec COMMA_SOURCE_FILE_AT_LINE (230)) ;
    var_cas_cpu.modifier_setTasks (_inLexique, var_cas_tasks COMMA_SOURCE_FILE_AT_LINE (231)) ;
    var_cas_tasks = var_cas_cpu.reader_tasks (_inLexique COMMA_SOURCE_FILE_AT_LINE (232)) ;
  }
  if ((var_cas_imp.reader_hasKey (_inLexique, GGS_string ("isr") COMMA_SOURCE_FILE_AT_LINE (236))).isBuiltAndTrue ()) {
    GGS_isr_map  var_cas_isrs ;
    var_cas_isrs = var_cas_cpu.reader_isrs (_inLexique COMMA_SOURCE_FILE_AT_LINE (237)) ;
    GGS_implementation_spec  var_cas_spec ;
    const GGS_implementation  _temp_7088 = var_cas_imp ;
    if (_temp_7088.isBuilt ()) {
      _temp_7088 (HERE)->method_get (_inLexique, GGS_lstring ::constructor_new (_inLexique, GGS_string ("isr"), GGS_location (_inLexique) COMMA_HERE), var_cas_spec COMMA_SOURCE_FILE_AT_LINE (239)) ;
    }
    ::routine_verify_and_set_isrs_defaults (_inLexique,  var_cas_isrs,  var_cas_spec COMMA_SOURCE_FILE_AT_LINE (240)) ;
    var_cas_cpu.modifier_setIsrs (_inLexique, var_cas_isrs COMMA_SOURCE_FILE_AT_LINE (241)) ;
  }
  ::routine_add_system_counter (_inLexique,  var_cas_cpu COMMA_SOURCE_FILE_AT_LINE (244)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_set_defaults\n") ;
  #endif
}

//---------------------------------------------------------------------------*

