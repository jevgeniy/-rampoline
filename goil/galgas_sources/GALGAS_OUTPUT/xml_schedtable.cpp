//---------------------------------------------------------------------------*
//                                                                           *
//                        File 'xml_schedtable.cpp'                          *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                      june 12th, 2009, at 14h44'49"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 502
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "xml_schedtable.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "xml_schedtable.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//          Implementation of routine "parse_schedtable_autostart"           *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_parse_schedtable_autostart (C_Compiler & inLexique,
                                const GGS_xmlNodeList   var_cas_cont_elems,
                                const GGS_lstring   var_cas_name,
                                const GGS_location   /* var_cas_autoloc */,
                                GGS_scheduletable_obj  & var_cas_st COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_parse_schedtable_autostart at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_xmlNode  var_cas_node ;
  var_cas_node = function_elem_named (inLexique, var_cas_cont_elems, GGS_string ("REFERENCE-VALUES") COMMA_SOURCE_FILE_AT_LINE (37)) ;
  if ((function_is_not_void (inLexique, var_cas_node COMMA_SOURCE_FILE_AT_LINE (38))).isBuiltAndTrue ()) {
    GGS_xmlNodeList  var_cas_subs ;
    var_cas_subs = var_cas_node.reader_nodeList (inLexique COMMA_SOURCE_FILE_AT_LINE (39)) ;
    GGS_stringset  var_cas_ams ;
    var_cas_ams = GGS_stringset ::constructor_emptySet () ;
    GGS_lstring  var_cas_auto_type ;
    var_cas_auto_type = function_empty_lstring (inLexique COMMA_SOURCE_FILE_AT_LINE (41)) ;
    GGS_basic_type  var_cas_auto_val_abs ;
    var_cas_auto_val_abs = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
    GGS_basic_type  var_cas_auto_val_rel ;
    var_cas_auto_val_rel = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
    {
      GGS_xmlNodeList::cEnumerator enumerator_1087 (var_cas_subs, true) ;
      const GGS_xmlNodeList::cElement * operand_1087 = NULL ;
      while (((operand_1087 = enumerator_1087.nextObject ()))) {
        macroValidPointer (operand_1087) ;
        if ((function_is_param (inLexique, operand_1087->node, GGS_string ("OsScheduleTableAutostartType") COMMA_SOURCE_FILE_AT_LINE (45))).isBuiltAndTrue ()) {
          ::routine_set_lstring_if_empty (inLexique,  var_cas_auto_type,  function_lstring_param (inLexique, operand_1087->node COMMA_SOURCE_FILE_AT_LINE (46)),  GGS_string ("OsScheduleTableAutostartType") COMMA_SOURCE_FILE_AT_LINE (46)) ;
        }else if ((function_is_param (inLexique, operand_1087->node, GGS_string ("OsScheduleTableAbsValue") COMMA_SOURCE_FILE_AT_LINE (47))).isBuiltAndTrue ()) {
          ::routine_set_uint64 (inLexique,  var_cas_auto_val_abs,  function_luint64_param (inLexique, operand_1087->node COMMA_SOURCE_FILE_AT_LINE (48)),  GGS_string ("OsScheduleTableAbsValue") COMMA_SOURCE_FILE_AT_LINE (48)) ;
        }
        GGS_string var_cas_am ;
        var_cas_am = function_ref_text (inLexique, operand_1087->node COMMA_SOURCE_FILE_AT_LINE (50)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (50)).reader_lastPathComponent (inLexique COMMA_SOURCE_FILE_AT_LINE (50)) ;
        var_cas_ams._addAssign_operation (var_cas_am) ;
      }
    }
    GGS_autostart_obj  var_cas_auto_obj ;
    var_cas_auto_obj = var_cas_st.reader_autostart (inLexique COMMA_SOURCE_FILE_AT_LINE (53)) ;
    if (((var_cas_auto_type.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (54))).operator_isEqual (GGS_string ("RELATIVE"))).isBuiltAndTrue ()) {
      { const GGS_basic_type _var_1832 = var_cas_auto_val_rel ; // CAST instruction
        if (_var_1832.getPtr () != NULL) {
          macroValidPointer (_var_1832.getPtr ()) ;
          if (typeid (cPtr_uint64_class) == typeid (* (_var_1832.getPtr ()))) {
            const GGS_uint64_class var_cas_av (_var_1832.getPtr ()) ;
            var_cas_auto_obj = GGS_sd_autostart_relative ::constructor_new (inLexique, var_cas_auto_type.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (57)), var_cas_ams, function_luint64_value (inLexique, var_cas_av COMMA_SOURCE_FILE_AT_LINE (57)) COMMA_HERE) ;
          }else{
            var_cas_auto_type.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Relative value expected") COMMA_SOURCE_FILE_AT_LINE (60)) ;
          }
        }
      }
    }else if (((var_cas_auto_type.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (61))).operator_isEqual (GGS_string ("ABSOLUTE"))).isBuiltAndTrue ()) {
      { const GGS_basic_type _var_2115 = var_cas_auto_val_abs ; // CAST instruction
        if (_var_2115.getPtr () != NULL) {
          macroValidPointer (_var_2115.getPtr ()) ;
          if (typeid (cPtr_uint64_class) == typeid (* (_var_2115.getPtr ()))) {
            const GGS_uint64_class var_cas_av (_var_2115.getPtr ()) ;
            var_cas_auto_obj = GGS_sd_autostart_absolute ::constructor_new (inLexique, var_cas_auto_type.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (64)), var_cas_ams, function_luint64_value (inLexique, var_cas_av COMMA_SOURCE_FILE_AT_LINE (64)) COMMA_HERE) ;
          }else{
            var_cas_auto_type.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Absolute value expected") COMMA_SOURCE_FILE_AT_LINE (67)) ;
          }
        }
      }
    }else if (((var_cas_auto_type.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (68))).operator_isEqual (GGS_string ("SYNCHRON"))).isBuiltAndTrue ()) {
      var_cas_auto_obj = GGS_sd_autostart_synchron ::constructor_new (inLexique, var_cas_auto_type.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (69)), var_cas_ams COMMA_HERE) ;
    }
    var_cas_st.modifier_setAutostart (inLexique, var_cas_auto_obj COMMA_SOURCE_FILE_AT_LINE (71)) ;
  }else{
    var_cas_name.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("No REFERENCE-VALUES found in OsTaskAutostart") COMMA_SOURCE_FILE_AT_LINE (74)) ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_parse_schedtable_autostart\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//           Implementation of routine "parse_st_taskactivation"             *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_parse_st_taskactivation (C_Compiler &,
                                const GGS_xmlNodeList   /* var_cas_cont_elems */,
                                const GGS_lstring   /* var_cas_name */,
                                const GGS_location   /* var_cas_loc */,
                                GGS_scheduletable_obj  & /* var_cas_st */ COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_parse_st_taskactivation at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_parse_st_taskactivation\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//            Implementation of routine "parse_st_eventsetting"              *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_parse_st_eventsetting (C_Compiler &,
                                const GGS_xmlNodeList   /* var_cas_cont_elems */,
                                const GGS_lstring   /* var_cas_name */,
                                const GGS_location   /* var_cas_loc */,
                                GGS_scheduletable_obj  & /* var_cas_st */ COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_parse_st_eventsetting at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_parse_st_eventsetting\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//           Implementation of routine "parse_st_adjustexppoint"             *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_parse_st_adjustexppoint (C_Compiler &,
                                const GGS_xmlNodeList   /* var_cas_cont_elems */,
                                const GGS_lstring   /* var_cas_name */,
                                const GGS_location   /* var_cas_loc */,
                                GGS_scheduletable_obj  & /* var_cas_st */ COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_parse_st_adjustexppoint at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_parse_st_adjustexppoint\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//     Implementation of routine "parse_schedtable_expiry_subcontainer"      *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_parse_schedtable_expiry_subcontainer (C_Compiler & inLexique,
                                const GGS_xmlNodeList   var_cas_cont_elems,
                                const GGS_lstring   var_cas_name,
                                GGS_scheduletable_obj  & var_cas_st COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_parse_schedtable_expiry_subcontainer at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  {
    GGS_xmlNodeList::cEnumerator enumerator_3030 (var_cas_cont_elems, true) ;
    const GGS_xmlNodeList::cElement * operand_3030 = NULL ;
    while (((operand_3030 = enumerator_3030.nextObject ()))) {
      macroValidPointer (operand_3030) ;
      GGS_lstring  var_cas_elem_name ;
      var_cas_elem_name = function_long_name (inLexique, operand_3030->node COMMA_SOURCE_FILE_AT_LINE (107)) ;
      if (((var_cas_elem_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (108))).operator_isEqual (GGS_string ("OsScheduleTableTaskActivation"))).isBuiltAndTrue ()) {
        ::routine_parse_st_taskactivation (inLexique,  var_cas_cont_elems,  var_cas_name,  var_cas_elem_name.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (109)),  var_cas_st COMMA_SOURCE_FILE_AT_LINE (109)) ;
      }else if (((var_cas_elem_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (110))).operator_isEqual (GGS_string ("OsScheduleTableEventSetting"))).isBuiltAndTrue ()) {
        ::routine_parse_st_eventsetting (inLexique,  var_cas_cont_elems,  var_cas_name,  var_cas_elem_name.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (111)),  var_cas_st COMMA_SOURCE_FILE_AT_LINE (111)) ;
      }else if (((var_cas_elem_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (112))).operator_isEqual (GGS_string ("OsScheduleTblAdjustableExpPoint"))).isBuiltAndTrue ()) {
        ::routine_parse_st_adjustexppoint (inLexique,  var_cas_cont_elems,  var_cas_name,  var_cas_elem_name.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (113)),  var_cas_st COMMA_SOURCE_FILE_AT_LINE (113)) ;
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_parse_schedtable_expiry_subcontainer\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//           Implementation of routine "parse_schedtable_expiry"             *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_parse_schedtable_expiry (C_Compiler & inLexique,
                                const GGS_xmlNodeList   var_cas_cont_elems,
                                const GGS_lstring   var_cas_name,
                                const GGS_location   /* var_cas_expiryloc */,
                                GGS_scheduletable_obj  & var_cas_st COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_parse_schedtable_expiry at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_xmlNode  var_cas_node ;
  var_cas_node = function_elem_named (inLexique, var_cas_cont_elems, GGS_string ("PARAMETER-VALUES") COMMA_SOURCE_FILE_AT_LINE (124)) ;
  if ((function_is_not_void (inLexique, var_cas_node COMMA_SOURCE_FILE_AT_LINE (125))).isBuiltAndTrue ()) {
    GGS_xmlNodeList  var_cas_subs ;
    var_cas_subs = var_cas_node.reader_nodeList (inLexique COMMA_SOURCE_FILE_AT_LINE (126)) ;
    GGS_basic_type  var_cas_offset ;
    var_cas_offset = function_void_class (inLexique COMMA_SOURCE_FILE_AT_LINE (127)) ;
    {
      GGS_xmlNodeList::cEnumerator enumerator_3901 (var_cas_subs, true) ;
      const GGS_xmlNodeList::cElement * operand_3901 = NULL ;
      while (((operand_3901 = enumerator_3901.nextObject ()))) {
        macroValidPointer (operand_3901) ;
        if ((function_is_param (inLexique, operand_3901->node, GGS_string ("OsScheduleTblExpPointOffset") COMMA_SOURCE_FILE_AT_LINE (129))).isBuiltAndTrue ()) {
          inLexique.printMessage (((GGS_string (" OFFSET = ")).operator_concat (function_luint64_param (inLexique, operand_3901->node COMMA_SOURCE_FILE_AT_LINE (130)).reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (130)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (130)))).operator_concat (GGS_string ("\n")) COMMA_SOURCE_FILE_AT_LINE (130)) ;
          ::routine_set_uint64 (inLexique,  var_cas_offset,  function_luint64_param (inLexique, operand_3901->node COMMA_SOURCE_FILE_AT_LINE (131)),  GGS_string ("OsScheduleTblExpPointOffset") COMMA_SOURCE_FILE_AT_LINE (131)) ;
        }
      }
    }
    var_cas_node = function_elem_named (inLexique, var_cas_cont_elems, GGS_string ("SUB-CONTAINERS") COMMA_SOURCE_FILE_AT_LINE (134)) ;
    GGS_xmlNodeList  var_cas_nl ;
    var_cas_nl = var_cas_node.reader_nodeList (inLexique COMMA_SOURCE_FILE_AT_LINE (135)) ;
    {
      GGS_xmlNodeList::cEnumerator enumerator_4263 (var_cas_nl, true) ;
      const GGS_xmlNodeList::cElement * operand_4263 = NULL ;
      while (((operand_4263 = enumerator_4263.nextObject ()))) {
        macroValidPointer (operand_4263) ;
        ::routine_parse_schedtable_expiry_subcontainer (inLexique,  operand_4263->node.reader_nodeList (inLexique COMMA_SOURCE_FILE_AT_LINE (137)),  var_cas_name,  var_cas_st COMMA_SOURCE_FILE_AT_LINE (137)) ;
      }
    }
  }else{
    var_cas_name.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("No PARAMETER-VALUES found in OsScheduleTableExpiryPoint") COMMA_SOURCE_FILE_AT_LINE (141)) ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_parse_schedtable_expiry\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//            Implementation of routine "parse_schedtable_sync"              *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_parse_schedtable_sync (C_Compiler &,
                                const GGS_xmlNodeList   /* var_cas_cont_elems */,
                                const GGS_lstring   /* var_cas_name */,
                                const GGS_location   /* var_cas_syncloc */,
                                GGS_scheduletable_obj  & /* var_cas_st */ COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_parse_schedtable_sync at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_parse_schedtable_sync\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//        Implementation of routine "parse_schedtable_subcontainer"          *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_parse_schedtable_subcontainer (C_Compiler & inLexique,
                                const GGS_xmlNodeList   var_cas_cont_elems,
                                const GGS_lstring   var_cas_name,
                                GGS_scheduletable_obj  & var_cas_st COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_parse_schedtable_subcontainer at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  {
    GGS_xmlNodeList::cEnumerator enumerator_4778 (var_cas_cont_elems, true) ;
    const GGS_xmlNodeList::cElement * operand_4778 = NULL ;
    while (((operand_4778 = enumerator_4778.nextObject ()))) {
      macroValidPointer (operand_4778) ;
      GGS_lstring  var_cas_elem_name ;
      var_cas_elem_name = function_long_name (inLexique, operand_4778->node COMMA_SOURCE_FILE_AT_LINE (158)) ;
      if (((var_cas_elem_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (159))).operator_isEqual (GGS_string ("OsScheduleTableAutostart"))).isBuiltAndTrue ()) {
        inLexique.printMessage (GGS_string ("ScheduleTable Autostart trouve\n") COMMA_SOURCE_FILE_AT_LINE (160)) ;
        ::routine_parse_schedtable_autostart (inLexique,  var_cas_cont_elems,  var_cas_name,  var_cas_elem_name.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (161)),  var_cas_st COMMA_SOURCE_FILE_AT_LINE (161)) ;
      }else if (((var_cas_elem_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (162))).operator_isEqual (GGS_string ("OsScheduleTableExpiryPoint"))).isBuiltAndTrue ()) {
        inLexique.printMessage (GGS_string ("OsScheduleTableExpiryPoint trouve\n") COMMA_SOURCE_FILE_AT_LINE (163)) ;
        ::routine_parse_schedtable_expiry (inLexique,  var_cas_cont_elems,  var_cas_name,  var_cas_elem_name.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (164)),  var_cas_st COMMA_SOURCE_FILE_AT_LINE (164)) ;
      }else if (((var_cas_elem_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (165))).operator_isEqual (GGS_string ("OsScheduleTableSync"))).isBuiltAndTrue ()) {
        inLexique.printMessage (GGS_string ("OsScheduleTableSync trouve\n") COMMA_SOURCE_FILE_AT_LINE (166)) ;
        ::routine_parse_schedtable_sync (inLexique,  var_cas_cont_elems,  var_cas_name,  var_cas_elem_name.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (167)),  var_cas_st COMMA_SOURCE_FILE_AT_LINE (167)) ;
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_parse_schedtable_subcontainer\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//               Implementation of routine "parse_schedtable"                *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_parse_schedtable (C_Compiler & inLexique,
                                const GGS_lstring   var_cas_name,
                                const GGS_xmlNodeList   var_cas_cont_elems,
                                GGS_root_obj  & var_cas_cpu COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_parse_schedtable at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_scheduletable_obj  var_cas_st ;
  var_cas_st = function_default_scheduletable_obj (inLexique COMMA_SOURCE_FILE_AT_LINE (177)) ;
  GGS_xmlNode  var_cas_node ;
  var_cas_node = function_elem_named (inLexique, var_cas_cont_elems, GGS_string ("PARAMETER-VALUES") COMMA_SOURCE_FILE_AT_LINE (179)) ;
  if ((function_is_not_void (inLexique, var_cas_node COMMA_SOURCE_FILE_AT_LINE (180))).isBuiltAndTrue ()) {
    GGS_xmlNodeList  var_cas_params ;
    var_cas_params = var_cas_node.reader_nodeList (inLexique COMMA_SOURCE_FILE_AT_LINE (181)) ;
    {
      GGS_xmlNodeList::cEnumerator enumerator_5771 (var_cas_params, true) ;
      const GGS_xmlNodeList::cElement * operand_5771 = NULL ;
      while (((operand_5771 = enumerator_5771.nextObject ()))) {
        macroValidPointer (operand_5771) ;
        if ((function_is_param (inLexique, operand_5771->node, GGS_string ("OsScheduleTableRepeating") COMMA_SOURCE_FILE_AT_LINE (183))).isBuiltAndTrue ()) {
          var_cas_st.modifier_setPeriodic (inLexique, function_bool_class_param (inLexique, operand_5771->node COMMA_SOURCE_FILE_AT_LINE (184)) COMMA_SOURCE_FILE_AT_LINE (184)) ;
        }else if ((function_is_param (inLexique, operand_5771->node, GGS_string ("OsSchTblAccessingApplication") COMMA_SOURCE_FILE_AT_LINE (185))).isBuiltAndTrue ()) {
          GGS_lstringlist  var_cas_acc_apps ;
          var_cas_acc_apps = var_cas_st.reader_acc_apps (inLexique COMMA_SOURCE_FILE_AT_LINE (186)) ;
          var_cas_acc_apps._addAssign_operation (function_value_text (inLexique, operand_5771->node COMMA_SOURCE_FILE_AT_LINE (187))) ;
          var_cas_st.modifier_setAcc_apps (inLexique, var_cas_acc_apps COMMA_SOURCE_FILE_AT_LINE (188)) ;
          inLexique.printMessage (C_String ("LOGGING acc_apps: ") + var_cas_acc_apps.reader_description (inLexique COMMA_HERE).string () + "\n" COMMA_SOURCE_FILE_AT_LINE (189)) ;
        }else if ((function_is_param (inLexique, operand_5771->node, GGS_string ("OsScheduleTableCounterRef") COMMA_SOURCE_FILE_AT_LINE (190))).isBuiltAndTrue ()) {
          var_cas_st.modifier_setCounter (inLexique, function_lstring_param (inLexique, operand_5771->node COMMA_SOURCE_FILE_AT_LINE (191)) COMMA_SOURCE_FILE_AT_LINE (191)) ;
        }
      }
    }
  }else{
    var_cas_name.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("ScheduleTable does not have a PARAMETER-VALUES element") COMMA_SOURCE_FILE_AT_LINE (196)) ;
  }
  var_cas_node = function_elem_named (inLexique, var_cas_cont_elems, GGS_string ("SUB-CONTAINERS") COMMA_SOURCE_FILE_AT_LINE (197)) ;
  GGS_xmlNodeList  var_cas_nl ;
  var_cas_nl = var_cas_node.reader_nodeList (inLexique COMMA_SOURCE_FILE_AT_LINE (198)) ;
  {
    GGS_xmlNodeList::cEnumerator enumerator_6438 (var_cas_nl, true) ;
    const GGS_xmlNodeList::cElement * operand_6438 = NULL ;
    while (((operand_6438 = enumerator_6438.nextObject ()))) {
      macroValidPointer (operand_6438) ;
      ::routine_parse_schedtable_subcontainer (inLexique,  operand_6438->node.reader_nodeList (inLexique COMMA_SOURCE_FILE_AT_LINE (200)),  var_cas_name,  var_cas_st COMMA_SOURCE_FILE_AT_LINE (200)) ;
    }
  }
  GGS_scheduletable_map  var_cas_sts ;
  var_cas_sts = var_cas_cpu.reader_scheduletables (inLexique COMMA_SOURCE_FILE_AT_LINE (202)) ;
  var_cas_sts.modifier_put (inLexique, var_cas_name, var_cas_st COMMA_SOURCE_FILE_AT_LINE (203)) ;
  var_cas_cpu.modifier_setScheduletables (inLexique, var_cas_sts COMMA_SOURCE_FILE_AT_LINE (204)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_parse_schedtable\n") ;
  #endif
}

//---------------------------------------------------------------------------*
