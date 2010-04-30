//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'api_scanner.cpp'                           *
//                       Generated by version 1.9.11                         *
//                      april 30th, 2010, at 16h48'51"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1


//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if CURRENT_LIBPM_VERSION != 725
  #error "This file has been compiled with a version of GALGAS that uses libpm version 725, different than the current version (CURRENT_LIBPM_VERSION) of libpm"
#endif

//---------------------------------------------------------------------------*

#include <ctype.h>
#include <string.h>

#include "utilities/MF_MemoryControl.h"
#include "api_scanner.h"

#include "strings/unicode_character_cpp.h"
#include "galgas/scanner_actions.h"
#ifndef DO_NOT_GENERATE_CHECKINGS
  #define LINE_AND_SOURCE_FILE sourceText ()->sourceFileName ().cString (HERE), lineNumber ()
  #define COMMA_LINE_AND_SOURCE_FILE , LINE_AND_SOURCE_FILE
#else
  #define LINE_AND_SOURCE_FILE
  #define COMMA_LINE_AND_SOURCE_FILE
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//                               Constructors                                *
//                                                                           *
//---------------------------------------------------------------------------*

cTokenFor_api_5F_scanner::cTokenFor_api_5F_scanner (void) :
mLexicalAttribute_att_5F_token () {
}

//---------------------------------------------------------------------------*

C_Lexique_api_5F_scanner::C_Lexique_api_5F_scanner (C_Compiler * inCallerCompiler,
                const C_String & inDependencyFileExtension,
                const C_String & inDependencyFilePath,
                C_galgas_io * inParametersPtr,
                const C_String & inSourceFileName
                COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inDependencyFileExtension, inDependencyFilePath, inParametersPtr, inSourceFileName COMMA_THERE) {
}

//---------------------------------------------------------------------------*

C_Lexique_api_5F_scanner::C_Lexique_api_5F_scanner (C_Compiler * inCallerCompiler,
                C_galgas_io * inParametersPtr,
                const C_String & inSourceString,
                const C_String & inStringForError
                COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inParametersPtr, inSourceString, inStringForError COMMA_THERE) {
}

//---------------------------------------------------------------------------*
//                                                                           *
//                        Lexical error message list                         *
//                                                                           *
//---------------------------------------------------------------------------*

static const utf32 gLexicalMessage_unterminated_comment_error [] = {
  TO_UNICODE ('u'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE ('m'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('d'),
  TO_UNICODE (' '),
  TO_UNICODE ('c'),
  TO_UNICODE ('o'),
  TO_UNICODE ('m'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//          Syntax error messages, for every terminal symbol                 *
//                                                                           *
//---------------------------------------------------------------------------*

//--- Syntax error message for terminal '$comment$' :
static const utf32 gSyntaxErrorMessage_comment [] = {
  TO_UNICODE ('a'),
  TO_UNICODE (' '),
  TO_UNICODE ('c'),
  TO_UNICODE ('o'),
  TO_UNICODE ('m'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Syntax error message for terminal '$idf$' :
static const utf32 gSyntaxErrorMessage_idf [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('d'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE ('i'),
  TO_UNICODE ('f'),
  TO_UNICODE ('i'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Syntax error message for terminal '$;$' :
static const utf32 gSyntaxErrorMessage__3B_ [] = {
  TO_UNICODE ('\''),
  TO_UNICODE (';'),
  TO_UNICODE ('\''),
  TO_UNICODE (' '),
  TO_UNICODE ('d'),
  TO_UNICODE ('e'),
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('m'),
  TO_UNICODE ('i'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Syntax error message for terminal '${$' :
static const utf32 gSyntaxErrorMessage__7B_ [] = {
  TO_UNICODE ('\''),
  TO_UNICODE ('{'),
  TO_UNICODE ('\''),
  TO_UNICODE (' '),
  TO_UNICODE ('d'),
  TO_UNICODE ('e'),
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('m'),
  TO_UNICODE ('i'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Syntax error message for terminal '$}$' :
static const utf32 gSyntaxErrorMessage__7D_ [] = {
  TO_UNICODE ('\''),
  TO_UNICODE ('}'),
  TO_UNICODE ('\''),
  TO_UNICODE (' '),
  TO_UNICODE ('d'),
  TO_UNICODE ('e'),
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('m'),
  TO_UNICODE ('i'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Syntax error message for terminal '$->$' :
static const utf32 gSyntaxErrorMessage__2D__3E_ [] = {
  TO_UNICODE ('\''),
  TO_UNICODE ('-'),
  TO_UNICODE ('>'),
  TO_UNICODE ('\''),
  TO_UNICODE (' '),
  TO_UNICODE ('d'),
  TO_UNICODE ('e'),
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('m'),
  TO_UNICODE ('i'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Syntax error message for terminal '$($' :
static const utf32 gSyntaxErrorMessage__28_ [] = {
  TO_UNICODE ('\''),
  TO_UNICODE ('('),
  TO_UNICODE ('\''),
  TO_UNICODE (' '),
  TO_UNICODE ('d'),
  TO_UNICODE ('e'),
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('m'),
  TO_UNICODE ('i'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Syntax error message for terminal '$)$' :
static const utf32 gSyntaxErrorMessage__29_ [] = {
  TO_UNICODE ('\''),
  TO_UNICODE (')'),
  TO_UNICODE ('\''),
  TO_UNICODE (' '),
  TO_UNICODE ('d'),
  TO_UNICODE ('e'),
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('m'),
  TO_UNICODE ('i'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                appendTerminalMessageToSyntaxErrorMessage                  *
//                                                                           *
//---------------------------------------------------------------------------*

void C_Lexique_api_5F_scanner::appendTerminalMessageToSyntaxErrorMessage (const PMSInt16 inTerminalIndex,
                                           C_String & outSyntaxErrorMessage) {
  static const utf32 * syntaxErrorMessageArray [9] = {kEndOfSourceLexicalErrorMessage,
    gSyntaxErrorMessage_comment,
    gSyntaxErrorMessage_idf,
    gSyntaxErrorMessage__3B_,
    gSyntaxErrorMessage__7B_,
    gSyntaxErrorMessage__7D_,
    gSyntaxErrorMessage__2D__3E_,
    gSyntaxErrorMessage__28_,
    gSyntaxErrorMessage__29_} ;
  outSyntaxErrorMessage << syntaxErrorMessageArray [inTerminalIndex] ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                      U N I C O D E    S T R I N G S                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- Unicode string for '$_28_$'
static const utf32 kUnicodeString__28_ [] = {
  TO_UNICODE ('('),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_29_$'
static const utf32 kUnicodeString__29_ [] = {
  TO_UNICODE (')'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2A__2F_$'
static const utf32 kUnicodeString__2A__2F_ [] = {
  TO_UNICODE ('*'),
  TO_UNICODE ('/'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2D__3E_$'
static const utf32 kUnicodeString__2D__3E_ [] = {
  TO_UNICODE ('-'),
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2F__2A_$'
static const utf32 kUnicodeString__2F__2A_ [] = {
  TO_UNICODE ('/'),
  TO_UNICODE ('*'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2F__2F_$'
static const utf32 kUnicodeString__2F__2F_ [] = {
  TO_UNICODE ('/'),
  TO_UNICODE ('/'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3B_$'
static const utf32 kUnicodeString__3B_ [] = {
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7B_$'
static const utf32 kUnicodeString__7B_ [] = {
  TO_UNICODE ('{'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7D_$'
static const utf32 kUnicodeString__7D_ [] = {
  TO_UNICODE ('}'),
  TO_UNICODE (0)
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//             Key words table 'delimiters'                            *
//                                                                           *
//---------------------------------------------------------------------------*

static const PMSInt32 ktable_size_delimiters = 6 ;

static const C_unicode_lexique_table_entry ktable_for_delimiters [ktable_size_delimiters] = {
  C_unicode_lexique_table_entry (kUnicodeString__28_, 1, C_Lexique_api_5F_scanner::kToken__28_),
  C_unicode_lexique_table_entry (kUnicodeString__29_, 1, C_Lexique_api_5F_scanner::kToken__29_),
  C_unicode_lexique_table_entry (kUnicodeString__3B_, 1, C_Lexique_api_5F_scanner::kToken__3B_),
  C_unicode_lexique_table_entry (kUnicodeString__7B_, 1, C_Lexique_api_5F_scanner::kToken__7B_),
  C_unicode_lexique_table_entry (kUnicodeString__7D_, 1, C_Lexique_api_5F_scanner::kToken__7D_),
  C_unicode_lexique_table_entry (kUnicodeString__2D__3E_, 2, C_Lexique_api_5F_scanner::kToken__2D__3E_)
} ;

PMSInt16 C_Lexique_api_5F_scanner::search_into_delimiters (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_delimiters, ktable_size_delimiters) ;
}


//---------------------------------------------------------------------------*
//                                                                           *
//                          getCurrentTokenString                            *
//                                                                           *
//---------------------------------------------------------------------------*

C_String C_Lexique_api_5F_scanner::getCurrentTokenString (const cToken * inTokenPtr) const {
  const cTokenFor_api_5F_scanner * ptr = (const cTokenFor_api_5F_scanner *) inTokenPtr ;
  C_String s ;
  if (ptr == NULL) {
    s.appendCString("$$") ;
  }else{
    switch (ptr->mTokenCode) {
    case kToken_:
      s.appendCString("$$") ;
      break ;
    case kToken_comment:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("comment") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_idf:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("idf") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_att_5F_token) ;
      break ;
    case kToken__3B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (";") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("{") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("}") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2D__3E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("->") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__28_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("(") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__29_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (")") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    default:
      break ;
    }
  }
  return s ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                           Template Delimiters                             *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                           Template Replacements                           *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//            Terminal Symbols as end of script in template mark             *
//                                                                           *
//---------------------------------------------------------------------------*

static const bool kEndOfScriptInTemplateArray [8] = {
  false /* comment */,
  false /* idf */,
  false /* ; */,
  false /* { */,
  false /* } */,
  false /* -> */,
  false /* ( */,
  false /* ) */
} ;


//---------------------------------------------------------------------------*
//                                                                           *
//               P A R S E    L E X I C A L    T O K E N                     *
//                                                                           *
//---------------------------------------------------------------------------*

bool C_Lexique_api_5F_scanner::parseLexicalToken (void) {
  cTokenFor_api_5F_scanner token ;
  mLoop = true ;
  token.mTokenCode = -1 ;
  while ((token.mTokenCode < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
    token.mLexicalAttribute_att_5F_token.setLengthToZero () ;
    mTokenFirstLocation = mCurrentLocation ;
    try{
      if (testForInputUTF32String (kUnicodeString__2F__2F_, 2, true)) {
        do {
          if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE ('\t')) || testForInputUTF32Char (TO_UNICODE ('\v')) || testForInputUTF32Char (TO_UNICODE ('\f')) || testForInputUTF32CharRange (TO_UNICODE (14), TO_UNICODE (65533))) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
      }else if (testForInputUTF32String (kUnicodeString__2F__2A_, 2, true)) {
        do {
          if (notTestForInputUTF32String (kUnicodeString__2A__2F_, 2, gLexicalMessage_unterminated_comment_error COMMA_LINE_AND_SOURCE_FILE)) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
      }else if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z'))) {
        do {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_att_5F_token, previousChar ()) ;
          if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z')) || testForInputUTF32Char (TO_UNICODE ('_')) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        token.mTokenCode = kToken_idf ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString__2D__3E_, 2, true)) {
        token.mTokenCode = kToken__2D__3E_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString__7D_, 1, true)) {
        token.mTokenCode = kToken__7D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString__7B_, 1, true)) {
        token.mTokenCode = kToken__7B_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString__3B_, 1, true)) {
        token.mTokenCode = kToken__3B_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString__29_, 1, true)) {
        token.mTokenCode = kToken__29_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString__28_, 1, true)) {
        token.mTokenCode = kToken__28_ ;
        enterToken (token) ;
      }else if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE (' '))) {
      }else if (testForInputUTF32Char (TO_UNICODE ('\0'))) { // End of source text ? 
        token.mTokenCode = kToken_ ; // Empty string code
      }else{ // Unknown input character
        unknownCharacterLexicalError (LINE_AND_SOURCE_FILE) ;
      }
    }catch (const C_lexicalErrorException &) {
      token.mTokenCode = -1 ; // No token
      advance () ; // ... go throught unknown character
    }
  }
  if ((UNICODE_VALUE (mCurrentChar) == '\0') && (token.mTemplateStringBeforeToken.length () > 0)) {
    token.mTokenCode = 0 ;
    enterToken (token) ;
  }
  return token.mTokenCode > 0 ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                         E N T E R    T O K E N                            *
//                                                                           *
//---------------------------------------------------------------------------*

void C_Lexique_api_5F_scanner::enterToken (const cTokenFor_api_5F_scanner & inToken) {
  cTokenFor_api_5F_scanner * ptr = NULL ;
  macroMyNew (ptr, cTokenFor_api_5F_scanner ()) ;
  ptr->mTokenCode = inToken.mTokenCode ;
  ptr->mStartLocation = mTokenFirstLocation ;
  ptr->mEndLocation = mTokenLastLocation ;
  ptr->mTemplateStringBeforeToken = inToken.mTemplateStringBeforeToken ;
  ptr->mLexicalAttribute_att_5F_token = inToken.mLexicalAttribute_att_5F_token ;
  enterTokenFromPointer (ptr) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//               A T T R I B U T E   A C C E S S                             *
//                                                                           *
//---------------------------------------------------------------------------*

C_String C_Lexique_api_5F_scanner::attributeValue_att_5F_token (void) const {
  cTokenFor_api_5F_scanner * ptr = (cTokenFor_api_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_att_5F_token ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//         A S S I G N    F R O M    A T T R I B U T E    ( V 1 )            *
//                                                                           *
//---------------------------------------------------------------------------*

void C_Lexique_api_5F_scanner::assignFromAttribute_att_5F_token (GGS_lstring & outValue) const {
  cTokenFor_api_5F_scanner * ptr = (cTokenFor_api_5F_scanner *) mCurrentTokenPtr ;
  outValue = GGS_lstring (* this, ptr->mLexicalAttribute_att_5F_token) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//         A S S I G N    F R O M    A T T R I B U T E    ( V 2 )            *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_lstring * C_Lexique_api_5F_scanner::synthetizedAttribute_att_5F_token (void) const {
  cTokenFor_api_5F_scanner * ptr = (cTokenFor_api_5F_scanner *) mCurrentTokenPtr ;
  macroValidObject (ptr, cTokenFor_api_5F_scanner) ;
  GALGAS_location * currentLocation = GALGAS_location::constructor_new (ptr->mStartLocation, ptr->mEndLocation, sourceText () COMMA_HERE) ;
  GALGAS_string * value = GALGAS_string::constructor_new (ptr->mLexicalAttribute_att_5F_token COMMA_HERE) ;
  return GALGAS_lstring::constructor_new (value, currentLocation COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//--- START OF USER ZONE 2


//--- END OF USER ZONE 2



