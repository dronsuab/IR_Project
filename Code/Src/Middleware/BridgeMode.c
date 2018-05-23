/*
 * BridgeMode.c
 *
 *  Created on: 23 feb. 2018
 *      Author: Iván
 */

#include "common.h"
#include "BridgeMode.h"
#include "GPIO.h"
#include "uart.h"

#define MAX_CHARS 5

static sLed Led;
static sMuerto Muerto;
static sDisparo Disparo;

char tag[10];


/*  enterBridgeMode
 *
 *  @description: Parses a RX buffer until EOM. Splits the message into fields.
 *  			  Decides further actions based on the Tag field.
 *
 *  @param:		  RxBuffer, Rxlength, TxBuffer, TxLength.
 *
 *  @return:      error.
 *
 *  */

tBool enterBridgeMode(char *RxBuffer, uint8_t Rxlength, char *TxBuffer, uint8_t TxLength)
{

	char tag[10];
	uint8_t index[MAX_CHARS];
	uint8_t i = 0;
	uint8_t lastcharacter;
	uint8_t searchedcharacter;
	tBool error = FALSE;
	char zeros[10];

	initStructs();
	initString(tag, 10);
	initString((char*)index, MAX_CHARS);
	initString(TxBuffer, TxLength);
	initString(zeros, 10);


	lastcharacter = searchChar(RxBuffer, Rxlength, '/');
	index[i] = searchChar(&RxBuffer[index[0]], lastcharacter, ',');
	i++;

	while ((index[i-1] < lastcharacter) && (i < MAX_CHARS))
	{
		searchedcharacter = searchChar(&RxBuffer[index[i-1]+1], lastcharacter-index[i-1], ',');
		if (searchedcharacter > 0)
		{
			index[i] = index[i-1] + searchedcharacter + 1;
			i++;
		}
		else
			i = MAX_CHARS;
	}

	strncpy(tag, RxBuffer, index[0]);

	if (strcmp(tag, "CFIRE") == 0)
	{
		strncpy(Disparo.controller, &RxBuffer[index[0]+1], (index[1]-index[0]-1));
		strncpy(Disparo.weapon, &RxBuffer[index[1]+1], lastcharacter-index[1]-1);

		strcpy(TxBuffer, "SHOT");
		strcat(TxBuffer, "A");
		strcat(TxBuffer, Disparo.weapon);
		strncpy(&TxBuffer[strlen(TxBuffer)], zeros, (10-strlen(TxBuffer)));

		error = TRUE;


		GPIOWrite(GPIO_LED_3, GPIO_HIGH);

	}

	else if (strcmp(tag, "LED") == 0)
	{
		strncpy(Led.drone, &RxBuffer[index[0]+1], (index[1]-index[0]-1));
		strncpy(Led.right, &RxBuffer[index[1]+1], (index[2]-index[1]-1));
		strncpy(Led.left, &RxBuffer[index[2]+1], (index[3]-index[2]-1));
		strncpy(Led.fw, &RxBuffer[index[3]+1], (index[4]-index[3]-1));
		strncpy(Led.bw, &RxBuffer[index[4]+1], lastcharacter-index[4]-1);

		if ((Led.right[0] == '1') || (Led.left[0] == '1'))
		{
			GPIOWrite(GPIO_LED_3, GPIO_HIGH);
		}
		else
		{
			GPIOWrite(GPIO_LED_3, GPIO_LOW);
		}
		if ((Led.fw[0] == '1') || (Led.bw[0] == '1'))
		{
			GPIOWrite(GPIO_LED_4, GPIO_HIGH);
		}
		else
		{
			GPIOWrite(GPIO_LED_4, GPIO_LOW);
		}

	}
	else if (strcmp(tag, "DEAD") == 0)
	{
		strncpy(Muerto.controller, &RxBuffer[index[0]+1], (index[1]-index[0]-1));
		strncpy(Muerto.drone, &RxBuffer[index[1]+1], lastcharacter-index[1]-1);

	}
	else if (strcmp(tag, "SHOT") == 0)
	{
		strncpy(Disparo.controller, &RxBuffer[index[0]+1], (index[1]-index[0]-1));
		strncpy(Disparo.weapon, &RxBuffer[index[1]+1], lastcharacter-index[1]-1);
		strcpy(TxBuffer, "FIRE");
		strcat(TxBuffer, Disparo.controller);
		strcat(TxBuffer, DRONE_ID);
		strcat(TxBuffer, Disparo.weapon);
		strcat(TxBuffer, SIDE);

		error = TRUE;
	}
	else if (strcmp(tag, "FJUEGO") == 0)
	{
		//enterinmodesleep
	}
	else
	{
		error = FALSE;
	}

	return error;

}


/*  initStructs
 *
 *  @description: Initializes all fields (structs).
 *
 *  @param:		  None.
 *
 *  @return:      None.
 *
 *  */

void initStructs(void)
{
	initString(Disparo.controller, strlen(Disparo.controller));
	initString(Disparo.weapon, strlen(Disparo.weapon));
	initString(Led.drone, strlen(Led.drone));
	initString(Led.right, strlen(Led.right));
	initString(Led.left, strlen(Led.left));
	initString(Led.fw, strlen(Led.fw));
	initString(Led.bw, strlen(Led.bw));
	initString(Muerto.controller, strlen(Muerto.controller));
	initString(Muerto.drone, strlen(Muerto.drone));
}
