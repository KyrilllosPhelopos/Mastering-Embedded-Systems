/*
 ============================================================================
 Name        : Ex3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

//c function to print all prime numbers between two numbers



void primeNum(int a , int b);

int main()
{

	primeNum(1,20);
}

void primeNum(int a , int b)
{
	int i;
	if(a==1)
		printf("%d",a);
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
