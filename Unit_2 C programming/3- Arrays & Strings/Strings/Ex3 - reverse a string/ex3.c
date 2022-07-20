/*
 * ex3.c
 *
 *  Created on: Jul 18, 2022
 *      Author: phelp
 */


// reverse string

#include<stdio.h>
#include<string.h>

int main()
{
char str [50], l=0 , h , temp;

printf("Enter string: ");
fflush(stdout);
gets(str);

 h = strlen(str) -1;

 while(h>l)
 {
	 temp = str[l];
	 str[l] = str[h];
	 str[h]=temp;
	 l++;h--;
 }
 printf("Reversed string: %s",str);
}
