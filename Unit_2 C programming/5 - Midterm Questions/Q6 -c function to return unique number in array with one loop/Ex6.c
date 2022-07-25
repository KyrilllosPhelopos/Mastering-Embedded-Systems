/*
 ============================================================================
 Name        : Ex6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

//c function to return unique number in array with one loop

int uniqueElement(int arr [] , int n , int x)
{

//	//static int counter = 0;
//	if(x>=n)
//		return -1 ;
//	int unique = arr[x];
//	int i , flag=1;
//	for(i=0;i<n-1;i++)
//	{
//		if(arr[i]==unique && i!=x)
//		{
//		flag =0;
//		uniqueElement(arr,n , x++);
//		}
//	}
//	if(flag)
//		return arr[x];
//	else
//		return -1;


	/*
	 * using frequency array
	 */

	int count , j , freq[100];

	for(int i=0; i<n; i++)
	    {
	        count = 1;
	        for(j=i+1; j<n; j++)
	        {
	            if(arr[i] == arr[j])
	            {
	                count++;
	                freq[j] = 0;
	            }
	        }

	        if(freq[i] != 0)
	        {
	            freq[i] = count;
	        }
	    }
	    for(int i=0; i<n; i++)
	    {
	        if(freq[i] == 1)
	        {
	            return arr[i];
	        }
	    }}
int main(void) {
	int arr[5]={4,2,4,5,5};
	printf("\nUnique element in the array is: %d", uniqueElement(arr,5,0));
}
