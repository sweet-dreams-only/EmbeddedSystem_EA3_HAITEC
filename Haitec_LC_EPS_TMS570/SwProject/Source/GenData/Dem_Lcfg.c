/* -----------------------------------------------------------------------------
  Filename:    Dem_Lcfg.c
  Description: Toolversion: 11.08.02.01.30.01.24.00.00.00
               
               Serial Number: CBD1300124
               Customer Info: Nxtr Automotive Corporation
                              Package: MSR_Vector_SLP3
                              Micro: TMS570LS30376USC
                              Compiler: TexasInstruments ccs 4.9.2
               
               
               Generator Fwk   : GENy 
               Generator Module: Dem
               
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

  Generated by , 2015-04-16  10:27:55
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
    &&&~ Includes
 ----------------------------------------------------------------------------- */

/* START of Checksum exclude for
  - Diag_AsrDemLinktimeCRC */
/* configuration, interrupt handling implementations differ from the 
 * source identification define used here. The naming 
 * schemes for those files can be taken from this list: 
 * 
 * Dem.c:         DEM_SOURCE
 * Dem_Lcfg.c:    DEM_LCFG_SOURCE
 * Dem_PBcfg.c:   DEM_PBCFG_SOURCE */
#define DEM_LCFG_SOURCE
#include "Dem.h"
#include "Dem_Lcfg.h"
#include "Dem_PBcfg.h"
/* DEM used with RTE */
#include "Rte_Dem.h"
#include "NvM.h"
#if (DEM_USE_NVM == STD_ON)
# if defined ( NVM_VENDOR_ID )
#   if ( NVM_VENDOR_ID == DEM_VENDOR_ID )
/* BSW004: AUTOSAR version check - DEM requires API NvM_SetRamBlockStatus() */
#   if (  (NVM_AR_MAJOR_VERSION == (0x02u)) && (NVM_AR_MINOR_VERSION == (0x01u)) )  /* Specification 2.1.x is part of AUTOSAR Release R2.0, R2.1 */
#   elif ((NVM_AR_MAJOR_VERSION == (0x02u)) && (NVM_AR_MINOR_VERSION == (0x02u)) )  /* Specification 2.2.x is part of AUTOSAR Release R3.0 Rev 0001-006 */
#   elif ((NVM_AR_MAJOR_VERSION == (0x02u)) && (NVM_AR_MINOR_VERSION == (0x03u)) )  /* Specification 2.3.x is part of AUTOSAR Release R3.0 Rev 7, R3.1 */
#   else
#    error "Dem: Incompatible AUTOSAR version of NvM."
#   endif
#  endif
# endif
#endif
/* END of Checksum exclude for
  - Diag_AsrDemLinktimeCRC */


/* -----------------------------------------------------------------------------
    &&&~ Version Check
 ----------------------------------------------------------------------------- */

/* START of Checksum exclude for
  - Diag_AsrDemLinktimeCRC */
#if (DIAG_ASRDEM_GENTOOL_GENY_MAJOR_VERSION != 0x03)
#error "Dem_Lcfg.c : Incompatible DIAG_ASRDEM_GENTOOL_GENY_MAJOR_VERSION in generated File!"
#endif

#if (DIAG_ASRDEM_GENTOOL_GENY_MINOR_VERSION != 0x03)
#error "Dem_Lcfg.c : Incompatible DIAG_ASRDEM_GENTOOL_GENY_MINOR_VERSION in generated File!"
#endif

#if (DIAG_ASRDEM_GENTOOL_GENY_PATCH_VERSION != 0x00)
#error "Dem_Lcfg.c : Incompatible DIAG_ASRDEM_GENTOOL_GENY_PATCH_VERSION in generated File!"
#endif

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
CONSTP2CONST(uint8, DEM_APPL_CONST, DEM_CONST) Dem_LCfg_GeneratedVersion_SW_02_14_00 =  & Dem_NeedDemLibVersion_SW_02_14_xx; /* MISRA-C:2004 Rule 8.8: An external object or function shall be declared in one and only one file. */ /* PRQA S 3408 */
CONSTP2CONST(uint8, DEM_APPL_CONST, DEM_CONST) Dem_LCfg_GeneratedOem_DEM_Vector =  & Dem_NeedDemLibOem_DEM_Vector; /* MISRA-C:2004 Rule 8.8: An external object or function shall be declared in one and only one file. */ /* PRQA S 3408 */
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* END of Checksum exclude for
  - Diag_AsrDemLinktimeCRC */


/* -----------------------------------------------------------------------------
    &&&~ Consistency Check
 ----------------------------------------------------------------------------- */

/* START of Checksum exclude for
  - Diag_AsrDemLinktimeCRC */
/* DEM used with RTE */
#if (DEM_GET_DTCOFEVENT_WRONG_DTCKIND != RTE_E_DiagnosticMonitor_DEM_GET_DTCOFEVENT_WRONG_DTCKIND)
# error "Consistency check in Dem_Lcfg.c failed! Different return values for GET_DTCOFEVENT_WRONG_DTCKIND in Dem_Types.h vs. RTE generated header"
#endif
#if (DEM_GET_DTCOFEVENT_WRONG_EVENTID != RTE_E_DiagnosticMonitor_DEM_GET_DTCOFEVENT_WRONG_EVENTID)
# error "Consistency check in Dem_Lcfg.c failed! Different return values for GET_DTCOFEVENT_WRONG_EVENTID in Dem_Types.h vs. RTE generated header"
#endif
/* END of Checksum exclude for
  - Diag_AsrDemLinktimeCRC */


/* -----------------------------------------------------------------------------
    &&&~ Dem data buffers
 ----------------------------------------------------------------------------- */

/* START of Checksum include for
  - Diag_AsrDemLinktimeCRC */
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
#include "MemMap.h"
VAR(Dem_NonVolatileDataType, DEM_APPL_DATA) Dem_NvData;
VAR(uint8, DEM_APPL_DATA) Dem_PreFFBuffer[DEM_PRESTORE_FF_BUFFER_SIZE];
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
#include "MemMap.h"

#define DEM_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"
VAR(Dem_OperationCycleStateType, DEM_VAR_NOINIT) Dem_OperationCycleState[DEM_NUMBER_OF_OPERATION_CYCLES];
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"

#define DEM_START_SEC_VAR_FAST_8BIT
#include "MemMap.h"
VAR(Dem_DtcInternalStatusType, DEM_VAR_NOINIT_FAST) Dem_DtcInternalStatus[DEM_NUMBER_OF_EVENTS+1];
#define DEM_STOP_SEC_VAR_FAST_8BIT
#include "MemMap.h"

#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(uint32, DEM_VAR_NOINIT) Dem_EnableConditionState;
VAR(Dem_AQElementType, DEM_VAR_NOINIT) Dem_ActionQueue[DEM_BSW_ERROR_BUFFER_SIZE + DEM_ADD_ERROR_BUFFER_SIZE];
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"


/* END of Checksum include for
  - Diag_AsrDemLinktimeCRC */


/* -----------------------------------------------------------------------------
    &&&~ Linktime specific config data tables
 ----------------------------------------------------------------------------- */

/* START of Checksum include for
  - Diag_AsrDemLinktimeCRC */
#define DEM_START_SEC_CONST_LCFG
#include "MemMap.h"
CONST(Dem_DemConfigurationType, DEM_CONST) Dem_DemConfiguration = 
{
  1
};
CONST(uint8, DEM_CONST) Dem_LinkTimeProperty[] = 
{
  0, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
CONST(uint8, DEM_CONST) Dem_InitMonitorIndexTable[] = 
{
  0, 0, 0
};
CONST(Dem_InitMonitorFPtrType, DEM_CONST) Dem_InitMonitorFPtrTable[] = 
{
  NULL_PTR
};
CONST(Dem_TriggerDTCFunctionType, DEM_CONST) Dem_TriggerDTCFunctionTable[] = 
{
  NULL_PTR
};
CONST(Dem_TriggerFunctionType, DEM_CONST) Dem_TriggerFunctionTable[] = 
{
  NULL_PTR
};
CONST(uint8, DEM_CONST) Dem_IndicatorCountTable[] = 
{
  0, 1, 1
};
CONST(Dem_IndicatorIdType, DEM_CONST) Dem_IndicatorIdTable[] = 
{
  EpasFailed, EpasFailed, EpasFailed, EpasFailed, 
  EpasFailed, EpasFailed, EpasFailed, EpasFailed, 
  EpasFailed, EpasFailed, EpasFailed, EpasFailed, 
  EpasFailed, EpasFailed
};
CONST(Dem_IndicatorStatusType, DEM_CONST) Dem_IndicatorStatusTable[] = 
{
  DEM_INDICATOR_CONTINUOUS, DEM_INDICATOR_CONTINUOUS, DEM_INDICATOR_CONTINUOUS, DEM_INDICATOR_CONTINUOUS, 
  DEM_INDICATOR_CONTINUOUS, DEM_INDICATOR_CONTINUOUS, DEM_INDICATOR_CONTINUOUS, DEM_INDICATOR_CONTINUOUS, 
  DEM_INDICATOR_CONTINUOUS, DEM_INDICATOR_CONTINUOUS, DEM_INDICATOR_CONTINUOUS, DEM_INDICATOR_CONTINUOUS, 
  DEM_INDICATOR_CONTINUOUS, DEM_INDICATOR_CONTINUOUS
};
CONST(Dem_DTCGroupKindType, DEM_CONST) Dem_EventGroupTable[] = 
{
  0, 4, 16
};
CONST(Dem_DIDLookupTableType, DEM_CONST) Dem_DIDLookupTable[] = 
{
  
  {
    0xFFFF, NULL_PTR
  }
};
CONST(Dem_GetExtDataRecordFPtrType, DEM_CONST) Dem_GetExtDataRecordListTable[] = 
{
  NULL_PTR
};
CONST(Dem_NvMBlockIdType, DEM_CONST) Dem_NvramBlockIdTable[] = 
{
  NvM_NVM_BLOCK_DEM
};
CONST(Dem_DTCGroupMappingType, DEM_CONST) Dem_DTCGroupTable[] = 
{
  
  {
    DEM_DTC_GROUPKIND_POWERTRAIN, DEM_DTC_GROUP_POWERTRAIN_DTCS
  }, 
  
  {
    DEM_DTC_GROUPKIND_CHASSIS, DEM_DTC_GROUP_CHASSIS_DTCS
  }, 
  
  {
    DEM_DTC_GROUPKIND_BODY, DEM_DTC_GROUP_BODY_DTCS
  }, 
  
  {
    DEM_DTC_GROUPKIND_NETWORK_COM, DEM_DTC_GROUP_NETWORK_COM_DTCS
  }, 
  
  {
    DEM_DTC_GROUPKIND_ALL_DTCS, DEM_DTC_GROUP_ALL_DTCS
  }
};
#define DEM_STOP_SEC_CONST_LCFG
#include "MemMap.h"
/* END of Checksum include for
  - Diag_AsrDemLinktimeCRC */


/* -----------------------------------------------------------------------------
    &&&~ Linktime specific config data values
 ----------------------------------------------------------------------------- */

/* START of Checksum include for
  - Diag_AsrDemLinktimeCRC */
#define DEM_START_SEC_CONST_LCFG
#include "MemMap.h"

CONST(uint8, DEM_CONST) Dem_StatusAvailabilityMask = DEM_STATUS_AVAILABILITY_MASK;
CONST(uint16, DEM_CONST) Dem_MaxSizeOfSnapshotRecord = DEM_MAX_SNAPSHOT_RECORD_SIZE;
CONST(uint16, DEM_CONST) Dem_MaxSizeOfExtdataRecord = DEM_MAX_EXTDATA_RECORD_SIZE;
CONST(uint16, DEM_CONST) Dem_NumberOfOperationCycles = DEM_NUMBER_OF_OPERATION_CYCLES;
CONST(uint16, DEM_CONST) Dem_NumberOfIndicators = DEM_NUMBER_OF_INDICATORS;
CONST(uint16, DEM_CONST) Dem_PriMemElementSize = sizeof(Dem_NvData.primaryStack[0]);
CONST(uint16, DEM_CONST) Dem_SizeofPreFFBuffer = DEM_PRESTORE_FF_BUFFER_SIZE;
CONST(Dem_DtcChronoRefType, DEM_CONST) Dem_MaxPriMemElementCount = DEM_MAX_NUMBER_EVENT_ENTRY;
CONST(Dem_EventIdType, DEM_CONST) Dem_MaxCountOfEventId = DEM_NUMBER_OF_EVENTS;
CONST(uint8, DEM_CONST) Dem_SnapshotsPerDTC = DEM_SNAPSHOTS_PER_DTC;
CONST(uint8, DEM_CONST) Dem_FirstOverwritableSnapshot = DEM_FIRST_SNAPSHOT_TO_OVERWRITE;
CONST(uint8, DEM_CONST) Dem_ReportErrorBufferSize = DEM_BSW_ERROR_BUFFER_SIZE;
CONST(uint16, DEM_CONST) Dem_ActionQueueCount = sizeof(Dem_ActionQueue)/sizeof(Dem_AQElementType);
CONST(uint8, DEM_CONST) Dem_DTCGroupMappingCount = sizeof(Dem_DTCGroupTable)/sizeof(Dem_DTCGroupMappingType);
CONST(uint8, DEM_CONST) Dem_NvramBlockIdCount = sizeof(Dem_NvramBlockIdTable)/sizeof(Dem_NvMBlockIdType);
CONST(uint8, DEM_CONST) Dem_SizeofEventIdType = sizeof(Dem_EventIdType);

CONSTP2VAR(Dem_NonVolatileDataType, DEM_CONST, DEM_APPL_DATA) Dem_NvDataPtr = &Dem_NvData;
CONSTP2VAR(uint8, DEM_CONST, DEM_APPL_DATA) Dem_ConsistencyPatternPtr = &Dem_NvData.consistencyPattern[0];
CONSTP2VAR(uint8, DEM_CONST, DEM_APPL_DATA) Dem_PrimaryStackPtr = &Dem_NvData.primaryStack[0][0];
CONSTP2VAR(Dem_ChronoPriMemType, DEM_CONST, DEM_APPL_DATA) Dem_ChronoPriMemPtr = Dem_NvData.chronoPriMem;
CONSTP2VAR(Dem_DtcStatusByteType, DEM_CONST, DEM_APPL_DATA) Dem_DtcStatusBytePtr = Dem_NvData.dtcStatusByte;
CONSTP2VAR(Dem_DtcChronoRefType, DEM_CONST, DEM_APPL_DATA) Dem_ChronoPriMemUsedPtr =  & Dem_NvData.chronoPriMemUsed;
CONSTP2VAR(sint8, DEM_CONST, DEM_APPL_DATA) Dem_FaultDetectionCounterPtr = &Dem_NvData.dtcFaultDetectionCounter[0];
CONSTP2VAR(uint8, DEM_CONST, DEM_APPL_DATA) Dem_DtcAgingCounterPtr = &Dem_NvData.dtcAgingCounter[0];
CONSTP2VAR(Dem_EventIdType, DEM_CONST, DEM_APPL_DATA) Dem_FirstFailedEventIdPtr =  & Dem_NvData.firstFailedEvent;
CONSTP2VAR(Dem_EventIdType, DEM_CONST, DEM_APPL_DATA) Dem_FirstConfirmedEventIdPtr =  & Dem_NvData.firstConfirmedEvent;
CONSTP2VAR(Dem_EventIdType, DEM_CONST, DEM_APPL_DATA) Dem_MostRecentFailedEventIdPtr =  & Dem_NvData.mostRecentFailedEvent;
CONSTP2VAR(Dem_EventIdType, DEM_CONST, DEM_APPL_DATA) Dem_MostRecentConfmdEventIdPtr =  & Dem_NvData.mostRecentConfirmedEvent;
CONSTP2VAR(uint8, DEM_CONST, DEM_VAR_NOINIT) Dem_OperationCycleStatePtr = &Dem_OperationCycleState[0];
CONSTP2VAR(uint8, DEM_CONST, DEM_APPL_DATA) Dem_TerminatingPatternPtr = &Dem_NvData.terminatingPattern[0];

#define DEM_STOP_SEC_CONST_LCFG
#include "MemMap.h"

/* END of Checksum include for
  - Diag_AsrDemLinktimeCRC */


/* -----------------------------------------------------------------------------
    &&&~ Access Functions to the configurable data
 ----------------------------------------------------------------------------- */

/* START of Checksum include for
  - Diag_AsrDemLinktimeCRC */
#define DEM_START_SEC_CODE
#include "MemMap.h"

#define DEM_FLAGTOBOOLEAN(flag)              ((boolean)(((flag) != 0) ? TRUE : FALSE))
/* Maximum number of supported events, excluding EventId 0. Basically defines the size of Dem_EventIdType. */
FUNC(Dem_EventIdType, DEM_CODE) DemCfg_GetMaxCountOfEventId(void)
{
  return Dem_MaxCountOfEventId;
}


/* Translation format (bitcoded): 0x01 ==  ISO15031_6, 0x02 == ISO14229_1 */
FUNC(uint8, DEM_CODE) DemCfg_GetDTCTranslationFormat(void)
{
  return Dem_DemConfiguration.DTCTranslationFormat;
}


/* Get number of configured operation cycles */
FUNC(uint16, DEM_CODE) DemCfg_GetMaxCountOfOperationCycle(void)
{
  return Dem_NumberOfOperationCycles;
}


/* Number of snapshots ("FirstConfirmed" + one or more "MostRecent") for each event */
FUNC(uint8, DEM_CODE) DemCfg_GetCountOfSnapshotsPerDTC(void)
{
  return Dem_SnapshotsPerDTC;
}


/* Number of first confirmed snapshot */
FUNC(uint8, DEM_CODE) DemCfg_GetFirstOccurredRecordNr(void)
{
  return 0x01;
}


/* Max. required buffer for storing all snapshots of the 'largest' event */
FUNC(uint16, DEM_CODE) DemCfg_GetMaxSnapshotRecordSize(void)
{
  return Dem_MaxSizeOfSnapshotRecord;
}


/* Count of FirstConfirmed snapshots */
FUNC(uint8, DEM_CODE) DemCfg_Get1stOverwrtSnapshotIndex(void)
{
  return Dem_FirstOverwritableSnapshot;
}


/* Max. required buffer for storing all extended data of the 'largest' event */
FUNC(uint16, DEM_CODE) DemCfg_GetMaxExtdataRecordSize(void)
{
  return Dem_MaxSizeOfExtdataRecord;
}


/* Number of events, that can simultanously be stored in the PrimaryMemory */
FUNC(Dem_DtcChronoRefType, DEM_CODE) DemCfg_GetMaxCountOfPriMemStack(void)
{
  return Dem_MaxPriMemElementCount;
}


/* Find bitcoded group number (Dem_DTCGroupKindType). Result == 0 means the group number was not found. */
FUNC(Dem_DTCGroupKindType, DEM_CODE) Dem_MapGroupNumberToGroupKind(Dem_DTCType DTCGroupNumber)
{
  VAR(Dem_DTCGroupKindType, AUTOMATIC) returnValue = 0;
  VAR(uint8, AUTOMATIC) i;
  for (i=0; i < Dem_DTCGroupMappingCount; ++i)
  {
    if (DTCGroupNumber == Dem_DTCGroupTable[i].DTCnumber)
    {
      returnValue = Dem_DTCGroupTable[i].GroupKind;
      break;
    }
  }
  return returnValue;
}


/* Map EventId to DTC number (Dem_DTCType). Success iff 0 < Result 0 <= 0x00FFFFFFuL . Result == 0xFFFFFFFFuL: no DTC number available (internal event). */
FUNC(Dem_DTCType, DEM_CODE) DemCfg_GetDTCnumber(Dem_EventIdType EventId)
{
  VAR(Dem_DTCType, AUTOMATIC) returnValue;
  returnValue = (((Dem_DTCType) Dem_DTCNumberTable[EventId] << 8) | Dem_DTC_FTB_Table[EventId]);
  if ( returnValue == 0x00FFFFFFuL )
  {
    returnValue = 0xFFFFFFFFuL;
  }
  return returnValue;
}


/* Initialization value for enable conditions. Bit position corresponds to enable condition index. (Bit0 is init value for EC0) */
FUNC(uint32, DEM_CODE) DemCfg_GetEnableConditionInitValue(void)
{
  return 0xFFFFFFFF;
}



/* Map EventId to a InitMonitorForEvent callback function pointer. */
FUNC(Dem_InitMonitorFPtrType, DEM_CODE) DemCfg_GetInitMonitorFPtr(Dem_EventIdType EventId)
{
  return Dem_InitMonitorFPtrTable[Dem_InitMonitorIndexTable[Dem_LinkTimeProperty[EventId]]];
}


/* Map EventId to the first Index into the list of TriggerOnDTCStatusChanged callbacks. */
FUNC(Dem_TriggerOnDTCIndexType, DEM_CODE) DemCfg_GetFirstTriggerOnDTC(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 0;
}


/* Map EventId to the number of corresponding TriggerOnDTCStatusChanged callbacks. */
FUNC(uint8, DEM_CODE) DemCfg_GetCountOfTriggerOnDTC(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 0;
}


/* Map EventId to the first Index into the list of TriggerOnEventStatusChanged callbacks. */
FUNC(Dem_TriggerOnEventIndexType, DEM_CODE) DemCfg_GetFirstTriggerOnEvent(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 0;
}


/* Map EventId to number of TriggerOnEventStatusChanged callbacks. */
FUNC(uint8, DEM_CODE) DemCfg_GetCountOfTriggerOnEvent(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 0;
}


/* Map EventId to priority. */
FUNC(Dem_EventPriorityType, DEM_CODE) DemCfg_GetEventPriority(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 0;
}


/* Map EventId to severity. */
FUNC(Dem_DTCSeverityType, DEM_CODE) DemCfg_GetDTCSeverity(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 0;
}


/* Map EventId to its healing cycle. See Dem_Types.h for operation cycle IDs. */
FUNC(uint8, DEM_CODE) DemCfg_GetAgingCycleId(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 0;
}


/* Map EventId to its operation cycle. See Dem_Types.h for healing cycle IDs. */
FUNC(uint8, DEM_CODE) DemCfg_GetOperationCycleId(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 0;
}


/* Maps EventId to <Number of Healing Cycles> - 1 */
FUNC(uint8, DEM_CODE) DemCfg_GetNumberOfAgingCycles(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 0;
}


/* Map EventId to relevant enable conditions. Set bit means enable condition must be active for the Event. */
FUNC(uint8, DEM_CODE) DemCfg_GetEnableConditionMask(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 0;
}


/* Map EventId to the number of relevant indicators. */
FUNC(uint8, DEM_CODE) DemCfg_GetCountOfIndicatorIds(Dem_EventIdType EventId)
{
  return Dem_IndicatorCountTable[Dem_LinkTimeProperty[EventId]];
}


/* Map IndIdIdx to IndicatorId. Sum up DemCfg_GetCountOfIndicatorIds(0) .. DemCfg_GetCountOfIndicatorIds(EventID-1) to get first index for EventId. */
FUNC(Dem_IndicatorIdType, DEM_CODE) DemCfg_GetIndicatorId(uint16 IndIdIdx)
{
  return Dem_IndicatorIdTable[IndIdIdx];
}


/* Map IndIdIdx to indicator status. Sum up DemCfg_GetCountOfIndicatorIds(0) .. DemCfg_GetCountOfIndicatorIds(EventID-1) to get first index for EventId. */
FUNC(Dem_IndicatorStatusType, DEM_CODE) DemCfg_GetIndicatorStatusType(uint16 IndIdIdx)
{
  return Dem_IndicatorStatusTable[IndIdIdx];
}


/* Map EventId to a ViewID. */
FUNC(Dem_ViewIdType, DEM_CODE) DemCfg_GetViewId(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 255;
}


/* Map EventId to functional unit. */
FUNC(uint8, DEM_CODE) DemCfg_GetFunctionalUnit(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 0;
}


/* Map EventId to flag value. */
FUNC(boolean, DEM_CODE) DemCfg_GetDtcSupportWarningIndicator(Dem_EventIdType EventId)
{
  return DEM_FLAGTOBOOLEAN(Dem_EventFlagsTable[Dem_PostBuildProperty[EventId]] & 1);
}


/* Map EventId to flag value. */
FUNC(boolean, DEM_CODE) DemCfg_GetDtcSuppressFlag(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return FALSE;
}


/* Map EventId to flag value. */
FUNC(boolean, DEM_CODE) DemCfg_GetIsAgingAllowed(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return FALSE;
}


/* Test if EventId uses Jump-Up-to-Zero, used for counter based debouncing. */
FUNC(uint8, DEM_CODE) DemCfg_GetIsPredebJumpPreFailed(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 1;
}


/* Test if EventId uses Jump-Down-to-Zero, used for counter based debouncing. */
FUNC(uint8, DEM_CODE) DemCfg_GetIsPredebJumpPrePassed(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 0;
}


/* Map EventId to CountUp step size, used for counter based debouncing. */
FUNC(uint8, DEM_CODE) DemCfg_GetPredebStepsizePreFailed(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 1;
}


/* Map EventId to CountDown step size, used for counter based debouncing. */
FUNC(uint8, DEM_CODE) DemCfg_GetPredebStepsizePrePassed(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 1;
}


/* Map EventId to DTC kind. Dem_DTCKindType is defined in dem_types.h */
FUNC(Dem_DTCKindType, DEM_CODE) DemCfg_GetDTCKind(Dem_EventIdType EventId)
{
  return Dem_DtcKindTable[Dem_PostBuildProperty[EventId]];
}


/* Map EventId to supported origin (bitcoded). Primary == 0x02, Mirror == 0x04, Permanent == 0x08, Secondary == 0x10. */
FUNC(uint8, DEM_CODE) DemCfg_GetDTCOrigin(Dem_EventIdType EventId)
{
  return Dem_EventDestinationTable[Dem_PostBuildProperty[EventId]];
}


/* Map EventId to DTC group index. OBD == 0x01, P == 0x02, C == 0x04, B == 0x08, U == 0x10, ALL == 0xFF */
FUNC(Dem_DTCGroupKindType, DEM_CODE) DemCfg_GetDTCGroupKind(Dem_EventIdType EventId)
{
  return Dem_EventGroupTable[Dem_LinkTimeProperty[EventId]];
}


/* Map EventId to the Index of the first DID of its snapshot records. */
FUNC(uint16, DEM_CODE) DemCfg_GetFirstSnapshot(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 0;
}


/* Map EventId to the total number of DIDs across all of its snapshot records. */
FUNC(uint8, DEM_CODE) DemCfg_GetCountOfSnapshotDIDs(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 0;
}


/* Map SsRecIdx to the DID number. Get first SsRecIdx either per Event using DemCfg_GetFirstSnapshot(EventId) or per Snapshot by DemCfg_GetSnapshotRecordDIDIndex(ssRecordIndex) */
FUNC(uint16, DEM_CODE) DemCfg_GetSnapshotDID(uint16 SsRecIdx)
{
  DEM_IGNORE_UNUSED_ARG(SsRecIdx);
  return 0;
}


/* Map SsRecIdx to a list of DID numbers. Get first SsRecIdx either per Event using DemCfg_GetFirstSnapshot(EventId) or per Snapshot by DemCfg_GetSnapshotRecordDIDIndex(ssRecordIndex) */
FUNC(Dem_RecordDIDAddrType, DEM_CODE) DemCfg_GetSnapshotDIDAddr(uint16 SsRecIdx)
{
  DEM_IGNORE_UNUSED_ARG(SsRecIdx);
  return 0;
}


/* Map SsRecIdx to the size of the DID (in byte). Get first SsRecIdx either per Event using DemCfg_GetFirstSnapshot(EventId) or per Snapshot by DemCfg_GetSnapshotRecordDIDIndex(ssRecordIndex) */
FUNC(Dem_DataRecordSizeType, DEM_CODE) DemCfg_GetSnapshotDIDDataSize(uint16 SsRecIdx)
{
  DEM_IGNORE_UNUSED_ARG(SsRecIdx);
  return 0;
}


/* Map EventId to first Index into snapshot table. */
FUNC(uint16, DEM_CODE) DemCfg_GetFirstSnapshotRecNumber(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 0;
}


/* Map EventId to number of snapshot records. */
FUNC(uint8, DEM_CODE) DemCfg_GetCountOfSnapshotRecNumbers(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 0;
}


/* Map ssRecordIndex to number of the snapshot record. The first valid ssRecordIndex is DemCfg_GetFirstSnapshotRecNumber(EvenId). */
FUNC(uint8, DEM_CODE) DemCfg_GetSnapshotRecordNumber(uint16 ssRecordIndex)
{
  DEM_IGNORE_UNUSED_ARG(ssRecordIndex);
  return 255;
}


/* Map ssRecordIndex to the size of the snapshot record (in byte). The first valid ssRecordIndex is DemCfg_GetFirstSnapshotRecNumber(EvenId). */
FUNC(uint16, DEM_CODE) DemCfg_GetSnapshotRecordDIDsSize(uint16 ssRecordIndex)
{
  DEM_IGNORE_UNUSED_ARG(ssRecordIndex);
  return 0;
}


/* Map ssRecordIndex to the number of DIDs in the snapshot record. The first valid ssRecordIndex is DemCfg_GetFirstSnapshotRecNumber(EvenId). */
FUNC(uint8, DEM_CODE) DemCfg_GetSnapshotRecordNumberOfDIDs(uint16 ssRecordIndex)
{
  DEM_IGNORE_UNUSED_ARG(ssRecordIndex);
  return 0;
}


/* Map ssRecordIndex to first Index into DID table. The first valid ssRecordIndex is DemCfg_GetFirstSnapshotRecNumber(EvenId). */
FUNC(uint16, DEM_CODE) DemCfg_GetSnapshotRecordDIDIndex(uint16 ssRecordIndex)
{
  DEM_IGNORE_UNUSED_ARG(ssRecordIndex);
  return 0;
}


/* Map EventId to the offset into the prestored snapshot buffer. */
FUNC(uint16, DEM_CODE) DemCfg_PrestoreFFBufStartOffset(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 0;
}


/* Map EventId to size of its prestored snapshot data. */
FUNC(uint16, DEM_CODE) DemCfg_PrestoreFFBufSize(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 0;
}


/* Map EventId to the end offset into the prestored snapshot buffer. */
FUNC(uint16, DEM_CODE) DemCfg_PrestoreFFBufEndOffset(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 0;
}


/* Map EventId to Index of first Extended Data Record. Index is valid in Dem_Record* tables. */
FUNC(uint16, DEM_CODE) DemCfg_GetFirstExtendedRecord(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 0;
}


/* Map EventId to number of Extended Data Records. */
FUNC(uint16, DEM_CODE) DemCfg_GetCountOfCurrentExtendedRecord(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 0;
}


/* Map ExtRecIdx to RecordId of an Extended Data Record. (First) valid ExtRecIdx per EventId is returned by DemCfg_GetFirstExtendedRecord. */
FUNC(uint8, DEM_CODE) DemCfg_GetExtendedRecordNumber(uint16 ExtRecIdx)
{
  DEM_IGNORE_UNUSED_ARG(ExtRecIdx);
  return 0;
}


/* Map ExtRecIdx to size [byte] of an Extended Data Record. (First) valid ExtRecIdx per EventId is returned by DemCfg_GetFirstExtendedRecord. */
FUNC(uint16, DEM_CODE) DemCfg_GetExtendedRecordNumberDataSize(uint16 ExtRecIdx)
{
  DEM_IGNORE_UNUSED_ARG(ExtRecIdx);
  return 0;
}


/* Map ExtRecIdx to size [byte] of an Extended Data Record, in MirrorMemory. (First) valid ExtRecIdx per EventId is returned by DemCfg_GetFirstExtendedRecord. */
FUNC(uint16, DEM_CODE) DemCfg_GetMirExtendedRecordNumberDataSize(uint16 ExtRecIdx)
{
  DEM_IGNORE_UNUSED_ARG(ExtRecIdx);
  return 0;
}


/* Map ExtRecIdx to function pointer used to get the data. (First) valid ExtRecIdx per EventId is returned by DemCfg_GetFirstExtendedRecord. */
FUNC(uint16, DEM_CODE) DemCfg_GetExtendedRecordFuncRef(uint16 ExtRecIdx)
{
  DEM_IGNORE_UNUSED_ARG(ExtRecIdx);
  return 0;
}


/* Map EventId to valid identity mask. Can be multiple identity (only one bit set) or VSG mode (multiple bits set). */
FUNC(uint32, DEM_CODE) DemCfg_GetEventIdentityVariant(Dem_EventIdType EventId)
{
  DEM_IGNORE_UNUSED_ARG(EventId);
  return 0;
}



#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/* END of Checksum include for
  - Diag_AsrDemLinktimeCRC */


