/*
 * lifo.h
 *
 *  Created on: Aug 15, 2022
 *      Author: phelp
 */

#ifndef LIFO_H_
#define LIFO_H_



/*************************************************
 * 				Configurations
 ***********************************************/
#define LIFO_DATA_TYPE int

#define LIFO_LENGHT 5

typedef struct{
	unsigned int length ;
	unsigned int count;
	LIFO_DATA_TYPE * base;
	LIFO_DATA_TYPE * head;
}LIFO_Buf_t;

typedef enum
{
	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_EMPTY,
	LIFO_NULL
}LIFO_Status;

/*******************************************************
 * 						APIS
 *************************************************** */
LIFO_Status LIFO_AddItem(LIFO_Buf_t * buf ,LIFO_DATA_TYPE  data );
LIFO_Status LIFO_PopItem(LIFO_Buf_t * buf ,LIFO_DATA_TYPE*  data );

#endif /* LIFO_H_ */
