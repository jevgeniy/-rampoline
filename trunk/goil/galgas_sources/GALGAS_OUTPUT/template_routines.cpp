//---------------------------------------------------------------------------*
//                                                                           *
//                       File 'template_routines.cpp'                        *
//                    Generated by version version 2.1.4                     *
//                     january 10th, 2011, at 14h31'42"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#include "version_libpm.h"
#if CURRENT_LIBPM_VERSION != 926
  #error "This file has been compiled with a version of GALGAS that uses libpm version 926, different than the current version (CURRENT_LIBPM_VERSION) of libpm"
#endif

//---------------------------------------------------------------------------*

#include "template_routines.h"
#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_CLI_Options.h"

//---------------------------------------------------------------------------*

#include "goil_options.h"
#include "template_grammar.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "template_routines.gSemantics", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//                         Function 'goil_template'                          *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string function_goil_5F_template (const GALGAS_string & constinArgument_prefix,
                                         const GALGAS_goilTemplateVariableMap & constinArgument_cfg,
                                         const GALGAS_string & constinArgument_name,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_string ; // Returned variable
  //-------- @assignmentInstructionForGeneration
  result_string = GALGAS_string::makeEmptyString () ;
  { //-------- @routineCallInstructionForGeneration
  GALGAS_bool joker_354_0 ; // Joker input parameter
  routine_goilTemplateInvocation (GALGAS_lstring::constructor_new (constinArgument_name, inCompiler->here () COMMA_SOURCE_FILE_AT_LINE (12)), constinArgument_prefix, GALGAS_string ("templates"), function_rootTemplatesDirectory (inCompiler COMMA_SOURCE_FILE_AT_LINE (15)), GALGAS_bool (true), constinArgument_cfg, result_string, joker_354_0, inCompiler COMMA_SOURCE_FILE_AT_LINE (11)) ;
  } //-------- @routineCallInstructionForGeneration
//---
  return result_string ;
}


//---------------------------------------------------------------------------*
//  Function introspection                                                   *
//---------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_goil_5F_template [4] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_goilTemplateVariableMap,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_goil_5F_template (C_Compiler * inCompiler,
                                                                 const cObjectArray & inEffectiveParameterArray,
                                                                 const GALGAS_location & inErrorLocation
                                                                 COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE), inCompiler, inErrorLocation COMMA_THERE) ;
  const GALGAS_goilTemplateVariableMap operand1 = GALGAS_goilTemplateVariableMap::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE), inCompiler, inErrorLocation COMMA_THERE) ;
  const GALGAS_string operand2 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE), inCompiler, inErrorLocation COMMA_THERE) ;
  return function_goil_5F_template (operand0, operand1, operand2, inCompiler COMMA_THERE).reader_object (THERE) ;
}

//---------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_goil_5F_template ("goil_template",
                                                                  functionWithGenericHeader_goil_5F_template,
                                                                  & kTypeDescriptor_GALGAS_string,
                                                                  3,
                                                                  functionArgs_goil_5F_template) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                        Function 'computeTemplate'                         *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string function_computeTemplate (const GALGAS_string & constinArgument_prefix,
                                        const GALGAS_goilTemplateVariableMap & constinArgument_cfg,
                                        const GALGAS_string & constinArgument_name,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_string ; // Returned variable
  //-------- @assignmentInstructionForGeneration
  result_string = GALGAS_string::makeEmptyString () ;
  { //-------- @routineCallInstructionForGeneration
  GALGAS_bool joker_656_0 ; // Joker input parameter
  routine_goilTemplateInvocation (GALGAS_lstring::constructor_new (constinArgument_name, inCompiler->here () COMMA_SOURCE_FILE_AT_LINE (30)), constinArgument_prefix, GALGAS_string ("templates"), function_rootTemplatesDirectory (inCompiler COMMA_SOURCE_FILE_AT_LINE (33)), GALGAS_bool (true), constinArgument_cfg, result_string, joker_656_0, inCompiler COMMA_SOURCE_FILE_AT_LINE (29)) ;
  } //-------- @routineCallInstructionForGeneration
//---
  return result_string ;
}


//---------------------------------------------------------------------------*
//  Function introspection                                                   *
//---------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_computeTemplate [4] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_goilTemplateVariableMap,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_computeTemplate (C_Compiler * inCompiler,
                                                                const cObjectArray & inEffectiveParameterArray,
                                                                const GALGAS_location & inErrorLocation
                                                                COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE), inCompiler, inErrorLocation COMMA_THERE) ;
  const GALGAS_goilTemplateVariableMap operand1 = GALGAS_goilTemplateVariableMap::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE), inCompiler, inErrorLocation COMMA_THERE) ;
  const GALGAS_string operand2 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE), inCompiler, inErrorLocation COMMA_THERE) ;
  return function_computeTemplate (operand0, operand1, operand2, inCompiler COMMA_THERE).reader_object (THERE) ;
}

//---------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_computeTemplate ("computeTemplate",
                                                                 functionWithGenericHeader_computeTemplate,
                                                                 & kTypeDescriptor_GALGAS_string,
                                                                 3,
                                                                 functionArgs_computeTemplate) ;

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


