/******************** (C) COPYRIGHT 2010 LEAD **********************************
* File Name          : Data_Handle.c
* Author             : Multi Function Electrical Meter Application Team
* Version            : V1.0
* Date               : 16/03/21
* Description        : Main program body
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
/* Local includes ------------------------------------------------------------*/
#include "DataType_Config.h"
//#include "Flash.h"
/* Private macro -------------------------------------------------------------*/
strParamSet_TypeDef             Setted, Setting;
strParamSet_TypeDef  SET_init = {0x07,
	                               0x0a,
																 0x06,
																 0x00,
																 16384 
																}; 
strTestData_TypeDef             Test;
LPF_Z_Type                      Filter;

extern void USART_waveform(u8 Usart_Num);
extern void ModifySettedPara(void);
extern FLASH_Status WriteSettedParam(void);

int8 GUI_output, Zero_adjustment = 1, Normal_operation;

extern	u16 t[6];
extern	u16 h[6];
extern	u16 Temp[2];


const int16  iDownLimitParamSet[] = {  
	                                     0x01,     // 本机地址        0x01~0xf7                         
	          
	                                     0x0a,     // 报警阈值        0x0a~0x64 
	
	                                     0x00,		 // 低通滤波        0x00~0x06
	
																			 0x00,     // 工作范围        0x00~0x18 
	
                                       0x00,    //  LBS灵敏度       
};
                                                                                                                                                                                                    
const int16  iUpLimitParamSet[] = {    
	                                     0xf7,     //本机地址         0x01~0xf7
	 
	                                     0x64,    // 报警阈值         10~100
	
	                                     0x06,	   // 低通滤波        0x00~0x06
	
																			 0x18,     // 工作范围        0x00~0x18 
	
	                                     0x4000,   // LBS灵敏度       2048~16384    
};

/******************************************************************************
** 函数原形：void RecoverPara(void)
** 功能描述；恢复出厂参数
** 参数说明：
** 返回值：
******************************************************************************/
void RecoverPara(void)
{
	Setted.iAddr        =    0x07;
	Setted.State_data   =    0x0a;      // 触发报警阈值
	Setted.Low_Pass     =    0x06;      // 低通滤波    0x00~0x06
	Setted.Acc_Speed    =    0x00;      // 工作范围    0x00-2g   0x08-4g   0x10-8g   0x18-16g
	Setted.LSB_Sens     =    16384;
        
}


