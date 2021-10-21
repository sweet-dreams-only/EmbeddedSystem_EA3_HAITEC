/* Kernbauer Version: 1.16 Konfiguration: Gw_AsrPduR Erzeugungsgangnummer: 957 */

/* STARTSINGLE_OF_MULTIPLE */

/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2012 by Vctr Informatik GmbH.                                                  All rights reserved.
 * 
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  PduR_Dcm.h
 *      Project:  Gw_AsrPduR
 *       Module:  MICROSAR PDU Router
 *    Generator:  GENy
 *
 *  Description:  Implements AUTOSAR PDU Router SWS Version: 2.2.1
 *  
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Hartmut Hoerner               HH            Vctr Informatik GmbH
 *  Gunnar de Haan                dH            Vctr Informatik GmbH
 *  Holger Birke                  Bir           Vctr Informatik GmbH
 *  Hannes Haas                   vishs         Vctr Informatik GmbH
 *  Erich Schondelmaier           visehs        Vctr Informatik GmbH
 *  Gunnar Meiss                  visms         Vctr Informatik GmbH
 *  Safiulla Shakir               visssa        Vctr Informatik GmbH
 *  Sebastian Waldvogel           visswa        Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version  Date        Author     Change Id       Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  1.00.00  2004-10-21   HH/dH/Bir -               initial version
 *  1.01.00  2004-11-18   HH        -               rework of code inspection
 *  1.02.00  2005-07-20   HH        -               update to Autosar 1.0 spec
 *  2.00.00  2006-06-14   vishs     -               Update to Autosar 2.0 spec
 *  2.01.00  2006-06-16   vishs     -               ASR compliant header file structure
 *                        vishs     ESCAN00017204   added support for LIN_IF
 *                        vishs     ESCAN00017205   naming convention for internal names     
 *                        vishs     ESCAN00017289   code replication is not used     
 *                        vishs     ESCAN00018046   consistency check of GENy dll implementation version     
 *                        vishs     ESCAN00018049   added support for CAN_TP     
 *  2.02.00  2007-02-09   vishs     ESCAN00018027   configuration variant 3 (Post-Build) support
 *                        vishs     ESCAN00018918   Adapted multiple include protection according to impl. rules     
 *                        vishs     ESCAN00019488   Allow DCM I-PDU transmission over CAN_IF     
 *  2.03.00  2007-08-07   vishs     ESCAN00019585   Corrected assertion handing in PduR_DcmTransmit()
 *                        vishs     ESCAN00020247   Update to AUTOSAR 2.1 specification     
 *                        vishs     ESCAN00020699   Routing between DCM and FrTp and FrIf added     
 *                        vishs     ESCAN00021037   Removed magic number for link- and pre-compile configuration     
 *                        vishs     ESCAN00021608   Compiler error in systems with LinIf and Gw_PduR     
 *  2.04.00  2007-11-06   vishs     ESCAN00021825   Added interface routing for CanIf, LinIf and FrIf
 *                        vishs     ESCAN00022036   Removed non-selectable post-build configuration feature     
 *                        vishs     ESCAN00022639   Added TP layer routing for CanTp and FrTp     
 *                        vishs     ESCAN00023115   Added callout functions for IF layer routing (ASR RFC18729)
 *  2.04.01  2007-12-05   vishs     ESCAN00023555   Removed linker error within IF Gateway if used on CAN bus only
 *  2.05.00  2008-01-31   vishs     ESCAN00023614   Added J1939 support for COM
 *                        vishs     ESCAN00023615   Allow forwarding of PDUs between COM and CanTp     
 *                        vishs     ESCAN00023527   Update to AUTOSAR 2.2.1 specification (AUTOSAR Release 3.0)     
 *                                                   - Compiler and memory abstraction
 *                                                   - AR version check of used BSW modules (AUTOSAR 2.1 versions)
 *  3.00.00  2008-04-03   vishs     ESCAN00024199   TP layer gateway ring-buffer support added
 *                        vishs     ESCAN00024576   Fixed compiler warning
 *                        vishs     ESCAN00023527   AR version check of used BSW modules (AUTOSAR 3.0 versions)
 *                        vishs     ESCAN00024677   Corrected return value check of callout functions
 *                        vishs     ESCAN00024330   Renamed ComTpApi_* to Com_Tp*
 *                        vishs     ESCAN00024855   Removed compiler warning
 *                        vishs     ESCAN00025432   Support of DEM errors provided as defines
 *                        vishs     ESCAN00025460   Removed consistency chek for IF gateway configuration data
 *  3.01.00  2008-05-16   vishs     ESCAN00026211   Library consistency check
 *                        vishs     ESCAN00026291   Removed V_CRITICAL_SECTION_USE_VECTOR_COMMENT
 *                        vishs     ESCAN00026292   PduR_GetVersionInfo now exports instanceID
 *                        vishs     ESCAN00026645   Generator Version Check added
 *  3.02.00  2008-06-17   vishs     ESCAN00027250   Support for TMS320 memory model added (no changes required)
 *                        vishs     ESCAN00026645   TP Gateway Generator Version Check added
 *                        vishs     ESCAN00027223   Direct include of Vctr Informatik include files
 *  3.03.00  2008-07-14   vishs     ESCAN00027971   TP layer routing hangs in case of a buffer overflow
 *                        vishs     ESCAN00027975   Missing cast leads to generator tool compatiblity check failing
 *                        vishs     ESCAN00027978   Abort initialization after failed generator version check
 *                        vishs     ESCAN00028107   Removed compiler warning
 *                        vishs     ESCAN00027670   Allow deactivation of gateway features at pre-compile time
 *  3.04.00  2008-10-16   vishs     ESCAN00027223   Modified include structure of Vctr Informatik includes
 *                        vishs     ESCAN00029044   Loss of TP PDUs during TP layer routing
 *                        vishs     ESCAN00029134   Changed FRTP AR version compatibility check to correct version
 *                        vishs     ESCAN00029121   Corrected memory qualifiers for post-build modifiable types
 *                        vishs     ESCAN00029438   Remove unrequired call to DET in case of single frame TP routing
 *                        vishs     ESCAN00029545   Own MemCpy functions provided - activation trough user config file
 *                        vishs     ESCAN00029591   Optimized access to API forwarding routing tables
 *                        vishs     ESCAN00029773   Precompile- and link time configuration CRC check
 *                        vishs     ESCAN00029986   Application access to interface and TP layer services
 *                        vishs     ESCAN00030053   Added Dcm to FrIf API forwarding
 *  3.05.00  2008-11-13   vishs     ESCAN00031161   Wrong definition for Memmap section
 *                        vishs     ESCAN00031220   Internal TP I-PDU communication
 *  3.05.01  2009-01-08   vishs     ESCAN00032284   Changed pre-configuration
 *  3.06.00  2009-01-28   visehs    ESCAN00032637   Add IpduM Routing
 *           2009-03-27   visehs    ESCAN00033510   Compiler Warning: variable pQStart was declared but never referenced
 *           2009-03-27   visehs    ESCAN00033991   Only execute the main body of GwTp_RxIndication if this is the first call to RxIndication for the ongoing routing.
 *           2009-04-02   visehs    ESCAN00034346   Linker Error in PduR.c with PduR_Core functions
 *  3.06.01  2009-04-02   visehs    ESCAN00034423   Wrong praeprocessor directive in PduR.c for IpduM support in the Lin and Flexray API
 *           2009-04-02   visehs    ESCAN00034424   Wrong function call for IpduM TxConfirmation in the Flexray interface
 *           2009-04-02   visehs    ESCAN00034426   Typo in function calls IpduM TxConfirmation and RxConfiramtion in the Lin API
 *  3.06.02  2009-04-23   visehs    ESCAN00034709   Uninitialized struct in PduR_GwTp_RxIndication
 *  3.07.00  2009-04-09   visehs    ESCAN00035755   Add MostIf and MostTp Support
 *           2009-06-10   visehs    ESCAN00035777   Add Il_AsrIpduMIsBmwSub Support
 *           2009-06-10   visehs    ESCAN00035575   one preprocessor switch encapsulate all BAC21 features 
 *  3.08.00  2009-06-22   visms     ESCAN00035904   Support Multiple Configurations
 *  3.09.00  2009-06-29   visms     ESCAN00035624   Support LinTp
 *           2009-06-29   visehs    ESCAN00034705   Renamed J1939 as J1939Tp
 *           2009-07-09   vishs     ESCAN00033781   AUTOSAR 4.0 Style CanTp routing
 *           2009-07-16   vishs     ESCAN00034231   Remove Det Error PDUR_E_TP_BUFFER_SIZE_LIMIT
 *           2009-07-16   visms     ESCAN00034190   Pointless comparison of unsigned integer with zero in <MSN>_Init()
 *           2009-07-16   visms     ESCAN00036100   Library Preprocessor Checks
 *           2009-08-04   visms     ESCAN00036387   Intra ECU TP communication fails for Service ID 0x19
 *           2009-07-20   visehs    ESCAN00036552   Allow more than 255 routing relations for the GW use case to be configured
 *  3.09.01  2009-09-18   visms     ESCAN00037839   Support MOST Dynamic DLC Routing
 *                        visms     ESCAN00037840   Change MostTpDapHeaderType to kMostIfDapHdrLen
 *  3.09.02  2009-09-15   visehs    ESCAN00037986   PDU Routing to the wrong bus in case of LinTp in combination with FrTp
 *           2009-10-15   visehs    ESCAN00038015   Memory area could overwritten during VPB communication  
 *           2009-10-15   visehs    ESCAN00037887   Service IDs reported to DET are not matching the specification
 *  3.10.00  2009-09-09   visehs    ESCAN00037658   Support SoAdTp communication (IP Support)
 *  3.11.00  2009-09-26   visehs    ESCAN00038443   Tp messages will not be gated using the AUTOSAR 4.0 CanTp API if the Chunk Size and Buffer Size are equal
 *           2009-09-26   visehs    ESCAN00037849   Support CanNm2Com and FrNm2Com Interface
 *           2009-11-09   visms     ESCAN00037251   Support Dobt-CanTp Dispatcher
 *           2009-11-10   visms     ESCAN00038295   Compiler error: PDUR_LINTP2COM_ROUTING undefined
 *           2009-11-10   visms     ESCAN00038296   Compiler error: PDUR_DEACTIVATE_DEM_VERSION_CHECK undefined
 *           2009-11-11   visehs    ESCAN00039029   Service ID PDUR_FCT_DCMTX is reported to DET in PduR_ComTransmit
 *           2009-11-13   visms     ESCAN00038625   Support E_PENDING in as return of <Lo>Transmit
 *           2009-11-13   visehs    ESCAN00037889   Memory is overwritten with MOST
 *           2009-11-20   visehs    ESCAN00038553   Manage Remaining Chunks within the Buffer
 *  3.12.00  2010-02-02   visms     ESCAN00039221   Call CddDobt_PduRCanTpCallout only for Dobt capable CanTp Rx Pdus
 *           2010-02-19   visehs    ESCAN00040855   Tp messages will not be routed if the payload is smaller than the chunksize
 *           2010-02-25   visehs    ESCAN00041039   CanTp connections are failing to Dcm, Com and ApplTp 
 *           2010-03-01   visms     ESCAN00041272   MISRA-C:2004 Update
 *  3.13.00  2010-03-24   visehs    ESCAN00041796   Linker Error: unresolved external symbol Ipdum_TriggerTransmit
 *           2010-03-24   visehs    ESCAN00041799   Compiler Error:  'PduR_TpCnv_TxCom2LoInfo' : undeclared identifier 
 *           2010-03-24   visehs    ESCAN00040669   Compiler Warning:  'pCATx' :unused unreferenced local variable 
 *           2010-03-24   visehs    ESCAN00039668   Support Routing of 2 Consecutive CanTp Single Frames for CanTp 4.0 API
 *           2010-04-01   visehs    ESCAN00042017   Det Error occurs due to an unexpected API call
 *           2010-04-15   visehs    ESCAN00040305   Add Feature Tp Parameter Control
 *           2010-05-17   visehs    ESCAN00042972   Misra warning: Structure has fewer initializers than its declared size
 *           2010-05-17   visehs    ESCAN00042974   Null pointer assignment in function PduR_Core_CanTpProvideRxBuffer()
 *           2010-05-21   visehs    ESCAN00043076   Rename function parameter value name J1939Xxx to J1939TpXxx
 *  3.13.01  2010-06-21   visehs    ESCAN00043511   Det_ReportError is called with IpduM Module ID
 *           2010-06-21   visehs    ESCAN00043491   Add BAC30 IPDUM Compatibility Defines
 *  3.14.00  2010-06-25   visssa    ESCAN00043581   Support TP Receive Cancellation
 *           2010-07-20   visssa    ESCAN00043968   Support TP Transmit Cancellation
 *           2010-07-28   visms     ESCAN00044309   Multiple ECU: PduR_DcmChangeParameterRequest with inactive DcmRxPduId
 *           2010-07-30   visms     ESCAN00034188   Optimize ProvideBuffer, RxIndication and TxConfirmation calls in PduR_MainFunction
 *           2010-08-10   visehs    ESCAN00044523   Support Optimized Routing with FrTp
 *           2010-08-11   visehs    ESCAN00043995   Support PduRoutingPathGoups
 *           2010-08-11   visehs    ESCAN00041722   Compiler warning: unreachable code in PduR_CanTpProvideRxBuffer
 *  3.14.01  2010-08-21   visehs    ESCAN00045516   RoutingPath Groups cannot be disabled
 *           2010-08-21   visehs    ESCAN00045422   Linker Error: unresolved external symbol ApplIf_TxConfirmation
 *           2010-08-22   visehs    ESCAN00039232   Added a consistency check for the PduIdType
 *           2010-08-22   visehs    ESCAN00045553   Second FrTp consecutive frame to Dcm and ApplTp is blocked forever until watch dog reset
 *  3.14.02  2010-10-05   visehs    ESCAN00045786   ApplTp_TxConfirmation is not called
 *           2010-10-13   visehs    ESCAN00045795   RAM will be overwritten is no TP Buffers are configured
 *           2010-10-15   visms     ESCAN00045936   Notify Dem if the PduIdType Check fails
 *           2010-10-15   visms     ESCAN00045505   Routing of Functional Requests with Fan Out Stops
 *           2010-10-15   visms     ESCAN00045944   Physical Multiple ECU: ECU is blocked until Watch-Dog reset
 *           2010-10-15   visms     ESCAN00045891   PduR_<Up>CancelReceiveRequest does not work
 *           2010-10-21   visms     ESCAN00044894   Include and check PduR Headers only if the component is supported
 *           2010-10-21   visms     ESCAN00046298   Linker Error with PduR_GwTpTxConfirmation
 *  3.14.03  2010-10-21   visehs    ESCAN00046355   Compile error due to missing Define "PDUR_CANIF_SUPPORT"
 *  3.14.04  2010-10-27   visehs    ESCAN00046407   Compile error occurs if PDUR routing group support is enabled
 *  3.15.00  2010-10-19   visms     ESCAN00045920   Support Rx CanNm and FrNm
 *           2010-11-30   visms     ESCAN00046248   Perform AUTOSAR version check only for Vector
 *           2010-12-08   visms     ESCAN00040225   AR3-297 AR3-894: Support PduInfoType instead of the DataPtr
 *           2010-12-16   visehs    ESCAN00047004   Balance the Routing time of Physical TP Routings
 *           2010-12-08   visms     ESCAN00047232   Compiler warning PduR_Core_UpTpTxConfirmation declared but not used
 *           2010-12-16   visehs    ESCAN00045919   Optimize Wrap Around interaction with Lower Layer TPs and Physical TP Routings
 *           2011-01-17   visms     ESCAN00046408   Compiler Error: struct has no field "DestPduCntIndex"
 *           2011-02-22   visms     ESCAN00048509   Support CDD
 *           2011-02-22   visms     ESCAN00048088   Length of copied SDU data is not indicated in PduR_<Lo>TriggerTransmit() API
 *  3.15.01  2011-02-24   visehs    ESCAN00048899   Compiler warning occurs: zero used for undefined preprocessing identifier
 *           2011-02-24   visehs    ESCAN00048901   Compiler warning occurs:" PduR_GwIf_Init" was declared but never referenced
 *           2011-02-24   visehs    ESCAN00048903   Compiler warning: nested comment is not allowed
 *           2011-02-25   visms     ESCAN00048926   Unexpected ECU behavior on reception of a TP SDU
 *           2011-02-25   visms     ESCAN00048937   Compiler Warning: extern used with definition
 * 3.15.02   2011-03-15   visehs    ESCAN00049284   DET error occurs in function EnableRouting() and DisableRouting()
 * 3.15.03   2011-04-12   visehs    ESCAN00049366   DET error occurs in function PduR_GwIf_RxIndication()
 *           2011-04-12   visehs    ESCAN00049756   Add PDUR_SOURCE Define at the beginning of the PduR.c file
 *           2011-04-10   visehs    ESCAN00050229   Interface Layer routing with TriggerTransmit FiFo queued routing: Arbitrary value are transmitted
 *           2011-04-28   visehs    ESCAN00050402   PduR stops routing of a TP routing relation.
 *           2011-05-11   visehs    ESCAN00050818   Misra warning: possible truncation at implicit conversion to type "unsigned short"
 * 3.15.04   2011-05-17   visehs    ESCAN00050649   Some functional transport protocol requests (SF) are not routed to the upper Tp layer 
 * 3.15.05   2011-05-23   visehs    ESCAN00051055   Compiler Error occurs due to an inconsistent version number
 * 3.15.06   2011-05-30   visehs    ESCAN00051259   Rename SoAdTp to SoAd and adjust all APIs
 * 3.15.07   2011-07-28   visswa    ESCAN00052333   TP Routing buffer remains locked in case of a failed Tp transmission request
 *           2011-07-28   visswa    ESCAN00052434   TP Routing buffer remains locked after MostTp routing
 * 3.15.08   2012-05-30   visehs    ESCAN00054623   Incorrect memory mapping of PduR internal function declarations
 * 3.15.09   2012-08-08   visms     ESCAN00060604   AR3-2457: Dynamic DLC with TriggerTransmit based Communication Interfaces
 *           2012-08-13   visehs    ESCAN00060357   Tp Gateway use case: Changed return value for the initial Tp buffer request due to optimization reasons
 * 3.15.10   2012-08-31   visehs    ESCAN00054630   [ASR3] Incorrect mapping of PduR global data into memory section VAR_NOINIT_UNSPECIFIED
 *           2012-08-31   visehs    ESCAN00062517   Tp Gateway use case: Changed return value for the initial Tp buffer request for all use cases due to optimization reasons
 *********************************************************************************************************************/


#if !defined(PDUR_DCM_H)
# define PDUR_DCM_H

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "PduR.h"

/**********************************************************************************************************************
  VERSION CHECK
**********************************************************************************************************************/
# define GW_ASRPDUR_DCM_VERSION            (0x0315u)
# define GW_ASRPDUR_DCM_RELEASE_VERSION            (0x10u)

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# define Dcm_TpRxIndication               Dcm_RxIndication
# define Dcm_TpTxConfirmation             Dcm_TxConfirmation

 /**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
# if(PDUR_DCM_SUPPORT == STD_ON)

/*===========================================PDUR_START_SEC_CODE=====================================================*/
#  define PDUR_START_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */

/**********************************************************************************************************************
  PduR_DcmTransmit
**********************************************************************************************************************/
/** \brief     The function serves to request the transmission of a TP layer I-PDU.\n
               The PDU Router evaluates the incoming I-PDU ID and performs appropriate ID and port conversion.
               The call is routed to the TP layer using the appropriate I-PDU handle of the destination layer.
    \param[in] DcmTxPduId        ID of the Dcm I-PDU to be transmitted
    \param[in] PduInfoPtr        Payload information of the I-PDU (pointer to data and data length)
    \return    Std_ReturnType\n
               E_OK              The request was accepted by the PDU Router and by the destination layer.\n
               E_NOT_OK          The PDU Router is in the PDUR_UNINIT state\n
                                 or the DcmTxPduId is not valid\n
                                 or the DcmTxPduId is not forwarded in this identity\n
                                 or the PduInfoPtr is not valid\n
                                 or the request was not accepted by the TP layer.\n
    \pre       PduR_Init() is executed sucessfully and the PDU Router is in PDUR_ONLINE state. 
    \context   The function can be called on interrupt and task level and has not to be interrupted by other
               PduR_DcmTransmit calls for the same DcmTxPduId.
    \note      The function is called by Dcm.
**********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmTransmit(PduIdType DcmTxPduId,
                                                 P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr);


#  if  (PDUR_DCMCHANGEPARAMETER_SUPPORT == STD_ON)
/**********************************************************************************************************************
  PduR_DcmChangeParameterRequest
**********************************************************************************************************************/
/** \brief     The function serves to change a specific transport protocol parameter (e.g. block-size).\n
               The PDU Router evaluates the Dcm I-PDU handle and performs appropriate handle and port conversion.
               The call is routed to a lower TP module using the appropriate I-PDU handle of the destination layer.
    \param[in] DcmRxPduId        ID of the Dcm I-PDU where the parameter has to be changed
    \param[in] parameter         The TP parameter that shall be changed.
    \param[in] value             The new value for the TP parameter.
    \return    Std_ReturnType\n
               E_OK              The request was accepted by the PDU Router and by the destination layer.\n
               E_NOT_OK          The PDU Router is in the PDUR_UNINIT state\n
                                 or the DcmTxPduId is not valid\n
                                 or the DcmTxPduId is not forwarded in this identity\n
                                 or the request was not accepted by the TP layer.\n
    \pre       PduR_Init() is executed sucessfully and the PDU Router is in PDUR_ONLINE state. 
    \context   The function can be called on interrupt and task level and has not to be interrupted by other
               PduR_DcmChangeParameterRequest calls for the same DcmRxPduId.
    \note      The function is called by Dcm.
**********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmChangeParameterRequest(PduIdType DcmRxPduId, TPParameterType parameter,
                                                               uint16 value);
#  endif

#  if ((PDUR_CANTPREADPARAMETER_SUPPORT == STD_ON) || (PDUR_FRTPREADPARAMETER_SUPPORT == STD_ON))
/**********************************************************************************************************************
  PduR_DcmReadParameterRequest
**********************************************************************************************************************/
/** \brief         The function serves to read a specific transport protocol parameter (e.g. block-size).\n
                   The PDU Router evaluates the Dcm I-PDU handle and performs appropriate handle and port conversion.
                   The call is routed to a lower TP module using the appropriate I-PDU handle of the destination layer.
    \param[in]     DcmRxPduId        ID of the Dcm I-PDU where the parameter has to be changed
    \param[in]     parameter         The TP parameter that shall be read.
    \param[in,out] valuePtr          The pointer to buffer to return the parameter value.
    \return       Std_ReturnType\n
                  E_OK              The request was accepted by the PDU Router and by the destination layer.\n
                  E_NOT_OK          The PDU Router is in the PDUR_UNINIT state\n
                                    or the DcmTxPduId is not valid\n
                                    or the DcmTxPduId is not forwarded in this identity\n
                                    or the request was not accepted by the TP layer.\n
    \pre          PduR_Init() is executed sucessfully and the PDU Router is in PDUR_ONLINE state. 
    \context      The function can be called on interrupt and task level and has not to be interrupted by other
                  PduR_DcmReadParameterRequest calls for the same DcmRxPduId.
    \note         The function is called by Dcm.
**********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmReadParameterRequest(PduIdType DcmRxPduId, TPParameterType parameter,
                                                             P2VAR(uint16, AUTOMATIC, PDUR_APPL_DATA) valuePtr);
#  endif

#  if((PDUR_DCMRECEIVECANCELLATION_SUPPORT == STD_ON) && (PDUR_DCM_SUPPORT == STD_ON))
/**********************************************************************************************************************
  PduR_DcmCancelReceiveRequest
**********************************************************************************************************************/
/** \brief     The function serves to cancel the reception of a TP layer I-PDU.\n
               The PDU Router evaluates the Dcm I-PDU handle and performs appropriate handle and port conversion.
               The call is routed to a lower TP module using the appropriate I-PDU handle of the destination layer.
    \param[in] DcmRxPduId        ID of the RX Dcm I-PDU to be cancelled
    \return    Std_ReturnType\n
               E_OK              The cancellation request was accepted by the PDU Router and by the TP layer.\n
               E_NOT_OK          The PDU Router is in the PDUR_UNINIT state\n
                                 or the DcmRxPduId is not valid\n
                                 or the DcmRxPduId is not forwarded in this identity\n
                                 or the request was not accepted by the TP layer.\n
    \pre       PduR_Init() is executed sucessfully and the PDU Router is in PDUR_ONLINE state.\n
    \context   The function can be called on interrupt and task level and has not to be interrupted by other
               PduR_DcmCancelReceiveRequest calls for the same DcmRxPduId.
    \note      The function is called by Dcm.
**********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmCancelReceiveRequest(PduIdType DcmRxPduId);
#  endif

#  if((PDUR_DCMTRANSMITCANCELLATION_SUPPORT == STD_ON) && (PDUR_DCM_SUPPORT == STD_ON))
/**********************************************************************************************************************
  PduR_DcmCancelTransmitRequest
**********************************************************************************************************************/
/** \brief     The function serves to cancel the transmission of a TP layer I-PDU.\n
               The PDU Router evaluates the Dcm I-PDU handle and performs appropriate handle and port conversion.
               The call is routed to a lower TP module using the appropriate I-PDU handle of the destination layer.
    \param[in] DcmTxPduId        ID of the TX Dcm I-PDU to be cancelled
    \return    Std_ReturnType\n
               E_OK              The cancellation request was accepted by the PDU Router and by the TP layer.\n
               E_NOT_OK          The PDU Router is in the PDUR_UNINIT state\n
                                 or the DcmTxPduId is not valid\n
                                 or the DcmTxPduId is not forwarded in this identity\n
                                 or the request was not accepted by the TP layer.\n
    \pre       PduR_Init() is executed sucessfully and the PDU Router is in PDUR_ONLINE state. 
    \context   The function can be called on interrupt and task level and has not to be interrupted by other
               PduR_DcmCancelTransmitRequest calls for the same DcmTxPduId.
    \note      The function is called by Dcm.
**********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmCancelTransmitRequest(PduIdType DcmTxPduId);
#  endif

#  define PDUR_STOP_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */
/*============================================PDUR_STOP_SEC_CODE=====================================================*/

# endif

#endif /* !defined(PDUR_DCM_H) */

/* STOPSINGLE_OF_MULTIPLE */
