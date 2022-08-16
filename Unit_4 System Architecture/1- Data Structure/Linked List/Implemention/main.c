/*
 * main.c
 *
 *  Created on: Aug 15, 2022
 *      Author: phelp
 */

#include<stdio.h>
#include"linked_list.h"

int main()
{
	char temp_text[10];
	int id = 2020;

	while(1)
	{
		DPRINTF("\n==================================\n");
		DPRINTF("\n \t choose one of the following options\n");
		DPRINTF("\n 1- Add_Student ");
		DPRINTF("\n 2- Delete_Student ");
		DPRINTF("\n 3- Delete_all ");
		DPRINTF("\n 4- View_Students");
		DPRINTF("\n 5- Find List Length ");
		DPRINTF("\n 6- print the Nth node");
		DPRINTF("\n 7- Reverse the list");
		DPRINTF("\n 8- exit\n");

		gets(temp_text);

		switch(atoi(temp_text))
		{
		case 1:
			addStudent();
			break;
		case 2:
			deleteStudent(id);
			break;
		case 3:
			deleteAll();
			DPRINTF("ALL Data Deleted Successfully\n");
			break;
		case 4:
			viewStudents();
			break;
		case 5:
			DPRINTF("The List Length = %d",list_Length());
			break;
		case 6:
			print_Nth();
			break;
		case 7:
			list_reverse();
			break;
		case 8:
			return 0;
			break;
		default :
			continue;


		}
	}




}
