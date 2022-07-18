/*
 * ex3.c
 *
 *  Created on: Jul 16, 2022
 *      Author: phelp
 */

// Find the largest number

#include<stdio.h>

int main ()
{
	int x,y,z;
	printf("Enter Three integers: ");
	fflush(stdout);
	scanf("%d %d %d", &x, &y, &z);
	if (x>y)
	{
		if (x>z)
			printf("%d is the largest number", x);
		else
			printf("%d is the largest number", z);
	}
	else
	{
		if (y>z)
			printf("%d is the largest number", y);
		else
			printf("%d is the largest number", z);
	}
}

