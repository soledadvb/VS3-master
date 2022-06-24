
#ifndef __DATATYPE_CONFIG__
#define __DATATYPE_CONFIG__
//#include "sys.h"
#include "bsp_i2c_gpio.h"
#include "delay.h"


/*******************************************************************************
* File Name          : DataConfig.h
* Author             :
* Version            : V1.0
* Date               : 03/25/2010
* Description        : ���ݽṹ����
*******************************************************************************/
typedef unsigned char  uint8;                   /* �޷���8λ���ͱ���                        */
typedef signed   char  int8;                    /* �з���8λ���ͱ���                        */
typedef unsigned short uint16;                  /* �޷���16λ���ͱ���                       */
typedef signed   short int16;                   /* �з���16λ���ͱ���                       */
typedef unsigned int   uint32;                  /* �޷���32λ���ͱ���                       */
typedef signed   int   int32;                   /* �з���32λ���ͱ���                       */
typedef float          fp32;                    /* �����ȸ�������32λ���ȣ�                 */
typedef double         fp64;                    /* ˫���ȸ�������64λ���ȣ�                 */

typedef unsigned char  u8;                   		/* �޷���8λ���ͱ���                        */
typedef unsigned short u16;                  		/* �޷���16λ���ͱ���                       */
typedef unsigned int   u32;                  		/* �޷���32λ���ͱ���                       */
typedef signed   char  s8;                    	/* �з���8λ���ͱ���                        */
typedef signed   short s16;                   	/* �з���16λ���ͱ���                       */
typedef signed   int   s32;                   	/* �з���32λ���ͱ���                       */

typedef unsigned char  bool;                    /* �޷���8λ���ͱ��� ��������               */
#define    TRUE				 0x00
#define    FALSE			 0xff

//----------����������--------------------
//�����ȸ���������������
typedef union
{
	float floatData;
	u32 byteData;
}FLOAT_BYTE;

//S16����������
union S16Dat
{
	u8	 u8D[2];
	s16	 s16D;
};
//U16����������
union U16Dat
{
	u8 		u8D[2];
	u16	  u16D;
};
//S32����������
union U32Dat
{
	u8  	u8D[4];
	u32 	u32D;
};
//S32����������
union S32Dat
{
	u8   u8D[4];
	s32 	s32D;
};

//���в���
typedef struct
{
	s16	   	State_RUN,       //����״̬
          Max_x,	         //ÿ�������ֵ    
	        Max_y,                
	        Max_z,
	        Recur_x,         //x
	        Recur_y,         //y
	        Recur_z,         //z ����ƽ�����ٶ�
          Temp,            //Ƭ���¶�	
          Acc_x,           //ʵʱ���ٶ�ֵ(mm/s2)
					Acc_y,           
					Acc_z,           
  		    Mg_x,            //x 
					Mg_y,            //y
					Mg_z,            //z ���ٶ�(mg)
	        mmS2_x,          //x
	        mmS2_y,          //y
	        mmS2_z;          //z ���ٶ�(mm/s2)
	        
	
} strTestData_TypeDef;


//���ò���
typedef struct
{
u16           iAddr,            // ������ַ
	
              State_data,       // ������ֵ
	
	            Low_Pass,         // ��ͨ�˲������ã���ֹƵ��1K,����5K	0x00~0x06 

	            Acc_Speed,        // Gֵģʽ  ���ü��ٶȴ�����������2G 4G 8G 16G 
										 			      //                                00 04 10 18	
	            LSB_Sens;         // LSB������  2G     4G    8G    16G
													      //           16384  8192  4096  2048
	
} strParamSet_TypeDef;



//��ͨ�˲�����
typedef struct 
{
        u16  Alpha_Min;           //0x0048ƽ�ȸ���    
        u16  Alpha_inc;           //0x0049���ٸ���ϵ��
        u16  Threshold_1;         //0x004a�˲�������ֵ1
        u16  Threshold_2;         //0x004B�˲�������ֵ2
	
}LPF_Coefficient;

/* ��ϵ��Z�任LPF�ṹ�� */
typedef struct
{
        float  Alpha;             //�˲�ϵ��
        float  Old_Data;          //��һ�����ֵ
        LPF_Coefficient Coe;      //�˲���������ֵ
        u16  Data_Inc_Dir;        //����������������
        u16  Filter_Num;          //�˲�����ֵ
        u16  First; 
	      
}LPF_Z_Type;


		

//-----------------------------------------------------------------------------------------------------------
// �����ź�		

#define        G_Run        0x0000       //  ����״̬
#define        x_Err        0x0001       //x ����״̬
#define        y_Err        0x0002       //y ����״̬
#define        z_Err        0x0003       //z ����״̬

//-----------------------------------------------------------------------------------------------------------
// LED ָʾ��
#define        LED_AL     GPIO_ResetBits(GPIOB,PB14_A);     //PB14 �͵�ƽ ��
#define        LED_BL     GPIO_ResetBits(GPIOB,PB13_B);     //
#define        LED_CL     GPIO_ResetBits(GPIOB,PB12_C);     //
#define        LED_PowL    GPIO_ResetBits(GPIOB,PB8_LED1);

#define        LED_AH     GPIO_SetBits(GPIOB,PB14_A);       //PB14 �ߵ�ƽ ��
#define        LED_BH     GPIO_SetBits(GPIOB,PB13_B);       //
#define        LED_CH     GPIO_SetBits(GPIOB,PB12_C);       //
#define        LED_PowH   GPIO_SetBits(GPIOB,PB8_LED1);

#define         UltraSNum										      5    
#define         UltraS180Num									    4
#define         TestNum												  128
#define         KNum													    4
#define         ACNum													  300
#define         FILERT_N                         20
#define         FS_N                             40   //���ͼ��ٶ���������
        

/* MPU6050�Ĵ�����ַ ***********************************************************************/

#define MPU6050_ADD             	  0xD0   	//������ַ��AD0���ջ�͵�ƽʱ��ַ��0xD0��Ϊ�ߵ�ƽʱΪ0xD2��7λ��ַ��1101 000x��
#define MPU6050_RA_XG_OFFS_TC       0x00 
#define MPU6050_RA_YG_OFFS_TC       0x01 
#define MPU6050_RA_ZG_OFFS_TC       0x02 
#define MPU6050_RA_X_FINE_GAIN      0x03 
#define MPU6050_RA_Y_FINE_GAIN      0x04 
#define MPU6050_RA_Z_FINE_GAIN      0x05 
#define MPU6050_RA_XA_OFFS_H        0x06 
#define MPU6050_RA_XA_OFFS_L_TC     0x07
#define MPU6050_RA_YA_OFFS_H        0x08 
#define MPU6050_RA_YA_OFFS_L_TC     0x09
#define MPU6050_RA_ZA_OFFS_H        0x0A 
#define MPU6050_RA_ZA_OFFS_L_TC     0x0B
#define MPU6050_RA_XG_OFFS_USRH     0x13 
#define MPU6050_RA_XG_OFFS_USRL     0x14
#define MPU6050_RA_YG_OFFS_USRH     0x15 
#define MPU6050_RA_YG_OFFS_USRL     0x16
#define MPU6050_RA_ZG_OFFS_USRH     0x17 
#define MPU6050_RA_ZG_OFFS_USRL     0x18
#define MPU6050_RA_SMPLRT_DIV       0x19 
#define MPU6050_RA_CONFIG           0x1A 
#define MPU6050_RA_GYRO_CONFIG      0x1B 
#define MPU6050_RA_ACCEL_CONFIG     0x1C 
#define MPU6050_RA_FF_THR           0x1D 
#define MPU6050_RA_FF_DUR           0x1E
#define MPU6050_RA_MOT_THR          0x1F
#define MPU6050_RA_MOT_DUR          0x20
#define MPU6050_RA_ZRMOT_THR        0x21
#define MPU6050_RA_ZRMOT_DUR        0x22
#define MPU6050_RA_FIFO_EN          0x23
#define MPU6050_RA_I2C_MST_CTRL     0x24
#define MPU6050_RA_I2C_SLV0_ADDR    0x25
#define MPU6050_RA_I2C_SLV0_REG     0x26
#define MPU6050_RA_I2C_SLV0_CTRL    0x27
#define MPU6050_RA_I2C_SLV1_ADDR    0x28
#define MPU6050_RA_I2C_SLV1_REG     0x29
#define MPU6050_RA_I2C_SLV1_CTRL    0x2A
#define MPU6050_RA_I2C_SLV2_ADDR    0x2B
#define MPU6050_RA_I2C_SLV2_REG     0x2C
#define MPU6050_RA_I2C_SLV2_CTRL    0x2D
#define MPU6050_RA_I2C_SLV3_ADDR    0x2E
#define MPU6050_RA_I2C_SLV3_REG     0x2F
#define MPU6050_RA_I2C_SLV3_CTRL    0x30
#define MPU6050_RA_I2C_SLV4_ADDR    0x31
#define MPU6050_RA_I2C_SLV4_REG     0x32
#define MPU6050_RA_I2C_SLV4_DO      0x33
#define MPU6050_RA_I2C_SLV4_CTRL    0x34
#define MPU6050_RA_I2C_SLV4_DI      0x35
#define MPU6050_RA_I2C_MST_STATUS   0x36
#define MPU6050_RA_INT_PIN_CFG      0x37
#define MPU6050_RA_INT_ENABLE       0x38
#define MPU6050_RA_DMP_INT_STATUS   0x39
#define MPU6050_RA_INT_STATUS       0x3A
#define MPU6050_RA_ACCEL_XOUT_H     0x3B
#define MPU6050_RA_ACCEL_XOUT_L     0x3C
#define MPU6050_RA_ACCEL_YOUT_H     0x3D
#define MPU6050_RA_ACCEL_YOUT_L     0x3E
#define MPU6050_RA_ACCEL_ZOUT_H     0x3F
#define MPU6050_RA_ACCEL_ZOUT_L     0x40
#define MPU6050_RA_TEMP_OUT_H       0x41
#define MPU6050_RA_TEMP_OUT_L       0x42
#define MPU6050_RA_GYRO_XOUT_H      0x43
#define MPU6050_RA_GYRO_XOUT_L      0x44
#define MPU6050_RA_GYRO_YOUT_H      0x45
#define MPU6050_RA_GYRO_YOUT_L      0x46
#define MPU6050_RA_GYRO_ZOUT_H      0x47
#define MPU6050_RA_GYRO_ZOUT_L      0x48
#define MPU6050_RA_EXT_SENS_DATA_00 0x49
#define MPU6050_RA_EXT_SENS_DATA_01 0x4A
#define MPU6050_RA_EXT_SENS_DATA_02 0x4B
#define MPU6050_RA_EXT_SENS_DATA_03 0x4C
#define MPU6050_RA_EXT_SENS_DATA_04 0x4D
#define MPU6050_RA_EXT_SENS_DATA_05 0x4E
#define MPU6050_RA_EXT_SENS_DATA_06 0x4F
#define MPU6050_RA_EXT_SENS_DATA_07 0x50
#define MPU6050_RA_EXT_SENS_DATA_08 0x51
#define MPU6050_RA_EXT_SENS_DATA_09 0x52
#define MPU6050_RA_EXT_SENS_DATA_10 0x53
#define MPU6050_RA_EXT_SENS_DATA_11 0x54
#define MPU6050_RA_EXT_SENS_DATA_12 0x55
#define MPU6050_RA_EXT_SENS_DATA_13 0x56
#define MPU6050_RA_EXT_SENS_DATA_14 0x57
#define MPU6050_RA_EXT_SENS_DATA_15 0x58
#define MPU6050_RA_EXT_SENS_DATA_16 0x59
#define MPU6050_RA_EXT_SENS_DATA_17 0x5A
#define MPU6050_RA_EXT_SENS_DATA_18 0x5B
#define MPU6050_RA_EXT_SENS_DATA_19 0x5C
#define MPU6050_RA_EXT_SENS_DATA_20 0x5D
#define MPU6050_RA_EXT_SENS_DATA_21 0x5E
#define MPU6050_RA_EXT_SENS_DATA_22 0x5F
#define MPU6050_RA_EXT_SENS_DATA_23 0x60
#define MPU6050_RA_MOT_DETECT_STATUS    0x61
#define MPU6050_RA_I2C_SLV0_DO      0x63
#define MPU6050_RA_I2C_SLV1_DO      0x64
#define MPU6050_RA_I2C_SLV2_DO      0x65
#define MPU6050_RA_I2C_SLV3_DO      0x66
#define MPU6050_RA_I2C_MST_DELAY_CTRL   0x67
#define MPU6050_RA_SIGNAL_PATH_RESET    0x68
#define MPU6050_RA_MOT_DETECT_CTRL      0x69
#define MPU6050_RA_USER_CTRL        0x6A
#define MPU6050_RA_PWR_MGMT_1       0x6B	
#define MPU6050_RA_PWR_MGMT_2       0x6C
#define MPU6050_RA_BANK_SEL         0x6D
#define MPU6050_RA_MEM_START_ADDR   0x6E
#define MPU6050_RA_MEM_R_W          0x6F
#define MPU6050_RA_DMP_CFG_1        0x70
#define MPU6050_RA_DMP_CFG_2        0x71
#define MPU6050_RA_FIFO_COUNTH      0x72
#define MPU6050_RA_FIFO_COUNTL      0x73
#define MPU6050_RA_FIFO_R_W         0x74
#define MPU6050_RA_WHO_AM_I         0x75  


void MPU6050_Init(void);
void MPU6050_READ(s16* n);   
void MPU6050_Temp(u16* t);


#endif
