/*
 * irda_map.c
 *
 *  Created on: Mar 21, 2018
 *      Author: FV4IYP0
 */


#include "common.h"
#include "irda.h"
#include "irda_map.h"

#ifdef IS_IRDA1
    uint8_t irda1TxBuffer[IRDA1_TX_BUFFER];
    uint8_t irda1RxBuffer[IRDA1_RX_BUFFER];
#endif


const sIrdaInstanceMap IRDAInstanceMap[NUM_OF_IRDA] =  {

#ifdef IS_IRDA1
    {
        IRDA1,
        115200,
        IRDA_WORDLENGTH_8B,
        IRDA_STOPBITS_1,
        IRDA_PARITY_NONE,
        IRDA1_TX_BUFFER,
        irdat1TxBuffer,
        IRDA1_RX_BUFFER,
        irda1RxBuffer,
        0, //NO DMA
        0, //NO DMA
        0, //NO DMA
        NULL, //modificable, mirar ejemplo MTG
        NULL,
    },
#endif


};
