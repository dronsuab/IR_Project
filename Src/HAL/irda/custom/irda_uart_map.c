/*
 * irda_uart_map.c
 *
 *  Created on: 20 ene. 2018
 *      Author: APM137
 */

#include "irda_uart_map.h"

extern HAL_StatusTypeDef testRxCallback(uint8_t c);
extern HAL_StatusTypeDef testTxCallback(uint8_t c);
/*
#ifdef IS_UART1
    uint8_t usart1TxBuffer[USART1_TX_BUFFER];
    uint8_t usart1RxBuffer[USART1_RX_BUFFER];
#endif

#ifdef IS_UART1
    {
        USART1,
        115200,
        UART_WORDLENGTH_8B,
        UART_STOPBITS_1,
        UART_PARITY_NONE,
        USART1_TX_BUFFER,
        usart1TxBuffer,
        USART1_RX_BUFFER,
        usart1RxBuffer,
        0, //NO DMA
        0, //NO DMA
        0, //NO DMA
        NULL, //modificable, mirar ejemplo MTG
        NULL,
    },
#endif
*/
