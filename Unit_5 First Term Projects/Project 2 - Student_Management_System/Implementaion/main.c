/*
 * main.c
 *
 *  Created on: Aug 22, 2022
 *      Author: Kyrillos Sawiris
 */


#include<stdio.h>

#include"studentMangementSystem.h"
#include"fifo.h"


int main()
{
	char temp_text[10];


	FIFO_Buf_t students_queue;
	struct student_info buf [100];
	FIFO_init(&students_queue ,buf , 100);

	while(1)
	{
		Dprintf("\n ================================== \n");
		Dprintf("\n \t choose one of the following options\n");
		Dprintf("\n 1- add_student_from_file ");
		Dprintf("\n 2- add_student_manualy ");
		Dprintf("\n 3- find_student_by_roll ");
		Dprintf("\n 4- find_student_by_firstname");
		Dprintf("\n 5- find_student_by_course");
		Dprintf("\n 6- print_students_count");
		Dprintf("\n 7- delete_student_by_roll");
		Dprintf("\n 8- update_student_by_roll");
		Dprintf("\n 9- view_all");
		Dprintf("\n 10- exit\n");

		gets(temp_text);

		switch(atoi(temp_text))
		{
		case 1:
			add_student_from_file(&students_queue);
			break;
		case 2:
			add_student_manualy(&students_queue);
			break;
		case 3:
			find_student_by_roll(&students_queue);
			break;
		case 4:
			find_student_by_firstname(&students_queue);
			break;
		case 5:
			find_student_by_course(&students_queue);
			break;
		case 6:
			print_students_count(&students_queue);
			break;
		case 7:
			delete_student_by_roll(&students_queue);
			break;
		case 8:
			update_student_by_roll(&students_queue);
			break;
		case 9:
			view_all(&students_queue);
			break;
		case 10:
			return 0;
			break;
		default :
			continue;


		}
	}




}
