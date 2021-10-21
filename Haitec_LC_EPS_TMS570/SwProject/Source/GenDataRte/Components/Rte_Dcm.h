/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2011 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Components/Rte_Dcm.h
 *     Workspace:  C:/SynergyProjects/Haitec_LC_EPS_TMS570-nzx5jd/Haitec_LC_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_DCM_H
# define _RTE_DCM_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_Customer_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0100_ConditionCheckRead DidServices_Customer_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_Customer_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0100_ConditionCheckWrite DidServices_Customer_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0x0100_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0x0100_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0100_ReadData DidServices_0x0100_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0x0100_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0x0100_WriteData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0100_WriteData DidServices_0x0100_WriteData
#  define Rte_Call_DidServices_0xf180_ConditionCheckRead DidServices_Customer_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xf180_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xf180_ReadData(P2VAR(Dcm_25Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf180_ReadData DidServices_0xf180_ReadData
#  define Rte_Call_DidServices_0xf187_ConditionCheckRead DidServices_Customer_ConditionCheckRead
#  define Rte_Call_DidServices_0xf187_ConditionCheckWrite DidServices_Customer_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xf187_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xf187_ReadData(P2VAR(Dcm_10Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf187_ReadData DidServices_0xf187_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xf187_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xf187_WriteData(P2VAR(Dcm_10Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf187_WriteData DidServices_0xf187_WriteData
#  define Rte_Call_DidServices_0xf18a_ConditionCheckRead DidServices_Customer_ConditionCheckRead
#  define Rte_Call_DidServices_0xf18a_ConditionCheckWrite DidServices_Customer_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xf18a_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xf18a_ReadData(P2VAR(Dcm_10Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf18a_ReadData DidServices_0xf18a_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xf18a_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xf18a_WriteData(P2VAR(Dcm_10Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf18a_WriteData DidServices_0xf18a_WriteData
#  define Rte_Call_DidServices_0xf18c_ConditionCheckRead DidServices_Customer_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xf18c_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xf18c_ReadData(P2VAR(Dcm_16Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf18c_ReadData DidServices_0xf18c_ReadData
#  define Rte_Call_DidServices_0xf191_ConditionCheckRead DidServices_Customer_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xf191_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xf191_ReadData(P2VAR(Dcm_16Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf191_ReadData DidServices_0xf191_ReadData
#  define Rte_Call_DidServices_0xf193_ConditionCheckRead DidServices_Customer_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xf193_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xf193_ReadData(P2VAR(Dcm_10Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf193_ReadData DidServices_0xf193_ReadData
#  define Rte_Call_DidServices_0xf194_ConditionCheckRead DidServices_Customer_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xf194_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xf194_ReadData(P2VAR(Dcm_10Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf194_ReadData DidServices_0xf194_ReadData
#  define Rte_Call_DidServices_0xf195_ConditionCheckRead DidServices_Customer_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xf195_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xf195_ReadData(P2VAR(Dcm_10Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf195_ReadData DidServices_0xf195_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_Nxtr_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd01_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd01_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd01_ReadData(P2VAR(Dcm_322Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd01_ReadData DidServices_0xfd01_ReadData
#  define Rte_Call_DidServices_0xfd02_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_Nxtr_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd02_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd02_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd02_ReadData(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd02_ReadData DidServices_0xfd02_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd02_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd02_WriteData(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd02_WriteData DidServices_0xfd02_WriteData
#  define Rte_Call_DidServices_0xfd07_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfd07_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd07_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd07_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd07_ReadData DidServices_0xfd07_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd07_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd07_WriteData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd07_WriteData DidServices_0xfd07_WriteData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_Service2F_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd0d_ConditionCheckRead DidServices_Service2F_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd0d_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd0d_ReadData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd0d_ReadData DidServices_0xfd0d_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd0d_ReturnControlToECU(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd0d_ReturnControlToECU(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd0d_ReturnControlToECU DidServices_0xfd0d_ReturnControlToECU
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd0d_ShortTermAdjustment(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd0d_ShortTermAdjustment(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd0d_ShortTermAdjustment DidServices_0xfd0d_ShortTermAdjustment
#  define Rte_Call_DidServices_0xfd0e_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd0e_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd0e_ReadData(P2VAR(Dcm_8Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd0e_ReadData DidServices_0xfd0e_ReadData
#  define Rte_Call_DidServices_0xfd10_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd10_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd10_ReadData(P2VAR(Dcm_10Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd10_ReadData DidServices_0xfd10_ReadData
#  define Rte_Call_DidServices_0xfd11_ConditionCheckRead DidServices_Service2F_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd11_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd11_ReadData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd11_ReadData DidServices_0xfd11_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd11_ReturnControlToECU(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd11_ReturnControlToECU(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd11_ReturnControlToECU DidServices_0xfd11_ReturnControlToECU
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd11_ShortTermAdjustment(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd11_ShortTermAdjustment(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd11_ShortTermAdjustment DidServices_0xfd11_ShortTermAdjustment
#  define Rte_Call_DidServices_0xfd12_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfd12_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd12_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd12_ReadData(P2VAR(Dcm_28Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd12_ReadData DidServices_0xfd12_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd12_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd12_WriteData(P2VAR(Dcm_28Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd12_WriteData DidServices_0xfd12_WriteData
#  define Rte_Call_DidServices_0xfd13_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd13_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd13_ReadData(P2VAR(Dcm_75Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd13_ReadData DidServices_0xfd13_ReadData
#  define Rte_Call_DidServices_0xfd14_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd14_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd14_ReadData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd14_ReadData DidServices_0xfd14_ReadData
#  define Rte_Call_DidServices_0xfd17_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd17_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd17_ReadData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd17_ReadData DidServices_0xfd17_ReadData
#  define Rte_Call_DidServices_0xfd19_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfd19_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd19_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd19_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd19_ReadData DidServices_0xfd19_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd19_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd19_WriteData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd19_WriteData DidServices_0xfd19_WriteData
#  define Rte_Call_DidServices_0xfd1a_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd1a_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd1a_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd1a_ReadData DidServices_0xfd1a_ReadData
#  define Rte_Call_DidServices_0xfd1b_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfd1b_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd1b_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd1b_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd1b_ReadData DidServices_0xfd1b_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd1b_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd1b_WriteData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd1b_WriteData DidServices_0xfd1b_WriteData
#  define Rte_Call_DidServices_0xfd1c_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd1c_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd1c_ReadData(P2VAR(Dcm_3Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd1c_ReadData DidServices_0xfd1c_ReadData
#  define Rte_Call_DidServices_0xfd1e_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfd1e_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd1e_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd1e_ReadData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd1e_ReadData DidServices_0xfd1e_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd1e_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd1e_WriteData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd1e_WriteData DidServices_0xfd1e_WriteData
#  define Rte_Call_DidServices_0xfd20_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd20_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd20_ReadData(P2VAR(Dcm_3Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd20_ReadData DidServices_0xfd20_ReadData
#  define Rte_Call_DidServices_0xfd21_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfd21_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd21_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd21_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd21_ReadData DidServices_0xfd21_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd21_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd21_WriteData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd21_WriteData DidServices_0xfd21_WriteData
#  define Rte_Call_DidServices_0xfd23_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfd23_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd23_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd23_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd23_ReadData DidServices_0xfd23_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd23_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd23_WriteData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd23_WriteData DidServices_0xfd23_WriteData
#  define Rte_Call_DidServices_0xfd25_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfd25_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd25_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd25_ReadData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd25_ReadData DidServices_0xfd25_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd25_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd25_WriteData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd25_WriteData DidServices_0xfd25_WriteData
#  define Rte_Call_DidServices_0xfd26_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfd26_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd26_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd26_ReadData(P2VAR(Dcm_3Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd26_ReadData DidServices_0xfd26_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd26_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd26_WriteData(P2VAR(Dcm_3Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd26_WriteData DidServices_0xfd26_WriteData
#  define Rte_Call_DidServices_0xfd27_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfd27_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd27_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd27_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd27_ReadData DidServices_0xfd27_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd27_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd27_WriteData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd27_WriteData DidServices_0xfd27_WriteData
#  define Rte_Call_DidServices_0xfd29_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfd29_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd29_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd29_ReadData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd29_ReadData DidServices_0xfd29_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd29_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd29_WriteData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd29_WriteData DidServices_0xfd29_WriteData
#  define Rte_Call_DidServices_0xfd30_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfd30_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd30_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd30_ReadData(P2VAR(Dcm_5Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd30_ReadData DidServices_0xfd30_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd30_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd30_WriteData(P2VAR(Dcm_5Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd30_WriteData DidServices_0xfd30_WriteData
#  define Rte_Call_DidServices_0xfd31_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd31_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfd31_ReadData(P2VAR(Dcm_12Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfd31_ReadData DidServices_0xfd31_ReadData
#  define Rte_Call_DidServices_0xfda1_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfda1_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfda1_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfda1_ReadData(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfda1_ReadData DidServices_0xfda1_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfda1_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfda1_WriteData(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfda1_WriteData DidServices_0xfda1_WriteData
#  define Rte_Call_DidServices_0xfda2_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfda2_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfda2_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfda2_ReadData(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfda2_ReadData DidServices_0xfda2_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfda2_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfda2_WriteData(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfda2_WriteData DidServices_0xfda2_WriteData
#  define Rte_Call_DidServices_0xfda3_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfda3_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfda3_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfda3_ReadData(P2VAR(Dcm_12Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfda3_ReadData DidServices_0xfda3_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfda3_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfda3_WriteData(P2VAR(Dcm_12Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfda3_WriteData DidServices_0xfda3_WriteData
#  define Rte_Call_DidServices_0xfdac_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfdac_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdac_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdac_ReadData(P2VAR(Dcm_64Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfdac_ReadData DidServices_0xfdac_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdac_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdac_WriteData(P2VAR(Dcm_64Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfdac_WriteData DidServices_0xfdac_WriteData
#  define Rte_Call_DidServices_0xfdad_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdad_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdad_ReadData(P2VAR(Dcm_7Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfdad_ReadData DidServices_0xfdad_ReadData
#  define Rte_Call_DidServices_0xfdae_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfdae_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdae_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdae_ReadData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfdae_ReadData DidServices_0xfdae_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdae_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdae_WriteData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfdae_WriteData DidServices_0xfdae_WriteData
#  define Rte_Call_DidServices_0xfdaf_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdaf_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdaf_ReadData(P2VAR(Dcm_176Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfdaf_ReadData DidServices_0xfdaf_ReadData
#  define Rte_Call_DidServices_0xfdb0_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfdb0_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb0_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb0_ReadData(P2VAR(Dcm_256Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfdb0_ReadData DidServices_0xfdb0_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb0_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb0_WriteData(P2VAR(Dcm_256Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfdb0_WriteData DidServices_0xfdb0_WriteData
#  define Rte_Call_DidServices_0xfdb1_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfdb1_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb1_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb1_ReadData(P2VAR(Dcm_256Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfdb1_ReadData DidServices_0xfdb1_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb1_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb1_WriteData(P2VAR(Dcm_256Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfdb1_WriteData DidServices_0xfdb1_WriteData
#  define Rte_Call_DidServices_0xfdb2_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfdb2_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb2_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb2_ReadData(P2VAR(Dcm_256Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfdb2_ReadData DidServices_0xfdb2_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb2_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb2_WriteData(P2VAR(Dcm_256Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfdb2_WriteData DidServices_0xfdb2_WriteData
#  define Rte_Call_DidServices_0xfdb3_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfdb3_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb3_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb3_ReadData(P2VAR(Dcm_256Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfdb3_ReadData DidServices_0xfdb3_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb3_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb3_WriteData(P2VAR(Dcm_256Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfdb3_WriteData DidServices_0xfdb3_WriteData
#  define Rte_Call_DidServices_0xfdb4_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfdb4_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb4_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb4_ReadData(P2VAR(Dcm_8Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfdb4_ReadData DidServices_0xfdb4_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb4_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb4_WriteData(P2VAR(Dcm_8Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfdb4_WriteData DidServices_0xfdb4_WriteData
#  define Rte_Call_DidServices_0xfdb5_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfdb5_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb5_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb5_ReadData(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfdb5_ReadData DidServices_0xfdb5_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb5_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb5_WriteData(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfdb5_WriteData DidServices_0xfdb5_WriteData
#  define Rte_Call_DidServices_0xfdb6_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfdb6_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb6_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb6_ReadData(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfdb6_ReadData DidServices_0xfdb6_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb6_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb6_WriteData(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfdb6_WriteData DidServices_0xfdb6_WriteData
#  define Rte_Call_DidServices_0xfdb7_ConditionCheckRead DidServices_Nxtr_ConditionCheckRead
#  define Rte_Call_DidServices_0xfdb7_ConditionCheckWrite DidServices_Nxtr_ConditionCheckWrite
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb7_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb7_ReadData(P2VAR(Dcm_18Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfdb7_ReadData DidServices_0xfdb7_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb7_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfdb7_WriteData(P2VAR(Dcm_18Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfdb7_WriteData DidServices_0xfdb7_WriteData
#  define Rte_Call_DidServices_0xfe00_ConditionCheckRead DidServices_Service2F_ConditionCheckRead
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfe00_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfe00_ReadData(P2VAR(Dcm_3Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfe00_ReadData DidServices_0xfe00_ReadData
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfe00_ReturnControlToECU(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfe00_ReturnControlToECU(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_3Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfe00_ReturnControlToECU DidServices_0xfe00_ReturnControlToECU
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfe00_ShortTermAdjustment(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) DidServices_0xfe00_ShortTermAdjustment(P2VAR(Dcm_3Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_3Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xfe00_ShortTermAdjustment DidServices_0xfe00_ShortTermAdjustment
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) RoutineServices_0xf000_Start(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) RoutineServices_0xf000_Start(P2VAR(Dcm_3Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0xf000_Start RoutineServices_0xf000_Start
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) RoutineServices_0xf001_Start(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) RoutineServices_0xf001_Start(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0xf001_Start RoutineServices_0xf001_Start
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) RoutineServices_0xf003_Start(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) RoutineServices_0xf003_Start(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0xf003_Start RoutineServices_0xf003_Start
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) RoutineServices_0xf004_Start(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) RoutineServices_0xf004_Start(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0xf004_Start RoutineServices_0xf004_Start
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) RoutineServices_0xf005_Start(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) RoutineServices_0xf005_Start(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_3Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0xf005_Start RoutineServices_0xf005_Start
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) RoutineServices_0xf008_Start(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) RoutineServices_0xf008_Start(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0xf008_Start RoutineServices_0xf008_Start
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) RoutineServices_0xf009_RequestResults(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) RoutineServices_0xf009_RequestResults(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0xf009_RequestResults RoutineServices_0xf009_RequestResults
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) RoutineServices_0xf009_Start(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) RoutineServices_0xf009_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0xf009_Start RoutineServices_0xf009_Start
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) RoutineServices_0xf009_Stop(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) RoutineServices_0xf009_Stop(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0xf009_Stop RoutineServices_0xf009_Stop
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) RoutineServices_0xf0ff_Start(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) RoutineServices_0xf0ff_Start(P2VAR(Dcm_6Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0xf0ff_Start RoutineServices_0xf0ff_Start
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) RoutineServices_0xfee0_Start(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) RoutineServices_0xfee0_Start(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0xfee0_Start RoutineServices_0xfee0_Start
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) SecurityAccess_1_CompareKey(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Key);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) SecurityAccess_1_CompareKey(P2VAR(Dcm_SecAccess_1_KeyType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Key);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SecurityAccess_1_CompareKey SecurityAccess_1_CompareKey
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) SecurityAccess_1_GetSeed(P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) securityAccessDataRecord, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) SecurityAccess_1_GetSeed(P2VAR(Dcm_SecAccess_1_DataRecType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) securityAccessDataRecord, P2VAR(Dcm_SecAccess_1_SeedType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_AP_DIAGSVC_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SecurityAccess_1_GetSeed SecurityAccess_1_GetSeed
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) SessionControl_ChangeIndication(Dcm_SesCtrlType SesCtrlTypeOld, Dcm_SesCtrlType SesCtrlTypeNew);
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SessionControl_ChangeIndication SessionControl_ChangeIndication
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) SessionControl_ConfirmationRespPending(Dcm_ConfirmationStatusType status);
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SessionControl_ConfirmationRespPending SessionControl_ConfirmationRespPending
#  define RTE_START_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGSVC_APPL_CODE) SessionControl_GetSesChgPermission(Dcm_SesCtrlType SesCtrlTypeActive, Dcm_SesCtrlType SesCtrlTypeNew);
#  define RTE_STOP_SEC_AP_DIAGSVC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SessionControl_GetSesChgPermission SessionControl_GetSesChgPermission


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_DCM_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_DCM_APPL_CODE) Dcm_MainFunction(void);

FUNC(Std_ReturnType, RTE_DCM_APPL_CODE) Dcm_GetSecurityLevel(P2VAR(Dcm_SecLevelType, AUTOMATIC, RTE_DCM_APPL_VAR) SecLevel);

FUNC(Std_ReturnType, RTE_DCM_APPL_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType, AUTOMATIC, RTE_DCM_APPL_VAR) SessionCtrlType);

# define RTE_STOP_SEC_DCM_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DCMServices_E_NOT_OK (1U)

#  define RTE_E_DidServices_0x0100_E_NOT_OK (1U)

#  define RTE_E_DidServices_0x0100_E_PENDING (10U)

#  define RTE_E_DidServices_0xf180_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xf180_E_PENDING (10U)

#  define RTE_E_DidServices_0xf187_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xf187_E_PENDING (10U)

#  define RTE_E_DidServices_0xf18a_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xf18a_E_PENDING (10U)

#  define RTE_E_DidServices_0xf18c_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xf18c_E_PENDING (10U)

#  define RTE_E_DidServices_0xf191_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xf191_E_PENDING (10U)

#  define RTE_E_DidServices_0xf193_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xf193_E_PENDING (10U)

#  define RTE_E_DidServices_0xf194_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xf194_E_PENDING (10U)

#  define RTE_E_DidServices_0xf195_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xf195_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd01_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd01_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd02_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd02_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd07_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd07_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd0d_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd0d_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd0e_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd0e_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd10_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd10_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd11_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd11_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd12_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd12_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd13_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd13_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd14_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd14_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd17_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd17_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd19_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd19_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd1a_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd1a_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd1b_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd1b_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd1c_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd1c_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd1e_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd1e_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd20_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd20_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd21_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd21_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd23_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd23_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd25_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd25_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd26_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd26_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd27_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd27_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd29_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd29_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd30_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd30_E_PENDING (10U)

#  define RTE_E_DidServices_0xfd31_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfd31_E_PENDING (10U)

#  define RTE_E_DidServices_0xfda1_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfda1_E_PENDING (10U)

#  define RTE_E_DidServices_0xfda2_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfda2_E_PENDING (10U)

#  define RTE_E_DidServices_0xfda3_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfda3_E_PENDING (10U)

#  define RTE_E_DidServices_0xfdac_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfdac_E_PENDING (10U)

#  define RTE_E_DidServices_0xfdad_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfdad_E_PENDING (10U)

#  define RTE_E_DidServices_0xfdae_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfdae_E_PENDING (10U)

#  define RTE_E_DidServices_0xfdaf_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfdaf_E_PENDING (10U)

#  define RTE_E_DidServices_0xfdb0_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfdb0_E_PENDING (10U)

#  define RTE_E_DidServices_0xfdb1_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfdb1_E_PENDING (10U)

#  define RTE_E_DidServices_0xfdb2_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfdb2_E_PENDING (10U)

#  define RTE_E_DidServices_0xfdb3_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfdb3_E_PENDING (10U)

#  define RTE_E_DidServices_0xfdb4_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfdb4_E_PENDING (10U)

#  define RTE_E_DidServices_0xfdb5_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfdb5_E_PENDING (10U)

#  define RTE_E_DidServices_0xfdb6_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfdb6_E_PENDING (10U)

#  define RTE_E_DidServices_0xfdb7_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfdb7_E_PENDING (10U)

#  define RTE_E_DidServices_0xfe00_E_NOT_OK (1U)

#  define RTE_E_DidServices_0xfe00_E_PENDING (10U)

#  define RTE_E_RoutineServices_0xf000_E_PENDING (10U)

#  define RTE_E_RoutineServices_0xf001_E_PENDING (10U)

#  define RTE_E_RoutineServices_0xf003_E_PENDING (10U)

#  define RTE_E_RoutineServices_0xf004_E_PENDING (10U)

#  define RTE_E_RoutineServices_0xf005_E_PENDING (10U)

#  define RTE_E_RoutineServices_0xf008_E_PENDING (10U)

#  define RTE_E_RoutineServices_0xf009_E_PENDING (10U)

#  define RTE_E_RoutineServices_0xf0ff_E_PENDING (10U)

#  define RTE_E_RoutineServices_0xfee0_E_PENDING (10U)

#  define RTE_E_SecurityAccess_1_E_COMPARE_KEY_FAILED (11U)

#  define RTE_E_SecurityAccess_1_E_NOT_OK (1U)

#  define RTE_E_SecurityAccess_1_E_PENDING (10U)

#  define RTE_E_SessionControl_E_FORCE_RCRRP (12U)

#  define RTE_E_SessionControl_E_NOT_OK (1U)

#  define RTE_E_SessionControl_E_PENDING (10U)

#  define RTE_E_SessionControl_E_SESSION_NOT_ALLOWED (4U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */


#endif /* _RTE_DCM_H */
