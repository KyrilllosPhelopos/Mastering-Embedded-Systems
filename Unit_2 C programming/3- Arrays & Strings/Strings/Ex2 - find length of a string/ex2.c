/*
 * ex2.c
 *
 *  Created on: Jul 18, 2022
 *      Author: phelp
 */


// count length of string

#include<stdio.h>

int main()
{
char str[50], len =0;

printf("Enter string to find its length: ");
fflush(stdout);
gets(str);

for(int i=0;str[i] != '\0';i++)
{
len++;
}
printf("Length = %d",len);
}
