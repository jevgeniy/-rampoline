//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'system_config.h'                           *
//                        Generated by version 1.9.6                         *
//                     december 2nd, 2009, at 21h44'20"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef system_config_DEFINED
#define system_config_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/GGS__header.h"

//---------------------------------------------------------------------------*

// Include imported semantics
#include "goil_template_semantics.h"
#include "goil_types_root.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_systemConfig ;
class cPtr_systemConfig ;

//---------------------------------------------------------------------------*
//                                                                           *
//                     GALGAS class 'GGS_systemConfig'                       *
//                                                                           *
//---------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GGS_systemConfig ;

//---------------------------------------------------------------------------*

class GGS_systemConfig : public AC_galgas_class {
//--- Default constructor
  public : inline GGS_systemConfig (void) :
  AC_galgas_class () {}

//--- Pointer assignment constructor
  public : GGS_systemConfig (const cPtr__AC_galgas_class * inPointer) ;

//--- Object assignment constructor
  public : GGS_systemConfig (cPtr__AC_galgas_class & inObject) ;

//--- castFrom class method (implements cast expression)
  public : static GGS_systemConfig
  castFrom (C_Compiler & inLexique,
             cPtr__AC_galgas_class * inPointer,
             const bool inUseKindOfClass,
             const GGS_location & inErrorLocation
             COMMA_LOCATION_ARGS) ;

//--- 'new' constructor
  public : static GGS_systemConfig constructor_new (C_Compiler & inLexique,
                                const GGS_string& argument_0,
                                const GGS_lstring & argument_1,
                                const GGS_goilTemplateFieldMapList & argument_2
                                COMMA_LOCATION_ARGS) ;

//--- getPtr
  public : inline cPtr_systemConfig * getPtr (void) const {
    return (cPtr_systemConfig *) mPointer ;
  }

//--- 'description' reader
  public : virtual const char * actualTypeName (void) const ;

//--- Readers
  public : GGS_string reader_version (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;
  public : GGS_lstring  reader_compilerKind (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;
  public : GGS_goilTemplateFieldMapList  reader_tasks (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;

//--- Modifiers
  public : void modifier_setVersion (C_Compiler & inLexique, const GGS_string & inValue COMMA_LOCATION_ARGS) ;
  public : void modifier_setCompilerKind (C_Compiler & inLexique, const GGS_lstring  & inValue COMMA_LOCATION_ARGS) ;
  public : void modifier_setTasks (C_Compiler & inLexique, const GGS_goilTemplateFieldMapList  & inValue COMMA_LOCATION_ARGS) ;

//--- operator ()
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : cPtr_systemConfig * operator () (LOCATION_ARGS) const ;
  #else
    public : inline cPtr_systemConfig * operator () (LOCATION_ARGS) const {
      return (cPtr_systemConfig *) mPointer ;
    }
  #endif

//--- Galgas RTTI
AC_galgasClassRunTimeInformation * galgasObjectRunTimeInfo (void) const ;

//--- Introspection
  public : virtual const C_galgas_type_descriptor * typeDescriptor (void) const ;

  public : GGS_object reader_object (void) const ;

  public : static GGS_systemConfig castFromObject (C_Compiler & inLexique,
                                           const GGS_object & inObject,
                                           const GGS_location & inErrorLocation
                                           COMMA_LOCATION_ARGS) ;

} ;

//---------------------------------------------------------------------------*

extern C_galgasRootClassRunTimeInformation gClassInfoFor__systemConfig ;

//---------------------------------------------------------------------------*
//                                                                           *
//                        Routine 'setCompilerKind'                          *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_setCompilerKind (C_Compiler &,
                                const GGS_root_obj  ,
                                GGS_systemConfig  & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       Function 'emptySystemConfig'                        *
//                                                                           *
//---------------------------------------------------------------------------*

extern const C_galgas_function_descriptor kFunction_descriptor_emptySystemConfig ;

//---------------------------------------------------------------------------*

GGS_systemConfig  function_emptySystemConfig (C_Compiler & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                    abstract class 'cPtr_systemConfig'                     *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_systemConfig : public cPtr__AC_galgas_class {
//--- Constructor
  public : cPtr_systemConfig (const GGS_string& ,
                                const GGS_lstring & ,
                                const GGS_goilTemplateFieldMapList & 
                                COMMA_LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~cPtr_systemConfig (void) {}
  #endif

//--- Attributes
  public : GGS_string version ;
  public : GGS_lstring  compilerKind ;
  public : GGS_goilTemplateFieldMapList  tasks ;
//--- Class message
  public : virtual const char * instanceMessage (void) const ;
  public : static const char * _static_message (void) ;

//--- Method for 'description' reader
  public : virtual void
  appendForDescription (C_String & ioString,
                        const PMSInt32 inIndentation) const ;

//--- Comparison
  public : virtual bool
  isEqualToObject (const cPtr__AC_galgas_class * inOperand) const ;

//--- Galgas RTTI
  public : virtual AC_galgasClassRunTimeInformation * galgasRTTI (void) const ;

//--- Make clone
  public : virtual cPtr__AC_galgas_class * makeClone (void) const ;
} ;

//---------------------------------------------------------------------------*

#endif
