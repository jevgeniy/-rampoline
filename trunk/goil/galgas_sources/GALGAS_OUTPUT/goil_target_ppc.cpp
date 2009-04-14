//---------------------------------------------------------------------------*
//                                                                           *
//                        File 'goil_target_ppc.cpp'                         *
//                        Generated by version 1.8.0                         *
//                       march 5th, 2009, at 9h29'9"                         *
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
#include "goil_target_ppc.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_target_ppc.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//             Implementation of routine "generate_target_ppc"               *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_target_ppc (C_Compiler & _inLexique,
                                const GGS_lstring   var_cas_name,
                                const GGS_ident_map   var_cas_others,
                                const GGS_oil_obj   /* var_cas_exe */,
                                GGS_string & var_cas_result COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_generate_target_ppc at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  ::routine_doReplace (_inLexique,  var_cas_result,  GGS_string (true, "$STACK_ZONE$"),  (var_cas_name.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (57)))._operator_concat (GGS_string (true, "_stack")) COMMA_SOURCE_FILE_AT_LINE (57)) ;
  ::routine_doReplace (_inLexique,  var_cas_result,  GGS_string (true, "$EXEC_INTEGER_CONTEXT$"),  (var_cas_name.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (59)))._operator_concat (GGS_string (true, "_int_context")) COMMA_SOURCE_FILE_AT_LINE (59)) ;
  ::routine_doReplace (_inLexique,  var_cas_result,  GGS_string (true, "$EXEC_FLOAT_CONTEXT$"),  (var_cas_name.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (61)))._operator_concat (GGS_string (true, "_fp_context")) COMMA_SOURCE_FILE_AT_LINE (61)) ;
  ::routine_doReplace (_inLexique,  var_cas_result,  GGS_string (true, "$EXEC_USE_FLOAT$"),  (var_cas_name.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (63)))._operator_concat (GGS_string (true, "_uses_fp")) COMMA_SOURCE_FILE_AT_LINE (63)) ;
  GGS_uint  var_cas_stack_size ;
  ::routine_additional_int_key_required (_inLexique,  GGS_string (true, "STACKSIZE"),  var_cas_others,  var_cas_name,  var_cas_stack_size COMMA_SOURCE_FILE_AT_LINE (66)) ;
  var_cas_result = var_cas_result.reader_stringByReplacingStringByString (_inLexique, GGS_string (true, "$STACK_SIZE$"), var_cas_stack_size.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (67)) COMMA_SOURCE_FILE_AT_LINE (67)) ;
  GGS_bool var_cas_use_float ;
  ::routine_additional_bool_key_required (_inLexique,  GGS_string (true, "USEFLOAT"),  var_cas_others,  var_cas_name,  var_cas_use_float COMMA_SOURCE_FILE_AT_LINE (70)) ;
  GGS_uint  var_cas_use_float_as_int ;
  if (((var_cas_use_float)._operator_isEqual (GGS_bool (true, true))).isBuiltAndTrue ()) {
    var_cas_use_float_as_int = GGS_uint (true, 1U) ;
  }else{
    var_cas_use_float_as_int = GGS_uint (true, 0U) ;
  }
  var_cas_result = var_cas_result.reader_stringByReplacingStringByString (_inLexique, GGS_string (true, "$FLAG_USE_FLOAT$"), var_cas_use_float_as_int.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (77)) COMMA_SOURCE_FILE_AT_LINE (77)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_generate_target_ppc\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//               Implementation of routine "generate_isr_ppc"                *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_isr_ppc (C_Compiler &,
                                const GGS_isr_map   /* var_cas_isrs */,
                                GGS_string & /* var_cas_code */ COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_generate_isr_ppc at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_generate_isr_ppc\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//             Implementation of routine "generate_counter_ppc"              *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_counter_ppc (C_Compiler & _inLexique,
                                const GGS_counter_map   var_cas_counters,
                                GGS_string & var_cas_code COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_generate_counter_ppc at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_result ;
  var_cas_result = GGS_string (true, "") ;
  {
    GGS_counter_map::cEnumerator enumerator_2973 (var_cas_counters, true) ;
    const GGS_counter_map::cElement * operand_2973 = NULL ;
    while (((operand_2973 = enumerator_2973.nextObject ()))) {
      macroValidPointer (operand_2973) ;
      { const GGS_counter_type _var_3272 = operand_2973->mInfo.counter.reader_type (_inLexique COMMA_SOURCE_FILE_AT_LINE (93)) ; // CAST instruction
        if (_var_3272.getPtr () != NULL) {
          macroValidPointer (_var_3272.getPtr ()) ;
          if (typeid (cPtr_software_counter) == typeid (* (_var_3272.getPtr ()))) {
          }else{
            GGS_string var_cas_tmp ;
            ::routine_retrieveTemplateString (_inLexique,  var_cas_tmp,  GGS_string (true, "counter_list_specific") COMMA_SOURCE_FILE_AT_LINE (97)) ;
            ::routine_doReplace (_inLexique,  var_cas_tmp,  GGS_string (true, "$COUNTER$"),  (operand_2973->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (98)))._operator_concat (GGS_string (true, "_counter_desc")) COMMA_SOURCE_FILE_AT_LINE (98)) ;
            var_cas_result._dotAssign_operation (var_cas_tmp) ;
          }
        }
      }
    }
  }
  ::routine_doReplace (_inLexique,  var_cas_code,  GGS_string (true, "$COUNTER_LIST$"),  var_cas_result COMMA_SOURCE_FILE_AT_LINE (103)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_generate_counter_ppc\n") ;
  #endif
}

//---------------------------------------------------------------------------*

