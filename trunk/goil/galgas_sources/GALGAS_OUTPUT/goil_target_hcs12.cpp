//---------------------------------------------------------------------------*
//                                                                           *
//                       File 'goil_target_hcs12.cpp'                        *
//                        Generated by version 1.9.2                         *
//                      october 7th, 2009, at 10h1'2"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 573
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "galgas/C_galgas_CLI_Options.h"
#include "goil_target_hcs12.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_target_hcs12.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//            Implementation of routine "generate_target_hcs12"              *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_target_hcs12 (C_Compiler & inLexique,
                                GGS_lstring   var_cas_name,
                                GGS_ident_map   var_cas_others,
                                GGS_oil_obj   /* var_cas_exe */,
                                GGS_string & var_cas_result COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_generate_target_hcs12 at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  ::routine_doReplace (inLexique,  var_cas_result,  GGS_string ("$STACK_ZONE$"),  (var_cas_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (52))).operator_concat (GGS_string ("_stack")) COMMA_SOURCE_FILE_AT_LINE (52)) ;
  ::routine_doReplace (inLexique,  var_cas_result,  GGS_string ("$EXEC_INTEGER_CONTEXT$"),  (var_cas_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (53))).operator_concat (GGS_string ("_int_context")) COMMA_SOURCE_FILE_AT_LINE (53)) ;
  GGS_uint  var_cas_stack_size ;
  ::routine_additional_int_key_required (inLexique,  GGS_string ("STACKSIZE"),  var_cas_others,  var_cas_name,  var_cas_stack_size COMMA_SOURCE_FILE_AT_LINE (56)) ;
  ::routine_doReplace (inLexique,  var_cas_result,  GGS_string ("$STACK_SIZE$"),  var_cas_stack_size.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (57)) COMMA_SOURCE_FILE_AT_LINE (57)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_generate_target_hcs12\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of routine "generate_isr_hcs12"               *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_isr_hcs12 (C_Compiler &,
                                const GGS_isr_map   /* var_cas_isrs */,
                                GGS_string & /* var_cas_code */ COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_generate_isr_hcs12 at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_generate_isr_hcs12\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//            Implementation of routine "generate_counter_hcs12"             *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_counter_hcs12 (C_Compiler & inLexique,
                                const GGS_counter_map   var_cas_counters,
                                GGS_string & var_cas_code COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_generate_counter_hcs12 at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_result ;
  var_cas_result = GGS_string ("") ;
  {
    GGS_counter_map::cEnumerator enumerator_1940 (var_cas_counters, true) ;
    const GGS_counter_map::cElement * operand_1940 = NULL ;
    while (((operand_1940 = enumerator_1940.nextObject ()))) {
      macroValidPointer (operand_1940) ;
      { const GGS_counter_type _var_2239 = operand_1940->mInfo.counter.reader_type (inLexique COMMA_SOURCE_FILE_AT_LINE (73)) ; // CAST instruction
        if (_var_2239.getPtr () != NULL) {
          macroValidPointer (_var_2239.getPtr ()) ;
          if (typeid (cPtr_software_counter) == typeid (* (_var_2239.getPtr ()))) {
          }else{
            GGS_string var_cas_tmp ;
            ::routine_retrieveTemplateString (inLexique,  var_cas_tmp,  GGS_string ("counter_list_specific") COMMA_SOURCE_FILE_AT_LINE (77)) ;
            ::routine_doReplace (inLexique,  var_cas_tmp,  GGS_string ("$COUNTER$"),  (operand_1940->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (78))).operator_concat (GGS_string ("_counter_desc")) COMMA_SOURCE_FILE_AT_LINE (78)) ;
            var_cas_result.dotAssign_operation (var_cas_tmp) ;
          }
        }
      }
    }
  }
  ::routine_doReplace (inLexique,  var_cas_code,  GGS_string ("$COUNTER_LIST$"),  var_cas_result COMMA_SOURCE_FILE_AT_LINE (83)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_generate_counter_hcs12\n") ;
  #endif
}

//---------------------------------------------------------------------------*

