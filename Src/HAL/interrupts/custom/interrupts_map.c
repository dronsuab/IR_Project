/*
 * interrupts_map.c
 *
 *  Created on: 29 oct. 2017
 *      Author: Iván
 */

#ifndef HAL_INTERRUPTS_CUSTOM_INTERRUPTS_MAP_C_
#define HAL_INTERRUPTS_CUSTOM_INTERRUPTS_MAP_C_


#include "common.h"
#include "interrupts.h"
#include "interrupts_map.h"


tInterruptsInstanceMap interruptsInstanceMap[NUM_OF_IRQS] =
{
		/* IRQ_SYSTICK		*/	{SysTick_IRQn		, 	TICK_INT_PRIORITY,	IRQ_SUBPRIORITY_0,		IRQ_ENABLE	},
		/* IRQ_USART1		*/	{USART1_IRQn		,	IRQ_PRIORITY_1	 ,	IRQ_SUBPRIORITY_0,		IRQ_ENABLE	},
		/* IRQ_USART2		*/	{USART2_IRQn		,	IRQ_PRIORITY_1	 ,	IRQ_SUBPRIORITY_0,		IRQ_ENABLE	},

};


void HAL_UART1_IRQ(void)
{
#ifdef IS_UART1
   uartDriverMainIRQHandler(UART_1);
#endif
}

void HAL_UART2_IRQ(void)
{
#ifdef IS_UART2
   uartIRQHandler(UART_2);
#endif
}


#endif /* HAL_INTERRUPTS_CUSTOM_INTERRUPTS_MAP_C_ */
