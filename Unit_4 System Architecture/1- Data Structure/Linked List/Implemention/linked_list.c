/*
 * linked_list.c
 *
 *  Created on: Aug 15, 2022
 *      Author: phelp
 */

#include"linked_list.h"

// Global pointer to the head of the linked list
struct SStudent* gpFirstStudent = 0;


/*******************************************************************
 * 				fill_the_record()
 * function to get the required data to store it in the linked list
 *******************************************************************/

void fill_the_record(struct SStudent *NewStudent)
{
	//array of chars to get inputs in it
	char temp_text[10];

	DPRINTF("Enter Student ID: ");
	gets(temp_text);
	NewStudent->student.ID = atoi(temp_text);

	DPRINTF("Enter Student Name: ");
	gets(NewStudent->student.name);

	DPRINTF("Enter Student Height: ");
	gets(temp_text);
	NewStudent->student.height = atof(temp_text);
}


/***************************************************************************
 * 			addStudent()
 * function to add the stored data node into the linked list
 ***************************************************************************/
void addStudent()
{
	struct SStudent* student;
	struct SStudent* Lstudent;//to use it as a pointer to the last node

	// if it will be the first node in the list
	if(gpFirstStudent ==0)
	{
		student = (struct SStudent*)malloc(sizeof(struct SStudent));
		gpFirstStudent = student;
	}

	else
	{
		Lstudent = gpFirstStudent;
		while(Lstudent->Ptr_nextStudent)//loop to get to the last node
			Lstudent = Lstudent->Ptr_nextStudent;
		student = (struct SStudent*) malloc(sizeof(struct SStudent));
		Lstudent->Ptr_nextStudent = student;
	}
	student->Ptr_nextStudent = 0;
	fill_the_record(student);

}

/***********************************************************
 *			deleteStudent()
 *	function to delete student according to its id
 * ***********************************************************/
int deleteStudent()
{
	if(! gpFirstStudent)
	{
		DPRINTF("There are no data in the list\n");
		return 0;
	}

	char temp_text[10];
	unsigned int id;

	// Get the selected ID from the user
	DPRINTF("\nEnter Student ID to be deleted: ");
	gets(temp_text);
	id = atoi(temp_text);

	struct SStudent* PrevStudent = 0;
	struct SStudent* CurrentStudent = gpFirstStudent;


	// if it is the first node in the list
	if(gpFirstStudent->student.ID == id)
	{
		gpFirstStudent = gpFirstStudent->Ptr_nextStudent;
		free(CurrentStudent);
		return 1;
	}

	else
	{
		while(CurrentStudent)
		{

			if(CurrentStudent->student.ID == id)
			{
				PrevStudent->Ptr_nextStudent = CurrentStudent->Ptr_nextStudent;
				free(CurrentStudent);
				return 1;
			}
			else
			{
				PrevStudent = CurrentStudent;
				CurrentStudent = CurrentStudent->Ptr_nextStudent;
			}

		}
		return 0;
	}



}

/*************************************************************
 * 					deleteAll()
 * function to delete the whole linked list
 ********************************************************* */
void deleteAll()
{
	struct SStudent* Ptr_Student = gpFirstStudent ;
	struct SStudent* temp;
	while(Ptr_Student)
	{
		temp = Ptr_Student;
		Ptr_Student = Ptr_Student->Ptr_nextStudent;
		free(temp);
	}
	gpFirstStudent =0;
}

/*************************************************************
 * 					viewStudents()
 * function to print the whole linked list data
 ********************************************************* */
void viewStudents()
{
	if(gpFirstStudent == 0)
	{
		DPRINTF("There are no data to be printed\n");
		return;
	}
	struct SStudent* Ptr_Student = gpFirstStudent;
	int i=0;

	while(Ptr_Student)
	{
		DPRINTF("========================================================\n");
		DPRINTF("Node:%d Data\n",++i);
		DPRINTF("Student Name: %s\n",Ptr_Student->student.name);
		DPRINTF("Student ID: %d\n",Ptr_Student->student.ID);
		DPRINTF("Student Height: %f\n",Ptr_Student->student.height);
		Ptr_Student = Ptr_Student->Ptr_nextStudent;

	}

}


/***********************************************
 * 					list_Length()
 * function to find the length the list
 ************************************************** */

int list_Length()
{
	if(gpFirstStudent == 0)
	{
		return 0;
	}
	else
	{
		int counter = 0;
		struct SStudent* Ptr_Student = gpFirstStudent;
		while(Ptr_Student)
		{
			counter++;
			Ptr_Student=Ptr_Student->Ptr_nextStudent;
		}
		return counter;

	}
}

/***********************************************
 * 					print_Nth()
 * function to print the Nth node in the list
 ************************************************** */
void print_Nth()
{
	if(gpFirstStudent == 0)
	{
		DPRINTF("There are no data to be printed\n");
		return;
	}

	// Get the selected ID from the user
	char temp_text[10];
	unsigned int n , counter ;
	struct SStudent* Ptr_Student = gpFirstStudent;
	DPRINTF("\nEnter number of the node to print its data: ");
	gets(temp_text);
	n = atoi(temp_text);

	if( n > list_Length())
	{
		DPRINTF("ERROR!!!!! the list is too small to compared to the entered number\n");
		return ;
	}
	while(Ptr_Student)
	{
		counter++;
		if( n == counter)
		{
			DPRINTF("========================================================\n");
			DPRINTF("Node:%d Data\n",n);
			DPRINTF("Student Name: %s\n",Ptr_Student->student.name);
			DPRINTF("Student ID: %d\n",Ptr_Student->student.ID);
			DPRINTF("Student Height: %f\n",Ptr_Student->student.height);
			return;

		}
		Ptr_Student=Ptr_Student->Ptr_nextStudent;
	}

}

/***********************************************
 * 					list_reverse()
 * function to reverse the linked list
 ************************************************** */

void list_reverse()
{
	if(gpFirstStudent == 0)
		{
			DPRINTF("There are no data in the list\n");
			return;
		}
	struct SStudent* ptr1 = gpFirstStudent;
	struct SStudent* ptr2 = ptr1->Ptr_nextStudent;
	struct SStudent* ptr3 = ptr2->Ptr_nextStudent;

	//put the next of the first node to be null
	ptr1->Ptr_nextStudent = 0;

	while(ptr2)
	{
		ptr2->Ptr_nextStudent = ptr1;
		ptr1=ptr2;
		ptr2=ptr3;
		if(ptr3)//check if ptr3 doesnot become null
			ptr3=ptr3->Ptr_nextStudent;

	}
	gpFirstStudent = ptr1;
	DPRINTF("List Reversed Successfully\n");


}
