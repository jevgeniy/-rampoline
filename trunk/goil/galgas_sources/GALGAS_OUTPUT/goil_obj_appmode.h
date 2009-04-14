//---------------------------------------------------------------------------*
//                                                                           *
//                        File 'goil_obj_appmode.h'                          *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                     november 20th, 2008, at 11h2'5"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_obj_appmode_DEFINED
#define goil_obj_appmode_DEFINED

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

#include "goil_lexique.h"

// Include imported semantics
#include "goil_options.h"
#include "goil_semantics.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                Parser class goil_obj_appmode declaration                  *
//                                                                           *
//---------------------------------------------------------------------------*

class goil_obj_appmode {
  public : virtual ~goil_obj_appmode (void) {}

  protected : virtual void nt_appmode_ (goil_lexique &) = 0 ;

  protected : virtual void nt_description_ (goil_lexique &,
                                GGS_lstring  &) = 0 ;

  protected : virtual void nt_free_field_ (goil_lexique &,
                                GGS_ident_map  &) = 0 ;

  protected : void pr_appmode_goil_obj_appmode_33_14_ (goil_lexique &) ;

  protected : virtual sint16 select_repeat_goil_obj_appmode_0 (goil_lexique &) = 0 ;

} ;

//---------------------------------------------------------------------------*

#endif
