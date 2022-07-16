/*
 * ex8.c
 *
 *  Created on: Jul 16, 2022
 *      Author: phelp
 */

// Simple calculator

#include<stdio.h>

int main()
{
char operator;
int x , y;
printf("Enter Operator + or - or * or / : ");
fflush(stdout);
scanf("%c", &operator);
printf("Enter two operands: ");
fflush(stdout);
scanf("%d %d ", &x, &y);

fflush(stdout);
switch(operator)
{
case '+' :
printf("%d + %d = %d",x, y ,x+y );
break;

case '-' :
printf("%d - %d = %d",x, y ,x-y );
break;

case '*' :
printf("%d * %d = %d",x, y ,x*y );
break;

case '/' :
printf("%d / %d = %d",x, y ,x/y );
break;



}
}
