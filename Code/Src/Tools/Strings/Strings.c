/*
 * Strings.c
 *
 *  Created on: 25 feb. 2018
 *      Author: Iván
 */

#include "common.h"
#include "Strings.h"

void initString(char * buffer, uint8_t length)
{
	uint8_t i;
	for(i=0;i<length;i++)
	{
		buffer[i] = 0;
	}
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

