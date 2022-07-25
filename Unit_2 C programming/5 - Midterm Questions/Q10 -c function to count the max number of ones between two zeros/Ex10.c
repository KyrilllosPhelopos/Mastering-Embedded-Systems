/*
 ============================================================================
 Name        : Ex10.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

//c function to count the max number of ones between two zeros

int numberofOnes(int n)
{
	int count=0 , temp;
	int max=0;
	for( ; n > 0; n >>= 1 )
		{
			// if the rightmost bit is zero:
			if( n % 2 ==0 )
			{
				temp = n;// assign n to a temp var
				temp>>=1;
				count =0; // initialte count with 0
				while(temp % 2 )
				{
					count++;
					temp>>=1;
				}
				if(count > max)
					max = count;
			}

		}
	return max;
}

int main( void )
{
	printf("%d", numberofOnes(110));
	return 0;
}
