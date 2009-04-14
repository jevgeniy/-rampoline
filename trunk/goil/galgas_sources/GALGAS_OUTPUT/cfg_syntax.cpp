//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'cfg_syntax.cpp'                            *
//                        Generated by version 1.8.0                         *
//                       march 5th, 2009, at 9h31'47"                        *
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
#include "cfg_syntax.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "cfg_syntax.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of production rule 'cfg_start'                *
//                                                                           *
//---------------------------------------------------------------------------*

void cfg_syntax::
pr_cfg_start_cfg_syntax_31_16_ (cfg_lexique & _inLexique,
                                GGS_config  &var_cas_cfg) {
  var_cas_cfg = GGS_config ::constructor_emptyMap (_inLexique COMMA_HERE) ;
  GGS_cfg_attrs  var_cas_task_attrs ;
  var_cas_task_attrs = GGS_cfg_attrs ::constructor_emptyMap (_inLexique COMMA_HERE) ;
  GGS_cfg_attrs  var_cas_isr_attrs ;
  var_cas_isr_attrs = GGS_cfg_attrs ::constructor_emptyMap (_inLexique COMMA_HERE) ;
  GGS_cfg_attrs  var_cas_isr_code_attrs ;
  var_cas_isr_code_attrs = GGS_cfg_attrs ::constructor_emptyMap (_inLexique COMMA_HERE) ;
  GGS_cfg_attrs  var_cas_counter_code_attrs ;
  var_cas_counter_code_attrs = GGS_cfg_attrs ::constructor_emptyMap (_inLexique COMMA_HERE) ;
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_repeat_cfg_syntax_0 (_inLexique)) {
        case 2 : {
          GGS_luint64  var_cas_tpn ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_tp_5Fns_5Fper_5Fcounter_5Ftick) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3D) COMMA_HERE) ;
          _inLexique._assignFromAttribute_integer (var_cas_tpn) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_uint) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3B) COMMA_HERE) ;
          if ((var_cas_cfg.reader_hasKey (_inLexique, GGS_string (true, "wd_ticks_per_ns") COMMA_SOURCE_FILE_AT_LINE (45))).isBuiltAndTrue ()) {
            GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "Redefinition of tp_ns_per_counter_tick") COMMA_SOURCE_FILE_AT_LINE (47)) ;
          }else{
            var_cas_cfg.modifier_put (_inLexique, GGS_lstring ::constructor_new (_inLexique, GGS_string (true, "wd_ticks_per_ns"), GGS_location (_inLexique) COMMA_HERE), GGS_uint64_class ::constructor_new (_inLexique, var_cas_tpn.reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (50)), var_cas_tpn.reader_uint64 (_inLexique COMMA_SOURCE_FILE_AT_LINE (50)) COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (48)) ;
          }
          } break ;
        case 3 : {
          GGS_luint64  var_cas_s_align ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_stack_5Falignment) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3D) COMMA_HERE) ;
          _inLexique._assignFromAttribute_integer (var_cas_s_align) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_uint) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3B) COMMA_HERE) ;
          if ((var_cas_cfg.reader_hasKey (_inLexique, GGS_string (true, "stack_align") COMMA_SOURCE_FILE_AT_LINE (56))).isBuiltAndTrue ()) {
            GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "Redefinition of stack_alignment") COMMA_SOURCE_FILE_AT_LINE (58)) ;
          }else{
            var_cas_cfg.modifier_put (_inLexique, GGS_lstring ::constructor_new (_inLexique, GGS_string (true, "stack_align"), GGS_location (_inLexique) COMMA_HERE), GGS_uint64_class ::constructor_new (_inLexique, var_cas_s_align.reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (61)), var_cas_s_align.reader_uint64 (_inLexique COMMA_SOURCE_FILE_AT_LINE (61)) COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (59)) ;
          }
          } break ;
        case 4 : {
          GGS_lstring  var_cas_oil_attr ;
          GGS_lstring  var_cas_tpl_attr ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_task) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__7B) COMMA_HERE) ;
          nt_cfg_attrs_ (_inLexique, var_cas_task_attrs) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__7D) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3B) COMMA_HERE) ;
          } break ;
        case 5 : {
          GGS_lstring  var_cas_oil_attr ;
          GGS_lstring  var_cas_tpl_attr ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_isr) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__7B) COMMA_HERE) ;
          nt_cfg_attrs_ (_inLexique, var_cas_isr_attrs) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__7D) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3B) COMMA_HERE) ;
          } break ;
        case 6 : {
          GGS_lstring  var_cas_oil_attr ;
          GGS_lstring  var_cas_tpl_attr ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_isr_5Fcode) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__7B) COMMA_HERE) ;
          nt_cfg_attrs_ (_inLexique, var_cas_isr_code_attrs) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__7D) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3B) COMMA_HERE) ;
          } break ;
        case 7 : {
          GGS_lstring  var_cas_oil_attr ;
          GGS_lstring  var_cas_tpl_attr ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_counter_5Fcode) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__7B) COMMA_HERE) ;
          nt_cfg_attrs_ (_inLexique, var_cas_counter_code_attrs) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__7D) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3B) COMMA_HERE) ;
          } break ;
        default :
          syntaxRepeat_0 = false ;
          break ;
      }
    }
  }
  var_cas_cfg.modifier_put (_inLexique, GGS_lstring ::constructor_new (_inLexique, GGS_string (true, "task_attrs"), GGS_location (_inLexique) COMMA_HERE), GGS_attrs ::constructor_new (_inLexique, GGS_location (_inLexique), var_cas_task_attrs COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (82)) ;
  var_cas_cfg.modifier_put (_inLexique, GGS_lstring ::constructor_new (_inLexique, GGS_string (true, "isr_attrs"), GGS_location (_inLexique) COMMA_HERE), GGS_attrs ::constructor_new (_inLexique, GGS_location (_inLexique), var_cas_isr_attrs COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (86)) ;
  var_cas_cfg.modifier_put (_inLexique, GGS_lstring ::constructor_new (_inLexique, GGS_string (true, "isr_code_attrs"), GGS_location (_inLexique) COMMA_HERE), GGS_attrs ::constructor_new (_inLexique, GGS_location (_inLexique), var_cas_isr_code_attrs COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (90)) ;
  var_cas_cfg.modifier_put (_inLexique, GGS_lstring ::constructor_new (_inLexique, GGS_string (true, "counter_code_attrs"), GGS_location (_inLexique) COMMA_HERE), GGS_attrs ::constructor_new (_inLexique, GGS_location (_inLexique), var_cas_counter_code_attrs COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (94)) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of production rule 'cfg_attrs'                *
//                                                                           *
//---------------------------------------------------------------------------*

void cfg_syntax::
pr_cfg_attrs_cfg_syntax_101_16_ (cfg_lexique & _inLexique,
                                GGS_cfg_attrs  &var_cas_attrs) {
  { bool syntaxRepeat_1 = true ;
    while (syntaxRepeat_1) {
      switch (select_repeat_cfg_syntax_1 (_inLexique)) {
        case 2 : {
          GGS_lstring  var_cas_oil_attr ;
          GGS_lstring  var_cas_tpl_attr ;
          _inLexique._assignFromAttribute_keyword (var_cas_oil_attr) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_idf) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3D) COMMA_HERE) ;
          _inLexique._assignFromAttribute_keyword (var_cas_tpl_attr) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1_idf) COMMA_HERE) ;
          _inLexique.acceptTerminal (ACCEPT_TERMINAL (cfg_lexique::cfg_lexique_1__3B) COMMA_HERE) ;
          var_cas_attrs.modifier_put (_inLexique, var_cas_oil_attr, var_cas_tpl_attr COMMA_SOURCE_FILE_AT_LINE (109)) ;
          } break ;
        default :
          syntaxRepeat_1 = false ;
          break ;
      }
    }
  }
}

//---------------------------------------------------------------------------*

