/******************************************************************************
 | Project Name:   XCP on CAN Transport Layer for AUTOSAR CanIf Release 3.0
 |    File Name:   CanXcp.h
 |
 |  Description:
 |    Header of adaption component for the XCP Protocol Layer interface
 |    and AUTOSAR CAN Interface.
 |
 |  Limitations:
 |    - Detection of all XCP slaves within a CAN network is not supported
 |        ( GET_SLAVE_ID )
 |    - Assignment of CAN identifiers to DAQ lists or STIM is not supported
 |        ( GET_DAQ_ID, SET_DAQ_ID )
 |
 |------------------------------------------------------------------------------
 |               C O P Y R I G H T
 |------------------------------------------------------------------------------
 | Copyright (c) 2011 by Vctr Informatik GmbH.          All rights reserved.
 |
 |       This software is copyright protected and 
 |       proporietary to Vctr Informatik GmbH.
 |       Vctr Informatik GmbH grants to you only
 |       those rights as set out in the license conditions.
 |       All other rights remain with Vctr Informatik GmbH.
 | 
 |       Diese Software ist urheberrechtlich geschuetzt. 
 |       Vctr Informatik GmbH raeumt Ihnen an dieser Software nur 
 |       die in den Lizenzbedingungen ausdruecklich genannten Rechte ein.
 |       Alle anderen Rechte verbleiben bei Vctr Informatik GmbH.
 |
 |------------------------------------------------------------------------------
 |               A U T H O R   I D E N T I T Y
 |------------------------------------------------------------------------------
 | Initials     Name                      Company
 | --------     ---------------------     --------------------------------------
 | Tri          Frank Triem               Vctr Informatik GmbH
 | Svh          Sven Hesselmann           Vctr Informatik GmbH
 |  Hr          Andreas Herkommer         Vctr Informatik GmbH
 | Dod          O'Donnell Dennis          Vector CANtech
 |------------------------------------------------------------------------------
 |               R E V I S I O N   H I S T O R Y
 |------------------------------------------------------------------------------
 |  Date       Version  Author  Description
 | ----------  -------  ------  ------------------------------------------------
 | 2007-01-18  1.00.00   Tri    ESCAN00017515: Creation of component based on Cp_XcpOnCan
 | 2007-01-29  1.01.00   Tri    ESCAN00019255: Compiler error: expression must have a constant value
 | 2008-04-04  1.02.00   Svh    ESCAN00023286: XCP will be reinitialized after transmission
 | 2008-07-25  1.03.00   Svh    ESCAN00028749: Post build support added
 |                              ESCAN00018171: Support BSW Scheduler
 | 2009-09-07  1.03.01    Hr    ESCAN00037598: Memory Mapping: Wrong PB section name
 | 2009-10-13             Hr    ESCAN00038409: Wrong variable section for compiler abstraction
 | 2009-11-25             Hr    ESCAN00039395: Support Multiple Configuration
 | 2009-12-02  1.03.02    Hr    ESCAN00039524: Compiler warning due to missing define 'ON'
 | 2009-12-16  1.03.03    Hr    ESCAN00039803: Version information mismatch
 | 2009-12-22  1.03.04    Hr    ESCAN00039896: reject "master" message for inactive identities (physical multiple ECU)
 | 2010-01-14  1.03.05    Hr    ESCAN00040111: Support Multiple Identity by selectable Post-Build
 |                        Dod   ESCAN00040113: Support for address doubling in CANape for DSP micros
 | 2010-07-30  1.03.06    Hr    ESCAN00044364: Missing Memory mapping sections in CanXcp_MemMap.inc
 | 2010-08-13  1.04.00    Hr    ESCAN00041935: Add feature to disable XcpOnCanAsr in serial production ECUs
 | 2010-08-13                   ESCAN00043931: Add support for XCP measurement during bus off phases
 | 2010-08-25                   ESCAN00040120: Support MultiChannel
 | 2010-09-24  1.04.01    Hr    ESCAN00045559: Compile Error: Enum type in CanXcp_Types.h wrong
 |                              ESCAN00045562: Compile Error: Wrong code section naming
 | 2010-11-03  1.04.02    Hr    ESCAN00046218: Compiler Abstraction not used for all pointer typecasts
 |                              ESCAN00046234: Adapt AUTOSAR version check
 | 2011-01-04  1.05.00    Hr    ESCAN00046303: AR3-297 AR3-894: Support PduInfoType instead of the DataPtr
 |                              ESCAN00047329: Adapt MainFunction for usage with IdentityManagerConfig
 |                              ESCAN00047694: Development Error Detection not implemented
 | 2011-02-28  1.05.01    Hr    ESCAN00048951: Compiler error in CanXcp_Control
 | 2011-03-03  1.05.02    Hr    ESCAN00048789: Frames can get lost in case of CAN Bus Off
 | 2011-03-21  1.06.00    Hr    ESCAN00049424: Support Monitoring Hooks for AUTOSAR 4
 | 2011-08-24  1.06.01    Hr    ESCAN00052955: Wrong return type for CanXcp_Transmit
 | 2011-12-01  1.06.02    Hr    ESCAN00053422: AR3-2069: Remove non-SchM code for critical section handling
 |*****************************************************************************/
#if !defined ( CANXCP_H )
#define CANXCP_H

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "ComStack_Types.h"              /* Include Communication Stack Types */
#include "CanXcp_Cfg.h"                /* Include configuration of XCP on CAN */
#include "CanXcp_Types.h"              /* Type definitions for XCP on CAN ASR */
#include "xcp_cfg.h"           /* Include configuration of XCP Protocol Layer */
#include "SchM_CanXcp.h"


/*******************************************************************************
* Version
*******************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : Cp_XcpOnCanAsr CQComponent : Implementation */
#define CP_XCPONCANASR_VERSION          0x0106u
#define CP_XCPONCANASR_RELEASE_VERSION  0x02u

#define CANXCP_SW_MAJOR_VERSION         ((CP_XCPONCANASR_VERSION & 0xFF00) >> 8)
#define CANXCP_SW_MINOR_VERSION         (CP_XCPONCANASR_VERSION & 0xFF)
#define CANXCP_SW_PATCH_VERSION         (CP_XCPONCANASR_RELEASE_VERSION)

#define CANXCP_VENDOR_ID                30u
#define CANXCP_MODULE_ID                255u

#define CANXCP_START_SEC_CONST_8BIT
#include "MemMap.h"

extern CONST(uint8, CANXCP_CONST)       kXcpOnCanAsrMainVersion;
extern CONST(uint8, CANXCP_CONST)       kXcpOnCanSubAsrVersion;
extern CONST(uint8, CANXCP_CONST)       kXcpOnCanAsrReleaseVersion;

#define CANXCP_STOP_SEC_CONST_8BIT
#include "MemMap.h"

/* Version of the XCP Transport Layer for CAN specification. */
#if ! defined ( CANXCP_TRANSPORT_LAYER_VERSION )
  #define CANXCP_TRANSPORT_LAYER_VERSION   0x0100
#endif

/*******************************************************************************
* Default Defintions
*******************************************************************************/

/* CTO and DTO are always 8 on CAN. */

#if defined ( kCanXcpMaxCTO )
#else
  #define kCanXcpMaxCTO                    8
#endif

#if defined ( kCanXcpMaxDTO )
#else
  #define kCanXcpMaxDTO                    8
#endif

/* Initialization status of XCP. */
#define CANXCP_UNINIT   0
#define CANXCP_INIT     1

/* The function XcpGetState is required for the protection against multiple connections. */
#if defined ( CANXCP_MULTI_CONN_PROT_ENABLED )
  #define XCP_ENABLE_GET_CONNECTION_STATE
#else
  #define XCP_DISABLE_GET_CONNECTION_STATE
#endif

#if !defined ( CANXCP_ENABLE_PDUMODE )
  #define CANXCP_ENABLE_PDUMODE STD_ON
#endif


/*******************************************************************************
* Type definitions
*******************************************************************************/

/* Development errors */
#if ( CANXCP_DEV_ERROR_DETECT == STD_ON )
/* Definition of the API ID */
  #define CANXCP_INIT_SERVICE_ID                   0u
  #define CANXCP_TLSERVICE_ID                      1u
  #define CANXCP_TRANSMIT_ID                       2u
  #define CANXCP_SENDFLUSH_ID                      4u
  #define CANXCP_CONTROL_ID                        5u
  #define CANXCP_GETVERSIONINFO_ID                 6u
  #define CANXCP_SETPDUMODE_ID                     7u
  #define CANXCP_TXCONFIRMATION_SERVICE_ID       101u
  #define CANXCP_RXINDICATION_SERVICE_ID         102u
  #define CANXCP_MAINFUNCTION_SERVICE_ID         200u

/* Definition of errors/exceptions */
  #define CANXCP_E_INV_POINTER                     1u
  #define CANXCP_E_NOT_INITIALIZED                 2u
  #define CANXCP_E_INVALID_PDUID                   3u
  #define CANXCP_E_NULL_POINTER                   18u
  #define CANXCP_E_RX_BUFFER_OVERFLOW              4u
  #define CANXCP_E_WRONG_CONTROL_COMMAND           5u
  #define CANXCP_E_INVALID_NW_HANDLE               6u
#endif


/******************************************************************************/
/* External ROM Data                                                          */
/******************************************************************************/

/***************************************************************************/
/* Default macros                                                          */
/***************************************************************************/

/* Interrupt enable and disable functions */
#if defined ( ApplXcpInterruptDisable )
#else
    #define ApplXcpInterruptDisable()           SchM_Enter_CanXcp(CANXCP_EXCLUSIVE_AREA_0)
#endif
#if defined ( ApplXcpInterruptEnable )
#else
    #define ApplXcpInterruptEnable()            SchM_Exit_CanXcp(CANXCP_EXCLUSIVE_AREA_0)
#endif

/****************************************************************************/
/* Prototypes                                                               */
/****************************************************************************/

#define CANXCP_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, CANXCP_CODE) CanXcp_InitMemory( void );

#if ( CANXCP_VERSION_INFO_API == STD_ON )
extern FUNC(void, CANXCP_CODE) CanXcp_GetVersionInfo
(
  P2VAR(Std_VersionInfoType, AUTOMATIC, CANXCP_APPL_VAR) Versioninfo
);
#endif

extern FUNC(void, CANXCP_CODE) CanXcp_Init
(
  P2CONST(CanXcp_ConfigType, AUTOMATIC, CANXCP_PBCFG) ConfigPtr
);

#if defined ( CANXCP_ENABLE_CONTROL )
/* En- or disable the Xcp Protocol Layer globally */
extern FUNC(void, CANXCP_CODE) CanXcp_Control
(
  VAR(uint8, AUTOMATIC) command
);
  #define kXcponCan_Control_Disable   0x00u
  #define kXcponCan_Control_Enable    0x01u
#endif

extern FUNC(void, CANXCP_CODE) CanXcp_MainFunction( void );


#if ( CANXCP_USE_PDUINFOTYPE == STD_ON )
extern FUNC(void, CANXCP_CODE) CanXcp_RxIndication
(
  VAR(PduIdType, AUTOMATIC) CanCanXcpRxPduId,
  P2CONST(PduInfoType, AUTOMATIC, CANXCP_APPL_VAR) PduInfoPtr
);
#else
extern FUNC(void, CANXCP_CODE) CanXcp_RxIndication
(
  VAR(PduIdType, AUTOMATIC) CanCanXcpRxPduId,
  P2CONST(uint8, AUTOMATIC, CANXCP_APPL_VAR) CanSduPtr
);
#endif

extern FUNC(void, CANXCP_CODE) CanXcp_TxConfirmation( VAR(PduIdType, AUTOMATIC) CanTxPduId );

extern FUNC(void, CANXCP_CODE) CanXcp_Transmit
(
  VAR(uint8, AUTOMATIC) len,
  P2CONST(uint8, AUTOMATIC, CANXCP_APPL_VAR) msg
);

extern FUNC(void, CANXCP_CODE) CanXcp_SendFlush( uint8 FlushType );
extern FUNC(uint8, CANXCP_CODE) CanXcp_TLService( P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) pCmd );
#if ( CANXCP_ENABLE_PDUMODE == STD_ON )
extern FUNC(void, CANXCP_CODE) CanXcp_SetPduMode( NetworkHandleType XcpNwH, CanXcp_PduSetModeType PduMode );
#endif


#define CANXCP_STOP_SEC_CODE
#include "MemMap.h"

#endif /* CANXCP_H */
