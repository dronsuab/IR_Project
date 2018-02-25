/*
 * BridgeMode.c
 *
 *  Created on: 23 feb. 2018
 *      Author: Iván
 */

#include "common.h"
#include "BridgeMode.h"
#include "GPIO.h"

#define MAX_CHARS 5

static Led tLed;
static Muerto tMuerto;
static Disparo tDisparo;

char tag[10];


tBool enterBridgeMode(char *RxBuffer, uint8_t Rxlength, char *TxBuffer, uint8_t TxLength)
{

	char tag[10];
	uint8_t index[MAX_CHARS];
	uint8_t i = 0;
	uint8_t lastcharacter;
	uint8_t searchedcharacter;
	tBool error = TRUE;

	initStructs();
	initString(tag, 10);
	initString((char*)index, MAX_CHARS);


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
		strncpy(tDisparo.controller, &RxBuffer[index[0]+1], (index[1]-index[0]-1));
		strncpy(tDisparo.weapon, &RxBuffer[index[1]+1], lastcharacter-index[1]-1);

	}

	else if (strcmp(tag, "LED") == 0)
	{
		strncpy(tLed.drone, &RxBuffer[index[0]+1], (index[1]-index[0]-1));
		strncpy(tLed.right, &RxBuffer[index[1]+1], (index[2]-index[1]-1));
		strncpy(tLed.left, &RxBuffer[index[2]+1], (index[3]-index[2]-1));
		strncpy(tLed.fw, &RxBuffer[index[3]+1], (index[4]-index[3]-1));
		strncpy(tLed.bw, &RxBuffer[index[4]+1], lastcharacter-index[4]-1);

		if ((tLed.right[0] == '1') || (tLed.left[0] == '1'))
		{
			GPIOWrite(GPIO_LED_3, GPIO_HIGH);
		}
		else
		{
			GPIOWrite(GPIO_LED_3, GPIO_LOW);
		}
		if ((tLed.fw[0] == '1') || (tLed.bw[0] == '1'))
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
		strncpy(tMuerto.controller, &RxBuffer[index[0]+1], (index[1]-index[0]-1));
		strncpy(tMuerto.drone, &RxBuffer[index[1]+1], lastcharacter-index[1]-1);

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

uint8_t searchChar(char *searchedbuffer, uint8_t length, char character)
{
	uint8_t i=0;
	tBool found = FALSE;
	char bufferchar;

	while((i < length) && (!found))
	{
		bufferchar = *(searchedbuffer+i);
		if (bufferchar == character)
		{
			found = TRUE;
			return i;
		}else
			i++;
	}
	return 0;
}


void initStructs(void)
{
	initString(tDisparo.controller, strlen(tDisparo.controller));
	initString(tDisparo.weapon, strlen(tDisparo.weapon));
	initString(tLed.drone, strlen(tLed.drone));
	initString(tLed.right, strlen(tLed.right));
	initString(tLed.left, strlen(tLed.left));
	initString(tLed.fw, strlen(tLed.fw));
	initString(tLed.bw, strlen(tLed.bw));
	initString(tMuerto.controller, strlen(tMuerto.controller));
	initString(tMuerto.drone, strlen(tMuerto.drone));
}
