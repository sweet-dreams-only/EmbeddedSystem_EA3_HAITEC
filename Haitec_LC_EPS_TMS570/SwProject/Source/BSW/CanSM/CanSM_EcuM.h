/*  *****   STARTSINGLE_OF_MULTIPLE_COMMENT    *****  */




/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  Copyright (c) 2008 - 2013 by Vctr Informatik GmbH.                                            All rights reserved.

                This software is copyright protected and proprietary to Vctr Informatik GmbH.
                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vctr Informatik GmbH.
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
         File:  CanSM_EcuM.h
    Component:  CAN State Manager
       Module:  -
    Generator:  -

  Description:  Public header of the CAN State Manager AUTOSAR Release 3.0
**********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
-----------------------------------------------------------------------------------------------------------------------
  Name                          Initials      Company
-----------------------------------------------------------------------------------------------------------------------
  Mark A. Fingerle              mfi           Vctr Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
-----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Change Id     Description
-----------------------------------------------------------------------------------------------------------------------
  00.01.00  2007-11-05  mfi     -             Initial version
  01.00.00  2008-01-23  mfi     -             ASR 3.0 release version of SWS, CanIf still on ASR 2.1
                                ESCAN00025949 The CanSM isn't affected. The CanSM handles the DEM already in the Lcfg.c (No access on "DEM-events" via DEM created and exported constant values)
  01.01.00  2008-02-04  mfi     ESCAN00024939 New Transition T00 (UNINIT to FULL),
                                ESCAN00024941 Set Transceiver to SILENT only if Controller is in SLEEP
  01.02.00  2008-02-25  mfi     ESCAN00024924 CAN not performs bus-off recovery
  01.03.00  2008-02-28  mfi     ESCAN00024985 Deadline monitoring not active in FULL communication and may be active in NO communication. Switched DL on in T00 and T02. Switched DL off in T03.
  01.04.00  2008-03-03  mfi     ESCAN00025095 Memory Mapping and Compiler Abstraction added
                                ESCAN00025096 Check if the configuration contains same NW index multiple times.
                                ESCAN00024943 The CanSM passes wrong parameter to the ComM. The parameter list in the function calls are switched.
                                ESCAN00025099 Activate Transceiver before Controller
                                ESCAN00025100 Version defines and version checks added/modified
                                ESCAN00025101 Switched API ComM_BusSM_ModeIndication and header file ComM_BusSM.h
                                ESCAN00025111 Adapt CanSM to ASR 3.0 CanIf, CanSM is still able to handle CanIf 2.1 too. API becomes chosen automatically
                                ESCAN00025138 API prototype GetVersionInfo in wrong header file
                                ESCAN00025139 First bus-off recovery time of level 2 may be to short
  01.05.00  2008-03-31  mfi     ESCAN00025653 CA _STATIC_ substituted by ASR 3.0 STATIC; doubled semicolon removed
                                ESCAN00025677 Include all CanSM headers, to check the version number
                                ESCAN00026039 Compiler error "Unrecognized token ';'" issued (... CanSm_Config_Ptr = NULL_PTR;;)
  01.06.00  2008-04-04  mfi     ESCAN00025892 Simplify the set controller mode algorithm of the CanSM
                                ESCAN00025893 Implement a check if E_OK has the value 0
                                ESCAN00025894 Reduce complexity of bus-off value handling
                                ESCAN00025895 Speedup evaluation of the conditions in the bus-off state machine
                                ESCAN00025896 Modified the return value of CanSM_RequestComMode
                                ESCAN00026000 Modify compiler abstraction according Newsletter
                                ESCAN00026001 Extend error handling to the case a transition fails and the mode request changes before recovering of the transition.
                                ESCAN00026002 Add an error counter and a DEM event triggered by the counter
                                ESCAN00026003 MetaStates of BOR SM shifted in NW SM
                                ESCAN00026110 Channel specific transceiver handling
                                ESCAN00026111 Switched form SW number to ASR number to check the version of the CanIf
                                ESCAN00026112 CanSM has defined wrong ASR version number
                                ESCAN00026122 The values of the pre-compile switch CANSM_BOR_DISABLE_RX_DL_MONITORING are interchanged
                                ESCAN00026176 Extension for MSR3.0 LinkTime checks
                                ESCAN00026347 Remove Compiler warning "condition is always true" in CanSM_Init
                                ESCAN00026269 Rename files and #include statements according coding styles
  01.07.00  2008-05-26  mfi     ESCAN00026502 Extension for MSR3.0 generator version checks
                                ESCAN00027533 CanSM don't report a Dem error if error counter exceeded
                                ESCAN00027592 Remove unnecessary if statement
  01.07.01  2008-06-04  mfi     ESCAN00028140 Extension for MSR3.0 generator version checks, changes added (typecast, stop init)
                                ESCAN00028247 The values of the preprocessor switch CanSMBorDisableRxDlMonitoring are switched.
  01.08.00  2008-07-24  mfi     ESCAN00028853 General improvements (pointer to the current channel data; defines instead of explicit value;  remove unused variable)
                                ESCAN00028328 Remove compatibility to CanIf ASR 2.1
                                ESCAN00027977 Resource and Runtime optimization at DET calls
                                ESCAN00028851 CanSM_GetCurrentComMode returns illegal E_NOT_OK
                                ESCAN00029339 Pointer for ComM_BusSM_ModeIndication as parameter
                                ESCAN00029365 Configuration switch "Rx deadline monitoring" changeable at linktime too
                                ESCAN00029501 Boolean type CanSm_IsInitialized changed to uint8
                                ESCAN00028889 The CAN controller not started in second level of the bus-off recovery ==> T07, T13, T12 are similar and joined ==> BOR SM modified
                                ESCAN00028814 Add brackets that CANSM_LeaveCritical and CANSM_EnterCritical look like functions
                                ESCAN00028323 Remove the redundant check CANSM_BOR_CHECK_INIT in Transition T09
                                ESCAN00028885 Resource and Runtime optimization at transceiver calls
  01.09.00  2008-09-23  mfi     ESCAN00030248 Use UpperCamelCase notation for the configuration parameter
                                ESCAN00030000 PreCompile and Linktime CRC check [BR]
                                ESCAN00029792 Resource and Runtime optimization at controller calls
                                ESCAN00030492 CAN bus specific bus-off configuration parameter
                                ESCAN00030619 Add support for the ECU passive mode (CanSM_SetEcuPassive) [022]
                                ESCAN00030656 Remove unused defines
                                ESCAN00030657 Add ASR short name prefix to defines
                                ESCAN00030658 Correct the pointer and memory class in the compiler abstraction macros
                                ESCAN00030659 Remove the init value of UNINIT variable
                                ESCAN00030663 Add compiler abstraction for function local pointers to data defined in the link or post build files
  01.10.00  2008-11-13  mfi     ESCAN00031381 CanSM includes wrong header ("Platform_Types.h" instead Std_Types.h)
                                ESCAN00031377 CanSM uses wrong compiler abstraction
                                ESCAN00031378 Error detection related code not encapsulated in pre-processor switches
                                ESCAN00031582 Deadline Monitoring not started
                                ESCAN00031970 Missing function declaration because of unknown define value
  01.11.00  2009-02-13  mfi     ESCAN00033112 Conditional skip transceiver mode set during initialization [023]
                                ESCAN00033173 Compiler abstraction and memory mapping for local variables are missing.
  01.11.01  2009-03-23  mfi     ESCAN00033501 Compiler Warnings CanSM_TransceiverMode, "CanSM_TransceiverMode" was declared but never referenced
                                ESCAN00034044 Compiler Warning "pointless comparison of unsigned integer with zero"
                                ESCAN00034070 Move CanSM passive mode API into CanSM.h file
                                ESCAN00034158 Wrong memory mapping for pointers to CanSM_LocalClusterDataType variables
  01.12.00  2009-05-27  mfi     ESCAN00034660 The type CanSM_NetworkModeStateType and CanSM_BusOffRecoveryStateType is not implemented correct
                                ESCAN00035004 CAN bus does not react on external wakeup interrupts ==> No repetition if set Trcv mode fail in the transition T03 OR T01
                                ESCAN00035856 CanSM increases the repetition error counter twice if transceiver produces a negative return value in T02
                                ESCAN00036045 Inform the application about a present bus-off [010]
                                ESCAN00036438 Misra violation Rule 5.6; Name Spaces of Identifiers
                                ESCAN00036095 Pre-processor checks for building the library
  01.12.01  2009-09-09  mfi     ESCAN00037693 Dcm throws Det error during initialization of the CanSM
  01.12.02  2009-10-23  mfi     ESCAN00038504 Wrong compiler abstraction
  01.12.03  2010-03-03  mfi     ESCAN00041368 Interrupt locks take very long during state changes
  01.13.00  2010-04-23  mfi     ESCAN00041156 Naming of CanSM functions and macros is inconsistent
  01.14.00  2010-07-13  mfi     ESCAN00043552 Submitted Add support for XCP shutdown
  01.15.00  2010-10-03  mfi     ESCAN00045704 Disable DeadlineMonitoring in state CANSM_SILENT_COMMUNICATION
                                ESCAN00045815 CanSM tries to call missing functions;  encapsulate DM in CANSM_BOR_DISABLE_RX_DL_MONITORING
  01.16.00  2011-01-13  mfi     ESCAN00046656 Call Appl_CanSM_BusOffEnd() if a BusOff recovery is interrupted
                                ESCAN00047400 change shutdown sequence for Partial Network
                                ESCAN00046783 Support Multiple Identity Configuration
                                ESCAN00047494 Adapt CanSM for usage with IdentityManagerConfig
                                ESCAN00047436 BswM callout BswM_CanSM_CurrentState
                                ESCAN00044505 The application call back function declaration is surround by the same MemMap.h section as CanSM code
                                ESCAN00047985 No CAN communication possible, caused by bus-off in SILENT communication
                                ESCAN00048379 Definition CANSM_PRE_COMPILE used before it is set - Build Lib Check not usable
  01.16.01  2011-05-05  mfi     ESCAN00044505 The application call back function declaration is surround by the same MemMap.h section as CanSM code
                                ESCAN00050250 Extend Bus Off recovery handling, additional ModeIndications during BusOff recovery
  01.16.02  2012-08-23  mfi     ESCAN00051096 Call SetControllerMode (or TransceiverMode) during startup only if necessary
  01.16.03  2013-02-03  mfi     ESCAN00064035 GetCurrentComMode() delivers wrong mode during running bus-off recovery
**********************************************************************************************************************/

#ifndef CANSM_ECUM_H

# define CANSM_ECUM_H

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/

# include "CanSM.h"             /* needed cause of CANSM_CONFIG_VARIANT and CanSM_ConfigType */

/**********************************************************************************************************************
* Version
**********************************************************************************************************************/
/* AUTOSAR CAN State Management version */
/* ##V_CFG_MANAGEMENT ##CQProject : Ccl_AsrSmCan CQComponent : Implementation */
# define CCL_ASRSMCAN_ECUM_HEADER_VERSION                             0x0116u   /* BCD coded version number */
# define CCL_ASRSMCAN_ECUM_HEADER_RELEASE_VERSION                     0x03u   /* BCD coded release version number  */


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

#if  ( STD_OFF == CANSM_IDENTITY_MANAGER_CONFIG )
# define CANSM_START_SEC_PBCFG
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(CanSM_ConfigType, CANSM_PBCFG) CanSMConfiguration;

# define CANSM_STOP_SEC_PBCFG
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
  API Functions
**********************************************************************************************************************/

# define CANSM_START_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */


/*********************************************************************************************************************
  FUNCTION: CanSM_Init
----------------------------------------------------------------------------------------------------------------------
  API     Type                              Name                            Description
----------------------------------------------------------------------------------------------------------------------
   Input: void / CanSM_ConfigType           - / *CanSm_ConfigPtr            configuration data structure (depends on configuration variant)
  Output: -
  Return: -
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: EcuM

  The API function to Initialize the CAN State Manager
*********************************************************************************************************************/
#if ( ( (0x03u) == CANSM_CONFIG_VARIANT ) || ( STD_ON == CANSM_IDENTITY_MANAGER_CONFIG )  )   /* PRQA S 0883 */ /* QAC bug. get rid of message: Include file code is not protected against repeated inclusion */
FUNC( void, CANSM_CODE ) CanSM_Init( P2CONST( CanSM_ConfigType, AUTOMATIC, CANSM_PBCFG ) CanSM_ConfigPtr );
#elif (  ( (0x01u)  == CANSM_CONFIG_VARIANT ) || ( (0x02u)  == CANSM_CONFIG_VARIANT )  )
FUNC( void, CANSM_CODE ) CanSM_Init( void );
#endif /* end if pre-compile (0x01u) OR link time 0x02u) configuration */




/*********************************************************************************************************************
  FUNCTION: CanSM_InitMemory
----------------------------------------------------------------------------------------------------------------------
  API     Type                              Name                            Description
----------------------------------------------------------------------------------------------------------------------
   Input: void                              -                               -
  Output: -
  Return: -
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: EcuM / Application

     Function to initialize some global variables which has to be set before the Init has been called (e.g. after ECU reset without powerup)
*********************************************************************************************************************/
FUNC( void, CANSM_CODE ) CanSM_InitMemory( void );


/*********************************************************************************************************************
  FUNCTION: CanSM_PreventBusSleepAtStartUp
----------------------------------------------------------------------------------------------------------------------
  API     Type                        Name                        Description
----------------------------------------------------------------------------------------------------------------------
   Input: NetworkHandleType           CanSm_NetworkHandle,        Specifies the CAN channel
  Output: -
  Return: -
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: EcuM
  Precondition: CanSM_Init must NOT be initialized.

  This API function receives network handle of the CAN channel which must NOT set to sleep during the initialization
*********************************************************************************************************************/
FUNC( Std_ReturnType, CANSM_CODE ) CanSM_PreventBusSleepAtStartUp( NetworkHandleType CanSM_NetworkHandle );


# define CANSM_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*******************************************************************************
* Organi check
*******************************************************************************/


#endif /* end if not defined ( CANSM_ECUM_H ) */
/**********************************************************************************************************************
  END OF FILE: CanSM_EcuM.h
**********************************************************************************************************************/
/*  *****   STOPSINGLE_OF_MULTIPLE_COMMENT    *****  */

