/*
 * irda_uart.c
 *
 *  Created on: 10 ene. 2018
 *      Author: APM137
 */

#include "irda_uart.h"
#include "stm32f0xx_hal.h"  /*ST HAL libraries*/
#include "stm32f0xx_hal_usart.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

IRDA_HandleTypeDef hirda1;
/*IRDA_HandleTypeDef hirda_1;							//1st Step*/
uint32_t uartBufferSize[NUM_OF_UART];          		//Buffer Size
//UART_HandleTypeDef ST_UartHandlers[NUM_OF_UART];   //ST HAL handlers
IRDA_HandleTypeDef ST_UartHandlers[NUM_OF_UART];
uint8_t RxBufferbyte;

static HAL_StatusTypeDef IRDA_Transmit_IT(IRDA_HandleTypeDef *IrdaHandler)
{
  uint16_t* tmp;

  if(IrdaHandler->gState == HAL_IRDA_STATE_BUSY_TX)
  {
    if(IrdaHandler->TxXferCount == 0U)
    {
      CLEAR_BIT(IrdaHandler->Instance->CR1, USART_CR1_TXEIE);
      SET_BIT(IrdaHandler->Instance->CR1, USART_CR1_TCIE);
      return HAL_OK;
    }
    else
    {
      if ((IrdaHandler->Init.WordLength == IRDA_WORDLENGTH_9B) && (IrdaHandler->Init.Parity == IRDA_PARITY_NONE))
      {
        tmp = (uint16_t*) IrdaHandler->pTxBuffPtr;
        IrdaHandler->Instance->TDR = (*tmp & (uint16_t)0x01FFU);
        IrdaHandler->pTxBuffPtr += 2U;
      }
      else
      {
    	  IrdaHandler->Instance->TDR = (uint8_t)(*IrdaHandler->pTxBuffPtr++ & (uint8_t)0xFFU);
      }
      IrdaHandler->TxXferCount--;

      return HAL_OK;
    }
  }
  else
  {
    return HAL_BUSY;
  }
}

HAL_StatusTypeDef irda_test1(IRDA_HandleTypeDef *IrdaHandler)
{
   uint8_t Cmd[] = {0x80};
   uint8_t ret[10];
   uint16_t BuffSize = 10;
	HAL_StatusTypeDef ver;

   //result=IRDA_Transmit_IT(&hirda_1);

	memset(ret,0x0,5);

	ver=HAL_IRDA_Transmit(&hirda1,(uint8_t *) Cmd,1,0xFFFF);
	//retval = HAL_IRDA_Receive(&hirda_1,ret,1,1000);				// ESTO DE MOMENTO NO LO IMPLEMENTO(ES LA RECEPCIÓN)

	return ver;

}

HAL_StatusTypeDef irda_test2(IRDA_HandleTypeDef *IrdaHandler)
{
   uint8_t Cmd[] = {0x80};
   uint8_t ret[10];
   uint16_t BuffSize = 10;
   HAL_StatusTypeDef ver;

	memset(ret,0x0,5);

	ver = HAL_IRDA_Transmit_IT(&hirda1,ret,BuffSize);

	return ver;
}

HAL_StatusTypeDef irda_test3(IRDA_HandleTypeDef *IrdaHandler)
{
   uint8_t Cmd[] = {0x80};
   uint8_t ret[10];
   uint16_t BuffSize = 10;
   HAL_StatusTypeDef ver;

	memset(ret,0x0,5);

	ver = IRDA_Transmit_IT(&hirda1);

	return ver;
}

void IrdaStart(void)
{
    //HAL_IRDA_DeInit(&hirda_1);
	HAL_StatusTypeDef check;

	check=init_irda();

	/*IRDA_SetConfig(&hirda_1);*/
    //HAL_IRDA_Init(&hirda_1);

}
/*
HAL_StatusTypeDef initt_irda(void)
{

	HAL_StatusTypeDef val = HAL_OK;
	#ifdef IS_UART1
	  __HAL_RCC_USART1_CLK_ENABLE();
	#endif

	hirda_1.Instance = USART1;
	hirda_1.Init.BaudRate = 115200;
	hirda_1.Init.PowerMode = IRDA_POWERMODE_LOWPOWER;
	hirda_1.Init.Parity = IRDA_PARITY_NONE;
	hirda_1.Init.Prescaler = 1;
	hirda_1.Init.Mode = IRDA_MODE_TX_RX;
	hirda_1.Init.WordLength = IRDA_WORDLENGTH_8B;

	if ( HAL_IRDA_Init(&hirda_1) == HAL_OK ) {
		//printf("HAL IRDA INIT ERROR\n");
		val= HAL_OK;
	}else{
		val= HAL_ERROR;
	}
 return val;
}
*/








