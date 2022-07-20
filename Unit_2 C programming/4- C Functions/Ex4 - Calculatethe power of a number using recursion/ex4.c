/*
 * ex4.c
 *
 *  Created on: Jul 20, 2022
 *      Author: phelp
 */

// calculate a power of a number using recursion

#include<stdio.h>

int power(int num , int pwr);

int main()
{
	int a , b;
	printf("Enter base: ");
	fflush(stdout);
	scanf("%d",&a);
	printf("Enter power number (positive integer): ");
	fflush(stdout);
	scanf("%d", &b);
	printf("%d^%d = %d",a, b, power(a,b) );
}

int power(int num , int pwr)
{
if (pwr==0)
	return 1;
return num* power(num , --pwr);
}
