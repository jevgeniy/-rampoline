//---------------------------------------------------------------------------*
//                                                                           *
//                            File 'cfg_types.h'                             *
//                    Generated by version version 2.1.4                     *
//                     january 10th, 2011, at 14h35'28"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef cfg_types_ENTITIES_DEFINED
#define cfg_types_ENTITIES_DEFINED

//---------------------------------------------------------------------------*

#include "galgas2/predefined-types.h"

//---------------------------------------------------------------------------*

#include "goil_basic_types.h"

//---------------------------------------------------------------------------*

class GALGAS_config ;
class GALGAS_cfg_5F_attrs ;
class GALGAS_attrs ;
class GALGAS_interrupts ;

//---------------------------------------------------------------------------*
//                                                                           *
//                                @config map                                *
//                                                                           *
//---------------------------------------------------------------------------*

class cMapElement_config ;

//---------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_config_get ;

//---------------------------------------------------------------------------*

class GALGAS_config : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_config (void) ;

//--------------------------------- Handle copy
  public : GALGAS_config (const GALGAS_config & inSource) ;
  public : GALGAS_config & operator = (const GALGAS_config & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_config extractObject (const GALGAS_object & inObject,
                                               C_Compiler * inCompiler,
                                               const GALGAS_location & inErrorLocation
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_config constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_config constructor_mapWithMapToOverride (const GALGAS_config & inOperand0
                                                                  COMMA_LOCATION_ARGS) ;


//--------------------------------- Modifiers
  public : VIRTUAL_IN_DEBUG void modifier_del (GALGAS_lstring constinArgument0,
                                               GALGAS_basic_5F_type & outArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_put (GALGAS_lstring constinArgument0,
                                               GALGAS_basic_5F_type constinArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setValueForKey (GALGAS_basic_5F_type constinArgument0,
                                                          GALGAS_string constinArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_get (GALGAS_lstring constinArgument0,
                                             GALGAS_basic_5F_type & outArgument1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Readers
  public : VIRTUAL_IN_DEBUG GALGAS_config reader_overriddenMap (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_basic_5F_type reader_valueForKey (const GALGAS_string & constinOperand0,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- 'with' accessors
  public : VIRTUAL_IN_DEBUG cMapElement_config * readWriteAccessForWithInstruction_get (C_Compiler * inCompiler,
                                                                                        const GALGAS_lstring & inKey
                                                                                        COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG cMapElement_config * readWriteAccessForWithInstruction_hasKey (C_Compiler * inCompiler,
                                                                                           const GALGAS_string & inKey
                                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_config ;
 
} ; // End of GALGAS_config class

//---------------------------------------------------------------------------*
//   Enumerator declaration                                                  *
//---------------------------------------------------------------------------*

class cEnumerator_config : public cGenericAbstractEnumerator {
  public : cEnumerator_config (const GALGAS_config & inEnumeratedObject,
                               const bool inAscending) ;

//--- Current element access
  public : GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : GALGAS_basic_5F_type current_value (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_config ;

//--------------------------------- 'with' accessors
cCollectionElement * readWriteAccessForWithInstruction_get (C_Compiler * inCompiler,
                                                            GALGAS_config & ioMap,
                                                            GALGAS_lstring & inKey
                                                            COMMA_LOCATION_ARGS) ;

cCollectionElement * readWriteAccessForWithInstruction_hasKey (C_Compiler * inCompiler,
                                                               GALGAS_config & ioMap,
                                                               GALGAS_string & inKey
                                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                              @cfg_attrs map                               *
//                                                                           *
//---------------------------------------------------------------------------*

class cMapElement_cfg_5F_attrs ;

//---------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_cfg_5F_attrs_get ;

//---------------------------------------------------------------------------*

class GALGAS_cfg_5F_attrs : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_cfg_5F_attrs (void) ;

//--------------------------------- Handle copy
  public : GALGAS_cfg_5F_attrs (const GALGAS_cfg_5F_attrs & inSource) ;
  public : GALGAS_cfg_5F_attrs & operator = (const GALGAS_cfg_5F_attrs & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_cfg_5F_attrs extractObject (const GALGAS_object & inObject,
                                                     C_Compiler * inCompiler,
                                                     const GALGAS_location & inErrorLocation
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_cfg_5F_attrs constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_cfg_5F_attrs constructor_mapWithMapToOverride (const GALGAS_cfg_5F_attrs & inOperand0
                                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Modifiers
  public : VIRTUAL_IN_DEBUG void modifier_del (GALGAS_lstring constinArgument0,
                                               GALGAS_lstring & outArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_put (GALGAS_lstring constinArgument0,
                                               GALGAS_lstring constinArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setTpl_5F_attrForKey (GALGAS_lstring constinArgument0,
                                                                GALGAS_string constinArgument1,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_get (GALGAS_lstring constinArgument0,
                                             GALGAS_lstring & outArgument1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Readers
  public : VIRTUAL_IN_DEBUG GALGAS_cfg_5F_attrs reader_overriddenMap (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_lstring reader_tpl_5F_attrForKey (const GALGAS_string & constinOperand0,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- 'with' accessors
  public : VIRTUAL_IN_DEBUG cMapElement_cfg_5F_attrs * readWriteAccessForWithInstruction_get (C_Compiler * inCompiler,
                                                                                              const GALGAS_lstring & inKey
                                                                                              COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG cMapElement_cfg_5F_attrs * readWriteAccessForWithInstruction_hasKey (C_Compiler * inCompiler,
                                                                                                 const GALGAS_string & inKey
                                                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_cfg_5F_attrs ;
 
} ; // End of GALGAS_cfg_5F_attrs class

//---------------------------------------------------------------------------*
//   Enumerator declaration                                                  *
//---------------------------------------------------------------------------*

class cEnumerator_cfg_5F_attrs : public cGenericAbstractEnumerator {
  public : cEnumerator_cfg_5F_attrs (const GALGAS_cfg_5F_attrs & inEnumeratedObject,
                                     const bool inAscending) ;

//--- Current element access
  public : GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : GALGAS_lstring current_tpl_5F_attr (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_cfg_5F_attrs ;

//--------------------------------- 'with' accessors
cCollectionElement * readWriteAccessForWithInstruction_get (C_Compiler * inCompiler,
                                                            GALGAS_cfg_5F_attrs & ioMap,
                                                            GALGAS_lstring & inKey
                                                            COMMA_LOCATION_ARGS) ;

cCollectionElement * readWriteAccessForWithInstruction_hasKey (C_Compiler * inCompiler,
                                                               GALGAS_cfg_5F_attrs & ioMap,
                                                               GALGAS_string & inKey
                                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                               @attrs class                                *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_attrs ;

//---------------------------------------------------------------------------*

class GALGAS_attrs : public GALGAS_basic_5F_type {
//--- Constructor
  public : GALGAS_attrs (void) ;

//---
  public : inline const cPtr_attrs * ptr (void) const { return (const cPtr_attrs *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_attrs (const cPtr_attrs * inSourcePtr) ;

//--- Insulate
  private : VIRTUAL_IN_DEBUG void insulate (LOCATION_ARGS) ;


//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_attrs extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler,
                                              const GALGAS_location & inErrorLocation
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_attrs constructor_new (const GALGAS_location & inOperand0,
                                                const GALGAS_cfg_5F_attrs & inOperand1
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : enumComparisonResult objectCompare (const GALGAS_attrs & inOperand) const ;

//--------------------------------- Modifiers

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Readers
  public : VIRTUAL_IN_DEBUG GALGAS_cfg_5F_attrs reader_attrs (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_attrs class


//---------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_attrs ;

//---------------------------------------------------------------------------*
//                                                                           *
//                             @interrupts class                             *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_interrupts ;

//---------------------------------------------------------------------------*

class GALGAS_interrupts : public GALGAS_basic_5F_type {
//--- Constructor
  public : GALGAS_interrupts (void) ;

//---
  public : inline const cPtr_interrupts * ptr (void) const { return (const cPtr_interrupts *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_interrupts (const cPtr_interrupts * inSourcePtr) ;

//--- Insulate
  private : VIRTUAL_IN_DEBUG void insulate (LOCATION_ARGS) ;


//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_interrupts extractObject (const GALGAS_object & inObject,
                                                   C_Compiler * inCompiler,
                                                   const GALGAS_location & inErrorLocation
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_interrupts constructor_new (const GALGAS_location & inOperand0,
                                                     const GALGAS_luint_36__34_ & inOperand1,
                                                     const GALGAS_ident_5F_map & inOperand2
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : enumComparisonResult objectCompare (const GALGAS_interrupts & inOperand) const ;

//--------------------------------- Modifiers

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Readers
  public : VIRTUAL_IN_DEBUG GALGAS_luint_36__34_ reader_it_5F_count (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_ident_5F_map reader_it_5F_sources (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_interrupts class


//---------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_interrupts ;

//---------------------------------------------------------------------------*
//                                                                           *
//                    Class for element of '@config' map                     *
//                                                                           *
//---------------------------------------------------------------------------*

class cMapElement_config : public cMapElement {
//--- Map attributes
  public : GALGAS_basic_5F_type mAttribute_value ;

//--- Constructor
  public : cMapElement_config (const GALGAS_lstring & inKey,
                               const GALGAS_basic_5F_type & in_value
                               COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual enumComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const PMSInt32 inIndentation) const ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                   Class for element of '@cfg_attrs' map                   *
//                                                                           *
//---------------------------------------------------------------------------*

class cMapElement_cfg_5F_attrs : public cMapElement {
//--- Map attributes
  public : GALGAS_lstring mAttribute_tpl_5F_attr ;

//--- Constructor
  public : cMapElement_cfg_5F_attrs (const GALGAS_lstring & inKey,
                                     const GALGAS_lstring & in_tpl_5F_attr
                                     COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual enumComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const PMSInt32 inIndentation) const ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      Pointer class for @attrs class                       *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_attrs : public cPtr_basic_5F_type {

//--- Attributes
  public : GALGAS_cfg_5F_attrs mAttribute_attrs ;

//--- Constructor
  public : cPtr_attrs (const GALGAS_location & in_location,
                       const GALGAS_cfg_5F_attrs & in_attrs
                       COMMA_LOCATION_ARGS) ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const PMSInt32 inIndentation) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                    Pointer class for @interrupts class                    *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_interrupts : public cPtr_basic_5F_type {

//--- Attributes
  public : GALGAS_luint_36__34_ mAttribute_it_5F_count ;
  public : GALGAS_ident_5F_map mAttribute_it_5F_sources ;

//--- Constructor
  public : cPtr_interrupts (const GALGAS_location & in_location,
                            const GALGAS_luint_36__34_ & in_it_5F_count,
                            const GALGAS_ident_5F_map & in_it_5F_sources
                            COMMA_LOCATION_ARGS) ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const PMSInt32 inIndentation) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

#endif
