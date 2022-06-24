/*
 * @Author: soledad
 * @Date: 2022-06-17 10:46:04
 * @LastEditors: soledad
 * @LastEditTime: 2022-06-24 11:39:03
 * @FilePath: \Project\BSP\delay.c
 * @Description:
 *
 * Copyright (c) 2022 by LEAD Corp, All Rights Reserved.
 */
#include "delay.h"

static __IO u32 TimingDelay;

void SysTick_Init(void)
{

	/* SystemFrequency / 1000 1ms 中断一次
	 * 	SystemFrequency / 100000 10us 中断一次
	 * 	SystemFrequency / 1000000 1us 中断一次
	 */
	if (SysTick_Config(SystemCoreClock / 1000))
		while (1)
			;
}

void Delay_us(uint32_t us)
{
	uint32_t i;
	SysTick_Config(SystemCoreClock / 1000000);

	for (i = 0; i < us; i++)
	{
		while (!((SysTick->CTRL) & (1 << 16)))
			;
	}

	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

void Delay_ms(uint32_t ms)
{
	uint32_t i;
	SysTick_Config(SystemCoreClock / 1000);

	for (i = 0; i < ms; i++)
	{
		while (!((SysTick->CTRL) & (1 << 16)))
			;
	}

	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}
