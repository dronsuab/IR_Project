/*
 * irda_map.c
 *
 *  Created on: Mar 21, 2018
 *      Author: FV4IYP0
 */


#include "common.h"
#include "irda.h"
#include "irda_map.h"




const sIrdaInstanceMap IRDAInstanceMap[NUM_OF_IRDA] =  {

#ifdef IS_IRDA1
    {
//    	USART1,
//        115200,
//        IRDA_WORDLENGTH_8B,
//        IRDA_MODE_TX_RX,
//        IRDA_PARITY_NONE,
//        1,
//        IRDA_POWERMODE_NORMAL,
//        IRDA1_TX_BUFFER,
//        irda1TxBuffer,
//        IRDA1_RX_BUFFER,
//        irda1RxBuffer,
//        NULL, //modificable, mirar ejemplo MTG
//        NULL,

		USART1,
		115200,
		IRDA_WORDLENGTH_8B,
		IRDA_MODE_TX_RX,
		IRDA_PARITY_NONE,
		1,
		IRDA_POWERMODE_NORMAL,
		IRDA1_TX_BUFFER,
		irda1TxBuffer,
		IRDA1_RX_BUFFER,
		irda1RxBuffer,
		NULL, //modificable, mirar ejemplo MTG
		NULL,
    },
#endif


};
