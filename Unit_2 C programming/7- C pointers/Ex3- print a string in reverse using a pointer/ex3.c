/*
 * ex3.c
 *
 *  Created on: Aug 2, 2022
 *      Author: Kyrillos Sawiris
 */

#include<stdio.h>
#include<string.h>


int main()
{
char str [50] , revered [50];
char* ptrstr , *ptr_reversed;

printf("Input a string: ");
fflush(stdout);
gets(str);

int i = strlen(str) -1;


ptr_reversed = revered;

while( i > 0)
{
	ptrstr =str  + i;
	*ptr_reversed++ = *ptrstr;
	i--;
}

*ptr_reversed = '\0';

printf("Reverse of the string is : %s",revered );

}

