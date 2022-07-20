/*
 * ex5.c
 *
 *  Created on: Jul 18, 2022
 *      Author: phelp
 */

// search for an element in the array

# include<stdio.h>

int main()
{
	int arr[10],n,element;

	printf("Enter the no of elements in the array\n");
	fflush(stdout);
	scanf("%d",&n);
	printf("Enter elements\n");
	fflush(stdout);
	for(int i=0;i<n ; i++)
	{
		scanf("%d",&arr[i]);
	}
	fflush(stdout);
	fflush(stdin);
	printf("Enter element you want to search for: ");
	fflush(stdout);
	scanf("%d",&element);

	for(int i=0 ;i<n;i++)
	{
		if(arr[i]== element)
		{
			printf("Number found at location: %d",i);
			return 0;

		}
	}

	printf("element not founded");
}
