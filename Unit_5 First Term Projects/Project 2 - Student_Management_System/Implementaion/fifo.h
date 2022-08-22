/*
 * fifo.h
 *
 *  Created on: Aug 22, 2022
 *      Author: phelp
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "common_macros.h"





/*******************************************************
 * 						APIS
 *************************************************** */
E_FIFO_Status FIFO_init(FIFO_Buf_t* queue , FIFO_DATA_TYPE * buf , int buf_size);

E_FIFO_Status FIFO_Enqueue(FIFO_Buf_t* queue , FIFO_DATA_TYPE item);

E_FIFO_Status FIFO_Dequeue(FIFO_Buf_t* queue , FIFO_DATA_TYPE * item);

E_FIFO_Status FIFO_IsFull(FIFO_Buf_t* queue );


#endif /* FIFO_H_ */
