/* -----------------------------------------------------------------------------
  Filename:    PduR_Cfg.h
  Description: Toolversion: 11.08.02.01.30.01.24.00.00.00
               
               Serial Number: CBD1300124
               Customer Info: Nxtr Automotive Corporation
                              Package: MSR_Vector_SLP3
                              Micro: TMS570LS30376USC
                              Compiler: TexasInstruments ccs 4.9.2
               
               
               Generator Fwk   : GENy 
               Generator Module: PduR
               
               Configuration   : C:\SynergyProjects\Haitec_LC_EPS_TMS570-nzx5jd\Haitec_LC_EPS_TMS570\Tools\AsrProject\Config\ECUC\EPS.ecuc.vdsxml
               
               ECU: 
                       TargetSystem: Hw_Tms470/570Cpu (Dcan)
                       Compiler:     TexasInstruments
                       Derivates:    TMS570LS30316U
               
               Channel "CAN00":
                       Databasefile: 
                       Bussystem:    CAN
                       Manufacturer: Vector
                       Node:         CanStateManagerConfiguration

  Generated by , 2015-02-13  10:21:39
 ----------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
  C O P Y R I G H T
 -------------------------------------------------------------------------------
  Copyright (c) 2001-2011 by Vctr Informatik GmbH. All rights reserved.
 
  This software is copyright protected and proprietary to Vctr Informatik 
  GmbH.
  
  Vctr Informatik GmbH grants to you only those rights as set out in the 
  license conditions.
  
  All other rights remain with Vctr Informatik GmbH.
 -------------------------------------------------------------------------------
 ----------------------------------------------------------------------------- */

#if !defined(PDUR_CFG_H)
#define PDUR_CFG_H

/* -----------------------------------------------------------------------------
    &&&~ Generator Version Check
 ----------------------------------------------------------------------------- */

#define GW_ASRPDUR_GENTOOL_GENY_MAJOR_VERSION 0x03
#define GW_ASRPDUR_GENTOOL_GENY_MINOR_VERSION 0x18
#define GW_ASRPDUR_GENTOOL_GENY_PATCH_VERSION 0x10


/* -----------------------------------------------------------------------------
    &&&~ GENy DLL Implementation Version
 ----------------------------------------------------------------------------- */

/* START of Checksum include for
  - Gw_AsrPduRPrecompileCRC */
#define GW_ASRPDUR_DLL_IMPLEMENTATION        0x13
/* END of Checksum include for
  - Gw_AsrPduRPrecompileCRC */


/* START of Checksum exclude for
  - Gw_AsrPduRPrecompileCRC */
#ifndef PDUR_OSTYPE_AUTOSAR
#define PDUR_OSTYPE_AUTOSAR
#endif


#ifndef PDUR_USE_DUMMY_FUNCTIONS
#define PDUR_USE_DUMMY_FUNCTIONS             STD_OFF
#endif


#ifndef PDUR_USE_DUMMY_STATEMENT
#define PDUR_USE_DUMMY_STATEMENT             STD_ON
#endif


#ifndef PDUR_CPU_TMS470
#define PDUR_CPU_TMS470
#endif


#ifndef PDUR_PROCESSOR_TI_TMS470_LS30316U
#define PDUR_PROCESSOR_TI_TMS470_LS30316U
#endif


#ifndef PDUR_COMP_TI
#define PDUR_COMP_TI
#endif


#ifndef PDUR_CRC_CHECK
#define PDUR_CRC_CHECK                       STD_OFF
#endif


#ifndef PDUR_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define PDUR_ATOMIC_BIT_ACCESS_IN_BITFIELD   STD_OFF
#endif


#ifndef PDUR_ATOMIC_VARIABLE_ACCESS
#define PDUR_ATOMIC_VARIABLE_ACCESS          32
#endif


/* END of Checksum exclude for
  - Gw_AsrPduRPrecompileCRC */

/* -----------------------------------------------------------------------------
    &&&~ List of Supported PduR Interfaces
 ----------------------------------------------------------------------------- */

/* START of Checksum include for
  - Gw_AsrPduRPrecompileCRC */
/* -----------------------------------------------------------------------------
    &&&~ SUPPORT Switches for each PduR Module Interfaces
 ----------------------------------------------------------------------------- */

#define PDUR_APPLIF_SUPPORT                  STD_OFF
#define PDUR_APPLTP_SUPPORT                  STD_OFF
#define PDUR_CANIF_SUPPORT                   STD_ON
#define PDUR_CANNM_SUPPORT                   STD_OFF
#define PDUR_CANTP_SUPPORT                   STD_ON
#define PDUR_COM_SUPPORT                     STD_ON
#define PDUR_DCM_SUPPORT                     STD_ON
#define PDUR_FRIF_SUPPORT                    STD_OFF
#define PDUR_FRNM_SUPPORT                    STD_OFF
#define PDUR_FRTP_SUPPORT                    STD_OFF
#define PDUR_GW_SUPPORT                      STD_OFF
#define PDUR_INVALID_SUPPORT                 STD_ON
#define PDUR_IPDUM_SUPPORT                   STD_OFF
#define PDUR_J1939TP_SUPPORT                 STD_OFF
#define PDUR_LINIF_SUPPORT                   STD_OFF
#define PDUR_LINTP_SUPPORT                   STD_OFF
#define PDUR_MOSTIF_SUPPORT                  STD_OFF
#define PDUR_MOSTTP_SUPPORT                  STD_OFF
#define PDUR_MULTI_SUPPORT                   STD_OFF
#define PDUR_NMOSEK_SUPPORT                  STD_OFF
#define PDUR_SOAD_SUPPORT                    STD_OFF


/* -----------------------------------------------------------------------------
    &&&~ Communication Interfaces Switches for each PduR Module Interfaces
 ----------------------------------------------------------------------------- */

#define PDUR_APPLIF_COMIF                    STD_OFF
#define PDUR_APPLTP_COMIF                    STD_OFF
#define PDUR_CANIF_COMIF                     STD_ON
#define PDUR_CANNM_COMIF                     STD_OFF
#define PDUR_CANTP_COMIF                     STD_OFF
#define PDUR_COM_COMIF                       STD_ON
#define PDUR_DCM_COMIF                       STD_OFF
#define PDUR_FRIF_COMIF                      STD_OFF
#define PDUR_FRNM_COMIF                      STD_OFF
#define PDUR_FRTP_COMIF                      STD_OFF
#define PDUR_GW_COMIF                        STD_OFF
#define PDUR_INVALID_COMIF                   STD_OFF
#define PDUR_IPDUM_COMIF                     STD_OFF
#define PDUR_J1939TP_COMIF                   STD_OFF
#define PDUR_LINIF_COMIF                     STD_OFF
#define PDUR_LINTP_COMIF                     STD_OFF
#define PDUR_MOSTIF_COMIF                    STD_OFF
#define PDUR_MOSTTP_COMIF                    STD_OFF
#define PDUR_MULTI_COMIF                     STD_OFF
#define PDUR_NMOSEK_COMIF                    STD_OFF
#define PDUR_SOAD_COMIF                      STD_OFF


/* -----------------------------------------------------------------------------
    &&&~ Transport Protocol Switches for each PduR Module Interfaces
 ----------------------------------------------------------------------------- */

#define PDUR_APPLIF_TP                       STD_OFF
#define PDUR_APPLTP_TP                       STD_OFF
#define PDUR_CANIF_TP                        STD_OFF
#define PDUR_CANNM_TP                        STD_OFF
#define PDUR_CANTP_TP                        STD_ON
#define PDUR_COM_TP                          STD_OFF
#define PDUR_DCM_TP                          STD_ON
#define PDUR_FRIF_TP                         STD_OFF
#define PDUR_FRNM_TP                         STD_OFF
#define PDUR_FRTP_TP                         STD_OFF
#define PDUR_GW_TP                           STD_OFF
#define PDUR_INVALID_TP                      STD_OFF
#define PDUR_IPDUM_TP                        STD_OFF
#define PDUR_J1939TP_TP                      STD_OFF
#define PDUR_LINIF_TP                        STD_OFF
#define PDUR_LINTP_TP                        STD_OFF
#define PDUR_MOSTIF_TP                       STD_OFF
#define PDUR_MOSTTP_TP                       STD_OFF
#define PDUR_MULTI_TP                        STD_OFF
#define PDUR_NMOSEK_TP                       STD_OFF
#define PDUR_SOAD_TP                         STD_OFF


/* -----------------------------------------------------------------------------
    &&&~ Upper and Lower Layer TRANSMITCANCELLATION_SUPPORT Switches
 ----------------------------------------------------------------------------- */

#define PDUR_APPLIFRECEIVECANCELLATION_SUPPORT STD_OFF
#define PDUR_APPLTPRECEIVECANCELLATION_SUPPORT STD_OFF
#define PDUR_CANIFRECEIVECANCELLATION_SUPPORT STD_OFF
#define PDUR_CANNMRECEIVECANCELLATION_SUPPORT STD_OFF
#define PDUR_CANTPRECEIVECANCELLATION_SUPPORT STD_OFF
#define PDUR_COMRECEIVECANCELLATION_SUPPORT  STD_OFF
#define PDUR_DCMRECEIVECANCELLATION_SUPPORT  STD_OFF
#define PDUR_FRIFRECEIVECANCELLATION_SUPPORT STD_OFF
#define PDUR_FRNMRECEIVECANCELLATION_SUPPORT STD_OFF
#define PDUR_FRTPRECEIVECANCELLATION_SUPPORT STD_OFF
#define PDUR_GWRECEIVECANCELLATION_SUPPORT   STD_OFF
#define PDUR_INVALIDRECEIVECANCELLATION_SUPPORT STD_OFF
#define PDUR_IPDUMRECEIVECANCELLATION_SUPPORT STD_OFF
#define PDUR_J1939TPRECEIVECANCELLATION_SUPPORT STD_OFF
#define PDUR_LINIFRECEIVECANCELLATION_SUPPORT STD_OFF
#define PDUR_LINTPRECEIVECANCELLATION_SUPPORT STD_OFF
#define PDUR_MOSTIFRECEIVECANCELLATION_SUPPORT STD_OFF
#define PDUR_MOSTTPRECEIVECANCELLATION_SUPPORT STD_OFF
#define PDUR_MULTIRECEIVECANCELLATION_SUPPORT STD_OFF
#define PDUR_NMOSEKRECEIVECANCELLATION_SUPPORT STD_OFF
#define PDUR_SOADRECEIVECANCELLATION_SUPPORT STD_OFF


/* -----------------------------------------------------------------------------
    &&&~ Upper and Lower Layer TRANSMITCANCELLATION_SUPPORT Switches
 ----------------------------------------------------------------------------- */

#define PDUR_APPLIFTRANSMITCANCELLATION_SUPPORT STD_OFF
#define PDUR_APPLTPTRANSMITCANCELLATION_SUPPORT STD_OFF
#define PDUR_CANIFTRANSMITCANCELLATION_SUPPORT STD_OFF
#define PDUR_CANNMTRANSMITCANCELLATION_SUPPORT STD_OFF
#define PDUR_CANTPTRANSMITCANCELLATION_SUPPORT STD_OFF
#define PDUR_COMTRANSMITCANCELLATION_SUPPORT STD_OFF
#define PDUR_DCMTRANSMITCANCELLATION_SUPPORT STD_OFF
#define PDUR_FRIFTRANSMITCANCELLATION_SUPPORT STD_OFF
#define PDUR_FRNMTRANSMITCANCELLATION_SUPPORT STD_OFF
#define PDUR_FRTPTRANSMITCANCELLATION_SUPPORT STD_OFF
#define PDUR_GWTRANSMITCANCELLATION_SUPPORT  STD_OFF
#define PDUR_INVALIDTRANSMITCANCELLATION_SUPPORT STD_OFF
#define PDUR_IPDUMTRANSMITCANCELLATION_SUPPORT STD_OFF
#define PDUR_J1939TPTRANSMITCANCELLATION_SUPPORT STD_OFF
#define PDUR_LINIFTRANSMITCANCELLATION_SUPPORT STD_OFF
#define PDUR_LINTPTRANSMITCANCELLATION_SUPPORT STD_OFF
#define PDUR_MOSTIFTRANSMITCANCELLATION_SUPPORT STD_OFF
#define PDUR_MOSTTPTRANSMITCANCELLATION_SUPPORT STD_OFF
#define PDUR_MULTITRANSMITCANCELLATION_SUPPORT STD_OFF
#define PDUR_NMOSEKTRANSMITCANCELLATION_SUPPORT STD_OFF
#define PDUR_SOADTRANSMITCANCELLATION_SUPPORT STD_OFF


/* -----------------------------------------------------------------------------
    &&&~ Upper and Lower Layer CHANGEPARAMETER_SUPPORT Switches
 ----------------------------------------------------------------------------- */

#define PDUR_APPLIFCHANGEPARAMETER_SUPPORT   STD_OFF
#define PDUR_APPLTPCHANGEPARAMETER_SUPPORT   STD_OFF
#define PDUR_CANIFCHANGEPARAMETER_SUPPORT    STD_OFF
#define PDUR_CANNMCHANGEPARAMETER_SUPPORT    STD_OFF
#define PDUR_CANTPCHANGEPARAMETER_SUPPORT    STD_OFF
#define PDUR_COMCHANGEPARAMETER_SUPPORT      STD_OFF
#define PDUR_DCMCHANGEPARAMETER_SUPPORT      STD_OFF
#define PDUR_FRIFCHANGEPARAMETER_SUPPORT     STD_OFF
#define PDUR_FRNMCHANGEPARAMETER_SUPPORT     STD_OFF
#define PDUR_FRTPCHANGEPARAMETER_SUPPORT     STD_OFF
#define PDUR_GWCHANGEPARAMETER_SUPPORT       STD_OFF
#define PDUR_INVALIDCHANGEPARAMETER_SUPPORT  STD_OFF
#define PDUR_IPDUMCHANGEPARAMETER_SUPPORT    STD_OFF
#define PDUR_J1939TPCHANGEPARAMETER_SUPPORT  STD_OFF
#define PDUR_LINIFCHANGEPARAMETER_SUPPORT    STD_OFF
#define PDUR_LINTPCHANGEPARAMETER_SUPPORT    STD_OFF
#define PDUR_MOSTIFCHANGEPARAMETER_SUPPORT   STD_OFF
#define PDUR_MOSTTPCHANGEPARAMETER_SUPPORT   STD_OFF
#define PDUR_MULTICHANGEPARAMETER_SUPPORT    STD_OFF
#define PDUR_NMOSEKCHANGEPARAMETER_SUPPORT   STD_OFF
#define PDUR_SOADCHANGEPARAMETER_SUPPORT     STD_OFF


/* -----------------------------------------------------------------------------
    &&&~ Upper and Lower Layer READPARAMETER_SUPPORT Switches
 ----------------------------------------------------------------------------- */

#define PDUR_APPLIFREADPARAMETER_SUPPORT     STD_OFF
#define PDUR_APPLTPREADPARAMETER_SUPPORT     STD_OFF
#define PDUR_CANIFREADPARAMETER_SUPPORT      STD_OFF
#define PDUR_CANNMREADPARAMETER_SUPPORT      STD_OFF
#define PDUR_CANTPREADPARAMETER_SUPPORT      STD_OFF
#define PDUR_COMREADPARAMETER_SUPPORT        STD_OFF
#define PDUR_DCMREADPARAMETER_SUPPORT        STD_OFF
#define PDUR_FRIFREADPARAMETER_SUPPORT       STD_OFF
#define PDUR_FRNMREADPARAMETER_SUPPORT       STD_OFF
#define PDUR_FRTPREADPARAMETER_SUPPORT       STD_OFF
#define PDUR_GWREADPARAMETER_SUPPORT         STD_OFF
#define PDUR_INVALIDREADPARAMETER_SUPPORT    STD_OFF
#define PDUR_IPDUMREADPARAMETER_SUPPORT      STD_OFF
#define PDUR_J1939TPREADPARAMETER_SUPPORT    STD_OFF
#define PDUR_LINIFREADPARAMETER_SUPPORT      STD_OFF
#define PDUR_LINTPREADPARAMETER_SUPPORT      STD_OFF
#define PDUR_MOSTIFREADPARAMETER_SUPPORT     STD_OFF
#define PDUR_MOSTTPREADPARAMETER_SUPPORT     STD_OFF
#define PDUR_MULTIREADPARAMETER_SUPPORT      STD_OFF
#define PDUR_NMOSEKREADPARAMETER_SUPPORT     STD_OFF
#define PDUR_SOADREADPARAMETER_SUPPORT       STD_OFF


/* -----------------------------------------------------------------------------
    &&&~ Upper and Lower Layer 2PROVIDERXBUFFER_CALLS Switches
 ----------------------------------------------------------------------------- */

#define PDUR_APPLIF_2PROVIDERXBUFFER_CALLS   STD_OFF
#define PDUR_APPLTP_2PROVIDERXBUFFER_CALLS   STD_OFF
#define PDUR_CANIF_2PROVIDERXBUFFER_CALLS    STD_OFF
#define PDUR_CANNM_2PROVIDERXBUFFER_CALLS    STD_OFF
#define PDUR_CANTP_2PROVIDERXBUFFER_CALLS    STD_OFF
#define PDUR_COM_2PROVIDERXBUFFER_CALLS      STD_OFF
#define PDUR_DCM_2PROVIDERXBUFFER_CALLS      STD_OFF
#define PDUR_FRIF_2PROVIDERXBUFFER_CALLS     STD_OFF
#define PDUR_FRNM_2PROVIDERXBUFFER_CALLS     STD_OFF
#define PDUR_FRTP_2PROVIDERXBUFFER_CALLS     STD_OFF
#define PDUR_GW_2PROVIDERXBUFFER_CALLS       STD_OFF
#define PDUR_INVALID_2PROVIDERXBUFFER_CALLS  STD_OFF
#define PDUR_IPDUM_2PROVIDERXBUFFER_CALLS    STD_OFF
#define PDUR_J1939TP_2PROVIDERXBUFFER_CALLS  STD_OFF
#define PDUR_LINIF_2PROVIDERXBUFFER_CALLS    STD_OFF
#define PDUR_LINTP_2PROVIDERXBUFFER_CALLS    STD_OFF
#define PDUR_MOSTIF_2PROVIDERXBUFFER_CALLS   STD_OFF
#define PDUR_MOSTTP_2PROVIDERXBUFFER_CALLS   STD_OFF
#define PDUR_MULTI_2PROVIDERXBUFFER_CALLS    STD_OFF
#define PDUR_NMOSEK_2PROVIDERXBUFFER_CALLS   STD_OFF
#define PDUR_SOAD_2PROVIDERXBUFFER_CALLS     STD_OFF


/* -----------------------------------------------------------------------------
    &&&~ Port Defines for each PduR Module Interface
 ----------------------------------------------------------------------------- */

#define PDUR_PORT_APPLIF                     0x00
#define PDUR_PORT_APPLTP                     0x01
#define PDUR_PORT_CANIF                      0x02
#define PDUR_PORT_CANNM                      0x03
#define PDUR_PORT_CANTP                      0x04
#define PDUR_PORT_COM                        0x05
#define PDUR_PORT_DCM                        0x06
#define PDUR_PORT_FRIF                       0x07
#define PDUR_PORT_FRNM                       0x08
#define PDUR_PORT_FRTP                       0x09
#define PDUR_PORT_GW                         0x0A
#define PDUR_PORT_INVALID                    0x0B
#define PDUR_PORT_IPDUM                      0x0C
#define PDUR_PORT_J1939TP                    0x0D
#define PDUR_PORT_LINIF                      0x0E
#define PDUR_PORT_LINTP                      0x0F
#define PDUR_PORT_MOSTIF                     0x10
#define PDUR_PORT_MOSTTP                     0x11
#define PDUR_PORT_MULTI                      0x12
#define PDUR_PORT_NMOSEK                     0x13
#define PDUR_PORT_SOAD                       0x14


#define PDUR_CDDDOBT_SUPPORT                 STD_OFF
#define PDUR_IPDUM_OPTIMIZED                 STD_ON
/* END of Checksum include for
  - Gw_AsrPduRPrecompileCRC */


/* -----------------------------------------------------------------------------
    &&&~ General PduR Configuration Switches
 ----------------------------------------------------------------------------- */

/* START of Checksum include for
  - Gw_AsrPduRPrecompileCRC */
#define PDUR_DEV_ERROR_DETECT                STD_ON
#define PDUR_MULTIPLE_CONFIGURATION          STD_OFF
#define PDUR_PROD_ERROR_DETECT               STD_ON
#define PDUR_VERSION_INFO_API                STD_ON
#define PDUR_CONFIG_VARIANT                  PDUR_CFGVAR_PRECOMPILETIME
#define PDUR_LIBRARY_SUPPORT                 STD_OFF
#define PDUR_VPB_SUPPORT                     STD_OFF
#define PDUR_GWTP_2PROVIDERXBUFFER_CALLS     STD_OFF
#define PDUR_BAC21_COMPATIBILITY             STD_OFF
#define PDUR_AR40TP_APISTYLE                 STD_OFF
#define PDUR_ROUTING_2_CSF_SUPPORT           STD_OFF
#define PDUR_ROUTINGPATHGROUP_SUPPORT        STD_OFF
#define PDUR_USE_PDUINFOTYPE                 STD_OFF
#define PDUR_USE_DYNAMIC_DLC                 STD_OFF
#define PDUR_BALANCE_ROUTING_TIME            STD_OFF
#define PDUR_GATEWAY_OPERATION               PDUR_GW_SUPPORT
#define PDUR_MULTICAST_FROMTP_SUPPORT        PDUR_MULTI_TP
#define PDUR_MULTICAST_FROMIF_SUPPORT        PDUR_MULTI_COMIF
#define PDUR_CANTPFFSIZE                     6
#define PDUR_SIZEOFPDUIDTYPE                 2
/* END of Checksum include for
  - Gw_AsrPduRPrecompileCRC */


/* -----------------------------------------------------------------------------
    &&&~ DET Error Ids
 ----------------------------------------------------------------------------- */

/* START of Checksum exclude for
  - Gw_AsrPduRPrecompileCRC */
/* -----------------------------------------------------------------------------
    &&&~ Det Error Ids for Transmit functions
 ----------------------------------------------------------------------------- */

#define PDUR_FCT_COMTX                       (uint8) 0xA0
#define PDUR_FCT_DCMTX                       (uint8) 0xA1


/* END of Checksum exclude for
  - Gw_AsrPduRPrecompileCRC */


/* START of Checksum exclude for
  - Gw_AsrPduRPrecompileCRC */
/* -----------------------------------------------------------------------------
    &&&~ The ECU Loader use the Init Pointer to choose a required Routing table
 ----------------------------------------------------------------------------- */

#define PDUR_SELECTABLE_INIT_POINTER         STD_OFF


/* END of Checksum exclude for
  - Gw_AsrPduRPrecompileCRC */

/* -----------------------------------------------------------------------------
    &&&~ Configuration Data Access Macro
 ----------------------------------------------------------------------------- */

#define PduR_GetCfgElement(x)                (PduRGlobalConfig.x)
#define PduR_PBConfigStruct                  PduRGlobalConfig


/* START of Checksum exclude for
  - Gw_AsrPduRPrecompileCRC */
/* -----------------------------------------------------------------------------
    &&&~ Rx CanIf Lo Source Handles
 ----------------------------------------------------------------------------- */

#define RxCanIf_BCM1__CAN00                  0
#define RxCanIf_ABS2__CAN00                  1
#define RxCanIf_ECM1__CAN00                  2


/* -----------------------------------------------------------------------------
    &&&~ Rx CanIf Lo Destination Handles
 ----------------------------------------------------------------------------- */

#define RxCom_Pdu_BCM1__CAN00                1
#define RxCom_Pdu_ABS2__CAN00                0
#define RxCom_Pdu_ECM1__CAN00                2


/* -----------------------------------------------------------------------------
    &&&~ Rx CanTp Lo Source Handles
 ----------------------------------------------------------------------------- */

#define RxCanTp_DiagFuncReqFT__CAN00         0
#define RxCanTp_DiagPhysReqToEPAS__CAN00_EPAS 1


/* -----------------------------------------------------------------------------
    &&&~ Rx CanTp Lo Destination Handles
 ----------------------------------------------------------------------------- */

#define RxDcm_DiagFuncReqFT__CAN00           1
#define RxDcm_DiagPhysReqToEPAS__CAN00_EPAS  0


/* -----------------------------------------------------------------------------
    &&&~ Tx Com Up Source Handles
 ----------------------------------------------------------------------------- */

#define TxCom_Pdu_EPAS2__CAN00               0
#define TxCom_Pdu_EPAS1__CAN00               1


/* -----------------------------------------------------------------------------
    &&&~ Tx Com Up Destination Handles
 ----------------------------------------------------------------------------- */

#define TxCanIf_EPAS2__CAN00                 4
#define TxCanIf_EPAS1__CAN00                 5


/* -----------------------------------------------------------------------------
    &&&~ Tx Dcm Up Source Handles
 ----------------------------------------------------------------------------- */

#define TxDcm_DiagRespFromEPAS__CAN00        0


/* -----------------------------------------------------------------------------
    &&&~ Tx Dcm Up Destination Handles
 ----------------------------------------------------------------------------- */

#define TxCanTp_DiagRespFromEPAS__CAN00      0


/* END of Checksum exclude for
  - Gw_AsrPduRPrecompileCRC */



#endif /* PDUR_CFG_H */