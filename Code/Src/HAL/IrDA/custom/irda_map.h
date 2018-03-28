/*
 * irda_map.h
 *
 *  Created on: Mar 21, 2018
 *      Author: FV4IYP0
 */

#ifndef IRDA_MAP_H_
#define IRDA_MAP_H_

#include "common.h"
#include "config.h"


#ifdef IS_IRDA1
#define IRDA1_TX_BUFFER          256
#endif



#ifdef IS_IRDA1
#define IRDA1_RX_BUFFER          100
#endif



typedef enum
{
#ifdef IS_IRDA1
    IRDA_1,
#endif
    NUM_OF_IRDA
} eIrda;


#endif /* IRDA_MAP_H_ */
