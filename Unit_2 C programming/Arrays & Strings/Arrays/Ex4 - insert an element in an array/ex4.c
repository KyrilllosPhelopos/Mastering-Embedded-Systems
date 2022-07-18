/*
 * ex4.c
 *
 *  Created on: Jul 18, 2022
 *      Author: phelp
 */

// insert number in array;

#include<stdio.h>

int main()
{
	int n, num, m;
	int arr[50];

	printf("Enter number of elements: ");
	fflush(stdout);
	scanf("%d",&n);


	printf("Enter elements: \n");
	fflush(stdout);

	for(int i =0;i<n ;i++)
	{
		scanf("%d ",&arr[i]);
		fflush(stdin);

	}



	printf("Enter element to be inserted: ");
	fflush(stdout);
	scanf("%d",&num);

	printf("Enter location to be in:");
	fflush(stdout);
	scanf("%d",&m);

	for(int i = n; i >= m ;i--)
	{
		arr[i] = arr[i-1];
	}

	arr[m-1]=num;

	for(int i =0; i<=n ;i++)
		{
			printf("\n%d ",arr[i]);
			fflush(stdout);
		}

}
