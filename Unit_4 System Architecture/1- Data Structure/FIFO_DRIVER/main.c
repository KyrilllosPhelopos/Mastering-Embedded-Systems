/*
 * main.c
 *
 *  Created on: Aug 15, 2022
 *      Author: phelp
 */

#include<stdio.h>
#include"fifo.h"

int main()
{
FIFO_DATA_TYPE buf[5];
FIFO_Buf_t fifoBuff;
FIFO_DATA_TYPE temp;
FIFO_init(&fifoBuff , buf , 5);

printf("Enqueue Some Values \n");
for(int i = 0 ;i< 7 ; i++)
{
	if(FIFO_Enqueue(&fifoBuff , i)==FIFO_NO_ERROR)
		printf("%d Enqueued Successfully \n",i);
	else
		printf("%d Failed to be Enqueued \n",i);
}
fflush(stdout);

printf("\n\n dequeue Some Values \n");
for(int i = 0 ;i< 2 ; i++)
{
	if(FIFO_Dequeue(&fifoBuff , & temp)==FIFO_NO_ERROR)
		printf("%d dequeued Successfully \n",temp);
	else
		printf("Failed to be dequeue \n");
}
fflush(stdout);
printf("\n\n\FIFO CONTENT \n");
FIFO_print(&fifoBuff );
fflush(stdout);
}
