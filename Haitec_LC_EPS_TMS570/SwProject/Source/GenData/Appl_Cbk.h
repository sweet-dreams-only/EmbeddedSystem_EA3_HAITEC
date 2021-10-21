/* -----------------------------------------------------------------------------
  Filename:    Appl_Cbk.h
  Description: Toolversion: 11.08.02.01.30.01.24.00.00.00
               
               Serial Number: CBD1300124
               Customer Info: Nxtr Automotive Corporation
                              Package: MSR_Vector_SLP3
                              Micro: TMS570LS30376USC
                              Compiler: TexasInstruments ccs 4.9.2
               
               
               Generator Fwk   : GENy 
               Generator Module: Com
               
               Configuration   : C:\synergy_projects_working\Haitec\Haitec_LC_EPS_TMS570\Haitec_LC_EPS_TMS570\Tools\AsrProject\Config\ECUC\EPS.ecuc.vdsxml
               
               ECU: 
                       TargetSystem: Hw_Tms470/570Cpu (Dcan)
                       Compiler:     TexasInstruments
                       Derivates:    TMS570LS30316U
               
               Channel "CAN00":
                       Databasefile: 
                       Bussystem:    CAN
                       Manufacturer: Vector
                       Node:         CanStateManagerConfiguration

  Generated by , 2016-01-22  15:41:14
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

#if !defined(APPL_CBK_H)
#define APPL_CBK_H

#include "ComStack_Types.h"
#define COM_START_SEC_APPL_CODE
/* PRQA S 5087 1 */ /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */
#include "MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ Rx Notification Handler Callback Functions
 ----------------------------------------------------------------------------- */

extern FUNC(void, COM_APPL_CODE) Appl_COMCbk_Com_BCM_Key_Sta__BCM1__CAN00(void);
extern FUNC(void, COM_APPL_CODE) Appl_COMCbk_Com_CAN_N__ECM1__CAN00(void);
extern FUNC(void, COM_APPL_CODE) Appl_COMCbk_Com_VehSpeed__ABS2__CAN00(void);


/* -----------------------------------------------------------------------------
    &&&~ Tx Notification Handler Callback Functions
 ----------------------------------------------------------------------------- */

extern FUNC(void, COM_APPL_CODE) Appl_COMCbkTAck_Com_Rel_Steer_Wheel_Ang__EPAS2__CAN00(void);




#define COM_STOP_SEC_APPL_CODE
/* PRQA S 5087 1 */ /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */
#include "MemMap.h"



#endif /* APPL_CBK_H */