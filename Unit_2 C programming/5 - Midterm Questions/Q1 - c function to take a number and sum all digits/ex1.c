/*
 * ex1.c
 *
 *  Created on: Jul 24, 2022
 *      Author: phelp
 */

//c function to take a number and sum all digits

#include<stdio.h>

int sumNum(int num)
{
int temp , sum=0;
while(num>0)
{
temp = num%10;
sum+=temp;
num =num/10;
}
return sum;
}

int main()
{
	int x = 12345;
	printf("%d",sumNum(x));

}
