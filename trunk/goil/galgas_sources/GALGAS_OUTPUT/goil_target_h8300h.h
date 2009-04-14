//---------------------------------------------------------------------------*
//                                                                           *
//                       File 'goil_target_h8300h.h'                         *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                     november 20th, 2008, at 11h2'37"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_target_h8300h_DEFINED
#define goil_target_h8300h_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/C_GGS_Object.h"
#include "galgas/GGS_location.h"
#include "galgas/GGS_lbool.h"
#include "galgas/GGS_lchar.h"
#include "galgas/GGS_lstring.h"
#include "galgas/GGS_ldouble.h"
#include "galgas/GGS_luint.h"
#include "galgas/GGS_lsint.h"
#include "galgas/GGS_luint64.h"
#include "galgas/GGS_lsint64.h"
#include "galgas/GGS_stringset.h"
#include "galgas/GGS_binaryset.h"
#include "galgas/GGS_filewrapper.h"
#include "galgas/predefined_types.h"
#include "galgas/AC_galgas_class.h"
#include "galgas/AC_galgas_domain.h"
#include "galgas/AC_galgas_mapindex.h"
#include "galgas/AC_galgas_map.h"
#include "galgas/AC_galgas_listmap.h"
#include "galgas/AC_galgas_list.h"
#include "galgas/AC_galgas_sortedlist.h"

//---------------------------------------------------------------------------*

#include "galgas/C_Lexique.h"

// Include imported semantics
#include "goil_routines.h"
#include "goil_semantic_types.h"
#include "goil_types_counter.h"
#include "goil_types_isr.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                     Routine 'generate_target_h8300h'                      *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_target_h8300h (C_Compiler &,
                                const GGS_lstring  ,
                                const GGS_ident_map  ,
                                const GGS_oil_obj  ,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      Routine 'generate_isr_h8300h'                        *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_isr_h8300h (C_Compiler &,
                                const GGS_isr_map  ,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                    Routine 'generate_counter_h8300h'                      *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_counter_h8300h (C_Compiler &,
                                const GGS_counter_map  ,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*

#endif
