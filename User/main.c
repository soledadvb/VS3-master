/*
 * @Author: soledad
 * @Date: 2022-06-17 10:34:50
 * @LastEditors: soledad
 * @LastEditTime: 2022-06-24 11:19:01
 * @FilePath: \Projectc:\Users\LD\Desktop\VS3-master\User\main.c
 * @Description:
 *
 * Copyright (c) 2022 by LEAD Corp, All Rights Reserved.
 */

#include "bsp.h"

int main(void)
{
    // SysTick_Init();
    LED_Config();
    USART_Config();
    USART3_DMA_Tx_Config();
    // TODO I2C_Config();
    // TODO FLASH_Config();

    Delay_ms(2000);
    USART_DMACmd(USART3, USART_DMAReq_Tx, ENABLE);
    for (;;)
    {

        LEDA_TOGGLE;
        Delay_ms(500);
        LEDB_TOGGLE;
        Delay_ms(500);
        LEDC_TOGGLE;
        Delay_ms(500);
        Usart_SendString(USART3, "AAAAAA");
    }
}
