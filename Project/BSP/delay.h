/*
 * @Author: soledad
 * @Date: 2022-06-18 13:15:29
 * @LastEditors: soledad
 * @LastEditTime: 2022-06-23 14:45:54
 * @FilePath: \Project\BSP\delay.h
 * @Description:
 *
 * Copyright (c) 2022 by LEAD Corp, All Rights Reserved.
 */
#ifndef __DELAY_H
#define __DELAY_H

#include "stm32f10x.h"

void SysTick_Init(void);

void Delay_ms(__IO u32 nTime);
void Delay_us(__IO u32 nTime);

#endif
