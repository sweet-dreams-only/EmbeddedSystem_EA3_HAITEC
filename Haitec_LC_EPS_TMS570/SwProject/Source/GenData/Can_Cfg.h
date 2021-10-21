/* -----------------------------------------------------------------------------
  Filename:    Can_Cfg.h
  Description: Toolversion: 11.08.02.01.30.01.24.00.00.00
               
               Serial Number: CBD1300124
               Customer Info: Nxtr Automotive Corporation
                              Package: MSR_Vector_SLP3
                              Micro: TMS570LS30376USC
                              Compiler: TexasInstruments ccs 4.9.2
               
               
               Generator Fwk   : GENy 
               Generator Module: DrvCan__coreAsr
               
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

  Generated by , 2015-06-25  11:09:17
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

#if !defined(CAN_CFG_H)
#define CAN_CFG_H

/* START of Checksum include for
  - DrvCan__baseAsrPrecompileCRC */
/* PRQA S 0850 EOF */ /* MD_Can_0850 */
/* -----------------------------------------------------------------------------
    &&&~ Includes
 ----------------------------------------------------------------------------- */

/* START of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */
#include "ComStack_Types.h"
#include "EcuM_Cbk.h"
#include "Dem.h"
#include "v_cfg.h"
/* END of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */


/* -----------------------------------------------------------------------------
    &&&~ Version defines
 ----------------------------------------------------------------------------- */

/* START of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */
#define DRVCAN__BASESASRDLL_VERSION          0x0403
#define DRVCAN__BASESASRDLL_RELEASE_VERSION  0x03

#define CAN_GEN_BASE_VERSION                 0x0106u
#define CAN_ASR_VERSION                      0x0300u
/* END of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */
#define DrvCan_Tms470DcanAsrDLL_VERSION      0x0206
#define DrvCan_Tms470DcanAsrDLL_RELEASE_VERSION 0x00
#define CAN_GEN_Tms470DcanAsr_VERSION        0x0101


/* -----------------------------------------------------------------------------
    &&&~ Hardcoded defines
 ----------------------------------------------------------------------------- */

/* START of Checksum include for
  - DrvCan__baseAsrPrecompileCRC */
#define RxBasicCANType                       0
#define RxFullCANType                        1
#define TxBasicCANType                       2
#define TxFullCANType                        3
#define UnusedCANType                        4
#define CAN_INTERRUPT                        0
#define CAN_POLLING                          1
#define kCanChannelNotUsed                   0xFF
/* END of Checksum include for
  - DrvCan__baseAsrPrecompileCRC */


/* -----------------------------------------------------------------------------
    &&&~ Defines / Switches
 ----------------------------------------------------------------------------- */

/* START of Checksum include for
  - DrvCan__baseAsrPrecompileCRC */
#define CAN_VERSION_INFO_API STD_OFF
#define CAN_DEV_ERROR_DETECT STD_ON
#define CAN_PROD_ERROR_DETECT STD_ON
#define CAN_HARDWARE_CANCELLATION STD_ON
#define CAN_TIMEOUT_DURATION                 10000u
#define CAN_TX_PROCESSING                    CAN_INTERRUPT
#define CAN_RX_PROCESSING                    CAN_POLLING
#define CAN_BUSOFF_PROCESSING                CAN_INTERRUPT
#define CAN_WAKEUP_PROCESSING                CAN_INTERRUPT
#define CAN_LOOP_MAX                         5u
#define CAN_MULTIPLEXED_TX_MAX               1u
#define CAN_INTERRUPT_USED STD_ON
#define CAN_CANCEL_SUPPORT_API STD_ON
#define CAN_TRANSMIT_BUFFER STD_OFF
#define CAN_MULTIPLEXED_TRANSMISSION STD_OFF
#define CAN_HW_TRANSMIT_CANCELLATION STD_OFF
#define CAN_SLEEP_SUPPORT STD_ON
#define CAN_WAKEUP_SUPPORT STD_OFF
#define CAN_EXTENDED_STATE_MACHINE STD_OFF
#define CAN_BUSOFF_SUPPORT_API STD_OFF
#define CAN_GENERIC_PRECOPY STD_OFF
#define CAN_GENERIC_CONFIRMATION STD_OFF
#define CAN_SECURE_TEMP_BUFFER STD_OFF
#define CAN_MULTI_ECU_CONFIG STD_OFF
#define CAN_RX_FULLCAN_OBJECTS STD_ON
#define CAN_TX_FULLCAN_OBJECTS STD_ON
#define CAN_RX_BASICCAN_OBJECTS STD_ON
#define CAN_NESTED_INTERRUPTS STD_OFF
#define CAN_EXTENDED_ID STD_OFF
#define CAN_MIXED_ID STD_OFF
#define CAN_HW_LOOP_SUPPORT_API  STD_OFF
#define CAN_DEV_TIMEOUT_DETECT STD_OFF
#define CAN_INDIVIDUAL_PROCESSING STD_OFF
#define CAN_SUPPORT_MIXED_ID STD_OFF
/* -----------------------------------------------------------------------------
    &&&~ CanConfigSet Container Name
 ----------------------------------------------------------------------------- */

/* START of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */
#define CanConfigSet                         CanConfig
/* END of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */


#define CAN_RX_QUEUE STD_OFF
#define CAN_MULTIPLE_BASICCAN STD_OFF
#define CAN_ONE_CONTROLLER_OPTIMIZATION STD_OFF
#define CAN_DYNAMIC_FULLCAN_ID STD_ON
#define CAN_COMMON_CAN STD_OFF
/* START of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */
#if (CAN_PROD_ERROR_DETECT == STD_ON)
#ifndef CAN_E_TIMEOUT
#define CAN_E_TIMEOUT                        Dem_CAN_E_TIMEOUT
#endif

#endif

/* END of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */

#define CAN_PARTIAL_NETWORK STD_OFF
#define CAN_RAM_CHECK                        CAN_NONE
#define CAN_NOTIFY_ISSUE                     1
#define CAN_NOTIFY_MAILBOX                   2
#define CAN_OVERRUN_NOTIFICATION             CAN_NONE
#define CAN_MICROSAR_VERSION                 CAN_MSR30
#define CAN_REINIT_START  STD_OFF
#define CAN_GENERIC_PRETRANSMIT STD_OFF
#define CAN_IDENTICAL_ID_CANCELLATION STD_ON
/* ModuleIdentityDefine  HERE AFTER */
#define CAN_AMD_RUNTIME_MEASUREMENT STD_OFF
#define CAN_SILENT_CHECK STD_ON
#define C_DISABLE_GEN_HW_START_STOP_IDX
/* END of Checksum include for
  - DrvCan__baseAsrPrecompileCRC */


/* START of Checksum include for
  - DrvCan__baseAsrLinktimeCRC


START of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */
#define kCanNumberOfMaxUsedControllers       1u
#define kCanNumberOfUsedHwChannels           1u
#ifndef C_DRV_INTERNAL
#ifndef kCanNumberOfHwChannels
#define kCanNumberOfHwChannels               kCanNumberOfUsedHwChannels
#endif

#endif

#define C_ENABLE_OSEK_OS_INTCAT2
#define C_DISABLE_ISRVOID
#define CAN_GET_STATUS STD_ON
#define CAN_DRIVER                           1
#define CAN_APPL                             2
#define CAN_BOTH                             3
#define CAN_INTLOCK                          CAN_DRIVER
#define CAN_NONE                             0
#define CAN_MSR30                            30
#define CAN_MSR40                            40
#define CAN_DET                              1
/* END of Checksum include for
  - DrvCan__baseAsrLinktimeCRC


END of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */

/* START of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */
#define kCanNumberOfUsedTxCANObjects         7u
#ifndef C_DRV_INTERNAL
#ifndef kCanNumberOfChannels
#define kCanNumberOfChannels                 kCanNumberOfMaxUsedControllers
#endif

#endif

#define Can_CAN00                            0
#define Can_CanHardwareObject_0              0
#define Can_CanHardwareObject_1              1
#define Can_CanHardwareObject_2              2
#define Can_CanHardwareObject_3              3
#define Can_CanHardwareObject_4              4
#define Can_CanHardwareObject_5              5
#define Can_CanHardwareObject_6              6
#define Can_CanHardwareObject_7              8
#define Can_CanHardwareObject_8              9
#define Can_CanHardwareObject_9              10
#define Can_CanHardwareObject_10             11
#define Can_CanHardwareObject_11             12
#define Can_CanHardwareObject_12             13
#define Can_CanHardwareObject_13             14
#define Can_CanHardwareObject_14             15
#define Can_CanHardwareObject_15             16
#define Can_CanHardwareObject_16             17
/* END of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */

/* -----------------------------------------------------------------------------
    &&&~ Channel indices
 ----------------------------------------------------------------------------- */

/* START of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */
#define kCanPhysToLogChannelIndex_0          0
#define kCanNumberOfPhysChannels             1
/* END of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */


/* -----------------------------------------------------------------------------
    &&&~ Defines / Switches (Hw specific ) 
 ----------------------------------------------------------------------------- */

/* START of Checksum include for
  - DrvCan__baseAsrPrecompileCRC */
#define CAN_ENABLE_SLEEP_WAKEUP_GLOBAL       STD_OFF
/* END of Checksum include for
  - DrvCan__baseAsrPrecompileCRC */


/* -----------------------------------------------------------------------------
    &&&~ Types
 ----------------------------------------------------------------------------- */

/* START of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */
typedef VAR(uint8, TYPEDEF) Can_StateTransitionType;
typedef VAR(uint8, TYPEDEF) Can_ReturnType;
typedef VAR(uint8, TYPEDEF) Can_HwHandleType;
typedef VAR(sint8, TYPEDEF) Can_SignedHwHandleType;
/* START of Checksum include for
  - DrvCan__baseAsrPrecompileCRC */
typedef VAR(uint16, TYPEDEF) Can_IdType;
/* END of Checksum include for
  - DrvCan__baseAsrPrecompileCRC */

typedef uint8 Can_ControllerBaudrateConfigType;
typedef struct Can_ControllerConfigTypeTag
{
  Can_HwHandleType TxFullHandleStart;
  Can_HwHandleType TxFullHandleStop;
  Can_HwHandleType TxFullHandleMax;
  Can_HwHandleType TxBasicHandleStart;
  Can_HwHandleType TxBasicHandleStop;
  Can_HwHandleType TxBasicHandleMax;
  Can_HwHandleType UnusedHandleStart;
  Can_HwHandleType UnusedHandleStop;
  Can_HwHandleType UnusedHandleMax;
  Can_HwHandleType RxFullHandleStart;
  Can_HwHandleType RxFullHandleStop;
  Can_HwHandleType RxFullHandleMax;
  Can_HwHandleType RxBasicHandleStart;
  Can_HwHandleType RxBasicHandleStop;
  Can_HwHandleType RxBasicHandleMax;
  Can_HwHandleType HandleMax;
} Can_ControllerConfigType;
typedef struct Can_MailboxTypeTag
{
  Can_IdType IDValue;
  Can_HwHandleType HwHandle;
  uint8 MsgController;
  uint8 MailboxType;
  uint8 DLC_FIFO;
} Can_MailboxType;
typedef P2VAR(uint8, TYPEDEF, CAN_APPL_VAR) Can_SduPtrType;
typedef struct Can_PduTypeTag
{
  Can_IdType id;
  uint8 length;
  Can_SduPtrType sdu;
  PduIdType swPduHandle;
} Can_PduType;
typedef P2CONST(Can_ControllerConfigType, TYPEDEF, CAN_CONST_PBCFG) CanControllerConfig_TabPtrType;
typedef P2CONST(Can_MailboxType, TYPEDEF, CAN_CONST_PBCFG) CanMailbox_TabPtrType;
typedef P2CONST(uint8, TYPEDEF, CAN_CONST_PBCFG) CanInitObjectStartIndex_TabPtrType;
/* END of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */


/* START of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */
typedef P2CONST(uint16, TYPEDEF, CAN_CONST_PBCFG) CanInitBRP_RegPtrType;
typedef P2CONST(uint16, TYPEDEF, CAN_CONST_PBCFG) CanInitBitTimingPtrType;
typedef P2CONST(uint16, TYPEDEF, CAN_CONST_PBCFG) CanInitBasicMskPtrType;
typedef P2CONST(uint16, TYPEDEF, CAN_CONST_PBCFG) CanInitBasicMskLoPtrType;
typedef P2CONST(uint16, TYPEDEF, CAN_CONST_PBCFG) CanInitBasicCodPtrType;
typedef P2CONST(uint16, TYPEDEF, CAN_CONST_PBCFG) CanInitBasicCodLoPtrType;
typedef P2CONST(uint16, TYPEDEF, CAN_CONST_PBCFG) CanInitBasic1MskLoPtrType;
typedef P2CONST(uint16, TYPEDEF, CAN_CONST_PBCFG) CanInitBasic1CodPtrType;
typedef P2CONST(uint16, TYPEDEF, CAN_CONST_PBCFG) CanInitBasic1CodLoPtrType;
typedef P2CONST(uint32, TYPEDEF, CAN_CONST_PBCFG) CanBasisAdrPtrType;
typedef P2CONST(uint32, TYPEDEF, CAN_CONST_PBCFG) interruptSrcPtrType;
typedef P2CONST(uint32, TYPEDEF, CAN_CONST_PBCFG) vimClrRegPtrType;
typedef P2CONST(uint32, TYPEDEF, CAN_CONST_PBCFG) vimSetRegPtrType;
typedef P2CONST(uint8, TYPEDEF, CAN_CONST_PBCFG) CanNumberOfMsgObjPtrType;
typedef struct Can_ConfigTypeTag
{
  uint8 CanControllerMax; /* Base_Generated */
  uint32 ConfigId; /* Base_Generated */
  CanControllerConfig_TabPtrType CanControllerConfig_TabPtr; /* Base_Generated */
  CanMailbox_TabPtrType CanMailbox_TabPtr; /* Base_Generated */
  CanInitObjectStartIndex_TabPtrType CanInitObjectStartIndex_TabPtr; /* Base_Generated */
  uint16 CanErrata22Iterations;
  CanInitBRP_RegPtrType CanInitBRP_RegPtr;
  CanInitBitTimingPtrType CanInitBitTimingPtr;
  CanInitBasicMskPtrType CanInitBasicMskPtr;
  CanInitBasicMskLoPtrType CanInitBasicMskLoPtr;
  CanInitBasicCodPtrType CanInitBasicCodPtr;
  CanInitBasicCodLoPtrType CanInitBasicCodLoPtr;
  CanBasisAdrPtrType CanBasisAdrPtr;
  interruptSrcPtrType interruptSrcPtr;
  vimClrRegPtrType vimClrRegPtr;
  vimSetRegPtrType vimSetRegPtr;
  CanNumberOfMsgObjPtrType CanNumberOfMsgObjPtr;
  uint16 Can_BaseDll_GeneratorVersion;
  uint16 Can_PlatformDll_GeneratorVersion;
  uint16 FinalMagicNumber;
} Can_ConfigType;
typedef VAR(uint32, CAN_VAR_NOINIT) tCanLLCanIntOld;
/* PRQA S 0750 2 */ /* MD_Can_0750 */
typedef union can_dataTag
{
  uint8 ucData[8];
  uint16 usData[4];
  uint32 ulData[2];
} can_data;
typedef volatile struct
{         
  uint16   Id[2];            
  uint16   Dlc;               
  uint16   reserved;         
  can_data  Data;              
} tTxMsgObj;
typedef volatile struct
{
  uint16   Id[2];           
  uint16   Dlc;              
  can_data  Data;              
  uint16   MessageCntrl;      
} tRxMsgObj;
/* END of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */

/* START of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */
/* -----------------------------------------------------------------------------
    &&&~ DEM Error Handling
 ----------------------------------------------------------------------------- */

#define CAN_START_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

extern CONST(Dem_EventIdType, CAN_CONST) canDemErrorTimeout;
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"




/* -----------------------------------------------------------------------------
    &&&~ Extern Declarations
 ----------------------------------------------------------------------------- */

#define CAN_START_SEC_PBCFG_ROOT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

extern CONST(Can_ConfigType, CAN_CONST_PBCFG) CanConfig;
#define CAN_STOP_SEC_PBCFG_ROOT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


#define CAN_START_SEC_PBCFG
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

extern CONST(Can_ControllerConfigType, CAN_CONST_PBCFG) CanControllerConfig[kCanNumberOfUsedHwChannels]; /* PRQA S 3684 */ /* MD_Can_3684 */

extern CONST(Can_MailboxType, CAN_CONST_PBCFG) CanMailbox[17]; /* PRQA S 3684 */ /* MD_Can_3684 */

extern CONST(uint8, CAN_CONST_PBCFG) CanInitObjectStartIndex[kCanNumberOfMaxUsedControllers+1]; /* PRQA S 3684 */ /* MD_Can_3684 */

#define CAN_STOP_SEC_PBCFG
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

extern VAR(PduIdType, CAN_VAR_NOINIT) CanActiveSendPdu[kCanNumberOfUsedTxCANObjects]; /* PRQA S 3684 */ /* MD_Can_3684 */
extern VAR(uint8, CAN_VAR_NOINIT) CanActiveSendState[kCanNumberOfUsedTxCANObjects]; /* PRQA S 3684 */ /* MD_Can_3684 */
extern VAR(uint8, CAN_VAR_NOINIT) lastInitObject[kCanNumberOfMaxUsedControllers]; /* PRQA S 3684 */ /* MD_Can_3684 */
extern VAR(Can_SignedHwHandleType, CAN_VAR_NOINIT) canTxOffsetHwToLog[kCanNumberOfMaxUsedControllers]; /* PRQA S 3684 */ /* MD_Can_3684 */
extern VAR(tCanLLCanIntOld, CAN_VAR_NOINIT) canCanInterruptOldStatus[kCanNumberOfUsedHwChannels]; /* PRQA S 3684 */ /* MD_Can_3684 */
extern volatile VAR(uint8, CAN_VAR_NOINIT) canInterruptCounter[kCanNumberOfMaxUsedControllers];
#if (CAN_WAKEUP_SUPPORT == STD_ON)
extern volatile VAR(boolean, CAN_VAR_NOINIT) canIsWakeup[kCanNumberOfMaxUsedControllers];
#endif

extern volatile VAR(boolean, CAN_VAR_NOINIT) canIsBusOff[kCanNumberOfMaxUsedControllers];
extern volatile VAR(uint8, CAN_VAR_NOINIT) canStatus[kCanNumberOfMaxUsedControllers];
#if (CAN_HARDWARE_CANCELLATION == STD_ON) || (CAN_MICROSAR_VERSION == CAN_MSR40)
extern volatile VAR(uint32, CAN_VAR_NOINIT) canLoopTimeout[kCanNumberOfMaxUsedControllers][CAN_LOOP_MAX];
#endif

#if (CAN_HARDWARE_CANCELLATION == STD_ON)
extern  VAR(uint8, CAN_VAR_NOINIT) canIsHardwareCanceled[kCanNumberOfMaxUsedControllers];
#endif

#if ((CAN_DEV_ERROR_DETECT == STD_ON) || defined(CAN_ENABLE_SELECTABLE_PB))
extern P2CONST(Can_ControllerConfigType, CAN_VAR_NOINIT, CAN_CONST_PBCFG) canControllerConfigPtr[kCanNumberOfUsedHwChannels]; /* PRQA S 3684 */ /* MD_Can_3684 */
#endif

#if ((CAN_HW_TRANSMIT_CANCELLATION == STD_ON) && (CAN_TRANSMIT_BUFFER == STD_ON))
extern VAR(uint8, CAN_VAR_NOINIT) canTxBasicDataBuffer[kCanNumberOfMaxUsedControllers][CAN_MULTIPLEXED_TX_MAX][8]; /* PRQA S 3684 */ /* MD_Can_3684 */
#endif


#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


#define CAN_START_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

extern CONST(EcuM_WakeupSourceType, CAN_CONST) CanWakeupSourceRef[1]; /* PRQA S 3684 */ /* MD_Can_3684 */
/* -----------------------------------------------------------------------------
    &&&~ Checksum
 ----------------------------------------------------------------------------- */

extern CONST(Can_ControllerBaudrateConfigType, CAN_CONST) Can_ControllerBaudrateConfig[3]; /* PRQA S 3684 */ /* MD_Can_3684 */



#define CAN_STOP_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


/* -----------------------------------------------------------------------------
    &&&~ Extern Declarations ( Hw specific )
 ----------------------------------------------------------------------------- */

/* START of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */
extern CONST(uint16, CAN_CONST) CanInitBRP_Reg[1];
extern CONST(uint16, CAN_CONST) CanInitBitTiming[1];
extern CONST(uint16, CAN_CONST) CanInitBasicMsk[1];
extern CONST(uint16, CAN_CONST) CanInitBasicMskLo[1];
extern CONST(uint16, CAN_CONST) CanInitBasicCod[1];
extern CONST(uint16, CAN_CONST) CanInitBasicCodLo[1];
extern CONST(uint32, CAN_CONST) CanBasisAdr[1];
extern CONST(uint32, CAN_CONST) interruptSrc[1];
extern CONST(uint32, CAN_CONST) vimClrReg[1];
extern CONST(uint32, CAN_CONST) vimSetReg[1];
extern CONST(uint8, CAN_CONST) CanNumberOfMsgObj[1];
extern VAR(tRxMsgObj, CAN_VAR_NOINIT) rxMsgObj[1];
extern VAR(tTxMsgObj, CAN_VAR_NOINIT) txMsgObj[kCanNumberOfUsedTxCANObjects];
extern VAR(uint8, CAN_VAR_NOINIT) status_sleep[1];
extern VAR(uint8, CAN_VAR_NOINIT) status_stop[1];
extern VAR(uint16, CAN_VAR_NOINIT) status_busoff[1];
extern VAR(uint32, CAN_VAR_NOINIT) normal_mode[1];
extern VAR(uint16, CAN_VAR_NOINIT) canllStatus[1];
extern VAR(uint32, CAN_VAR_NOINIT) txsendflag[4][1];
/* END of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */




/* END of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */

/* START of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */
#define CAN_CRC_CHECK                        STD_OFF
#define CAN_PRECOMPILE_CRC                   (uint32) 0xA28B161Du
/* END of Checksum exclude for
  - DrvCan__baseAsrPrecompileCRC */


/* END of Checksum include for
  - DrvCan__baseAsrPrecompileCRC */

#endif /* CAN_CFG_H */
