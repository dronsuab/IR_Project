/*
 * irda.c
 *
 *  Created on: Mar 21, 2018
 *      Author: FV4IYP0
 */

#include "irda.h"
#include "irda_map.h"
#include "common.h"

extern const sIrdaInstanceMap IRDAInstanceMap[NUM_OF_IRDA];
IRDA_HandleTypeDef irdaHandlers[NUM_OF_IRDA];
sIrdaContext irdaCircularBuffers[NUM_OF_IRDA];
uint8_t RxByte[10];
static eIrda irdaPortIRQ;
extern UART_HandleTypeDef uartHandlers[NUM_OF_UART];

void irdaInterruptHandler(eIrda irdaPort)
{
    IRDA_HandleTypeDef* irda_instance;
    irda_instance = &irdaHandlers[irdaPort];
    irdaPortIRQ = irdaPort;
    HAL_IRDA_IRQHandler(irda_instance);
}

void irdaInit(void)
{
    IRDA_HandleTypeDef* irda_handler;
    const sIrdaInstanceMap* irda_instance;
    uint8_t i;


	#ifdef IS_IRDA1
        __HAL_RCC_USART1_CLK_ENABLE();
	#endif


    for(i=0; i<NUM_OF_IRDA; i++) {
        irda_handler = &irdaHandlers[i];
        irda_instance = &IRDAInstanceMap[i];
        irda_handler->Instance        	= irda_instance->port;
        irda_handler->Init.BaudRate  	= irda_instance->baudRate;
        irda_handler->Init.WordLength 	= irda_instance->dataSize;
        irda_handler->Init.Mode   		= irda_instance->mode;
        irda_handler->Init.Parity    	= irda_instance->parity;
        irda_handler->Init.Prescaler    = irda_instance->prescaler;
        irda_handler->Init.PowerMode    = irda_instance->powermode;


        __HAL_IRDA_ENABLE_IT(irda_handler, IRDA_IT_RXNE);

//		CreateFIFO(&irdaCircularBuffers[i].rxBuffer,
//                IRDAInstanceMap[i].rxBufferPtr,
//                IRDAInstanceMap[i].rxBufferSize);
//
//		CreateFIFO(&irdaCircularBuffers[i].txBuffer,
//                IRDAInstanceMap[i].txBufferPtr,
//                IRDAInstanceMap[i].txBufferSize);
    }
}

HAL_StatusTypeDef irdaStop(void)
{
    uint8_t i;
    IRDA_HandleTypeDef* irda_handler;

    for(i=0; i<NUM_OF_IRDA; i++){
        irda_handler = &irdaHandlers[i];
        if(HAL_IRDA_DeInit(irda_handler) != HAL_OK)
        {
            return HAL_ERROR;
        }
    }

    return HAL_OK;
}

HAL_StatusTypeDef irdaStart(void)
{
    uint8_t i;
    IRDA_HandleTypeDef* irda_handler;
    for(i=0; i<NUM_OF_IRDA; i++){
        irda_handler = &irdaHandlers[i];
        if(HAL_IRDA_DeInit(irda_handler) != HAL_OK)
        {
            return HAL_ERROR;
        }
        if(HAL_IRDA_Init(irda_handler) != HAL_OK)
        {
            return HAL_ERROR;
        }
        HAL_IRDA_Receive_IT(irda_handler, (uint8_t *)irda1RxBuffer, 28 );
    }
    return HAL_OK;
}

HAL_StatusTypeDef irdaRead(eIrda irdaPort, char* buffer, uint8_t lastChar)
{
    uint32_t i=0;
    uint32_t bufferSize = 28;
    uint8_t result = HAL_ERROR;

    if(strlen(irda1RxBuffer) < bufferSize ){
		initString(buffer,bufferSize);
		result = HAL_ERROR;
    }else{
        while((irda1RxBuffer[i] != lastChar) && (i<30) )
        {
            buffer[i] = irda1RxBuffer[i];
            i++;
        }
        buffer[i] = irda1RxBuffer[i];
        if (irda1RxBuffer[i] == lastChar)
        	result = HAL_OK;
        initString(irda1RxBuffer,bufferSize);

    }

    return result;
}

HAL_StatusTypeDef irdaWrite(eIrda irdaPort, char* buffer)
{
    HAL_StatusTypeDef error;
    error = HAL_IRDA_Transmit_IT(&irdaHandlers[irdaPort], (uint8_t*)buffer, strlen(buffer));
    //HAL_Delay(10);
    return error;

}

void HAL_IRDA_RxCpltCallback(IRDA_HandleTypeDef *irda_handler)
{

//	if(strlen(irda1RxBuffer) == 10){
//		AddFIFOByte(&irdaCircularBuffers[irdaPortIRQ].rxBuffer, RxByte);
//	}
//

	HAL_IRDA_Receive_IT(irda_handler, (uint8_t *)irda1RxBuffer, 28 );


}

void HAL_IRDA_TxCpltCallback(IRDA_HandleTypeDef *irda_handler)
{
//	if (irdaPortIRQ == IRDA1)
//		HAL_HalfDuplex_EnableReceiver((UART_HandleTypeDef *)irda_handler);
}
