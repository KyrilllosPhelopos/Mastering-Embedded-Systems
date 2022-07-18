/*
 * ex3.c
 *
 *  Created on: Jul 18, 2022
 *      Author: phelp
 */

// find transpose of a matrix

#include<stdio.h>

int main()
{
	int arr[50][50];
	int Tarr[50][50];
	int n, m;

	printf("enter the number of rows of the matrix: ");
	fflush(stdout);
	scanf("%d",&n);
	fflush(stdin);
	printf("enter the number of cols of the matrix: ");
	fflush(stdout);
	scanf("%d",&m);
	fflush(stdout);



	for(int i =0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			//printf("Enter a%d%d: ",i+1,j+1);
			//fflush(stdout);
			scanf("%d",&arr[i][j] );
			//fflush(stdin);
		}
	}

	printf("you entered: \n");
	fflush(stdout);

	for(int i =0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%d ",arr[i][j] );
		}
		printf("\n");
	}


	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			Tarr[j][i]=arr[i][j];
		}
	}


	printf("\n \nThe Transpose of the matrix: \n");

	for(int i =0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",Tarr[i][j] );
		}
		printf("\n");
	}
}
