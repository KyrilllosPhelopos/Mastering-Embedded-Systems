/*
 * ex7.c
 *
 *  Created on: Jul 16, 2022
 *      Author: phelp
 */

// Find Factorial of an integer

#include<stdio.h>

int main()
{
	int factorial=1 , n;
	printf("Enter integer you want to find its factorial: ");
	fflush(stdout);
	scanf("%d",&n);
	if (n <0)
	{
		printf("Error!!! factorial of negative numbers are not allowed ");
	}
	else
	{
		for(int i =1 ; i<=n ; i++)
			factorial *=i;
		printf("Factorial = %d" , factorial);
	}


}
