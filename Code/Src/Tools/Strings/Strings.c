/*
 * Strings.c
 *
 *  Created on: 25 feb. 2018
 *      Author: Iván
 */

#include "common.h"
#include "Strings.h"

/*  initString
 *
 *  @description: Initializes a string.
 *
 *  @param:		  buffer, length.
 *
 *  @return:      None.
 *
 *  */

void initString(char * buffer, uint8_t length)
{
	uint8_t i;
	for(i=0;i<length;i++)
	{
		buffer[i] = 0;
	}
}


/*  searchChar
 *
 *  @description: Searches for a specific char in a string.
 *
 *  @param:		  buffer, length, character.
 *
 *  @return:      if (found) -> index
 *  			  else       -> 0
 *
 *  */

uint8_t searchChar(char *buffer, uint8_t length, char character)
{
	uint8_t index=0;
	tBool found = FALSE;
	char bufferchar;

	while((index < length) && (!found))
	{
		bufferchar = *(buffer+index);
		if (bufferchar == character)
		{
			found = TRUE;
			return index;
		}else
			index++;
	}
	return 0;
}

