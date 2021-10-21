/********************************************************************************************************************
|    File Name: CANIF.C
|
|  Description: Implementation of the AUTOSAR CAN Interface
|--------------------------------------------------------------------------------------------------------------------
|               C O P Y R I G H T
|--------------------------------------------------------------------------------------------------------------------
| Copyright (c) 1996-2012 by Vctr Informatik GmbH.       All rights reserved.
|
| This software is copyright protected and proprietary
| to Vctr Informatik GmbH. Vctr Informatik GmbH
| grants to you only those rights as set out in the
| license conditions. All other rights remain with
| Vctr Informatik GmbH.
|
|--------------------------------------------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|--------------------------------------------------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| Ard          Thomas Arnold             Vctr Informatik GmbH
| Rna          Ruediger Naas             Vctr Informatik GmbH
| Seu          Eugen Stripling           Vctr Informatik GmbH
| Bir          Holger Birke              Vctr Informatik GmbH
|--------------------------------------------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|--------------------------------------------------------------------------------------------------------------------
| Date        Version   Author  Description
| ----------  --------  ------  -------------------------------------------------------------------------------------
| 2005-09-12  0.01      Ard       firstimplementation
| 2006-01-18  0.02      Ard     - Fix issue when sending queued PDUs
| 2006-02-06  0.03      Ard     - Fix queue handling
| 2006-02-08  0.04      Ard     - Use global interrupt disable routines from osek
| 2006-02-09  0.05      Ard     - Inform DET if Can_Write returns CAN_BUSY when sending from queue
| 2006-02-10  0.06      Ard     - Change to STOP mode in BusOff notification before notifying upper layer
| 2006-03-30  0.07      Ard     - Change Version of CanIf_Types
| 2006-04-05  0.08      Ard     - Remove controller state check in CanIf_Init()
| 2006-04-24  0.09      Ard     - Add missing preprocessor switches at Det_ReportError call
| 2006-05-24  2.00      Ard     - AUTOSAR 2.0
| 2006-05-31  2.01      Ard     - Support DET, RxIndication function type 2 (TP)
|                                 rename CANIF_CS_STOP mode
|                                 add missing channel mode
| 2006-06-21  2.02      Ard     - Add CanIf_InitMemory function
| 2006-06-22  2.03      Ard     - Changes in channel mode state machine
|                                 Change API of CanIf_GetChannelMode and CanIf_GetControllerMode
| 2006-06-23  2.04      Ard     - Modifiy init functions
| 2006-06-26  2.05      Ard     - Changes in channel mode state machine
|                                 Remove PDU specific de/activation of DLC-Check
|                                 Add global initialization structure
| 2006-07-03  2.06      Ard     - Change parameter value of WakeupNotification
| 2006-07-03  2.07      Ard     - Remove EcuM and ComM header includes
| 2006-07-05  2.08      Ard     - Remove Det calls which will never be reached
|                               - Change API of CanIf_Init
|                               - Changes in Version history and Version defines
| 2006-07-12  2.09      Ard     - Remove compile warnings
|                                 changes in CanIf.h and CanIf_Types.h
| 2006-09-05  2.10      Ard     - Remove MISRA warnings
| 2006-09-18  2.11      Ard     - Add Tx polling mode
| 2006-11-17  2.12      Ard     - Support postbuild configurations
| 2006-12-20  2.13      Ard     - Adapt access to generated data
|                                 Add BusOff polling
| 2007-02-20  2.14      Ard     - Abandon reception in BasicCAN if no BasicCAN messages and ranges are configured
| 2007-02-22  2.15      Ard     - ESCAN00019715: Add dynamic Tx DLC support
|                               - ESCAN00019714: Change ControllerWakeup callback function name
| 2007-03-01  2.16      Ard     - ESCAN00019796: Change type of local variable to PduLengthType
| 2007-03-20  2.17      Ard     - ESCAN00020010: Remove spurious DET error when transmitting queued messages
| 2007-03-30  2.18      Ard     - Support VStdLib copy algorithms (configurable)
| 2007-03-12  3.00      Ard     - AUTOSAR 2.1
| 2007-09-03  3.01      Ard     - ESCAN00022117: Fix compile warning due to inconsistent function declaration
|                               - ESCAN00022291: Fix memory qualifiers 
|                               - ESCAN00022292: Add support for modified CanIf state machine
|                               - ESCAN00022119: Add additionally check of generated data
|                               - ESCAN00022479: Fix wake up notification handling 
|                               - ESCAN00022491: Remove compile warning in CanIf_SetWakeupEvent
| 2007-10-12  3.02      Ard     - ESCAN00022751: Fix accidentially raised DET error in CanIf_ConvertPduId
| 2007-11-05  3.03      Ard     - ESCAN00023167: Introcude binary search
|                                 ESCAN00023168: Support extended IDs
|                                 ESCAN00023165: Apply fix for Can_Init API
|                                 ESCAN00023199: Encapsulate Dummy statements with precompiler switch
|                                 ESCAN00023502: Modify CanIf_InitController API 
|                                 ESCAN00024165: Change handling of DLC for advanced indication function
| 2008-02-22  4.00      Ard     - ESCAN00024947: AUTOSAR 3.0
| 2008-04-10  4.01      Ard     - ESCAN00026007: MISRA compliance + Minor changes
|                                 ESCAN00026212: Implement Library version check
|                                 ESCAN00026257: Fix spelling of include filenames
|                                 ESCAN00025964: Access DEM errors via generated constants
| 2008-05-13  4.02      Ard     - ESCAN00026849: Fix unexpected DET Error in case of activated CANIF_CANCEL_SUPPORT_API
| 2008-05-14  4.03      Ard     - ESCAN00026647: Introduce extended generator checks
|                                 ESCAN00026946: Fix transmission of wrong CanID in case of  CANIF_DYNAMIC_TX_DLC == STD_OFF
|                                 ESCAN00026971: Fix unexpected behaviour after DET error is raised in CanIf_Transmit
| 2008-07-28  4.04      Ard     - ESCAN00028771: Add BrsTime support for runtime measurement
|                                 ESCAN00027656: Support wake up validation
|                                 ESCAN00025740: Remove Beta Disclaimer
|                                 ESCAN00029138: Fix post-build data access to TransceiverUpToLow map table
|                                 ESCAN00029110: Remove channel specific bus off notification function
|                                 ESCAN00029314: Check version of generated data with pre-processor
|                                 ESCAN00029315: Change version definitions
| 2008-09-10  4.05      Ard     - ESCAN00029908: Rework Critical sections
|                                 ESCAN00029825: Change dummy Statement handling
|                                 ESCAN00029828: Support precompile and link-time CRC check
| 2008-11-06  4.06      Ard     - ESCAN00031108: Avoid compiler warnings
|                                 ESCAN00031111: Avoid preprocessor warnings
|                                 ESCAN00031182: Remove Compiler warning due to pointless statement in CanIf_Init()
|                                 ESCAN00031206: Add pre-processor error message if ReadRxPduData API is activated
|                                 ESCAN00031640: Raise DET error in case of inconsistent transceiver configuration
|                                 ESCAN00031731: Unbalanced call of CanIf_LeaveCritical
|                                 ESCAN00031732: Fix unexpected Tx confirmation of canceled PDUs (CanIf_CancelTransmit)
| 2009-02-19  4.07      Ard     - ESCAN00032430: Change referenced generator version to correct value
|                                 ESCAN00032434: Remove compiler warning due to unused variable in CanIf_HlIndication
|                                 ESCAN00032207: Fix compile error "Invalid pointer conversion" in CanIf_SetPduMode
|                                 ESCAN00032330: Code improvements (e.g. runtime, comments, ...)
|                                 ESCAN00033078: Support state transition "CANIF_CS_STARTED" to "CANIF_CS_SLEEP"
|                                 ESCAN00032595: Support transceiver state transition to normal during wake up 
|                                 ESCAN00033608: Support new requirements (DEM to DET, ApplDlcErrorNotification)
| 2009-04-09  4.08      Ard     - ESCAN00034547: Support new requirements (TxPduId Mapping)
| 2009-06-17  4.09      Rna     - ESCAN00034553: Provide Hash Search algorithm
| 2009-07-06  4.10      Bir     - ESCAN00034841: Confirmation without critical section
| 2009-07-23  4.11      Rna     - ESCAN00036101: pre-processor checks for building the library
| 2009-08-03            Rna       ESCAN00035031: Compiler error: "Wrong pointer cast"
| 2009-08-24  4.11.01   Rna     - ESCAN00037328: DET reports that CANIF is not initialized 
| 2009-09-01  4.11.02   Rna     - ESCAN00037493: Some PDUs are not received by the ECU
| 2009-09-29  4.11.03   Rna     - ESCAN00037987: Some PDUs are not received by the ECU
| 2009-10-22            Rna     - ESCAN00037935: Compile error in CanIf_cfg.h (changes only in CanIf_Compiler_Cfg.inc)
| 2009-12-18  4.11.04   Rna     - ESCAN00039858: Uppler layer, for example TP, receives wrong data from CanDriver/CanInterface
| 2010-01-11  4.11.05   Rna     - ESCAN00039888: CanIf_HlIndication() incompatible near pointer cast (changes only for CanIf_Types.h)
| 2010-01-20  4.12.00   Rna     - ESCAN00040264: Support 8 and 16 bit CanIf_HwHandleType for variable Hrh
| 2010-02-10            Rna       ESCAN00040966: Code optimization in case of only one channel used
| 2010-02-19            Rna       ESCAN00040119: CANIF code size optimization at function CanIf_SetPduMode()
| 2010-03-04  4.13.00   Rna     - ESCAN00041353: Support dynamic Tx objects
| 2010-04-01            Rna       ESCAN00041879: Compiler warnings:"condition is always false" and "undefined enum value" occur
| 2010-04-14            Rna       ESCAN00041366: Runtime of CanIf_Transmit is too high
| 2010-05-03  4.13.01   Rna     - ESCAN00042675: Reference to Generator changed
| 2010-07-20  4.14.00   Rna     - ESCAN00044166: Support Common CAN
| 2010-06-28  4.15.00   Rna     - ESCAN00043633: Changes regarding interrupt locks
| 2010-07-14            Rna       ESCAN00042905: compiler warning occurs "controller" was set but never used
| 2010-07-14            Rna       ESCAN00043501: Support Tx Bitqueue
| 2010-08-09            Rna       ESCAN00044608: MISRA compliance changes
| 2010-09-27  4.15.01   Rna     - ESCAN00045607: Compile error: "identifier channel is undefined"
| 2010-09-28  4.16.00   Rna     - ESCAN00045687: Changes regarding one channel optimization
| 2010-09-29            Rna       ESCAN00045645: Compiler warning:  undefined enum value
| 2010-09-29            Rna       ESCAN00045644: Compiler warning: condition is always true in CanIf_SetChannelMode
| 2010-10-04            Rna       ESCAN00045749: Support "Teilnetzbetrieb"
| 2010-12-06            Rna       ESCAN00046249: Adapt AUTOSAR version check
| 2011-01-31            Seu       ESCAN00048317: When using Tx-bitqueue CAN-messages are not send in the order: high-priority (first) low-priority(last)
| 2011-04-02            Rna       ESCAN00048457: Compiler warning: Variable was defined but never referenced
| 2011-02-14            Rna       ESCAN00048657: Undefined type "CanTransmitHandle"
| 2012-09-20  4.16.01   Rna       ESCAN00061139: Data inversion occurs: older data set is send after newer one
| 2012-09-20            Rna       ESCAN00060317: Compiler error: Variables CanIf_TxQueueCounter and Controller undefined
| 2012-11-27  4.16.02   Seu       ESCAN00051563: Remove the AUTOSAR Release Version Check
| 2012-11-29  4.16.03   Seu       ESCAN00063422: The API "CanIf_GetVersionInfo" returns an unexpected SW patch version
|*******************************************************************************************************************/

#define CANIF_SOURCE

/*******************************************************************************************************************/
/*  Include files                                                                                                  */
/*******************************************************************************************************************/

#include "CanIf.h"

#include "CanIf_Cbk.h"

/* Required as CAN API is called from CanIf.c not from generated data */
# include "Can.h"
# include "Can_Cfg.h"

#if !defined (CANIF_AVOID_VSTDLIB_COPY)
/* For VStdLib / CanIf.h/CanIf_Cfg.h has to be included before       */
/* possibility to explicitely avoid usage of VStdLib copy algorithm  */
# include "v_cfg.h"
# include "v_def.h"

# if defined (VGEN_ENABLE_VSTDLIB)
/* Check if VStdlib is system                                        */
#  if defined (VSTD_HL_USE_VSTD_RAMMEMCPY)
/* Copy algorithm is available                                       */
#   define CANIF_USES_VSTDLIB_COPY      STD_ON
#  endif
# endif
#endif


#if (CANIF_TRCV_HANDLING == STD_ON)
# include "CanIf_CanTrcv.h"
#endif


#if (CANIF_PROD_ERROR_DETECT == STD_ON)
# include "Dem.h"
#endif

#if (CANIF_DEV_ERROR_DETECT == STD_ON)
# include "Det.h"
#endif


#if !defined (V_SUPPRESS_EXTENDED_VERSION_CHECK)
# include "v_ver.h"
#endif


/*******************************************************************************************************************/
/*  Version check                                                                                                  */
/*******************************************************************************************************************/


/* CanIf.c version definition (module version) */
#define CANIF_MAJOR_VERSION   0x04
#define CANIF_MINOR_VERSION   0x16
#define CANIF_PATCH_VERSION   0x03



/* CanIf_cbk.h version check */
#if (CANIF_CBK_MAJOR_VERSION != 0x04)
# error "Source and Header files are inconsistent!"
#endif

#if (CANIF_CBK_MINOR_VERSION != 0x03)
# error "Source and Header files are inconsistent!"
#endif

#if (CANIF_CBK_PATCH_VERSION != 0x00)
# error "Source and Header files are inconsistent!"
#endif

/* CanIf_types.h version check */
#if (CANIF_TYPES_MAJOR_VERSION != 0x04)
# error "Source and Header files are inconsistent!"
#endif

#if (CANIF_TYPES_MINOR_VERSION != 0x12)
# error "Source and Header files are inconsistent!"
#endif

#if (CANIF_TYPES_PATCH_VERSION != 0x00)
# error "Source and Header files are inconsistent!"
#endif

/* CanIf.h version check */
#if (CANIF_API_MAJOR_VERSION != 0x04)
# error "Source and Header files are inconsistent!"
#endif

#if (CANIF_API_MINOR_VERSION != 0x16)
# error "Source and Header files are inconsistent!"
#endif

#if (CANIF_API_PATCH_VERSION != 0x03)
# error "Source and Header files are inconsistent!"
#endif

/*******************************************************************************************************************/
/*  Compatibility / Defaults                                                                                       */
/*******************************************************************************************************************/

#if !defined (CANIF_PARTIAL_NETWORK)
# define CANIF_PARTIAL_NETWORK                        STD_OFF
#endif

#if !defined (CANIF_DYNAMIC_TX_DLC)
# define CANIF_DYNAMIC_TX_DLC                         STD_ON
#endif

#if !defined (CANIF_EXTENDED_STATE_MACHINE)
# define CANIF_EXTENDED_STATE_MACHINE                 STD_OFF
#endif

#if !defined (CANIF_SEARCH_ALGORITHM)
# define CANIF_SEARCH_ALGORITHM                       CANIF_LINEAR
#endif

#if !defined (CANIF_RX_PASS_STATIC_DLC)
# define CANIF_RX_PASS_STATIC_DLC                     STD_OFF
#endif

#if !defined (CANIF_LIBRARY_SUPPORT)
# define CANIF_LIBRARY_SUPPORT                        STD_OFF
#endif

#if !defined (CANIF_SUPPRESS_CANIF_GENDATA_VERSION_CHECK)
# define CANIF_SUPPRESS_CANIF_GENDATA_VERSION_CHECK   STD_OFF
#endif

#if !defined (CANIF_WAKEUP_VALIDATION)
# define CANIF_WAKEUP_VALIDATION                      STD_OFF
#endif

#if !defined (CANIF_WAKEUP_VALID_ALL_RX_MSGS)
# define CANIF_WAKEUP_VALID_ALL_RX_MSGS               STD_OFF
#endif

#if !defined (CANIF_USES_VSTDLIB_COPY)
# define CANIF_USES_VSTDLIB_COPY                      STD_OFF
#endif

#if !defined (CANIF_DEM_REPORT_DLC_FAILED)
/* Default AUTOSAR behaviour */
# define CANIF_DEM_REPORT_DLC_FAILED                  STD_ON
#endif

#if !defined (CANIF_USER_DLC_ERROR_NOTIFICATION)
# define CANIF_USER_DLC_ERROR_NOTIFICATION            STD_OFF
#endif

#if !defined (CANIF_DEMTODET_E_FULL_TX_BUFFER)
# define CANIF_DEMTODET_E_FULL_TX_BUFFER              STD_OFF
#endif

#if !defined (CANIF_DEMTODET_E_STOPPED)
# define CANIF_DEMTODET_E_STOPPED                     STD_OFF
#endif


#if !defined(CANIF_ONE_CONTROLLER_OPTIMIZATION)
# define CANIF_ONE_CONTROLLER_OPTIMIZATION            STD_OFF
#endif


#if !defined(CANIF_SETDYNAMICTXID_API)
# define CANIF_SETDYNAMICTXID_API                     STD_OFF
#endif 


#if !defined(CANIF_OPTIMIZE_TX_WITH_SHORT_PIA_GAP)
# define CANIF_OPTIMIZE_TX_WITH_SHORT_PIA_GAP         STD_ON
#endif


#if !defined (CANIF_TRCV_WAKEUPSTATETRANSITION)
/* See CanIf_Types.h */
#endif


/* Feature validation */
#if defined (V_EXTENDED_BUILD_LIB_CHECK)
# if (CANIF_LIBRARY_SUPPORT != STD_ON)
#  error "Activate Library Solution in PreConfig file! (Attribute: If_AsrIfCan_IsLibrarySolution)"
# endif
#endif

#if defined (V_EXTENDED_BUILD_LIB_CHECK)
# if !defined (CANIF_SUPPRESS_TRANSCEIVERMAPPING_BUILDLIBCHECK)   
#  if (CANIF_TRCV_HANDLING == STD_ON)  /* If Trcv Handling is active, we need the mapping (for PB)*/ 
#   if (CANIF_TRCV_MAPPING != STD_ON)
#    error "It is strongly suggested to activate the feature 'Transceiver Mapping' in a library delivery."
#   endif
#  endif
# endif
#endif

#if defined (V_EXTENDED_BUILD_LIB_CHECK)
# if (CANIF_CONFIG_VARIANT  == CANIF_CFGVAR_PRECOMPILETIME)
#  error "Config variant: "precompile config" not possible for a library delivery" 
# endif
#endif
  


/* Wakeup Validation not allowed with Extended State machine */
#if (CANIF_WAKEUP_VALIDATION == STD_ON)
# if (CANIF_EXTENDED_STATE_MACHINE == STD_ON)
#  error "Invalid configuration: Wake up validation (CANIF_WAKEUP_VALIDATION) is activated with extended state machine (CANIF_EXTENDED_STATE_MACHINE)"
# endif
#endif

/* WakeUp Validation without WakeUp support not acceptable */
#if (CANIF_WAKEUP_VALIDATION == STD_ON)
# if (CANIF_WAKEUP_SUPPORT == STD_OFF)
#  error "Invalid configuration: Wake up validation (CANIF_WAKEUP_VALIDATION) is activated without activating wake up support (CANIF_WAKEUP_SUPPORT)"
# endif
#endif


/* ESCAN00031206 - ReadRxPduDataAPI currently not suggested to be enabled */
#if (CANIF_READRXPDUDATA_API == STD_ON)
# error "Invalid configuration: Activation of the feature ReadRxPduDataAPI is currently not suggested"
#endif


#if !defined (V_USE_DUMMY_STATEMENT)
# error "The define V_USE_DUMMY_STATEMENT shall be defined either in Compiler_Cfg.h or as parameter for the Compiler"
#endif


/*******************************************************************************************************************/
/*  Version check (external modules)                                                                               */
/*******************************************************************************************************************/

/* ESCAN00051563 - all ASR checks removed */

/* Check AR Version of the CAN Driver */

/* Check AR Version of the ECU Manager */

/* Check AR Version of the Development Error Tracer */

/* Check AR Version of the Diagnostics Event Manager */



/*******************************************************************************************************************/
/*  Defines / data types / structs / unions                                                                        */
/*******************************************************************************************************************/


#define CANIF_MAGIC_NUMBER                      0xDEAF
#define CANIF_GENDATA_VERSION                   0x0600

#define CANIF_GENTOOL_GENY_MAJOR_VERSION_REF    0x03
#define CANIF_GENTOOL_GENY_MINOR_VERSION_REF    0x14


#if (CANIF_LIBRARY_SUPPORT == STD_ON) 
# define CANIF_INDIRECT_E_FULL_TX_BUFFER        CanIf_DemError_TxBufferFull
# define CANIF_INDIRECT_E_STOPPED               CanIf_DemError_Stopped
# define CANIF_INDIRECT_E_INVALID_DLC           CanIf_DemError_InvalidDlc
# define CANIF_INDIRECT_E_SLEEP_REQ_FAILED      CanIf_DemError_SleepReqFailed
#else
# define CANIF_INDIRECT_E_FULL_TX_BUFFER        CANIF_E_FULL_TX_BUFFER
# define CANIF_INDIRECT_E_STOPPED               CANIF_E_STOPPED
# define CANIF_INDIRECT_E_INVALID_DLC           CANIF_E_INVALID_DLC
# define CANIF_INDIRECT_E_SLEEP_REQ_FAILED      CANIF_E_SLEEP_REQ_FAILED
#endif

#if (CANIF_EXTENDEDID_SUPPORT == STD_ON)
#define CANIF_STOP_FLAG        0x40000000
#define CANIF_RANGE_FLAG       0x20000000
#else
#define CANIF_STOP_FLAG        0x4000
#define CANIF_RANGE_FLAG       0x2000
#endif


#if !defined ( V_SUPPRESS_EXTENDED_VERSION_CHECK ) || (CANIF_CRC_CHECK == STD_ON)
# define CanIf_GeneratorCompatibilityError()      EcuM_GeneratorCompatibilityError((uint16) CANIF_MODULE_ID, (uint8) 0)
#endif


#if (CANIF_PROD_ERROR_DETECT == STD_ON)
# define CanIf_Dem_ReportError(EventId)           ((void)Dem_ReportErrorStatus((EventId), DEM_EVENT_STATUS_FAILED))
# define CanIf_Dem_ReportPassed(EventId)          ((void)Dem_ReportErrorStatus((EventId), DEM_EVENT_STATUS_PASSED))
#else
# define CanIf_Dem_ReportError(EventId)
# define CanIf_Dem_ReportPassed(EventId)
#endif

#if (CANIF_DEV_ERROR_DETECT == STD_ON)
# define CanIf_Det_ReportError(APIID, ErrorCode)  (Det_ReportError(CANIF_MODULE_ID, 0, (APIID), (ErrorCode)))
#else
# define CanIf_Det_ReportError(APIID, ErrorCode)
#endif

/* ParameterList: uint8 Hrh, PduIdType PduId, P2CONST(uint8, AUTOMATIC, CANIF_CBK_DRV_VAR) CanSduPtr, uint8 CanDlc, Can_IdType CanId */
#if (CANIF_SUPPORT_NMOSEK_INDICATION == STD_ON)
#define CanIf_Indirect_HlIndication(hrh, pduid, cansduptr, candlc, canid)     CanIf_HlIndication((hrh), (pduid), (cansduptr), (candlc), (canid))
#else
#define CanIf_Indirect_HlIndication(hrh, pduid, cansduptr, candlc, canid)     CanIf_HlIndication((hrh), (pduid), (cansduptr), (candlc))
#endif


#if (CANIF_ONE_CONTROLLER_OPTIMIZATION==STD_ON)
# define CANIF_CHANNEL_CANTYPE_FIRST 
# define CANIF_CHANNEL_CANTYPE_ONLY             void
# define CANIF_CHANNEL_CANPARA_ONLY     
# define CANIF_CHANNEL_CANPARA_FIRST     
# define CanIf_Controller_Value                 0
# define CANIF_CHANNEL_CANTYPE_LOCAL
# define CANIF_WUCHANNEL_CANTYPE_LOCAL
# define CanIf_Controller_Value_Local           0
# define CanIf_WU_Controller_Value_Local        0
# define CANIF_CFG_GENERIC_EMAXCONTROLLER       1
# define CANIF_CFG_TX_ECONTROLLER               0
# define CANIF_CFG_TX_ECONTROLLER_X             0
#else
# define CANIF_CHANNEL_CANTYPE_FIRST            uint8 Controller,
# define CANIF_CHANNEL_CANTYPE_ONLY             uint8 Controller
# define CANIF_CHANNEL_CANPARA_ONLY             Controller
# define CANIF_CHANNEL_CANPARA_FIRST            Controller,
# define CanIf_Controller_Value                 Controller
# define CANIF_CHANNEL_CANTYPE_LOCAL            uint8 controller;
# define CANIF_WUCHANNEL_CANTYPE_LOCAL          uint8 wuController;
# define CanIf_Controller_Value_Local           controller
# define CanIf_WU_Controller_Value_Local        wuController
# define CANIF_CFG_GENERIC_EMAXCONTROLLER       CANIF_CFG_GENERIC(eMaxController)
# define CANIF_CFG_TX_ECONTROLLER               CANIF_CFG_TX(CanTxPduId, eController)
# define CANIF_CFG_TX_ECONTROLLER_X             CANIF_CFG_TX(PduId, eController)
#endif



#if defined (CANIF_ENABLE_SELECTABLE_PB)
  
# define CANIF_CFG                               (CanIf_Configuration)

# define CANIF_CFG_GENERIC(field)                (CanIf_Configuration->field)
# define CANIF_CFG_CONTROLLER(index, field)      (CanIf_ControllerConfiguration[(index)]->field)
# define CANIF_CFG_RX(index, field)              (CanIf_Configuration->eRxPduConfig[(index)].field)

# define CANIF_CFG_RX_MASK(index)                (CanIf_Configuration->eRxPduMask[(index)])
# define CANIF_CFG_RX_ID(index)                  (CanIf_Configuration->eRxPduId[(index)])

# define CANIF_CFG_TX(index, field)              (CanIf_Configuration->eTxPduConfig[(index)].field)
# define CANIF_CFG_TX_QUEUEINDEX(index)          (CanIf_Configuration->eTxPduQueueIndex[(index)])
# define CANIF_CFG_MAILBOX(index, field)         (CanIf_Configuration->eMailBoxConfig[(index)].field)

# define CANIF_CFG_WAKEUP(index, field)          (CanIf_Configuration->eWakeUpConfig[(index)].field)


# define CANIF_CFG_CONVERTPDU(index)             (CanIf_Configuration->eNPB2CanIfPduId[(index)])
# define CANIF_CFG_TRCVUPTOLOWMAP(index, field)  (CanIf_Configuration->eTransceiverMap[(index)].field)
# define CANIF_CFG_CTRLTOTRCVINDEXMAP(index)     (CanIf_Configuration->eControllerToTrcvMap[(index)])
# define CANIF_CFG_TXPDUMAP(index)               (CanIf_Configuration->eTxPduMap[(index)])

# define CANIF_CFG_RXDHRANDOMNUMBER1(index)      (CanIf_Configuration->eCanIf_RxDHRandomNumber1[(index)])
# define CANIF_CFG_RXDHRANDOMNUMBER2(index)      (CanIf_Configuration->eCanIf_RxDHRandomNumber2[(index)])
# define CANIF_CFG_RXDHADJUST(index)             (CanIf_Configuration->eCanIf_RxDHAdjust[(index)]) 
# define CANIF_CFG_RXDHADJUSTCOUNT               (CanIf_Configuration->eCanIf_RxDHAdjustcount) 
# define CANIF_CFG_MAX_RXPDUHANDLE               (CanIf_Configuration->eMaxRxPDUHandle) 
# define CANIF_CFG_STAT2DYN_INDIRECTION(index)   (CanIf_Configuration->eCanIf_TxPduStatic2DynamicIndirection[(index)]) 
# define CANIF_CFG_TXQUEUE_STARTINDEX(index)     (CanIf_Configuration->eCanIf_TxQueueStartIndex[(index)])
# define CANIF_CFG_TXQUEUE_PADBITS(index)        (CanIf_Configuration->eCanIf_TxQueuePadBits[(index)])
# define CANIF_CFG_WU_TXPDU_FILTER_ACTIVE(index) (CanIf_Configuration->eCanIf_WUTxPDU_Filter[(index)])
# define CANIF_CFG_WU_TXPDU_HANDLE(index)        (CanIf_Configuration->eCanIf_PnWakeupTxPduHandle[(index)])


/* # define CANIF_CFG_MAGIC()                       (*(CanIf_Configuration->eMagicNumber)) */


#else /* CANIF_ENABLE_SELECTABLE_PB */
/* Don't use () in macros -> Compiler */
# define CANIF_CFG                               (&CanIf_Config)
# define CANIF_CFG_GENERIC(field)                (CanIf_Config.field)
# define CANIF_CFG_CONTROLLER(index, field)      (CanIf_ControllerConfig[(index)].field)

# define CANIF_CFG_RX(index, field)              (CanIf_RxPduConfig[(index)].field)
# define CANIF_CFG_RX_MASK(index)                (CanIf_RxPduMask[(index)])
# define CANIF_CFG_RX_ID(index)                  (CanIf_RxPduId[(index)])


# define CANIF_CFG_TX(index, field)              (CanIf_TxPduConfig[(index)].field)
# define CANIF_CFG_TX_QUEUEINDEX(index)          (CanIf_TxPduQueueIndex[(index)])
# define CANIF_CFG_MAILBOX(index, field)         (CanIf_MailBoxConfig[(index)].field)

# define CANIF_CFG_WAKEUP(index, field)          (CanIf_WakeUpConfig[(index)].field)

# define CANIF_CFG_CONVERTPDU(index)             (CanIf_NPB2CanIfPduId[(index)])
# define CANIF_CFG_TRCVUPTOLOWMAP(index, field)  (CanIf_TransceiverUpToLowMap[(index)].field)
# define CANIF_CFG_CTRLTOTRCVINDEXMAP(index)     (CanIf_ControllerToTransceiverMap[(index)])
# define CANIF_CFG_TXPDUMAP(index)               (CanIf_TxPduMap[(index)])

# define CANIF_CFG_RXDHRANDOMNUMBER1(index)      (CanIf_RxDHRandomNumber1[(index)])
# define CANIF_CFG_RXDHRANDOMNUMBER2(index)      (CanIf_RxDHRandomNumber2[(index)])
# define CANIF_CFG_RXDHADJUST(index)             (CanIf_RxDHAdjust[(index)])
# define CANIF_CFG_RXDHADJUSTCOUNT               (CanIf_Config.eCanIf_RxDHAdjustcount) 
# define CANIF_CFG_MAX_RXPDUHANDLE               (CanIf_Config.eMaxRxPDUHandle)
# define CANIF_CFG_STAT2DYN_INDIRECTION(index)   (CanIf_Config.eCanIf_TxPduStatic2DynamicIndirection[(index)]) 
# define CANIF_CFG_TXQUEUE_STARTINDEX(index)     (CanIf_Config.eCanIf_TxQueueStartIndex[(index)])
# define CANIF_CFG_TXQUEUE_PADBITS(index)        (CanIf_Config.eCanIf_TxQueuePadBits[(index)])
# define CANIF_CFG_WU_TXPDU_FILTER_ACTIVE(index) (CanIf_Config.eCanIf_WUTxPDU_Filter[(index)])
# define CANIF_CFG_WU_TXPDU_HANDLE(index)        (CanIf_Config.eCanIf_PnWakeupTxPduHandle[(index)])


/* # define CANIF_CFG_MAGIC()                     (CanIf_MagicNumber) */

#endif /* CANIF_ENABLE_SELECTABLE_PB */

#define CANIF_CFG_MAGIC()                        (*(CANIF_CFG_GENERIC(eMagicNumber)))

#define CANIF_CFG_RXINDICATION(index)            (CanIf_RxIndicationFctList[(index)])
#define CANIF_CFG_TXCONFIRMATION(index)          (CanIf_TxConfirmationFctList[(index)])
#define CANIF_CFG_BUSOFFNOTIFICATION()           (CanIf_BusOffNotificationFct)
#define CANIF_CFG_WAKEUPEVENT()                  (CanIf_WakeUpEventFct)
#define CANIF_CFG_WAKEUPVALIDATION()             (CanIf_WakeUpValidationFct)
#define CANIF_CFG_DLCERRORNOTIFICATION()         (CanIf_DlcErrorNotificationFct)





# define CanIf_EnterCritical(area)     SchM_Enter_CanIf((area))
# define CanIf_LeaveCritical(area)     SchM_Exit_CanIf((area))



# include "SchM_CanIf.h"


#define CANIF_NOP      ((uint8)0xFF)


#if (CANIF_BITQUEUE == STD_ON)
#if ( CPU_TYPE == CPU_TYPE_32 )
# define kCanTxQueueShift     5
#endif
#if ( CPU_TYPE == CPU_TYPE_16 )
# define kCanTxQueueShift     4
#endif
#if ( CPU_TYPE == CPU_TYPE_8 )
# define kCanTxQueueShift     3
#endif

/* mask used to get the flag index from the handle */
# define kCanTxQueueMask      (((uint8)1 << kCanTxQueueShift) - (uint8)1)
#endif
/*******************************************************************************************************************/
/*  Version check (generated data)                                                                                 */
/*******************************************************************************************************************/


/* Check version of the generated data */
#if (CANIF_SUPPRESS_CANIF_GENDATA_VERSION_CHECK == STD_OFF)
/* Check major and minor Version only */
# if (IF_ASRIFCAN_GENTOOL_GENY_MAJOR_VERSION != CANIF_GENTOOL_GENY_MAJOR_VERSION_REF)
#  error "Unexpected major version of generated data. Please check the version of the generator."
# endif

/* Avoid version check for developer/beta versions */
# if (IF_ASRIFCAN_GENTOOL_GENY_PATCH_VERSION != 0xFF) 
#  if (IF_ASRIFCAN_GENTOOL_GENY_MINOR_VERSION != CANIF_GENTOOL_GENY_MINOR_VERSION_REF)
#   error "Unexpected minor version of generated data. Please check the version of the generator."
#  endif
# else
/* Increment minor version of GenTool for 0xFF Versions */
#  if ((IF_ASRIFCAN_GENTOOL_GENY_MINOR_VERSION + 1u) != CANIF_GENTOOL_GENY_MINOR_VERSION_REF)
#   error "Unexpected minor version of generated data. Please check the version of the generator."
#  endif
# endif
#endif



/*******************************************************************************************************************/
/*  Compatibility defines                                                                                          */
/*******************************************************************************************************************/

#if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
#define CanIf_SetPduMode      CanIf_SetChannelMode
#endif


/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/
#define CANIF_START_SEC_CONST_8BIT
#include "MemMap.h"

CONST(uint8, CANIF_CONST) CanIf_MainVersion         = CANIF_SW_MAJOR_VERSION;
CONST(uint8, CANIF_CONST) CanIf_SubVersion          = CANIF_SW_MINOR_VERSION;
CONST(uint8, CANIF_CONST) CanIf_ReleaseVersion      = CANIF_SW_PATCH_VERSION;

#define CANIF_STOP_SEC_CONST_8BIT
#include "MemMap.h"




#define CANIF_START_SEC_CONST_32BIT
#include "MemMap.h"

#if !defined (V_SUPPRESS_EXTENDED_VERSION_CHECK)
CONST(uint32, CANIF_CONST) IF_ASRIFCAN_LIB_SYMBOL   = IF_ASRIFCAN_LIB_VERSION;
#endif

#define CANIF_STOP_SEC_CONST_32BIT
#include "MemMap.h"




/*******************************************************************************************************************/
/*  local prototypes                                                                                               */
/*******************************************************************************************************************/

#define CANIF_START_SEC_CODE
#include "MemMap.h"

#if (CANIF_TRANSMIT_BUFFER == STD_ON)
/* static void CanIf_TxQueueTreatment(uint8 Controller); */
STATIC FUNC(Std_ReturnType, CANIF_CODE) CanIf_TxQueueTreatment(uint8 Controller);

/* static void CanIf_TxQueueTransmit(uint8 Controller, PduIdType PduId); */
STATIC FUNC(Std_ReturnType, CANIF_CODE) CanIf_TxQueueTransmit(CANIF_CHANNEL_CANTYPE_FIRST PduIdType PduId);
#endif

#if (CANIF_TRANSMIT_BUFFER == STD_ON)
/* Initialize and reset queue */
/* static void CanIf_ClearQueue(uint8 Controller); */
STATIC FUNC(void, CANIF_CODE) CanIf_ClearQueue(CANIF_CHANNEL_CANTYPE_ONLY);
#else 
# define CanIf_ClearQueue(x)
#endif

/* Handle DLC check, indication for upper layers */
#if (CANIF_SUPPORT_NMOSEK_INDICATION == STD_ON)
/* static void CanIf_HlIndication(CanIf_HwHandleType Hrh, PduIdType PduId, const uint8 *CanSduPtr, uint8 CanDlc, Can_IdType CanId); */
STATIC FUNC(void, CANIF_CODE) CanIf_HlIndication(CanIf_HwHandleType  Hrh, PduIdType PduId, P2CONST(uint8, AUTOMATIC, CANIF_CBK_DRV_VAR) CanSduPtr, uint8 CanDlc, Can_IdType CanId);
#else
STATIC FUNC(void, CANIF_CODE) CanIf_HlIndication(CanIf_HwHandleType  Hrh, PduIdType PduId, P2CONST(uint8, AUTOMATIC, CANIF_CBK_DRV_VAR) CanSduPtr, uint8 CanDlc);
#endif

/* static void CanIf_HlTxConfirmation(PduIdType CanTxPduId); */
STATIC FUNC(void, CANIF_CODE) CanIf_HlTxConfirmation(PduIdType CanTxPduId);

#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************************************************/
/*  local data definitions                                                                                         */
/*******************************************************************************************************************/

#if (CANIF_PARTIAL_NETWORK == STD_ON)
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
STATIC VAR(boolean, CANIF_VAR_NOINIT) CanIf_WUTxPDU_Filter_Active[CANIF_MAX_CONTROLLER_TABLESIZE];
#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#endif


#if (CANIF_READRXPDUDATA_API == STD_ON)

#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* V_MEMRAM0 static V_MEMRAM1 SduPtrType V_MEMRAM2 CanIf_RxSduPtr; */
STATIC VAR(SduPtrType, CANIF_VAR_NOINIT) CanIf_RxSduPtr;

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#endif /* CANIF_READRXPDUDATA_API */


#if (CANIF_WAKEUP_VALIDATION == STD_ON)

#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

STATIC VAR(EcuM_WakeupSourceType, CANIF_VAR_NOINIT) CanIf_ValidationWakeUpSource;

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#endif /* CANIF_WAKEUP_VALIDATION */


#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

STATIC CONST(uint8, CANIF_CONST) CanIfState[6][7] =
{
  /*actual state CANIF_GET_OFFLINE: */  
  { 
    (uint8)(CANIF_NOP),
    (uint8)(CANIF_NOP),
    (uint8)(CANIF_GET_RX_ONLINE),
    (uint8)(CANIF_NOP),
    (uint8)(CANIF_GET_TX_ONLINE),
    (uint8)(CANIF_GET_ONLINE),
    (uint8)(CANIF_GET_OFFLINE_ACTIVE)
  },
  
  /*actual state CANIF_GET_RX_ONLINE: */  
  {
    (uint8)(CANIF_GET_OFFLINE),
    (uint8)(CANIF_GET_OFFLINE),
    (uint8)(CANIF_NOP),
    (uint8)(CANIF_NOP),
    (uint8)(CANIF_GET_ONLINE),
    (uint8)(CANIF_GET_ONLINE),
    (uint8)(CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE)
  },
  
  /*actual state CANIF_GET_TX_ONLINE: */  
  {
    (uint8)(CANIF_GET_OFFLINE),
    (uint8)(CANIF_NOP),
    (uint8)(CANIF_GET_ONLINE),
    (uint8)(CANIF_GET_OFFLINE),
    (uint8)(CANIF_NOP),
    (uint8)(CANIF_GET_ONLINE),
    (uint8)(CANIF_GET_OFFLINE_ACTIVE)
  },
    
  /*actual state CANIF_GET_ONLINE: */  
  {
    (uint8)(CANIF_GET_OFFLINE),
    (uint8)(CANIF_GET_TX_ONLINE),
    (uint8)(CANIF_NOP),
    (uint8)(CANIF_GET_RX_ONLINE),
    (uint8)(CANIF_NOP),
    (uint8)(CANIF_NOP),
    (uint8)(CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE) 
  },
    
  /*actual state CANIF_GET_OFFLINE_ACTIVE: */  
  { 
    (uint8)(CANIF_GET_OFFLINE),
    (uint8)(CANIF_NOP),
    (uint8)(CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE),
    (uint8)(CANIF_GET_OFFLINE),
    (uint8)(CANIF_GET_TX_ONLINE),
    (uint8)(CANIF_GET_ONLINE),
    (uint8)(CANIF_NOP)
  } ,
        
  /*actual state CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE: */  
  {
    (uint8)(CANIF_GET_OFFLINE),
    (uint8)(CANIF_GET_OFFLINE_ACTIVE),
    (uint8)(CANIF_NOP),
    (uint8)(CANIF_GET_RX_ONLINE),
    (uint8)(CANIF_GET_ONLINE),
    (uint8)(CANIF_GET_ONLINE),
    (uint8)(CANIF_NOP)
  }
};




#if (CANIF_BITQUEUE == STD_ON)
/* lookup table for setting the flags in the queue */
STATIC CONST(CanIf_TxQueueFlagType, CANIF_CONST) CanShiftLookUp[1 << kCanTxQueueShift] = 
{
  (CanIf_TxQueueFlagType)0x00000001u, (CanIf_TxQueueFlagType)0x00000002u, (CanIf_TxQueueFlagType)0x00000004u, (CanIf_TxQueueFlagType)0x00000008u, 
  (CanIf_TxQueueFlagType)0x00000010u, (CanIf_TxQueueFlagType)0x00000020u, (CanIf_TxQueueFlagType)0x00000040u, (CanIf_TxQueueFlagType)0x00000080u

#if ( CPU_TYPE > CPU_TYPE_8 ) 
 ,(CanIf_TxQueueFlagType)0x00000100u, (CanIf_TxQueueFlagType)0x00000200u, (CanIf_TxQueueFlagType)0x00000400u, (CanIf_TxQueueFlagType)0x00000800u, 
  (CanIf_TxQueueFlagType)0x00001000u, (CanIf_TxQueueFlagType)0x00002000u, (CanIf_TxQueueFlagType)0x00004000u, (CanIf_TxQueueFlagType)0x00008000u
#endif

#if ( CPU_TYPE > CPU_TYPE_16 )
 ,(CanIf_TxQueueFlagType)0x00010000u, (CanIf_TxQueueFlagType)0x00020000u, (CanIf_TxQueueFlagType)0x00040000u, (CanIf_TxQueueFlagType)0x00080000u, 
  (CanIf_TxQueueFlagType)0x00100000u, (CanIf_TxQueueFlagType)0x00200000u, (CanIf_TxQueueFlagType)0x00400000u, (CanIf_TxQueueFlagType)0x00800000u,
  (CanIf_TxQueueFlagType)0x01000000u, (CanIf_TxQueueFlagType)0x02000000u, (CanIf_TxQueueFlagType)0x04000000u, (CanIf_TxQueueFlagType)0x08000000u, 
  (CanIf_TxQueueFlagType)0x10000000u, (CanIf_TxQueueFlagType)0x20000000u, (CanIf_TxQueueFlagType)0x40000000u, (CanIf_TxQueueFlagType)0x80000000u
#endif
};
#endif 

#define CANIF_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"


#if defined (CANIF_ENABLE_SELECTABLE_PB)

# define CANIF_START_SEC_VAR_INIT_UNSPECIFIED
# include "MemMap.h"

/* V_MEMRAM0 static V_MEMROM1 CanIf_ConfigType V_MEMROM2 V_MEMROM3* V_MEMRAM1 V_MEMRAM2 CanIf_Configuration; */
STATIC P2CONST(CanIf_ConfigType, CANIF_VAR_INIT, CANIF_PBCFG) CanIf_Configuration = NULL_PTR;

# define CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
# include "MemMap.h"

#endif /* CANIF_ENABLE_SELECTABLE_PB */


#define CANIF_START_SEC_CODE
#include "MemMap.h"

#if (CANIF_TRANSMIT_BUFFER == STD_ON)
/*******************************************************************************************************************
| NAME:             CanIf_ClearQueue()
| CALLED BY:        CAN Interface
| PRECONDITIONS:    none
| INPUT PARAMETERS: CANIF_CHANNEL_CANTYPE_ONLY: Controller (in case of optimization one channel -> void)
| RETURN VALUES:    none
| DESCRIPTION:      Initialize queue for specified controller
*******************************************************************************************************************/
/* void CanIf_ClearQueue(uint8 Controller); */
STATIC FUNC(void, CANIF_CODE) CanIf_ClearQueue(CANIF_CHANNEL_CANTYPE_ONLY)
{
# if (CANIF_BITQUEUE == STD_ON)
  uint8 queueElementIdx;
# else
  PduIdType TxBCStartIndex;
  PduIdType TxBCStopIndex;
  PduIdType PduId;
# endif

# if (CANIF_BITQUEUE == STD_ON)
  for(queueElementIdx = CANIF_CFG_TXQUEUE_STARTINDEX(CanIf_Controller_Value); queueElementIdx < CANIF_CFG_TXQUEUE_STARTINDEX(CanIf_Controller_Value+1); queueElementIdx++)
  { 
    canIf_TxQueueFlags[queueElementIdx] = (CanIf_TxQueueFlagType)0;
  } 
# else

  CanIf_TxQueueCounter[CanIf_Controller_Value] = 0;

  /* Loop over all normal Tx PDU IDs of requested controller */
  TxBCStartIndex = CANIF_CFG_CONTROLLER(CanIf_Controller_Value, eTxBCStartIndex);
  TxBCStopIndex = CANIF_CFG_CONTROLLER(CanIf_Controller_Value, eTxBCStopIndex);

  for (PduId = TxBCStartIndex; PduId < TxBCStopIndex; PduId++) 
  {
    CanIf_TxQueue[CANIF_CFG_TX_QUEUEINDEX(PduId)].eQueued = 0;
  }
# endif
}
#endif  /* CANIF_TRANSMIT_BUFFER */


/*******************************************************************************************************************
| NAME:             CanIf_Init()
| SID:              0x01
| CALLED BY:        upper layer
| PRECONDITIONS:    All controllers in CANIF_CS_UNINIT or CANIF_CS_STOPPED mode
| INPUT PARAMETERS: const CanIf_ConfigType *ConfigPtr: Pointer to global configuration struct
| RETURN VALUES:    none
| DESCRIPTION:      Global initialisation of CAN Interface and CAN Driver
*******************************************************************************************************************/
/* void CanIf_Init(V_MEMROM1 CanIf_ConfigType V_MEMROM2 V_MEMROM3 *ConfigPtr) */
FUNC(void, CANIF_CODE) CanIf_Init( P2CONST(CanIf_ConfigType, AUTOMATIC, CANIF_PBCFG) ConfigPtr )
{
  CANIF_CHANNEL_CANTYPE_LOCAL

#if (CANIF_DEV_ERROR_DETECT == STD_ON)
# if defined (CANIF_ENABLE_SELECTABLE_PB)
  /*  Check if ConfigPtr is valid */
  if (ConfigPtr == NULL_PTR) 
  {
    CanIf_Det_ReportError(CANIF_INIT_API, CANIF_E_PARAM_POINTER);
  } 
  else 
# endif
#endif
  {
    /* Store Pointer to initialization */
#if defined (CANIF_ENABLE_SELECTABLE_PB)
    CanIf_Configuration = ConfigPtr;
#else 
# if (V_USE_DUMMY_STATEMENT == STD_ON)
    ConfigPtr = ConfigPtr;
# endif
#endif

#if (CANIF_DEV_ERROR_DETECT == STD_ON)
    /* Now we can use the macros to access Gendata as ConfigPtr is correctly stored */
    if (CANIF_CFG_GENERIC(eMagic) != CANIF_MAGIC_NUMBER) 
    {
      CanIf_Det_ReportError(CANIF_INIT_API, CANIF_E_CONFIG);
    } 
    else if (CANIF_CFG_MAGIC() != CANIF_MAGIC_NUMBER)
    {
      /* 2nd Magic Number check ( Check for correct alignment/sizes of postbuild data ) */
      CanIf_Det_ReportError(CANIF_INIT_API, CANIF_E_CONFIG);
    }
    else if (CANIF_CFG_GENERIC(eVersion) != CANIF_GENDATA_VERSION)
    {
      /* Version Check */
      CanIf_Det_ReportError(CANIF_INIT_API, CANIF_E_CONFIG);
    }
    else
#endif  /* CANIF_DEV_ERROR_DETECT */
    {

#if (CANIF_READRXPDUDATA_API == STD_ON)
      CanIf_RxSduPtr = NULL_PTR;
#endif



#if !defined ( V_SUPPRESS_EXTENDED_VERSION_CHECK )
      if(  ( (CANIF_CFG_GENERIC(eGeneratorVersion) & 0x00FFFF00) != 
            ( ((uint32)IF_ASRIFCAN_GENTOOL_GENY_MAJOR_VERSION << 16) | ((uint32)IF_ASRIFCAN_GENTOOL_GENY_MINOR_VERSION << 8) ) )
#if (IF_ASRIFCAN_GENTOOL_GENY_PATCH_VERSION != 0)
           || ( (CANIF_CFG_GENERIC(eGeneratorVersion) & 0x000000FF) < IF_ASRIFCAN_GENTOOL_GENY_PATCH_VERSION )
#endif
        ) 
      {
        /* better cast to void, function may change its return value */
        (void)CanIf_GeneratorCompatibilityError();
      } 
      else 
#endif
      
#if (CANIF_CRC_CHECK == STD_ON)
      if (CANIF_CFG_GENERIC(eCanIfPrecompileCRC) != CANIF_PRECOMPILE_CRC)
      {
        (void)CanIf_GeneratorCompatibilityError();
      }
      else
      if (CANIF_CFG_GENERIC(eCanIfLinktimeCRC) != CanIf_LinktimeCRC)
      {
        (void)CanIf_GeneratorCompatibilityError();
      }
      else
#endif
      {
#if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
# if (CANIF_TRCV_HANDLING == STD_ON)
#  if (CANIF_TRCV_MAPPING == STD_ON)
        uint8         transceiver;
#  endif /* CANIF_TRCV_MAPPING */
# endif  /* CANIF_TRCV_HANDLING */
#endif   /* CANIF_COMPATIBILITY_AUTOSAR21  */

#if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
        Can_Init(&CanConfig);

# if (CANIF_TRCV_HANDLING == STD_ON)
#  if (CANIF_TRCV_MAPPING == STD_ON)

        for (transceiver = 0; transceiver < CANIF_CFG_GENERIC(eMaxTransceivers) ; transceiver++) 
        {
          uint8                                 lowAddress;
          uint8                                 lowIndex;
          CanIf_CanTrcv_InitFctType             lowFct;
          /* Indirection here */
          lowIndex   = CANIF_CFG_TRCVUPTOLOWMAP(transceiver, eDriverIndex);

          /* Currently we loop over all tranceiver indexes and convert the to the driver index          */
          /* So we just do the initialization for index 0 for each Driver                               */

          if (lowIndex == 0) 
          {

            lowAddress = CANIF_CFG_TRCVUPTOLOWMAP(transceiver, eDriverAddress);

            lowFct      = CanIf_TransceiverAPICanTrcv_InitFctMap[lowAddress];

            /* ESCAN00031640 */
            if (lowFct == NULL_PTR) 
            {
              CanIf_Det_ReportError(CANIF_INIT_API, CANIF_TRCV_E_TRANSCEIVER);
            }
            else
            {
              (void)lowFct();
            }
          }
          else
          {
            /* TransceiverIndex not equal to 0, so this TransceiverDriver has been initialized previously */
          }
        }
#  else  /* CANIF_TRCV_MAPPING */
        (void)CanTrcv_Init();
#  endif /* CANIF_TRCV_MAPPING */
# endif  /* CANIF_TRCV_HANDLING */
#endif   /* CANIF_COMPATIBILITY_AUTOSAR21  */

#if (CANIF_SETDYNAMICTXID_API == STD_ON)
        {
          PduIdType DynamicPduId;
          PduIdType CanPduId;
          for(CanPduId = 0; CanPduId < CANIF_CFG_GENERIC(eMaxTxPDUHandle); CanPduId++)
          {
            DynamicPduId = CANIF_CFG_STAT2DYN_INDIRECTION(CanPduId);
            if(DynamicPduId != (PduIdType)-1)
            {
              CanIf_DynTxId[DynamicPduId] = CANIF_CFG_TX(CanPduId, eId);
            }
          }
        }
#endif

        /* Initialisation of all controllers */
#if (CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
        for (controller = 0; controller < CANIF_CFG_GENERIC_EMAXCONTROLLER; controller++) 
#endif
        {
#if (CANIF_PARTIAL_NETWORK == STD_ON)
          CanIf_WUTxPDU_Filter_Active[CanIf_Controller_Value_Local] = FALSE;
#endif
          /* Set controller state to stopped */
          CanIf_ControllerMode[CanIf_Controller_Value_Local] = CANIF_CS_STOPPED;
          CanIf_ChannelMode[CanIf_Controller_Value_Local] = CANIF_GET_OFFLINE;
          /* Init Controller ( Configuration Index not supported ) */
#if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
          CanIf_InitController(CanIf_Controller_Value_Local, &CANIF_CFG_GENERIC(eControllerConfig)[CanIf_Controller_Value_Local]);
#else
          CanIf_InitController(CanIf_Controller_Value_Local, 0);
#endif
        }
      }
    }   /* Check MagicNumbers and Gendata version */
  }   /* Check ConfigPtr == NULL_PTR */
}

/*******************************************************************************************************************
| NAME:             CanIf_InitController()
| SID:              0x02
| CALLED BY:        upper layer, CanIf_Init()
| PRECONDITIONS:    Controller in CANIF_CS_STOPPED mode
| INPUT PARAMETERS: uint8 CanNetwork, const CanIf_ControllerConfigType *ConfigPtr: Pointer to configuration
| RETURN VALUES:    none
| DESCRIPTION:      Controller initialisation of CAN Interface and CAN Driver
*******************************************************************************************************************/
#if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
/* void CanIf_InitController(uint8 CanNetwork, const CanIf_ControllerConfigType *ConfigPtr) */
FUNC(void, CANIF_CODE) CanIf_InitController(uint8 CanNetwork, P2CONST(CanIf_ControllerConfigType, AUTOMATIC, CANIF_PBCFG) ConfigPtr)
#else
/* void CanIf_InitController(uint8 Controller, uint8 ConfigurationIndex) */
FUNC(void, CANIF_CODE) CanIf_InitController(uint8 Controller, uint8 ConfigurationIndex)
#endif
{
#if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
  uint8 Controller;

  Controller = CanNetwork;
#else
# if (V_USE_DUMMY_STATEMENT == STD_ON)
#   if (CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON)
  Controller = Controller;
#   endif
  ConfigurationIndex = ConfigurationIndex; /* Avoid compile warnings */
# endif
#endif

#if ((CANIF_DEV_ERROR_DETECT == STD_ON) && (CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF))
  if (Controller >= CANIF_CFG_GENERIC_EMAXCONTROLLER) 
  {
    CanIf_Det_ReportError(CANIF_INITCONTROLLER_API, CANIF_E_PARAM_CONTROLLER);
  }
  else 
#endif
  {
    if (CanIf_ControllerMode[CanIf_Controller_Value] == CANIF_CS_STARTED) 
    {
      /* Explicitely cast to void as return value cannot be used here */
      (void)CanIf_SetControllerMode(CanIf_Controller_Value, CANIF_CS_STOPPED);
    }
#if (CANIF_DEV_ERROR_DETECT == STD_ON) 
    if (CanIf_ControllerMode[CanIf_Controller_Value] == CANIF_CS_UNINIT) 
    {
      /* CanIf_Init was not called */
      CanIf_Det_ReportError(CANIF_INITCONTROLLER_API, CANIF_E_UNINIT);
    }
#endif    
    if (CanIf_ControllerMode[CanIf_Controller_Value] == CANIF_CS_STOPPED) 
    {

#if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
# if defined (CANIF_ENABLE_SELECTABLE_PB)
      CanIf_ControllerConfiguration[CanIf_Controller_Value] = ConfigPtr;
# else
#  if (V_USE_DUMMY_STATEMENT == STD_ON)
      ConfigPtr = ConfigPtr;
#  endif  
# endif
#else
# if defined (CANIF_ENABLE_SELECTABLE_PB)
      /* Store configuration for controller */
      CanIf_ControllerConfiguration[CanIf_Controller_Value] = &CANIF_CFG_GENERIC(eControllerConfig)[CanIf_Controller_Value];
# endif
#endif

#if (CANIF_WAKEUP_VALIDATION == STD_ON)
      /* Initialize Wakeup Validation */
      CanIf_ValidationWakeUpSource            = 0;
      CanIf_WakeUpValidationState[CanIf_Controller_Value] = CANIF_WUVALIDATION_IDLE;
#endif
      /* Reset Transmit Queue */
      CanIf_ClearQueue(CANIF_CHANNEL_CANPARA_ONLY);

      /* Initialize CAN Controller */
      /* void Can_InitController( uint8 Controller, const Can_ControllerConfigType* Config ) */
      Can_InitController(CanIf_Controller_Value, &(CANIF_CFG_GENERIC(eCan_ControllerConfig)[CanIf_Controller_Value]));
    }
  }    /* Controller invalid (DET) */
}


/*******************************************************************************************************************
| NAME:             CanIf_SetControllerMode()
| SID:              0x3
| CALLED BY:        upper layer
| PRECONDITIONS:    CAN Interrupts are not disabled
| INPUT PARAMETERS: uint8 CanNetwork, CanIf_ControllerModeType ControllerMode: mode transition
| RETURN VALUES:    Result of state transition
| DESCRIPTION:      Execute state transition of network mode of a controller
*******************************************************************************************************************/
#if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
/* Std_ReturnType CanIf_SetControllerMode(uint8 CanNetwork, CanIf_ControllerModeType ControllerMode); */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllerMode(uint8 CanNetwork, CanIf_ControllerModeType ControllerMode)
#else
/* Std_ReturnType CanIf_SetControllerMode(uint8 Controller, CanIf_ControllerModeType ControllerMode) */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllerMode(uint8 Controller, CanIf_ControllerModeType ControllerMode)
#endif
{
  Std_ReturnType retval;
#if (CANIF_PARTIAL_NETWORK == STD_ON)
  uint8  numWUsrc;
  Std_ReturnType retvalTrcv;
#endif

#if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
  uint8 Controller = CanNetwork;
#endif
  retval = E_NOT_OK;
# if ((CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON) && (CANIF_DEV_ERROR_DETECT == STD_OFF))
  Controller = Controller;
#endif
  /* Check parameters */
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
  if (Controller >= CANIF_CFG_GENERIC_EMAXCONTROLLER) 
  {
    CanIf_Det_ReportError(CANIF_SETCONTROLLERMODE_API, CANIF_E_PARAM_CONTROLLER);
  } 
  else 
#endif
  {
    /* return E_OK if controller is in state CANIF_CS_UNINIT */
    if (CanIf_ControllerMode[CanIf_Controller_Value] != CANIF_CS_UNINIT) 
    {
      /* return E_NOT_OK if requested device mode already active */
      CanIf_EnterCritical(CANIF_EXCLUSIVE_AREA_0);
      if (CanIf_ControllerMode[CanIf_Controller_Value] != ControllerMode) 
      {
        switch (ControllerMode) 
        {
          case CANIF_CS_UNINIT:
            /* return E_NOT_OK */
            break;
          case CANIF_CS_STOPPED:
            /* Call wakeup if currently in sleep mode */
            if (CanIf_ControllerMode[CanIf_Controller_Value] == CANIF_CS_SLEEP) 
            {
#if (CANIF_EXTENDED_STATE_MACHINE == STD_ON)
              /* Do not allow SLEEP -> STOP transition */
#else
              /* CAN Driver transition to WakeUp and Stop required if WakeUp is initiated by application */
              if (Can_SetControllerMode(CanIf_Controller_Value, CAN_T_WAKEUP) == CAN_OK) 
              {
                if (Can_SetControllerMode(CanIf_Controller_Value, CAN_T_STOP) == CAN_OK) 
                {
                  /* Set channel mode to offline */
                  CanIf_ChannelMode[CanIf_Controller_Value] = CANIF_GET_OFFLINE;
                  /* Set network mode */
                  /* SET to STOP Mode */
                  CanIf_ControllerMode[CanIf_Controller_Value] = CANIF_CS_STOPPED;
                  retval = E_OK;
                } 
                else 
                {
                  /* retval already set to E_NOT_OK as default */
                }
              }
#endif
            } 
            /* Call stop if currently in running mode */
            else if (CanIf_ControllerMode[CanIf_Controller_Value] == CANIF_CS_STARTED) 
            {
              if (Can_SetControllerMode(CanIf_Controller_Value, CAN_T_STOP) == CAN_OK) 
              {
                /* Set channel mode to offline */
                if (CanIf_SetPduMode(CanIf_Controller_Value, CANIF_SET_OFFLINE) == E_OK) 
                {
                  /* Set network mode */
                  CanIf_ControllerMode[CanIf_Controller_Value] = CANIF_CS_STOPPED;
                  retval = E_OK;
                } 
                else 
                {
                  /* retval already set to E_NOT_OK as default */
                }
              }
            } 
            else 
            {
              /* CAN Interface in invalid mode */
            }

            break;
          case CANIF_CS_STARTED:
            /* Transition only possible from CANIF_CS_STOPPED mode */
            if (CanIf_ControllerMode[CanIf_Controller_Value] == CANIF_CS_STOPPED) 
            {
              if (Can_SetControllerMode(CanIf_Controller_Value, CAN_T_START) == CAN_OK) 
              {
                CanIf_ControllerMode[CanIf_Controller_Value] = CANIF_CS_STARTED;
                retval = E_OK;
              } 
              else 
              {
                /* retval already set to E_NOT_OK as default */
              }
            }
#if (CANIF_EXTENDED_STATE_MACHINE == STD_ON)
            else if (CanIf_ControllerMode[CanIf_Controller_Value] == CANIF_CS_SLEEP) 
            {
              /* SLEEP -> STARTED allowed */
              if (Can_SetControllerMode(CanIf_Controller_Value, CAN_T_WAKEUP) == CAN_OK) 
              {
                /* Set channel mode to offline */
                CanIf_ChannelMode[CanIf_Controller_Value] = CANIF_GET_OFFLINE;
                /* Set network mode */
                CanIf_ControllerMode[CanIf_Controller_Value] = CANIF_CS_STARTED;
                retval = E_OK;
              }
            }
#endif
            else 
            {
              /* Transition not allowed */
              /* E_NOT_OK already set */
            }
            break;
          case CANIF_CS_SLEEP:
#if (CANIF_EXTENDED_STATE_MACHINE == STD_OFF)
            /* Transition from STARTED TO STOPPED first */
            if (CanIf_ControllerMode[CanIf_Controller_Value] == CANIF_CS_STARTED)
            {
              if (Can_SetControllerMode(CanIf_Controller_Value, CAN_T_STOP) == CAN_OK) 
              {
                /* Set channel mode to offline */
                if (CanIf_SetPduMode(CanIf_Controller_Value, CANIF_SET_OFFLINE) == E_OK) 
                {
                  /* Set network mode */
                  CanIf_ControllerMode[CanIf_Controller_Value] = CANIF_CS_STOPPED;
                } 
                else 
                {
                  /* retval already set to E_NOT_OK as default */
                }
              }
            }
            /* CanIf_ControllerMode is now CANIF_CS_STOPPED unless an error occured 
                -> E_NOT_OK still set in case of uncomplete transition */
#endif
            if (CanIf_ControllerMode[CanIf_Controller_Value] == CANIF_CS_STOPPED) 
            {
#if (CANIF_EXTENDED_STATE_MACHINE == STD_ON)
              /* STOP -> SLEEP not allowed, E_NOT_OK already set */
            } 
            else if (CanIf_ControllerMode[CanIf_Controller_Value] == CANIF_CS_STARTED) 
            {
              /* START -> SLEEP allowed */
              /* Clear the Queue first - CanIf should be in Offline mode already */
              (void)CanIf_SetPduMode(CanIf_Controller_Value, CANIF_SET_OFFLINE);
#endif
#if (CANIF_WAKEUP_VALIDATION == STD_ON)
              /* Reset wake up validation state -> we are going to sleep again */
              CanIf_WakeUpValidationState[CanIf_Controller_Value] = CANIF_WUVALIDATION_IDLE;
#endif

              if (Can_SetControllerMode(CanIf_Controller_Value, CAN_T_SLEEP) == CAN_OK) 
              {
                CanIf_ControllerMode[CanIf_Controller_Value] = CANIF_CS_SLEEP;
                retval = E_OK;
              } 
              else 
              {
                /* retval is already set to E_NOT_OK */
              }
#if (CANIF_PARTIAL_NETWORK == STD_ON)
              if (CANIF_CFG_WU_TXPDU_FILTER_ACTIVE(CanIf_Controller_Value) == TRUE)
              {
                for (numWUsrc = 0; numWUsrc < CANIF_CFG_GENERIC(eMaxWakeUpSources); numWUsrc++) 
                {   
                  uint8                                 wuTrgtaddress;
                  CanIf_WakeUpTargetType                wuTrgtmodule;


                  wuTrgtaddress = CANIF_CFG_WAKEUP(numWUsrc, eWakeUpTargetAddress);    
                  wuTrgtmodule  = CANIF_CFG_WAKEUP(numWUsrc, eWakeUpTargetModule);

                  if (wuTrgtmodule == CANIF_WAKEUPREQUEST_TRCV) 
                  {
# if (CANIF_TRCV_MAPPING == STD_ON)
                    /* Indirection here */
                    uint8                                 lowIndex;
                    uint8                                 lowAddress;
                    CanIf_CanTrcv_CB_WakeupByBusFctType   lowFct;

                    lowIndex   = CANIF_CFG_TRCVUPTOLOWMAP(wuTrgtaddress, eDriverIndex);
                    lowAddress = CANIF_CFG_TRCVUPTOLOWMAP(wuTrgtaddress, eDriverAddress);

                    lowFct      = CanIf_TransceiverAPICanTrcv_CB_WakeupByBusFctMap[lowAddress];

                    /* ESCAN00031640 */
                    if (lowFct == NULL_PTR)
                    {
                      CanIf_Det_ReportError(CANIF_SETCONTROLLERMODE_API, CANIF_TRCV_E_TRANSCEIVER);
                    }
                    else
                    {
                      retvalTrcv = lowFct(lowIndex);
                    }
# else  /* CANIF_TRCV_MAPPING */
                    retvalTrcv = CanTrcv_CB_WakeupByBus(wuTrgtaddress);
# endif /* CANIF_MULTIPLE_TRANSCEIVER_SUPPORT */
                    if (retvalTrcv == E_OK)
                    {
                      retval = E_OK;
                      EcuM_CheckWakeup( CANIF_CFG_WAKEUP(numWUsrc, eWakeUpSource) );
                    }
                    else if( retval == E_NOT_OK )
                    {
                      CanIf_Dem_ReportError(CANIF_INDIRECT_E_SLEEP_REQ_FAILED);
                    }
                  }
                }
              }
#endif
            } 
            else
            {
              /* Transition not allowed */
              /* E_NOT_OK already set */
            }
            break;
          default:
            retval = E_NOT_OK;
            break;
        }
      } 
      else 
      {
        /* CanIf already in requested state */
        retval = E_OK;
      }
      CanIf_LeaveCritical(CANIF_EXCLUSIVE_AREA_0);
    }
  }
  return retval;
}


/*******************************************************************************************************************
| NAME:             CanIf_GetControllerMode()
| SID:              0x04
| CALLED BY:        upper layer
| PRECONDITIONS:    CanInterface is initialized
| INPUT PARAMETERS: uint8 CanNetwork, CanIf_ControllerModeType  *ControllerModePtr
| RETURN VALUES:    network mode of controller
| DESCRIPTION:      Execute state transition of a controller
*******************************************************************************************************************/
#if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
/* Std_ReturnType CanIf_GetControllerMode(uint8 CanNetwork, CanIf_ControllerModeType *ControllerModePtr); */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerMode(uint8 CanNetwork, P2VAR(CanIf_ControllerModeType, AUTOMATIC, CANIF_APPL_STATE_VAR) ControllerModePtr)
#else
/* Std_ReturnType CanIf_GetControllerMode(uint8 Controller, CanIf_ControllerModeType *ControllerModePtr) */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerMode(uint8 Controller, P2VAR(CanIf_ControllerModeType, AUTOMATIC, CANIF_APPL_STATE_VAR) ControllerModePtr)
#endif
{
  Std_ReturnType retval;

#if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
  uint8 Controller;

  Controller = CanNetwork;
#endif
#if ((CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON) && (CANIF_DEV_ERROR_DETECT == STD_OFF))
  Controller = Controller;
#endif
  retval = E_NOT_OK;
  /* Deviation: No check for state uninit of CanIf simply return state */
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
  if (Controller >= CANIF_CFG_GENERIC_EMAXCONTROLLER ) 
  {
    /* Check CanNetwork parameter is valid */
    CanIf_Det_ReportError(CANIF_GETCONTROLLERMODE_API, CANIF_E_PARAM_CONTROLLER);
  }
# if defined (CANIF_ENABLE_SELECTABLE_PB)
  else if (CANIF_CFG == NULL_PTR) 
  {
    CanIf_Det_ReportError(CANIF_GETCONTROLLERMODE_API, CANIF_E_PARAM_POINTER);
  } 
# endif
  else if (ControllerModePtr == NULL_PTR) 
  {
    CanIf_Det_ReportError(CANIF_GETCONTROLLERMODE_API, CANIF_E_PARAM_POINTER);
  } 
  else 
#endif
  {
    *ControllerModePtr = CanIf_ControllerMode[CanIf_Controller_Value];
    retval = E_OK;
  }
  return retval;
}

/*******************************************************************************************************************
| NAME:             CanIf_Transmit()
| SID:              0x05
| CALLED BY:        upper layer
| PRECONDITIONS:    CAN Interface initialized
| INPUT PARAMETERS: PduIdType CanTxPduId: Handle of Tx PDU, 
|                   const PduInfoType *PduInfoPtr: PDU Info (Data length, data ptr)
| RETURN VALUES:    Result of transmission request
| DESCRIPTION:      Initiate transmission of a Tx PDU
*******************************************************************************************************************/
/* Std_ReturnType CanIf_Transmit(PduIdType CanTxPduId, const PduInfoType *PduInfoPtr) */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit(PduIdType CanTxPduId, P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_MSG_VAR)PduInfoPtr)
{
  Can_PduType     localPdu;
  Std_ReturnType  retval;
#if CANIF_SETDYNAMICTXID_API == STD_ON
  PduIdType     DynamicPduId;
#endif
  CANIF_CHANNEL_CANTYPE_LOCAL
#if (CANIF_BITQUEUE == STD_ON)
  sint8_least queueElementIdx;
# if ((CANIF_TRANSMIT_CANCELLATION == STD_OFF) && (CANIF_OPTIMIZE_TX_WITH_SHORT_PIA_GAP == STD_OFF))
  sint8_least queueEndElementIdx;
# endif
  uint8 elementBitIdx;
  PduIdType queueBitPos;
#endif  
  retval = E_NOT_OK;
  /* Check if CanTxPduId is valid */
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
  if (CanTxPduId >= CANIF_CFG_GENERIC(eMaxTxPDUHandle)) 
  {
    CanIf_Det_ReportError(CANIF_TRANSMIT_API, CANIF_E_PARAM_LPDU);
  } 
  else if (PduInfoPtr == NULL_PTR) 
  {
    CanIf_Det_ReportError(CANIF_TRANSMIT_API, CANIF_E_PARAM_POINTER);
  } 
  else
#endif
  {   
#if (CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
    /* Collect configuration data */
    controller = CANIF_CFG_TX_ECONTROLLER;
#endif
#if (CANIF_PARTIAL_NETWORK == STD_ON)
if(!(((PduIdType) -1 != CANIF_CFG_WU_TXPDU_HANDLE(CanIf_Controller_Value_Local)) && 
   ( CANIF_CFG_WU_TXPDU_FILTER_ACTIVE(CanIf_Controller_Value_Local) == TRUE ) && 
   (CanIf_WUTxPDU_Filter_Active[CanIf_Controller_Value_Local] ==  TRUE) && 
   (CanTxPduId != CANIF_CFG_WU_TXPDU_HANDLE(CanIf_Controller_Value_Local))))
#endif
    {
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
    if (CanIf_ControllerMode[CanIf_Controller_Value_Local] == CANIF_CS_UNINIT) 
    {
      CanIf_Det_ReportError(CANIF_TRANSMIT_API, CANIF_E_UNINIT);
    } 
    else 
#endif
    {
      /* Check network mode */
      if (CanIf_ControllerMode[CanIf_Controller_Value_Local] == CANIF_CS_STARTED) 
      {

        /* Check Channel mode */
        if ( (CanIf_ChannelMode[CanIf_Controller_Value_Local] == CANIF_GET_ONLINE) ||
             (CanIf_ChannelMode[CanIf_Controller_Value_Local] == CANIF_GET_TX_ONLINE) )
        {
          Can_ReturnType txResult;
		  CanIf_EnterCritical(CANIF_EXCLUSIVE_AREA_4);

#if (CANIF_SETDYNAMICTXID_API == STD_ON)
          DynamicPduId = CANIF_CFG_STAT2DYN_INDIRECTION(CanTxPduId);
          if(DynamicPduId != (PduIdType)-1)
          {
            (localPdu).id = CanIf_DynTxId[DynamicPduId];
          }
          else
          {
            (localPdu).id = CANIF_CFG_TX(CanTxPduId, eId);
          }
#else
          (localPdu).id = CANIF_CFG_TX(CanTxPduId, eId);
#endif
#if (CANIF_DYNAMIC_TX_DLC == STD_ON)
          (localPdu).length = (uint8)(PduInfoPtr->SduLength);
#else
          (localPdu).length = CANIF_CFG_TX(CanTxPduId, eLength); 
#endif
          (localPdu).sdu = (PduInfoPtr->SduDataPtr);
          (localPdu).swPduHandle = (CanTxPduId);

#if (CANIF_TRANSMIT_BUFFER == STD_ON) && (CANIF_OPTIMIZE_TX_WITH_SHORT_PIA_GAP == STD_OFF)
          /* Check if message is not a Tx Full CAN */
          if ( ( CanTxPduId >= CANIF_CFG_CONTROLLER(CanIf_Controller_Value_Local, eTxBCStartIndex) ) &&
               ( CanTxPduId < CANIF_CFG_CONTROLLER(CanIf_Controller_Value_Local, eTxBCStopIndex ) )  )
          {  /* Queue the data / Overwrite data in Queue / always queue it also in empty queue to avoid quing after write return busy */
# if (CANIF_DEV_ERROR_DETECT == STD_ON)
            if ( (localPdu.sdu == NULL_PTR) && (localPdu.length != 0) )
            {
              CanIf_Det_ReportError(CANIF_TRANSMIT_API, CANIF_E_PARAM_POINTER);
            } 
            else 
# endif
            { /* Queue information */
# if (CANIF_USES_VSTDLIB_COPY != STD_ON)
              PduLengthType i;
# endif

# if (CANIF_TRANSMIT_CANCELLATION == STD_OFF)
#  if(CANIF_BITQUEUE == STD_ON)
              CanIf_TxQueueFlagType localQueueCount = 0;
              queueEndElementIdx = (sint8_least)(CANIF_CFG_TXQUEUE_STARTINDEX(CanIf_Controller_Value_Local));
              /* process from last to first */
              for(queueElementIdx = CANIF_CFG_TXQUEUE_STARTINDEX(CanIf_Controller_Value_Local+1)-1; queueElementIdx >= queueEndElementIdx; queueElementIdx--)
              {
                localQueueCount = canIf_TxQueueFlags[queueElementIdx];
                if (localQueueCount != 0)
                {
                  break;
                }
              }
#  else
              PduIdType localQueueCount;
              localQueueCount = CanIf_TxQueueCounter[CanIf_Controller_Value_Local];
#  endif /* (CANIF_BITQUEUE == STD_ON) */
# endif  /* (CANIF_TRANSMIT_CANCELLATION == STD_OFF) */
              CanIf_TxQueue[CANIF_CFG_TX_QUEUEINDEX(CanTxPduId)].eSduLength = localPdu.length;
# if (CANIF_USES_VSTDLIB_COPY == STD_ON)
              VStdMemCpyRamToRam(CanIf_TxQueue[CANIF_CFG_TX_QUEUEINDEX(CanTxPduId)].eSdu, localPdu.sdu, localPdu.length);
# else
              for (i = 0; i < localPdu.length; i++) 
              {
                CanIf_TxQueue[CANIF_CFG_TX_QUEUEINDEX(CanTxPduId)].eSdu[i] = localPdu.sdu[i];
              }
# endif
              /* Set queue flag for current PDU and return E_OK */
              /* Mark queued element */
# if (CANIF_BITQUEUE == STD_ON)
              queueBitPos  = CanTxPduId + CANIF_CFG_TXQUEUE_PADBITS(CanIf_Controller_Value_Local);
              queueElementIdx = (uint8)(queueBitPos >> kCanTxQueueShift); /* get the queue element where to set the flag */
              elementBitIdx  = (uint8)(queueBitPos & kCanTxQueueMask);   /* get the flag index wihtin the queue element */
              if( (canIf_TxQueueFlags[queueElementIdx] & CanShiftLookUp[elementBitIdx]) == (CanIf_TxQueueFlagType)0 )
              {
                canIf_TxQueueFlags[queueElementIdx] |= CanShiftLookUp[elementBitIdx];
              }
# else
              if (CanIf_TxQueue[CANIF_CFG_TX_QUEUEINDEX(CanTxPduId)].eQueued == 0) 
              {
                CanIf_TxQueue[CANIF_CFG_TX_QUEUEINDEX(CanTxPduId)].eQueued = 1;
                CanIf_TxQueueCounter[CanIf_Controller_Value_Local] ++;
              }
# endif
              else 
              {
                /* Tx Buffer for this PduId busy - data is overwritten - queue flag already set */
# if (CANIF_DEMTODET_E_FULL_TX_BUFFER == STD_ON)
                /* Only reported if development error detection is activated (by macro definition) */
                CanIf_Det_ReportError(CANIF_TRANSMIT_API, CANIF_E_FULL_TX_BUFFER);
# else
                CanIf_Dem_ReportError(CANIF_INDIRECT_E_FULL_TX_BUFFER);
# endif
              }
# if (CANIF_TRANSMIT_CANCELLATION == STD_OFF)
              if( localQueueCount != 0 ) /* queue was not empty and no internal PIA supported
                                            --> so send request out of confirmation will follow in queue handling */
              {
                retval = E_OK; /*message is queued*/
              }
              else
# endif
              { /*retval = E_OK for CAN_OK or CAN_BUSY / E_NOT_OK for CAN_NOT_OK */
                retval = CanIf_TxQueueTreatment(CanIf_Controller_Value_Local); /*send out of queue for internal PIA - trigger possible cancelation*/
              }
            } /* Development error check SduDataPtr == NULL_PTR */
          }
          else 
          { /* Tx object is FullCAN (will not be queued) - do direct Tx */
#else       /* no Tx Buffer -                              do always direct Tx*/
          {
#endif
          /* (const Can_PduType*) cast required (No Compiler abstraction, target is on stack (RAM)
              const to mark it read-only / CA cast (-> to get the const )                          */
            txResult = Can_Write(CANIF_CFG_TX(CanTxPduId, eHth), (P2CONST(Can_PduType, AUTOMATIC, CANIF_VAR_STACK))&localPdu);
            if (txResult == CAN_BUSY) 
            { /* Tx Object busy */
#if (CANIF_TRANSMIT_BUFFER == STD_ON) && (CANIF_OPTIMIZE_TX_WITH_SHORT_PIA_GAP == STD_ON)
              /* Check if message is not a Tx Full CAN */
                                   
          if ( ( CanTxPduId >= CANIF_CFG_CONTROLLER(CanIf_Controller_Value_Local, eTxBCStartIndex) ) &&
               ( CanTxPduId < CANIF_CFG_CONTROLLER(CanIf_Controller_Value_Local, eTxBCStopIndex ) )  )
              {
                /* Queue the data / Overwrite data in Queue*/
# if (CANIF_DEV_ERROR_DETECT == STD_ON)
                if ( (localPdu.sdu == NULL_PTR) && (localPdu.length != 0) )
                {
                  CanIf_Det_ReportError(CANIF_TRANSMIT_API, CANIF_E_PARAM_POINTER);
                } 
                else 
# endif
                {
                  /* Queue information */
# if (CANIF_USES_VSTDLIB_COPY != STD_ON)
                  PduLengthType i;
# endif
                  CanIf_TxQueue[CANIF_CFG_TX_QUEUEINDEX(CanTxPduId)].eSduLength = localPdu.length;
# if (CANIF_USES_VSTDLIB_COPY == STD_ON)
                  VStdMemCpyRamToRam(CanIf_TxQueue[CANIF_CFG_TX_QUEUEINDEX(CanTxPduId)].eSdu, localPdu.sdu, localPdu.length);
# else
                  for (i = 0; i < localPdu.length; i++) 
                  {
                    CanIf_TxQueue[CANIF_CFG_TX_QUEUEINDEX(CanTxPduId)].eSdu[i] = localPdu.sdu[i];
                  }
# endif
                  /* Set queue flag for current PDU and return E_OK */
                  
                  
                  /* Mark queued element */
# if (CANIF_BITQUEUE == STD_ON)
                  queueBitPos  = CanTxPduId + CANIF_CFG_TXQUEUE_PADBITS(CanIf_Controller_Value_Local);
                  queueElementIdx = (uint8)(queueBitPos >> kCanTxQueueShift);
                  elementBitIdx  = (uint8)(queueBitPos & kCanTxQueueMask);
                  if( (canIf_TxQueueFlags[queueElementIdx] & CanShiftLookUp[elementBitIdx]) == (CanIf_TxQueueFlagType)0 )
                  {
                    canIf_TxQueueFlags[queueElementIdx] |= CanShiftLookUp[elementBitIdx];
                  }
# else
                  if (CanIf_TxQueue[CANIF_CFG_TX_QUEUEINDEX(CanTxPduId)].eQueued == 0) 
                  {
                    CanIf_TxQueue[CANIF_CFG_TX_QUEUEINDEX(CanTxPduId)].eQueued = 1;
                    CanIf_TxQueueCounter[CanIf_Controller_Value_Local] ++;
                  } 
# endif
                  else 
                  {
                    /* Tx Buffer for this PduId busy - data is overwritten - queue flag already set */
# if (CANIF_DEMTODET_E_FULL_TX_BUFFER == STD_ON)
                    /* Only reported if development error detection is activated (by macro definition) */
                    CanIf_Det_ReportError(CANIF_TRANSMIT_API, CANIF_E_FULL_TX_BUFFER);
# else
                    CanIf_Dem_ReportError(CANIF_INDIRECT_E_FULL_TX_BUFFER);
# endif
                  }

                  retval = E_OK;
                } /* Development error check SduDataPtr == NULL_PTR */
              } 
              else 
              {
                /* Tx object busy - FullCAN will not be queued */
                retval = E_NOT_OK;
              }
#else /* (CANIF_TRANSMIT_BUFFER == STD_ON) && (CANIF_OPTIMIZE_TX_WITH_SHORT_PIA_GAP == STD_ON) */
              /* Tx Object busy */
# if (CANIF_DEMTODET_E_FULL_TX_BUFFER == STD_ON)
              /* Only reported if development error detection is activated (by macro definition) */
              CanIf_Det_ReportError(CANIF_TRANSMIT_API, CANIF_E_FULL_TX_BUFFER);
# else
              CanIf_Dem_ReportError(CANIF_INDIRECT_E_FULL_TX_BUFFER);
# endif
#endif /* (CANIF_TRANSMIT_BUFFER == STD_ON) && (CANIF_OPTIMIZE_TX_WITH_SHORT_PIA_GAP == STD_ON) */
            } 
            else if (txResult == CAN_NOT_OK) 
            { /* Can_Write failed */
              retval = E_NOT_OK;
            } 
            else 
            { 
              /* ESCAN00061139 - start */
#if ((CANIF_TRANSMIT_BUFFER == STD_ON) && (CANIF_OPTIMIZE_TX_WITH_SHORT_PIA_GAP == STD_ON))
              /* Do clear the TxPdu queued flag of the transmitted BasicCAN-TxPdu */
              if ( ( CanTxPduId >= CANIF_CFG_CONTROLLER(CanIf_Controller_Value_Local, eTxBCStartIndex) ) &&
                   ( CanTxPduId < CANIF_CFG_CONTROLLER(CanIf_Controller_Value_Local, eTxBCStopIndex ) ) )
              {
# if (CANIF_BITQUEUE == STD_ON)
                queueBitPos  = CanTxPduId + CANIF_CFG_TXQUEUE_PADBITS(CanIf_Controller_Value_Local);
                queueElementIdx = (uint8)(queueBitPos >> kCanTxQueueShift);
                elementBitIdx  = (uint8)(queueBitPos & kCanTxQueueMask);
                canIf_TxQueueFlags[queueElementIdx] &= ~CanShiftLookUp[elementBitIdx];
# else
                if (CanIf_TxQueue[CANIF_CFG_TX_QUEUEINDEX(CanTxPduId)].eQueued == 1u)
                {
                  CanIf_TxQueue[CANIF_CFG_TX_QUEUEINDEX(CanTxPduId)].eQueued = 0u;
                  --CanIf_TxQueueCounter[CanIf_Controller_Value_Local];
                }
# endif
              }
#endif
                    /* ESCAN00061139 - end */
              retval = E_OK;
            }
          }
        CanIf_LeaveCritical(CANIF_EXCLUSIVE_AREA_4);
        } 
        else if ( (CanIf_ChannelMode[CanIf_Controller_Value_Local] == CANIF_GET_OFFLINE_ACTIVE) ||
                    (CanIf_ChannelMode[CanIf_Controller_Value_Local] == CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE) )  
        {
          retval = E_OK;
          /* Choose destination for Tx Confirmation */
          CanIf_HlTxConfirmation(CanTxPduId);
              
        } 
        else 
        { /* Nothing to do, else required for MISRA */
          /* default   retval = E_NOT_OK; */
        }

      } 
      else 
      {
        /* STOPPED, possibly uninit if DevErrorDetection is not enabled */
#if (CANIF_DEMTODET_E_STOPPED == STD_ON)
        /* Only reported if development error detection is activated (by macro definition) */
        CanIf_Det_ReportError(CANIF_TRANSMIT_API, CANIF_E_STOPPED);
#else
        CanIf_Dem_ReportError(CANIF_INDIRECT_E_STOPPED);
#endif
        /* default   retval = E_NOT_OK; */
        }
      }
    }
  }
  return retval;
}


/*******************************************************************************************************************
| NAME:             CanIf_HlTxConfirmation()
| SID:              0x13
| CALLED BY:        CAN Driver
| PRECONDITIONS:    CAN Interface initialized
| INPUT PARAMETERS: PduIdType CanTxPduId: Handle of Tx PDU
| RETURN VALUES:    none
| DESCRIPTION:      Confirmation for a successful transmission
*******************************************************************************************************************/
/* static void CanIf_HlTxConfirmation(PduIdType CanTxPduId) */
STATIC FUNC(void, CANIF_CODE) CanIf_HlTxConfirmation(PduIdType CanTxPduId) 
{
  uint8 index;
  CanIf_TxConfirmationFctType txConfirmationFct;
#if (CANIF_PARTIAL_NETWORK == STD_ON)
  CANIF_CHANNEL_CANTYPE_LOCAL
#endif

  
  index = CANIF_CFG_TX(CanTxPduId, eTxConfirmation);
#if (CANIF_PARTIAL_NETWORK == STD_ON)
# if (CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
  controller = CANIF_CFG_TX(CanTxPduId, eController);
# endif

  CanIf_WUTxPDU_Filter_Active[CanIf_Controller_Value_Local] = FALSE; /*Tx message confirmed, deactivate Tx filter*/
#endif

  txConfirmationFct = CANIF_CFG_TXCONFIRMATION(index);

  if (txConfirmationFct != NULL_PTR) 
  {
#if (CANIF_ENABLE_TX_LPDU_REMAPPING == STD_ON)
    PduIdType mappedPduId;
    mappedPduId = CANIF_CFG_TX(CanTxPduId, eMappedPduId);
    txConfirmationFct(mappedPduId);
#else
    txConfirmationFct(CanTxPduId);
#endif
  }
}


/*******************************************************************************************************************
| NAME:             CanIf_TxConfirmation()
| SID:              0x13
| CALLED BY:        CAN Driver
| PRECONDITIONS:    CAN Interface initialized
| INPUT PARAMETERS: PduIdType CanTxPduId: Handle of Tx PDU
| RETURN VALUES:    none
| DESCRIPTION:      Confirmation for a successful transmission
*******************************************************************************************************************/
/* void CanIf_TxConfirmation(PduIdType CanTxPduId) */
FUNC(void, CANIF_CODE) CanIf_TxConfirmation(PduIdType CanTxPduId)
{

#if (CANIF_DEV_ERROR_DETECT == STD_ON)
  if (CanTxPduId >=  CANIF_CFG_GENERIC(eMaxTxPDUHandle)) 
  {
    CanIf_Det_ReportError(CANIF_TXCONFIRMATION_API, CANIF_E_PARAM_LPDU);
  } 
  else if (CanIf_ControllerMode[CANIF_CFG_TX_ECONTROLLER] == CANIF_CS_UNINIT ) 
  {
    CanIf_Det_ReportError(CANIF_TXCONFIRMATION_API, CANIF_E_UNINIT);
  } 
  else 
#endif
  {
    if (CanIf_ControllerMode[CANIF_CFG_TX_ECONTROLLER] == CANIF_CS_STARTED) 
    {
      if ( (CanIf_ChannelMode[CANIF_CFG_TX_ECONTROLLER] == CANIF_GET_ONLINE) || 
           (CanIf_ChannelMode[CANIF_CFG_TX_ECONTROLLER] == CANIF_GET_TX_ONLINE) ) 
      {
#if (CANIF_TRANSMIT_BUFFER == STD_ON)
        /* Send queued messages directly if Normal Tx message was confirmed */
        PduIdType queueindex;
        queueindex = CANIF_CFG_TX_QUEUEINDEX(CanTxPduId);

        /* Check if queue is affected (Normal Tx object) */
        if (queueindex != (PduIdType)-1) 
        {
          /* Send queued messages directly */
          CanIf_EnterCritical(CANIF_EXCLUSIVE_AREA_2); 
          (void)CanIf_TxQueueTreatment(CANIF_CFG_TX_ECONTROLLER);
          CanIf_LeaveCritical(CANIF_EXCLUSIVE_AREA_2);  /*lock over queue handling + write call (driver does not expect direct call inbetween)*/
        }
#endif

        CanIf_HlTxConfirmation(CanTxPduId);
      }
    }
  }
}

/*******************************************************************************************************************
| NAME:             CanIf_RxIndication()
| SID:              0x14
| CALLED BY:        CAN Driver
| PRECONDITIONS:    CAN Interface initialized
| INPUT PARAMETERS: uint8 Hrh: Handle of hardware object
|                   Can_IdType CanId: Id of receive message
|                   uint8 CanDlc: DLC of received message
|                   const uint8 *CanSduPtr: Pointer to data of received message
| RETURN VALUES:    none
| DESCRIPTION:      Find PDU ID of received messages
*******************************************************************************************************************/
/* void CanIf_RxIndication(uint8 Hrh, Can_IdType CanId, uint8 CanDlc, const uint8 *CanSduPtr) */
FUNC(void, CANIF_CODE) CanIf_RxIndication(CanIf_HwHandleType Hrh, Can_IdType CanId, uint8 CanDlc, P2CONST(uint8, AUTOMATIC, CANIF_CBK_DRV_VAR)CanSduPtr)
{
  PduIdType RxPduId;
#if (CANIF_SEARCH_ALGORITHM == CANIF_DOUBLE_HASH)
  Can_IdType hash1;
  Can_IdType hash2;
#endif
#if ((CANIF_SEARCH_ALGORITHM == CANIF_BINARY) || (CANIF_SEARCH_ALGORITHM == CANIF_DOUBLE_HASH))
  boolean continueSearch;
#endif
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
  if (CanSduPtr == NULL_PTR) 
  {
    CanIf_Det_ReportError(CANIF_RXINDICATION_API, CANIF_E_PARAM_POINTER);
  } 
  else if (CanDlc > 8) 
  {
    CanIf_Det_ReportError(CANIF_RXINDICATION_API, CANIF_E_PARAM_DLC);
# if (CANIF_EXTENDEDID_SUPPORT != STD_ON)
  } 
  else if (CanId > 0x7FF) 
  {
    CanIf_Det_ReportError(CANIF_RXINDICATION_API, CANIF_E_PARAM_CANID);
# endif
  } 
  else if (Hrh >= CANIF_CFG_GENERIC(eMaxMailBox)) 
  {
    CanIf_Det_ReportError(CANIF_RXINDICATION_API, CANIF_E_PARAM_HRH);
  } 
  else 
#endif
  {
#if (CANIF_WAKEUP_VALIDATION == STD_ON)
# if (CANIF_WAKEUP_VALID_ALL_RX_MSGS == STD_ON)
    CANIF_CHANNEL_CANTYPE_LOCAL
#if (CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
    /* Acquire controller from CanIf_Mailbox struct */
    controller = CANIF_CFG_MAILBOX(Hrh, eController);
#endif
    if (CanIf_ControllerMode[CanIf_Controller_Value_Local] == CANIF_CS_STARTED) 
    {
      if (CanIf_WakeUpValidationState[CanIf_Controller_Value_Local] == CANIF_WUVALIDATION_ARMED) 
      {
        /* All messages will be used for validation only in controller mode STARTED*/
        CanIf_WakeUpValidationState[CanIf_Controller_Value_Local] = CANIF_WUVALIDATION_DETECTED;
      }
    }
# endif
#endif

    /* No Rx-Pdus or Ranges configured. Nothing to search. */
    if (CANIF_CFG_GENERIC(eMaxRxPDUHandle) != 0) 
    {

      RxPduId = CANIF_CFG_MAILBOX(Hrh, ePduIdLast);
      if (RxPduId != CanIf_RxPduHnd_INVALID)
      {
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
        if (RxPduId >= CANIF_CFG_GENERIC(eMaxRxPDUHandle)) 
        {
          CanIf_Det_ReportError(CANIF_RXINDICATION_API, CANIF_E_PARAM_LPDU);
        } 
        else 
#endif
        {
          if (CANIF_RxFullCANMailbox == CANIF_CFG_MAILBOX(Hrh, eMailBoxType)) 
          {
            /* Full CAN message */
            CanIf_Indirect_HlIndication(Hrh, RxPduId, CanSduPtr, CanDlc, CanId);
          } 
          else 
          {
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
            if (CANIF_RxBasicCANMailbox == CANIF_CFG_MAILBOX(Hrh, eMailBoxType)) 
            {
#endif


#if ((CANIF_SEARCH_ALGORITHM == CANIF_BINARY) || (CANIF_SEARCH_ALGORITHM == CANIF_DOUBLE_HASH))
              /* Ranges message (searched linearly also in case of binary search) */
              continueSearch = TRUE;
              while  ( (CANIF_CFG_RX_MASK(RxPduId) & (CANIF_STOP_FLAG | CANIF_RANGE_FLAG)) == CANIF_RANGE_FLAG )  
              {
                if (CANIF_CFG_RX_ID(RxPduId) == (CanId & CANIF_CFG_RX_MASK(RxPduId)) ) 
                {
                  /* ID matches - Pdu identified */
                  CanIf_Indirect_HlIndication(Hrh, RxPduId, CanSduPtr, CanDlc, CanId);
                  continueSearch = FALSE;
                  break;
                }
                RxPduId--;
              }
              if ( (CANIF_CFG_RX_MASK(RxPduId) & (CANIF_STOP_FLAG | CANIF_RANGE_FLAG)) == (CANIF_STOP_FLAG | CANIF_RANGE_FLAG) ) 
              {
                /* End flag for Search algorithm is set, this means no more messages to search for */
                continueSearch = FALSE;
                if (CANIF_CFG_RX_ID(RxPduId) == (CanId & CANIF_CFG_RX_MASK(RxPduId)) ) 
                {
                  /* ID matches - Pdu identified */
                  CanIf_Indirect_HlIndication(Hrh, RxPduId, CanSduPtr, CanDlc, CanId);
                }
              }
#endif
#if (CANIF_SEARCH_ALGORITHM == CANIF_BINARY)
              if (continueSearch == TRUE)
              {

                PduIdType first;
                PduIdType last;
                PduIdType mid;
                PduIdType resultId;

                resultId = CanIf_RxPduHnd_INVALID;

                /* Get first and last object to search over */

                first = CANIF_CFG_MAILBOX(Hrh, ePduIdFirst);
                last = RxPduId;

                while (first <= last) 
                {
#if (CANIF_EXTENDEDID_SUPPORT == STD_ON)
                  sint32 diffId;
#else 
                  sint16 diffId;
#endif

                  mid = ((last + first) >> 1);

#if (CANIF_EXTENDEDID_SUPPORT == STD_ON)
                  diffId = (sint32)(CanId - CANIF_CFG_RX_ID(mid));

#else
                  diffId = (sint16)(CanId - CANIF_CFG_RX_ID(mid));
#endif
      
                
                  if (diffId == 0 ) 
                  {
                    resultId = mid;
                    break;
                  } 
                  if (diffId > 0) {
                    last = mid;
                  } 
                  else 
                  {
                    first = mid;
                  }

                  if((last - first) < 2)
                  {
                    if(CanId == CANIF_CFG_RX_ID(first))
                    {
                      resultId = first;
                      break;
                    } 
                    else if(CanId == CANIF_CFG_RX_ID(last))
                    { 
                      resultId = last;
                      break;
                    } 
                    else
                    {
                      break;
                    }
                  }
                }
                
                if (resultId != CanIf_RxPduHnd_INVALID) 
                {
                  CanIf_Indirect_HlIndication(Hrh, resultId, CanSduPtr, CanDlc, CanId);
                } 
                else 
                {
                  /* Not found - ignore received PDU */
                }
              }
#endif
#if (CANIF_SEARCH_ALGORITHM == CANIF_DOUBLE_HASH)
              if (continueSearch == TRUE)
              {
                hash1 = ((CanId ^ CANIF_CFG_RXDHRANDOMNUMBER1(CANIF_CFG_MAILBOX(Hrh, eController))) % CANIF_CFG_RXDHADJUSTCOUNT);
                hash2 = ((CanId ^ CANIF_CFG_RXDHRANDOMNUMBER2(CANIF_CFG_MAILBOX(Hrh, eController))) % CANIF_CFG_RXDHADJUSTCOUNT);
                RxPduId = ((uint16)CANIF_CFG_RXDHADJUST(hash1)) + ((uint16)CANIF_CFG_RXDHADJUST(hash2));
                if (RxPduId >= CANIF_CFG_MAX_RXPDUHANDLE)
                {
                  RxPduId -= CANIF_CFG_MAX_RXPDUHANDLE;
                }
                if (CANIF_CFG_RX_ID(RxPduId) == CanId)
                {
                  /* ID matches - Pdu identified */
                  CanIf_Indirect_HlIndication(Hrh, RxPduId, CanSduPtr, CanDlc, CanId);
                }
              }
#endif
#if (CANIF_SEARCH_ALGORITHM == CANIF_LINEAR)
              /* Basic CAN message */
              /* Checked for invalid RxPduId earlier */
              do 
              {
                if (CANIF_CFG_RX_ID(RxPduId) == (CanId & CANIF_CFG_RX_MASK(RxPduId)) ) 
                {
                  /* ID matches - Pdu identified */
                  CanIf_Indirect_HlIndication(Hrh, RxPduId, CanSduPtr, CanDlc, CanId);
                  break;
                }
              }
              while ( ( (CANIF_CFG_RX_MASK(RxPduId--) & CANIF_STOP_FLAG) != CANIF_STOP_FLAG) );
              /* Index 0 in generated table ALWAYS has the STOP_FLAG set (see while condition), 
                 Underrun to 0xFFFF only in case of not matched -> RxPduId will not be used any more */
#endif

#if (CANIF_DEV_ERROR_DETECT == STD_ON)
            } 
            else 
            {
              /* Hrh does not belong to Rx Mailbox */
              CanIf_Det_ReportError(CANIF_RXINDICATION_API, CANIF_E_CONFIG);
            }
#endif
          }
        }
      }
    }
  }
}


/*******************************************************************************************************************
| NAME:             CanIf_HlIndication()
| SID:              0x14
| CALLED BY:        CanIf_RxIndication
| PRECONDITIONS:    CAN Interface initialized
| INPUT PARAMETERS: CanIf_HwHandleType Hrh: Handle of hardware object
|                   Can_IdType CanId: Id of receive message
|                   uint8 CanDlc: DLC of received message
|                   const uint8 *CanSduPtr: Pointer to data of received message
| RETURN VALUES:    none
| DESCRIPTION:      DLC check, Call of user indication function
*******************************************************************************************************************/
#if (CANIF_SUPPORT_NMOSEK_INDICATION == STD_ON)
/* static void CanIf_HlIndication(uint8 Hrh, PduIdType PduId, const uint8 *CanSduPtr, uint8 CanDlc, Can_IdType CanId) */
STATIC FUNC(void, CANIF_CODE) CanIf_HlIndication(CanIf_HwHandleType  Hrh, PduIdType PduId, P2CONST(uint8, AUTOMATIC, CANIF_CBK_DRV_VAR) CanSduPtr, uint8 CanDlc, Can_IdType CanId)
#else
/* static void CanIf_HlIndication(uint8 Hrh, PduIdType PduId, const uint8 *CanSduPtr, uint8 CanDlc) */
STATIC FUNC(void, CANIF_CODE) CanIf_HlIndication(CanIf_HwHandleType  Hrh, PduIdType PduId, P2CONST(uint8, AUTOMATIC, CANIF_CBK_DRV_VAR) CanSduPtr, uint8 CanDlc)
#endif
{
  CANIF_CHANNEL_CANTYPE_LOCAL

#if (V_USE_DUMMY_STATEMENT == STD_ON)
  CanDlc = CanDlc; /* Avoid compiler warnings as CanDlc is not used in all configurations */
#endif
#if (CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
  /* Acquire controller from CanIf_Mailbox struct */
  controller = CANIF_CFG_MAILBOX(Hrh, eController);
#endif

#if ((CANIF_DEV_ERROR_DETECT == STD_ON) && (CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF))
  if (controller >= CANIF_CFG_GENERIC_EMAXCONTROLLER) 
  {
    CanIf_Det_ReportError(CANIF_RXINDICATION_API, CANIF_E_CONFIG);
  } 
  else if (CanIf_ControllerMode[controller] == CANIF_CS_UNINIT ) 
  {
    CanIf_Det_ReportError(CANIF_RXINDICATION_API, CANIF_E_UNINIT);
  } 
  else 
#else
# if ((CANIF_DEV_ERROR_DETECT == STD_ON) && (CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON))
  if (CanIf_ControllerMode[CanIf_Controller_Value_Local] == CANIF_CS_UNINIT ) 
  {
    CanIf_Det_ReportError(CANIF_RXINDICATION_API, CANIF_E_UNINIT);
  } 
  else
# endif
#endif
  {
    if (CanIf_ControllerMode[CanIf_Controller_Value_Local] == CANIF_CS_STARTED) 
    {

#if (CANIF_WAKEUP_VALIDATION == STD_ON)
# if (CANIF_WAKEUP_VALID_ALL_RX_MSGS != STD_ON)
      if (CanIf_WakeUpValidationState[CanIf_Controller_Value_Local] == CANIF_WUVALIDATION_ARMED) 
      {
        /* Only ECUs receive list will validate an Rx event / Controllermode: Started, PduMode: Don't care*/
        CanIf_WakeUpValidationState[CanIf_Controller_Value_Local] = CANIF_WUVALIDATION_DETECTED;
      }
# endif
#endif
      if ( (CanIf_ChannelMode[CanIf_Controller_Value_Local] == CANIF_GET_ONLINE) ||
           (CanIf_ChannelMode[CanIf_Controller_Value_Local] == CANIF_GET_RX_ONLINE) ||
           (CanIf_ChannelMode[CanIf_Controller_Value_Local] == CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE) ) 
      {
#if (CANIF_DLC_CHECK == STD_ON)
        /* DLC check - if configured DLC == 0 the following condition is always false and DLC check is deactivated */
        if (CanDlc < CANIF_CFG_RX(PduId, eDlc) ) 
        {
# if (CANIF_USER_DLC_ERROR_NOTIFICATION == STD_ON)
          CanIf_DlcErrorNotifictionFctType dlcErrorNotification;
# endif          
# if (CANIF_DEM_REPORT_DLC_FAILED == STD_ON)
          /* Notification to DEM */
          CanIf_Dem_ReportError(CANIF_INDIRECT_E_INVALID_DLC);
# endif
# if (CANIF_USER_DLC_ERROR_NOTIFICATION == STD_ON)
          /* Notification to Application */
          dlcErrorNotification = CANIF_CFG_DLCERRORNOTIFICATION();
          if (dlcErrorNotification != NULL_PTR)
          {
            dlcErrorNotification(PduId);
          }
# endif
        } 
        else 
#endif

        {
#if (CANIF_READRXPDUDATA_API == STD_ON)
          /* Store Ptr to Sdu, set valid */
          CanIf_RxSduPtr = CanSduPtr;
#endif

          /* Parameter Check */
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
          if ( CANIF_CFG_RX(PduId, eRxIndication) >= CANIF_CFG_GENERIC(eMaxRxIndication) ) 
          {
            CanIf_Det_ReportError(CANIF_RXINDICATION_API, CANIF_E_CONFIG);
          } 
          else 
#endif
          {
            uint8 index;
            index = CANIF_CFG_RX(PduId, eRxIndication);

            if (CANIF_CFG_RXINDICATION(index).eRxIndicationLayout == CanIf_SimpleRxIndicationLayout) 
            {
              CanIf_SimpleRxIndicationFctType rxIndicationFct;
              rxIndicationFct = CANIF_CFG_RXINDICATION(index).eRxIndicationFct.eSimpleRxIndicationType;
              if (rxIndicationFct != NULL_PTR) 
              {
                /* CA cast (-> to get the const ) */
                /* CANIF_APPL_VAR -> located in CAN Driver */
                rxIndicationFct(CANIF_CFG_RX(PduId, eUpperPduId), (P2CONST(uint8, AUTOMATIC, CANIF_UL_STANDARD_VAR))CanSduPtr);
              }
            } 
            else 
#if (CANIF_SUPPORT_NMOSEK_INDICATION == STD_ON)
            if (CANIF_CFG_RXINDICATION(index).eRxIndicationLayout == CanIf_NmOsekRxIndicationLayout) 
            {
              CanIf_NmOsekRxIndicationFctType rxIndicationFct;
              rxIndicationFct = CANIF_CFG_RXINDICATION(index).eRxIndicationFct.eNmOsekRxIndicationType;
              if (rxIndicationFct != NULL_PTR) 
              {
                /* CA cast (-> to get the const ) */
                /* CANIF_APPL_VAR -> located in CAN Driver */
                rxIndicationFct(CANIF_CFG_RX(PduId, eUpperPduId), (P2CONST(uint8, AUTOMATIC, CANIF_UL_OSEKNM_VAR))CanSduPtr, CanId);
              }
            
            } 
            else 
#endif
            {
              CanIf_AdvancedRxIndicationFctType rxIndicationFct;
              PduInfoType pduinfo;
              /* cast from CANIF_CBK_DRV_VAR to AUTOSAR_COMSTACKDATA --> has to be resolved in compiler abstraction configuration */
              /* const to non-const cast is not avoidable */
              pduinfo.SduDataPtr = (P2VAR(uint8, AUTOMATIC, AUTOSAR_COMSTACKDATA))CanSduPtr;
#if (CANIF_RX_PASS_STATIC_DLC == STD_ON)
              /* old requirement: CANIF262: Predefined DLC is passed to upper layer not the currently received one */
              pduinfo.SduLength = CANIF_CFG_RX(PduId, Dlc);
#else
              /* new requirement: CANIF262: Currently received DLC value is passed to upper layer */
              pduinfo.SduLength = CanDlc;
#endif
              rxIndicationFct = CANIF_CFG_RXINDICATION(index).eRxIndicationFct.eAdvancedRxIndicationType;
              if (rxIndicationFct != NULL_PTR) 
              {
                /* CA cast (-> to get the const ) */
                /* PTR to Stack -> AUTOMATIC */
                rxIndicationFct(CANIF_CFG_RX(PduId, eUpperPduId), (P2CONST(PduInfoType, AUTOMATIC, CANIF_UL_ADVANCED_VAR))&pduinfo);
              }
            }
          }
# if (CANIF_READRXPDUDATA_API == STD_ON)
          /* Set invalid */
          CanIf_RxSduPtr = NULL_PTR;
# endif            
        }
      }
    }
  }
}

/*******************************************************************************************************************
| NAME:             CanIf_ControllerBusOff()
| SID:              0x16
| CALLED BY:        CAN Driver
| PRECONDITIONS:    -
| INPUT PARAMETERS: uint8 Controller: Controller
| RETURN VALUES:    none
| DESCRIPTION:      Indication of BusOff from CAN Driver
*******************************************************************************************************************/
/* void CanIf_ControllerBusOff(uint8 Controller) */
FUNC(void, CANIF_CODE) CanIf_ControllerBusOff(uint8 Controller)
{

#if (CANIF_DEV_ERROR_DETECT == STD_ON)
  if (Controller >= CANIF_CFG_GENERIC_EMAXCONTROLLER) 
  {
    CanIf_Det_ReportError(CANIF_CONTROLLERBUSOFF_API, CANIF_E_PARAM_CONTROLLER);
  } 
  else if (CanIf_ControllerMode[CanIf_Controller_Value] == CANIF_CS_UNINIT ) 
  {
    CanIf_Det_ReportError(CANIF_CONTROLLERBUSOFF_API, CANIF_E_UNINIT);
  } 
  else 
#endif
  {
    CanIf_BusOffNotificationFctType busoffnotificationFct;

    /* Explicitely cast to void as return value cannot be used here */    
    (void)CanIf_SetControllerMode(CanIf_Controller_Value, CANIF_CS_STOPPED);
    /* Set CAN Interface to Stopped mode, CAN Controller is BusOff */
    CanIf_ControllerMode[CanIf_Controller_Value] = CANIF_CS_STOPPED;

    busoffnotificationFct = CANIF_CFG_BUSOFFNOTIFICATION();

    if (busoffnotificationFct != NULL_PTR) {
#if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
      busoffnotificationFct((ComM_ChannelHandleType)CanIf_Controller_Value);
#else
      busoffnotificationFct(CanIf_Controller_Value);
#endif
    }
  }
#if ((CANIF_ONE_CONTROLLER_OPTIMIZATION==STD_ON) && (CANIF_DEV_ERROR_DETECT == STD_OFF) && (V_USE_DUMMY_STATEMENT == STD_ON))
  Controller = Controller;
#endif
}



/*******************************************************************************************************************
| NAME:             CanIf_SetPduMode()
| SID:              0x09
| CALLED BY:        Application
| PRECONDITIONS:    CAN Interrupts are not disabled
| INPUT PARAMETERS: uint8 Channel, CanIf_ChannelRequestTypeChannelRequest
| RETURN VALUES:    none
| DESCRIPTION:      Set channel mode of specified channel
*******************************************************************************************************************/
#if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
/* Std_ReturnType CanIf_SetChannelMode(uint8 Channel, CanIf_ChannelSetModeType ChannelRequest) */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetChannelMode(uint8 Channel, CanIf_ChannelSetModeType ChannelRequest)
#else
/* Std_ReturnType CanIf_SetPduMode(uint8 Controller, CanIf_PduSetModeType PduModeRequest) */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPduMode(uint8 Controller, CanIf_PduSetModeType PduModeRequest)
#endif
{
  Std_ReturnType retval;

#if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
  /* Function parameter mapping */
  uint8                     Controller;
  CanIf_ChannelSetModeType  PduModeRequest;

  Controller      = Channel;
  PduModeRequest  = ChannelRequest;
#endif

  retval = E_NOT_OK;
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
  if (Controller >= CANIF_CFG_GENERIC_EMAXCONTROLLER) 
  {
    CanIf_Det_ReportError(CANIF_SETPDUMODE_API, CANIF_E_PARAM_CONTROLLER);
  } 
  else if (CanIf_ControllerMode[CanIf_Controller_Value] == CANIF_CS_UNINIT) 
  {
    CanIf_Det_ReportError(CANIF_SETPDUMODE_API, CANIF_E_UNINIT);
  } 
  else 
#endif
  {
    retval = E_OK;
    /* Channel mode transitions only available in CANIF_CS_STARTED mode */
    if (CanIf_ControllerMode[CanIf_Controller_Value] == CANIF_CS_STARTED) 
    {
      CanIf_EnterCritical(CANIF_EXCLUSIVE_AREA_3);

      /* Do allow transitions if target mode is equal current mode */
      if(CanIfState[CanIf_ChannelMode[CanIf_Controller_Value]][PduModeRequest] != CANIF_NOP)
      {
        switch (PduModeRequest) 
        {
          case CANIF_SET_OFFLINE:
          case CANIF_SET_TX_OFFLINE:
          case CANIF_SET_TX_OFFLINE_ACTIVE:
            switch(CanIf_ChannelMode[CanIf_Controller_Value])
            {
              case CANIF_GET_TX_ONLINE:
              case CANIF_GET_ONLINE:
                CanIf_ClearQueue(CANIF_CHANNEL_CANPARA_ONLY);
                break;
            }
            break;
          case CANIF_SET_ONLINE:
          case CANIF_SET_TX_ONLINE:
#if (CANIF_PARTIAL_NETWORK == STD_ON)
            if((CANIF_CFG_WU_TXPDU_FILTER_ACTIVE(CanIf_Controller_Value) == TRUE) && (CANIF_CFG_WU_TXPDU_HANDLE(CanIf_Controller_Value) != (PduIdType) -1))
            {
              CanIf_WUTxPDU_Filter_Active[CanIf_Controller_Value] = TRUE;
            }
#endif
            break;
          default:
            break;
        }
        CanIf_ChannelMode[CanIf_Controller_Value] = (CanIf_PduGetModeType)CanIfState[CanIf_ChannelMode[CanIf_Controller_Value]][PduModeRequest];
      }
      CanIf_LeaveCritical(CANIF_EXCLUSIVE_AREA_3);
    }
  }
# if ((CANIF_ONE_CONTROLLER_OPTIMIZATION==STD_ON) && (CANIF_DEV_ERROR_DETECT == STD_OFF) && (V_USE_DUMMY_STATEMENT == STD_ON))
  Controller = Controller;
# endif
  return retval;
}

/*******************************************************************************************************************
| NAME:             CanIf_GetPduMode()
| SID:              0x0A
| CALLED BY:        Application
| PRECONDITIONS:    -
| INPUT PARAMETERS: uint8 Channel, CanIf_ChannelModeType *ChannelModePtr
| RETURN VALUES:    Std_ReturnType (E_OK, E_NOT_OK)
| DESCRIPTION:      Request channel mode of specified channel
*******************************************************************************************************************/
#if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
/* Std_ReturnType CanIf_GetChannelMode(uint8 Channel, CanIf_ChannelGetModeType *ChannelModePtr) */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetChannelMode(uint8 Channel, P2VAR(CanIf_ChannelGetModeType, AUTOMATIC, CANIF_APPL_STATE_VAR) ChannelModePtr)
#else
/* Std_ReturnType CanIf_GetPduMode(uint8 Controller, CanIf_PduGetModeType *PduModePtr) */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetPduMode(uint8 Controller, P2VAR(CanIf_PduGetModeType, AUTOMATIC, CANIF_APPL_STATE_VAR) PduModePtr)
#endif
{
  Std_ReturnType retval;

#if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
  uint8                   Controller;
  P2VAR(CanIf_PduGetModeType, AUTOMATIC, CANIF_APPL_STATE_VAR) PduModePtr;

  Controller  = Channel;
  PduModePtr  = ChannelModePtr;
#endif
#if ((CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON) && (V_USE_DUMMY_STATEMENT == STD_ON))
  Controller = Controller;
#endif
  /* Default return value */
  retval = E_NOT_OK;

#if (CANIF_DEV_ERROR_DETECT == STD_ON)
  if (CanIf_ControllerMode[CanIf_Controller_Value] == CANIF_CS_UNINIT) 
  {
    /* Channel mode unspecified in CANIF_CS_UNINIT mode */
    CanIf_Det_ReportError(CANIF_GETPDUMODE_API, CANIF_E_UNINIT);
  } 
# if defined (CANIF_ENABLE_SELECTABLE_PB)
  else if (CANIF_CFG == NULL_PTR) 
  {
    CanIf_Det_ReportError(CANIF_GETPDUMODE_API, CANIF_E_PARAM_POINTER);
  } 
# endif
# if (CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
  else if (Controller >= CANIF_CFG_GENERIC_EMAXCONTROLLER) 
  {
    CanIf_Det_ReportError(CANIF_GETPDUMODE_API, CANIF_E_PARAM_CONTROLLER);
  }
# endif

  else if (PduModePtr == NULL_PTR) 
  {
    CanIf_Det_ReportError(CANIF_GETPDUMODE_API, CANIF_E_PARAM_POINTER);
  } 
  else 
#endif
  {
    *PduModePtr = CanIf_ChannelMode[CanIf_Controller_Value];
    retval = E_OK;
  }
  return retval;
}

#if (CANIF_TRANSMIT_BUFFER == STD_ON)
/*******************************************************************************************************************
| NAME:             CanIf_TxQueueTransmit()
| CALLED BY:        CanIf_TxQueueTreatment
| PRECONDITIONS:    critical section already entered (secure queue)
| INPUT PARAMETERS: CANIF_CHANNEL_CANTYPE_ONLY: Controller (in case of optimization one channel -> void),
|                   PduIdType PduId ( has to be a Normal Tx PDU )
| RETURN VALUES:    none
| DESCRIPTION:      Transmit message and remove from queue
*******************************************************************************************************************/
/* static void CanIf_TxQueueTransmit(uint8 Controller, PduIdType PduId) */
STATIC FUNC(Std_ReturnType, CANIF_CODE) CanIf_TxQueueTransmit(CANIF_CHANNEL_CANTYPE_FIRST PduIdType PduId)
{
  Can_PduType localPdu;
  Can_ReturnType txResult;
  Std_ReturnType retval;
# if CANIF_SETDYNAMICTXID_API == STD_ON
  PduIdType       DynamicPduId;
# endif
# if (CANIF_BITQUEUE == STD_ON)
  uint8 queueElementIdx;
  uint8 elementBitIdx;
  PduIdType queueBitPos;
# endif


# if (CANIF_SETDYNAMICTXID_API == STD_ON)
            DynamicPduId = CANIF_CFG_STAT2DYN_INDIRECTION(PduId);
            if(DynamicPduId != (PduIdType)-1)
            {
              (localPdu).id = CanIf_DynTxId[DynamicPduId];
            }
            else
            {
              (localPdu).id = CANIF_CFG_TX(PduId, eId);
            }
# else
            (localPdu).id = CANIF_CFG_TX(PduId, eId);
# endif
# if (CANIF_DYNAMIC_TX_DLC == STD_ON)
            (localPdu).length = (uint8)CanIf_TxQueue[CANIF_CFG_TX_QUEUEINDEX(PduId)].eSduLength;
# else
            (localPdu).length = CANIF_CFG_TX(PduId, eLength); 
# endif
            (localPdu).sdu = CanIf_TxQueue[CANIF_CFG_TX_QUEUEINDEX(PduId)].eSdu;                                                   \
            (localPdu).swPduHandle = (PduId);

  txResult = Can_Write(CANIF_CFG_TX(PduId, eHth), &localPdu);
  if (txResult == CAN_OK) 
  { /*tx requested in hw*/
# if (CANIF_BITQUEUE == STD_ON)
    queueBitPos  = PduId + CANIF_CFG_TXQUEUE_PADBITS(CanIf_Controller_Value);
    queueElementIdx = (uint8)(queueBitPos >> kCanTxQueueShift); /* get the queue element where to set the flag */
    elementBitIdx  = (uint8)(queueBitPos & kCanTxQueueMask);   /* get the flag index wihtin the queue element */
    canIf_TxQueueFlags[queueElementIdx] &= ~CanShiftLookUp[elementBitIdx]; /* clear flag from the queue */
# else
    CanIf_TxQueue[CANIF_CFG_TX_QUEUEINDEX(PduId)].eQueued = 0;
    CanIf_TxQueueCounter[CanIf_Controller_Value] --;
# endif
    retval = E_OK;
  } 
  else if (txResult == CAN_BUSY)
  { /*also ok due to confirmation queue handling may be interrupted by canif_transmit() or just a cancel request*/
    retval = E_OK;
  }
  else /*CAN_NOT_OK*/
  {
    retval = E_NOT_OK;
  }
  return retval;
}
#endif



#if (CANIF_TRANSMIT_BUFFER == STD_ON)
/*******************************************************************************************************************
| NAME:             CanIf_TxQueueTreatment()
| CALLED BY:        CanIf_TxConfirmation
| PRECONDITIONS:    critical section already entered (secure queue)
| INPUT PARAMETERS: uint8 Controller
| RETURN VALUES:    none
| DESCRIPTION:      Check if queued PDUs have to be transmitted
*******************************************************************************************************************/
/* static void CanIf_TxQueueTreatment(uint8 Controller) */
STATIC FUNC(Std_ReturnType, CANIF_CODE) CanIf_TxQueueTreatment(uint8 Controller)
{
  PduIdType PduId;
  Std_ReturnType retval;

# if (CANIF_BITQUEUE == STD_ON)
  /* FOR-loop: cnt.-variable */
  sint8_least queueElementIdx; 
  /* FOR-loop: stores the end-condition, improves performance */
  sint8_least queueEndElementIdx;
  sint8  elementBitIdx;
  CanIf_TxQueueFlagType  elem;
# endif

# if ((CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON) && (V_USE_DUMMY_STATEMENT == STD_ON))
  Controller = Controller;
# endif  
 
  retval = E_NOT_OK; /*default nothing to send*/

# if (CANIF_BITQUEUE == STD_ON)
   /* Get the end-condition of the following FOR-loop */
  queueEndElementIdx = (sint8_least)(CANIF_CFG_TXQUEUE_STARTINDEX(CanIf_Controller_Value));

  /* process from last to first */
  for(queueElementIdx = CANIF_CFG_TXQUEUE_STARTINDEX(CanIf_Controller_Value+1)-1; queueElementIdx >= queueEndElementIdx; queueElementIdx--)
  { 
    elem = canIf_TxQueueFlags[queueElementIdx];
    if(elem != (CanIf_TxQueueFlagType)0) /* is there any flag set in the queue element? */
    {
      /* iterate through all flags and notify application for every scheduled transmission */
      for(elementBitIdx = ((sint8)1 << kCanTxQueueShift) - (sint8)1; elementBitIdx >= (sint8)0; elementBitIdx--)
      { 
        if( ( elem & CanShiftLookUp[elementBitIdx] ) != (CanIf_TxQueueFlagType)0)
        {
          PduId = (((PduIdType)queueElementIdx << kCanTxQueueShift) + (PduIdType)elementBitIdx) - CANIF_CFG_TXQUEUE_PADBITS(CanIf_Controller_Value);
          /* Send and remove from queue */
          retval = CanIf_TxQueueTransmit(CANIF_CHANNEL_CANPARA_FIRST PduId);
		  break;
        }
      }
    }
  }
# else
  if (CanIf_TxQueueCounter[CanIf_Controller_Value] != 0) 
  {
    /* CanIf_TxQueueCounter always 0 if CanIf_ControllerConfiguration[Controller]->TxStopIndex = 0 */
    for (PduId = CANIF_CFG_CONTROLLER(CanIf_Controller_Value, eTxBCStopIndex) - (PduIdType)1; PduId > CANIF_CFG_CONTROLLER(CanIf_Controller_Value, eTxBCStartIndex); PduId--) 
    {
      if (CanIf_TxQueue[CANIF_CFG_TX_QUEUEINDEX(PduId)].eQueued != 0) 
      {
        /* Send and remove from queue */
        retval = CanIf_TxQueueTransmit(CANIF_CHANNEL_CANPARA_FIRST PduId);
        break;
      }
    }
    /* Avoid usage of signed datatype for PduId */
    if (PduId == CANIF_CFG_CONTROLLER(CanIf_Controller_Value, eTxBCStartIndex)) 
    {
      if (CanIf_TxQueue[CANIF_CFG_TX_QUEUEINDEX(PduId)].eQueued != 0) 
      {
        /* Send and remove from queue */
        retval = CanIf_TxQueueTransmit(CANIF_CHANNEL_CANPARA_FIRST PduId);
      }
    }
  }
# endif
  return retval;
}
#endif

#if (CANIF_READRXPDUDATA_API == STD_ON)
/*******************************************************************************************************************
| NAME:             CanIf_ReadRxPduData()
| SID:              0x06
| CALLED BY:        Upper layer
| PRECONDITIONS:    CanIf Initialized
| INPUT PARAMETERS: PduIdType CanRxPduId - specifies RxPpdu
|                   PduInfoType *PduInfoPtr - Pointer to struct to copy DLC and data to
| RETURN VALUES:    Std_ReturnType
| DESCRIPTION:      Provide DLC and data of the specified Pdu to upper layers
*******************************************************************************************************************/
/* Std_ReturnType CanIf_ReadRxPduData(PduIdType CanRxPduId, PduInfoType *PduInfoPtr) */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReadRxPduData(PduIdType CanRxPduId, P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_MSG_VAR) PduInfoPtr)
{
  Std_ReturnType retval;
  
  retval = E_NOT_OK;
  /* Check for valid parameters */
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
  if (CanRxPduId >= CANIF_CFG_GENERIC(eMaxRxPDUHandle)) 
  {
    CanIf_Det_ReportError(CANIF_READRXDATA_API, CANIF_E_PARAM_LPDU);
  } 
  else if (PduInfoPtr == NULL_PTR) 
  {
    CanIf_Det_ReportError(CANIF_READRXDATA_API, CANIF_E_PARAM_POINTER);
  } 
  else 
#endif
  {
    if (CanIf_RxSduPtr != NULL_PTR) 
    {
      uint8 len;
      /* Deviation: No check if CanIf is CANIF_CS_UNINIT for current controller, 
         we do not know which controller received this PDU */
      /* Same problem for the channel mode */
   
      /* Assuming a copy from a temp buffer in same memory section */
      len = CANIF_CFG_RX(CanRxPduId, eDlc);
      PduInfoPtr->SduLength = len;      
      while (len > 0) 
      {
        len--;
        PduInfoPtr->SduDataPtr[len] = CanIf_RxSduPtr[len];
      }
      retval = E_OK; 
    } 
    else 
    {
      /* RxData Invalid, HwBuffer or Temporary buffer can be overwritten */
    }
  }
  return retval;
}
#endif


#if (CANIF_VERSION_INFO_API == STD_ON)
/*******************************************************************************************************************
| NAME:             CanIf_GetVersionInfo()
| SID:              0x0B
| CALLED BY:        Upper layer
| PRECONDITIONS:
| INPUT PARAMETERS: versioninfo - buffer to copy version info to
| RETURN VALUES:    Std_ReturnType
| DESCRIPTION:      Provide DLC and data of the specified Pdu to upper layers
*******************************************************************************************************************/
/* void CanIf_GetVersionInfo(Std_VersionInfoType *Versioninfo) */
FUNC(void, CANIF_CODE)CanIf_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CANIF_APPL_VAR) VersionInfo)
{
# if (CANIF_DEV_ERROR_DETECT == STD_ON)
  if (VersionInfo == NULL_PTR)
  {
    CanIf_Det_ReportError(CANIF_GETVERSIONINFO_API, CANIF_E_PARAM_POINTER);
  }
  else
# endif
  {
    VersionInfo->vendorID         = CANIF_VENDOR_ID;
    VersionInfo->moduleID         = CANIF_MODULE_ID;
    VersionInfo->instanceID       = 0;
    VersionInfo->sw_major_version = CANIF_SW_MAJOR_VERSION;
    VersionInfo->sw_minor_version = CANIF_SW_MINOR_VERSION;
    VersionInfo->sw_patch_version = CANIF_SW_PATCH_VERSION;
  }
}
#endif



/*******************************************************************************************************************
| NAME:             CanIf_InitMemory()
| SID:              none
| CALLED BY:        Upper layer
| PRECONDITIONS:    
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Initializes global variables. This function has to be called
|                   before any other calls to the CanIf API
*******************************************************************************************************************/
FUNC(void, CANIF_CODE) CanIf_InitMemory(void)
{
  CANIF_CHANNEL_CANTYPE_LOCAL
# if defined (CANIF_ENABLE_SELECTABLE_PB)
  CanIf_Configuration = NULL_PTR;
# endif
#if (CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
  for (controller = 0; controller < CanIf_Config.eMaxController; controller++) 
#endif
  {
    CanIf_ControllerMode[CanIf_Controller_Value_Local] = CANIF_CS_UNINIT;
  }
}



#if (CANIF_TRANSMIT_BUFFER == STD_ON)
# if (CANIF_TRANSMIT_CANCELLATION == STD_ON)
/*******************************************************************************************************************
| NAME:             CanIf_CancelTxConfirmation()
| SID:              0x15
| CALLED BY:        CAN Driver
| PRECONDITIONS:    CanInterface is initialized
|                   Valid PDU ID is passed
| INPUT PARAMETERS: const Can_PduType*
| RETURN VALUES:    none
| DESCRIPTION:      CanIf is indicated of a cancelled PDU by the driver
*******************************************************************************************************************/
/* void CanIf_CancelTxConfirmation(const Can_PduType* PduInfoPtr) */
FUNC(void, CANIF_CODE) CanIf_CancelTxConfirmation(P2CONST(Can_PduType, AUTOMATIC, CANIF_CBK_DRV_VAR) PduInfoPtr)
{
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
  if (PduInfoPtr->swPduHandle >= CANIF_CFG_GENERIC(eMaxTxPDUHandle)) 
  {
    CanIf_Det_ReportError(CANIF_TXCONFIRMATION_API, CANIF_E_PARAM_LPDU);
  } 
  else if (CanIf_ControllerMode[CANIF_CFG_TX(PduInfoPtr->swPduHandle, eController)] == CANIF_CS_UNINIT ) 
  {
    CanIf_Det_ReportError(CANIF_TXCONFIRMATION_API, CANIF_E_UNINIT);
  } 
  else 
#endif
  {
    PduIdType queueindex;
    CANIF_CHANNEL_CANTYPE_LOCAL
#if (CANIF_BITQUEUE == STD_ON)
    uint8 queueElementIdx; /* index for accessing the tx queue */
    uint8 elementBitIdx;  /* bit index within the tx queue element */
    PduIdType queueBitPos;  /* physical bitposition of the handle */
#endif

#if (CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
    controller = CANIF_CFG_TX(PduInfoPtr->swPduHandle, eController);
#endif

    /* Check if PduInfoPtr->swPduHandle is queued */
    queueindex = CANIF_CFG_TX_QUEUEINDEX(PduInfoPtr->swPduHandle);

    /* Check if queue is affected (Normal Tx object) */
    if (queueindex != (PduIdType)-1) 
    {
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
      if (queueindex >= CANIF_CFG_GENERIC(eMaxTxPDUHandle))
      {
        CanIf_Det_ReportError(CANIF_CANCELTRANSMIT_API, CANIF_E_PARAM_LPDU);
      } 
      else
#endif
      {
        CanIf_EnterCritical(CANIF_EXCLUSIVE_AREA_1); 
#if (CANIF_BITQUEUE == STD_ON)
        queueBitPos  = (PduInfoPtr->swPduHandle) + CANIF_CFG_TXQUEUE_PADBITS(CanIf_Controller_Value_Local);
        queueElementIdx = (uint8)(queueBitPos >> kCanTxQueueShift); /* get the queue element where to set the flag */
        elementBitIdx  = (uint8)(queueBitPos & kCanTxQueueMask);   /* get the flag index wihtin the queue element */
        if( (canIf_TxQueueFlags[queueElementIdx] & CanShiftLookUp[elementBitIdx]) == (CanIf_TxQueueFlagType)0 )
        {
          PduLengthType len; 
          /* Buffer is free, store the cancelled one */
          canIf_TxQueueFlags[queueElementIdx] |= CanShiftLookUp[elementBitIdx];
#else
        if (CanIf_TxQueue[queueindex].eQueued == 0) 
        {
          PduLengthType len; 
          /* Buffer is free, store the cancelled one */
          CanIf_TxQueue[queueindex].eQueued = 1;
#endif


          CanIf_TxQueue[queueindex].eSduLength = PduInfoPtr->length;
          for (len = 0; len < PduInfoPtr->length; len++) 
          {
            CanIf_TxQueue[queueindex].eSdu[len] = PduInfoPtr->sdu[len];
          }
          /* Find appropriate controller for swPduHandle */
#if (CANIF_BITQUEUE == STD_OFF)  
# if (CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
          controller = CANIF_CFG_TX(PduInfoPtr->swPduHandle, eController);
# endif
          CanIf_TxQueueCounter[CanIf_Controller_Value_Local] ++;
#endif
        }
        else
        {
          /* Newer PDU already queued, discard the cancelled one */
        }
        CanIf_LeaveCritical(CANIF_EXCLUSIVE_AREA_1); 
      }
      /* Send queued messages directly */
      CanIf_EnterCritical(CANIF_EXCLUSIVE_AREA_2); 
      (void)CanIf_TxQueueTreatment(CANIF_CFG_TX(PduInfoPtr->swPduHandle, eController));
      CanIf_LeaveCritical(CANIF_EXCLUSIVE_AREA_2);  /*lock over queue handling + write call (driver does not expect direct call inbetween)*/
    } 
    else 
    {
      /* Full CANs won't be cancelled */
    }
    
  }
}
# endif
#endif



#if (CANIF_CANCEL_SUPPORT_API == STD_ON)
/*******************************************************************************************************************
| NAME:             CanIf_CancelTransmit()
| SID:              -
| CALLED BY:        Upper layer
| PRECONDITIONS:    CanInterface is initialized
|                   Valid PDU ID is passed
| INPUT PARAMETERS: PduIdType
| RETURN VALUES:    none
| DESCRIPTION:      Initiate cancellation of a TxPDU
*******************************************************************************************************************/
/* void CanIf_CancelTransmit(PduIdType CanTxPduId) */
FUNC(void, CANIF_CODE) CanIf_CancelTransmit(PduIdType CanTxPduId)
{
  /* Check if CanTxPduId is valid */
#if (CANIF_DEV_ERROR_DETECT == STD_ON)
  if (CanTxPduId >= CANIF_CFG_GENERIC(eMaxTxPDUHandle)) 
  {
    CanIf_Det_ReportError(CANIF_CANCELTRANSMIT_API, CANIF_E_PARAM_LPDU);
  } 
  else
#endif
  {
    Can_HwHandleType  hth;
#if (CANIF_TRANSMIT_BUFFER == STD_ON)
    PduIdType         queueindex;
#endif
#if (CANIF_BITQUEUE == STD_ON)
    uint8 queueElementIdx; /* index for accessing the tx queue */
    uint8 elementBitIdx;  /* bit index within the tx queue element */
    PduIdType queueBitPos;  /* physical bitposition of the handle */
    CANIF_CHANNEL_CANTYPE_LOCAL
# if (CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
    /* Collect configuration data */
    controller = CANIF_CFG_TX_ECONTROLLER;
# endif
#endif
   
    hth = CANIF_CFG_TX(CanTxPduId, eHth);
#if (CANIF_TRANSMIT_BUFFER == STD_ON)
    /* Check if PDU has to be cancelled from queue */

    queueindex = CANIF_CFG_TX_QUEUEINDEX(CanTxPduId);

    /* Check if FullCAN message */
    if (queueindex != (PduIdType)-1) 
    {
# if (CANIF_DEV_ERROR_DETECT == STD_ON)
      if (queueindex >= CANIF_CFG_GENERIC(eMaxTxPDUHandle))
      {
        CanIf_Det_ReportError(CANIF_CANCELTRANSMIT_API, CANIF_E_PARAM_LPDU);
      } 
      else
# endif
      { 
        CanIf_EnterCritical(CANIF_EXCLUSIVE_AREA_1); 

# if (CANIF_BITQUEUE == STD_ON)
        queueBitPos  = CanTxPduId + CANIF_CFG_TXQUEUE_PADBITS(CanIf_Controller_Value_Local);
        queueElementIdx = (uint8)(queueBitPos >> kCanTxQueueShift); /* get the queue element where to set the flag */
        elementBitIdx  = (uint8)(queueBitPos & kCanTxQueueMask);   /* get the flag index wihtin the queue element */
        if( (canIf_TxQueueFlags[queueElementIdx] & CanShiftLookUp[elementBitIdx]) != (CanIf_TxQueueFlagType)0 )
        {
          canIf_TxQueueFlags[queueElementIdx] &= ~CanShiftLookUp[elementBitIdx]; /* clear flag from the queue */
# else
          if (CanIf_TxQueue[queueindex].eQueued != 0)
          {
            /* Cancel PDU from queue */
            CANIF_CHANNEL_CANTYPE_LOCAL

            CanIf_TxQueue[queueindex].eQueued = 0;
#  if (CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF)
            controller = CANIF_CFG_TX_ECONTROLLER;
#  endif
            CanIf_TxQueueCounter[CanIf_Controller_Value_Local] --;
# endif
            CanIf_LeaveCritical(CANIF_EXCLUSIVE_AREA_1); 
          } 
          else 
          {
            /* Handle not queued messages */
            Can_CancelTx(hth, CanTxPduId);
            CanIf_LeaveCritical(CANIF_EXCLUSIVE_AREA_1);
          }
        } 
      } 
      else 
      {
        /* Handle FullCan messages */
        Can_CancelTx(hth, CanTxPduId);
      }
# else  /* CANIF_TRANSMIT_BUFFER */
    Can_CancelTx(hth, CanTxPduId);
# endif /* CANIF_TRANSMIT_BUFFER */
  }
}

/*******************************************************************************************************************
| NAME:             CanIf_CancelTxNotification()
| SID:              -
| CALLED BY:        CAN Driver
| PRECONDITIONS:    CanInterface is initialized
|                   Valid PDU ID is passed
| INPUT PARAMETERS: PduIdType, cancellation was successful?
| RETURN VALUES:    none
| DESCRIPTION:      CAN Interface is notified of a cancelled PDU
|                   The confirmation won't be passed to upper layers
|                   Next message from queue will be transmitted
*******************************************************************************************************************/
/* void CanIf_CancelTxNotification(PduIdType PduId, CanIf_CancelResultType IsCancelled) */
FUNC(void, CANIF_CODE) CanIf_CancelTxNotification(PduIdType PduId, CanIf_CancelResultType IsCancelled)
{
# if (V_USE_DUMMY_STATEMENT == STD_ON)
  IsCancelled = IsCancelled; /* Avoid compiler warnings */
# endif
# if (CANIF_DEV_ERROR_DETECT == STD_ON)
  if (PduId >=  CANIF_CFG_GENERIC(eMaxTxPDUHandle)) 
  {
    CanIf_Det_ReportError(CANIF_TXNOTIFICATION_API, CANIF_E_PARAM_LPDU);
  } 
  else if (CanIf_ControllerMode[CANIF_CFG_TX_ECONTROLLER_X] == CANIF_CS_UNINIT ) 
  {
    CanIf_Det_ReportError(CANIF_TXNOTIFICATION_API, CANIF_E_UNINIT);
  } 
  else 
# endif
  {
    if (CanIf_ControllerMode[CANIF_CFG_TX_ECONTROLLER_X] == CANIF_CS_STARTED) 
    {
      if ( (CanIf_ChannelMode[CANIF_CFG_TX_ECONTROLLER_X] == CANIF_GET_ONLINE) || 
           (CanIf_ChannelMode[CANIF_CFG_TX_ECONTROLLER_X] == CANIF_GET_TX_ONLINE) ) 
      {
# if (CANIF_TRANSMIT_BUFFER == STD_ON)
        PduIdType queueindex;
        queueindex = CANIF_CFG_TX_QUEUEINDEX(PduId);

        /* Check if queue is affected (Normal Tx object) */
        if (queueindex != (PduIdType)-1) 
        {
          /* Send queued messages directly */
          CanIf_EnterCritical(CANIF_EXCLUSIVE_AREA_2);
          (void)CanIf_TxQueueTreatment(CANIF_CFG_TX_ECONTROLLER_X);
          CanIf_LeaveCritical(CANIF_EXCLUSIVE_AREA_2);  /*lock over queue handling + write call (driver does not expect direct call inbetween)*/
        }
# endif
      }
    }
  }
}

#endif

#if (CANIF_TRCV_HANDLING == STD_ON)
/*******************************************************************************************************************
| NAME:             CanIf_SetTransceiverMode()
| SID:              0x0D
| CALLED BY:        Ecu State Manager
| PRECONDITIONS:    Transceiver Driver is initialized
| INPUT PARAMETERS: uint8 Transceiver: Index to address transceiver
|                   CanIf_TransceiverModeType TransceiverMode: Requested transceiver mode
| RETURN VALUES:    E_OK: success / E_NOT_OK: fail
| DESCRIPTION:      Set transceiver to requested mode
*******************************************************************************************************************/
# if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
/* Std_ReturnType CanIf_SetTransceiverMode(uint8 CanNetwork, CanIf_TransceiverModeType TransceiverMode); */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTransceiverMode(uint8 CanNetwork, CanIf_TransceiverModeType TransceiverMode)
# else
/* Std_ReturnType CanIf_SetTransceiverMode(uint8 Transceiver, CanIf_TransceiverModeType TransceiverMode) */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTransceiverMode(uint8 Transceiver, CanIf_TransceiverModeType TransceiverMode)
# endif
{
  Std_ReturnType                  retval;

# if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
  uint8 Transceiver;

  Transceiver = CanNetwork;
# endif

  retval = E_NOT_OK;
# if (CANIF_DEV_ERROR_DETECT == STD_ON) 
  
  if (Transceiver >= CANIF_CFG_GENERIC(eMaxTransceivers)) 
  {
    CanIf_Det_ReportError(CANIF_SETTRANSCEIVERMODE_API, CANIF_TRCV_E_TRANSCEIVER);
  } 
  else
# endif /* CANIF_DEV_ERROR_DETECT */
  {
# if (CANIF_TRCV_MAPPING == STD_ON)
    uint8                           lowIndex;
    uint8                           lowAddress;
    CanIf_CanTrcv_SetOpModeFctType  lowFct;

    lowIndex   = CANIF_CFG_TRCVUPTOLOWMAP(Transceiver, eDriverIndex);
    lowAddress = CANIF_CFG_TRCVUPTOLOWMAP(Transceiver, eDriverAddress);

    lowFct = CanIf_TransceiverAPICanTrcv_SetOpModeFctMap[lowAddress];

    /* ESCAN00031640 */
    if (lowFct == NULL_PTR)
    {
      CanIf_Det_ReportError(CANIF_SETTRANSCEIVERMODE_API, CANIF_TRCV_E_TRANSCEIVER);
      /* retval is already set to E_NOT_OK */
    }
    else
    {
      retval = lowFct(TransceiverMode, lowIndex);
    }
# else
    retval = CanTrcv_SetOpMode(TransceiverMode, Transceiver);
# endif
  }
  return retval;
}
#endif


#if (CANIF_TRCV_HANDLING == STD_ON)
/*******************************************************************************************************************
| NAME:             CanIf_GetTransceiverMode()
| SID:              0x0E
| CALLED BY:        Ecu State Manager
| PRECONDITIONS:    Transceiver Driver is initialized
| INPUT PARAMETERS: uint8 Transceiver: Index to address transceiver
|                   CanIf_TransceiverModeType *TransceiverModePtr: Pointer to buffer for current transceiver mode
| RETURN VALUES:    E_OK: success / E_NOT_OK: fail
| DESCRIPTION:      Request current transceiver mode
*******************************************************************************************************************/
# if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
/* Std_ReturnType CanIf_GetTransceiverMode(uint8 CanNetwork, CanIf_TransceiverModeType *TransceiverModePtr); */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTransceiverMode(uint8 CanNetwork, P2VAR(CanIf_TransceiverModeType, AUTOMATIC, CANIF_APPL_STATE_VAR) TransceiverModePtr)
# else
/* Std_ReturnType CanIf_GetTransceiverMode(uint8 Transceiver, CanIf_TransceiverModeType *TransceiverModePtr) */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTransceiverMode(uint8 Transceiver, P2VAR(CanIf_TransceiverModeType, AUTOMATIC, CANIF_APPL_STATE_VAR) TransceiverModePtr)
# endif
{
  Std_ReturnType retval;

# if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
  uint8 Transceiver;

  Transceiver = CanNetwork;
# endif

  retval = E_NOT_OK;
# if (CANIF_DEV_ERROR_DETECT == STD_ON) 
  
  if (Transceiver >= CANIF_CFG_GENERIC(eMaxTransceivers)) 
  {
    CanIf_Det_ReportError(CANIF_GETTRANSCEIVERMODE_API, CANIF_TRCV_E_TRANSCEIVER);
  } 
  else
# endif /* CANIF_DEV_ERROR_DETECT */
  {
# if (CANIF_TRCV_MAPPING == STD_ON)
    uint8                           lowIndex;
    uint8                           lowAddress;
    CanIf_CanTrcv_GetOpModeFctType  lowFct;

    lowIndex   = CANIF_CFG_TRCVUPTOLOWMAP(Transceiver, eDriverIndex);
    lowAddress = CANIF_CFG_TRCVUPTOLOWMAP(Transceiver, eDriverAddress);

    lowFct = CanIf_TransceiverAPICanTrcv_GetOpModeFctMap[lowAddress];

    /* ESCAN00031640 */
    if (lowFct == NULL_PTR)
    {
      CanIf_Det_ReportError(CANIF_GETTRANSCEIVERMODE_API, CANIF_TRCV_E_TRANSCEIVER);
      /* retval is already set to E_NOT_OK */
    }
    else
    {
      retval = lowFct(TransceiverModePtr, lowIndex);
    }
# else
    retval = CanTrcv_GetOpMode(TransceiverModePtr, Transceiver);
# endif
  }
  return retval;
}
#endif


#if (CANIF_TRCV_HANDLING == STD_ON)
/*******************************************************************************************************************
| NAME:             CanIf_GetTrcvWakeupReason()
| SID:              0x0F
| CALLED BY:        Ecu State Manager
| PRECONDITIONS:    Transceiver Driver is initialized
| INPUT PARAMETERS: uint8 Transceiver: Index to address transceiver
|                   CanIf_TrcvWakeupReasonType *TrcvWuReasonPtr: Pointer to buffer for wake up reason
| RETURN VALUES:    E_OK: success / E_NOT_OK: fail
| DESCRIPTION:      Request wake up reason
*******************************************************************************************************************/
# if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
/* Std_ReturnType CanIf_GetTrcvWakeupReason(uint8 CanNetwork, CanIf_TrcvWakeupReasonType *TrcvWuReasonPtr) */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvWakeupReason(uint8 CanNetwork, P2VAR(CanIf_TrcvWakeupReasonType, AUTOMATIC, CANIF_APPL_STATE_VAR) TrcvWuReasonPtr)
# else
/* Std_ReturnType CanIf_GetTrcvWakeupReason(uint8 Transceiver, CanIf_TrcvWakeupReasonType *TrcvWuReasonPtr) */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvWakeupReason(uint8 Transceiver, P2VAR(CanIf_TrcvWakeupReasonType, AUTOMATIC, CANIF_APPL_STATE_VAR) TrcvWuReasonPtr)
# endif
{
  Std_ReturnType retval;

# if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
  uint8 Transceiver;

  Transceiver = CanNetwork;
#endif

  retval = E_NOT_OK;
# if (CANIF_DEV_ERROR_DETECT == STD_ON) 
  if (Transceiver >= CANIF_CFG_GENERIC(eMaxTransceivers)) 
  {
    CanIf_Det_ReportError(CANIF_TRCVWAKEUPREASON_API, CANIF_TRCV_E_TRANSCEIVER);
  } 
  else
# endif /* CANIF_DEV_ERROR_DETECT */
  {
# if (CANIF_TRCV_MAPPING == STD_ON)
    uint8                                 lowIndex;
    uint8                                 lowAddress;
    CanIf_CanTrcv_GetBusWuReasonFctType   lowFct;

    lowIndex   = CANIF_CFG_TRCVUPTOLOWMAP(Transceiver, eDriverIndex);
    lowAddress = CANIF_CFG_TRCVUPTOLOWMAP(Transceiver, eDriverAddress);

    lowFct = CanIf_TransceiverAPICanTrcv_GetBusWuReasonFctMap[lowAddress];

    /* ESCAN00031640 */
    if (lowFct == NULL_PTR) 
    {
      CanIf_Det_ReportError(CANIF_TRCVWAKEUPREASON_API, CANIF_TRCV_E_TRANSCEIVER);
      /* retval is already set to E_NOT_OK */
    }
    else
    {
      retval = lowFct(lowIndex, TrcvWuReasonPtr);
    }
# else
    retval = CanTrcv_GetBusWuReason(Transceiver, TrcvWuReasonPtr);
# endif
  }
  return retval;
}
#endif


#if (CANIF_TRCV_HANDLING == STD_ON)
/*******************************************************************************************************************
| NAME:             CanIf_SetTransceiverWakeupMode()
| SID:              0x10
| CALLED BY:        Ecu State Manager
| PRECONDITIONS:    Transceiver Driver is initialized
| INPUT PARAMETERS: uint8 Transceiver: Index to address transceiver
|                   CanIf_TrcvWakeupModeType TrcvWakeupMode: Set wake up mode
| RETURN VALUES:    E_OK: success / E_NOT_OK: fail
| DESCRIPTION:      Set transceiver wake up mode (enable, disable, clear)
*******************************************************************************************************************/
# if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
/* Std_ReturnType CanIf_SetTransceiverWakeupMode(uint8 CanNetwork, CanIf_TrcvWakeupModeType TrcvWakeupMode); */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTransceiverWakeupMode(uint8 CanNetwork, CanIf_TrcvWakeupModeType TrcvWakeupMode)
# else
/* Std_ReturnType CanIf_SetTransceiverWakeupMode(uint8 Transceiver, CanIf_TrcvWakeupModeType TrcvWakeupMode) */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTransceiverWakeupMode(uint8 Transceiver, CanIf_TrcvWakeupModeType TrcvWakeupMode)
# endif

{
  Std_ReturnType retval;

# if (CANIF_COMPATIBILITY_AUTOSAR21 == STD_ON)
  uint8 Transceiver;

  Transceiver = CanNetwork;
# endif

  retval = E_NOT_OK;
# if (CANIF_DEV_ERROR_DETECT == STD_ON) 
  if (Transceiver >= CANIF_CFG_GENERIC(eMaxTransceivers)) 
  {
    CanIf_Det_ReportError(CANIF_SETTRANSCEIVERWAKEUPMODE_API, CANIF_TRCV_E_TRANSCEIVER);
  } 
  else
# endif /* CANIF_DEV_ERROR_DETECT */
  {

# if (CANIF_TRCV_MAPPING == STD_ON)
    uint8                                 lowIndex;
    uint8                                 lowAddress;
    CanIf_CanTrcv_SetWakeupModeFctType    lowFct;

    lowIndex   = CANIF_CFG_TRCVUPTOLOWMAP(Transceiver, eDriverIndex);
    lowAddress = CANIF_CFG_TRCVUPTOLOWMAP(Transceiver, eDriverAddress);

    lowFct = CanIf_TransceiverAPICanTrcv_SetWakeupModeFctMap[lowAddress];
  
    /* ESCAN00031640 */
    if (lowFct == NULL_PTR)
    {
      CanIf_Det_ReportError(CANIF_SETTRANSCEIVERWAKEUPMODE_API, CANIF_TRCV_E_TRANSCEIVER);
      /* retval is already set to E_NOT_OK */
    }
    else
    {
      retval = lowFct(TrcvWakeupMode, lowIndex);
    }
# else
    retval = CanTrcv_SetWakeupMode(TrcvWakeupMode, Transceiver);
# endif
  }
  return retval;
}
#endif


/*******************************************************************************************************************
| NAME:             CanIf_CheckWakeup()
| SID:              0x11
| CALLED BY:        EcuM
| PRECONDITIONS:    CanInterface is initialized
| INPUT PARAMETERS: EcuM WakeupSource
| RETURN VALUES:    E_OK:     Check WakeUp request was accepted
|                   E_NOT_OK: Check WakeUp request was not accepted
| DESCRIPTION:      CAN Interface is asked by the EcuM if one of the possible 
|                   WakeUp Sources encoded in 'WakeupSource' is responsible
|                   for the WakeUp
*******************************************************************************************************************/
/* Std_ReturnType CanIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource) */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
  Std_ReturnType                        retval;

#if (CANIF_WAKEUP_SUPPORT == STD_ON)
  Std_ReturnType                        localRetval;
  EcuM_WakeupSourceType                 wokenUpSources;
  uint8                                 numWUsrc;
  
  wokenUpSources = 0;
  retval         = E_OK;        /* WakeUp request will be accepted */

  /* Find the first WakeUp Source which pretends to be the responsible */
  /* Always cycle through all Sources */
  for (numWUsrc = 0; numWUsrc < CANIF_CFG_GENERIC(eMaxWakeUpSources); numWUsrc++) 
  {
    EcuM_WakeupSourceType                 wuSrc;
    CanIf_WakeUpTargetType                wuTrgtmodule;
    uint8                                 wuTrgtaddress;
    CANIF_WUCHANNEL_CANTYPE_LOCAL


    /* Acquire wake up source information */
    wuSrc         = CANIF_CFG_WAKEUP(numWUsrc, eWakeUpSource);
    wuTrgtmodule  = CANIF_CFG_WAKEUP(numWUsrc, eWakeUpTargetModule);
    wuTrgtaddress = CANIF_CFG_WAKEUP(numWUsrc, eWakeUpTargetAddress);

#if (CANIF_ONE_CONTROLLER_OPTIMIZATION==STD_OFF)
    /* Find the correct CAN Controller */
    wuController  = CANIF_CFG_WAKEUP(numWUsrc, eController);
#endif

    /* Initialize localRetval for WakeUpSources which are not handled by CanIf*/
    localRetval = E_NOT_OK;

# if (CANIF_DEV_ERROR_DETECT == STD_ON) 
    /* DET error occured
       other sources will be checked 
       return value will be E_NOT_OK
    */
    if (CanIf_WU_Controller_Value_Local >= CANIF_CFG_GENERIC_EMAXCONTROLLER) 
    {
      retval = E_NOT_OK;
      CanIf_Det_ReportError(CANIF_CHECKWAKEUP_API, CANIF_E_PARAM_CONTROLLER);
    } 
    else if (CanIf_ControllerMode[CanIf_WU_Controller_Value_Local] == CANIF_CS_UNINIT)
    {
      retval = E_NOT_OK;
      CanIf_Det_ReportError(CANIF_CHECKWAKEUP_API, CANIF_E_UNINIT);
    }
    else
# endif /* CANIF_DEV_ERROR_DETECT */
    {
      if ((WakeupSource & wuSrc) != 0) 
      {
        if (wuTrgtmodule == CANIF_WAKEUPREQUEST_CAN) 
        {
          localRetval = Can_Cbk_CheckWakeup(wuTrgtaddress);
          if (localRetval == E_OK) 
          {

# if (CANIF_TRCV_HANDLING == STD_ON)
#  if (CANIF_TRCV_WAKEUPSTATETRANSITION == STD_ON)
            /* Wakeup by CAN detected - Switch transceiver from Standby or Sleep to  
               Normal mode to get rid of the permanent dominant level on the Rx Pin */
            uint8 transceiverUp;

            transceiverUp = CANIF_CFG_CTRLTOTRCVINDEXMAP(CanIf_WU_Controller_Value_Local);

            /* Check if a transceiver is connected to that controller by checking the index */
            if (transceiverUp != CanIf_TrcvIndex_INVALID) 
            {

#   if (CANIF_DEV_ERROR_DETECT == STD_ON) 
              if (transceiverUp >= CANIF_CFG_GENERIC(eMaxTransceivers)) 
              {
                /* Transceiver index received from generated date for the controller is invalid -> fail */
                CanIf_Det_ReportError(CANIF_CHECKWAKEUP_API, CANIF_E_CONFIG);
              } 
              else
#   endif
              {
                /* Do not evaluate return value -> issues will detected later */
                (void)CanIf_SetTransceiverMode(transceiverUp , CANIF_TRCV_MODE_NORMAL);
              }
            }
#  endif
# endif




# if (CANIF_EXTENDED_STATE_MACHINE == STD_ON)
            /* Controller WakeUp -> Set to started mode */
            /* Explicitely cast to void as return value cannot be used here */
            (void)CanIf_SetControllerMode(CanIf_WU_Controller_Value_Local, CANIF_CS_STARTED);
# else
            /* Controller WakeUp -> Set to stop mode */
            /* Explicitely cast to void as return value cannot be used here */
            (void)CanIf_SetControllerMode(CanIf_WU_Controller_Value_Local, CANIF_CS_STOPPED);
# endif
          }
# if (CANIF_TRCV_HANDLING == STD_ON)
        } 
        else if (wuTrgtmodule == CANIF_WAKEUPREQUEST_TRCV) 
        {
#  if (CANIF_TRCV_MAPPING == STD_ON)
          /* Indirection here */
          uint8                                 lowIndex;
          uint8                                 lowAddress;
          CanIf_CanTrcv_CB_WakeupByBusFctType   lowFct;


          lowIndex   = CANIF_CFG_TRCVUPTOLOWMAP(wuTrgtaddress, eDriverIndex);
          lowAddress = CANIF_CFG_TRCVUPTOLOWMAP(wuTrgtaddress, eDriverAddress);

          lowFct      = CanIf_TransceiverAPICanTrcv_CB_WakeupByBusFctMap[lowAddress];

          /* ESCAN00031640 */
          if (lowFct == NULL_PTR)
          {
            CanIf_Det_ReportError(CANIF_CHECKWAKEUP_API, CANIF_TRCV_E_TRANSCEIVER);
            /* localRetval is already set to E_NOT_OK */
          }
          else
          {
            localRetval = lowFct(lowIndex);
          }
#  else  /* CANIF_TRCV_MAPPING */
          localRetval = CanTrcv_CB_WakeupByBus(wuTrgtaddress);
#  endif /* CANIF_MULTIPLE_TRANSCEIVER_SUPPORT */
# endif /* CANIF_TRCV_HANDLING */
        } 
        else 
        {
          /* CANIF_WAKEUPREQUEST_NONE nothing to do*/
        }
        /* localRetval is E_OK if the requested source is responsible for the wakeup */
        if (localRetval == E_OK) 
        {
          /* Store source of woken up module */
          wokenUpSources |= wuSrc;
# if (CANIF_WAKEUP_VALIDATION == STD_ON)
          /* Here we are notified about some kind of wakeup and made sure we found a source */
          /* Start the wake up validation here and store the wake up source                 */
          CanIf_ValidationWakeUpSource              |= wuSrc;
          CanIf_WakeUpValidationState[CanIf_WU_Controller_Value_Local] =  CANIF_WUVALIDATION_ARMED;
# endif
        }
      } /* ValidWakeUpSource */
    } /* DET Error occured */
  }   /* WakeUp-Source Loop */

  /* Optional EcuM call (in case a valid wake up responsible has been found) */
  if (wokenUpSources != 0) 
  {
    CanIf_WakeUpEventFctType wakeupnotificationFct;
    wakeupnotificationFct = CANIF_CFG_WAKEUPEVENT();

    if (wakeupnotificationFct != NULL_PTR) 
    {
      wakeupnotificationFct(wokenUpSources);
    }
  }

#else  /* CANIF_WAKEUP_SUPPORT */
# if (V_USE_DUMMY_STATEMENT == STD_ON)
  WakeupSource = WakeupSource;
# endif
  retval = E_NOT_OK;
#endif /* CANIF_WAKEUP_SUPPORT */

  return retval;
}


/*******************************************************************************************************************
| NAME:             CanIf_CheckValidation()
| SID:              0x12
| CALLED BY:        EcuManager
| PRECONDITIONS:    A wake up event occurred and CanIf_CheckWakeup was called before / CanIf has to be inititalized
| INPUT PARAMETERS: EcuM WakeupSource
| RETURN VALUES:    E_OK:     Check Validation request was accepted
|                   E_NOT_OK: Check Validation request was not accepted
| DESCRIPTION:      CAN Interface is asked by the EcuM if an Rx message was received since the last wake up event.
|                     In this case the call back function EcuM_ValidateWakeupEvent will be called.
*******************************************************************************************************************/
/* Std_ReturnType CanIf_CheckValidation(EcuM_WakeupSourceType WakeupSource) */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckValidation(EcuM_WakeupSourceType WakeupSource)
{
  Std_ReturnType                        retval;
#if (CANIF_WAKEUP_VALIDATION == STD_ON)
  Std_ReturnType                        localRetval;
  EcuM_WakeupSourceType                 wokenUpSources;
  uint8                                 numWUsrc;

  retval         = E_OK;
  wokenUpSources = 0;

  /* Always cycle through all Sources */
  for (numWUsrc = 0; numWUsrc < CANIF_CFG_GENERIC(eMaxWakeUpSources); numWUsrc++) 
  {
    EcuM_WakeupSourceType                 wuSrc;
    CANIF_WUCHANNEL_CANTYPE_LOCAL

    /* Acquire wake up source information */
    wuSrc         = CANIF_CFG_WAKEUP(numWUsrc, eWakeUpSource);

#if (CANIF_ONE_CONTROLLER_OPTIMIZATION==STD_OFF)
    /* Find the correct CAN Controller */
    wuController  = CANIF_CFG_WAKEUP(numWUsrc, eController);
#endif

    /* Initialize localRetval for WakeUpSources which are not handled by CanIf*/
    localRetval = E_NOT_OK;

# if (CANIF_DEV_ERROR_DETECT == STD_ON) 
    /* DET error occured
       other sources will be checked 
       return value will be E_NOT_OK
    */
    if (CanIf_WU_Controller_Value_Local >= CANIF_CFG_GENERIC_EMAXCONTROLLER) 
    {
      retval = E_NOT_OK;
      CanIf_Det_ReportError(CANIF_CHECKVALIDATIONUP_API, CANIF_E_PARAM_CONTROLLER);
    } 
    else if (CanIf_ControllerMode[CanIf_WU_Controller_Value_Local] == CANIF_CS_UNINIT)
    {
      retval = E_NOT_OK;
      CanIf_Det_ReportError(CANIF_CHECKVALIDATIONUP_API, CANIF_E_UNINIT);
    }
    else
# endif /* CANIF_DEV_ERROR_DETECT */
    {
      if ((WakeupSource & wuSrc & CanIf_ValidationWakeUpSource) != 0) 
      {
        /* Passed wake up source is valid and wake up event occurred earlier */
        if ( CanIf_WakeUpValidationState[CanIf_WU_Controller_Value_Local] == CANIF_WUVALIDATION_DETECTED ) 
        {
          /* We detected a wake up validation */
          CanIf_WakeUpValidationState[CanIf_WU_Controller_Value_Local] = CANIF_WUVALIDATION_IDLE;

          localRetval = E_OK;
        } 
        else
        {
          /* We detected no validation of the wake up event -> No error */
          localRetval = E_NOT_OK;
        }

        /* localRetval is E_OK if the requested source is responsible for the wakeup */
        if (localRetval == E_OK) 
        {
          /* Store source of woken up module */
          wokenUpSources |= wuSrc;
        }
      } /* ValidWakeUpSource */
      else 
      {
        /* Invalid wake up source passed / or no wake up occurred */
        /* Nothing to do */
      }
    } /* DET Error occured */
  }   /* WakeUp-Source Loop */

  /* EcuM call (in case a valid wake up validation for the requested source is pending) */
  if (wokenUpSources != 0) 
  {
    CanIf_WakeUpValidationFctType wakeupvalidationFct;

    wakeupvalidationFct = CANIF_CFG_WAKEUPVALIDATION();
    CanIf_ValidationWakeUpSource &= ~wokenUpSources;   /* Remove all validated sources from list */

    if (wakeupvalidationFct != NULL_PTR) 
    {
      wakeupvalidationFct(wokenUpSources);
    }
  }

#else  /* CANIF_WAKEUP_VALIDATION */
# if (V_USE_DUMMY_STATEMENT == STD_ON)
  WakeupSource = WakeupSource;
# endif
  retval = E_NOT_OK;
#endif /* CANIF_WAKEUP_VALIDATION */

  return retval;
}



#if (CANIF_BUSOFF_RECOVERY_API == STD_ON)
/*******************************************************************************************************************
| NAME:             CanIf_ResetBusOffStart()
| SID:              -
| CALLED BY:        Application
| PRECONDITIONS:    -
| INPUT PARAMETERS: uint8 Controller
| RETURN VALUES:    -
| DESCRIPTION:      API to recover a bus off event for not AUTOSAR compliant network management layers
*******************************************************************************************************************/
/* void CanIf_ResetBusOffStart(uint8 Controller) */
FUNC(void, CANIF_CODE) CanIf_ResetBusOffStart(uint8 Controller)
{
# if (CANIF_DEV_ERROR_DETECT == STD_ON)
  if (Controller >= CANIF_CFG_GENERIC_EMAXCONTROLLER) 
  {
    CanIf_Det_ReportError(CANIF_TRCVWAKEUPREASON_API, CANIF_E_PARAM_CONTROLLER);
  } 
  else 
# else
#  if ((CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON) && (V_USE_DUMMY_STATEMENT == STD_ON))
  Controller = Controller;
#  endif
# endif
  {
    CanIf_ControllerMode[CanIf_Controller_Value] = CANIF_CS_STARTED;
    CanIf_ChannelMode[CanIf_Controller_Value] = CANIF_GET_RX_ONLINE;
    Can_ResetBusOffStart(CanIf_Controller_Value);
  }
}

/*******************************************************************************************************************
| NAME:             CanIf_ResetBusOffEnd()
| SID:              -
| CALLED BY:        Application
| PRECONDITIONS:    -
| INPUT PARAMETERS: uint8 Controller
| RETURN VALUES:    -
| DESCRIPTION:      API to recover a bus off event for not AUTOSAR compliant network management layers
*******************************************************************************************************************/
/* void CanIf_ResetBusOffEnd(uint8 Controller) */
FUNC(void, CANIF_CODE) CanIf_ResetBusOffEnd(uint8 Controller)
{
# if ((CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_ON) && (V_USE_DUMMY_STATEMENT == STD_ON))
  Controller = Controller;
# endif  
# if (CANIF_DEV_ERROR_DETECT == STD_ON)
  if (Controller >= CANIF_CFG_GENERIC_EMAXCONTROLLER) 
  {
    CanIf_Det_ReportError(CANIF_TRCVWAKEUPREASON_API, CANIF_E_PARAM_CONTROLLER);
  } 
  else 
# endif
  {
    /* CanIf already in CANIF_CS_STARTED and RX_ONLINE state. No need to switch states */
    Can_ResetBusOffEnd(CanIf_Controller_Value);
  }
}
#endif

#if (CANIF_SUPPORT_NONPB_API == STD_ON)
/*******************************************************************************************************************
| NAME:             CanIf_ConvertPduId()
| SID:              -
| CALLED BY:        Application
| PRECONDITIONS:    -
| INPUT PARAMETERS: PduIdType PbPduId: PduId which has to be converted
|                   PduIdType *PduId:  Converted Pdu Id
| RETURN VALUES:    E_OK: Conversion successful
|                   E_NOT_OK: Vonversion not successful
| DESCRIPTION:      Convert a Tx PDU Id (defined at link time) to the correct Pdu Id which
|                   is valid after post build configuration (has to be used by upper layers
|                   which use Tx PDU which are not included in post build configuration of this layer
*******************************************************************************************************************/
/* Std_ReturnType CanIf_ConvertPduId(PduIdType PbPduId, PduIdType *PduId) */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_ConvertPduId(PduIdType PbPduId, P2VAR(PduIdType, AUTOMATIC, CANIF_APPL_MSG_VAR)PduId)
{
  Std_ReturnType retval;

  retval = E_OK;
# if (CANIF_DEV_ERROR_DETECT == STD_ON)
  /* Compare LinkTime and PostBuild configuration AND if PduId parameter is valid */
  if (  ( CanIf_MaxNPBPduHandles != CANIF_CFG_GENERIC(eMaxNPBTxPDUHandle) )  &&
        ( PbPduId >= CanIf_MaxNPBPduHandles )   ) 
  {
    *PduId = CanIf_TxPduHnd_INVALID;
    retval = E_NOT_OK;
  } 

  else 
# endif
  {
    /* Always check if table is valid by evaluating the last entry
       better return an invalid handle here instead of raising a DET error */
    if (CANIF_CFG_CONVERTPDU(CanIf_MaxNPBPduHandles) != (PduIdType) 0xFEFEFEFE) 
    {
      *PduId = CanIf_TxPduHnd_INVALID;
      retval = E_NOT_OK;
    } 
    else 
    {
      *PduId = CANIF_CFG_CONVERTPDU(PbPduId);
    }
  }
  return retval;
}
#endif


#if (CANIF_ENABLE_TX_LPDU_REMAPPING == STD_ON)
/*******************************************************************************************************************
| NAME:             CanIfWrapper_Transmit()
| SID:              0x05
| CALLED BY:        upper layer
| PRECONDITIONS:    CAN Interface initialized
| INPUT PARAMETERS: PduIdType CanTxPduId: Handle of Tx PDU (Provided by UpperLayer, will be converted to CanIf's PduID 
|                   const PduInfoType *PduInfoPtr: PDU Info (Data length, data ptr)
| RETURN VALUES:    Result of transmission request
| DESCRIPTION:      Initiate transmission of a Tx PDU (call CanIf_Transmit) after conversion of the provided PduId
|                   The Tx PduId will be provided by the upper layer and converted by this function.
*******************************************************************************************************************/
/* Std_ReturnType CanIfWrapper_Transmit(PduIdType CanTxPduId, const PduInfoType *PduInfoPtr); */
FUNC(Std_ReturnType, CANIF_CODE) CanIfWrapper_Transmit(PduIdType CanTxPduId, P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_MSG_VAR)PduInfoPtr)
{
  Std_ReturnType retval;
  retval = E_NOT_OK;

#if (CANIF_DEV_ERROR_DETECT == STD_ON)
  if (CanTxPduId < CANIF_CFG_GENERIC(eMapTxPduOffset)) 
  {
    CanIf_Det_ReportError(CANIF_TRANSMIT_API, CANIF_E_PARAM_LPDU);
  } 
  else if (CanTxPduId >= (CANIF_CFG_GENERIC(eMapTxPduOffset) + CANIF_CFG_GENERIC(eMaxMappedTxPDUs)) ) 
  {
    CanIf_Det_ReportError(CANIF_TRANSMIT_API, CANIF_E_PARAM_LPDU);
  }
  else
#endif
  {
    PduIdType mappedCanTxPdu;

    mappedCanTxPdu = CANIF_CFG_TXPDUMAP((CanTxPduId - CANIF_CFG_GENERIC(eMapTxPduOffset)));
    /* Parameters will be checked in CanIf_Transmit if development error detection is active */
    retval = CanIf_Transmit(mappedCanTxPdu, PduInfoPtr);
  }
  return retval;
}
#endif

#if(CANIF_SETDYNAMICTXID_API == STD_ON)
/*******************************************************************************************************************
| NAME:             CanIf_SetDynamicTxId(PduIdType CanTxPduId, Can_IdType CanId)
| SID:              0x0C
| CALLED BY:        Application
| PRECONDITIONS:    CAN Interface initialized
| Caveats:          This function may not be interrupted by CanIf_Transmit() if the same L-PDU ID is handled
| INPUT PARAMETERS: PduIdType CanTxPduId: Handle of Tx PDU provided by UpperLayer
|                   Can_IdType CanId: Id of transmit message
| RETURN VALUES:    none
| DESCRIPTION:      This service reconfigures the corresponding CAN identifier of the requested CAN L-PDU
*******************************************************************************************************************/
void CanIf_SetDynamicTxId(PduIdType CanTxPduId, Can_IdType CanId)
{
# if (CANIF_DEV_ERROR_DETECT == STD_ON)
  CANIF_CHANNEL_CANTYPE_LOCAL
# endif
  PduIdType dynamicPduId;
# if ((CANIF_ONE_CONTROLLER_OPTIMIZATION == STD_OFF) && (CANIF_DEV_ERROR_DETECT == STD_ON))
    /* Collect configuration data */
  controller = CANIF_CFG_TX_ECONTROLLER;
# endif
  dynamicPduId = CANIF_CFG_STAT2DYN_INDIRECTION(CanTxPduId);  
  /* Check if CanTxPduId is valid */
# if (CANIF_DEV_ERROR_DETECT == STD_ON)
  if (CanTxPduId >= CANIF_CFG_GENERIC(eMaxTxPDUHandle)) 
  {
    CanIf_Det_ReportError(CANIF_TRANSMIT_API, CANIF_E_INVALID_TXPDUID);
  } 
  else if (dynamicPduId == (PduIdType)-1) /*no dyamic TxPdu handle*/
  {
    CanIf_Det_ReportError(CANIF_TRANSMIT_API, CANIF_E_INVALID_TXPDUID);
  } 
#  if (CANIF_EXTENDEDID_SUPPORT != STD_ON)
  else if (CanId > 0x7FF)
  {
    CanIf_Det_ReportError(CANIF_RXINDICATION_API, CANIF_E_PARAM_CANID);
  }
#  endif
  else if(CanIf_ControllerMode[CanIf_Controller_Value_Local] == CANIF_CS_UNINIT)
  {
    CanIf_Det_ReportError(CANIF_TRANSMIT_API, CANIF_E_UNINIT);
  } 
  else
# endif
  {
    CanIf_DynTxId[dynamicPduId]= CanId;
  }
}
#endif

/*******************************************************************************************************************
| NAME:             CanIf_XXX()
| SID:              0xXXX
| CALLED BY:        XXX
| PRECONDITIONS:    XXX
| INPUT PARAMETERS: XXX
| RETURN VALUES:    XXX
| DESCRIPTION:      XXX
*******************************************************************************************************************/

#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
