/* -----------------------------------------------------------------------------
  Filename:    ComM_Cfg.h
  Description: Toolversion: 11.08.02.01.30.01.24.00.00.00
               
               Serial Number: CBD1300124
               Customer Info: Nxtr Automotive Corporation
                              Package: MSR_Vector_SLP3
                              Micro: TMS570LS30376USC
                              Compiler: TexasInstruments ccs 4.9.2
               
               
               Generator Fwk   : GENy 
               Generator Module: ComM
               
               Configuration   : C:\Temp\Haitec_LC_EPS_TMS570\Haitec_LC_EPS_TMS570\Tools\AsrProject\Config\ECUC\EPS.ecuc.vdsxml
               
               ECU: 
                       TargetSystem: Hw_Tms470/570Cpu (Dcan)
                       Compiler:     TexasInstruments
                       Derivates:    TMS570LS30316U
               
               Channel "CAN00":
                       Databasefile: 
                       Bussystem:    CAN
                       Manufacturer: Vector
                       Node:         CanStateManagerConfiguration

  Generated by , 2013-07-19  08:51:13
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

#if !defined(COMM_CFG_H)
#define COMM_CFG_H

/* -----------------------------------------------------------------------------
    &&&~ INCLUDES
 ----------------------------------------------------------------------------- */

#include "ComM_Types.h"


/* -----------------------------------------------------------------------------
    &&&~ GLOBAL CONSTANT MACROS
 ----------------------------------------------------------------------------- */

#define CCL_ASRCOMMDLL_VERSION               0x0318
#define CCL_ASRCOMMDLL_RELEASE_VERSION       0x04
/* -----------------------------------------------------------------------------
    &&&~ CONFIGURATION DEFINES
 ----------------------------------------------------------------------------- */

/* START of Checksum include for
  - Ccl_AsrComMPrecompileCRC */
#define COMM_DEV_ERROR_DETECT STD_ON
#define COMM_PROD_ERROR_DETECT STD_ON
#define COMM_VERSION_INFO_API STD_ON
#define COMM_IDENTITY_MANAGER_CONFIG         STD_OFF
#define COMM_CRC_CHECK                       STD_OFF
#define COMM_PRECOMPILE_CRC                  (uint32) 0xD0FFB5B3
/* END of Checksum include for
  - Ccl_AsrComMPrecompileCRC */



#define COMM_BUS_TYPE_ON_CHANNEL_0    COMM_BUS_TYPE_CAN
#define COMM_CONFIG_VARIANT    1u
#define COMM_ACTIVE_CHANNEL    1u   /* amount of active ComM channels */
#define COMM_MAX_NUMBER_OF_USERS    1u  /* maximum amount of useres */
#define COMM_MAX_BYTE_MASK    1u  /* maximum amount of useres */
#define COMM_USER_BYTE    1u  /* ComM user count */





#endif /* COMM_CFG_H */