//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'goil_syntax.cpp'                           *
//                        Generated by version 1.9.4                         *
//                     november 12th, 2009, at 11h41'7"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 599
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "galgas/C_galgas_CLI_Options.h"
#include "goil_syntax.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_syntax.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//             Include directives generated by grammar includes              *
//                                                                           *
//---------------------------------------------------------------------------*

#include "goil_cpu_level_include.h"
#include "goil_file_level_include.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                Implementation of production rule 'start'                  *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_syntax::
pr_start_goil_syntax_136_12_ (goil_lexique & inLexique) {
  GGS_implementation  var_cas_imp = GGS_implementation ::constructor_emptyMap (inLexique COMMA_HERE) ;
  GGS_void  var_cas_void_obj = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
  GGS_root_obj  var_cas_cpu = function_void_root_obj (inLexique COMMA_SOURCE_FILE_AT_LINE (139)) ;
  nt_file_ (inLexique, var_cas_imp, var_cas_cpu) ;
  ::routine_set_defaults (inLexique,  var_cas_imp,  var_cas_cpu COMMA_SOURCE_FILE_AT_LINE (161)) ;
  ::routine_verify_all (inLexique,  var_cas_cpu COMMA_SOURCE_FILE_AT_LINE (162)) ;
  const GGS_bool cond_4974 = (GGS_uint ::constructor_errorCount (inLexique COMMA_HERE)).operator_isEqual (GGS_uint (0U)) ;
  if (cond_4974.isBuiltAndTrue ()) {
    ::routine_generate_all (inLexique,  var_cas_cpu COMMA_SOURCE_FILE_AT_LINE (166)) ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//                 Implementation of production rule 'file'                  *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_syntax::
pr_file_goil_syntax_171_11_ (goil_lexique & inLexique,
                                GGS_implementation  &var_cas_imp,
                                GGS_root_obj  &var_cas_cpu) {
  GGS_lstring  var_cas_version = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_HERE) ;
  GGS_lstring  var_cas_desc = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_HERE) ;
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_goil_syntax_0 (inLexique)) {
        case 2 : {
          nt_include_file_level_ (inLexique, var_cas_imp, var_cas_cpu) ;
          } break ;
        case 3 : {
          nt_OIL_version_ (inLexique, var_cas_version, var_cas_desc) ;
          } break ;
        case 4 : {
          nt_implementation_definition_ (inLexique, var_cas_imp) ;
          } break ;
        case 5 : {
          nt_application_definition_ (inLexique, var_cas_cpu) ;
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
//             Implementation of production rule 'description'               *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_syntax::
pr_description_goil_syntax_193_18_ (goil_lexique & inLexique,
                                GGS_lstring  &var_cas_desc) {
  switch (select_goil_syntax_1 (inLexique)) {
    case 1 : {
      var_cas_desc = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_HERE) ;
      } break ;
    case 2 : {
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3A_) COMMA_HERE) ;
      inLexique.assignFromAttribute_a_string (var_cas_desc) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_string) COMMA_HERE) ;
      } break ;
    default :
      break ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//             Implementation of production rule 'OIL_version'               *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_syntax::
pr_OIL_version_goil_syntax_205_18_ (goil_lexique & inLexique,
                                GGS_lstring  &var_cas_version,
                                GGS_lstring  &var_cas_desc) {
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_OIL_5F_VERSION) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
  inLexique.assignFromAttribute_a_string (var_cas_version) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_string) COMMA_HERE) ;
  nt_description_ (inLexique, var_cas_desc) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//        Implementation of production rule 'application_definition'         *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_syntax::
pr_application_definition_goil_syntax_216_29_ (goil_lexique & inLexique,
                                GGS_root_obj  &var_cas_file) {
  GGS_os_obj  var_cas_os = var_cas_file.reader_os (inLexique COMMA_SOURCE_FILE_AT_LINE (219)) ;
  GGS_com  var_cas_com = var_cas_file.reader_com (inLexique COMMA_SOURCE_FILE_AT_LINE (220)) ;
  GGS_task_map  var_cas_tasks = var_cas_file.reader_tasks (inLexique COMMA_SOURCE_FILE_AT_LINE (221)) ;
  GGS_counter_map  var_cas_counters = var_cas_file.reader_counters (inLexique COMMA_SOURCE_FILE_AT_LINE (222)) ;
  GGS_alarm_map  var_cas_alarms = var_cas_file.reader_alarms (inLexique COMMA_SOURCE_FILE_AT_LINE (223)) ;
  GGS_resource_map  var_cas_resources = var_cas_file.reader_resources (inLexique COMMA_SOURCE_FILE_AT_LINE (224)) ;
  GGS_event_map  var_cas_events = var_cas_file.reader_events (inLexique COMMA_SOURCE_FILE_AT_LINE (225)) ;
  GGS_isr_map  var_cas_isrs = var_cas_file.reader_isrs (inLexique COMMA_SOURCE_FILE_AT_LINE (226)) ;
  GGS_message_map  var_cas_messages = var_cas_file.reader_messages (inLexique COMMA_SOURCE_FILE_AT_LINE (227)) ;
  GGS_netmess_map  var_cas_net_messages = var_cas_file.reader_net_messages (inLexique COMMA_SOURCE_FILE_AT_LINE (228)) ;
  GGS_scheduletable_map  var_cas_scheduletables = var_cas_file.reader_scheduletables (inLexique COMMA_SOURCE_FILE_AT_LINE (229)) ;
  GGS_app_map  var_cas_applis = var_cas_file.reader_applis (inLexique COMMA_SOURCE_FILE_AT_LINE (230)) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_CPU) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B_) COMMA_HERE) ;
  nt_object_definition_list_ (inLexique, var_cas_os, var_cas_com, var_cas_tasks, var_cas_counters, var_cas_alarms, var_cas_resources, var_cas_events, var_cas_isrs, var_cas_messages, var_cas_net_messages, var_cas_scheduletables, var_cas_applis) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D_) COMMA_HERE) ;
  GGS_lstring  automatic_var_0 ;
  nt_description_ (inLexique, automatic_var_0) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
  var_cas_file = GGS_root_obj ::constructor_new (inLexique, var_cas_os, var_cas_com, var_cas_tasks, var_cas_counters, var_cas_alarms, var_cas_resources, var_cas_events, var_cas_isrs, var_cas_messages, var_cas_net_messages, var_cas_scheduletables, var_cas_applis COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//        Implementation of production rule 'object_definition_list'         *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_syntax::
pr_object_definition_list_goil_syntax_269_29_ (goil_lexique & inLexique,
                                GGS_os_obj  &var_cas_os,
                                GGS_com  &var_cas_com,
                                GGS_task_map  &var_cas_tasks,
                                GGS_counter_map  &var_cas_counters,
                                GGS_alarm_map  &var_cas_alarms,
                                GGS_resource_map  &var_cas_resources,
                                GGS_event_map  &var_cas_events,
                                GGS_isr_map  &var_cas_isrs,
                                GGS_message_map  &var_cas_messages,
                                GGS_netmess_map  &var_cas_net_messages,
                                GGS_scheduletable_map  &var_cas_scheduletables,
                                GGS_app_map  &var_cas_applis) {
  { bool syntaxRepeat_2 = true ;
    while (syntaxRepeat_2) {
      switch (select_goil_syntax_2 (inLexique)) {
        case 2 : {
          nt_os_ (inLexique, var_cas_os) ;
          } break ;
        case 3 : {
          nt_appmode_ (inLexique) ;
          GGS_lstring  automatic_var_1 ;
          nt_description_ (inLexique, automatic_var_1) ;
          } break ;
        case 4 : {
          nt_task_ (inLexique, var_cas_tasks) ;
          } break ;
        case 5 : {
          nt_counter_ (inLexique, var_cas_counters) ;
          } break ;
        case 6 : {
          nt_alarm_ (inLexique, var_cas_alarms) ;
          GGS_lstring  automatic_var_2 ;
          nt_description_ (inLexique, automatic_var_2) ;
          } break ;
        case 7 : {
          nt_resource_ (inLexique, var_cas_resources) ;
          GGS_lstring  automatic_var_3 ;
          nt_description_ (inLexique, automatic_var_3) ;
          } break ;
        case 8 : {
          nt_event_ (inLexique, var_cas_events) ;
          GGS_lstring  automatic_var_4 ;
          nt_description_ (inLexique, automatic_var_4) ;
          } break ;
        case 9 : {
          nt_isr_ (inLexique, var_cas_isrs) ;
          GGS_lstring  automatic_var_5 ;
          nt_description_ (inLexique, automatic_var_5) ;
          } break ;
        case 10 : {
          nt_mess_ (inLexique, var_cas_messages) ;
          GGS_lstring  automatic_var_6 ;
          nt_description_ (inLexique, automatic_var_6) ;
          } break ;
        case 11 : {
          nt_networkmess_ (inLexique, var_cas_net_messages) ;
          GGS_lstring  automatic_var_7 ;
          nt_description_ (inLexique, automatic_var_7) ;
          } break ;
        case 12 : {
          nt_com_ (inLexique, var_cas_com) ;
          GGS_lstring  automatic_var_8 ;
          nt_description_ (inLexique, automatic_var_8) ;
          } break ;
        case 13 : {
          nt_ipdu_ (inLexique) ;
          GGS_lstring  automatic_var_9 ;
          nt_description_ (inLexique, automatic_var_9) ;
          } break ;
        case 14 : {
          nt_nm_ (inLexique) ;
          GGS_lstring  automatic_var_10 ;
          nt_description_ (inLexique, automatic_var_10) ;
          } break ;
        case 15 : {
          nt_scheduletable_ (inLexique, var_cas_scheduletables) ;
          GGS_lstring  automatic_var_11 ;
          nt_description_ (inLexique, automatic_var_11) ;
          } break ;
        case 16 : {
          nt_appli_ (inLexique, var_cas_applis) ;
          GGS_lstring  automatic_var_12 ;
          nt_description_ (inLexique, automatic_var_12) ;
          } break ;
        case 17 : {
          nt_include_cpu_level_ (inLexique, var_cas_os, var_cas_com, var_cas_tasks, var_cas_counters, var_cas_alarms, var_cas_resources, var_cas_events, var_cas_isrs, var_cas_messages, var_cas_net_messages, var_cas_scheduletables, var_cas_applis) ;
          } break ;
        default :
          syntaxRepeat_2 = false ;
          break ;
      }
    }
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//                  Implementation of production rule 'nm'                   *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_syntax::
pr_nm_goil_syntax_317_9_ (goil_lexique & inLexique) {
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_NM) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B_) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D_) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//               Implementation of production rule 'boolean'                 *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_syntax::
pr_boolean_goil_syntax_328_14_ (goil_lexique & inLexique,
                                GGS_lbool  &var_cas_val) {
  switch (select_goil_syntax_3 (inLexique)) {
    case 1 : {
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRUE) COMMA_HERE) ;
      var_cas_val = GGS_lbool ::constructor_new (inLexique, GGS_bool (true), GGS_location (inLexique) COMMA_HERE) ;
      } break ;
    case 2 : {
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_FALSE) COMMA_HERE) ;
      var_cas_val = GGS_lbool ::constructor_new (inLexique, GGS_bool (false), GGS_location (inLexique) COMMA_HERE) ;
      } break ;
    default :
      break ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of production rule 'free_field'               *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_syntax::
pr_free_field_goil_syntax_338_17_ (goil_lexique & inLexique,
                                GGS_ident_map  &var_cas_ids) {
  GGS_lstring  var_cas_idf ;
  GGS_basic_type  var_cas_val ;
  inLexique.assignFromAttribute_att_token (var_cas_idf) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
  switch (select_goil_syntax_4 (inLexique)) {
    case 1 : {
      GGS_lstring  var_cas_value ;
      inLexique.assignFromAttribute_att_token (var_cas_value) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
      var_cas_val = GGS_string_class ::constructor_new (inLexique, var_cas_value.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (346)), var_cas_value.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (346)) COMMA_HERE) ;
      } break ;
    case 2 : {
      GGS_luint64  var_cas_value ;
      inLexique.assignFromAttribute_integerNumber (var_cas_value) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_uint_5F_number) COMMA_HERE) ;
      var_cas_val = GGS_uint64_class ::constructor_new (inLexique, var_cas_value.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (350)), var_cas_value.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (350)) COMMA_HERE) ;
      } break ;
    case 3 : {
      GGS_lbool  var_cas_value ;
      nt_boolean_ (inLexique, var_cas_value) ;
      var_cas_val = GGS_bool_class ::constructor_new (inLexique, var_cas_idf.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (354)), var_cas_value.reader_bool (inLexique COMMA_SOURCE_FILE_AT_LINE (354)) COMMA_HERE) ;
      } break ;
    default :
      break ;
  }
  var_cas_ids.modifier_put (inLexique, var_cas_idf, var_cas_val COMMA_SOURCE_FILE_AT_LINE (356)) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          Implementation of production rule 'include_file_level'           *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_syntax::
pr_include_file_level_goil_syntax_359_25_ (goil_lexique & inLexique,
                                GGS_implementation  &var_cas_imp,
                                GGS_root_obj  &var_cas_cpu) {
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_include) COMMA_HERE) ;
  GGS_lstring  var_cas_file_name ;
  switch (select_goil_syntax_5 (inLexique)) {
    case 1 : {
      inLexique.assignFromAttribute_a_string (var_cas_file_name) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_g_5F_string) COMMA_HERE) ;
      ::routine_file_in_path (inLexique,  var_cas_file_name COMMA_SOURCE_FILE_AT_LINE (367)) ;
      } break ;
    case 2 : {
      inLexique.assignFromAttribute_a_string (var_cas_file_name) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_string) COMMA_HERE) ;
      } break ;
    default :
      break ;
  }
  const GGS_string _depExtension = GGS_string ("") ;
  const GGS_string _depPath = GGS_string ("") ;
  if (_depExtension.isBuilt () && _depPath.isBuilt ()) {
    goil_file_level_include::_performSourceFileParsing_ (inLexique,
                                  _depExtension.string (),
                                  _depPath.string (),
                                  NULL,
                                  var_cas_file_name,
                                  var_cas_imp,
                                  var_cas_cpu
                                  COMMA_SOURCE_FILE_AT_LINE (371)) ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//          Implementation of production rule 'include_cpu_level'            *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_syntax::
pr_include_cpu_level_goil_syntax_377_24_ (goil_lexique & inLexique,
                                GGS_os_obj  &var_cas_os,
                                GGS_com  &var_cas_com,
                                GGS_task_map  &var_cas_tasks,
                                GGS_counter_map  &var_cas_counters,
                                GGS_alarm_map  &var_cas_alarms,
                                GGS_resource_map  &var_cas_resources,
                                GGS_event_map  &var_cas_events,
                                GGS_isr_map  &var_cas_isrs,
                                GGS_message_map  &var_cas_messages,
                                GGS_netmess_map  &var_cas_net_messages,
                                GGS_scheduletable_map  &var_cas_scheduletables,
                                GGS_app_map  &var_cas_applis) {
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_include) COMMA_HERE) ;
  GGS_lstring  var_cas_file_name ;
  switch (select_goil_syntax_6 (inLexique)) {
    case 1 : {
      inLexique.assignFromAttribute_a_string (var_cas_file_name) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_g_5F_string) COMMA_HERE) ;
      ::routine_file_in_path (inLexique,  var_cas_file_name COMMA_SOURCE_FILE_AT_LINE (395)) ;
      } break ;
    case 2 : {
      inLexique.assignFromAttribute_a_string (var_cas_file_name) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_string) COMMA_HERE) ;
      } break ;
    default :
      break ;
  }
  const GGS_string _depExtension = GGS_string ("") ;
  const GGS_string _depPath = GGS_string ("") ;
  if (_depExtension.isBuilt () && _depPath.isBuilt ()) {
    goil_cpu_level_include::_performSourceFileParsing_ (inLexique,
                                  _depExtension.string (),
                                  _depPath.string (),
                                  NULL,
                                  var_cas_file_name,
                                  var_cas_os,
                                  var_cas_com,
                                  var_cas_tasks,
                                  var_cas_counters,
                                  var_cas_alarms,
                                  var_cas_resources,
                                  var_cas_events,
                                  var_cas_isrs,
                                  var_cas_messages,
                                  var_cas_net_messages,
                                  var_cas_scheduletables,
                                  var_cas_applis
                                  COMMA_SOURCE_FILE_AT_LINE (399)) ;
  }
}

//---------------------------------------------------------------------------*

