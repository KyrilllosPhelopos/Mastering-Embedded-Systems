/*
 * ex1.c
 *
 *  Created on: Jul 16, 2022
 *      Author: phelp
 */

/*
 * check where the integer is even or odd
 *
 */

#include<stdio.h>

int main()
{
int x;
printf("Enter an integer you want to check: ");
fflush(stdout);
scanf("%d", &x);
if((x%2) == 0)
	printf("%d is even",x);
else
	printf("%d is odd",x);
}
