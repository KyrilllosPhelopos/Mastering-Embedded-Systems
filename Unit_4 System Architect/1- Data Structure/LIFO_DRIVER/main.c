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
		printf("%d\t", i);
		LIFO_AddItem(&buffer1 , i);
	}
	fflush(stdout);
	printf("\nBuffer 1 (static allocation) LIFO_POP_ITEMS \n");
	int temp;
		for(int i =0 ;i< 5;i++)
		{
			LIFO_PopItem(&buffer1 , &temp);
			printf("%d\t", temp);
		}


		printf("\n\n\===========================================================\n");

		buffer2.count = 0;
		buffer2.length = LIFO_LENGHT;
		printf("Buffer 2 (Dynamic allocation) LIFO_PUSH_ITEMS \n");
		for(int i =0 ;i< 5;i++)
		{
			printf("%d\t", i);
			LIFO_AddItem(&buffer1 , i);
		}
		fflush(stdout);
		printf("\nBuffer 2 (Dynamic allocation) LIFO_POP_ITEMS \n");

			for(int i =0 ;i< 5;i++)
			{
				LIFO_PopItem(&buffer1 , &temp);
				printf("%d\t", temp);
			}



}

