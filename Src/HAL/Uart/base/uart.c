/*
 * uart.c
 *
 *  Created on: 20 oct. 2017
 *      Author: Iván
 */


#include "uart.h"
#include "common.h"


extern const tUartInstanceMap UARTInstanceMap[NUM_OF_UART];

uint32_t uartBufferSize[NUM_OF_UART];
USART_HandleTypeDef uartHandlers[NUM_OF_UART];
tUartContext uartCircularBuffers[NUM_OF_UART];
eError uartStatusList[NUM_OF_UART];
static tUart uartPortIrq;
uint8_t RxBufferbyte;

static eError uartReadIT(tUart uartPort, uint8_t* rdBuffer, uint32_t rdSize);
static eError uartWriteIT(tUart uartPort, uint8_t* buffer, uint32_t size);

void HAL_UART_MspInit(USART_HandleTypeDef *uart_handler)
{
    if(uart_handler->Instance == USART1){
        __HAL_RCC_USART1_CLK_ENABLE();
    }
    else if (uart_handler->Instance == USART2){
        __HAL_RCC_USART2_CLK_ENABLE();
    }

    /* Enable the UART Data Register not empty Interrupt. ALWAYS ENABLED */
    __HAL_USART_ENABLE_IT(uart_handler, USART_IT_RXNE);

}

void HAL_UART_TxCpltCallback(USART_HandleTypeDef *uart_handler)
{
	uint8_t byte;
	if ( GetQueuePendingBytes(&uartCircularBuffers[uartPortIrq].txBuffer) != 0)
	{
		 byte = (uint8_t)(GetQueueByte(&uartCircularBuffers[uartPortIrq].txBuffer) & (uint8_t)0xFF);
		 HAL_UART_Transmit_IT(&uartHandlers[uartPortIrq], &byte, 1);
	}
	else
	{
		 __HAL_UART_DISABLE_IT(&uartHandlers[uartPortIrq], USART_IT_TXE);
	}
}


void HAL_UART_RxCpltCallback(USART_HandleTypeDef *uart_handler)
{
	const tUartInstanceMap* uart_instance; //Montseny handler

	uart_instance = &UARTInstanceMap[uartPortIrq];

	//IF callback defined use it. Otherwise, default behaviour
	if(uart_instance->rxCallback != NULL){
		uart_instance->rxCallback(RxBufferbyte);
	}
	else{
		if(GetQueueFreeBytes(&uartCircularBuffers[uartPortIrq].rxBuffer) > 0){
			AddQueueByte(&uartCircularBuffers[uartPortIrq].rxBuffer, RxBufferbyte);
		}
		else{
			uartStatusList[uartPortIrq] = RET_BUFFER_FULL;
		}
	}

	 HAL_UART_Receive_IT(uart_handler, &RxBufferbyte, 1 );

}


void uartIRQHandler(tUart uartPort)
{
    USART_HandleTypeDef* uart_handler;

    uart_handler = &uartHandlers[uartPort];
    uartPortIrq = uartPort;
    HAL_USART_IRQHandler(uart_handler);
}


eError uartInit(void)
{
    eError result = RET_OK;
    USART_HandleTypeDef* uart_handler;
    const tUartInstanceMap* uart_instance;
    uint8_t i;

    for(i=0; i<NUM_OF_UART; i++) {
        uart_handler = &uartHandlers[i];
        uart_instance = &UARTInstanceMap[i];
        uart_handler->Instance        = uart_instance->port;
        uart_handler->Init.BaudRate   = uart_instance->baudRate;
        uart_handler->Init.WordLength = uart_instance->dataSize;
        uart_handler->Init.StopBits   = uart_instance->stopBits;
        uart_handler->Init.Parity     = uart_instance->parity;
        uart_handler->Init.Mode       = USART_MODE_TX_RX;
        //se pueden añadir los parámetros Init.CLKPolarity, Init.CLKPhase e Init.CLKLastBit

		CreateQueue(&uartCircularBuffers[i].rxBuffer,
                UARTInstanceMap[i].rxBufferPtr,
                UARTInstanceMap[i].rxBufferSize);

		CreateQueue(&uartCircularBuffers[i].txBuffer,
                UARTInstanceMap[i].txBufferPtr,
                UARTInstanceMap[i].txBufferSize);

    }

    return result;
}

/*************************************************************************//**
 * @brief  Stops UART driver.
 * @return  None.
 ****************************************************************************/
eError uartStop(void)
{
    eError result = RET_OK;
    uint8_t i;
    USART_HandleTypeDef* uart_handler;

    for(i=0; i<NUM_OF_UART; i++){
        uart_handler = &uartHandlers[i];
        if(HAL_USART_DeInit(uart_handler) != HAL_OK)
        {
            return RET_FAIL;
        }
    }

    return result;
}

/*************************************************************************//**
 * @brief  Starts UART driver.
 * @return  None.
 ****************************************************************************/
eError uartStart(void)
{
    eError result = RET_OK;
    uint8_t i;
    USART_HandleTypeDef* uart_handler;

    for(i=0; i<NUM_OF_UART; i++){
        uart_handler = &uartHandlers[i];
        if(HAL_USART_DeInit(uart_handler) != HAL_OK)
        {
            return RET_FAIL;
        }
        if(HAL_USART_Init(uart_handler) != HAL_OK)
        {
            return RET_FAIL;
        }
        HAL_USART_Receive_IT(uart_handler, &RxBufferbyte, 1 );
    }

    return result;
}

eError uartRead(tUart uartPort, uint8_t* buffer)
{
    eError result = RET_FAIL;
    uint32_t rdSize;

    rdSize = uartBufferSize[uartPort];

    return uartReadIT(uartPort, buffer, rdSize);
}

eError uartWrite(tUart uartPort, uint8_t* buffer)
{
    eError result = RET_OK;
    uint32_t bufferSize;

    bufferSize = uartBufferSize[uartPort];

    if(bufferSize == 0){
        return RET_INVALID_PARAMETER;
    }

    result = uartWriteIT(uartPort, buffer, bufferSize);

}

static eError uartReadIT(tUart uartPort, uint8_t* rdBuffer , uint32_t rdSize)
{
    eError result = RET_FAIL;
    uint32_t i;
    uint8_t byte;

    if(GetQueuePendingBytes(&uartCircularBuffers[uartPort].rxBuffer) < rdSize ){
        result =  RET_FAIL;
    }else{
        for(i=0; i<rdSize; i++){
            byte = GetQueueByte(&uartCircularBuffers[uartPort].rxBuffer);
            rdBuffer[i] = byte;
        }
        result = RET_OK;
    }

    return result;
}

static eError uartWriteIT(tUart uartPort, uint8_t* buffer, uint32_t size)
{
    eError result = RET_OK;
    uint32_t i;
    uint8_t byte = 0;

    if(GetQueueFreeBytes(&uartCircularBuffers[uartPort].txBuffer) < size){
        return RET_BUFFER_FULL;
    }

    for(i = 0; i < size; i++){
        AddQueueByte(&uartCircularBuffers[uartPort].txBuffer, buffer[i]);
    }

    if ( GetQueuePendingBytes(&uartCircularBuffers[uartPort].txBuffer) > 0)
    {
    	 /* send a empty buffer to enable Transmision and TXE */
    	 HAL_USART_Transmit_IT(&uartHandlers[uartPort], &byte, 1);
    }


    return result;
}

uint32_t uartGetBufferSize(tUart uartPort)
{
    return (GetQueuePendingBytes(&uartCircularBuffers[uartPort].rxBuffer));
}

eError uartSetBufferSize(tUart uartPort, uint32_t bufferSize )
{
    eError result = RET_OK;
    uartBufferSize[uartPort] = bufferSize;
    return result;
}
