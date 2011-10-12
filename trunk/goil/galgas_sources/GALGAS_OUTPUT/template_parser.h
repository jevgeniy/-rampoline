//---------------------------------------------------------------------------*
//                                                                           *
//                         File 'template_parser.h'                          *
//                    Generated by version version 2.2.6                     *
//                     october 12th, 2011, at 14h50'28"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef template_parser_ENTITIES_DEFINED
#define template_parser_ENTITIES_DEFINED

//---------------------------------------------------------------------------*

#include "galgas2/predefined-types.h"

//---------------------------------------------------------------------------*

#include "template_scanner.h"

//---------------------------------------------------------------------------*

#include "template_invocation.h"
#include "goil_routines.h"
#include "goil_basic_types.h"
#include "template_semantics.h"

//---------------------------------------------------------------------------*

class GALGAS__32_stringlist ;
class GALGAS_application ;
class GALGAS_auto_5F_bool_5F_class ;
class GALGAS_auto_5F_sint_33__32__5F_class ;
class GALGAS_auto_5F_sint_36__34__5F_class ;
class GALGAS_auto_5F_string_5F_class ;
class GALGAS_auto_5F_uint_33__32__5F_class ;
class GALGAS_auto_5F_uint_36__34__5F_class ;
class GALGAS_autostart_5F_false ;
class GALGAS_autostart_5F_obj ;
class GALGAS_autostart_5F_void ;
class GALGAS_basic_5F_type ;
class GALGAS_binaryset ;
class GALGAS_bool ;
class GALGAS_bool_5F_class ;
class GALGAS_char ;
class GALGAS_data ;
class GALGAS_double ;
class GALGAS_filewrapper ;
class GALGAS_float_5F_class ;
class GALGAS_float_5F_empty_5F_set ;
class GALGAS_float_5F_set ;
class GALGAS_function ;
class GALGAS_functionlist ;
class GALGAS_goilTemplateEnumationList ;
class GALGAS_goilTemplateExpressionList ;
class GALGAS_goilTemplateFieldMap ;
class GALGAS_goilTemplateFieldMapList ;
class GALGAS_goilTemplateType ;
class GALGAS_goilTemplateTypeList ;
class GALGAS_goilTemplateValue ;
class GALGAS_goilTemplateVariableMap ;
class GALGAS_ident_5F_list ;
class GALGAS_ident_5F_list_5F_map ;
class GALGAS_ident_5F_map ;
class GALGAS_imp_5F_obj_5F_ref ;
class GALGAS_imp_5F_sca_5F_type ;
class GALGAS_imp_5F_type ;
class GALGAS_lbool ;
class GALGAS_lchar ;
class GALGAS_ldouble ;
class GALGAS_list_5F_sint_33__32_ ;
class GALGAS_list_5F_sint_36__34_ ;
class GALGAS_list_5F_uint_33__32_ ;
class GALGAS_list_5F_uint_36__34_ ;
class GALGAS_location ;
class GALGAS_lsint ;
class GALGAS_lsint_36__34_ ;
class GALGAS_lstring ;
class GALGAS_lstringMap ;
class GALGAS_lstringlist ;
class GALGAS_luint ;
class GALGAS_luint_36__34_ ;
class GALGAS_luintlist ;
class GALGAS_number_5F_set ;
class GALGAS_object ;
class GALGAS_objectlist ;
class GALGAS_oil_5F_obj ;
class GALGAS_sint ;
class GALGAS_sint_33__32__5F_class ;
class GALGAS_sint_33__32__5F_empty_5F_set ;
class GALGAS_sint_33__32__5F_list ;
class GALGAS_sint_33__32__5F_range ;
class GALGAS_sint_33__32__5F_set ;
class GALGAS_sint_33__32__5F_type ;
class GALGAS_sint_36__34_ ;
class GALGAS_sint_36__34__5F_class ;
class GALGAS_sint_36__34__5F_empty_5F_set ;
class GALGAS_sint_36__34__5F_list ;
class GALGAS_sint_36__34__5F_range ;
class GALGAS_sint_36__34__5F_set ;
class GALGAS_sint_36__34__5F_type ;
class GALGAS_string ;
class GALGAS_stringMap ;
class GALGAS_string_5F_class ;
class GALGAS_stringlist ;
class GALGAS_stringset ;
class GALGAS_stringset_5F_map ;
class GALGAS_type ;
class GALGAS_typelist ;
class GALGAS_uint ;
class GALGAS_uint_33__32__5F_class ;
class GALGAS_uint_33__32__5F_empty_5F_set ;
class GALGAS_uint_33__32__5F_list ;
class GALGAS_uint_33__32__5F_range ;
class GALGAS_uint_33__32__5F_set ;
class GALGAS_uint_33__32__5F_type ;
class GALGAS_uint_36__34_ ;
class GALGAS_uint_36__34__5F_class ;
class GALGAS_uint_36__34__5F_empty_5F_set ;
class GALGAS_uint_36__34__5F_list ;
class GALGAS_uint_36__34__5F_range ;
class GALGAS_uint_36__34__5F_set ;
class GALGAS_uint_36__34__5F_type ;
class GALGAS_uint_36__34_list ;
class GALGAS_uintlist ;
class GALGAS_void ;
class GALGAS_void_5F_bool_5F_class ;
class GALGAS_void_5F_float_5F_class ;
class GALGAS_void_5F_sint_33__32__5F_class ;
class GALGAS_void_5F_sint_36__34__5F_class ;
class GALGAS_void_5F_string_5F_class ;
class GALGAS_void_5F_type ;
class GALGAS_void_5F_uint_33__32__5F_class ;
class GALGAS_void_5F_uint_36__34__5F_class ;

//---------------------------------------------------------------------------*
//                                                                           *
//                Parser class 'template_parser' declaration                 *
//                                                                           *
//---------------------------------------------------------------------------*

class cParser_template_5F_parser {
//--- Virtual destructor
  public : virtual ~ cParser_template_5F_parser (void) {}

//--- Non terminal declarations
  protected : virtual void nt_expression_ (const GALGAS_string constinArgument0,
                                           const GALGAS_string constinArgument1,
                                           const GALGAS_string constinArgument2,
                                           const GALGAS_goilTemplateVariableMap constinArgument3,
                                           GALGAS_goilTemplateValue & outArgument4,
                                           GALGAS_goilTemplateType & outArgument5,
                                           C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_expression_parse (C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_goil_5F_template_5F_start_5F_symbol_ (const GALGAS_string constinArgument0,
                                                                    const GALGAS_string constinArgument1,
                                                                    const GALGAS_string constinArgument2,
                                                                    GALGAS_goilTemplateVariableMap inArgument3,
                                                                    GALGAS_string & ioArgument4,
                                                                    C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_goil_5F_template_5F_start_5F_symbol_parse (C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_template_5F_instruction_ (const GALGAS_string constinArgument0,
                                                        const GALGAS_string constinArgument1,
                                                        const GALGAS_string constinArgument2,
                                                        GALGAS_goilTemplateVariableMap & ioArgument3,
                                                        GALGAS_string & ioArgument4,
                                                        C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_template_5F_instruction_parse (C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_template_5F_instruction_5F_list_ (const GALGAS_string constinArgument0,
                                                                const GALGAS_string constinArgument1,
                                                                const GALGAS_string constinArgument2,
                                                                GALGAS_goilTemplateVariableMap & ioArgument3,
                                                                GALGAS_string & ioArgument4,
                                                                C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_template_5F_instruction_5F_list_parse (C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_variable_5F_or_5F_here_ (const GALGAS_goilTemplateVariableMap constinArgument0,
                                                       GALGAS_location & outArgument1,
                                                       C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_variable_5F_or_5F_here_parse (C_Lexique_template_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected : void rule_template_5F_parser_template_5F_instruction_i0_ (const GALGAS_string constinArgument0,
                                                                        const GALGAS_string constinArgument1,
                                                                        const GALGAS_string constinArgument2,
                                                                        GALGAS_goilTemplateVariableMap & ioArgument3,
                                                                        GALGAS_string & ioArgument4,
                                                                        C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i0_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i1_ (const GALGAS_string constinArgument0,
                                                                        const GALGAS_string constinArgument1,
                                                                        const GALGAS_string constinArgument2,
                                                                        GALGAS_goilTemplateVariableMap & ioArgument3,
                                                                        GALGAS_string & ioArgument4,
                                                                        C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i1_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i2_ (const GALGAS_string constinArgument0,
                                                                        const GALGAS_string constinArgument1,
                                                                        const GALGAS_string constinArgument2,
                                                                        GALGAS_goilTemplateVariableMap & ioArgument3,
                                                                        GALGAS_string & ioArgument4,
                                                                        C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i2_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i3_ (const GALGAS_string constinArgument0,
                                                                        const GALGAS_string constinArgument1,
                                                                        const GALGAS_string constinArgument2,
                                                                        GALGAS_goilTemplateVariableMap & ioArgument3,
                                                                        GALGAS_string & ioArgument4,
                                                                        C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i3_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i4_ (const GALGAS_string constinArgument0,
                                                                        const GALGAS_string constinArgument1,
                                                                        const GALGAS_string constinArgument2,
                                                                        GALGAS_goilTemplateVariableMap & ioArgument3,
                                                                        GALGAS_string & ioArgument4,
                                                                        C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i4_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_5F_list_i5_ (const GALGAS_string constinArgument0,
                                                                                const GALGAS_string constinArgument1,
                                                                                const GALGAS_string constinArgument2,
                                                                                GALGAS_goilTemplateVariableMap & ioArgument3,
                                                                                GALGAS_string & ioArgument4,
                                                                                C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_5F_list_i5_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_goil_5F_template_5F_start_5F_symbol_i6_ (const GALGAS_string constinArgument0,
                                                                                    const GALGAS_string constinArgument1,
                                                                                    const GALGAS_string constinArgument2,
                                                                                    GALGAS_goilTemplateVariableMap inArgument3,
                                                                                    GALGAS_string & ioArgument4,
                                                                                    C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_goil_5F_template_5F_start_5F_symbol_i6_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i7_ (const GALGAS_string constinArgument0,
                                                                        const GALGAS_string constinArgument1,
                                                                        const GALGAS_string constinArgument2,
                                                                        GALGAS_goilTemplateVariableMap & ioArgument3,
                                                                        GALGAS_string & ioArgument4,
                                                                        C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i7_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i8_ (const GALGAS_string constinArgument0,
                                                                        const GALGAS_string constinArgument1,
                                                                        const GALGAS_string constinArgument2,
                                                                        GALGAS_goilTemplateVariableMap & ioArgument3,
                                                                        GALGAS_string & ioArgument4,
                                                                        C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i8_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i9_ (const GALGAS_string constinArgument0,
                                                                        const GALGAS_string constinArgument1,
                                                                        const GALGAS_string constinArgument2,
                                                                        GALGAS_goilTemplateVariableMap & ioArgument3,
                                                                        GALGAS_string & ioArgument4,
                                                                        C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i9_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i10_ (const GALGAS_string constinArgument0,
                                                                         const GALGAS_string constinArgument1,
                                                                         const GALGAS_string constinArgument2,
                                                                         GALGAS_goilTemplateVariableMap & ioArgument3,
                                                                         GALGAS_string & ioArgument4,
                                                                         C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i10_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_variable_5F_or_5F_here_i11_ (const GALGAS_goilTemplateVariableMap constinArgument0,
                                                                        GALGAS_location & outArgument1,
                                                                        C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_variable_5F_or_5F_here_i11_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i12_ (const GALGAS_string constinArgument0,
                                                                         const GALGAS_string constinArgument1,
                                                                         const GALGAS_string constinArgument2,
                                                                         GALGAS_goilTemplateVariableMap & ioArgument3,
                                                                         GALGAS_string & ioArgument4,
                                                                         C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i12_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i13_ (const GALGAS_string constinArgument0,
                                                                         const GALGAS_string constinArgument1,
                                                                         const GALGAS_string constinArgument2,
                                                                         GALGAS_goilTemplateVariableMap & ioArgument3,
                                                                         GALGAS_string & ioArgument4,
                                                                         C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i13_parse (C_Lexique_template_5F_scanner * inLexique) ;



//--- Select methods
  protected : virtual PMSInt32 select_template_5F_parser_0 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_template_5F_parser_1 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_template_5F_parser_2 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_template_5F_parser_3 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_template_5F_parser_4 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_template_5F_parser_5 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_template_5F_parser_6 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_template_5F_parser_7 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_template_5F_parser_8 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_template_5F_parser_9 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_template_5F_parser_10 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_template_5F_parser_11 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_template_5F_parser_12 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_template_5F_parser_13 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_template_5F_parser_14 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_template_5F_parser_15 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_template_5F_parser_16 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_template_5F_parser_17 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_template_5F_parser_18 (C_Lexique_template_5F_scanner *) = 0 ;


} ;

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

#endif
