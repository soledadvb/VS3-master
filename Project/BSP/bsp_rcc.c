/*
 * @Author: soledad
 * @Date: 2022-06-22 16:02:34
 * @LastEditors: soledad
 * @LastEditTime: 2022-06-23 08:36:15
 * @FilePath: \Project\bsp_rcc.c
 * @Description:
 *
 * Copyright (c) 2022 by LEAD Corp, All Rights Reserved.
 */
#include "bsp_rcc.h"

void HSE_SetSysClock(u32 pllmul)
{
    __IO u32 StartUpCounter = 0, HSEStartUpStatus = 0;

    // ��RCC�����ʼ���ɸ�λ״̬
    RCC_DeInit();

    // ʹ��HSE, �����ⲿ����, VS300ʹ�õ���6M
    RCC_HSEConfig(RCC_HSE_ON);

    // �ȴ� HSE �����ȶ�
    HSEStartUpStatus = RCC_WaitForHSEStartUp();

    if (HSEStartUpStatus == SUCCESS)
    {
        FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
        FLASH_SetLatency(FLASH_Latency_2);
        RCC_HCLKConfig(RCC_SYSCLK_Div1);
        RCC_PCLK2Config(RCC_HCLK_Div1);
        RCC_PCLK1Config(RCC_HCLK_Div2);
        RCC_PLLConfig(RCC_PLLSource_HSE_Div1, pllmul);
        RCC_PLLCmd(ENABLE);
        while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
            ;
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

        while (RCC_GetSYSCLKSource() != 0x08)
            ;
    }
    else
    {
        while (1)
            ;
    }
}

void HSI_SetSysClock(u32 pllmul)
{
    __IO u32 HSIStartUpStatus = 0;
    // �� RCC �����ʼ���ɸ�λ״̬
    RCC_DeInit();

    // ʹ�� HSI
    HSIStartUpStatus = RCC_CR_HSIRDY;

    // ֻ�� HSI ����֮�����������ִ��
    if (HSIStartUpStatus == RCC_CR_HSIRDY)
    {
        FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
        FLASH_SetLatency(FLASH_Latency_2);
        RCC_HCLKConfig(RCC_HCLK_Div1);
        RCC_PCLK2Config(RCC_HCLK_Div1);
        RCC_PCLK1Config(RCC_HCLK_Div2);
        RCC_PLLConfig(RCC_PLLSource_HSI_Div2, pllmul);
        RCC_PLLCmd(ENABLE);
        while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
            ;
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
        while (RCC_GetSYSCLKSource() != 0x08)
            ;
    }
    else
    {
        while (1)
            ;
    }
}
