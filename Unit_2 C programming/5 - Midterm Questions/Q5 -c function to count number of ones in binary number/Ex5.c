/*
 ============================================================================
 Name        : Ex5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

//c function to count number of ones in binary number

int countOnes(int x)
{
	int mask = 0b01;
	int count =0;
	int max =0;
	while(x >= mask)
	{

		if( (x&mask) )
			count++;
		mask<<=1;
	}
	return count;
}

int main(void) {

	printf("%d",countOnes(5));

}
