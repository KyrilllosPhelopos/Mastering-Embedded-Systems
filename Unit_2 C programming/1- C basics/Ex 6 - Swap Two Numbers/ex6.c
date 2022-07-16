/*
 * ex6.c
 *
 *  Created on: Jul 16, 2022
 *      Author: phelp
 */


/*
 * Write Source Code to Swap Two Numbers

#########Console_output######
Enter value of a: 1.20
Enter value of b: 2.45

After swapping, value of a = 2.45
After swapping, value of b = 1.2
#############################
 */

#include<stdio.h>

int main()
{
float a, b;
printf("Enter value of a: ");
fflush(stdout);
scanf("%f", &a);

printf("Enter value of b: ");
fflush(stdout);
scanf("%f", &b);

float temp ;
temp = a;
a = b ;
b = temp;

printf("After swapping, value of a = %f \n", a);
printf("After swapping, value of b = %f", b);
}
