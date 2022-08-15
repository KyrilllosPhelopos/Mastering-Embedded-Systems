/*
 * lifo.c
 *
 *  Created on: Aug 15, 2022
 *      Author: phelp
 */
#include"lifo.h"

LIFO_Status LIFO_AddItem(LIFO_Buf_t * buf ,LIFO_DATA_TYPE  data )
{
	//check if the buffer is null
	if(!buf->base || ! buf->head  ||! buf)
		return LIFO_NULL;
	// check if the buffer is full
	if(buf->length == buf->count )
		return LIFO_FULL;
	// adding data
	*(buf->head) = data;
	(buf->head)++;
	buf->count++;
	return LIFO_NO_ERROR;
}
LIFO_Status LIFO_PopItem(LIFO_Buf_t * buf ,LIFO_DATA_TYPE*  data )
{
	//check if the buffer is null
	if(!buf->base || ! buf->head  ||! buf)
		return LIFO_NULL;
	// check if the buffer is empty
	if(buf->count == 0 )
		return LIFO_EMPTY;
	// poping head content
	buf->head --;
	*data = *buf->head;
	buf->count--;
	return LIFO_NO_ERROR;


}
