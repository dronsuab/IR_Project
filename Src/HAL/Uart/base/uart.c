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
uint8_t RxBufferbyte;


void uartInterruptHandler(eUart uartPort)
{
    USART_HandleTypeDef* uart_instance; //HAL Uart
    //en caso de usar las callbacks, revisar el código de MTG
    uart_instance = &uartHandlers[uartPort];
    HAL_USART_IRQHandler(uart_instance);
}


void uartInit(void)
{
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

		CreateFIFO(&uartCircularBuffers[i].rxBuffer,
                UARTInstanceMap[i].rxBufferPtr,
                UARTInstanceMap[i].rxBufferSize);

		CreateFIFO(&uartCircularBuffers[i].txBuffer,
                UARTInstanceMap[i].txBufferPtr,
                UARTInstanceMap[i].txBufferSize);

    }
}

HAL_StatusTypeDef uartStop(void)
{
    uint8_t i;
    USART_HandleTypeDef* uart_handler;

    for(i=0; i<NUM_OF_UART; i++){
        uart_handler = &uartHandlers[i];
        if(HAL_USART_DeInit(uart_handler) != HAL_OK)
        {
            return HAL_ERROR;
        }
    }

    return HAL_OK;
}

HAL_StatusTypeDef uartStart(void)
{
    uint8_t i;
    USART_HandleTypeDef* uart_handler;

    for(i=0; i<NUM_OF_UART; i++){
        uart_handler = &uartHandlers[i];
        if(HAL_USART_DeInit(uart_handler) != HAL_OK)
        {
            return HAL_ERROR;
        }
        if(HAL_USART_Init(uart_handler) != HAL_OK)
        {
            return HAL_ERROR;
        }
        HAL_USART_Receive_IT(uart_handler, &RxBufferbyte, 1 );
    }
    return HAL_OK;
}

HAL_StatusTypeDef uartRead(eUart uartPort, uint8_t* buffer)
{
    uint32_t i;
    uint8_t byte;
    uint32_t bufferSize;

    bufferSize = UARTInstanceMap[uartPort].txBufferSize;

    if(GetFIFOPendingBytes(&uartCircularBuffers[uartPort].rxBuffer) < bufferSize ){
        return HAL_ERROR;
    }else{
        for(i=0; i<bufferSize; i++){
            byte = GetFIFOByte(&uartCircularBuffers[uartPort].rxBuffer);
            buffer[i] = byte;
        }
    }
    return HAL_OK;
}

HAL_StatusTypeDef uartWrite(eUart uartPort, uint8_t* buffer)
{
    uint32_t i;
    uint8_t byte = 0;
    uint32_t bufferSize;

    bufferSize = 50;

    if(bufferSize != 0){

		if(GetFIFOFreeBytes(&uartCircularBuffers[uartPort].txBuffer) > bufferSize){

			for(i = 0; i < bufferSize; i++){
				AddFIFOByte(&uartCircularBuffers[uartPort].txBuffer, buffer[i]);
			}

		    if ( GetFIFOPendingBytes(&uartCircularBuffers[uartPort].txBuffer) > 0)
		    {
			 HAL_USART_Transmit_IT(&uartHandlers[uartPort], &byte, 1);
			 return HAL_OK;
		    }
		    else
		    	return HAL_ERROR;
		}
		else
			return HAL_ERROR;
    }
    else
    	return HAL_ERROR;
}

uint32_t uartGetBufferSize(eUart uartPort)
{
	uint16_t bufferSize = (GetFIFOPendingBytes(&uartCircularBuffers[uartPort].rxBuffer));
    return bufferSize;
}

void uartSetBufferSize(eUart uartPort, uint32_t bufferSize )
{
    uartBufferSize[uartPort] = bufferSize;
}

