/*
 ============================================================================
 Name        : Ex4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

//c function to revere digits in number

int reverseNum(int x)
{
	int temp , reversed =0;
	while(x>0)
	{
		reversed *=10;
		temp = x%10;
		reversed += temp;
		x = x/10;
	}
	return reversed;
}

int main(void) {
printf("%d",reverseNum(1075));
}
