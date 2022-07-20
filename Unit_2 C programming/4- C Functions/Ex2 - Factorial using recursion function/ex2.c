/*
 * ex2.c
 *
 *  Created on: Jul 20, 2022
 *      Author: phelp
 */

// calculate factorial of a number using recursion

#include<stdio.h>

int Fact(int a);

int main()
{
	int a;
	printf("Enter a positive integer: ");
	fflush(stdout);
	scanf("%d",&a);
	printf("Factorial of %d = %d",a,Fact(a));
}

int Fact(int a)
{
	if (a==1)
		return 1;
	else
	{
		return a * Fact(a-1);
	}
}
