//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'cfg_syntax.cpp'                            *
//                        Generated by version 2.0.0                         *
//                       july 7th, 2010, at 17h17'10"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if CURRENT_LIBPM_VERSION != 820
  #error "This file has been compiled with a version of GALGAS that uses libpm version 820, different than the current version (CURRENT_LIBPM_VERSION) of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "galgas/C_galgas_CLI_Options.h"
#include "cfg_syntax.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "cfg_syntax.gSyntax", line
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

void cfg_syntax::rule_cfg_5F_syntax_cfg_5F_start_i0_ (C_Lexique_cfg_5F_lexique & inLexique,
                                GGS_config  &var_cas_cfg) {
  var_cas_cfg = GGS_config ::constructor_emptyMap (inLexique COMMA_SOURCE_FILE_AT_LINE (41)) ;
  GGS_cfg_attrs  var_cas_task_attrs = GGS_cfg_attrs ::constructor_emptyMap (inLexique COMMA_SOURCE_FILE_AT_LINE (43)) ;
  GGS_cfg_attrs  var_cas_isr_attrs = GGS_cfg_attrs ::constructor_emptyMap (inLexique COMMA_SOURCE_FILE_AT_LINE (44)) ;
  GGS_cfg_attrs  var_cas_isr_code_attrs = GGS_cfg_attrs ::constructor_emptyMap (inLexique COMMA_SOURCE_FILE_AT_LINE (45)) ;
  GGS_cfg_attrs  var_cas_counter_code_attrs = GGS_cfg_attrs ::constructor_emptyMap (inLexique COMMA_SOURCE_FILE_AT_LINE (46)) ;
  GGS_basic_type  var_cas_its = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (47)) ;
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_cfg_5F_syntax_0 (inLexique)) {
        case 2 : {
          GGS_luint64  var_cas_tpn ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_tp_5F_ns_5F_per_5F_counter_5F_tick) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_integer (var_cas_tpn) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_uint) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3B_) COMMA_HERE) ;
          const GGS_bool cond_1260 = var_cas_cfg.reader_hasKey (GGS_string ("wd_ticks_per_ns")) ;
          if (cond_1260.isBuiltAndTrue ()) {
            GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Redefinition of tp_ns_per_counter_tick") COMMA_SOURCE_FILE_AT_LINE (55)) ;
          }else if (cond_1260.isBuiltAndFalse ()) {
            var_cas_cfg.modifier_put (inLexique, GGS_lstring ::constructor_new (inLexique, GGS_string ("wd_ticks_per_ns"), GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (57)), GGS_uint64_class ::constructor_new (inLexique, var_cas_tpn.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (58)), var_cas_tpn.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (58)) COMMA_SOURCE_FILE_AT_LINE (58)) COMMA_SOURCE_FILE_AT_LINE (56)) ;
          }
          } break ;
        case 3 : {
          GGS_luint64  var_cas_s_align ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_stack_5F_alignment) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_integer (var_cas_s_align) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_uint) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3B_) COMMA_HERE) ;
          const GGS_bool cond_1654 = var_cas_cfg.reader_hasKey (GGS_string ("stack_align")) ;
          if (cond_1654.isBuiltAndTrue ()) {
            GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Redefinition of stack_alignment") COMMA_SOURCE_FILE_AT_LINE (66)) ;
          }else if (cond_1654.isBuiltAndFalse ()) {
            var_cas_cfg.modifier_put (inLexique, GGS_lstring ::constructor_new (inLexique, GGS_string ("stack_align"), GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (68)), GGS_uint64_class ::constructor_new (inLexique, var_cas_s_align.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (69)), var_cas_s_align.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (69)) COMMA_SOURCE_FILE_AT_LINE (69)) COMMA_SOURCE_FILE_AT_LINE (67)) ;
          }
          } break ;
        case 4 : {
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_task) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__7B_) COMMA_HERE) ;
          nt_cfg_5F_attrs_ (inLexique, var_cas_task_attrs) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__7D_) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3B_) COMMA_HERE) ;
          } break ;
        case 5 : {
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_isr) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__7B_) COMMA_HERE) ;
          nt_cfg_5F_attrs_ (inLexique, var_cas_isr_attrs) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__7D_) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3B_) COMMA_HERE) ;
          } break ;
        case 6 : {
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_isr_5F_code) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__7B_) COMMA_HERE) ;
          nt_cfg_5F_attrs_ (inLexique, var_cas_isr_code_attrs) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__7D_) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3B_) COMMA_HERE) ;
          } break ;
        case 7 : {
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_counter_5F_code) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__7B_) COMMA_HERE) ;
          nt_cfg_5F_attrs_ (inLexique, var_cas_counter_code_attrs) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__7D_) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3B_) COMMA_HERE) ;
          } break ;
        case 8 : {
          nt_interrupts_ (inLexique, var_cas_its) ;
          } break ;
        default :
          syntaxRepeat_0 = false ;
          break ;
      }
    }
  }
  var_cas_cfg.modifier_put (inLexique, GGS_lstring ::constructor_new (inLexique, GGS_string ("task_attrs"), GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (85)), GGS_attrs ::constructor_new (inLexique, GGS_location (inLexique), var_cas_task_attrs COMMA_SOURCE_FILE_AT_LINE (86)) COMMA_SOURCE_FILE_AT_LINE (84)) ;
  var_cas_cfg.modifier_put (inLexique, GGS_lstring ::constructor_new (inLexique, GGS_string ("isr_attrs"), GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (89)), GGS_attrs ::constructor_new (inLexique, GGS_location (inLexique), var_cas_isr_attrs COMMA_SOURCE_FILE_AT_LINE (90)) COMMA_SOURCE_FILE_AT_LINE (88)) ;
  var_cas_cfg.modifier_put (inLexique, GGS_lstring ::constructor_new (inLexique, GGS_string ("isr_code_attrs"), GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (93)), GGS_attrs ::constructor_new (inLexique, GGS_location (inLexique), var_cas_isr_code_attrs COMMA_SOURCE_FILE_AT_LINE (94)) COMMA_SOURCE_FILE_AT_LINE (92)) ;
  var_cas_cfg.modifier_put (inLexique, GGS_lstring ::constructor_new (inLexique, GGS_string ("counter_code_attrs"), GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (97)), GGS_attrs ::constructor_new (inLexique, GGS_location (inLexique), var_cas_counter_code_attrs COMMA_SOURCE_FILE_AT_LINE (98)) COMMA_SOURCE_FILE_AT_LINE (96)) ;
  var_cas_cfg.modifier_put (inLexique, GGS_lstring ::constructor_new (inLexique, GGS_string ("it_sources"), GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (100)), var_cas_its COMMA_SOURCE_FILE_AT_LINE (100)) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of production rule 'cfg_attrs'                *
//                                                                           *
//---------------------------------------------------------------------------*

void cfg_syntax::rule_cfg_5F_syntax_cfg_5F_attrs_i1_ (C_Lexique_cfg_5F_lexique & inLexique,
                                GGS_cfg_attrs  &var_cas_attrs) {
  { bool syntaxRepeat_1 = true ;
    while (syntaxRepeat_1) {
      switch (select_cfg_5F_syntax_1 (inLexique)) {
        case 2 : {
          GGS_lstring  var_cas_oil_attr ;
          GGS_lstring  var_cas_tpl_attr ;
          inLexique.assignFromAttribute_keyword (var_cas_oil_attr) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_idf) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_keyword (var_cas_tpl_attr) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_idf) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3B_) COMMA_HERE) ;
          var_cas_attrs.modifier_put (inLexique, var_cas_oil_attr, var_cas_tpl_attr COMMA_SOURCE_FILE_AT_LINE (112)) ;
          } break ;
        default :
          syntaxRepeat_1 = false ;
          break ;
      }
    }
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of production rule 'interrupts'               *
//                                                                           *
//---------------------------------------------------------------------------*

void cfg_syntax::rule_cfg_5F_syntax_interrupts_i2_ (C_Lexique_cfg_5F_lexique & inLexique,
                                GGS_basic_type  &var_cas_its) {
  GGS_ident_map  var_cas_it_src = GGS_ident_map ::constructor_emptyMap (inLexique COMMA_SOURCE_FILE_AT_LINE (119)) ;
  GGS_luint64  var_cas_it_count ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_interrupts) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__5B_) COMMA_HERE) ;
  inLexique.assignFromAttribute_integer (var_cas_it_count) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_uint) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__5D_) COMMA_HERE) ;
  GGS_location  var_cas_it_loc = GGS_location (inLexique) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__7B_) COMMA_HERE) ;
  { bool syntaxRepeat_2 = true ;
    while (syntaxRepeat_2) {
      switch (select_cfg_5F_syntax_2 (inLexique)) {
        case 2 : {
          GGS_lstring  var_cas_src ;
          GGS_luint64  var_cas_id ;
          inLexique.assignFromAttribute_keyword (var_cas_src) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_idf) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_integer (var_cas_id) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_uint) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3B_) COMMA_HERE) ;
          const GGS_bool cond_3375 = (var_cas_id.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (128))).operator_supOrEqual (var_cas_it_count.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (128))) ;
          if (cond_3375.isBuiltAndTrue ()) {
            var_cas_id.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Interrupt id out of range") COMMA_SOURCE_FILE_AT_LINE (130)) ;
            var_cas_it_count.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Range was defined here") COMMA_SOURCE_FILE_AT_LINE (131)) ;
          }
          var_cas_it_src.modifier_put (inLexique, var_cas_src, GGS_uint64_class ::constructor_new (inLexique, var_cas_id.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (132)), var_cas_id.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (132)) COMMA_SOURCE_FILE_AT_LINE (132)) COMMA_SOURCE_FILE_AT_LINE (132)) ;
          } break ;
        default :
          syntaxRepeat_2 = false ;
          break ;
      }
    }
  }
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__7D_) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3B_) COMMA_HERE) ;
  var_cas_its = GGS_interrupts ::constructor_new (inLexique, var_cas_it_loc, var_cas_it_count, var_cas_it_src COMMA_SOURCE_FILE_AT_LINE (135)) ;
}

//---------------------------------------------------------------------------*

