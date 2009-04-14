//---------------------------------------------------------------------------*
//                                                                           *
//                         File 'goil_defaults.cpp'                          *
//                        Generated by version 1.8.0                         *
//                       march 5th, 2009, at 9h28'14"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 451
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "goil_defaults.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_defaults.ggs", line
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
    { const GGS_imp_type _var_1208 = var_cas_f_def ; // CAST instruction
      if (_var_1208.getPtr () != NULL) {
        macroValidPointer (_var_1208.getPtr ()) ;
        if (typeid (cPtr_uint32_type) == typeid (* (_var_1208.getPtr ()))) {
          const GGS_uint32_type var_cas_f (_var_1208.getPtr ()) ;
          var_cas_others.modifier_put (_inLexique, var_cas_field, var_cas_f.reader_def_val (_inLexique COMMA_SOURCE_FILE_AT_LINE (42)) COMMA_SOURCE_FILE_AT_LINE (42)) ;
        }else if (typeid (cPtr_sint32_type) == typeid (* (_var_1208.getPtr ()))) {
          const GGS_sint32_type var_cas_f (_var_1208.getPtr ()) ;
          var_cas_others.modifier_put (_inLexique, var_cas_field, var_cas_f.reader_def_val (_inLexique COMMA_SOURCE_FILE_AT_LINE (43)) COMMA_SOURCE_FILE_AT_LINE (43)) ;
        }else if (typeid (cPtr_uint64_type) == typeid (* (_var_1208.getPtr ()))) {
          const GGS_uint64_type var_cas_f (_var_1208.getPtr ()) ;
          var_cas_others.modifier_put (_inLexique, var_cas_field, var_cas_f.reader_def_val (_inLexique COMMA_SOURCE_FILE_AT_LINE (44)) COMMA_SOURCE_FILE_AT_LINE (44)) ;
        }else if (typeid (cPtr_sint64_type) == typeid (* (_var_1208.getPtr ()))) {
          const GGS_sint64_type var_cas_f (_var_1208.getPtr ()) ;
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
  { const GGS_basic_type _var_1710 = var_cas_var ; // CAST instruction
    if (_var_1710.getPtr () != NULL) {
      macroValidPointer (_var_1710.getPtr ()) ;
      if (typeid (cPtr_uint32_class) == typeid (* (_var_1710.getPtr ()))) {
        const GGS_uint32_class var_cas_ui (_var_1710.getPtr ()) ;
        { const GGS_imp_type _var_1636 = var_cas_def ; // CAST instruction
          if (_var_1636.getPtr () != NULL) {
            macroValidPointer (_var_1636.getPtr ()) ;
            if (typeid (cPtr_uint32_type) == typeid (* (_var_1636.getPtr ()))) {
              const GGS_uint32_type var_cas_d (_var_1636.getPtr ()) ;
              ::routine_check_uint32_range (_inLexique,  var_cas_d.reader_set (_inLexique COMMA_SOURCE_FILE_AT_LINE (62)),  var_cas_ui.reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (62)),  var_cas_ui.reader_value (_inLexique COMMA_SOURCE_FILE_AT_LINE (62)) COMMA_SOURCE_FILE_AT_LINE (62)) ;
            }else{
              var_cas_def.reader_loc (_inLexique COMMA_SOURCE_FILE_AT_LINE (64)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "Internal error") COMMA_SOURCE_FILE_AT_LINE (65)) ;
            }
          }
        }
      }else{
        var_cas_var.reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (67)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "Internal error") COMMA_SOURCE_FILE_AT_LINE (68)) ;
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
    GGS_task_map::cEnumerator enumerator_1980 (var_cas_tp, true) ;
    const GGS_task_map::cElement * operand_1980 = NULL ;
    while (((operand_1980 = enumerator_1980.nextObject ()))) {
      macroValidPointer (operand_1980) ;
      GGS_task_obj  automatic_var_0 ;
      var_cas_tasks.modifier_del (_inLexique, operand_1980->mKey, automatic_var_0 COMMA_SOURCE_FILE_AT_LINE (82)) ;
      GGS_ident_map  var_cas_others ;
      var_cas_others = operand_1980->mInfo.task.reader_others (_inLexique COMMA_SOURCE_FILE_AT_LINE (83)) ;
      {
        GGS_implementation_spec::cEnumerator enumerator_2111 (var_cas_spec, true) ;
        const GGS_implementation_spec::cElement * operand_2111 = NULL ;
        while (((operand_2111 = enumerator_2111.nextObject ()))) {
          macroValidPointer (operand_2111) ;
          if (((operand_2111->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (85)))._operator_isEqual (GGS_string (true, "PRIORITY"))).isBuiltAndTrue ()) {
            ::routine_check_range (_inLexique,  operand_1980->mInfo.task.reader_priority (_inLexique COMMA_SOURCE_FILE_AT_LINE (86)),  operand_2111->mInfo.type COMMA_SOURCE_FILE_AT_LINE (86)) ;
          }else if (((operand_2111->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (87)))._operator_isEqual (GGS_string (true, ""))).isBuiltAndTrue ()) {
          }else if (((operand_2111->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (88)))._operator_isEqual (GGS_string (true, ""))).isBuiltAndTrue ()) {
          }else if (((operand_2111->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (89)))._operator_isEqual (GGS_string (true, ""))).isBuiltAndTrue ()) {
          }else if (((operand_2111->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (90)))._operator_isEqual (GGS_string (true, ""))).isBuiltAndTrue ()) {
          }else if (((operand_2111->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (91)))._operator_isEqual (GGS_string (true, ""))).isBuiltAndTrue ()) {
          }else if (((operand_2111->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (92)))._operator_isEqual (GGS_string (true, ""))).isBuiltAndTrue ()) {
          }else{
            ::routine_check_custom_field (_inLexique,  var_cas_others,  operand_2111->mKey,  operand_2111->mInfo.type COMMA_SOURCE_FILE_AT_LINE (94)) ;
          }
        }
      }
      GGS_task_obj  var_cas_updated_task ;
      var_cas_updated_task = GGS_task_obj ::constructor_new (_inLexique, operand_1980->mInfo.task.reader_desc (_inLexique COMMA_SOURCE_FILE_AT_LINE (98)), operand_1980->mInfo.task.reader_priority (_inLexique COMMA_SOURCE_FILE_AT_LINE (99)), operand_1980->mInfo.task.reader_schedule (_inLexique COMMA_SOURCE_FILE_AT_LINE (100)), operand_1980->mInfo.task.reader_activation (_inLexique COMMA_SOURCE_FILE_AT_LINE (101)), operand_1980->mInfo.task.reader_autostart (_inLexique COMMA_SOURCE_FILE_AT_LINE (102)), operand_1980->mInfo.task.reader_resources (_inLexique COMMA_SOURCE_FILE_AT_LINE (103)), operand_1980->mInfo.task.reader_events (_inLexique COMMA_SOURCE_FILE_AT_LINE (104)), operand_1980->mInfo.task.reader_messages (_inLexique COMMA_SOURCE_FILE_AT_LINE (105)), operand_1980->mInfo.task.reader_acc_apps (_inLexique COMMA_SOURCE_FILE_AT_LINE (106)), operand_1980->mInfo.task.reader_timing_prot (_inLexique COMMA_SOURCE_FILE_AT_LINE (107)), var_cas_others COMMA_HERE) ;
      var_cas_tasks.modifier_put (_inLexique, operand_1980->mKey, var_cas_updated_task COMMA_SOURCE_FILE_AT_LINE (110)) ;
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
    GGS_isr_map::cEnumerator enumerator_3326 (var_cas_ip, true) ;
    const GGS_isr_map::cElement * operand_3326 = NULL ;
    while (((operand_3326 = enumerator_3326.nextObject ()))) {
      macroValidPointer (operand_3326) ;
      GGS_isr_obj  automatic_var_1 ;
      var_cas_isrs.modifier_del (_inLexique, operand_3326->mKey, automatic_var_1 COMMA_SOURCE_FILE_AT_LINE (125)) ;
      GGS_ident_map  var_cas_others ;
      var_cas_others = operand_3326->mInfo.isr.reader_other_fields (_inLexique COMMA_SOURCE_FILE_AT_LINE (126)) ;
      {
        GGS_implementation_spec::cEnumerator enumerator_3459 (var_cas_spec, true) ;
        const GGS_implementation_spec::cElement * operand_3459 = NULL ;
        while (((operand_3459 = enumerator_3459.nextObject ()))) {
          macroValidPointer (operand_3459) ;
          if (((operand_3459->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (128)))._operator_isEqual (GGS_string (true, "PRIORITY"))).isBuiltAndTrue ()) {
            _inLexique.printMessage (GGS_string (true, "PRIORITY!\n") COMMA_SOURCE_FILE_AT_LINE (129)) ;
          }else if (((operand_3459->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (130)))._operator_isEqual (GGS_string (true, ""))).isBuiltAndTrue ()) {
          }else if (((operand_3459->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (131)))._operator_isEqual (GGS_string (true, ""))).isBuiltAndTrue ()) {
          }else if (((operand_3459->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (132)))._operator_isEqual (GGS_string (true, ""))).isBuiltAndTrue ()) {
          }else if (((operand_3459->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (133)))._operator_isEqual (GGS_string (true, ""))).isBuiltAndTrue ()) {
          }else if (((operand_3459->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (134)))._operator_isEqual (GGS_string (true, ""))).isBuiltAndTrue ()) {
          }else if (((operand_3459->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (135)))._operator_isEqual (GGS_string (true, ""))).isBuiltAndTrue ()) {
          }else{
            ::routine_check_custom_field (_inLexique,  var_cas_others,  operand_3459->mKey,  operand_3459->mInfo.type COMMA_SOURCE_FILE_AT_LINE (137)) ;
          }
        }
      }
      GGS_isr_obj  var_cas_updated_isr ;
      var_cas_updated_isr = GGS_isr_obj ::constructor_new (_inLexique, operand_3326->mInfo.isr.reader_desc (_inLexique COMMA_SOURCE_FILE_AT_LINE (141)), operand_3326->mInfo.isr.reader_category (_inLexique COMMA_SOURCE_FILE_AT_LINE (142)), operand_3326->mInfo.isr.reader_priority (_inLexique COMMA_SOURCE_FILE_AT_LINE (143)), operand_3326->mInfo.isr.reader_resources (_inLexique COMMA_SOURCE_FILE_AT_LINE (144)), operand_3326->mInfo.isr.reader_messages (_inLexique COMMA_SOURCE_FILE_AT_LINE (145)), operand_3326->mInfo.isr.reader_acc_apps (_inLexique COMMA_SOURCE_FILE_AT_LINE (146)), operand_3326->mInfo.isr.reader_timing_prot (_inLexique COMMA_SOURCE_FILE_AT_LINE (147)), var_cas_others COMMA_HERE) ;
      var_cas_isrs.modifier_put (_inLexique, operand_3326->mKey, var_cas_updated_isr COMMA_SOURCE_FILE_AT_LINE (150)) ;
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_verify_and_set_isrs_defaults\n") ;
  #endif
}

//---------------------------------------------------------------------------*

