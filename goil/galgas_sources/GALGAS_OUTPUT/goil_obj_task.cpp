//---------------------------------------------------------------------------*
//                                                                           *
//                         File 'goil_obj_task.cpp'                          *
//                        Generated by version 1.8.5                         *
//                      june 19th, 2009, at 17h46'39"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 515
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "goil_obj_task.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_obj_task.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                 Implementation of production rule 'task'                  *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_task::
pr_task_goil_obj_task_64_11_ (goil_lexique & inLexique,
                                GGS_task_map  &var_cas_tasks) {
  GGS_lstring  var_cas_task_name ;
  GGS_task_obj  var_cas_task ;
  GGS_basic_type  var_cas_priority ;
  GGS_lstring  var_cas_schedule ;
  GGS_basic_type  var_cas_activation ;
  GGS_task_autostart_obj  var_cas_autostart ;
  GGS_lstringlist  var_cas_resources ;
  GGS_lstringlist  var_cas_events ;
  GGS_lstringlist  var_cas_messages ;
  GGS_lstringlist  var_cas_acc_apps ;
  GGS_timing_prot  var_cas_timing_prot ;
  GGS_lstring  var_cas_desc ;
  GGS_ident_map  var_cas_others ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TASK) COMMA_HERE) ;
  inLexique.assignFromAttribute_att_token (var_cas_task_name) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
  if ((var_cas_tasks.reader_hasKey (inLexique, var_cas_task_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (83)) COMMA_SOURCE_FILE_AT_LINE (83))).isBuiltAndTrue ()) {
    var_cas_tasks.modifier_del (inLexique, var_cas_task_name, var_cas_task COMMA_SOURCE_FILE_AT_LINE (84)) ;
    var_cas_priority = var_cas_task.reader_priority (inLexique COMMA_SOURCE_FILE_AT_LINE (85)) ;
    var_cas_schedule = var_cas_task.reader_schedule (inLexique COMMA_SOURCE_FILE_AT_LINE (86)) ;
    var_cas_activation = var_cas_task.reader_activation (inLexique COMMA_SOURCE_FILE_AT_LINE (87)) ;
    var_cas_autostart = var_cas_task.reader_autostart (inLexique COMMA_SOURCE_FILE_AT_LINE (88)) ;
    var_cas_resources = var_cas_task.reader_resources (inLexique COMMA_SOURCE_FILE_AT_LINE (89)) ;
    var_cas_events = var_cas_task.reader_events (inLexique COMMA_SOURCE_FILE_AT_LINE (90)) ;
    var_cas_messages = var_cas_task.reader_messages (inLexique COMMA_SOURCE_FILE_AT_LINE (91)) ;
    var_cas_acc_apps = var_cas_task.reader_acc_apps (inLexique COMMA_SOURCE_FILE_AT_LINE (92)) ;
    var_cas_timing_prot = var_cas_task.reader_timing_prot (inLexique COMMA_SOURCE_FILE_AT_LINE (93)) ;
    var_cas_desc = var_cas_task.reader_desc (inLexique COMMA_SOURCE_FILE_AT_LINE (94)) ;
    var_cas_others = var_cas_task.reader_others (inLexique COMMA_SOURCE_FILE_AT_LINE (95)) ;
  }else{
    var_cas_priority = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
    var_cas_schedule = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_HERE) ;
    var_cas_activation = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
    var_cas_autostart = GGS_task_autostart_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
    var_cas_resources = GGS_lstringlist ::constructor_emptyList () ;
    var_cas_events = GGS_lstringlist ::constructor_emptyList () ;
    var_cas_messages = GGS_lstringlist ::constructor_emptyList () ;
    var_cas_acc_apps = GGS_lstringlist ::constructor_emptyList () ;
    var_cas_timing_prot = GGS_void_timing_prot ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
    var_cas_desc = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_HERE) ;
    var_cas_others = GGS_ident_map ::constructor_emptyMap (inLexique COMMA_HERE) ;
    var_cas_task = GGS_task_obj ::constructor_new (inLexique, var_cas_desc, var_cas_priority, var_cas_schedule, var_cas_activation, var_cas_autostart, var_cas_resources, var_cas_events, var_cas_messages, var_cas_acc_apps, var_cas_timing_prot, var_cas_others COMMA_HERE) ;
  }
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B_) COMMA_HERE) ;
  nt_task_attributes_ (inLexique, var_cas_priority, var_cas_schedule, var_cas_activation, var_cas_autostart, var_cas_resources, var_cas_events, var_cas_messages, var_cas_acc_apps, var_cas_timing_prot, var_cas_others) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D_) COMMA_HERE) ;
  nt_description_ (inLexique, var_cas_desc) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
  var_cas_task = GGS_task_obj ::constructor_new (inLexique, var_cas_desc, var_cas_priority, var_cas_schedule, var_cas_activation, var_cas_autostart, var_cas_resources, var_cas_events, var_cas_messages, var_cas_acc_apps, var_cas_timing_prot, var_cas_others COMMA_HERE) ;
  var_cas_tasks.modifier_put (inLexique, var_cas_task_name, var_cas_task COMMA_SOURCE_FILE_AT_LINE (151)) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//           Implementation of production rule 'task_attributes'             *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_task::
pr_task_attributes_goil_obj_task_154_22_ (goil_lexique & inLexique,
                                GGS_basic_type  &var_cas_priority,
                                GGS_lstring  &var_cas_schedule,
                                GGS_basic_type  &var_cas_activation,
                                GGS_task_autostart_obj  &var_cas_autostart,
                                GGS_lstringlist  &var_cas_resources,
                                GGS_lstringlist  &var_cas_events,
                                GGS_lstringlist  &var_cas_messages,
                                GGS_lstringlist  &var_cas_acc_apps,
                                GGS_timing_prot  &var_cas_timing_prot,
                                GGS_ident_map  &var_cas_others) {
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_repeat_goil_obj_task_0 (inLexique)) {
        case 2 : {
          GGS_luint64  var_cas_prio ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_PRIORITY) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_integerNumber (var_cas_prio) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_uint_5F_number) COMMA_HERE) ;
          GGS_lstring  automatic_var_0 ;
          nt_description_ (inLexique, automatic_var_0) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          ::routine_set_uint32 (inLexique,  var_cas_priority,  var_cas_prio,  GGS_string ("PRIORITY") COMMA_SOURCE_FILE_AT_LINE (170)) ;
          } break ;
        case 3 : {
          GGS_lstring  var_cas_sc ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_SCHEDULE) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          switch (select_goil_obj_task_1 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_FULL) COMMA_HERE) ;
              var_cas_sc = GGS_lstring ::constructor_new (inLexique, GGS_string ("FULL"), GGS_location (inLexique) COMMA_HERE) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_NON) COMMA_HERE) ;
              var_cas_sc = GGS_lstring ::constructor_new (inLexique, GGS_string ("NON"), GGS_location (inLexique) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          ::routine_set_lstring_if_empty (inLexique,  var_cas_schedule,  var_cas_sc,  GGS_string ("SCHEDULE") COMMA_SOURCE_FILE_AT_LINE (177)) ;
          GGS_lstring  automatic_var_1 ;
          nt_description_ (inLexique, automatic_var_1) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 4 : {
          GGS_task_autostart_obj  var_cas_auto ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_AUTOSTART) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          switch (select_goil_obj_task_2 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRUE) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B_) COMMA_HERE) ;
              nt_task_autostart_params_ (inLexique, var_cas_auto) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D_) COMMA_HERE) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_FALSE) COMMA_HERE) ;
              var_cas_auto = GGS_task_autostart_false ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          { const GGS_task_autostart_obj _var_4783 = var_cas_autostart ; // CAST instruction
            if (_var_4783.getPtr () != NULL) {
              macroValidPointer (_var_4783.getPtr ()) ;
              if (typeid (cPtr_task_autostart_void) == typeid (* (_var_4783.getPtr ()))) {
                var_cas_autostart = var_cas_auto ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Redefinition of AUTOSTART") COMMA_SOURCE_FILE_AT_LINE (190)) ;
                var_cas_autostart.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (190)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was defined here") COMMA_SOURCE_FILE_AT_LINE (191)) ;
              }
            }
          }
          GGS_lstring  automatic_var_2 ;
          nt_description_ (inLexique, automatic_var_2) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 5 : {
          GGS_luint64  var_cas_act ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_ACTIVATION) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_integerNumber (var_cas_act) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_uint_5F_number) COMMA_HERE) ;
          GGS_lstring  automatic_var_3 ;
          nt_description_ (inLexique, automatic_var_3) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          ::routine_set_uint32 (inLexique,  var_cas_activation,  var_cas_act,  GGS_string ("ACTIVATION") COMMA_SOURCE_FILE_AT_LINE (196)) ;
          } break ;
        case 6 : {
          GGS_lstring  var_cas_resource ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_RESOURCE) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_token (var_cas_resource) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          GGS_lstring  automatic_var_4 ;
          nt_description_ (inLexique, automatic_var_4) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          ::routine_add_lstring_unique (inLexique,  var_cas_resources,  var_cas_resource,  GGS_string ("RESOURCE") COMMA_SOURCE_FILE_AT_LINE (200)) ;
          } break ;
        case 7 : {
          GGS_lstring  var_cas_event ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_EVENT) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_token (var_cas_event) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          GGS_lstring  automatic_var_5 ;
          nt_description_ (inLexique, automatic_var_5) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          ::routine_add_lstring_unique (inLexique,  var_cas_events,  var_cas_event,  GGS_string ("EVENT") COMMA_SOURCE_FILE_AT_LINE (204)) ;
          } break ;
        case 8 : {
          GGS_lstring  var_cas_mess ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_MESSAGE) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_token (var_cas_mess) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          GGS_lstring  automatic_var_6 ;
          nt_description_ (inLexique, automatic_var_6) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          ::routine_add_lstring_unique (inLexique,  var_cas_messages,  var_cas_mess,  GGS_string ("MESSAGE") COMMA_SOURCE_FILE_AT_LINE (208)) ;
          } break ;
        case 9 : {
          if (((GGS_bool (inLexique.boolOptionValueFromKeys ("goil_options", "autosar_on" COMMA_SOURCE_FILE_AT_LINE (210)))).operator_isEqual (GGS_bool (false))).isBuiltAndTrue ()) {
            GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("AUTOSAR flag is off, turn it on to use TIMINGPROTECTION attribute in TASK object") COMMA_SOURCE_FILE_AT_LINE (212)) ;
          }
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TIMING_5F_PROTECTION) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          switch (select_goil_obj_task_3 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_FALSE) COMMA_HERE) ;
              var_cas_timing_prot = GGS_false_timing_prot ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRUE) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B_) COMMA_HERE) ;
              GGS_basic_type  var_cas_exe_budget ;
              GGS_basic_type  var_cas_exe_time ;
              GGS_basic_type  var_cas_count_limit ;
              GGS_basic_type  var_cas_time_frame ;
              GGS_basic_type  var_cas_os_it_lock ;
              GGS_basic_type  var_cas_all_it_lock ;
              GGS_rezlock_map  var_cas_rezlocks ;
              nt_timing_prot_attrs_ (inLexique, var_cas_exe_budget, var_cas_exe_time, var_cas_count_limit, var_cas_time_frame, var_cas_os_it_lock, var_cas_all_it_lock, var_cas_rezlocks) ;
              { const GGS_basic_type _var_6221 = var_cas_count_limit ; // CAST instruction
                if (_var_6221.getPtr () != NULL) {
                  macroValidPointer (_var_6221.getPtr ()) ;
                  if (typeid (cPtr_uint32_class) == typeid (* (_var_6221.getPtr ()))) {
                    const GGS_uint32_class var_cas_uc (_var_6221.getPtr ()) ;
                    var_cas_uc.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (229)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("COUNTLIMIT is not an attribute of task timing protection") COMMA_SOURCE_FILE_AT_LINE (230)) ;
                  }else{
                  }
                }
              }
              { const GGS_basic_type _var_6336 = var_cas_exe_budget ; // CAST instruction
                if (_var_6336.getPtr () != NULL) {
                  macroValidPointer (_var_6336.getPtr ()) ;
                  if (typeid (cPtr_void) == typeid (* (_var_6336.getPtr ()))) {
                    GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("EXECUTIONBUDGET not declared") COMMA_SOURCE_FILE_AT_LINE (233)) ;
                  }else{
                  }
                }
              }
              { const GGS_basic_type _var_6507 = var_cas_exe_time ; // CAST instruction
                if (_var_6507.getPtr () != NULL) {
                  macroValidPointer (_var_6507.getPtr ()) ;
                  if (typeid (cPtr_uint64_class) == typeid (* (_var_6507.getPtr ()))) {
                    const GGS_uint64_class var_cas_et (_var_6507.getPtr ()) ;
                    var_cas_et.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (236)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("EXECUTIONTIME is not an attribute of task timing protection") COMMA_SOURCE_FILE_AT_LINE (237)) ;
                  }else{
                  }
                }
              }
              var_cas_timing_prot = GGS_timing_prot_task ::constructor_new (inLexique, GGS_location (inLexique), var_cas_exe_budget, var_cas_time_frame, var_cas_os_it_lock, var_cas_all_it_lock, var_cas_rezlocks COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D_) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 10 : {
          GGS_lstring  var_cas_app ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_ACCESSING_5F_APPLICATION) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_token (var_cas_app) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          GGS_lstring  automatic_var_7 ;
          nt_description_ (inLexique, automatic_var_7) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          ::routine_add_lstring_unique (inLexique,  var_cas_acc_apps,  var_cas_app,  GGS_string ("ACCESSING_APPLICATION") COMMA_SOURCE_FILE_AT_LINE (251)) ;
          } break ;
        case 11 : {
          nt_free_field_ (inLexique, var_cas_others) ;
          GGS_lstring  automatic_var_8 ;
          nt_description_ (inLexique, automatic_var_8) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
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
//        Implementation of production rule 'task_autostart_params'          *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_task::
pr_task_autostart_params_goil_obj_task_257_28_ (goil_lexique & inLexique,
                                GGS_task_autostart_obj  &var_cas_autostart) {
  GGS_lstring  var_cas_appmode ;
  var_cas_appmode = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_HERE) ;
  GGS_stringset  var_cas_appmodes ;
  var_cas_appmodes = GGS_stringset ::constructor_emptySet () ;
  { bool syntaxRepeat_4 = true ;
    while (syntaxRepeat_4) {
      switch (select_repeat_goil_obj_task_4 (inLexique)) {
        case 2 : {
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_APPMODE) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_token (var_cas_appmode) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          GGS_lstring  automatic_var_9 ;
          nt_description_ (inLexique, automatic_var_9) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          if ((var_cas_appmodes.reader_hasKey (inLexique, var_cas_appmode.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (265)) COMMA_SOURCE_FILE_AT_LINE (265))).isBuiltAndTrue ()) {
            GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticWarning (inLexique, ((GGS_string ("APPMODE ")).operator_concat (var_cas_appmode.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (266)))).operator_concat (GGS_string (" already defined for this task AUTOSTART attribute")) COMMA_SOURCE_FILE_AT_LINE (266)) ;
          }
          var_cas_appmodes._addAssign_operation (var_cas_appmode.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (268))) ;
          } break ;
        default :
          syntaxRepeat_4 = false ;
          break ;
      }
    }
  }
  var_cas_autostart = GGS_task_autostart_true ::constructor_new (inLexique, GGS_location (inLexique), var_cas_appmodes COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
