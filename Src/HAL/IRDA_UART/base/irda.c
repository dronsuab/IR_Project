/*
 * irda.c
 *
 *  Created on: 18 Nov 2017
 *      Author: APM137
 */

extern const tUartInstanceMap UARTInstanceMap[NUM_OF_UART];
uint32_t uartBufferSize[NUM_OF_UART];          		//Buffer Size
//UART_HandleTypeDef ST_UartHandlers[NUM_OF_UART];   //ST HAL handlers
IRDA_HandleTypeDef ST_UartHandlers[NUM_OF_UART];
IRDA_HandleTypeDef ST_UartHandlers[NUM_OF_UART];			//Handler IRDA
USART_HandleTypeDef ST_UartHandlers[NUM_OF_UART];

IRDA_HandleTypeDef *IrdaHandler;										//**********1*/
#if defined(MON_UART_RX_IT) || defined(MON_UART_TX_IT)
	//tUartContext uartCBuffers[NUM_OF_UART];
	eError uartStatus[NUM_OF_UART];
	static tUart uartPortIrq;
	uint8_t byteRxBuffer;
#endif

static HAL_StatusTypeDef IRDA_SetConfig(IRDA_HandleTypeDef *IrdaHandler)
 {
   uint32_t tmpreg                     = 0x00000000U;
   IRDA_ClockSourceTypeDef clocksource = IRDA_CLOCKSOURCE_UNDEFINED;
   HAL_StatusTypeDef ret               = HAL_OK;

   assert_param(IS_IRDA_BAUDRATE(IrdaHandler->Init.BaudRate));
   assert_param(IS_IRDA_WORD_LENGTH(IrdaHandler->Init.WordLength));
   ///assert_param(IS_IRDA_PARITY(hirda->IrdaHandler.Parity));
   assert_param(IS_IRDA_TX_RX_MODE(IrdaHandler->Init.Mode));
   assert_param(IS_IRDA_PRESCALER(IrdaHandler->Init.Prescaler));

   tmpreg = (uint32_t)IrdaHandler->Init.WordLength | IrdaHandler->Init.Parity | IrdaHandler->Init.Mode ;

   MODIFY_REG(IrdaHandler->Instance->CR1, IRDA_CR1_FIELDS, tmpreg);
   MODIFY_REG(IrdaHandler->Instance->CR3, USART_CR3_IRLP, IrdaHandler->Init.PowerMode);
   MODIFY_REG(IrdaHandler->Instance->GTPR, USART_GTPR_PSC, IrdaHandler->IrdaHandler.Prescaler);

   IRDA_GETCLOCKSOURCE(IrdaHandler, clocksource);
   switch (clocksource)
   {
	 case IRDA_CLOCKSOURCE_PCLK1:
		 IrdaHandler->Instance->BRR = (uint16_t)((HAL_RCC_GetPCLK1Freq() + (IrdaHandler->Init.BaudRate/2)) / IrdaHandler->Init.BaudRate);
	   break;
	 case IRDA_CLOCKSOURCE_HSI:
		 IrdaHandler->Instance->BRR = (uint16_t)((HSI_VALUE + (IrdaHandler->Init.BaudRate/2)) / IrdaHandler->Init.BaudRate);
	   break;
	 case IRDA_CLOCKSOURCE_SYSCLK:
		 IrdaHandler->Instance->BRR = (uint16_t)((HAL_RCC_GetSysClockFreq() + (IrdaHandler->Init.BaudRate/2)) / IrdaHandler->Init.BaudRate);
	   break;
	 case IRDA_CLOCKSOURCE_LSE:
		 IrdaHandler->Instance->BRR = (uint16_t)((LSE_VALUE  + (IrdaHandler->Init.BaudRate/2)) / IrdaHandler->Init.BaudRate);
	   break;
	 case IRDA_CLOCKSOURCE_UNDEFINED:
	 default:
	   ret = HAL_ERROR;
	   break;
   }
   return ret;
 }

HAL_StatusTypeDef HAL_IRDA_Init(IRDA_HandleTypeDef *IrdaHandler)
{
  if(IrdaHandler == NULL)
  {
    return HAL_ERROR;
  }

  assert_param(IS_IRDA_INSTANCE(IrdaHandler->Instance));
  if(IrdaHandler->gState == HAL_IRDA_STATE_RESET)
  {
	  IrdaHandler->Lock = HAL_UNLOCKED;
	  HAL_IRDA_MspInit(IrdaHandler);
  }

  IrdaHandler->gState = HAL_IRDA_STATE_BUSY;
  __HAL_IRDA_DISABLE(IrdaHandler);
  if (IRDA_SetConfig(IrdaHandler) == HAL_ERROR)
  {
    return HAL_ERROR;
  }

  CLEAR_BIT(IrdaHandler->Instance->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN | USART_CR2_STOP));
  CLEAR_BIT(IrdaHandler->Instance->CR3, (USART_CR3_SCEN | USART_CR3_HDSEL));


  IrdaHandler->Instance->CR3 |= USART_CR3_IREN;


  __HAL_IRDA_ENABLE(IrdaHandler);

  return (IRDA_CheckIdleState(IrdaHandler));
}

static HAL_StatusTypeDef IRDA_CheckIdleState(IRDA_HandleTypeDef *IrdaHandler)
 {
   uint32_t tickstart = 0U;
   IrdaHandler->ErrorCode = HAL_IRDA_ERROR_NONE;

   tickstart = HAL_GetTick();

 #if !defined(STM32F030x6) && !defined(STM32F030x8)&& !defined(STM32F070xB)&& !defined(STM32F070x6)&& !defined(STM32F030xC)
   if (IS_UART_WAKEUP_FROMSTOP_INSTANCE(IrdaHandler->Instance))
   {
     if((IrdaHandler->Instance->CR1 & USART_CR1_TE) == USART_CR1_TE)
     {
       if(IRDA_WaitOnFlagUntilTimeout(IrdaHandler, USART_ISR_TEACK, RESET, tickstart, IRDA_TEACK_REACK_TIMEOUT) != HAL_OK)
       {
         return HAL_TIMEOUT;
       }
     }

     if((IrdaHandler->Instance->CR1 & USART_CR1_RE) == USART_CR1_RE)
     {
       if(IRDA_WaitOnFlagUntilTimeout(IrdaHandler, USART_ISR_REACK, RESET, tickstart, IRDA_TEACK_REACK_TIMEOUT) != HAL_OK)
       {
         return HAL_TIMEOUT;
       }
     }
   }
 #endif

   IrdaHandler->gState  = HAL_IRDA_STATE_READY;
   IrdaHandler->RxState = HAL_IRDA_STATE_READY;
   __HAL_UNLOCK(IrdaHandler);

   return HAL_OK;
 }


static void irda_uart_init(IRDA_HandleTypeDef *IrdaHandler)
{
 	eError result = RET_FAIL;

 	if  (HAL_IRDA_Init(IrdaHandler) != HAL_ERROR)
 	{
 		result = RET_OK;
 	}

 	HAL_IRDA_MspInit(IrdaHandler);

 	if(IRDA_SetConfig(IrdaHandler) == HAL_OK)
 	{
 		result = RET_OK;
 	}

 	return result;
}

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

