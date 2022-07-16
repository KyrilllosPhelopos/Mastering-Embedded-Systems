/*
 * ex2.c
 *
 *  Created on: Jul 16, 2022
 *      Author: Kyrillos Sawiris
 */

/*EX2:

	Write C Program to Print a Integer Entered by a User
	i should see the Console as following:
				##########Console-output###
				Enter an integer: 25
				You entered: 25
				###########################

*/

#include<stdio.h>

int main ()

{
int num ;
printf("Enter an integer: ");
fflush(stdout);
scanf("%d",&num );
fflush(stdout);

printf("You entered: %d",num);

}




