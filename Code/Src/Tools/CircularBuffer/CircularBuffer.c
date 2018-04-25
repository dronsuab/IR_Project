/*
 * CircularBuffer.c
 *
 *  Created on: 26 oct. 2017
 *      Author: Iván
 */

#include "CircularBuffer.h"

#include "common.h"



/*  CreateFIFO
 *
 *  @description: Initializes a CircularBuffer.
 *
 *  @param:		  CircularBuffer, bufferPtr, size.
 *
 *  @return:      None.
 *
 *  */

void CreateFIFO(CircularBuffer* buffer, uint8_t* bufferPtr, uint16_t size)
{
	buffer->bufferPtr = bufferPtr;
	buffer->bufferLen = size;
	buffer->rxPtr = 0;
	buffer->txPtr = 0;
    buffer->numOfBytes = 0;
}


/*  ResetFIFO
 *
 *  @description: Resets a CircularBuffer.
 *
 *  @param:		  CircularBuffer.
 *
 *  @return:      None.
 *
 *  */

void ResetFIFO(CircularBuffer* buffer)
{
	buffer->rxPtr = 0;
	buffer->txPtr = 0;
    buffer->numOfBytes = 0;
}


/*  GetFIFOByte
 *
 *  @description: Gets a byte from a CircularBuffer.
 *
 *  @param:		  CircularBuffer.
 *
 *  @return:      data.
 *
 *  */

uint8_t GetFIFOByte(CircularBuffer* buffer)
{
    uint8_t data;
	//interruptsDisable();
    data = buffer->bufferPtr[buffer->rxPtr];
    buffer->numOfBytes--;
    buffer->rxPtr++;
    buffer->rxPtr %= buffer->bufferLen;
    //interruptsEnable();
    return data;
}


/*  AddFIFOByte
 *
 *  @description: Adds a byte to a CircularBuffer.
 *
 *  @param:		  CircularBuffer, data.
 *
 *  @return:      None.
 *
 *  */

void AddFIFOByte(CircularBuffer* buffer, uint8_t data)
{
	//interruptsDisable();
    buffer->bufferPtr[buffer->txPtr]= data;
    buffer->numOfBytes++;
    buffer->txPtr++;
    buffer->txPtr %= buffer->bufferLen;
	//interruptsEnable();
}


/*  GetFIFOPendingBytes
 *
 *  @description: Gets the number of filled bytes in a CircularBuffer.
 *
 *  @param:		  CircularBuffer.
 *
 *  @return:      numOfBytes.
 *
 *  */

uint16_t GetFIFOPendingBytes(CircularBuffer* buffer)
{
    return buffer->numOfBytes;
}


/*  GetFIFOFreeBytes
 *
 *  @description: Gets the number of empty bytes in a CircularBuffer.
 *
 *  @param:		  CircularBuffer.
 *
 *  @return:      bufferLen - numOfBytes.
 *
 *  */

uint16_t GetFIFOFreeBytes(CircularBuffer* buffer)
{
    return (buffer->bufferLen)-(buffer->numOfBytes);
}

