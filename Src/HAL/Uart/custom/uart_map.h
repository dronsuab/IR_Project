/*
 * uart_map.h
 *
 *  Created on: 20 oct. 2017
 *      Author: Iván
 */

#ifndef HAL_UART_CUSTOM_UART_MAP_H_
#define HAL_UART_CUSTOM_UART_MAP_H_


#include "common.h"
#include "config.h"

#define UART_TX_BUFFER 100

#define IS_UART1
#define IS_UART2
//#define IS_UART3
//#define IS_UART4
//#define IS_UART5
//#define IS_UART6

#ifdef IS_UART1
#define USART1_TX_BUFFER          256
#endif
#ifdef IS_UART2
#define USART2_TX_BUFFER          1028
#endif
#ifdef IS_UART3
#define USART3_TX_BUFFER          100
#endif
#ifdef IS_UART4
#define USART4_TX_BUFFER          100
#endif
#ifdef IS_UART5
#define USART5_TX_BUFFER          100
#endif
#ifdef IS_UART6
#define USART6_TX_BUFFER          100
#endif

#ifdef IS_UART1
#define USART1_RX_BUFFER          100
#endif
#ifdef IS_UART2
#define USART2_RX_BUFFER          100
#endif
#ifdef IS_UART3
#define USART3_RX_BUFFER          100
#endif
#ifdef IS_UART4
#define USART4_RX_BUFFER          100
#endif
#ifdef IS_UART5
#define USART5_RX_BUFFER          100
#endif
#ifdef IS_UART6
#define USART6_RX_BUFFER          100
#endif


/***********************************************************************
 * TYPE DEFINITIONS
 **********************************************************************/

typedef enum eUart
{
    UART_INIT = -1,
#ifdef IS_UART1
    UART_1,
#endif
#ifdef IS_UART2
    UART_2,
#endif
#ifdef IS_UART3
    UART_3,
#endif
#ifdef IS_UART4
    UART_4,
#endif
#ifdef IS_UART5
    UART_5,
#endif
#ifdef IS_UART6
    UART_6,
#endif
    NUM_OF_UART
} tUart;



#endif /* HAL_UART_CUSTOM_UART_MAP_H_ */
