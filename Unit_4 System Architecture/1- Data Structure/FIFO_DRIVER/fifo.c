/*
 * fifo.c
 *
 *  Created on: Aug 15, 2022
 *      Author: phelp
 */

#include"fifo.h"

/*******************************************************
 * 						APIS
 *************************************************** */
E_FIFO_Status FIFO_init(FIFO_Buf_t* queue , FIFO_DATA_TYPE * buf , int buf_size)
{
	if(!buf)
		return FIFO_NULL;

	queue->length = buf_size;
	queue->count = 0;
	queue->base=buf;
	queue->head = queue->base;
	queue->tail = queue->base;
	return FIFO_NO_ERROR;

}


E_FIFO_Status FIFO_Enqueue(FIFO_Buf_t* queue , FIFO_DATA_TYPE item)
{
	if (! queue ||! queue->base || ! queue->head || ! queue->tail)
		return FIFO_NULL;
	if( FIFO_IsFull(queue) == FIFO_FULL)
		return FIFO_FULL;

	* (queue->tail) = item;
	queue->count ++;
	if(queue->tail == (queue->base + (queue->length *sizeof(FIFO_DATA_TYPE))))
		queue->tail= queue->base;
	else
		queue->tail ++;
	return FIFO_NO_ERROR;
}


E_FIFO_Status FIFO_Dequeue(FIFO_Buf_t* queue , FIFO_DATA_TYPE* item)
{
	if (! queue ||! queue->base || ! queue->head || ! queue->tail)
		return FIFO_NULL;
	if(queue->count == 0)
		return FIFO_EMPTY;
	*item = *queue->head;
	queue->count --;
	if(queue->head == (queue->base + (queue->length *sizeof(FIFO_DATA_TYPE))))
		queue->head= queue->base;
	else
		queue->head ++;

	return FIFO_NO_ERROR;

}


E_FIFO_Status FIFO_IsFull(FIFO_Buf_t* queue )
{
	if (! queue ||! queue->base || ! queue->head || ! queue->tail)
		return FIFO_NULL;
	if(queue->count >= queue->length)
		return FIFO_FULL;
	return FIFO_NO_ERROR;
}


void FIFO_print(FIFO_Buf_t* queue)
{
	if (! queue ||! queue->base || ! queue->head || ! queue->tail)
	{
		printf("FIFO IS NULL\n");
		return;
	}
	else if(queue->count == 0)
	{
		printf("FIFO IS EMPTY \n");
		return;
	}
	FIFO_DATA_TYPE * temp;
	temp = queue->head;
	for(int i = 0;i< queue->count;i++)
	{
		printf("item: %d has value = %x \n",i,*temp);
		if(temp == (queue->base + (queue->length *sizeof(FIFO_DATA_TYPE))))
			temp= queue->base;
		else
			temp++;

	}
}
