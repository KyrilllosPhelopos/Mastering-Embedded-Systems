/*
 * ex1.c
 *
 *  Created on: Jul 18, 2022
 *      Author: phelp
 */

// sum of two 2*2 (2d arrays)

#include<stdio.h>

int main()
{
int a [2][2];
int b [2][2];
int r [2][2];
printf("Enter ELements of 1st array \n");
fflush(stdout);

for(int i =0;i<2;i++)
{
	for(int j=0;j<2;j++)
	{
		printf("Enter a%d%d: ",i+1,j+1);
		fflush(stdout);
		scanf("%d",&a[i][j] );
		fflush(stdin);
	}
}

printf("\n \nEnter ELements of 2nd array \n");
fflush(stdout);

for(int i =0;i<2;i++)
{
	for(int j=0;j<2;j++)
	{
		printf("Enter a%d%d: ",i+1,j+1);
		fflush(stdout);
		scanf("%d",&b[i][j]);
		fflush(stdin);

	}
}

for(int i =0;i<2;i++)
{
	for(int j=0;j<2;j++)
	{
		r[i][j]=a[i][j]+b[i][j];
	}
}


printf("\n \nThe sum of the two matrices: \n");

for(int i =0;i<2;i++)
{
	for(int j=0;j<2;j++)
	{
		printf("%d ",r[i][j] );
	}
	printf("\n");
}



}
