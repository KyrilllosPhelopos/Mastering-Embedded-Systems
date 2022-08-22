/*
 * studentMangementSystem.h
 *
 *  Created on: Aug 21, 2022
 *      Author: Kyrillos Sawiris
 */

#ifndef STUDENTMANGEMENTSYSTEM_H_
#define STUDENTMANGEMENTSYSTEM_H_


#include<stdio.h>
#include <string.h>
#include"fifo.h"
#include"common_macros.h"

// Data type of buffer item



/*******************************************************
 * 						APIS
 *************************************************** */


int FIFO_Search_With_Fname(FIFO_Buf_t* queue ,FIFO_DATA_TYPE* item ,char str []);
int FIFO_Search_With_Roll(FIFO_Buf_t* queue ,Item* item ,int n);


// Enter student data form file
void add_student_from_file(FIFO_Buf_t *students_queue);

// Enter student data manually from console
void add_student_manualy(FIFO_Buf_t *students_queue);

// Get student date by its roll number
void find_student_by_roll(FIFO_Buf_t *students_queue);

// Get student date by its first name
void find_student_by_firstname(FIFO_Buf_t *students_queue);

// Get student date by its course
void find_student_by_course(FIFO_Buf_t *students_queue);

// Get students number in queue
void print_students_count(FIFO_Buf_t *students_queue);

// Delete student from the queue
void delete_student_by_roll(FIFO_Buf_t *students_queue);

// Update a specific data in queue
void update_student_by_roll(FIFO_Buf_t *students_queue);

// View students data
void view_all(FIFO_Buf_t *students_queue);



#endif /* STUDENTMANGEMENTSYSTEM_H_ */
