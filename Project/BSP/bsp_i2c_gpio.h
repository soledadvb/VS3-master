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
#ifndef __BSP_I2C_GPIO_H
#define __BSP_I2C_GPIO_H

#include "stm32f10x.h"

#define I2C_WR 0
#define I2C_RD 1

void i2c_Start(void);
void i2c_Stop(void);
void i2c_SendByte(uint8_t _ucByte);
uint8_t i2c_ReadByte(uint8_t ack);
uint8_t i2c_WaitAck(void);
void i2c_Ack(void);
void i2c_NAck(void);
uint8_t I2C_CheckDevice(uint8_t _Address);
void i2c_GPIO_Config(void);


#define I2CPORT GPIOB
#define I2C_SCL GPIO_Pin_6
#define I2C_SDA GPIO_Pin_7

#define SCLH GPIOB->BSRR = GPIO_Pin_6
#define SCLL GPIOB->BRR = GPIO_Pin_6

#define SDAH GPIOB->BSRR = GPIO_Pin_7
#define SDAL GPIOB->BRR = GPIO_Pin_7

#define SCLread GPIOB->IDR &GPIO_Pin_6
#define SDAread GPIOB->IDR &GPIO_Pin_7




#endif
