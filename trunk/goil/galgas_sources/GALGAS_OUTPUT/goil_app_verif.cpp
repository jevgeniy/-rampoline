//---------------------------------------------------------------------------*
//                                                                           *
//                        File 'goil_app_verif.cpp'                          *
//                        Generated by version 1.8.0                         *
//                      march 6th, 2009, at 21h20'29"                        *
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
#include "goil_app_verif.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_app_verif.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                Implementation of routine "object_exists"                  *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_object_exists (C_Compiler & _inLexique,
                                GGS_stringset   var_cas_def,
                                GGS_lstringlist   var_cas_ref,
                                GGS_string  var_cas_obj_type COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_object_exists at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  {
    GGS_lstringlist::cEnumerator enumerator_384 (var_cas_ref, true) ;
    const GGS_lstringlist::cElement * operand_384 = NULL ;
    while (((operand_384 = enumerator_384.nextObject ()))) {
      macroValidPointer (operand_384) ;
      if (((var_cas_def.reader_hasKey (_inLexique, operand_384->mValue.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (14)) COMMA_SOURCE_FILE_AT_LINE (14)))._operator_not ()).isBuiltAndTrue ()) {
        operand_384->mValue.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, (((var_cas_obj_type)._operator_concat (GGS_string (true, " ")))._operator_concat (operand_384->mValue.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (15))))._operator_concat (GGS_string (true, " referenced does not exist")) COMMA_SOURCE_FILE_AT_LINE (16)) ;
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_object_exists\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//                Implementation of routine "object_in_one"                  *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_object_in_one (C_Compiler & _inLexique,
                                GGS_lstringlist  & var_cas_objects,
                                GGS_lstring   var_cas_sName,
                                GGS_string  var_cas_kind COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_object_in_one at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_bool var_cas_not_found ;
  var_cas_not_found = GGS_bool (true, true) ;
  {
    GGS_lstringlist::cEnumerator enumerator_696 (var_cas_objects, true) ;
    const GGS_lstringlist::cElement * operand_696 = NULL ;
    while (((operand_696 = enumerator_696.nextObject ()))) {
      macroValidPointer (operand_696) ;
      if (((operand_696->mValue.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (28)))._operator_isEqual (var_cas_sName.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (28)))).isBuiltAndTrue ()) {
        var_cas_not_found = GGS_bool (true, false) ;
        var_cas_sName.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, (((var_cas_kind)._operator_concat (GGS_string (true, " ")))._operator_concat (var_cas_sName.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (30))))._operator_concat (GGS_string (true, " is already part of an OS Application")) COMMA_SOURCE_FILE_AT_LINE (31)) ;
        operand_696->mValue.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "It has been declared here") COMMA_SOURCE_FILE_AT_LINE (32)) ;
      }
    }
  }
  if ((var_cas_not_found).isBuiltAndTrue ()) {
    var_cas_objects._addAssign_operation (var_cas_sName) ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_object_in_one\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of routine "object_not_in_any"                *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_object_not_in_any (C_Compiler & _inLexique,
                                GGS_lstringlist   var_cas_objs,
                                GGS_stringset   var_cas_app_objs,
                                GGS_string  var_cas_obj_kind COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_object_not_in_any at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  {
    GGS_lstringlist::cEnumerator enumerator_1169 (var_cas_objs, true) ;
    const GGS_lstringlist::cElement * operand_1169 = NULL ;
    while (((operand_1169 = enumerator_1169.nextObject ()))) {
      macroValidPointer (operand_1169) ;
      GGS_string var_cas_name ;
      var_cas_name = operand_1169->mValue.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (46)) ;
      if (((var_cas_app_objs.reader_hasKey (_inLexique, var_cas_name COMMA_SOURCE_FILE_AT_LINE (47)))._operator_not ()).isBuiltAndTrue ()) {
        operand_1169->mValue.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, (((var_cas_obj_kind)._operator_concat (GGS_string (true, " ")))._operator_concat (var_cas_name))._operator_concat (GGS_string (true, " does not belong to any OS Application")) COMMA_SOURCE_FILE_AT_LINE (49)) ;
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_object_not_in_any\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//               Implementation of routine "apps_well_formed"                *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_apps_well_formed (C_Compiler & _inLexique,
                                GGS_app_map   var_cas_apps,
                                GGS_task_map   var_cas_tasks,
                                GGS_isr_map   var_cas_isrs,
                                GGS_alarm_map   var_cas_alarms,
                                GGS_scheduletable_map   var_cas_schedtables,
                                GGS_counter_map   var_cas_counters,
                                GGS_resource_map   var_cas_resources,
                                GGS_message_map   var_cas_messages COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_apps_well_formed at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  if (((var_cas_apps.reader_count (_inLexique COMMA_SOURCE_FILE_AT_LINE (63)))._operator_strictSup (GGS_uint (true, 0U))).isBuiltAndTrue ()) {
    {
      GGS_app_map::cEnumerator enumerator_1764 (var_cas_apps, true) ;
      const GGS_app_map::cElement * operand_1764 = NULL ;
      while (((operand_1764 = enumerator_1764.nextObject ()))) {
        macroValidPointer (operand_1764) ;
        ::routine_object_exists (_inLexique,  var_cas_tasks.reader_allKeys (_inLexique COMMA_SOURCE_FILE_AT_LINE (66)),  operand_1764->mInfo.app.reader_tasks (_inLexique COMMA_SOURCE_FILE_AT_LINE (66)).reader_keyList (_inLexique COMMA_SOURCE_FILE_AT_LINE (66)),  GGS_string (true, "Task") COMMA_SOURCE_FILE_AT_LINE (66)) ;
        ::routine_object_exists (_inLexique,  var_cas_isrs.reader_allKeys (_inLexique COMMA_SOURCE_FILE_AT_LINE (67)),  operand_1764->mInfo.app.reader_isrs (_inLexique COMMA_SOURCE_FILE_AT_LINE (67)).reader_keyList (_inLexique COMMA_SOURCE_FILE_AT_LINE (67)),  GGS_string (true, "ISR") COMMA_SOURCE_FILE_AT_LINE (67)) ;
        ::routine_object_exists (_inLexique,  var_cas_alarms.reader_allKeys (_inLexique COMMA_SOURCE_FILE_AT_LINE (68)),  operand_1764->mInfo.app.reader_alarms (_inLexique COMMA_SOURCE_FILE_AT_LINE (68)).reader_keyList (_inLexique COMMA_SOURCE_FILE_AT_LINE (68)),  GGS_string (true, "Alarm") COMMA_SOURCE_FILE_AT_LINE (68)) ;
        ::routine_object_exists (_inLexique,  var_cas_schedtables.reader_allKeys (_inLexique COMMA_SOURCE_FILE_AT_LINE (69)),  operand_1764->mInfo.app.reader_schedtables (_inLexique COMMA_SOURCE_FILE_AT_LINE (69)).reader_keyList (_inLexique COMMA_SOURCE_FILE_AT_LINE (69)),  GGS_string (true, "Schedule Table") COMMA_SOURCE_FILE_AT_LINE (69)) ;
        ::routine_object_exists (_inLexique,  var_cas_counters.reader_allKeys (_inLexique COMMA_SOURCE_FILE_AT_LINE (70)),  operand_1764->mInfo.app.reader_counters (_inLexique COMMA_SOURCE_FILE_AT_LINE (70)).reader_keyList (_inLexique COMMA_SOURCE_FILE_AT_LINE (70)),  GGS_string (true, "Counter") COMMA_SOURCE_FILE_AT_LINE (70)) ;
        ::routine_object_exists (_inLexique,  var_cas_resources.reader_allKeys (_inLexique COMMA_SOURCE_FILE_AT_LINE (71)),  operand_1764->mInfo.app.reader_resources (_inLexique COMMA_SOURCE_FILE_AT_LINE (71)).reader_keyList (_inLexique COMMA_SOURCE_FILE_AT_LINE (71)),  GGS_string (true, "Resource") COMMA_SOURCE_FILE_AT_LINE (71)) ;
      }
    }
    GGS_stringset  var_cas_all_apps ;
    var_cas_all_apps = var_cas_apps.reader_allKeys (_inLexique COMMA_SOURCE_FILE_AT_LINE (76)) ;
    {
      GGS_task_map::cEnumerator enumerator_2451 (var_cas_tasks, true) ;
      const GGS_task_map::cElement * operand_2451 = NULL ;
      while (((operand_2451 = enumerator_2451.nextObject ()))) {
        macroValidPointer (operand_2451) ;
        ::routine_object_exists (_inLexique,  var_cas_all_apps,  operand_2451->mInfo.task.reader_acc_apps (_inLexique COMMA_SOURCE_FILE_AT_LINE (78)),  GGS_string (true, "Application") COMMA_SOURCE_FILE_AT_LINE (78)) ;
      }
    }
    {
      GGS_isr_map::cEnumerator enumerator_2553 (var_cas_isrs, true) ;
      const GGS_isr_map::cElement * operand_2553 = NULL ;
      while (((operand_2553 = enumerator_2553.nextObject ()))) {
        macroValidPointer (operand_2553) ;
        ::routine_object_exists (_inLexique,  var_cas_all_apps,  operand_2553->mInfo.isr.reader_acc_apps (_inLexique COMMA_SOURCE_FILE_AT_LINE (81)),  GGS_string (true, "Application") COMMA_SOURCE_FILE_AT_LINE (81)) ;
      }
    }
    {
      GGS_alarm_map::cEnumerator enumerator_2656 (var_cas_alarms, true) ;
      const GGS_alarm_map::cElement * operand_2656 = NULL ;
      while (((operand_2656 = enumerator_2656.nextObject ()))) {
        macroValidPointer (operand_2656) ;
        ::routine_object_exists (_inLexique,  var_cas_all_apps,  operand_2656->mInfo.alarm.reader_acc_apps (_inLexique COMMA_SOURCE_FILE_AT_LINE (84)),  GGS_string (true, "Application") COMMA_SOURCE_FILE_AT_LINE (84)) ;
      }
    }
    {
      GGS_scheduletable_map::cEnumerator enumerator_2766 (var_cas_schedtables, true) ;
      const GGS_scheduletable_map::cElement * operand_2766 = NULL ;
      while (((operand_2766 = enumerator_2766.nextObject ()))) {
        macroValidPointer (operand_2766) ;
        ::routine_object_exists (_inLexique,  var_cas_all_apps,  operand_2766->mInfo.st.reader_acc_apps (_inLexique COMMA_SOURCE_FILE_AT_LINE (87)),  GGS_string (true, "Application") COMMA_SOURCE_FILE_AT_LINE (87)) ;
      }
    }
    {
      GGS_counter_map::cEnumerator enumerator_2870 (var_cas_counters, true) ;
      const GGS_counter_map::cElement * operand_2870 = NULL ;
      while (((operand_2870 = enumerator_2870.nextObject ()))) {
        macroValidPointer (operand_2870) ;
        ::routine_object_exists (_inLexique,  var_cas_all_apps,  operand_2870->mInfo.counter.reader_acc_apps (_inLexique COMMA_SOURCE_FILE_AT_LINE (90)),  GGS_string (true, "Application") COMMA_SOURCE_FILE_AT_LINE (90)) ;
      }
    }
    {
      GGS_resource_map::cEnumerator enumerator_2980 (var_cas_resources, true) ;
      const GGS_resource_map::cElement * operand_2980 = NULL ;
      while (((operand_2980 = enumerator_2980.nextObject ()))) {
        macroValidPointer (operand_2980) ;
        ::routine_object_exists (_inLexique,  var_cas_all_apps,  operand_2980->mInfo.resource.reader_acc_apps (_inLexique COMMA_SOURCE_FILE_AT_LINE (93)),  GGS_string (true, "Application") COMMA_SOURCE_FILE_AT_LINE (93)) ;
      }
    }
    {
      GGS_message_map::cEnumerator enumerator_3090 (var_cas_messages, true) ;
      const GGS_message_map::cElement * operand_3090 = NULL ;
      while (((operand_3090 = enumerator_3090.nextObject ()))) {
        macroValidPointer (operand_3090) ;
        ::routine_object_exists (_inLexique,  var_cas_all_apps,  operand_3090->mInfo.mess.reader_acc_apps (_inLexique COMMA_SOURCE_FILE_AT_LINE (96)),  GGS_string (true, "Application") COMMA_SOURCE_FILE_AT_LINE (96)) ;
      }
    }
    GGS_lstringlist  var_cas_objects ;
    var_cas_objects = GGS_lstringlist ::constructor_emptyList () ;
    {
      GGS_app_map::cEnumerator enumerator_3282 (var_cas_apps, true) ;
      const GGS_app_map::cElement * operand_3282 = NULL ;
      while (((operand_3282 = enumerator_3282.nextObject ()))) {
        macroValidPointer (operand_3282) ;
        {
          GGS_ident_map::cEnumerator enumerator_3301 (operand_3282->mInfo.app.reader_tasks (_inLexique COMMA_SOURCE_FILE_AT_LINE (102)), true) ;
          const GGS_ident_map::cElement * operand_3301 = NULL ;
          while (((operand_3301 = enumerator_3301.nextObject ()))) {
            macroValidPointer (operand_3301) ;
            ::routine_object_in_one (_inLexique,  var_cas_objects,  operand_3301->mKey,  GGS_string (true, "TASK") COMMA_SOURCE_FILE_AT_LINE (102)) ;
          }
        }
        {
          GGS_ident_map::cEnumerator enumerator_3383 (operand_3282->mInfo.app.reader_isrs (_inLexique COMMA_SOURCE_FILE_AT_LINE (103)), true) ;
          const GGS_ident_map::cElement * operand_3383 = NULL ;
          while (((operand_3383 = enumerator_3383.nextObject ()))) {
            macroValidPointer (operand_3383) ;
            ::routine_object_in_one (_inLexique,  var_cas_objects,  operand_3383->mKey,  GGS_string (true, "ISR") COMMA_SOURCE_FILE_AT_LINE (103)) ;
          }
        }
        {
          GGS_ident_map::cEnumerator enumerator_3463 (operand_3282->mInfo.app.reader_alarms (_inLexique COMMA_SOURCE_FILE_AT_LINE (104)), true) ;
          const GGS_ident_map::cElement * operand_3463 = NULL ;
          while (((operand_3463 = enumerator_3463.nextObject ()))) {
            macroValidPointer (operand_3463) ;
            ::routine_object_in_one (_inLexique,  var_cas_objects,  operand_3463->mKey,  GGS_string (true, "ALARM") COMMA_SOURCE_FILE_AT_LINE (104)) ;
          }
        }
        {
          GGS_ident_map::cEnumerator enumerator_3547 (operand_3282->mInfo.app.reader_schedtables (_inLexique COMMA_SOURCE_FILE_AT_LINE (105)), true) ;
          const GGS_ident_map::cElement * operand_3547 = NULL ;
          while (((operand_3547 = enumerator_3547.nextObject ()))) {
            macroValidPointer (operand_3547) ;
            ::routine_object_in_one (_inLexique,  var_cas_objects,  operand_3547->mKey,  GGS_string (true, "SCHEDULETABLE") COMMA_SOURCE_FILE_AT_LINE (105)) ;
          }
        }
        {
          GGS_ident_map::cEnumerator enumerator_3644 (operand_3282->mInfo.app.reader_counters (_inLexique COMMA_SOURCE_FILE_AT_LINE (106)), true) ;
          const GGS_ident_map::cElement * operand_3644 = NULL ;
          while (((operand_3644 = enumerator_3644.nextObject ()))) {
            macroValidPointer (operand_3644) ;
            ::routine_object_in_one (_inLexique,  var_cas_objects,  operand_3644->mKey,  GGS_string (true, "COUNTER") COMMA_SOURCE_FILE_AT_LINE (106)) ;
          }
        }
        {
          GGS_ident_map::cEnumerator enumerator_3732 (operand_3282->mInfo.app.reader_resources (_inLexique COMMA_SOURCE_FILE_AT_LINE (107)), true) ;
          const GGS_ident_map::cElement * operand_3732 = NULL ;
          while (((operand_3732 = enumerator_3732.nextObject ()))) {
            macroValidPointer (operand_3732) ;
            ::routine_object_in_one (_inLexique,  var_cas_objects,  operand_3732->mKey,  GGS_string (true, "RESOURCE") COMMA_SOURCE_FILE_AT_LINE (107)) ;
          }
        }
      }
    }
    GGS_stringset  var_cas_all_tasks_in_app ;
    var_cas_all_tasks_in_app = GGS_stringset ::constructor_emptySet () ;
    GGS_stringset  var_cas_all_isrs_in_app ;
    var_cas_all_isrs_in_app = GGS_stringset ::constructor_emptySet () ;
    GGS_stringset  var_cas_all_alarms_in_app ;
    var_cas_all_alarms_in_app = GGS_stringset ::constructor_emptySet () ;
    GGS_stringset  var_cas_all_sts_in_app ;
    var_cas_all_sts_in_app = GGS_stringset ::constructor_emptySet () ;
    GGS_stringset  var_cas_all_cnts_in_app ;
    var_cas_all_cnts_in_app = GGS_stringset ::constructor_emptySet () ;
    GGS_stringset  var_cas_all_rezs_in_app ;
    var_cas_all_rezs_in_app = GGS_stringset ::constructor_emptySet () ;
    {
      GGS_app_map::cEnumerator enumerator_4248 (var_cas_apps, true) ;
      const GGS_app_map::cElement * operand_4248 = NULL ;
      while (((operand_4248 = enumerator_4248.nextObject ()))) {
        macroValidPointer (operand_4248) ;
        var_cas_all_tasks_in_app = (var_cas_all_tasks_in_app)._operator_or (operand_4248->mInfo.app.reader_tasks (_inLexique COMMA_SOURCE_FILE_AT_LINE (120)).reader_allKeys (_inLexique COMMA_SOURCE_FILE_AT_LINE (120))) ;
        var_cas_all_isrs_in_app = (var_cas_all_isrs_in_app)._operator_or (operand_4248->mInfo.app.reader_isrs (_inLexique COMMA_SOURCE_FILE_AT_LINE (121)).reader_allKeys (_inLexique COMMA_SOURCE_FILE_AT_LINE (121))) ;
        var_cas_all_alarms_in_app = (var_cas_all_alarms_in_app)._operator_or (operand_4248->mInfo.app.reader_alarms (_inLexique COMMA_SOURCE_FILE_AT_LINE (122)).reader_allKeys (_inLexique COMMA_SOURCE_FILE_AT_LINE (122))) ;
        var_cas_all_sts_in_app = (var_cas_all_sts_in_app)._operator_or (operand_4248->mInfo.app.reader_schedtables (_inLexique COMMA_SOURCE_FILE_AT_LINE (123)).reader_allKeys (_inLexique COMMA_SOURCE_FILE_AT_LINE (123))) ;
        var_cas_all_cnts_in_app = (var_cas_all_cnts_in_app)._operator_or (operand_4248->mInfo.app.reader_counters (_inLexique COMMA_SOURCE_FILE_AT_LINE (124)).reader_allKeys (_inLexique COMMA_SOURCE_FILE_AT_LINE (124))) ;
        var_cas_all_rezs_in_app = (var_cas_all_rezs_in_app)._operator_or (operand_4248->mInfo.app.reader_resources (_inLexique COMMA_SOURCE_FILE_AT_LINE (125)).reader_allKeys (_inLexique COMMA_SOURCE_FILE_AT_LINE (125))) ;
      }
    }
    ::routine_object_not_in_any (_inLexique,  var_cas_tasks.reader_keyList (_inLexique COMMA_SOURCE_FILE_AT_LINE (129)),  var_cas_all_tasks_in_app,  GGS_string (true, "TASK") COMMA_SOURCE_FILE_AT_LINE (129)) ;
    ::routine_object_not_in_any (_inLexique,  var_cas_isrs.reader_keyList (_inLexique COMMA_SOURCE_FILE_AT_LINE (131)),  var_cas_all_isrs_in_app,  GGS_string (true, "ISR") COMMA_SOURCE_FILE_AT_LINE (131)) ;
    ::routine_object_not_in_any (_inLexique,  var_cas_alarms.reader_keyList (_inLexique COMMA_SOURCE_FILE_AT_LINE (133)),  var_cas_all_alarms_in_app,  GGS_string (true, "ALARM") COMMA_SOURCE_FILE_AT_LINE (133)) ;
    ::routine_object_not_in_any (_inLexique,  var_cas_schedtables.reader_keyList (_inLexique COMMA_SOURCE_FILE_AT_LINE (135)),  var_cas_all_sts_in_app,  GGS_string (true, "SCHEDULETABLE") COMMA_SOURCE_FILE_AT_LINE (135)) ;
    ::routine_object_not_in_any (_inLexique,  var_cas_counters.reader_keyList (_inLexique COMMA_SOURCE_FILE_AT_LINE (137)),  var_cas_all_cnts_in_app,  GGS_string (true, "COUNTER") COMMA_SOURCE_FILE_AT_LINE (137)) ;
    ::routine_object_not_in_any (_inLexique,  var_cas_resources.reader_keyList (_inLexique COMMA_SOURCE_FILE_AT_LINE (139)),  var_cas_all_rezs_in_app,  GGS_string (true, "RESOURCE") COMMA_SOURCE_FILE_AT_LINE (139)) ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_apps_well_formed\n") ;
  #endif
}

//---------------------------------------------------------------------------*

