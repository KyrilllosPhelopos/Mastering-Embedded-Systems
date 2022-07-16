/*
 * ex3.c
 *
 *  Created on: Jul 16, 2022
 *      Author: Kyrillos Sawiris
 */

/*
 * EX3:

	Write C Program to Add Two Integers

	i should see the Console as following:
			##########Console-output###
			Enter two integers: 12
			11
			Sum: 23
			###########################
 *
 */

#include<stdio.h>

int main()
{
int i , j;
printf("Enter two integers: ");
fflush(stdout);

scanf("%d %d ",&i, &j);

fflush(stdin);

printf("Sum: %d", i+j);

}
