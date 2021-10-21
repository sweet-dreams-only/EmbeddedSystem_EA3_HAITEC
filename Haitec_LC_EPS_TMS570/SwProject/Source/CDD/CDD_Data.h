/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : CDD_Data.h
* Module Description: Header file for data communicated between Nxtr
*                      Complex Device Drivers (CDD)
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
* %version:          13 %
* %derived_by:       nzx5jd %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                               SCR #
* --------  -------  --------  ------------------------------------------------------------------------------  -------
* 07/17/13   1       OT        Initial Haitec version
* 07/30/13   2       OT        Added variables for DigMSB components
* 08/07/13   3       OT        Added more variables for DigMSB components
* 08/09/13   4       OT        Added global variable for CMS 0xFD23
* 08/27/13   5       OT        Added CDD_CommOffset_Cnt_G_u16
* 08/30/13   6       OT        Rerouted and clarified various CorrMtrPosElec signals
* 09/03/13   7       OT        Updates for latest DigMSB and DigMSBSigCorr components
* 12/02/13   8       OT        Removed Die1RevCntr per FDD 50A v4
* 04/21/14   9       OT        Added variables for updated ADC and ePWM modules
* 05/08/14  10       OT        Updates for DigMSB v6
* 12/15/14  11       OT        Updates for Adc v3 and CmMtrCurr v8
* 02/13/15  12       OT        Updates for DigMSB v6
* 02/18/15  13       OT        Updates for VehDyn v5
*/


#ifndef CDD_DATA_H
#define CDD_DATA_H

#include "Std_Types.h"
#include "CDD_Const.h"
#include "Rte_Type.h"


extern VAR(uint16,  CDD_DATA_VAR) CDD_ModIdxSrlComSvcDft_Cnt_G_u16;
extern VAR(sint8,   CDD_DATA_VAR) CDD_MtrElecPol_Cnt_G_s8;
extern VAR(uint32,  CDD_DATA_VAR) CDD_PWMPeriodSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(boolean, CDD_DATA_VAR) CDD_PwmDisable_Cnt_G_lgc[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32,  CDD_DATA_VAR) CDD_EOLSrlComSvcDft_Cnt_G_b32;
extern VAR(boolean, CDD_DATA_VAR) CDD_DftAsstTbl_Cnt_G_lgc;
extern VAR(float32, CDD_DATA_VAR) CDD_DwnldAsstGain_Uls_G_f32;
extern VAR(uint16,  CDD_DATA_VAR) CDD_DCPhsComp_Cnt_G_u16[3];
extern VAR(uint16,  CDD_DATA_VAR) CDD_PWMPeriod_Cnt_G_u16;
extern VAR(uint16,  CDD_DATA_VAR) CDD_ePWM4CMPB_Cnt_G_u16;
extern VAR(uint16,  CDD_DATA_VAR) CDD_ADC2OffsetComp_Cnt_G_u8p8;


extern VAR(float32, CDD_DATA_VAR) CDD_MtrCurr1_Volts_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_DATA_VAR) CDD_MtrCurr2_Volts_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_DATA_VAR) CDD_CorrMtrCurrPosition_Rev_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,  CDD_DATA_VAR) CDD_CorrectedElecMtrPos_Rev_G_u0p16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(sint32,  CDD_DATA_VAR) CDD_CumMechMtrPos_Rev_s15p16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,  CDD_DATA_VAR) CDD_Die1RxError_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,  CDD_DATA_VAR) CDD_Die1RxMtrPos_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,  CDD_DATA_VAR) CDD_Die1RxRevCtr_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,  CDD_DATA_VAR) CDD_Die1UnderVoltgFltAccum_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,  CDD_DATA_VAR) CDD_Die2RxError_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,  CDD_DATA_VAR) CDD_Die2RxMtrPos_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,  CDD_DATA_VAR) CDD_Die2RxRevCtr_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32,  CDD_DATA_VAR) CDD_PWMDutyCycleASum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32,  CDD_DATA_VAR) CDD_PWMDutyCycleBSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32,  CDD_DATA_VAR) CDD_PWMDutyCycleCSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,  CDD_DATA_VAR) CDD_PhaseAdvFinal_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,  CDD_DATA_VAR) CDD_MechMtrPos1_Rev_G_u0p16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32,  CDD_DATA_VAR) CDD_MechMtrPos1TimeStamp_uSec_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32,  CDD_DATA_VAR) CDD_MechMtrPos2TimeStamp_uSec_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32,  CDD_DATA_VAR) CDD_ModIdxFinal_Uls_G_u16p16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_DATA_VAR) CDD_MtrCurrDax_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_DATA_VAR) CDD_MtrCurrK1_Amps_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_DATA_VAR) CDD_MtrCurrK2_Amps_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_DATA_VAR) CDD_MtrCurrQaxFinalRef_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_DATA_VAR) CDD_MtrCurrQax_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_DATA_VAR) CDD_MtrVoltDax_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_DATA_VAR) CDD_MtrVoltQax_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,  CDD_DATA_VAR) CDD_RxMtrPosParityAccum_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,  CDD_DATA_VAR) CDD_SysCCorrectedElecMtrPos_Rev_G_u0p16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,  CDD_DATA_VAR) CDD_SysCVSwitchADC_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,  CDD_DATA_VAR) CDD_UncorrMechMtrPos1_Rev_G_u0p16[D_APPCDDBFRSIZE_CNT_U16];

extern VAR(uint16,  CDD_DATA_VAR) CDD_MtrCurrOffComOffset_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_DATA_VAR) CDD_MRFMtrVel_MtrRadpS_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_DATA_VAR) CDD_MtrCurr1TempOffset_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_DATA_VAR) CDD_MtrCurr2TempOffset_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(sint8,   CDD_DATA_VAR) CDD_MtrPosPolarity_Cnt_G_s08[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(sint16,  CDD_DATA_VAR) CDD_MtrTrqCmdSign_Cnt_G_s16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_DATA_VAR) CDD_Vecu_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(Rte_ModeType_StaMd_Mode, CDD_DATA_VAR) CDD_SysState_Cnt_G_Enum[D_APPCDDBFRSIZE_CNT_U16];


extern VAR(uint16,  CDD_DATA_VAR) CDD_AppDataFwdPthAccessBfr_Cnt_G_u16;
extern VAR(uint16,  CDD_DATA_VAR) CDD_AppDataFbkPthAccessBfr_Cnt_G_u16;
extern VAR(uint16,  CDD_DATA_VAR) CDD_CDDDataAccessBfr_Cnt_G_u16;


extern VAR(uint16,  CDD_DATA_VAR) CDD_CommOffset_Cnt_G_u16;

extern VAR(uint8,   CDD_DATA_VAR) CDD_EnergyModeState_Cnt_G_u08;

#endif

