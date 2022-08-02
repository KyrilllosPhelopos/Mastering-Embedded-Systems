/*
 * ex4.c
 *
 *  Created on: Aug 2, 2022
 *      Author: Kyrillos Sawiris
 */


//Write a program in C to print the elements of an array in reverse order.

#include<stdio.h>

int main()
{
int arr [5];
int* ptr ;

printf("Input 5 number of elements in the array :\n");

for(int i =0;i<5;i++)
{
	printf("Enter element- %d: \n" , i+1);
	fflush(stdout);
	scanf("%d", &arr[i]);

}

ptr = arr;

printf("The elements of array in reverse order are :\n");
fflush(stdout);

for(int i =4 ; i>=0;i--)
{
	printf("element -%d : %d\n" ,  i, *(ptr+i));
}
}
