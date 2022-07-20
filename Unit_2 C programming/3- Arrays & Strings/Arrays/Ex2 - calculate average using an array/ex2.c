/*
 * ex2.c
 *
 *  Created on: Jul 18, 2022
 *      Author: phelp
 */


// calculate average using an array

#include<stdio.h>

int main()
{
	float arr [50];
	float sum =0;
	int n;

	printf("Enter the number of data : ");
	scanf("%d",&n);
	for(int i=1 ; i<=n;i++)
	{
		printf("Enter a%d: ",i);
		fflush(stdout);
		scanf("%f",&arr[i-1] );
		fflush(stdin);
		sum +=arr[i-1];
	}

	printf("\n \nthe average of the 6 numbers is: %0.2f", sum/n);


}
