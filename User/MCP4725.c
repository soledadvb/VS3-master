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
**  Function:  I2C��ʱ
**  Input:
**  Output:
**  Attention:
*******************************************************************************/
void I2CWait(u16 us)   
{ 
    while(us--); 
} 

#define I2CWait I2CWait(400)  

/********����I2C����********/
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

/********�ر�I2C����*******/
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

/*********����ACK*********/
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

/*********����NO ACK*********/
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

/*********��ȡACK�ź�*********/
void I2CWaitAck(void)  //����Ϊ:1=��ACK,0=��ACK
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
**  Function:  I2CSendByte ����IIC����һ���ֽڣ�
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
**  Function: дEEֵΪ0����ֹ�ϵ�ʱ���������
**  Input:		
**  Output:		
**  Attention:
***********************************************************************/
void WriteDac_4725_EE_INITDATA(u8 adr)
{
    I2CStart();
	  if(adr==1)I2CSendByte(0xc2);       // ����MCP4725������ַ 1100 0010
    if(adr==0)I2CSendByte(0xc0);       // ����MCP4725������ַ 1100 0000
    I2CWaitAck();                    
    I2CSendByte(0x60);       // д���� 0110 0000                 
    I2CWaitAck();   
    I2CSendByte(0x00);       // ����D11-D4
    I2CWaitAck();  
    I2CSendByte(0x00);       // ����D3-D0
    I2CWaitAck();
    I2CStop();
}
/*******************************************************************************
* Function Name : void Wr_MCP4725(uint16 uiDAC_Data)
* Description   : MCP4725 ����ģʽдDAC�Ĵ��� ����ģʽ:(C2,C1)=(0,0)
*               :                             �ض�ģʽ:(PD1,PD0)=(0,0)  
* Input         : uiDAC_Data��4λΪ0 �� 0000 xxxx xxxx xxxxb
* Output        : None
* Return        : None adr:�ܽ�A0�ӵ� adr=0  �ܽ�A0��VCC adr=1��
*******************************************************************************/
void Wr_MCP4725(u16 uiDAC_Data, u8 adr)
{
    I2CStart();
    
	  if(adr==1)I2CSendByte(0xc2);       // ����MCP4725������ַ 1100 0010
    if(adr==0)I2CSendByte(0xc0);       // ����MCP4725������ַ 1100 0000
    I2CWaitAck();                    
    I2CSendByte(0x40);       // д���� 0100 0000                 
    I2CWaitAck();
    
    I2CSendByte((u8)(uiDAC_Data>>4)); // ����D11-D4
    I2CWaitAck();  
    I2CSendByte((u8)(uiDAC_Data<<4)); // ����D3-D0
    I2CWaitAck();
    
    I2CStop();
}

