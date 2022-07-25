/*
 ============================================================================
 Name        : Ex7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// calculate the sum from 1 to 100 without loop

int sum (int num)
{
if(num <=0)
	return 0;
else
	return  sum(num -1) + num ;
}


int main(void) {
	printf(" the summation from 1 to %d is %d",100,sum(100));
	fflush(stdout);
}
