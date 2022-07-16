/*
 * ex6.c
 *
 *  Created on: Jul 16, 2022
 *      Author: phelp
 */

// calculate sum of natural numbers

#include<stdio.h>

int main()
{
int n, sum=0;
printf("Enter number to find its sum: " );
fflush(stdout);
scanf("%d", &n);
for(int i=1 ; i<=n ; i++)
	sum+=i;
printf("Sum = %d",  sum);
}
