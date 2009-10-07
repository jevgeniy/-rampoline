//---------------------------------------------------------------------------*
//                                                                           *
//                           File 'cfg_syntax.h'                             *
//                        Generated by version 1.9.2                         *
//                      october 7th, 2009, at 10h7'9"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef cfg_syntax_DEFINED
#define cfg_syntax_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/C_GGS_Object.h"
#include "galgas/GGS_location.h"
#include "galgas/GGS_data.h"
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

#include "cfg_lexique.h"

// Include imported semantics
#include "cfg_types.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                   Parser class cfg_syntax declaration                     *
//                                                                           *
//---------------------------------------------------------------------------*

class cfg_syntax {
  public : virtual ~cfg_syntax (void) {}

  protected : virtual void nt_cfg_start_ (cfg_lexique &,
                                GGS_config  &) = 0 ;

  protected : virtual void nt_cfg_attrs_ (cfg_lexique &,
                                GGS_cfg_attrs  &) = 0 ;

  protected : virtual void nt_interrupts_ (cfg_lexique &,
                                GGS_basic_type  &) = 0 ;

  protected : void pr_cfg_start_cfg_syntax_35_16_ (cfg_lexique &,
                                GGS_config  &) ;

  protected : virtual PMSInt16 select_repeat_cfg_syntax_0 (cfg_lexique &) = 0 ;

  protected : void pr_cfg_attrs_cfg_syntax_109_16_ (cfg_lexique &,
                                GGS_cfg_attrs  &) ;

  protected : virtual PMSInt16 select_repeat_cfg_syntax_1 (cfg_lexique &) = 0 ;

  protected : void pr_interrupts_cfg_syntax_121_17_ (cfg_lexique &,
                                GGS_basic_type  &) ;

  protected : virtual PMSInt16 select_repeat_cfg_syntax_2 (cfg_lexique &) = 0 ;

} ;

//---------------------------------------------------------------------------*

#endif
