/*
 * GPIO_map.c
 *
 *  Created on: 15 oct. 2017
 *      Author: Iván
 */

#include "common.h"
#include "GPIO.h"


const tGPIOInstanceMap GPIOInstanceMap[NUM_OF_GPIO] =
{
		/* {Port, GPIO_pins, GPIO_mode, GPIO_speed, GPIO_pull, GPIO_AF, GPIO_Init_Value }
		 *
		 * Port 			--> GPIOA, GPIOB, GPIOC, GPIOD, GPIOH
		 * GPIO_pins  		--> GPIO_PIN_X
		 * GPIO_mode 		--> GPIO_MODE_INPUT, GPIO_MODE_OUTPUT_PP, GPIO_MODE_OUTPUT_OD, GPIO_MODE_AF_PP,
		 * 						GPIO_MODE_AF_OD, GPIO_MODE_ANALOG
		 * GPIO_speed 		--> GPIO_SPEED_LOW, GPIO_SPEED_MEDIUM, GPIO_SPEED_FREQ_HIGH
		 * GPIO_pull 		--> GPIO_NOPULL, GPIO_PULLUP, GPIO_PULLDOWN
		 * GPIO_AF		-->
		 * GPIO_Init_Value 	--> GPIO_LOW, GPIO_HIGH, GPIO_TOGGLE, GPIO_DEFAULT        */


	/* UART2 */

	/* LEDS */
			/* GPIO_LED_3				*/				{ GPIOC, GPIO_PIN_9, GPIO_MODE_OUTPUT_PP, GPIO_SPEED_FREQ_HIGH, GPIO_NOPULL, GPIO_AF_NONE, GPIO_LOW },
			/* GPIO_LED_4				*/				{ GPIOC, GPIO_PIN_8, GPIO_MODE_OUTPUT_PP, GPIO_SPEED_FREQ_HIGH, GPIO_NOPULL, GPIO_AF_NONE, GPIO_LOW },

};

