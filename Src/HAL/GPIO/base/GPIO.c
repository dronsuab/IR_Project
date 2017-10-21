/*
 * GPIO.c
 *
 *  Created on: 15 oct. 2017
 *      Author: Iván
 */

#include "common.h"
#include "GPIO.h"
#include "GPIO_map.h"

extern const tGPIOInstanceMap GPIOInstanceMap[NUM_OF_GPIO];


void InitGPIOClock(tGPIO port);



eError GPIOInit( void )
{
	eError 				result = RET_OK;
	uint8_t 			port;
	GPIO_InitTypeDef  	GPIO_InitStructure;

	for (port = 0; port < NUM_OF_GPIO; port++)
	{
		/* Enable GPIO clock of corresponding port */
		InitGPIOClock(port);

		/* Configure the GPIO parameters */
        GPIO_InitStructure.Pin =  	(uint32_t)GPIOInstanceMap[port].pin;
		GPIO_InitStructure.Mode = 	(uint32_t)GPIOInstanceMap[port].mode;
		GPIO_InitStructure.Speed = 	(uint32_t)GPIOInstanceMap[port].speed;
		GPIO_InitStructure.Pull = 	(uint32_t)GPIOInstanceMap[port].pupd;
		GPIO_InitStructure.Alternate = (uint32_t)GPIOInstanceMap[port].alternate;

		HAL_GPIO_Init(GPIOInstanceMap[port].port, &GPIO_InitStructure);

		/* Set GPIO initial value */
		if ( GPIOInstanceMap[port].initialValue != GPIO_DEFAULT )
		{
			result = GPIOWritePort(port, GPIOInstanceMap[port].initialValue);
		}
		/* No else needed */
	}

	return result;
}

/*************************************************************************//**
 * @brief  	Writes GPIO port with desired value.
 * @param	port to write.
 * @param   value
 * @return  success.
 ****************************************************************************/
eError GPIOWritePort(tGPIO port, tGPIOValue value)
{
	eError 	result = RET_OK;

	if ( value == GPIO_DEFAULT )
	{
		result = RET_INVALID_PARAMETER;
		return result;
	}


	if ( value != GPIO_TOGGLE )
	{
		HAL_GPIO_WritePin(GPIOInstanceMap[port].port, GPIOInstanceMap[port].pin, value);
	}
	else
	{
		HAL_GPIO_TogglePin(GPIOInstanceMap[port].port, GPIOInstanceMap[port].pin);
	}

	return result;
}

/*************************************************************************//**
 * @brief  	Reads GPIO port.
 * @param	port to read.
 * @param   value
 * @return  success.
 ****************************************************************************/
eError GPIOReadPort(tGPIO port,  tGPIOValue *value)
{
	eError 	result = RET_OK;

	*value = HAL_GPIO_ReadPin(GPIOInstanceMap[port].port, GPIOInstanceMap[port].pin);

	return result;
}


/****************************************************************************
 *    PRIVATE FUNCTIONS
 ****************************************************************************/

/*************************************************************************//**
 * @brief  Enable GPIO clock.
 * @param	port to enable clock.
 * @return  None.
 ****************************************************************************/
void InitGPIOClock(tGPIO port)
{
	/* Enable the GPIO Clock */
#ifdef GPIOA
	if ( GPIOInstanceMap[port].port == GPIOA ){
		__GPIOA_CLK_ENABLE();
	}
#endif //GPIOA

#ifdef GPIOB
	if( GPIOInstanceMap[port].port == GPIOB ){
		__GPIOB_CLK_ENABLE();
	}
#endif //GPIOB

#ifdef GPIOC
	if( GPIOInstanceMap[port].port == GPIOC ){
		__GPIOC_CLK_ENABLE();
	}
#endif //GPIOC

#ifdef GPIOD
	if( GPIOInstanceMap[port].port == GPIOD ){
		__GPIOD_CLK_ENABLE();
	}
#endif //GPIOD

#ifdef GPIOE
	if( GPIOInstanceMap[port].port == GPIOE ){
		__GPIOE_CLK_ENABLE();
	}
#endif //GPIOE

#ifdef GPIOF
	if( GPIOInstanceMap[port].port == GPIOF ){
		__GPIOF_CLK_ENABLE();
	}
#endif //GPIOF

#ifdef GPIOG
	if( GPIOInstanceMap[port].port == GPIOG ){
		__GPIOG_CLK_ENABLE();
	}
#endif //GPIOG

#ifdef GPIOH
	if( GPIOInstanceMap[port].port == GPIOH ){
		__GPIOH_CLK_ENABLE();
	}
#endif //GPIOH

#ifdef GPIOI
	if( GPIOInstanceMap[port].port == GPIOI ){
		__GPIOI_CLK_ENABLE();
	}
#endif //GPIOI


}


