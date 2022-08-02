/*
 * ex5.c
 *
 *  Created on: Aug 2, 2022
 *      Author: phelp
 */

// Write a program in C to show a pointer to an array which contents are pointer to structure.

#include<stdio.h>

struct employee
{
char name [50];
int id;
} ;;

int main()
{
	struct employee emp1 = {"Kyrillos" , 100} , emp2 = {"Sawiris" , 300};
	struct employee* arr[] = {&emp1 , &emp2};
	struct employee* (*ptr )[2] = &arr;

		printf(" Employee Name : %s \n",(*(*ptr ))->name);
		printf(" Employee ID :  %d \n",(*(*ptr ))->id);

		fflush(stdout);


	}

