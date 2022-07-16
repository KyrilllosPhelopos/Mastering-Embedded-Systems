/*
 * ex3.c
 *
 *  Created on: Jul 16, 2022
 *      Author: Kyrillos Sawiris
 */

/*
 * EX4:

		Write C Program to Multiply two Floating Point Numbers
		i should see the Console as following:

				##########Console-output###

				###########################
				Enter two numbers: 2.4
				1.1
				Product: 2.640000
 */

#include<stdio.h>

int main()
{
float x , y;
printf("Enter two numbers: ");
fflush(stdout);
scanf("%f %f",&x , &y );

printf("Product: %f", (x*y));
}


