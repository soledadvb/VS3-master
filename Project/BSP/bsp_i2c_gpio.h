/*
 * @Author: soledad
 * @Date: 2022-06-17 10:46:55
 * @LastEditors: soledad
 * @LastEditTime: 2022-06-18 14:45:03
 * @FilePath: \Project\BSP\bsp_i2c.h
 * @Description:
 *
 * Copyright (c) 2022 by LEAD Corp, All Rights Reserved.
 */
#ifndef __I2C_H_
#define __I2C_H_

#include "stm32f10x.h"

#define I2CPORT GPIOB
#define I2C_SCL GPIO_Pin_6
#define I2C_SDA GPIO_Pin_7

#define SCLH GPIOB->BSRR = GPIO_Pin_6
#define SCLL GPIOB->BRR = GPIO_Pin_6

#define SDAH GPIOB->BSRR = GPIO_Pin_7
#define SDAL GPIOB->BRR = GPIO_Pin_7

#define SCLread GPIOB->IDR &GPIO_Pin_6
#define SDAread GPIOB->IDR &GPIO_Pin_7

#define HostAddress 0xC0 //总线主机的器件地址
#define BusSpeed 300000  //总线速度（不高于400000）

void MPU6050_READ(s16 *Data);
void I2C_Configuration(void);
void I2C_SEND_BUFFER(u8 SlaveAddr, u8 WriteAddr, u8 *pBuffer, u16 NumByteToWrite);
void I2C_SEND_BYTE(u8 SlaveAddr, u8 writeAddr, u8 pBuffer);
void I2C_READ_BUFFER(u8 SlaveAddr, u8 readAddr, u8 *pBuffer, u16 NumByteToRead);
u8 I2C_READ_BYTE(u8 SlaveAddr, u8 readAddr);

#endif
