//-----------------------------------------------------------------------------*
//                                                                             *
//  Implementation of routines for handling dynamic allocation checking.     *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 1994, ..., 2010 Pierre Molinaro.                             *
//                                                                             *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
//                                                                             *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes  *
//  ECN, École Centrale de Nantes (France)                                     *
//                                                                             *
//  This library is free software; you can redistribute it and/or modify it    *
//  under the terms of the GNU Lesser General Public License as published      *
//  by the Free Software Foundation; either version 2 of the License, or       *
//  (at your option) any later version.                                        *
//                                                                             *
//  This program is distributed in the hope it will be useful, but WITHOUT     *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or      *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for   *
//  more details.                                                              *
//                                                                             *
//-----------------------------------------------------------------------------*

#ifndef BASIC_ALLOCATION_ROUTINES_DEFINED
#define BASIC_ALLOCATION_ROUTINES_DEFINED

//-----------------------------------------------------------------------------*

void * myAllocRoutine (const size_t inSizeInBytes) ;

void myFreeRoutine (void * inPointer) ;

//-----------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void prologueForNew (void) ;
#endif

//-----------------------------------------------------------------------------*

void displayAllocatedBlockSizeStats (void) ;

//-----------------------------------------------------------------------------*

#endif
