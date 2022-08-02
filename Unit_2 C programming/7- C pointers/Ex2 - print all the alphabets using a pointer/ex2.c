/*
 * ex2.c
 *
 *  Created on: Aug 2, 2022
 *      Author: Kyrillos Sawiris
 */

#include<stdio.h>

int main()
{
char ch = 'A';
char* ptr = &ch;
printf("The Alphabets are :\n");
fflush(stdout);
for(int i=0; i <26;i++)
{
printf("%c ",*ptr + i);

}
}

