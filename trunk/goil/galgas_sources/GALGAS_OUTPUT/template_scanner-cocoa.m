//---------------------------------------------------------------------------*
//                                                                           *
//                     File 'template_scanner-cocoa.m'                       *
//                    Generated by version version 2.3.0                     *
//                      march 1st, 2012, at 13h32'49"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1


#import "template_scanner-cocoa.h"

//---------------------------------------------------------------------------*

@implementation OC_Lexique_template_scanner

//---------------------------------------------------------------------------*

- (id) init {
  self = [super init] ;
  if (self) {
    mLexicalAttribute_a_string = [[NSMutableString alloc] init] ;
    mLexicalAttribute_floatValue = 0.0 ;
    mLexicalAttribute_identifierString = [[NSMutableString alloc] init] ;
    mLexicalAttribute_tokenString = [[NSMutableString alloc] init] ;
    mLexicalAttribute_uint64value = 0 ;
  }
  return self ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                 I N D E X I N G    D I R E C T O R Y                      *
//                                                                           *
//---------------------------------------------------------------------------*

- (NSString *) indexingDirectory {
  return @"" ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                 I N D E X I N G    T I T L E S                            *
//                                                                           *
//---------------------------------------------------------------------------*

- (NSArray *) indexingTitles { // Array of NSString
  return [NSArray arrayWithObjects:
    NULL
  ] ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                           Template Delimiters                             *
//                                                                           *
//---------------------------------------------------------------------------*

static const templateDelimiterStructForCocoa kTemplateDefinitionArray_template_5F_scanner [1] = {
  {@"%", @"%", YES}
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                           Template Replacments                            *
//                                                                           *
//---------------------------------------------------------------------------*

static NSString * kTemplateReplacementArray_template_5F_scanner [4] = {
  @"\\%", @"\\n", @"\\\\", nil
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//            Terminal Symbols as end of script in template mark             *
//                                                                           *
//---------------------------------------------------------------------------*

static const BOOL kEndOfScriptInTemplateArray_template_5F_scanner [82] = {
  NO /* identifier */,
  NO /* literal_double */,
  NO /* unsigned_literal_integer64 */,
  NO /* . */,
  NO /* .= */,
  NO /* ... */,
  NO /* < */,
  NO /* <= */,
  NO /* << */,
  NO /* string */,
  NO /* comment */,
  NO /* after */,
  NO /* before */,
  NO /* between */,
  NO /* block */,
  NO /* default */,
  NO /* do */,
  NO /* else */,
  NO /* elsif */,
  NO /* emptylist */,
  NO /* end */,
  NO /* error */,
  NO /* exists */,
  NO /* false */,
  NO /* for */,
  NO /* foreach */,
  NO /* from */,
  NO /* here */,
  NO /* if */,
  NO /* in */,
  NO /* let */,
  NO /* loop */,
  NO /* mod */,
  NO /* no */,
  NO /* not */,
  NO /* or */,
  NO /* prefixedby */,
  NO /* template */,
  NO /* templateresult */,
  NO /* then */,
  NO /* to */,
  NO /* true */,
  NO /* yes */,
  NO /* warning */,
  NO /* while */,
  NO /* write */,
  NO /* * */,
  NO /* | */,
  NO /* , */,
  NO /* + */,
  NO /* -- */,
  NO /* :: */,
  NO /* > */,
  NO /* ; */,
  NO /* : */,
  NO /* - */,
  NO /* ( */,
  NO /* ) */,
  NO /* -> */,
  NO /* ? */,
  NO /* == */,
  NO /* ?? */,
  NO /* ! */,
  NO /* := */,
  NO /* ++ */,
  NO /* [ */,
  NO /* ] */,
  NO /* += */,
  NO /* ?! */,
  NO /* !? */,
  NO /* / */,
  NO /* != */,
  NO /* >= */,
  NO /* & */,
  NO /* { */,
  NO /* } */,
  NO /* +> */,
  NO /* -= */,
  NO /* ^ */,
  NO /* >> */,
  NO /* ~ */,
  NO /* <- */
} ;


//---------------------------------------------------------------------------*
//                                                                           *
//             Key words table 'goilTemplateKeyWordList'                            *
//                                                                           *
//---------------------------------------------------------------------------*

static const C_cocoa_lexique_table_entry ktable_for_template_5F_scanner_goilTemplateKeyWordList [35] = {
  {@"do", template_scanner_1_do},
  {@"if", template_scanner_1_if},
  {@"in", template_scanner_1_in},
  {@"no", template_scanner_1_no},
  {@"or", template_scanner_1_or},
  {@"to", template_scanner_1_to},
  {@"end", template_scanner_1_end},
  {@"for", template_scanner_1_for},
  {@"let", template_scanner_1_let},
  {@"mod", template_scanner_1_mod},
  {@"not", template_scanner_1_not},
  {@"yes", template_scanner_1_yes},
  {@"else", template_scanner_1_else},
  {@"from", template_scanner_1_from},
  {@"here", template_scanner_1_here},
  {@"loop", template_scanner_1_loop},
  {@"then", template_scanner_1_then},
  {@"true", template_scanner_1_true},
  {@"after", template_scanner_1_after},
  {@"block", template_scanner_1_block},
  {@"elsif", template_scanner_1_elsif},
  {@"error", template_scanner_1_error},
  {@"false", template_scanner_1_false},
  {@"while", template_scanner_1_while},
  {@"write", template_scanner_1_write},
  {@"before", template_scanner_1_before},
  {@"exists", template_scanner_1_exists},
  {@"between", template_scanner_1_between},
  {@"default", template_scanner_1_default},
  {@"foreach", template_scanner_1_foreach},
  {@"warning", template_scanner_1_warning},
  {@"template", template_scanner_1_template},
  {@"emptylist", template_scanner_1_emptylist},
  {@"prefixedby", template_scanner_1_prefixedby},
  {@"templateresult", template_scanner_1_templateresult}
} ;

static SInt32 search_into_template_5F_scanner_goilTemplateKeyWordList (NSString * inSearchedString) {
  return searchStringInTable (inSearchedString, ktable_for_template_5F_scanner_goilTemplateKeyWordList, 35) ;
}


//---------------------------------------------------------------------------*
//                                                                           *
//               P A R S E    L E X I C A L    T O K E N                     *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) parseLexicalTokenForLexicalColoring {
  mLoop = YES ;
  BOOL scanningOk = YES ;
  mTokenCode = 0 ;
  while ((mTokenCode == 0) && (mCurrentChar != '\0')) {
    mTokenStartLocation = mCurrentLocation ;
    if ((mMatchedTemplateDelimiterIndex >= 0) && ([kTemplateDefinitionArray_template_5F_scanner [mMatchedTemplateDelimiterIndex].mStartString length] > 0)) {
      const BOOL foundEndDelimitor = [self testForInputString:kTemplateDefinitionArray_template_5F_scanner [mMatchedTemplateDelimiterIndex].mEndString advance:YES] ;
      if (foundEndDelimitor) {
        mMatchedTemplateDelimiterIndex = -1 ;
      }
    }
    while ((mMatchedTemplateDelimiterIndex < 0) && (mCurrentChar != '\0')) {
      
      [self searchForReplacementPattern:kTemplateReplacementArray_template_5F_scanner] ;
      
      mMatchedTemplateDelimiterIndex = [self findTemplateDelimiterIndex:kTemplateDefinitionArray_template_5F_scanner listLength:1] ;
      if (mMatchedTemplateDelimiterIndex < 0) {
        [self advance] ;
        mTokenCode = -2 ;
      }
    }
    if ((mMatchedTemplateDelimiterIndex >= 0) && (mTokenCode == 0) && (mCurrentChar != '\0') && scanningOk) {
      [mLexicalAttribute_a_string setString:@""] ;
      mLexicalAttribute_floatValue = 0.0 ;
      [mLexicalAttribute_identifierString setString:@""] ;
      [mLexicalAttribute_tokenString setString:@""] ;
      mLexicalAttribute_uint64value = 0 ;
      mTokenStartLocation = mCurrentLocation ;
      if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90])) {
        do {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_identifierString, scanner_cocoa_function_toLower (mPreviousChar)) ;
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
          if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90] || [self testForInputChar:95] || [self testForInputFromChar:48 toChar:57])) {
          }else{
            mLoop = NO ;
          }
        }while (mLoop && scanningOk) ;
        mLoop = YES ;
        if (mTokenCode == 0) {
          mTokenCode = search_into_template_5F_scanner_goilTemplateKeyWordList (mLexicalAttribute_identifierString) ;
        }
        if (mTokenCode == 0) {
          mTokenCode = template_scanner_1_identifier ;
        }
      }else if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
        do {
          if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
            scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
          }else if (scanningOk && ([self testForInputChar:95])) {
          }else{
            mLoop = NO ;
          }
        }while (mLoop && scanningOk) ;
        mLoop = YES ;
        if (scanningOk && ([self testForInputChar:46])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 46) ;
          do {
            if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
              scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
            }else if (scanningOk && ([self testForInputChar:95])) {
            }else{
              mLoop = NO ;
            }
          }while (mLoop && scanningOk) ;
          mLoop = YES ;
          scanner_cocoa_routine_convertStringToDouble (& scanningOk, mLexicalAttribute_tokenString, & mLexicalAttribute_floatValue) ;
          mTokenCode = template_scanner_1_literal_5F_double ;
        }else{
          scanner_cocoa_routine_convertDecimalStringIntoUInt64 (& scanningOk, mLexicalAttribute_tokenString, & mLexicalAttribute_uint64value) ;
          mTokenCode = template_scanner_1_unsigned_5F_literal_5F_integer_36__34_ ;
        }
      }else if (scanningOk && ([self testForInputChar:46])) {
        if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 48) ;
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 46) ;
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
          do {
            if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
              scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
            }else if (scanningOk && ([self testForInputChar:95])) {
            }else{
              mLoop = NO ;
            }
          }while (mLoop && scanningOk) ;
          mLoop = YES ;
          scanner_cocoa_routine_convertStringToDouble (& scanningOk, mLexicalAttribute_tokenString, & mLexicalAttribute_floatValue) ;
          mTokenCode = template_scanner_1_literal_5F_double ;
        }else{
          if (scanningOk && ([self testForInputString:@".." advance:YES])) {
            mTokenCode = template_scanner_1__2E__2E__2E_ ;
          }else if (scanningOk && ([self testForInputString:@"=" advance:YES])) {
            mTokenCode = template_scanner_1__2E__3D_ ;
          }else{
            mTokenCode = template_scanner_1__2E_ ;
          }
        }
      }else if (scanningOk && [self testForInputString:@"\?\?" advance:YES]) {
        mTokenCode = template_scanner_1__3F__3F_ ;
      }else if (scanningOk && [self testForInputString:@"\?!" advance:YES]) {
        mTokenCode = template_scanner_1__3F__21_ ;
      }else if (scanningOk && [self testForInputString:@">>" advance:YES]) {
        mTokenCode = template_scanner_1__3E__3E_ ;
      }else if (scanningOk && [self testForInputString:@">=" advance:YES]) {
        mTokenCode = template_scanner_1__3E__3D_ ;
      }else if (scanningOk && [self testForInputString:@"==" advance:YES]) {
        mTokenCode = template_scanner_1__3D__3D_ ;
      }else if (scanningOk && [self testForInputString:@"<-" advance:YES]) {
        mTokenCode = template_scanner_1__3C__2D_ ;
      }else if (scanningOk && [self testForInputString:@":=" advance:YES]) {
        mTokenCode = template_scanner_1__3A__3D_ ;
      }else if (scanningOk && [self testForInputString:@"::" advance:YES]) {
        mTokenCode = template_scanner_1__3A__3A_ ;
      }else if (scanningOk && [self testForInputString:@"->" advance:YES]) {
        mTokenCode = template_scanner_1__2D__3E_ ;
      }else if (scanningOk && [self testForInputString:@"-=" advance:YES]) {
        mTokenCode = template_scanner_1__2D__3D_ ;
      }else if (scanningOk && [self testForInputString:@"--" advance:YES]) {
        mTokenCode = template_scanner_1__2D__2D_ ;
      }else if (scanningOk && [self testForInputString:@"+>" advance:YES]) {
        mTokenCode = template_scanner_1__2B__3E_ ;
      }else if (scanningOk && [self testForInputString:@"+=" advance:YES]) {
        mTokenCode = template_scanner_1__2B__3D_ ;
      }else if (scanningOk && [self testForInputString:@"++" advance:YES]) {
        mTokenCode = template_scanner_1__2B__2B_ ;
      }else if (scanningOk && [self testForInputString:@"!\?" advance:YES]) {
        mTokenCode = template_scanner_1__21__3F_ ;
      }else if (scanningOk && [self testForInputString:@"!=" advance:YES]) {
        mTokenCode = template_scanner_1__21__3D_ ;
      }else if (scanningOk && [self testForInputString:@"~" advance:YES]) {
        mTokenCode = template_scanner_1__7E_ ;
      }else if (scanningOk && [self testForInputString:@"}" advance:YES]) {
        mTokenCode = template_scanner_1__7D_ ;
      }else if (scanningOk && [self testForInputString:@"|" advance:YES]) {
        mTokenCode = template_scanner_1__7C_ ;
      }else if (scanningOk && [self testForInputString:@"{" advance:YES]) {
        mTokenCode = template_scanner_1__7B_ ;
      }else if (scanningOk && [self testForInputString:@"^" advance:YES]) {
        mTokenCode = template_scanner_1__5E_ ;
      }else if (scanningOk && [self testForInputString:@"]" advance:YES]) {
        mTokenCode = template_scanner_1__5D_ ;
      }else if (scanningOk && [self testForInputString:@"[" advance:YES]) {
        mTokenCode = template_scanner_1__5B_ ;
      }else if (scanningOk && [self testForInputString:@"\?" advance:YES]) {
        mTokenCode = template_scanner_1__3F_ ;
      }else if (scanningOk && [self testForInputString:@">" advance:YES]) {
        mTokenCode = template_scanner_1__3E_ ;
      }else if (scanningOk && [self testForInputString:@";" advance:YES]) {
        mTokenCode = template_scanner_1__3B_ ;
      }else if (scanningOk && [self testForInputString:@":" advance:YES]) {
        mTokenCode = template_scanner_1__3A_ ;
      }else if (scanningOk && [self testForInputString:@"/" advance:YES]) {
        mTokenCode = template_scanner_1__2F_ ;
      }else if (scanningOk && [self testForInputString:@"-" advance:YES]) {
        mTokenCode = template_scanner_1__2D_ ;
      }else if (scanningOk && [self testForInputString:@"," advance:YES]) {
        mTokenCode = template_scanner_1__2C_ ;
      }else if (scanningOk && [self testForInputString:@"+" advance:YES]) {
        mTokenCode = template_scanner_1__2B_ ;
      }else if (scanningOk && [self testForInputString:@"*" advance:YES]) {
        mTokenCode = template_scanner_1__2A_ ;
      }else if (scanningOk && [self testForInputString:@")" advance:YES]) {
        mTokenCode = template_scanner_1__29_ ;
      }else if (scanningOk && [self testForInputString:@"(" advance:YES]) {
        mTokenCode = template_scanner_1__28_ ;
      }else if (scanningOk && [self testForInputString:@"&" advance:YES]) {
        mTokenCode = template_scanner_1__26_ ;
      }else if (scanningOk && [self testForInputString:@"!" advance:YES]) {
        mTokenCode = template_scanner_1__21_ ;
      }else if (scanningOk && ([self testForInputChar:60])) {
        if (scanningOk && ([self testForInputChar:61])) {
          mTokenCode = template_scanner_1__3C__3D_ ;
        }else if (scanningOk && ([self testForInputChar:60])) {
          mTokenCode = template_scanner_1__3C__3C_ ;
        }else{
          mTokenCode = template_scanner_1__3C_ ;
        }
      }else if (scanningOk && ([self testForInputChar:34])) {
        do {
          if (scanningOk && ([self testForInputFromChar:32 toChar:33] || [self testForInputFromChar:35 toChar:65533])) {
            scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_a_string, mPreviousChar) ;
          }else{
            mLoop = NO ;
          }
        }while (mLoop && scanningOk) ;
        mLoop = YES ;
        if (scanningOk && ([self testForInputChar:34])) {
          mTokenCode = template_scanner_1_string ;
        }else{
          scanningOk = NO ;
        }
      }else if (scanningOk && ([self testForInputChar:35])) {
        do {
          if (scanningOk && ([self testForInputFromChar:1 toChar:9] || [self testForInputChar:11] || [self testForInputChar:12] || [self testForInputFromChar:14 toChar:65533])) {
          }else{
            mLoop = NO ;
          }
        }while (mLoop && scanningOk) ;
        mLoop = YES ;
        mTokenCode = template_scanner_1_comment ;
      }else if (scanningOk && ([self testForInputFromChar:1 toChar:32])) {
      }else if ([self testForInputChar:'\0']) { // End of source text ? 
        mTokenCode = template_scanner_1_ ; // Empty string code
      }else{ // Unknown input character
        scanningOk = NO ;
      }
    }
    if ((mTokenCode > 0) && kEndOfScriptInTemplateArray_template_5F_scanner [mTokenCode - 1]) {
      mMatchedTemplateDelimiterIndex = -1 ;
    }
  //--- Error ?
    if (! scanningOk) {
      mTokenCode = -1 ;
      [self advance] ;
    }
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//                   T E R M I N A L    C O U N T                            *
//                                                                           *
//---------------------------------------------------------------------------*

- (UInt32) terminalVocabularyCount {
  return 82 ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                     S T Y L E   C O U N T                                 *
//                                                                           *
//---------------------------------------------------------------------------*

- (UInt32) styleCount {
  return 8 ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                I S    T E M P L A T E    L E X I Q U E                    *
//                                                                           *
//---------------------------------------------------------------------------*

- (BOOL) isTemplateLexique {
  return YES ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//              S T Y L E   F O R    T E R M I N A L                         *
//                                                                           *
//---------------------------------------------------------------------------*

- (UInt32) styleIndexForTerminal: (SInt32) inTerminal {
  static const UInt32 kTerminalSymbolStyles [83] = {0,
    0 /* template_scanner_1_identifier */,
    5 /* template_scanner_1_literal_5F_double */,
    4 /* template_scanner_1_unsigned_5F_literal_5F_integer_36__34_ */,
    2 /* template_scanner_1__2E_ */,
    2 /* template_scanner_1__2E__3D_ */,
    2 /* template_scanner_1__2E__2E__2E_ */,
    2 /* template_scanner_1__3C_ */,
    2 /* template_scanner_1__3C__3D_ */,
    2 /* template_scanner_1__3C__3C_ */,
    6 /* template_scanner_1_string */,
    7 /* template_scanner_1_comment */,
    1 /* template_scanner_1_after */,
    1 /* template_scanner_1_before */,
    1 /* template_scanner_1_between */,
    1 /* template_scanner_1_block */,
    1 /* template_scanner_1_default */,
    1 /* template_scanner_1_do */,
    1 /* template_scanner_1_else */,
    1 /* template_scanner_1_elsif */,
    1 /* template_scanner_1_emptylist */,
    1 /* template_scanner_1_end */,
    1 /* template_scanner_1_error */,
    1 /* template_scanner_1_exists */,
    1 /* template_scanner_1_false */,
    1 /* template_scanner_1_for */,
    1 /* template_scanner_1_foreach */,
    1 /* template_scanner_1_from */,
    1 /* template_scanner_1_here */,
    1 /* template_scanner_1_if */,
    1 /* template_scanner_1_in */,
    1 /* template_scanner_1_let */,
    1 /* template_scanner_1_loop */,
    1 /* template_scanner_1_mod */,
    1 /* template_scanner_1_no */,
    1 /* template_scanner_1_not */,
    1 /* template_scanner_1_or */,
    1 /* template_scanner_1_prefixedby */,
    1 /* template_scanner_1_template */,
    1 /* template_scanner_1_templateresult */,
    1 /* template_scanner_1_then */,
    1 /* template_scanner_1_to */,
    1 /* template_scanner_1_true */,
    1 /* template_scanner_1_yes */,
    1 /* template_scanner_1_warning */,
    1 /* template_scanner_1_while */,
    1 /* template_scanner_1_write */,
    2 /* template_scanner_1__2A_ */,
    2 /* template_scanner_1__7C_ */,
    2 /* template_scanner_1__2C_ */,
    2 /* template_scanner_1__2B_ */,
    2 /* template_scanner_1__2D__2D_ */,
    2 /* template_scanner_1__3A__3A_ */,
    2 /* template_scanner_1__3E_ */,
    2 /* template_scanner_1__3B_ */,
    2 /* template_scanner_1__3A_ */,
    2 /* template_scanner_1__2D_ */,
    2 /* template_scanner_1__28_ */,
    2 /* template_scanner_1__29_ */,
    2 /* template_scanner_1__2D__3E_ */,
    2 /* template_scanner_1__3F_ */,
    2 /* template_scanner_1__3D__3D_ */,
    2 /* template_scanner_1__3F__3F_ */,
    2 /* template_scanner_1__21_ */,
    2 /* template_scanner_1__3A__3D_ */,
    2 /* template_scanner_1__2B__2B_ */,
    2 /* template_scanner_1__5B_ */,
    2 /* template_scanner_1__5D_ */,
    2 /* template_scanner_1__2B__3D_ */,
    2 /* template_scanner_1__3F__21_ */,
    2 /* template_scanner_1__21__3F_ */,
    2 /* template_scanner_1__2F_ */,
    2 /* template_scanner_1__21__3D_ */,
    2 /* template_scanner_1__3E__3D_ */,
    2 /* template_scanner_1__26_ */,
    2 /* template_scanner_1__7B_ */,
    2 /* template_scanner_1__7D_ */,
    2 /* template_scanner_1__2B__3E_ */,
    2 /* template_scanner_1__2D__3D_ */,
    2 /* template_scanner_1__5E_ */,
    2 /* template_scanner_1__3E__3E_ */,
    2 /* template_scanner_1__7E_ */,
    2 /* template_scanner_1__3C__2D_ */
  } ;
  return kTerminalSymbolStyles [inTerminal] ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//    A T O M I C    S E L E C T I O N   F O R    T E R M I N A L            *
//                                                                           *
//---------------------------------------------------------------------------*

- (BOOL) atomicSelectionForToken: (NSUInteger) inTokenIndex {
  static const BOOL kTerminalAtomicSelection [83] = {NO,
    YES /* template_scanner_1_identifier */,
    YES /* template_scanner_1_literal_5F_double */,
    YES /* template_scanner_1_unsigned_5F_literal_5F_integer_36__34_ */,
    YES /* template_scanner_1__2E_ */,
    YES /* template_scanner_1__2E__3D_ */,
    YES /* template_scanner_1__2E__2E__2E_ */,
    YES /* template_scanner_1__3C_ */,
    YES /* template_scanner_1__3C__3D_ */,
    YES /* template_scanner_1__3C__3C_ */,
    YES /* template_scanner_1_string */,
    YES /* template_scanner_1_comment */,
    YES /* template_scanner_1_after */,
    YES /* template_scanner_1_before */,
    YES /* template_scanner_1_between */,
    YES /* template_scanner_1_block */,
    YES /* template_scanner_1_default */,
    YES /* template_scanner_1_do */,
    YES /* template_scanner_1_else */,
    YES /* template_scanner_1_elsif */,
    YES /* template_scanner_1_emptylist */,
    YES /* template_scanner_1_end */,
    YES /* template_scanner_1_error */,
    YES /* template_scanner_1_exists */,
    YES /* template_scanner_1_false */,
    YES /* template_scanner_1_for */,
    YES /* template_scanner_1_foreach */,
    YES /* template_scanner_1_from */,
    YES /* template_scanner_1_here */,
    YES /* template_scanner_1_if */,
    YES /* template_scanner_1_in */,
    YES /* template_scanner_1_let */,
    YES /* template_scanner_1_loop */,
    YES /* template_scanner_1_mod */,
    YES /* template_scanner_1_no */,
    YES /* template_scanner_1_not */,
    YES /* template_scanner_1_or */,
    YES /* template_scanner_1_prefixedby */,
    YES /* template_scanner_1_template */,
    YES /* template_scanner_1_templateresult */,
    YES /* template_scanner_1_then */,
    YES /* template_scanner_1_to */,
    YES /* template_scanner_1_true */,
    YES /* template_scanner_1_yes */,
    YES /* template_scanner_1_warning */,
    YES /* template_scanner_1_while */,
    YES /* template_scanner_1_write */,
    YES /* template_scanner_1__2A_ */,
    YES /* template_scanner_1__7C_ */,
    YES /* template_scanner_1__2C_ */,
    YES /* template_scanner_1__2B_ */,
    YES /* template_scanner_1__2D__2D_ */,
    YES /* template_scanner_1__3A__3A_ */,
    YES /* template_scanner_1__3E_ */,
    YES /* template_scanner_1__3B_ */,
    YES /* template_scanner_1__3A_ */,
    YES /* template_scanner_1__2D_ */,
    YES /* template_scanner_1__28_ */,
    YES /* template_scanner_1__29_ */,
    YES /* template_scanner_1__2D__3E_ */,
    YES /* template_scanner_1__3F_ */,
    YES /* template_scanner_1__3D__3D_ */,
    YES /* template_scanner_1__3F__3F_ */,
    YES /* template_scanner_1__21_ */,
    YES /* template_scanner_1__3A__3D_ */,
    YES /* template_scanner_1__2B__2B_ */,
    YES /* template_scanner_1__5B_ */,
    YES /* template_scanner_1__5D_ */,
    YES /* template_scanner_1__2B__3D_ */,
    YES /* template_scanner_1__3F__21_ */,
    YES /* template_scanner_1__21__3F_ */,
    YES /* template_scanner_1__2F_ */,
    YES /* template_scanner_1__21__3D_ */,
    YES /* template_scanner_1__3E__3D_ */,
    YES /* template_scanner_1__26_ */,
    YES /* template_scanner_1__7B_ */,
    YES /* template_scanner_1__7D_ */,
    YES /* template_scanner_1__2B__3E_ */,
    YES /* template_scanner_1__2D__3D_ */,
    YES /* template_scanner_1__5E_ */,
    YES /* template_scanner_1__3E__3E_ */,
    YES /* template_scanner_1__7E_ */,
    YES /* template_scanner_1__3C__2D_ */
  } ;
  return kTerminalAtomicSelection [inTokenIndex] ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//             S T Y L E   N A M E    F O R    I N D E X                     *
//                                                                           *
//---------------------------------------------------------------------------*

- (NSString *) styleNameForStyleIndex: (SInt32) inIndex {
  NSString * result = nil ;
  if ((inIndex >= 0) && (inIndex < 8)) {
    NSString * kStyleArray [8] = {
      @"Default Style",
      @"Keywords",
      @"Delimiters",
      @"Non Terminal Symbols",
      @"Integer Constants",
      @"Floating Point Constants",
      @"String literals",
      @"Comments"
    } ;
    result = kStyleArray [inIndex] ;
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//         S T Y L E   I D E N T I F I E R    F O R    I N D E X             *
//                                                                           *
//---------------------------------------------------------------------------*

- (NSString *) styleIdentifierForStyleIndex: (SInt32) inIndex {
  NSString * result = nil ;
  if ((inIndex >= 0) && (inIndex < 8)) {
    NSString * kStyleArray [8] = {
      @"template_scanner",
      @"template_scanner-keywordsStyle",
      @"template_scanner-delimitersStyle",
      @"template_scanner-nonTerminalStyle",
      @"template_scanner-integerStyle",
      @"template_scanner-float_csts",
      @"template_scanner-stringStyle",
      @"template_scanner-commentStyle"
    } ;
    result = kStyleArray [inIndex] ;
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//         L E X I Q U E   I D E N T I F I E R                               *
//                                                                           *
//---------------------------------------------------------------------------*

- (NSString *) lexiqueIdentifier {
  return @"template_scanner" ;
}

//---------------------------------------------------------------------------*

@end

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2



