/*
 * uart.h
 *
 *  Created on: 20 oct. 2017
 *      Author: Iv�n
 */

#ifndef HAL_UART_BASE_UART_H_
#define HAL_UART_BASE_UART_H_

#include "common.h"
#include "UART_map.h"
#include "CircularBuffer.h"


#define MAX_UART_BUFFER_SIZE    256


/**
 * Generic callback for a defined UART. It expects an uint8_t parameter
 * and returns eError.
 */
typedef eError (*uartRxCallback)(uint8_t);
typedef eError (*uartTxCallback)(uint8_t);

typedef struct
{
	CircularBuffer rxBuffer;
	CircularBuffer txBuffer;
} tUartContext;

typedef struct
{
    USART_TypeDef*  port;           /**< @brief ST HAL UART port structure */
    uint32_t        baudRate;       /**< @brief speed of the UART port */
    uint8_t         dataSize;       /**< @brief Word Length of the sent data */
    uint8_t         parity;         /**< @brief Activate or deactivate Parity */
    uint8_t         stopBits;       /**< @brief Activate or deactivate stop bits*/

    //Read/Write Buffers
    uint16_t        txBufferSize;   /**< @brief Size of the tx buffer */
    uint8_t*        txBufferPtr;    /**< @brief Pointer of the tx buffer */
    uint16_t        rxBufferSize;   /**< @brief Size of the tx buffer */
    uint8_t*        rxBufferPtr;    /**< @brief Pointer of the tx buffer */

    //DmaChannel      dmaChn; //PENDING TO BE DEFINED
    uint32_t*       dmaSrc;         /**< @brief Not implemented */
    uint8_t         dmaSrcLen;      /**< @brief Not implemented */
    uint8_t         dmaIrq;         /**< @brief Not implemented */

    //Callbacks
    uartRxCallback  rxCallback;     /**< @brief Callback for RX interruption */
    uartTxCallback  txCallback;     /**< @brief Callback for TX interruption */
} tUartInstanceMap;



eError uartInit(void);
eError uartStop(void);
eError uartStart(void);
eError uartSetBufferSize(eUart  uartPort, uint32_t bufferSize );
uint32_t uartGetBufferSize(eUart  uartPort);
eError uartWrite(eUart  uartPort, uint8_t* buffer);
eError uartRead(eUart  uartPort, uint8_t* buffer);

#endif // HAL_UART_BASE_UART_H_
