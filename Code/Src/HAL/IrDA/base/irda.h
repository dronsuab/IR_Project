/*
 * irda.h
 *
 *  Created on: Mar 21, 2018
 *      Author: FV4IYP0
 */

#ifndef IRDA_H_
#define IRDA_H_

#include "common.h"
#include "irda_map.h"
#include "uart.h"
#include "GPIO.h"
#include "../../../Tools/CircularBuffer/CircularBuffer.h"



#define MAX_IRDA_BUFFER_SIZE    256

typedef HAL_StatusTypeDef (*irdaRxCallback)(uint8_t);
typedef HAL_StatusTypeDef (*irdaTxCallback)(uint8_t);

typedef struct
{
	CircularBuffer rxBuffer;
	CircularBuffer txBuffer;
} sIrdaContext;

typedef struct
{
    USART_TypeDef*  port;           /**< @brief ST HAL UART port structure */
    uint32_t        baudRate;       /**< @brief speed of the UART port */
    uint8_t         dataSize;       /**< @brief Word Length of the sent data */
    uint8_t 		mode;
    uint8_t         parity;         /**< @brief Activate or deactivate Parity */
    uint8_t         prescaler;      /**< @brief Prescaler value for dividing the UART/USART source clock
                                           to achieve low-power frequency */
    uint8_t 		powermode;		/**< @brief Specifies the IRDA power mode */

    //Read/Write Buffers
    uint16_t        txBufferSize;   /**< @brief Size of the tx buffer */
    uint8_t*        txBufferPtr;    /**< @brief Pointer of the tx buffer */
    uint16_t        rxBufferSize;   /**< @brief Size of the tx buffer */
    uint8_t*        rxBufferPtr;    /**< @brief Pointer of the tx buffer */

    //Callbacks
    irdaRxCallback  rxCallback;     /**< @brief Callback for RX interruption */
    irdaTxCallback  txCallback;     /**< @brief Callback for TX interruption */
} sIrdaInstanceMap;


void irdaInterruptHandler(eIrda irdaPort);
void irdaInit(void);
HAL_StatusTypeDef irdaStop(void);
HAL_StatusTypeDef irdaStart(void);
HAL_StatusTypeDef irdaWrite(eIrda  irdaPort, char* buffer);
HAL_StatusTypeDef irdaRead(eIrda  irdaPort, char* buffer, uint8_t lastChar);




#endif /* IRDA_H_ */
