/*
 * ex5.c
 *
 *  Created on: Jul 16, 2022
 *      Author: phelp
 */


// check whether the character is Alphabet or not

#include<stdio.h>

int main()
{
char c ;
printf("Enter character to check: ");
fflush(stdout);
scanf("%c",&c);
if((c>= 'a'&& c<='z') || (c>= 'A'&& c<='Z'))
	printf("%c is an Alphabet", c);
else
	printf("%c is Not an Alphabet", c);
}
