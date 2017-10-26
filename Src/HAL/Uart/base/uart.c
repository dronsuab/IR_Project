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
uint8_t RxBufferbyte;


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

		CreateFIFO(&uartCircularBuffers[i].rxBuffer,
                UARTInstanceMap[i].rxBufferPtr,
                UARTInstanceMap[i].rxBufferSize);

		CreateFIFO(&uartCircularBuffers[i].txBuffer,
                UARTInstanceMap[i].txBufferPtr,
                UARTInstanceMap[i].txBufferSize);

    }

    return result;
}

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

eError uartRead(eUart uartPort, uint8_t* buffer)
{
    eError result = RET_FAIL;
    uint32_t i;
    uint8_t byte;
    uint32_t bufferSize;

    bufferSize = uartBufferSize[uartPort];

    if(GetFIFOPendingBytes(&uartCircularBuffers[uartPort].rxBuffer) < bufferSize ){
        result =  RET_FAIL;
    }else{
        for(i=0; i<bufferSize; i++){
            byte = GetFIFOByte(&uartCircularBuffers[uartPort].rxBuffer);
            buffer[i] = byte;
        }
        result = RET_OK;
    }
    return result;
}

eError uartWrite(eUart uartPort, uint8_t* buffer)
{
    eError result = RET_OK;
    uint32_t i;
    uint8_t byte = 0;
    uint32_t bufferSize;

    bufferSize = uartBufferSize[uartPort];

    if(bufferSize == 0){
        return RET_INVALID_PARAMETER;
    }

    if(GetFIFOFreeBytes(&uartCircularBuffers[uartPort].txBuffer) < bufferSize){
	   return RET_BUFFER_FULL;
   }

   for(i = 0; i < bufferSize; i++){
	   AddFIFOByte(&uartCircularBuffers[uartPort].txBuffer, buffer[i]);
   }

   if ( GetFIFOPendingBytes(&uartCircularBuffers[uartPort].txBuffer) > 0)
   {
	 HAL_USART_Transmit_IT(&uartHandlers[uartPort], &byte, 1);
   }

   return result;

}

uint32_t uartGetBufferSize(eUart uartPort)
{
	uint16_t bufferSize = (GetFIFOPendingBytes(&uartCircularBuffers[uartPort].rxBuffer));
    return bufferSize;
}

eError uartSetBufferSize(eUart uartPort, uint32_t bufferSize )
{
    eError result = RET_OK;
    uartBufferSize[uartPort] = bufferSize;
    return result;
}

