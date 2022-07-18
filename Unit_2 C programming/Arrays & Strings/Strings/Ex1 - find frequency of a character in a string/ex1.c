/*
 * ex1.c
 *
 *  Created on: Jul 18, 2022
 *      Author: phelp
 */

// find frequency of a specific character in a string

#include<stdio.h>

int main()

{
char str [50],c,counter=0;

printf("Enter a string: ");
fflush(stdout);
gets(str);

printf("Enter character to find its frequency: ");
fflush(stdout);

scanf("%c",&c);

for(int i =0;str[i]!='\0';i++)
{
if(str[i]==c)
	counter++;
}

printf("Frequency of %c = %d",c,counter);
}
