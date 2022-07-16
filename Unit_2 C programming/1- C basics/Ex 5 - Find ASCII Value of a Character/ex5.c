/*
 * ex5.c
 *
 *  Created on: Jul 16, 2022
 *      Author: phelp
 */


/*
 * EX5:

Write C Program to Find ASCII Value of a Character

#########Console_output######
Enter a character: G
ASCII value of G = 71
 */

#include<stdio.h>

int main()
{
	char c;
printf("Enter a character: ");
fflush(stdout);
scanf("%c", &c);
printf("ASCII value of %c = %d",c,c );
}
