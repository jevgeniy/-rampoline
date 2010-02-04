//---------------------------------------------------------------------------*
//                                                                           *
//                        File 'template_routines.h'                         *
//                        Generated by version 1.9.9                         *
//                     january 28th, 2010, at 16h31'30"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef template_routines_DEFINED
#define template_routines_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/GGS__header.h"

//---------------------------------------------------------------------------*

// Include imported semantics
#include "template_invocation.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                         Function 'goil_template'                          *
//                                                                           *
//---------------------------------------------------------------------------*

extern const C_galgas_function_descriptor kFunction_descriptor_goil_template ;

//---------------------------------------------------------------------------*

GGS_string function_goil_template (C_Compiler &,
                                const GGS_string ,
                                const GGS_goilTemplateVariableMap  ,
                                const GGS_string  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                        Function 'computeTemplate'                         *
//                                                                           *
//---------------------------------------------------------------------------*

extern const C_galgas_function_descriptor kFunction_descriptor_computeTemplate ;

//---------------------------------------------------------------------------*

GGS_string function_computeTemplate (C_Compiler &,
                                const GGS_string ,
                                const GGS_goilTemplateVariableMap  ,
                                const GGS_string  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*

#endif
