/*
 * irda_uart_map.h
 *
 *  Created on: 20 ene. 2018
 *      Author: APM137
 */

#include "stm32f0xx_hal.h"  				/*PONERLOS EN UN ARCHIVO*/
#include "stm32_hal_legacy.h"
#include "stm32f051x8.h"

#ifndef HAL_IRDA_CUSTOM_IRDA_UART_MAP_H_
#define HAL_IRDA_CUSTOM_IRDA_UART_MAP_H_

#define MON_UART_TX_IT
	#define MON_UART_RX_IT

	#define UART_TX_BUFFER 100

	#define IS_UART1                 //Necesitamos este para el IRDA
	#define IS_UART2


	#ifdef IS_UART1
		#define UART1_TX_BUFFER          256
	#endif
	#ifdef IS_UART1
		#define UART2_TX_BUFFER          256
	#endif


	#ifdef IS_UART1
		#define UART1_RX_BUFFER          100
	#endif
	#ifdef IS_UART2
		#define UART2_RX_BUFFER          100
	#endif


	typedef enum eUart
	{
		UART_INIT = -1,

		#ifdef IS_UART1
			UART_1,
		#endif

		#ifdef IS_UART2
			UART_2,
		#endif
		NUM_OF_UART
	} tUart;

	/***********************************************************************
	 * PUBLIC FUCNTION PROTOTYPES
	 **********************************************************************/
	//void handleOREIRQ(UART_HandleTypeDef* huart);												//SE PUEDE QUITAR?
	#define MAX_UART_BUFFER_SIZE    256
	//static HAL_StatusTypeDef irda_test();

#endif /* HAL_IRDA_CUSTOM_IRDA_UART_MAP_H_ */
