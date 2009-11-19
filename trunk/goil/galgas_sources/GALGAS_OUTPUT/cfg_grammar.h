//---------------------------------------------------------------------------*
//                                                                           *
//                           File 'cfg_grammar.h'                            *
//                        Generated by version 1.9.4                         *
//                    november 12th, 2009, at 11h43'46"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef GRAMMAR_cfg_grammar_HAS_BEEN_DEFINED
#define GRAMMAR_cfg_grammar_HAS_BEEN_DEFINED

//---------------------------------------------------------------------------*

#include "cfg_syntax.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*

class cfg_grammar : public cfg_syntax {
  public : virtual void nt_cfg_start_ (cfg_lexique &,
                                GGS_config &) ;
  public : static void _performSourceFileParsing_ (C_Compiler & inCompiler,
                                const C_String & inDependancyExtension,
                                const C_String & inDependancyPath,
                                GGS_string * inSentStringPtr,
                                const GGS_lstring inFileName,
                                GGS_config &
                                COMMA_LOCATION_ARGS) ;
  public : static void _performSourceStringParsing_ (C_Compiler & inCompiler,
                                GGS_string * inSentStringPtr,
                                const GGS_string inSourceString,
                                GGS_config &
                                COMMA_LOCATION_ARGS) ;
  public : virtual void nt_cfg_attrs_ (cfg_lexique &,
                                GGS_cfg_attrs &) ;
  public : virtual void nt_interrupts_ (cfg_lexique &,
                                GGS_basic_type &) ;
  public : virtual PMSInt16 select_cfg_syntax_0 (cfg_lexique &) ;
  public : virtual PMSInt16 select_cfg_syntax_1 (cfg_lexique &) ;
  public : virtual PMSInt16 select_cfg_syntax_2 (cfg_lexique &) ;
} ;

//---------------------------------------------------------------------------*

#endif