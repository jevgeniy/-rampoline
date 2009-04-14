//---------------------------------------------------------------------------*
//                                                                           *
//                      File 'goil_message_verif.cpp'                        *
//                        Generated by version 1.8.0                         *
//                       march 5th, 2009, at 9h28'18"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 451
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "goil_message_verif.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_message_verif.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                Implementation of routine "check_net_dir"                  *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_check_net_dir (C_Compiler & _inLexique,
                                GGS_lstring   var_cas_net,
                                GGS_netmess_map   var_cas_netm,
                                GGS_string  var_cas_exp_dir COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_check_net_dir at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_netmess_obj  var_cas_nm ;
  GGS_lstring  var_cas_dir ;
  const GGS_netmess_map  _temp_315 = var_cas_netm ;
  if (_temp_315._isBuilt ()) {
    _temp_315 (HERE)->method_get (_inLexique, var_cas_net, var_cas_nm COMMA_SOURCE_FILE_AT_LINE (13)) ;
  }
  { const GGS_base_netprop _var_630 = var_cas_nm.reader_netprop (_inLexique COMMA_SOURCE_FILE_AT_LINE (14)) ; // CAST instruction
    if (_var_630.getPtr () != NULL) {
      macroValidPointer (_var_630.getPtr ()) ;
      if (typeid (cPtr_static_netprop) == typeid (* (_var_630.getPtr ()))) {
        const GGS_static_netprop var_cas_sn (_var_630.getPtr ()) ;
        var_cas_dir = var_cas_sn.reader_direction (_inLexique COMMA_SOURCE_FILE_AT_LINE (15)) ;
      }else if (typeid (cPtr_dynamic_netprop) == typeid (* (_var_630.getPtr ()))) {
        const GGS_dynamic_netprop var_cas_dn (_var_630.getPtr ()) ;
        var_cas_dir = var_cas_dn.reader_direction (_inLexique COMMA_SOURCE_FILE_AT_LINE (16)) ;
      }else if (typeid (cPtr_zero_netprop) == typeid (* (_var_630.getPtr ()))) {
        const GGS_zero_netprop var_cas_zn (_var_630.getPtr ()) ;
        var_cas_dir = var_cas_zn.reader_direction (_inLexique COMMA_SOURCE_FILE_AT_LINE (17)) ;
      }else{
        var_cas_dir = GGS_lstring ::constructor_new (_inLexique, GGS_string (true, ""), GGS_location (_inLexique) COMMA_HERE) ;
        var_cas_nm.reader_netprop (_inLexique COMMA_SOURCE_FILE_AT_LINE (20)).reader_loc (_inLexique COMMA_SOURCE_FILE_AT_LINE (20)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "Internal error, unexpected type") COMMA_SOURCE_FILE_AT_LINE (21)) ;
      }
    }
  }
  if (((var_cas_dir.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (22)))._operator_isNotEqual (GGS_string (true, ""))).isBuiltAndTrue ()) {
    if (((var_cas_dir.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (23)))._operator_isNotEqual (var_cas_exp_dir)).isBuiltAndTrue ()) {
      var_cas_net.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, ((GGS_string (true, "NETWORKMESSAGE does not have the DIRECTION = "))._operator_concat (var_cas_exp_dir.reader_uppercaseString (_inLexique COMMA_SOURCE_FILE_AT_LINE (24))))._operator_concat (GGS_string (true, " attribute")) COMMA_SOURCE_FILE_AT_LINE (25)) ;
      var_cas_dir.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "DIRECTION attribute is defined here") COMMA_SOURCE_FILE_AT_LINE (26)) ;
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_check_net_dir\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//             Implementation of routine "check_external_sent"               *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_check_external_sent (C_Compiler & _inLexique,
                                GGS_lstring   var_cas_net,
                                GGS_netmess_map   var_cas_netm COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_check_external_sent at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  if (((var_cas_netm.reader_hasKey (_inLexique, var_cas_net.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (35)) COMMA_SOURCE_FILE_AT_LINE (35)))._operator_not ()).isBuiltAndTrue ()) {
    var_cas_net.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, ((GGS_string (true, "NETWORKMESSAGE "))._operator_concat (var_cas_net.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (36))))._operator_concat (GGS_string (true, " does not exist")) COMMA_SOURCE_FILE_AT_LINE (37)) ;
  }else{
    ::routine_check_net_dir (_inLexique,  var_cas_net,  var_cas_netm,  GGS_string (true, "sent") COMMA_SOURCE_FILE_AT_LINE (38)) ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_check_external_sent\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//           Implementation of routine "check_external_received"             *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_check_external_received (C_Compiler & _inLexique,
                                GGS_lstring   var_cas_net,
                                GGS_netmess_map   var_cas_netm COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_check_external_received at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  if (((var_cas_netm.reader_hasKey (_inLexique, var_cas_net.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (47)) COMMA_SOURCE_FILE_AT_LINE (47)))._operator_not ()).isBuiltAndTrue ()) {
    var_cas_net.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, ((GGS_string (true, "NETWORKMESSAGE "))._operator_concat (var_cas_net.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (48))))._operator_concat (GGS_string (true, " does not exist")) COMMA_SOURCE_FILE_AT_LINE (49)) ;
  }else{
    ::routine_check_net_dir (_inLexique,  var_cas_net,  var_cas_netm,  GGS_string (true, "received") COMMA_SOURCE_FILE_AT_LINE (50)) ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_check_external_received\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//         Implementation of routine "check_external_link_received"          *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_check_external_link_received (C_Compiler & _inLexique,
                                GGS_link_obj   var_cas_link,
                                GGS_message_map   var_cas_messages,
                                GGS_netmess_map   var_cas_netm,
                                GGS_location   var_cas_link_ref,
                                GGS_uint   var_cas_depth COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_check_external_link_received at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  { const GGS_link_obj _var_3317 = var_cas_link ; // CAST instruction
    if (_var_3317.getPtr () != NULL) {
      macroValidPointer (_var_3317.getPtr ()) ;
      if (typeid (cPtr_true_link) == typeid (* (_var_3317.getPtr ()))) {
        const GGS_true_link var_cas_tl (_var_3317.getPtr ()) ;
        if (((var_cas_depth)._operator_isEqual (GGS_uint (true, 0U))).isBuiltAndTrue ()) {
          var_cas_link.reader_loc (_inLexique COMMA_SOURCE_FILE_AT_LINE (64)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "This message is linked from another message.") COMMA_SOURCE_FILE_AT_LINE (65)) ;
          var_cas_link.reader_loc (_inLexique COMMA_SOURCE_FILE_AT_LINE (65)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "So it should be linked to a network message.") COMMA_SOURCE_FILE_AT_LINE (66)) ;
          var_cas_link_ref.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "Referencing message is here") COMMA_SOURCE_FILE_AT_LINE (67)) ;
        }else{
          GGS_lstring  var_cas_mess ;
          var_cas_mess = var_cas_tl.reader_receivemessage (_inLexique COMMA_SOURCE_FILE_AT_LINE (68)) ;
          if ((var_cas_messages.reader_hasKey (_inLexique, var_cas_mess.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (70)) COMMA_SOURCE_FILE_AT_LINE (70))).isBuiltAndTrue ()) {
            GGS_message_obj  var_cas_lm ;
            const GGS_message_map  _temp_2089 = var_cas_messages ;
            if (_temp_2089._isBuilt ()) {
              _temp_2089 (HERE)->method_get (_inLexique, var_cas_mess, var_cas_lm COMMA_SOURCE_FILE_AT_LINE (72)) ;
            }
            { const GGS_mess_prop_obj _var_2879 = var_cas_lm.reader_messageproperty (_inLexique COMMA_SOURCE_FILE_AT_LINE (73)) ; // CAST instruction
              if (_var_2879.getPtr () != NULL) {
                macroValidPointer (_var_2879.getPtr ()) ;
                if (typeid (cPtr_rue_mess_prop) == typeid (* (_var_2879.getPtr ()))) {
                  const GGS_rue_mess_prop var_cas_ue (_var_2879.getPtr ()) ;
                  ::routine_check_external_link_received (_inLexique,  var_cas_ue.reader_link (_inLexique COMMA_SOURCE_FILE_AT_LINE (75)),  var_cas_messages,  var_cas_netm,  var_cas_tl.reader_loc (_inLexique COMMA_SOURCE_FILE_AT_LINE (75)),  var_cas_depth._substract_operation (_inLexique, GGS_uint (true, 1U) COMMA_SOURCE_FILE_AT_LINE (75)) COMMA_SOURCE_FILE_AT_LINE (75)) ;
                }else if (typeid (cPtr_rqe_mess_prop) == typeid (* (_var_2879.getPtr ()))) {
                  const GGS_rqe_mess_prop var_cas_qe (_var_2879.getPtr ()) ;
                  ::routine_check_external_link_received (_inLexique,  var_cas_qe.reader_link (_inLexique COMMA_SOURCE_FILE_AT_LINE (77)),  var_cas_messages,  var_cas_netm,  var_cas_tl.reader_loc (_inLexique COMMA_SOURCE_FILE_AT_LINE (77)),  var_cas_depth._substract_operation (_inLexique, GGS_uint (true, 1U) COMMA_SOURCE_FILE_AT_LINE (77)) COMMA_SOURCE_FILE_AT_LINE (77)) ;
                }else if (typeid (cPtr_rde_mess_prop) == typeid (* (_var_2879.getPtr ()))) {
                  const GGS_rde_mess_prop var_cas_de (_var_2879.getPtr ()) ;
                  ::routine_check_external_link_received (_inLexique,  var_cas_de.reader_link (_inLexique COMMA_SOURCE_FILE_AT_LINE (79)),  var_cas_messages,  var_cas_netm,  var_cas_tl.reader_loc (_inLexique COMMA_SOURCE_FILE_AT_LINE (79)),  var_cas_depth._substract_operation (_inLexique, GGS_uint (true, 1U) COMMA_SOURCE_FILE_AT_LINE (79)) COMMA_SOURCE_FILE_AT_LINE (79)) ;
                }else{
                  var_cas_mess.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "Linked message has a wrong MESSAGEPROPERTY") COMMA_SOURCE_FILE_AT_LINE (82)) ;
                  GGS_location  var_cas_loc ;
                  var_cas_loc = var_cas_lm.reader_messageproperty (_inLexique COMMA_SOURCE_FILE_AT_LINE (82)).reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (82)) ;
                  var_cas_loc.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "expected MESSAGEPROPERTY are") COMMA_SOURCE_FILE_AT_LINE (84)) ;
                  var_cas_loc.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "    RECEIVE_UNQUEUED_EXTERNAL,") COMMA_SOURCE_FILE_AT_LINE (85)) ;
                  var_cas_loc.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "    RECEIVE_QUEUED_EXTERNAL or") COMMA_SOURCE_FILE_AT_LINE (86)) ;
                  var_cas_loc.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "    RECEIVE_DYNAMIC_EXTERNAL") COMMA_SOURCE_FILE_AT_LINE (87)) ;
                }
              }
            }
          }else{
            var_cas_mess.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, ((GGS_string (true, "Linked message "))._operator_concat (var_cas_mess.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (89))))._operator_concat (GGS_string (true, " does not exist")) COMMA_SOURCE_FILE_AT_LINE (90)) ;
          }
        }
      }else if (typeid (cPtr_false_link) == typeid (* (_var_3317.getPtr ()))) {
        const GGS_false_link var_cas_fl (_var_3317.getPtr ()) ;
        GGS_lstring  var_cas_net ;
        var_cas_net = var_cas_fl.reader_networkmessage (_inLexique COMMA_SOURCE_FILE_AT_LINE (93)) ;
        if (((var_cas_netm.reader_hasKey (_inLexique, var_cas_net.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (94)) COMMA_SOURCE_FILE_AT_LINE (94)))._operator_not ()).isBuiltAndTrue ()) {
          var_cas_net.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, ((GGS_string (true, "NETWORKMESSAGE "))._operator_concat (var_cas_net.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (95))))._operator_concat (GGS_string (true, " does not exist")) COMMA_SOURCE_FILE_AT_LINE (96)) ;
        }else{
          ::routine_check_net_dir (_inLexique,  var_cas_net,  var_cas_netm,  GGS_string (true, "received") COMMA_SOURCE_FILE_AT_LINE (97)) ;
        }
      }else{
        var_cas_link.reader_loc (_inLexique COMMA_SOURCE_FILE_AT_LINE (100)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "Internal error, unexpected type") COMMA_SOURCE_FILE_AT_LINE (101)) ;
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_check_external_link_received\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//         Implementation of routine "networkmessages_exist_and_ok"          *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_networkmessages_exist_and_ok (C_Compiler & _inLexique,
                                GGS_message_map   var_cas_messages,
                                GGS_netmess_map   var_cas_netm COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_networkmessages_exist_and_ok at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  {
    GGS_message_map::cEnumerator enumerator_3534 (var_cas_messages, true) ;
    const GGS_message_map::cElement * operand_3534 = NULL ;
    while (((operand_3534 = enumerator_3534.nextObject ()))) {
      macroValidPointer (operand_3534) ;
      { const GGS_mess_prop_obj _var_4272 = operand_3534->mInfo.mess.reader_messageproperty (_inLexique COMMA_SOURCE_FILE_AT_LINE (112)) ; // CAST instruction
        if (_var_4272.getPtr () != NULL) {
          macroValidPointer (_var_4272.getPtr ()) ;
          if (typeid (cPtr_sse_mess_prop) == typeid (* (_var_4272.getPtr ()))) {
            const GGS_sse_mess_prop var_cas_sse (_var_4272.getPtr ()) ;
            ::routine_check_external_sent (_inLexique,  var_cas_sse.reader_networkmessage (_inLexique COMMA_SOURCE_FILE_AT_LINE (114)),  var_cas_netm COMMA_SOURCE_FILE_AT_LINE (114)) ;
          }else if (typeid (cPtr_sde_mess_prop) == typeid (* (_var_4272.getPtr ()))) {
            const GGS_sde_mess_prop var_cas_sde (_var_4272.getPtr ()) ;
            ::routine_check_external_sent (_inLexique,  var_cas_sde.reader_networkmessage (_inLexique COMMA_SOURCE_FILE_AT_LINE (116)),  var_cas_netm COMMA_SOURCE_FILE_AT_LINE (116)) ;
          }else if (typeid (cPtr_sze_mess_prop) == typeid (* (_var_4272.getPtr ()))) {
            const GGS_sze_mess_prop var_cas_sze (_var_4272.getPtr ()) ;
            ::routine_check_external_sent (_inLexique,  var_cas_sze.reader_networkmessage (_inLexique COMMA_SOURCE_FILE_AT_LINE (118)),  var_cas_netm COMMA_SOURCE_FILE_AT_LINE (118)) ;
          }else if (typeid (cPtr_rze_mess_prop) == typeid (* (_var_4272.getPtr ()))) {
            const GGS_rze_mess_prop var_cas_rze (_var_4272.getPtr ()) ;
            ::routine_check_external_received (_inLexique,  var_cas_rze.reader_networkmessage (_inLexique COMMA_SOURCE_FILE_AT_LINE (120)),  var_cas_netm COMMA_SOURCE_FILE_AT_LINE (120)) ;
          }else if (typeid (cPtr_rue_mess_prop) == typeid (* (_var_4272.getPtr ()))) {
            const GGS_rue_mess_prop var_cas_rue (_var_4272.getPtr ()) ;
            ::routine_check_external_link_received (_inLexique,  var_cas_rue.reader_link (_inLexique COMMA_SOURCE_FILE_AT_LINE (122)),  var_cas_messages,  var_cas_netm,  GGS_location (_inLexique),  GGS_uint (true, 1U) COMMA_SOURCE_FILE_AT_LINE (122)) ;
          }else if (typeid (cPtr_rqe_mess_prop) == typeid (* (_var_4272.getPtr ()))) {
            const GGS_rqe_mess_prop var_cas_rqe (_var_4272.getPtr ()) ;
            ::routine_check_external_link_received (_inLexique,  var_cas_rqe.reader_link (_inLexique COMMA_SOURCE_FILE_AT_LINE (124)),  var_cas_messages,  var_cas_netm,  GGS_location (_inLexique),  GGS_uint (true, 1U) COMMA_SOURCE_FILE_AT_LINE (124)) ;
          }else if (typeid (cPtr_rde_mess_prop) == typeid (* (_var_4272.getPtr ()))) {
            const GGS_rde_mess_prop var_cas_rde (_var_4272.getPtr ()) ;
            ::routine_check_external_link_received (_inLexique,  var_cas_rde.reader_link (_inLexique COMMA_SOURCE_FILE_AT_LINE (126)),  var_cas_messages,  var_cas_netm,  GGS_location (_inLexique),  GGS_uint (true, 1U) COMMA_SOURCE_FILE_AT_LINE (126)) ;
          }else{
          }
        }
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_networkmessages_exist_and_ok\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//         Implementation of routine "networkmessages_well_formed"           *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_networkmessages_well_formed (C_Compiler & _inLexique,
                                GGS_netmess_map   var_cas_netm COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_networkmessages_well_formed at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  {
    GGS_netmess_map::cEnumerator enumerator_4384 (var_cas_netm, true) ;
    const GGS_netmess_map::cElement * operand_4384 = NULL ;
    while (((operand_4384 = enumerator_4384.nextObject ()))) {
      macroValidPointer (operand_4384) ;
      { const GGS_base_netprop _var_4549 = operand_4384->mInfo.netmess.reader_netprop (_inLexique COMMA_SOURCE_FILE_AT_LINE (135)) ; // CAST instruction
        if (_var_4549.getPtr () != NULL) {
          macroValidPointer (_var_4549.getPtr ()) ;
          if (typeid (cPtr_void_netprop) == typeid (* (_var_4549.getPtr ()))) {
            operand_4384->mKey.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, (GGS_string (true, "MESSAGEPROPERTY attribute is missing for NETWORKMESSAGE "))._operator_concat (operand_4384->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (137))) COMMA_SOURCE_FILE_AT_LINE (138)) ;
          }else{
          }
        }
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_networkmessages_well_formed\n") ;
  #endif
}

//---------------------------------------------------------------------------*

