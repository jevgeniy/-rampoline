//---------------------------------------------------------------------------*
//                                                                           *
//                     File 'goil_proc_generation.cpp'                       *
//                        Generated by version 1.8.2                         *
//                      april 27th, 2009, at 22h45'40"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 463
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "goil_proc_generation.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_proc_generation.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//             Implementation of routine "generate_proc_table"               *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_proc_table (C_Compiler & _inLexique,
                                const GGS_task_map   var_cas_tasks,
                                const GGS_isr_map   var_cas_isrs,
                                GGS_string & var_cas_head,
                                GGS_string & var_cas_imp,
                                GGS_string & var_cas_obj_head COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_generate_proc_table at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_names_head ;
  GGS_string var_cas_names_imp ;
  GGS_string var_cas_proc_ids ;
  var_cas_proc_ids = GGS_string (true, "") ;
  GGS_string var_cas_proc_stat_imp ;
  var_cas_proc_stat_imp = GGS_string (true, "") ;
  GGS_string var_cas_proc_dyn_imp ;
  var_cas_proc_dyn_imp = GGS_string (true, "") ;
  GGS_string var_cas_event_imp ;
  var_cas_event_imp = GGS_string (true, "") ;
  GGS_string var_cas_isr_stat_imp ;
  var_cas_isr_stat_imp = GGS_string (true, "") ;
  GGS_string var_cas_isr_ena_imp ;
  var_cas_isr_ena_imp = GGS_string (true, "") ;
  GGS_uint  var_cas_id ;
  var_cas_id = GGS_uint (true, 0U) ;
  GGS_uint  var_cas_ex_t_ct ;
  var_cas_ex_t_ct = GGS_uint (true, 0U) ;
  GGS_tasks_by_type  var_cas_stasks ;
  var_cas_stasks = GGS_tasks_by_type ::constructor_emptySortedList () ;
  {
    GGS_task_map::cEnumerator enumerator_1191 (var_cas_tasks, true) ;
    const GGS_task_map::cElement * operand_1191 = NULL ;
    while (((operand_1191 = enumerator_1191.nextObject ()))) {
      macroValidPointer (operand_1191) ;
      if (((operand_1191->mInfo.task.reader_events (_inLexique COMMA_SOURCE_FILE_AT_LINE (53)).reader_length (_inLexique COMMA_SOURCE_FILE_AT_LINE (53)))._operator_strictSup (GGS_uint (true, 0U))).isBuiltAndTrue ()) {
        var_cas_stasks._addAssign_operation (GGS_uint (true, 0U), operand_1191->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (54))) ;
        var_cas_ex_t_ct._increment_operation (_inLexique COMMA_SOURCE_FILE_AT_LINE (55)) ;
      }else{
        var_cas_stasks._addAssign_operation (GGS_uint (true, 1U), operand_1191->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (57))) ;
      }
    }
  }
  ::routine_doReplace (_inLexique,  var_cas_obj_head,  GGS_string (true, "$EXTENDED_TASK_COUNT$"),  var_cas_ex_t_ct.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (61)) COMMA_SOURCE_FILE_AT_LINE (61)) ;
  var_cas_names_head = GGS_string (true, "#if !defined(NO_TASK) || !defined(NO_ISR)\n") ;
  var_cas_names_head.appendCstring ("extern char *proc_name_table[TASK_COUNT + ISR_COUNT];\n") ;
  var_cas_names_head.appendCstring ("#endif\n") ;
  var_cas_names_imp = GGS_string (true, "#if !defined(NO_TASK) || !defined(NO_ISR)\n") ;
  var_cas_names_imp.appendCstring ("char *proc_name_table[TASK_COUNT + ISR_COUNT] = {\n") ;
  {
    GGS_tasks_by_type::cEnumerator enumerator_1788 (var_cas_stasks, true) ;
    const GGS_tasks_by_type::cElement * operand_1788 = NULL ;
    while (((operand_1788 = enumerator_1788.nextObject ()))) {
      macroValidPointer (operand_1788) ;
      var_cas_names_imp.appendCstring ("  \"") ;
      var_cas_names_imp._dotAssign_operation (operand_1788->name) ;
      var_cas_names_imp.appendCstring ("\",\n") ;
      var_cas_proc_ids.appendCstring ("#define ") ;
      var_cas_proc_ids._dotAssign_operation (operand_1788->name) ;
      var_cas_proc_ids.appendCstring ("_id  ") ;
      var_cas_proc_ids._dotAssign_operation (var_cas_id.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (72))) ;
      var_cas_proc_ids.appendCstring ("\n") ;
      var_cas_proc_ids.appendCstring ("CONST(TaskType, AUTOMATIC) ") ;
      var_cas_proc_ids._dotAssign_operation (operand_1788->name) ;
      var_cas_proc_ids.appendCstring (" = ") ;
      var_cas_proc_ids._dotAssign_operation (operand_1788->name) ;
      var_cas_proc_ids.appendCstring ("_id;\n") ;
      var_cas_id._increment_operation (_inLexique COMMA_SOURCE_FILE_AT_LINE (74)) ;
    }
  }
  {
    GGS_isr_map::cEnumerator enumerator_2086 (var_cas_isrs, true) ;
    const GGS_isr_map::cElement * operand_2086 = NULL ;
    while (((operand_2086 = enumerator_2086.nextObject ()))) {
      macroValidPointer (operand_2086) ;
      var_cas_names_imp.appendCstring ("  \"") ;
      var_cas_names_imp._dotAssign_operation (operand_2086->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (79))) ;
      var_cas_names_imp.appendCstring ("\",\n") ;
      var_cas_proc_ids.appendCstring ("#define ") ;
      var_cas_proc_ids._dotAssign_operation (operand_2086->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (81))) ;
      var_cas_proc_ids.appendCstring ("_id  ") ;
      var_cas_proc_ids._dotAssign_operation (var_cas_id.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (81))) ;
      var_cas_proc_ids.appendCstring ("\n") ;
      if ((GGS_bool (true, _inLexique.boolOptionValueFromKeys ("goil_options", "autosar_on" COMMA_SOURCE_FILE_AT_LINE (82)))).isBuiltAndTrue ()) {
        var_cas_proc_ids.appendCstring ("CONST(ISRType, AUTOMATIC) ") ;
        var_cas_proc_ids._dotAssign_operation (operand_2086->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (83))) ;
        var_cas_proc_ids.appendCstring (" = ") ;
        var_cas_proc_ids._dotAssign_operation (operand_2086->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (83))) ;
        var_cas_proc_ids.appendCstring ("_id;\n") ;
      }
      var_cas_id._increment_operation (_inLexique COMMA_SOURCE_FILE_AT_LINE (85)) ;
    }
  }
  var_cas_names_imp.appendCstring ("};\n"
    "#endif") ;
  var_cas_proc_stat_imp = GGS_string (true, "CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA)\n"
    "tpl_stat_proc_table[TASK_COUNT+ISR_COUNT+1] = {\n") ;
  var_cas_proc_dyn_imp = GGS_string (true, "CONSTP2VAR(tpl_proc, AUTOMATIC, OS_APPL_DATA)\n"
    "tpl_dyn_proc_table[TASK_COUNT+ISR_COUNT+1] = {\n") ;
  var_cas_event_imp = GGS_string (true, "CONSTP2VAR(tpl_task_events, AUTOMATIC, OS_APPL_DATA)\n"
    "tpl_task_events_table[EXTENDED_TASK_COUNT] = {\n") ;
  {
    GGS_tasks_by_type::cEnumerator enumerator_2911 (var_cas_stasks, true) ;
    const GGS_tasks_by_type::cElement * operand_2911 = NULL ;
    while (((operand_2911 = enumerator_2911.nextObject ()))) {
      macroValidPointer (operand_2911) ;
      var_cas_proc_stat_imp.appendCstring ("  &") ;
      var_cas_proc_stat_imp._dotAssign_operation (operand_2911->name) ;
      var_cas_proc_stat_imp.appendCstring ("_task_stat_desc,\n") ;
      var_cas_proc_dyn_imp.appendCstring ("  &") ;
      var_cas_proc_dyn_imp._dotAssign_operation (operand_2911->name) ;
      var_cas_proc_dyn_imp.appendCstring ("_task_desc,\n") ;
    }
  }
  GGS_uint  var_cas_ct ;
  var_cas_ct = GGS_uint (true, 0U) ;
  {
    GGS_tasks_by_type::cEnumerator enumerator_3105 (var_cas_stasks, true) ;
    const GGS_tasks_by_type::cElement * operand_3105 = enumerator_3105.nextObject () ;
    if ((operand_3105 != NULL)) {
      bool _foreach_loop_3105 ;
      do{
        macroValidPointer (operand_3105) ;
        if (((operand_3105->type)._operator_isEqual (GGS_uint (true, 0U))).isBuiltAndTrue ()) {
          var_cas_ct._increment_operation (_inLexique COMMA_SOURCE_FILE_AT_LINE (104)) ;
          var_cas_event_imp.appendCstring ("  &") ;
          var_cas_event_imp._dotAssign_operation (operand_3105->name) ;
          var_cas_event_imp.appendCstring ("_task_evts") ;
          if (((var_cas_ct)._operator_strictInf (var_cas_ex_t_ct)).isBuiltAndTrue ()) {
            var_cas_event_imp.appendCstring (",\n") ;
          }
        }
        operand_3105 = enumerator_3105.nextObject () ;
        _foreach_loop_3105 = ((operand_3105 != NULL)) ;
        if (_foreach_loop_3105) {
        }
      }while (_foreach_loop_3105) ;
      var_cas_event_imp.appendCstring ("\n"
        "};") ;
    }
  }
  {
    GGS_isr_map::cEnumerator enumerator_3340 (var_cas_isrs, true) ;
    const GGS_isr_map::cElement * operand_3340 = NULL ;
    while (((operand_3340 = enumerator_3340.nextObject ()))) {
      macroValidPointer (operand_3340) ;
      var_cas_proc_stat_imp.appendCstring ("  &") ;
      var_cas_proc_stat_imp._dotAssign_operation (operand_3340->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (115))) ;
      var_cas_proc_stat_imp.appendCstring ("_isr_stat_desc,\n") ;
      var_cas_proc_dyn_imp.appendCstring ("  &") ;
      var_cas_proc_dyn_imp._dotAssign_operation (operand_3340->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (116))) ;
      var_cas_proc_dyn_imp.appendCstring ("_isr_desc,\n") ;
    }
  }
  var_cas_proc_stat_imp.appendCstring ("  &idle_task_static\n"
    "};\n") ;
  var_cas_proc_dyn_imp.appendCstring ("  &idle_task\n"
    "};\n") ;
  {
    GGS_isr_map::cEnumerator enumerator_3584 (var_cas_isrs, true) ;
    const GGS_isr_map::cElement * operand_3584 = enumerator_3584.nextObject () ;
    if ((operand_3584 != NULL)) {
      var_cas_isr_ena_imp = GGS_string (true, "VAR(tpl_isr2_enable_state, OS_VAR)\n"
        "tpl_isr2_enable_table[ISR_COUNT] = {\n") ;
      var_cas_isr_stat_imp = GGS_string (true, "CONSTP2CONST(tpl_isr_static, AUTOMATIC, OS_APPL_DATA)\n"
        "tpl_isr_stat_table[ISR_COUNT] = {\n") ;
      bool _foreach_loop_3584 ;
      do{
        macroValidPointer (operand_3584) ;
        var_cas_isr_stat_imp.appendCstring ("  &") ;
        var_cas_isr_stat_imp._dotAssign_operation (operand_3584->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (127))) ;
        var_cas_isr_stat_imp.appendCstring ("_isr_helper") ;
        var_cas_isr_ena_imp.appendCstring ("  ENABLED") ;
        operand_3584 = enumerator_3584.nextObject () ;
        _foreach_loop_3584 = ((operand_3584 != NULL)) ;
        if (_foreach_loop_3584) {
          var_cas_isr_stat_imp.appendCstring (",\n") ;
          var_cas_isr_ena_imp.appendCstring (",\n") ;
        }
      }while (_foreach_loop_3584) ;
      var_cas_isr_stat_imp.appendCstring ("\n"
        "};") ;
      var_cas_isr_ena_imp.appendCstring ("\n"
        "};") ;
    }
  }
  ::routine_doReplace (_inLexique,  var_cas_imp,  GGS_string (true, "$PROCIDS$"),  var_cas_proc_ids COMMA_SOURCE_FILE_AT_LINE (138)) ;
  ::routine_doReplace (_inLexique,  var_cas_head,  GGS_string (true, "$PROC_NAMES$"),  var_cas_names_head COMMA_SOURCE_FILE_AT_LINE (139)) ;
  ::routine_doReplace (_inLexique,  var_cas_imp,  GGS_string (true, "$PROC_NAMES$"),  var_cas_names_imp COMMA_SOURCE_FILE_AT_LINE (140)) ;
  ::routine_doReplace (_inLexique,  var_cas_imp,  GGS_string (true, "$PROC_STATIC_TABLE$"),  var_cas_proc_stat_imp COMMA_SOURCE_FILE_AT_LINE (141)) ;
  ::routine_doReplace (_inLexique,  var_cas_imp,  GGS_string (true, "$PROC_DYNAMIC_TABLE$"),  var_cas_proc_dyn_imp COMMA_SOURCE_FILE_AT_LINE (142)) ;
  ::routine_doReplace (_inLexique,  var_cas_imp,  GGS_string (true, "$TASK_EVENTS_TABLE$"),  var_cas_event_imp COMMA_SOURCE_FILE_AT_LINE (143)) ;
  ::routine_doReplace (_inLexique,  var_cas_imp,  GGS_string (true, "$ISR_HELPER_TABLE$"),  var_cas_isr_stat_imp COMMA_SOURCE_FILE_AT_LINE (144)) ;
  ::routine_doReplace (_inLexique,  var_cas_imp,  GGS_string (true, "$ISR_ENABLE_TABLE$"),  var_cas_isr_ena_imp COMMA_SOURCE_FILE_AT_LINE (145)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_generate_proc_table\n") ;
  #endif
}

//---------------------------------------------------------------------------*
