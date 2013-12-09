//---------------------------------------------------------------------------*
//                                                                           *
//  Generic Unsigned Command Line Interface Option                           *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2009, ..., 2010 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
//                                                                           *
//  This library is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU Lesser General Public License as published    *
//  by the Free Software Foundation; either version 2 of the License, or     *
//  (at your option) any later version.                                      *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#include <string.h>
#include <stdio.h>

//---------------------------------------------------------------------------*

#include "command_line_interface/C_UIntCommandLineOption.h"
#include "strings/C_String.h"

//---------------------------------------------------------------------------*

static C_UIntCommandLineOption * gFirst ;
static C_UIntCommandLineOption * gLast ;

//---------------------------------------------------------------------------*

C_UIntCommandLineOption::C_UIntCommandLineOption (const char * inDomainName,
                                                  const char * inIdentifier,
                                                  const char inChar,
                                                  const char * inString,
                                                  const char * inComment,
                                                  const PMUInt32 inDefaultValue) :
C_CommandLineOption (inDomainName, inIdentifier, inChar, inString, inComment),
mNext (NULL),
mValue (inDefaultValue),
mDefaultValue (inDefaultValue) {
  if (NULL == gFirst) {
    gFirst = this ;
  }else{
    gLast->mNext = this ;
  }
  gLast = this ;
}

//---------------------------------------------------------------------------*

void C_UIntCommandLineOption::
setUIntOptionForCommandChar (const char * inCommandCommandLineOptionString,
                             bool & outFound,
                             bool & outCommandLineOptionStringIsValid) {
  const PMUInt32 optionLength = (PMUInt32) (strlen (inCommandCommandLineOptionString) & PMUINT32_MAX) ;
  outCommandLineOptionStringIsValid = (optionLength > 2) && (inCommandCommandLineOptionString [1] == '=') ;
  PMUInt32 optionValue = 0 ;
  for (PMUInt32 i=2 ; (i<optionLength) && outCommandLineOptionStringIsValid ; i++) {
    outCommandLineOptionStringIsValid = (inCommandCommandLineOptionString [i] >= '0') && (inCommandCommandLineOptionString [i] <= '9') ;
    optionValue *= 10 ;
    optionValue += (PMUInt32) (inCommandCommandLineOptionString [i] - '0') ;
  }
  outFound = false ;
  C_UIntCommandLineOption * p = gFirst ;
  if (outCommandLineOptionStringIsValid) {
    while ((p != NULL) && ! outFound) {
      outFound = inCommandCommandLineOptionString [0] == p->mCommandChar ;
      if (outFound) {
        p->mValue = optionValue ;
      }
      p = p->mNext ;
    }
  }
}

//---------------------------------------------------------------------------*

void C_UIntCommandLineOption::
setUIntOptionForCommandString (const char * inCommandCommandLineOptionString,
                               bool & outFound,
                               bool & outCommandLineOptionStringIsValid) {
  const PMUInt32 optionLength = (PMUInt32) (strlen (inCommandCommandLineOptionString) & PMUINT32_MAX) ;
  outCommandLineOptionStringIsValid = optionLength > 2 ;
//--- Find '=' character
  PMUInt32 equalSignIndex = 0 ;
  if (outCommandLineOptionStringIsValid) {
    bool found = false ;
    while ((equalSignIndex < optionLength) && outCommandLineOptionStringIsValid && !found) {
      found = inCommandCommandLineOptionString [equalSignIndex] == '=' ;
      if (! found) {
        equalSignIndex ++ ;
      }
    }
    outCommandLineOptionStringIsValid = found && (equalSignIndex > 0) && (equalSignIndex < (optionLength - 1)) ;
  }
//--- Compute option value
  PMUInt32 optionValue = 0 ;
  for (PMUInt32 i=equalSignIndex+1 ; (i<optionLength) && outCommandLineOptionStringIsValid ; i++) {
    outCommandLineOptionStringIsValid = (inCommandCommandLineOptionString [i] >= '0') && (inCommandCommandLineOptionString [i] <= '9') ;
    optionValue *= 10 ;
    optionValue += inCommandCommandLineOptionString [i] - '0' ;
  }
//--- Search option
  outFound = false ;
  if (outCommandLineOptionStringIsValid) {
    C_UIntCommandLineOption * p = gFirst ;
    while ((p != NULL) && ! outFound) {
      outFound = (strlen (p->mCommandString) == equalSignIndex) && 
                  (strncmp (inCommandCommandLineOptionString, p->mCommandString, equalSignIndex) == 0) ;
      if (outFound) {
        p->mValue = optionValue ;
      }
      p = p->mNext ;
    }
  }
}

//---------------------------------------------------------------------------*

void C_UIntCommandLineOption::printUsageOfUIntOptions (void) {
  C_UIntCommandLineOption * p = gFirst ;
  while (p != NULL) {
    const char c = p->mCommandChar ;
    if (c != '\0') {
      printf (" [-%c=number]", c) ;
    }
    const char * s = p->mCommandString ;
    if (s [0] != 0) {
      printf (" [--%s=number]", s) ;
    }
    p = p->mNext ;
  }
}

//---------------------------------------------------------------------------*

void C_UIntCommandLineOption::printUIntOptions (const PMUInt32 inDisplayLength) {
  C_UIntCommandLineOption * p = gFirst ;
  while (p != NULL) {
    PMUInt32 charCount = 0 ;
    if (p->mCommandChar != '\0') {
      co.setForeColor (kBlueForeColor) ;
      co.setTextAttribute (kBoldTextAttribute) ;
      co << "-" << cStringWithCharacter (p->mCommandChar) << "=number" ;
      co.setTextAttribute (kAllAttributesOff) ;
      charCount += 2 + (PMUInt32) strlen ("=number") ;
      if (p->mCommandString [0] != '\0') {
        co << ", " ;
        charCount += 2 ;
      }
    }
    if (p->mCommandString [0] != '\0') {
      co.setForeColor (kBlueForeColor) ;
      co.setTextAttribute (kBoldTextAttribute) ;
      co << "--" << p->mCommandString << "=number" ;
      co.setTextAttribute (kAllAttributesOff) ;
      charCount += 2 + (PMUInt32) (strlen (p->mCommandString) + strlen ("=number")) ;
    }
    if (charCount > inDisplayLength) {
      co << "\n" ;
      charCount = 0 ;
    }
    for (PMUInt32 i=charCount ; i<=inDisplayLength ; i++) {
      co << " " ;
    }
    co << p->mComment << " (default value: "
       << cStringWithUnsigned (p->mDefaultValue)
       << ")\n" ;
    p = p->mNext ;
  }
}

//---------------------------------------------------------------------------*

void C_UIntCommandLineOption::getUIntOptionNameList (TC_UniqueArray <C_String> & outArray) {
  C_UIntCommandLineOption * p = gFirst ;
  while (p != NULL) {
    outArray.addObject (p->mDomainName) ;
    outArray.addObject (p->mIdentifier) ;
    p = p->mNext ;
  }
}

//---------------------------------------------------------------------------*

utf32 C_UIntCommandLineOption::getUIntOptionInvocationLetter (const C_String & inDomainName,
                                                       const C_String & inIdentifier) {
  utf32 result = TO_UNICODE (0) ;
  C_UIntCommandLineOption * p = gFirst ;
  bool found = false ;
  while ((p != NULL) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    result = TO_UNICODE (p->mCommandChar) ;
    p = p->mNext ;
}
  return result ;
}

//---------------------------------------------------------------------------*

C_String C_UIntCommandLineOption::getUIntOptionInvocationString (const C_String & inDomainName,
                                                       const C_String & inIdentifier) {
  C_String result ;
  C_UIntCommandLineOption * p = gFirst ;
  bool found = false ;
  while ((p != NULL) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    result = p->mCommandString ;
    p = p->mNext ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

C_String C_UIntCommandLineOption::getUIntOptionCommentString (const C_String & inDomainName,
                                                       const C_String & inIdentifier) {
  C_String result ;
  C_UIntCommandLineOption * p = gFirst ;
  bool found = false ;
  while ((p != NULL) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    result = p->mComment ;
    p = p->mNext ;
  }
  return result ;
}

//---------------------------------------------------------------------------*