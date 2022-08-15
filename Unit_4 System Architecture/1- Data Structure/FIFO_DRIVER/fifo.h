/*
 * fifo.h
 *
 *  Created on: Aug 15, 2022
 *      Author: phelp
 */

#ifndef FIFO_H_
#define FIFO_H_

#include<stdio.h>
/*************************************************
 * 				Configurations
 ***********************************************/
#define FIFO_DATA_TYPE int

#define FIFO_LENGHT 5

typedef struct{
	unsigned int length ;
	unsigned int count;
	FIFO_DATA_TYPE * base;
	FIFO_DATA_TYPE * head;
	FIFO_DATA_TYPE *  tail;
}FIFO_Buf_t;

typedef enum
{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL
}E_FIFO_Status;

/*******************************************************
 * 						APIS
 *************************************************** */
E_FIFO_Status FIFO_init(FIFO_Buf_t* queue , FIFO_DATA_TYPE * buf , int buf_size);
E_FIFO_Status FIFO_Enqueue(FIFO_Buf_t* queue , FIFO_DATA_TYPE item);
E_FIFO_Status FIFO_Dequeue(FIFO_Buf_t* queue , FIFO_DATA_TYPE* item);
E_FIFO_Status FIFO_IsFull(FIFO_Buf_t* queue );
void FIFO_print(FIFO_Buf_t* queue);

#endif /* FIFO_H_ */
