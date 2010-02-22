//---------------------------------------------------------------------------*
//                                                                           *
//                       File 'template_functions.h'                         *
//                        Generated by version 1.9.9                         *
//                     january 28th, 2010, at 15h58'32"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef template_functions_DEFINED
#define template_functions_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/GGS__header.h"

//---------------------------------------------------------------------------*

// Include imported semantics
#include "system_config.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                           Function 'trueFalse'                            *
//                                                                           *
//---------------------------------------------------------------------------*

extern const C_galgas_function_descriptor kFunction_descriptor_trueFalse ;

//---------------------------------------------------------------------------*

GGS_string function_trueFalse (C_Compiler &,
                                const GGS_bool  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                             Function 'yesNo'                              *
//                                                                           *
//---------------------------------------------------------------------------*

extern const C_galgas_function_descriptor kFunction_descriptor_yesNo ;

//---------------------------------------------------------------------------*

GGS_string function_yesNo (C_Compiler &,
                                const GGS_bool  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                           Function 'TRUEFALSE'                            *
//                                                                           *
//---------------------------------------------------------------------------*

extern const C_galgas_function_descriptor kFunction_descriptor_TRUEFALSE ;

//---------------------------------------------------------------------------*

GGS_string function_TRUEFALSE (C_Compiler &,
                                const GGS_bool  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*

#endif