/* -----------------------------------------------------------------------------
  Filename:    CanTp_PBcfg.c
  Description: Toolversion: 11.08.02.01.30.01.24.00.00.00
               
               Serial Number: CBD1300124
               Customer Info: Nxtr Automotive Corporation
                              Package: MSR_Vector_SLP3
                              Micro: TMS570LS30376USC
                              Compiler: TexasInstruments ccs 4.9.2
               
               
               Generator Fwk   : GENy 
               Generator Module: CanTp
               
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

  Generated by , 2014-11-17  12:08:28
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

/* -----------------------------------------------------------------------------
    &&&~ Include files
 ----------------------------------------------------------------------------- */

#include "Dem.h"
#include "CanTp_PBcfg.h"
#include "CanIf_Cfg.h"


/* -----------------------------------------------------------------------------
    &&&~ CanTp Overall (ROM)
 ----------------------------------------------------------------------------- */

/* Struct to hold the complete CanTp-configuration */
#define CANTP_START_SEC_CONST_PBCFG
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

extern CONST(vCanTp_RxNsduCfgType, CANTP_PBCFG) vCanTp_RxNsduCfg[];
extern CONST(vCanTp_TxNsduCfgType, CANTP_PBCFG) vCanTp_TxNsduCfg[];
extern CONST(vCanTp_RxPduMapType, CANTP_PBCFG) vCanTp_RxPduMap[];

#define CANTP_STOP_SEC_CONST_PBCFG
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


#define CANTP_START_SEC_CONST_PBCFG_ROOT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

CONST(vCanTp_CfgType, CANTP_PBCFG) vCanTp_Cfg = 
{
  vCanTp_RxNsduCfg /* Pointer to RxNsdu-cfg-table */, 
  vCanTp_TxNsduCfg /* Pointer to TxNsdu-cfg-table */, 
  vCanTp_RxPduMap /* Extended SDU indirection table */, 
  10 /* vCanTp_TaskCycle */, 
  1 /* ROM_MEM PduIdType MaxCanIfTxPduId */, 
  2 /* ROM_MEM PduIdType NumCanIfRxPdus */, 
  1 /* ROM_MEM PduIdType NumCanTpTxSduId */, 
  2 /* ROM_MEM PduIdType NumCanTpRxSduId */, 
  0 /* uint8 InstanceId */, 
  0x1267 /* Magic Number */
};
#define CANTP_STOP_SEC_CONST_PBCFG_ROOT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"



#define CANTP_START_SEC_CONST_PBCFG
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ RxNsdu (ROM)
 ----------------------------------------------------------------------------- */

CONST(vCanTp_RxNsduCfgType, CANTP_PBCFG) vCanTp_RxNsduCfg[] = 
{
  
  {
    0 /* CANTP_RXNSDU_ID; to    PduR */, 
    0 /* CANTP_RXNPDU_ID; from  CanIf */, 
    65535 /* CANTP_TXFC_NPDU_ID; to CanIf */, 
    1 /* CANTP_TA_TYPE */, 
    0xFF /* CANTP_RX_NTA */, 
    0xFF /* CANTP_TXFC_NSA */
  } /* DiagFuncReqFT__CAN00 - Index 0 */, 
  
  {
    1 /* CANTP_RXNSDU_ID; to    PduR */, 
    1 /* CANTP_RXNPDU_ID; from  CanIf */, 
    1 /* CANTP_TXFC_NPDU_ID; to CanIf */, 
    0 /* CANTP_TA_TYPE */, 
    0xFF /* CANTP_RX_NTA */, 
    0xFF /* CANTP_TXFC_NSA */
  } /* DiagPhysReqToEPAS__CAN00_EPAS - Index 1 */
};


/* -----------------------------------------------------------------------------
    &&&~ TxNsdu (ROM)
 ----------------------------------------------------------------------------- */

CONST(vCanTp_TxNsduCfgType, CANTP_PBCFG) vCanTp_TxNsduCfg[] = 
{
  
  {
    0 /* CANTP_TXNSDU_ID;  from PduR */, 
    1 /* CANTP_TXNPDU_ID; to CanIf */, 
    1 /* CANTP_RXFC_NPDU_ID; from CanIf */, 
    0xFF /* CANTP_TX_NTA */, 
    0xFF /* CANTP_RXFC_NTA */
  } /* DiagRespFromEPAS__CAN00 - Index 0 */
};


/* -----------------------------------------------------------------------------
    &&&~ RxPdu mapping table
 ----------------------------------------------------------------------------- */

CONST(vCanTp_RxPduMapType, CANTP_PBCFG) vCanTp_RxPduMap[] = 
{
  
  {
    0, 
    65535, 
    0
  }, 
  
  {
    1, 
    0, 
    0
  }
};



#define CANTP_STOP_SEC_CONST_PBCFG
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"




