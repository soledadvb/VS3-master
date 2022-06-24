/*
 * @Author: soledad
 * @Date: 2022-06-17 10:46:55
 * @LastEditors: soledad
 * @LastEditTime: 2022-06-23 11:16:31
 * @FilePath: \Project\BSP\bsp_uart_dma.h
 * @Description:
 *
 * Copyright (c) 2022 by LEAD Corp, All Rights Reserved.
 */
#ifndef __BSP_UART_H_
#define __BSP_UART_H_

#include <stm32f10x.h>
#include <stdio.h>

// 串口工作参数宏定义
#define USART1_Tx_Pin GPIO_Pin_9
#define USART1_Rx_Pin GPIO_Pin_10

#define RS485_USART USART2
#define RS485_Tx_Pin GPIO_Pin_2
#define RS485_Rx_Pin GPIO_Pin_3
#define RS485_EN_GPIO_PORT GPIOA
#define RS485_EN_Pin GPIO_Pin_1

#define USART3_Tx_Pin GPIO_Pin_10
#define USART3_Rx_Pin GPIO_Pin_11

#define USARTx_DMAx_TX_CHANNEL DMA1_Channel2
#define USARTx_DMAx_TX_IRQn DMA1_Channel2_IRQn
#define USARTx_DMAx_TX_IRQHandler DMA1_Channel2_IRQHandler

#define USARTx_DMAx_RX_CHANNEL DMA1_Channel3
#define USARTx_DMAx_RX_IRQn DMA1_Channel3_IRQn
#define USARTx_DMAx_RX_IRQHandler DMA1_Channel3_IRQHandler // 外设寄存器地址

// 一次DMA传输的最大字节数
#define BUFF_SIZE 1024

extern uint8_t SendBuff[BUFF_SIZE];
extern uint8_t ReceiveBuff[BUFF_SIZE];

void USART1_Config(void);
void RS485_Config(void);
void USART3_Config(void);
void Usart_SendByte(USART_TypeDef *pUSARTx, uint8_t ch);
void Usart_SendArray(USART_TypeDef *pUSARTx, uint8_t *array, uint16_t num);
void Usart_SendString(USART_TypeDef *pUSARTx, char *str);
void Usart_SendHalfWord(USART_TypeDef *pUSARTx, uint16_t ch);
void USARTx_DMA_Config(void);
void USART_Config(void);
void Usart_Send(USART_TypeDef *pUSARTx, u8 *buf, u16 len);

void USART3_DMA_Tx_Config(void);

#endif
