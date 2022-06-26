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
#include "stm32f10x_it.h"

/* MPU6050数据 */
short Accel[3];
short Gyro[3];
float Temp;

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    // SysTick_Init();
    LED_Config();
    USART_Config();
    USART3_DMA_Tx_Config();
    i2c_GPIO_Config();
    MPU6050_Init();
    if (MPU6050ReadID() == 0) /* 如果没有检测到 MPU6050 传感器 */
        LED1_ON;
    USART_DMACmd(USART3, USART_DMAReq_Tx, ENABLE);
    for (;;)
    {
        if (task_readdata_finish)
        {
            printf("\r\n加速度： %8d%8d%8d    ", Accel[0], Accel[1], Accel[2]);
            printf("陀螺仪： %8d%8d%8d    ", Gyro[0], Gyro[1], Gyro[2]);
            printf("温度： %8.2f", Temp);
            printf("测试: %d ",1);
        }
    }
}
