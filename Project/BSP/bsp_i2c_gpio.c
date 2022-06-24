/*
 * @Author: soledad
 * @Date: 2022-06-17 10:45:40
 * @LastEditors: soledad
 * @LastEditTime: 2022-06-24 11:04:34
 * @FilePath: \Project\BSP\bsp_i2c_gpio.c
 * @Description:
 *
 * Copyright (c) 2022 by LEAD Corp, All Rights Reserved.
 */
#include "bsp_i2c_gpio.h"

#define GPIO_PORT_I2C GPIOB
#define RCC_I2C_PORT RCC_APB2Periph_GPIOA
#define I2C_SCL_PIN GPIO_Pin_8
#define I2C_SDA_PIN GPIO_Pin_7

#define I2C_SCL_1() GPIO_PORT_I2C->BSRR = I2C_SCL_PIN
#define I2C_SCL_0() GPIO_PORT_I2C->BRR = I2C_SCL_PIN

#define I2C_SDA_1() GPIO_PORT_I2C->BSRR = I2C_SDA_PIN
#define I2C_SDA_0() GPIO_PORT_I2C->BRR = I2C_SDA_PIN

#define I2C_SDA_READ() ((GPIO_PORT_I2C->IDR & I2C_SDA_PIN) != 0) /* 读SDA口线状态 */
#define I2C_SCL_READ() ((GPIO_PORT_I2C->IDR & I2C_SCL_PIN) != 0) /* 读SCL口线状态 */

void i2c_GPIO_Config(void);

static void i2c_Delay(void)
{
    u8 i;
    for (i = 0; i < 10; i++)
        ;
}

void i2c_Start(void)
{
    I2C_SDA_1();
    I2C_SCL_1();
    i2c_Delay();
    I2C_SDA_0();
    i2c_Delay();
    I2C_SCL_0();
    i2c_Delay();
}

void i2c_Stop(void)
{
    I2C_SDA_0();
    I2C_SCL_1();
    i2c_Delay();
    I2C_SDA_1();
}
/**
 * @description: 发送数据
 * @param {uint8_t} _ucByte
 * @return {*}
 */
void i2c_SendByte(uint8_t _ucByte)
{
    uint8_t i;
    /* 先发送字节的高位 bit7 */
    for (i = 0; i < 8; i++)
    {
        if (_ucByte & 0X80)
        {
            I2C_SDA_1();
        }
        else
        {
            I2C_SDA_0();
        }
        i2c_Delay();
        I2C_SCL_1();
        i2c_Delay();
        I2C_SCL_0();
        if (i == 7)
        {
            I2C_SDA_1();
        }
        _ucByte <<= 1;
        i2c_Delay();
    }
}

uint8_t i2c_ReadByte(u8 ack)
{
    uint8_t i;
    uint8_t value;

    /* 读到第一个bit为数据的bit7 */
    value = 0;
    for (i = 0; i < 8; i++)
    {
        value <<= 1;
        I2C_SCL_1();
        i2c_Delay();
        if (I2C_SDA_READ())
        {
            value++;
        }
        I2C_SCL_0();
        i2c_Delay();
    }
    if(ack==0)
        i2c_NAck();
    else
        i2c_Ack();
    return value;
}

uint8_t i2c_WaitAck(void)
{
    uint8_t re;

    I2C_SDA_1();
    i2c_Delay();
    I2C_SCL_1();
    i2c_Delay();
    if(I2C_SDA_READ())
    {
        re = 1;
    }
    else
    {
        re = 0;
    }
    I2C_SCL_0();
    i2c_Delay();
    return re;
}

void i2c_Ack(void)
{
    I2C_SDA_0();
    i2c_Delay();
    I2C_SCL_1();
    i2c_Delay();
    I2C_SCL_0();
    i2c_Delay();
    I2C_SDA_1();
}

void i2c_NAck()
{
    I2C_SDA_1();
    i2c_Delay();
    I2C_SCL_1();
    i2c_Delay();
    I2C_SCL_0();
    i2c_Delay();
}

void i2c_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_I2C_PORT, ENABLE);
    GPIO_InitStructure.GPIO_Pin = I2C_SCL_PIN|I2C_SDA_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIO_Init(GPIO_PORT_I2C, &GPIO_InitStructure);

    i2c_Stop();
}

uint8_t I2C_CheckDevice( uint8_t _Address) 
{
    uint8_t ucAck;
    i2c_GPIO_Config();
    i2c_Start();

    i2c_SendByte(_Address|I2C_WR);
    ucAck = i2c_WaitAck();

    i2c_Stop();

    return ucAck;
}


