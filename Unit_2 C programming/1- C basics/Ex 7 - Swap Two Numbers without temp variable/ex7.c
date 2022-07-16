/*
 * ex7.c
 *
 *  Created on: Jul 16, 2022
 *      Author: phelp
 */

/*
 * EX7:
it is an interview trick

Write Source Code to Swap Two Numbers without temp variable.
 *
 */

#include<stdio.h>

int main ()
{
int a , b;

printf("Enter value of a: ");
fflush(stdout);
scanf("%d", &a);

printf("Enter value of b: ");
fflush(stdout);
scanf("%d", &b);


a = a+b;
b = a- b ;
a = a - b;

printf("After swapping, value of a = %d \n", a);
printf("After swapping, value of b = %d", b);

}
