/* * main.c
 *
 *  Created on: Aug 15, 2022
 *      Author: Kyrillos Sawiris
 */

#include<stdio.h>
#include<stdlib.h>
#include"lifo.h"


int main()
{
	LIFO_Buf_t buffer1,buffer2;
	int static_buf [LIFO_LENGHT];
	buffer1.base = static_buf;
	buffer1.head = buffer1.base;
	buffer2.base = (int *) malloc(LIFO_LENGHT * sizeof(int));
	buffer2.head = buffer2.base;

	buffer1.count = 0;
	buffer1.length = LIFO_LENGHT;
	printf("Buffer 1 (static allocation) LIFO_PUSH_ITEMS \n");
	for(int i =0 ;i< 5;i++)
	{
		if(LIFO_AddItem(&buffer1 , i) == LIFO_NO_ERROR)
			printf("Writing %d in LIFO_uart passed\n",i);
		else
			printf("Writing %d in LIFO_uart failed\n",i);
	}
	fflush(stdout);
	printf("\nBuffer 1 (static allocation) LIFO_POP_ITEMS \n");
	int temp;
	for(int i =0 ;i< 5;i++)
	{
		if(LIFO_PopItem(&buffer1 , &temp)==LIFO_NO_ERROR)
		{
			printf("Reading %d in static Buffer passed\n",temp);
		}
		else
		{
			printf("Reading %d in static Buffer failed\n",temp);
		}
	}


	printf("\n\n\===========================================================\n");

	buffer2.count = 0;
	buffer2.length = LIFO_LENGHT;
	printf("Buffer 2 (Dynamic allocation) LIFO_PUSH_ITEMS \n");
	for(int i =0 ;i< 5;i++)
	{
		if(LIFO_AddItem(&buffer1 , i) == LIFO_NO_ERROR)
			printf("Writing %d in Dynamic Buffer passed\n",i);
		else
			printf("Writing %d in Dynamic Buffer failed\n",i);
	}
	fflush(stdout);
	printf("\nBuffer 2 (Dynamic allocation) LIFO_POP_ITEMS \n");

	for(int i =0 ;i< 5;i++)
	{
		if(LIFO_PopItem(&buffer1 , &temp)==LIFO_NO_ERROR)
		{
			printf("Reading %d in Dynamic Buffer passed\n",temp);
		}
		else
		{
			printf("Reading %d in Dynamic Buffer failed\n",temp);
		}
	}



}

