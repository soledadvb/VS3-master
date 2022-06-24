/*
 * @Author: soledad
 * @Date: 2022-06-17 13:34:33
 * @LastEditors: soledad
 * @LastEditTime: 2022-06-18 16:49:20
 * @FilePath: \Project\BSP\bsp_led.h
 * @Description:
 *
 * Copyright (c) 2022 by LEAD Corp, All Rights Reserved.
 */

#ifndef __BSP_LED_H_
#define __BSP_LED_H_

#include "stm32f10x.h"

/* LED1 */
#define LED1_GPIO_PORT GPIOB
#define LED1_GPIO_CLK RCC_APB2Periph_GPIOB
#define LED1_GPIO_PIN GPIO_Pin_8

/* LEDA */
#define LEDA_GPIO_PORT GPIOB
#define LEDA_GPIO_CLK RCC_APB2Periph_GPIOB
#define LEDA_GPIO_PIN GPIO_Pin_14

/* LEDB */
#define LEDB_GPIO_PORT GPIOB
#define LEDB_GPIO_CLK RCC_APB2Periph_GPIOB
#define LEDB_GPIO_PIN GPIO_Pin_13

/* LEDC */
#define LEDC_GPIO_PORT GPIOB
#define LEDC_GPIO_CLK RCC_APB2Periph_GPIOB
#define LEDC_GPIO_PIN GPIO_Pin_12

#define ON 0
#define OFF 1

#define LED1(a)                                      \
    if (!a)                                          \
        GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN); \
    else                                             \
        GPIO_ResetBits(LED1_GPIO_PORT, LED1_GPIO_PIN)

#define LEDA(a)                                      \
    if (!a)                                          \
        GPIO_SetBits(LED1_GPIO_PORT, LEDA_GPIO_PIN); \
    else                                             \
        GPIO_ResetBits(LED1_GPIO_PORT, LEDA_GPIO_PIN)

#define LEDB(a)                                      \
    if (!a)                                          \
        GPIO_SetBits(LED1_GPIO_PORT, LEDB_GPIO_PIN); \
    else                                             \
        GPIO_ResetBits(LED1_GPIO_PORT, LEDB_GPIO_PIN)

#define LEDC(a)                                      \
    if (!a)                                          \
        GPIO_SetBits(LED1_GPIO_PORT, LEDC_GPIO_PIN); \
    else                                             \
        GPIO_ResetBits(LED1_GPIO_PORT, LEDC_GPIO_PIN)

/* 直接操作寄存器的方法控制IO */
#define digitalHi(p, i) \
    {                   \
        p->BSRR = i;    \
    } //输出为高电平
#define digitalLo(p, i) \
    {                   \
        p->BRR = i;     \
    } //输出低电平
#define digitalToggle(p, i) \
    {                       \
        p->ODR ^= i;        \
    } //输出反转状态

/* 定义控制IO的宏 */
#define LED1_TOGGLE digitalToggle(LED1_GPIO_PORT, LED1_GPIO_PIN)
#define LED1_OFF digitalHi(LED1_GPIO_PORT, LED1_GPIO_PIN)
#define LED1_ON digitalLo(LED1_GPIO_PORT, LED1_GPIO_PIN)

#define LEDA_TOGGLE digitalToggle(LEDA_GPIO_PORT, LEDA_GPIO_PIN)
#define LEDA_OFF digitalHi(LEDA_GPIO_PORT, LEDA_GPIO_PIN)
#define LEDA_ON digitalLo(LEDA_GPIO_PORT, LEDA_GPIO_PIN)

#define LEDB_TOGGLE digitalToggle(LEDB_GPIO_PORT, LEDB_GPIO_PIN)
#define LEDB_OFF digitalHi(LEDB_GPIO_PORT, LEDB_GPIO_PIN)
#define LEDB_ON digitalLo(LEDB_GPIO_PORT, LEDB_GPIO_PIN)

#define LEDC_TOGGLE digitalToggle(LEDC_GPIO_PORT, LEDC_GPIO_PIN)
#define LEDC_OFF digitalHi(LEDC_GPIO_PORT, LEDC_GPIO_PIN)
#define LEDC_ON digitalLo(LEDC_GPIO_PORT, LEDC_GPIO_PIN)

void LED_Config(void);

#endif
