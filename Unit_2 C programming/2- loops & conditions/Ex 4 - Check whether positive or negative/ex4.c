/*
 * ex4.c
 *
 *  Created on: Jul 16, 2022
 *      Author: phelp
 */

// check whether the number is positive or negative

#include<stdio.h>

int main()
{
float x;
printf("Enter an integer to check: ");
fflush(stdout);
scanf("%f", &x);
if (x>0)
	printf("%f is positive integer",x);
else if (x<0)
	printf("%f is negative integer",x);
else
	printf("you entered Zero");
}
