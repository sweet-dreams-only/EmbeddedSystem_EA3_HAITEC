/* -----------------------------------------------------------------------------
  Filename:    Vmm_Cfg.h
  Description: Toolversion: 11.08.02.01.30.01.24.00.00.00
               
               Serial Number: CBD1300124
               Customer Info: Nxtr Automotive Corporation
                              Package: MSR_Vector_SLP3
                              Micro: TMS570LS30376USC
                              Compiler: TexasInstruments ccs 4.9.2
               
               
               Generator Fwk   : GENy 
               Generator Module: Vmm
               
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

  Generated by , 2013-08-10  09:48:00
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

#if !defined(VMM_CFG_H)
#define VMM_CFG_H

/* -----------------------------------------------------------------------------
    &&&~ INCLUDES
 ----------------------------------------------------------------------------- */

#include "Vmm_Types.h"
#include "Com.h"


/* -----------------------------------------------------------------------------
    &&&~ DEFINES
 ----------------------------------------------------------------------------- */

/* START of Checksum include for
  - SysService_AsrVmmPrecompileCRC */
#define VMM_CONFIG_VARIANT                   (0x01u)
#define VMM_DEV_ERROR_DETECT                 STD_OFF
#define VMM_ECU_PASSIVE_HANDLING             STD_OFF
#define VMM_CRC_CHECK                        STD_OFF
#define VMM_PRECOMPILE_CRC                   (uint32) 0x240F602F
#define VMM_IDENTITY_MANAGER_CONFIG          STD_OFF
/* END of Checksum include for
  - SysService_AsrVmmPrecompileCRC */


/* -----------------------------------------------------------------------------
    &&&~ CONST DATA PROTOTYPES
 ----------------------------------------------------------------------------- */

#define VMM_START_SEC_CONST_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

extern CONST(uint8, VMM_CONST) VMM_BusSMToVmmChannel[1];
extern CONST(uint8, VMM_CONST) VMM_ChannelCount;
#define VMM_STOP_SEC_CONST_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

#define VMM_START_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

extern CONST(Com_PduGroupIdType, VMM_VAR_NOINIT) Vmm_ComCtrlRxGroup[1];
extern CONST(Com_PduGroupIdType, VMM_VAR_NOINIT) Vmm_ComCtrlTxGroup[1];
extern CONST(Com_PduGroupIdType, VMM_VAR_NOINIT) Vmm_BusSMRxGroup[1];
extern CONST(Com_PduGroupIdType, VMM_VAR_NOINIT) Vmm_BusSMTxGroup[1];
#define VMM_STOP_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

#if (VMM_CRC_CHECK == STD_ON)
#define VMM_START_SEC_CONST_32BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

extern CONST(uint32, VMM_CONST) Vmm_PrecompileCRC;
#define VMM_STOP_SEC_CONST_32BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


#endif

#define VMM_START_SEC_CONST_32BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

extern CONST(uint32, VMM_CONST) Vmm_GeneratorVersion;
#define VMM_STOP_SEC_CONST_32BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"



/* -----------------------------------------------------------------------------
    &&&~ RAM DATA PROTOTYPES
 ----------------------------------------------------------------------------- */

#define VMM_START_SEC_VAR_NOINIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

extern VAR(boolean, VMM_VAR_NOINIT) Vmm_BusSMInitFlag[1];
extern VAR(boolean, VMM_VAR_NOINIT) Vmm_ComCtrlComRx[1];
extern VAR(boolean, VMM_VAR_NOINIT) Vmm_ComCtrlComTx[1];
extern VAR(boolean, VMM_VAR_NOINIT) Vmm_ComTxState[1];
extern VAR(boolean, VMM_VAR_NOINIT) Vmm_ComRxState[1];
extern VAR(boolean, VMM_VAR_NOINIT) Vmm_BusSMDMState[1];
#define VMM_STOP_SEC_VAR_NOINIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"



/* -----------------------------------------------------------------------------
    &&&~ FUNCTION PROTOTYPES
 ----------------------------------------------------------------------------- */

#define VMM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

extern FUNC(void, VMM_CODE) Vmm_SwitchNm(NetworkHandleType Channel, boolean txState);
#define VMM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"




#endif /* VMM_CFG_H */