/*******************************************************************************
* File Name          : Disp.h
* Author             :  
* Version            : V1.0
* Date               : 03/13/2013
* Description        : 
*******************************************************************************/
#ifndef  __DataType_Config_H__
#define  __DataType_Config_H__
/* Local includes ------------------------------------------------------------*/
#include "DataType_Config.h"
/* Private define ------------------------------------------------------------*/
/*MOS管控制***********************************************/
#define K48_OUT_OFF  ZQ48_OUT_PORT->BSRR = ZQ48_OUT_Pin 
#define K48_OUT_ON   ZQ48_OUT_PORT->BRR  = ZQ48_OUT_Pin

#define ZQ48_OUT_OFF  K48_OUT_PORT->BSRR = K48_OUT_Pin 
#define ZQ48_OUT_ON   K48_OUT_PORT->BRR  = K48_OUT_Pin

#define BAT_MEASURE_OFF  BAT_MEASURE_PORT->BSRR = BAT_MEASURE_Pin 
#define BAT_MEASURE_ON   BAT_MEASURE_PORT->BRR  = BAT_MEASURE_Pin	
	
#define         BatteryU_LoadLowErr             0x0001                          // 电池负载电压太低
#define         BatteryI_LoadLowErr             0x0002                          // 电池额定负载电流太小
#define         BatteryR_InnerHighErr           0x0004                          // 电池内阻太大
#define         BatteryP_PowerlowErr            0x0008                          // 电池电量太低不能启动水轮机

#define         Battery_Err											0x0010                  // 电池故障
#define         AC220_ShortBridge_Err						0x0020                          // 电池故障

#define LED_RHA_H LED5_H(DIR.DirData[9]) 
#define LED_RHA_L LED5_L(DIR.DirData[9]) 

#define LED_XL_H LED3_H(DIR.DirData[10]) 
#define LED_XL_L LED3_L(DIR.DirData[10]) 

#define LED_HY_H LED4_H(DIR.DirData[10]) 
#define LED_HY_L LED4_L(DIR.DirData[10]) 

#define LED_FC_H LED5_H(DIR.DirData[10]) 
#define LED_FC_L LED5_L(DIR.DirData[10]) 


//-----------------------------------------------------------------
#define HLJC 0X01
#define HYJC 0X02
#define HYFC 0X04
#define CD_W 0X08
#define W220F 0X10
/* Private variables ---------------------------------------------------------*/

/* variables external used----------------------------------------------------*/
extern u8  bEvenCharge, bEven_I,bSeccon;    
extern u8 DI_State;
/* functions external used----------------------------------------------------*/
extern void DI_State_filter(void);
extern void Data_Handle(void);
extern void V48PIDControl(void);
extern void V48SorseTest(void);
extern void CalculTiaoZhiDuM(void);
#endif

