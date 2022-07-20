/*
 * ex3.c
 *
 *  Created on: Jul 20, 2022
 *      Author: phelp
 */

// reverse sentence using recursion

#include<stdio.h>
#include"string.h"


void reverseString(char str[] , char len , char i);

int main()
{
	char str [100] , len;
	printf("Enter a sentence: ");
	fflush(stdout);
	gets(str);
	len = strlen(str);
	reverseString(str , len ,0);
}

void reverseString(char str[] , char len , char i)
{
	if (i >len)
	{
		return;
	}

	else
	{
		reverseString(str ,len , ++i);
		printf("%c",str[i-2]);
	}
}
