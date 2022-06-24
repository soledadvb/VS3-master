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
#include "mpu6050.h"

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    // SysTick_Init();
    LED_Config();
    USART_Config();
    USART3_DMA_Tx_Config();
    MPU6050_Init();
    if (MPU6050ReadID() == 0) /* 如果没有检测到 MPU6050 传感器 */
    {
        LED1_ON;
    }

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
