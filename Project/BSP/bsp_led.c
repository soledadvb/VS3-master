/*
 * @Author: soledad
 * @Date: 2022-06-17 13:34:33
 * @LastEditors: soledad
 * @LastEditTime: 2022-06-22 14:01:03
 * @FilePath: \Project\BSP\bsp_led.c
 * @Description:
 *
 * Copyright (c) 2022 by LEAD Corp, All Rights Reserved.
 */

#include "bsp_led.h"

void LED_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(LED1_GPIO_CLK | LEDA_GPIO_CLK | LEDB_GPIO_CLK | LEDC_GPIO_CLK, ENABLE);

    GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LEDA_GPIO_PIN;
    GPIO_Init(LEDA_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LEDB_GPIO_PIN;
    GPIO_Init(LEDB_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LEDC_GPIO_PIN;
    GPIO_Init(LEDC_GPIO_PORT, &GPIO_InitStructure);

    /* πÿ±’À˘”–LEDµ∆ */
    GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
    GPIO_SetBits(LEDA_GPIO_PORT, LEDA_GPIO_PIN);
    GPIO_SetBits(LEDB_GPIO_PORT, LEDB_GPIO_PIN);
    GPIO_SetBits(LEDC_GPIO_PORT, LEDC_GPIO_PIN);
}
