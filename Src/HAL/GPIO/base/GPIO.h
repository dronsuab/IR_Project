


/****************************************************************************
 *  INCLUDES
 ***************************************************************************/

#include "common.h"
#include "GPIO_map.h"

/****************************************************************************
 * DEFINES
 ****************************************************************************/
#define GPIO_AF_NONE		0xFF


typedef enum
{
	GPIO_LOW,
	GPIO_HIGH,
	GPIO_TOGGLE,
	GPIO_DEFAULT
} eGPIOValue;

typedef struct
{
	GPIO_TypeDef*	  	port;
	uint16_t 			pin;
	uint32_t 			mode;
	uint8_t				speed;
	uint8_t    			pupd;
	uint8_t				alternate;
	eGPIOValue			initialValue;
} tGPIOInstanceMap;


/****************************************************************************
 *    PUBLIC FUNCTION DEFINITIONS
 ****************************************************************************/
eError GPIOInit( void );
eError GPIOStop( void );
eError GPIOStart( void );
eError GPIOSleep( void );
eError GPIOWake( void );
eError GPIOWrite(eGPIO port, eGPIOValue value);
eError GPIORead(eGPIO port,  eGPIOValue *value);


/****************************************************************************
 *    End of file
 ***************************************************************************/
