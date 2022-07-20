/*
 * ex1.c
 *
 *  Created on: Jul 20, 2022
 *      Author: phelp
 */

// prime numbers between two intervals

#include<stdio.h>

void primeNum(int a , int b);

int main()
{
	int a , b;
	printf("Enter two numbers: ");
	fflush(stdout);
	scanf("%d %d",&a,&b);
	printf("prime numbers between %d and %d are: ",a,b);
	primeNum(a,b);
}

void primeNum(int a , int b)
{
	int i;
	for(;a<=b;a++)
	{
		for (i=2;i<a;i++)
		{
			if((a%i)==0)
				break;
		}
		if (i==a)
			printf(" %d",a);
	}
}
