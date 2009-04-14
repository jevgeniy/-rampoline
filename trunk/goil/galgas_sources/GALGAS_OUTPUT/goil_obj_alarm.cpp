//---------------------------------------------------------------------------*
//                                                                           *
//                        File 'goil_obj_alarm.cpp'                          *
//                        Generated by version 1.8.0                         *
//                       march 7th, 2009, at 14h27'3"                        *
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
#include "goil_obj_alarm.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_obj_alarm.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                Implementation of production rule 'alarm'                  *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_alarm::
pr_alarm_goil_obj_alarm_47_12_ (goil_lexique & _inLexique,
                                GGS_alarm_map  &var_cas_alarms) {
  GGS_lstring  var_cas_alarm_name ;
  GGS_alarm_obj  var_cas_alarm ;
  GGS_action_obj  var_cas_alarm_action ;
  GGS_autostart_obj  var_cas_alarm_autostart ;
  GGS_lstring  var_cas_counter_name ;
  GGS_lstringlist  var_cas_acc_apps ;
  GGS_lstring  var_cas_desc ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_ALARM) COMMA_HERE) ;
  _inLexique._assignFromAttribute_att_token (var_cas_alarm_name) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
  if ((var_cas_alarms.reader_hasKey (_inLexique, var_cas_alarm_name.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (60)) COMMA_SOURCE_FILE_AT_LINE (60))).isBuiltAndTrue ()) {
    var_cas_alarms.modifier_del (_inLexique, var_cas_alarm_name, var_cas_alarm COMMA_SOURCE_FILE_AT_LINE (61)) ;
    var_cas_alarm_action = var_cas_alarm.reader_action_params (_inLexique COMMA_SOURCE_FILE_AT_LINE (62)) ;
    var_cas_alarm_autostart = var_cas_alarm.reader_autostart_params (_inLexique COMMA_SOURCE_FILE_AT_LINE (63)) ;
    var_cas_counter_name = var_cas_alarm.reader_counter_name (_inLexique COMMA_SOURCE_FILE_AT_LINE (64)) ;
    var_cas_acc_apps = var_cas_alarm.reader_acc_apps (_inLexique COMMA_SOURCE_FILE_AT_LINE (65)) ;
    var_cas_desc = var_cas_alarm.reader_desc (_inLexique COMMA_SOURCE_FILE_AT_LINE (66)) ;
  }else{
    var_cas_alarm_action = GGS_void_action ::constructor_new (_inLexique, GGS_location (_inLexique) COMMA_HERE) ;
    var_cas_alarm_autostart = GGS_autostart_void ::constructor_new (_inLexique, GGS_location (_inLexique) COMMA_HERE) ;
    var_cas_counter_name = GGS_lstring ::constructor_new (_inLexique, GGS_string (true, ""), GGS_location (_inLexique) COMMA_HERE) ;
    var_cas_acc_apps = GGS_lstringlist ::constructor_emptyList () ;
    var_cas_desc = GGS_lstring ::constructor_new (_inLexique, GGS_string (true, ""), GGS_location (_inLexique) COMMA_HERE) ;
    var_cas_alarm = GGS_alarm_obj ::constructor_new (_inLexique, var_cas_desc, var_cas_counter_name, var_cas_alarm_action, var_cas_alarm_autostart, var_cas_acc_apps COMMA_HERE) ;
  }
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B) COMMA_HERE) ;
  nt_alarm_parameters_ (_inLexique, var_cas_counter_name, var_cas_alarm_action, var_cas_alarm_autostart, var_cas_acc_apps) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D) COMMA_HERE) ;
  nt_description_ (_inLexique, var_cas_desc) ;
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
  var_cas_alarm = GGS_alarm_obj ::constructor_new (_inLexique, var_cas_desc, var_cas_counter_name, var_cas_alarm_action, var_cas_alarm_autostart, var_cas_acc_apps COMMA_HERE) ;
  var_cas_alarms.modifier_put (_inLexique, var_cas_alarm_name, var_cas_alarm COMMA_SOURCE_FILE_AT_LINE (83)) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//           Implementation of production rule 'alarm_parameters'            *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_alarm::
pr_alarm_parameters_goil_obj_alarm_86_23_ (goil_lexique & _inLexique,
                                GGS_lstring  &var_cas_counter_name,
                                GGS_action_obj  &var_cas_alarm_action,
                                GGS_autostart_obj  &var_cas_alarm_autostart,
                                GGS_lstringlist  &var_cas_acc_apps) {
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_repeat_goil_obj_alarm_0 (_inLexique)) {
        case 2 : {
          if (((var_cas_counter_name.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (94)))._operator_isNotEqual (GGS_string (true, ""))).isBuiltAndTrue ()) {
            GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "COUNTER attribute already defined for this alarm") COMMA_SOURCE_FILE_AT_LINE (96)) ;
            var_cas_counter_name.reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (96)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "was previously defined here") COMMA_SOURCE_FILE_AT_LINE (97)) ;
          }
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_COUNTER) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          _inLexique._assignFromAttribute_att_token (var_cas_counter_name) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          GGS_lstring  automatic_var_0 ;
          nt_description_ (_inLexique, automatic_var_0) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          } break ;
        case 3 : {
          { const GGS_action_obj _var_2738 = var_cas_alarm_action ; // CAST instruction
            if (_var_2738.getPtr () != NULL) {
              macroValidPointer (_var_2738.getPtr ()) ;
              if (typeid (cPtr_void_action) == typeid (* (_var_2738.getPtr ()))) {
              }else{
                GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "ACTION attribute already defined for this alarm") COMMA_SOURCE_FILE_AT_LINE (104)) ;
                var_cas_alarm_action.reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (104)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "was previously defined here") COMMA_SOURCE_FILE_AT_LINE (105)) ;
              }
            }
          }
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_ACTION) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          nt_alarm_action_params_ (_inLexique, var_cas_alarm_action) ;
          GGS_lstring  automatic_var_1 ;
          nt_description_ (_inLexique, automatic_var_1) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          } break ;
        case 4 : {
          { const GGS_autostart_obj _var_3063 = var_cas_alarm_autostart ; // CAST instruction
            if (_var_3063.getPtr () != NULL) {
              macroValidPointer (_var_3063.getPtr ()) ;
              if (typeid (cPtr_autostart_void) == typeid (* (_var_3063.getPtr ()))) {
              }else{
                GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "AUTOSTART attribute already defined for this alarm") COMMA_SOURCE_FILE_AT_LINE (112)) ;
                var_cas_alarm_autostart.reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (112)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "was previously defined here") COMMA_SOURCE_FILE_AT_LINE (113)) ;
              }
            }
          }
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_AUTOSTART) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          switch (select_goil_obj_alarm_1 (_inLexique)) {
            case 1 : {
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRUE) COMMA_HERE) ;
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B) COMMA_HERE) ;
              nt_alarm_autostart_params_ (_inLexique, var_cas_alarm_autostart) ;
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D) COMMA_HERE) ;
              } break ;
            case 2 : {
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_FALSE) COMMA_HERE) ;
              var_cas_alarm_autostart = GGS_autostart_false ::constructor_new (_inLexique, GGS_location (_inLexique) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          GGS_lstring  automatic_var_2 ;
          nt_description_ (_inLexique, automatic_var_2) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          } break ;
        case 5 : {
          GGS_lstring  var_cas_app ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_ACCESSING_5FAPPLICATION) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          _inLexique._assignFromAttribute_att_token (var_cas_app) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          GGS_lstring  automatic_var_3 ;
          nt_description_ (_inLexique, automatic_var_3) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          ::routine_add_lstring_unique (_inLexique,  var_cas_acc_apps,  var_cas_app,  GGS_string (true, "ACCESSING_APPLICATION") COMMA_SOURCE_FILE_AT_LINE (127)) ;
          } break ;
        case 6 : {
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          switch (select_goil_obj_alarm_2 (_inLexique)) {
            case 1 : {
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
              } break ;
            case 2 : {
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_uint_5Fnumber) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          } break ;
        default :
          syntaxRepeat_0 = false ;
          break ;
      }
    }
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//         Implementation of production rule 'alarm_action_params'           *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_alarm::
pr_alarm_action_params_goil_obj_alarm_133_26_ (goil_lexique & _inLexique,
                                GGS_action_obj  &var_cas_alarm_action) {
  switch (select_goil_obj_alarm_3 (_inLexique)) {
    case 1 : {
      GGS_lstring  var_cas_task_name ;
      var_cas_task_name = GGS_lstring ::constructor_new (_inLexique, GGS_string (true, ""), GGS_location (_inLexique) COMMA_HERE) ;
      GGS_lstring  var_cas_event_name ;
      var_cas_event_name = GGS_lstring ::constructor_new (_inLexique, GGS_string (true, ""), GGS_location (_inLexique) COMMA_HERE) ;
      _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_SETEVENT) COMMA_HERE) ;
      _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B) COMMA_HERE) ;
      { bool syntaxRepeat_4 = true ;
        while (syntaxRepeat_4) {
          switch (select_repeat_goil_obj_alarm_4 (_inLexique)) {
            case 2 : {
              if (((var_cas_task_name.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (142)))._operator_isNotEqual (GGS_string (true, ""))).isBuiltAndTrue ()) {
                GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "TASK attribute already defined for this alarm action") COMMA_SOURCE_FILE_AT_LINE (144)) ;
                var_cas_task_name.reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (144)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "was previously defined here") COMMA_SOURCE_FILE_AT_LINE (145)) ;
              }
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TASK) COMMA_HERE) ;
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
              _inLexique._assignFromAttribute_att_token (var_cas_task_name) ;
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
              GGS_lstring  automatic_var_4 ;
              nt_description_ (_inLexique, automatic_var_4) ;
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
              } break ;
            case 3 : {
              if (((var_cas_event_name.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (151)))._operator_isNotEqual (GGS_string (true, ""))).isBuiltAndTrue ()) {
                GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "EVENT attribute already defined for this alarm action") COMMA_SOURCE_FILE_AT_LINE (153)) ;
                var_cas_event_name.reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (153)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "was previously defined here") COMMA_SOURCE_FILE_AT_LINE (154)) ;
              }
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_EVENT) COMMA_HERE) ;
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
              _inLexique._assignFromAttribute_att_token (var_cas_event_name) ;
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
              GGS_lstring  automatic_var_5 ;
              nt_description_ (_inLexique, automatic_var_5) ;
              _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
              } break ;
            default :
              syntaxRepeat_4 = false ;
              break ;
          }
        }
      }
      var_cas_alarm_action = GGS_setevent_action ::constructor_new (_inLexique, GGS_location (_inLexique), var_cas_task_name, var_cas_event_name COMMA_HERE) ;
      } break ;
    case 2 : {
      GGS_lstring  var_cas_task_name ;
      _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_ACTIVATETASK) COMMA_HERE) ;
      _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B) COMMA_HERE) ;
      _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TASK) COMMA_HERE) ;
      _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
      _inLexique._assignFromAttribute_att_token (var_cas_task_name) ;
      _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
      GGS_lstring  automatic_var_6 ;
      nt_description_ (_inLexique, automatic_var_6) ;
      _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
      var_cas_alarm_action = GGS_activatetask_action ::constructor_new (_inLexique, GGS_location (_inLexique), var_cas_task_name COMMA_HERE) ;
      } break ;
    case 3 : {
      if ((GGS_bool (true, _inLexique.boolOptionValueFromKeys ("goil_options", "autosar_on" COMMA_SOURCE_FILE_AT_LINE (168)))).isBuiltAndTrue ()) {
        GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "AUTOSAR flag is on. AUTOSAR spec does not allow alarm callback") COMMA_SOURCE_FILE_AT_LINE (170)) ;
      }
      GGS_lstring  var_cas_function_name ;
      _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_ALARMCALLBACK) COMMA_HERE) ;
      _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B) COMMA_HERE) ;
      _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_ALARMCALLBACKNAME) COMMA_HERE) ;
      _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
      _inLexique._assignFromAttribute_a_string (var_cas_function_name) ;
      _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_string) COMMA_HERE) ;
      GGS_lstring  automatic_var_7 ;
      nt_description_ (_inLexique, automatic_var_7) ;
      _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
      var_cas_alarm_action = GGS_callback_action ::constructor_new (_inLexique, GGS_location (_inLexique), var_cas_function_name COMMA_HERE) ;
      } break ;
    case 4 : {
      if (((GGS_bool (true, _inLexique.boolOptionValueFromKeys ("goil_options", "autosar_on" COMMA_SOURCE_FILE_AT_LINE (177))))._operator_isEqual (GGS_bool (true, false))).isBuiltAndTrue ()) {
        GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "AUTOSAR flag is off. Turn it on to allow an INCREMENTCOUNTER action in alarm") COMMA_SOURCE_FILE_AT_LINE (179)) ;
      }
      GGS_lstring  var_cas_counter_name ;
      _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_INCREMENTCOUNTER) COMMA_HERE) ;
      _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B) COMMA_HERE) ;
      _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_COUNTER) COMMA_HERE) ;
      _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
      _inLexique._assignFromAttribute_att_token (var_cas_counter_name) ;
      _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
      GGS_lstring  automatic_var_8 ;
      nt_description_ (_inLexique, automatic_var_8) ;
      _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
      var_cas_alarm_action = GGS_incrementcounter_action ::constructor_new (_inLexique, GGS_location (_inLexique), var_cas_counter_name COMMA_HERE) ;
      } break ;
    default :
      break ;
  }
  _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//        Implementation of production rule 'alarm_autostart_params'         *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_alarm::
pr_alarm_autostart_params_goil_obj_alarm_189_29_ (goil_lexique & _inLexique,
                                GGS_autostart_obj  &var_cas_alarm_autostart) {
  GGS_bool var_cas_alarm_time_known ;
  var_cas_alarm_time_known = GGS_bool (true, false) ;
  GGS_bool var_cas_cycle_time_known ;
  var_cas_cycle_time_known = GGS_bool (true, false) ;
  GGS_luint64  var_cas_alarm_time ;
  var_cas_alarm_time = GGS_luint64 ::constructor_new (_inLexique, GGS_uint64 (true, 0LLU), GGS_location (_inLexique) COMMA_HERE) ;
  GGS_luint64  var_cas_cycle_time ;
  var_cas_cycle_time = GGS_luint64 ::constructor_new (_inLexique, GGS_uint64 (true, 0LLU), GGS_location (_inLexique) COMMA_HERE) ;
  GGS_lstring  var_cas_app_mode ;
  var_cas_app_mode = GGS_lstring ::constructor_new (_inLexique, GGS_string (true, ""), GGS_location (_inLexique) COMMA_HERE) ;
  GGS_stringset  var_cas_app_modes ;
  var_cas_app_modes = GGS_stringset ::constructor_emptySet () ;
  { bool syntaxRepeat_5 = true ;
    while (syntaxRepeat_5) {
      switch (select_repeat_goil_obj_alarm_5 (_inLexique)) {
        case 2 : {
          if ((var_cas_alarm_time_known).isBuiltAndTrue ()) {
            GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "ALARMTIME attribute already defined for this alarm autostart") COMMA_SOURCE_FILE_AT_LINE (204)) ;
            var_cas_alarm_time.reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (204)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "was previously defined here") COMMA_SOURCE_FILE_AT_LINE (205)) ;
          }
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_ALARMTIME) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          _inLexique._assignFromAttribute_integerNumber (var_cas_alarm_time) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_uint_5Fnumber) COMMA_HERE) ;
          GGS_lstring  automatic_var_9 ;
          nt_description_ (_inLexique, automatic_var_9) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          var_cas_alarm_time_known = GGS_bool (true, true) ;
          } break ;
        case 3 : {
          if ((var_cas_cycle_time_known).isBuiltAndTrue ()) {
            GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "CYCLETIME attribute already defined for this alarm autostart") COMMA_SOURCE_FILE_AT_LINE (211)) ;
            var_cas_cycle_time.reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (211)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "was previously defined here") COMMA_SOURCE_FILE_AT_LINE (212)) ;
          }
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_CYCLETIME) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          _inLexique._assignFromAttribute_integerNumber (var_cas_cycle_time) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_uint_5Fnumber) COMMA_HERE) ;
          GGS_lstring  automatic_var_10 ;
          nt_description_ (_inLexique, automatic_var_10) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          var_cas_cycle_time_known = GGS_bool (true, true) ;
          } break ;
        case 4 : {
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_APPMODE) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D) COMMA_HERE) ;
          _inLexique._assignFromAttribute_att_token (var_cas_app_mode) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          GGS_lstring  automatic_var_11 ;
          nt_description_ (_inLexique, automatic_var_11) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B) COMMA_HERE) ;
          var_cas_app_modes._addAssign_operation (var_cas_app_mode.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (217))) ;
          } break ;
        default :
          syntaxRepeat_5 = false ;
          break ;
      }
    }
  }
  if (((var_cas_alarm_time_known)._operator_not ()).isBuiltAndTrue ()) {
    GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "ALARMTIME attribute is missing") COMMA_SOURCE_FILE_AT_LINE (223)) ;
  }
  var_cas_alarm_autostart = GGS_alarm_autostart_true ::constructor_new (_inLexique, GGS_location (_inLexique), var_cas_alarm_time, var_cas_cycle_time, var_cas_app_modes COMMA_HERE) ;
}

//---------------------------------------------------------------------------*

