/******************** (C) COPYRIGHT 2010 LEAD **********************************
* File Name          : Key_Handle.c
* Author             : Multi Function Electrical Meter Application Team
* Version            : V1.0
* Date               : 07/21/2010
* Description        : Main program body
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "DataType_Config.h"
/* Local includes ------------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* extern variables ----------------------------------------------------------*/       

/* Private functions ---------------------------------------------------------*/

/* extern functions ----------------------------------------------------------*/

/*******************************************************************************
**  Time:      2009-12-5 wxq
**  Function:  I2C延时
**  Input:
**  Output:
**  Attention:
*******************************************************************************/
void I2CWait(u16 us)   
{ 
    while(us--); 
} 

#define I2CWait I2CWait(400)  

/********开启I2C总线********/
void I2CStart(void)
{        
    SCL_H;     
    I2CWait;
    SDA_H;      
    I2CWait; 
    SDA_L;    
    I2CWait;	
    SCL_L;     
    I2CWait;	
}

/********关闭I2C总线*******/
void I2CStop(void)
{         
    SCL_L;
    I2CWait; 
    SDA_L; 
    I2CWait; 
    SCL_H;
    I2CWait; 
    SDA_H;
    I2CWait;
    SCL_L;
    I2CWait;
}

/*********发送ACK*********/
void I2CAck(void)
{   
    SDA_L; 
    I2CWait; 
    SCL_L; 
    I2CWait; 
    SCL_H;
    I2CWait;
    SCL_L;
    I2CWait; 
}

/*********发送NO ACK*********/
void I2CNoAck(void)
{   
    SDA_H;
    I2CWait;
    SCL_L;
    I2CWait;
    SCL_H;
    I2CWait; 
    SCL_L;
    I2CWait;
}

/*********读取ACK信号*********/
void I2CWaitAck(void)  //返回为:1=有ACK,0=无ACK
{
 
    SCL_L;        
    I2CWait; 
    SCL_H;
    I2CWait; 	
    SDA_L;   // STUR_SDA;
    I2CWait; 
	  I2CWait;
    SDA_H;  // STUW_SDA;
    I2CWait; 	
    SCL_L;  
    I2CWait;
}  
  
/*******************************************************************
**  Time:      2009-12-7 wxq
**  Function:  I2CSendByte （从IIC发送一个字节）
**  Input:
**  Output:
**  Attention:
*******************************************************************/   
void I2CSendByte(u8 demand) 
{
    u8 i=8;                       
                                         
    while( i-- )
    {        
        SCL_L;
        I2CWait;    	
        if( demand&0x80 ) {SDA_H;}
        else              {SDA_L;}
				
        I2CWait; 			
        demand<<=1;                                                                    
        SCL_H;
        I2CWait; 			
    }
    SCL_L;
    I2CWait;   	
}
/***********************************************************************
**  Time: 	 
**  Function: 写EE值为0，防止上电时，输出电流
**  Input:		
**  Output:		
**  Attention:
***********************************************************************/
void WriteDac_4725_EE_INITDATA(u8 adr)
{
    I2CStart();
	  if(adr==1)I2CSendByte(0xc2);       // 发送MCP4725器件地址 1100 0010
    if(adr==0)I2CSendByte(0xc0);       // 发送MCP4725器件地址 1100 0000
    I2CWaitAck();                    
    I2CSendByte(0x60);       // 写命令 0110 0000                 
    I2CWaitAck();   
    I2CSendByte(0x00);       // 数据D11-D4
    I2CWaitAck();  
    I2CSendByte(0x00);       // 数据D3-D0
    I2CWaitAck();
    I2CStop();
}
/*******************************************************************************
* Function Name : void Wr_MCP4725(uint16 uiDAC_Data)
* Description   : MCP4725 快速模式写DAC寄存器 快速模式:(C2,C1)=(0,0)
*               :                             关断模式:(PD1,PD0)=(0,0)  
* Input         : uiDAC_Data高4位为0 即 0000 xxxx xxxx xxxxb
* Output        : None
* Return        : None adr:管脚A0接地 adr=0  管脚A0接VCC adr=1；
*******************************************************************************/
void Wr_MCP4725(u16 uiDAC_Data, u8 adr)
{
    I2CStart();
    
	  if(adr==1)I2CSendByte(0xc2);       // 发送MCP4725器件地址 1100 0010
    if(adr==0)I2CSendByte(0xc0);       // 发送MCP4725器件地址 1100 0000
    I2CWaitAck();                    
    I2CSendByte(0x40);       // 写命令 0100 0000                 
    I2CWaitAck();
    
    I2CSendByte((u8)(uiDAC_Data>>4)); // 数据D11-D4
    I2CWaitAck();  
    I2CSendByte((u8)(uiDAC_Data<<4)); // 数据D3-D0
    I2CWaitAck();
    
    I2CStop();
}

