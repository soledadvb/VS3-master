/*
 * @Author: soledad
 * @Date: 2022-06-22 16:02:45
 * @LastEditors: soledad
 * @LastEditTime: 2022-06-22 16:17:14
 * @FilePath: \Project\bsp_rcc.h
 * @Description:
 *
 * Copyright (c) 2022 by LEAD Corp, All Rights Reserved.
 */
#ifndef __BSP_RCC_H
#define __BSP_RCC_H
#include "stm32f10x.h"
#include "stdio.h"

void HSE_SetSysClock(u32 pllmul);

#endif /* bsp_rcc.h */
