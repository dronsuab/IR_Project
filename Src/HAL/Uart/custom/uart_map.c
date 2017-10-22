/*
 * uart_map.c
 *
 *  Created on: 20 oct. 2017
 *      Author: Iván
 */


#include "common.h"

/***********************************************************************
 * COMMON ARCHITECTURE INCLUDES
 **********************************************************************/
//#include "PipeDevice.h" //For the Pipe Helpers

/***********************************************************************
 * INCLUDES
 **********************************************************************/
#include "UART.h"
#include "UART_map.h"

extern eError testRxCallback(uint8_t c);
extern eError testTxCallback(uint8_t c);

#ifdef IS_UART1
    uint8_t usart1TxBuffer[USART1_TX_BUFFER];
    uint8_t usart1RxBuffer[USART1_RX_BUFFER];
#endif
#ifdef IS_UART2
    uint8_t usart2TxBuffer[USART2_TX_BUFFER];
    uint8_t usart2RxBuffer[USART2_RX_BUFFER];
#endif
#ifdef IS_UART3
    uint8_t usart3TxBuffer[USART3_TX_BUFFER];
    uint8_t usart3RxBuffer[USART3_RX_BUFFER];
#endif
#ifdef IS_UART4
    uint8_t usart4TxBuffer[USART4_TX_BUFFER];
    uint8_t usart4RxBuffer[USART4_RX_BUFFER];
#endif
#ifdef IS_UART5
    uint8_t usart5TxBuffer[USART5_TX_BUFFER];
    uint8_t usart5RxBuffer[USART5_RX_BUFFER];
#endif
#ifdef IS_UART6
    uint8_t usart6TxBuffer[USART6_TX_BUFFER];
    uint8_t usart6RxBuffer[USART6_RX_BUFFER];
#endif

const tUartInstanceMap UARTInstanceMap[NUM_OF_UART] =  {
/*
    {
        port                USART_TypeDef
        baudRate            uint32_t
        dataSize            uint8_t
        parity              uint8_t
        stopBits            uint8_t
        txBufferSize        uint16_t
        txBufferPtr         uint8_t*
        rxBufferSize        uint16_t
        rxBufferPtr         uint8_t*
        dmaChn              //DmaChannel
        dmaSrc              uint32_t*
        dmaSrcLen           uint8_t
        dmaIrq              uint8_t
        rxCallback          uartRxCallback
        txCallback          uartTxCallback
    }
*/
#ifdef IS_UART1
    {
        USART1,
        115200,
        USART_WORDLENGTH_8B,
        USART_PARITY_NONE,
        USART_STOPBITS_1,
        USART1_TX_BUFFER,
        usart1TxBuffer,
        USART1_RX_BUFFER,
        usart1RxBuffer,
        0, //NO DMA
        0, //NO DMA
        0, //NO DMA
        &HAL_UART_RxCpltCallback, //modificable, mirar ejemplo MTG
        NULL,
    },
#endif
#ifdef IS_UART2
    {
        USART2,
        115200,
        USART_WORDLENGTH_8B,
        USART_PARITY_NONE,
        USART_STOPBITS_1,
        USART2_TX_BUFFER,
        usart2TxBuffer,
        USART2_RX_BUFFER,
        usart2RxBuffer,
        0, //NO DMA
        0, //NO DMA
        0, //NO DMA
        &HAL_UART_RxCpltCallback, //modificable, mirar ejemplo MTG
        NULL,
    },
#endif
#ifdef IS_UART3
    {
        USART3,
        9600,
        USART_WORDLENGTH_8B,
        USART_PARITY_NONE,
        USART_STOPBITS_1,
        USART3_TX_BUFFER,
        usart3TxBuffer,
        USART3_RX_BUFFER,
        usart3RxBuffer,
        0, //NO DMA
        0, //NO DMA
        0, //NO DMA
        NULL, //No RX callback
        NULL, //No TX callback
    },
#endif
#ifdef IS_UART4
    {
        USART4,
        9600,
        USART_WORDLENGTH_8B,
        USART_PARITY_NONE,
        USART_STOPBITS_1,
        USART4_TX_BUFFER,
        usart4TxBuffer,
        USART4_RX_BUFFER,
        usart4RxBuffer,
        0, //NO DMA
        0, //NO DMA
        0, //NO DMA
        NULL, //No RX callback
        NULL, //No TX callback
    },
#endif
#ifdef IS_UART5
    {
        USART5,
        9600,
        USART_WORDLENGTH_8B,
        USART_PARITY_NONE,
        USART_STOPBITS_1,
        USART5_TX_BUFFER,
        usart5TxBuffer,
        USART5_RX_BUFFER,
        usart5RxBuffer,
        0, //NO DMA
        0, //NO DMA
        0, //NO DMA
        NULL, //No RX callback
        NULL, //No TX callback
    },
#endif
#ifdef IS_UART6
    {
        USART6,
        9600,
        USART_WORDLENGTH_8B,
        USART_PARITY_NONE,
        USART_STOPBITS_1,
        USART6_TX_BUFFER,
        usart6TxBuffer,
        USART6_RX_BUFFER,
        usart6RxBuffer,
        0, //NO DMA
        0, //NO DMA
        0, //NO DMA
        NULL, //No RX callback
        NULL, //No TX callback
    },
#endif
};
