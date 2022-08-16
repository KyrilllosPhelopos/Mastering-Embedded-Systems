/*
 * linked_list.h
 *
 *  Created on: Aug 15, 2022
 *      Author: phelp
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "conio.h"


#define DPRINTF(...) 		{fflush(stdout);fflush(stdin);\
							printf(__VA_ARGS__);\
							fflush(stdout);fflush(stdin);}

struct Sdata
{
	int ID;
	char name[40];
	float height;
};

struct SStudent
{
	struct Sdata student;
	struct SStudent* Ptr_nextStudent;
};


/*********************************************************
 * 						Linked List APIS
 * ******************************************************/
void fill_the_record(struct SStudent* ptr);
void addStudent();
int deleteStudent();
void deleteAll();
void viewStudents();
void print_Nth();
int list_Length();
void list_reverse();


#endif /* LINKED_LIST_H_ */
