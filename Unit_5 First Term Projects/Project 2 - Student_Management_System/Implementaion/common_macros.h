/*
 * common_macros.h
 *
 *  Created on: Aug 21, 2022
 *      Author: phelp
 */

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_


#include<stdio.h>

#define Dprintf(...)	{fflush(stdout); fflush(stdin);\
						printf(__VA_ARGS__);\
						fflush(stdout); fflush(stdin);}


typedef struct student_info Item;
#define NAME_LENGTH 20
#define COURSES_NUMBER 5
#define FIFO_DATA_TYPE Item

/*
 * student structure
 */

struct student_info {
	char first_name[NAME_LENGTH];
	char last_name[NAME_LENGTH];
	int roll_number;
	float GPA;
	int course_id[COURSES_NUMBER];
};

typedef struct{
	unsigned int length ;
	unsigned int count;
	FIFO_DATA_TYPE * base;
	FIFO_DATA_TYPE * head;
	FIFO_DATA_TYPE * tail;
}FIFO_Buf_t;


typedef enum
{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL
}E_FIFO_Status;

#endif /* COMMON_MACROS_H_ */
