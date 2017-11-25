/*
 * irda.h
 *
 *  Created on: 18 Nov 2017
 *      Author: APM137
 */

#ifndef HAL_IRDA_UART_BASE_IRDA_H_
#define HAL_IRDA_UART_BASE_IRDA_H_

	typedef struct
	{
		uint32_t BaudRate;
		uint32_t WordLength;
		uint32_t Parity;
		uint32_t Mode;
		uint8_t  Prescaler;
		uint16_t PowerMode;

	} tIrdaUartInstanceMap;


	void irda_uart_init(IRDA_HandleTypeDef *IrdaHandler);
	static HAL_StatusTypeDef IRDA_SetConfig(IRDA_HandleTypeDef *IrdaHandler);
	HAL_StatusTypeDef HAL_IRDA_Init(IRDA_HandleTypeDef *IrdaHandler);
	static HAL_StatusTypeDef IRDA_CheckIdleState(IRDA_HandleTypeDef *IrdaHandler);

#endif /* HAL_IRDA_UART_BASE_IRDA_H_ */
