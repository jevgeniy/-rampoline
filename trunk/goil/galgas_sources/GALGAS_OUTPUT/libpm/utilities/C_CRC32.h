//---------------------------------------------------------------------------*
//                                                                           *
//  'C_CRC32' : a class for computing CRC32                                  *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1997 Pierre Molinaro.                                      *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes                                            *
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

#ifndef CLASS_CRC32_DEFINED
#define CLASS_CRC32_DEFINED

//---------------------------------------------------------------------------*

#include "M_machine.h"

//---------------------------------------------------------------------------*

class C_CRC32 {
//--- Valeur initiale de la somme
  public : static PMUInt32 getInitialValue (void) {
     return 0xCAFECAFEUL ;
  }

  public : static void addCharToChecksum (const char car, PMUInt32 & somme) ;
  public : static void addLongToChecksum (const PMSInt32 v, PMUInt32 & somme) ;
  public : static void addUnsignedLongToChecksum (const PMUInt32 v, PMUInt32 & somme) ;
  public : static void addShortToChecksum (const PMSInt16 v, PMUInt32 & somme) ;
  public : static void addStringToChecksum (const char * chaine, PMUInt32 & somme) ;
} ;

//---------------------------------------------------------------------------*

#endif
