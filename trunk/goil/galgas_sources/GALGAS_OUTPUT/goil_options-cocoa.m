//---------------------------------------------------------------------------*
//                                                                           *
//                       File 'goil_options-cocoa.m'                         *
//                        Generated by version 1.9.4                         *
//                    november 12th, 2009, at 11h40'57"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#import "goil_options-cocoa.h"
#import "OC_GGS_CommandLineOption.h"

//---------------------------------------------------------------------------*

void enterOptionsFor_goil_5F_options (NSMutableArray * ioBoolOptionArray,
                                                       NSMutableArray * ioUIntOptionArray,
                                                       NSMutableArray * ioStringOptionArray) {
  OC_GGS_CommandLineOption * option ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"goil_options"
    identifier:@"autosar_on"
    commandChar:97
    commandString:@"autosar"
    comment:@"Parse Autosar objects and attributes"
  ] ;
  [ioBoolOptionArray addObject:option] ;
  [option release] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"goil_options"
    identifier:@"generate_makefile"
    commandChar:103
    commandString:@"generate-makefile"
    comment:@"Generate a Makefile from OS extra attributes"
  ] ;
  [ioBoolOptionArray addObject:option] ;
  [option release] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"goil_options"
    identifier:@"posix_it"
    commandChar:105
    commandString:@"interrupts"
    comment:@"Use the new interrupt scheme introduced for viper 2"
  ] ;
  [ioBoolOptionArray addObject:option] ;
  [option release] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"goil_options"
    identifier:@"run_goil_template_test"
    commandChar:0
    commandString:@"run-goil-template-test"
    comment:@"Runs and displays a GOIL template for template testing purpose"
  ] ;
  [ioBoolOptionArray addObject:option] ;
  [option release] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"goil_options"
    identifier:@"goil_template_dir"
    commandChar:0
    commandString:@"goil-templates"
    comment:@"Specifies template directory (used by goil for code generation, for new-style templates)"
  ] ;
  [ioStringOptionArray addObject:option] ;
  [option release] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"goil_options"
    identifier:@"project_dir"
    commandChar:112
    commandString:@"project"
    comment:@"Specifies project directory (by default, the project directory is the name of the oil file, without the .oil extension)"
  ] ;
  [ioStringOptionArray addObject:option] ;
  [option release] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"goil_options"
    identifier:@"target_platform"
    commandChar:116
    commandString:@"target"
    comment:@"Specifies target platform (avr, h8300h, libpcl, posix, posix_vp2, v850e, arm, c166, hcs12 or ppc)"
  ] ;
  [ioStringOptionArray addObject:option] ;
  [option release] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"goil_options"
    identifier:@"template_dir"
    commandChar:0
    commandString:@"templates"
    comment:@"Specifies template directory (used by goil for code generation)"
  ] ;
  [ioStringOptionArray addObject:option] ;
  [option release] ;
}

//---------------------------------------------------------------------------*

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2



