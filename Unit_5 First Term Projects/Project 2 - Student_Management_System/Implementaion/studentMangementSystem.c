/*
 * studentMangementSystem.c
 *
 *  Created on: Aug 21, 2022
 *      Author: phelp
 */

#include"studentMangementSystem.h"

// Enter student data form file

FILE *fp ;
void add_student_from_file(FIFO_Buf_t *students_queue)
{

	fp = fopen("Students_Data.txt", "r");
	if(fp == 0)
	{
		Dprintf("Error!!!! Cannot open the file \n");
		return ;
	}

	Item new_Student;

	while(!feof(fp))
	{
		fscanf(fp , "%d",&new_Student.roll_number);

		int num = new_Student.roll_number;
		Item temp;
		if (FIFO_Search_With_Roll(students_queue ,&temp , num ) == 1)
		{
			Dprintf("Error!!!! Failed >>(Repeated Roll_No: %d) \n", num);

			// Ignore the rest of the line
			fscanf(fp, "%*[^\n]");

			// Start over form next line in text file
			continue ;
		}

		fscanf(fp , "%s" , new_Student.first_name);
		fscanf(fp , "%s" , new_Student.last_name);
		fscanf(fp , "%f" , &new_Student.GPA);
		for(int i =0 ;i< COURSES_NUMBER ;i++)
		{
			fscanf(fp , "%d" ,& new_Student.course_id[i]);
		}

		if((FIFO_Enqueue(students_queue ,  new_Student) == FIFO_NO_ERROR))
		{

			Dprintf("Student: %d added successfully \n" , new_Student.roll_number);
		}
		else
		{
			Dprintf("Student: %d Failed to be added  \n" , new_Student.roll_number)
		}

	}
	fclose(fp);
}


// Enter student data manually from console
void add_student_manualy(FIFO_Buf_t *students_queue)
{
	Item new_Student;
	Dprintf("Enter Student Roll Number: \n");
	scanf("%d",&new_Student.roll_number);
	int num = new_Student.roll_number;
	Item temp;
	if (FIFO_Search_With_Roll(students_queue ,&temp , num ) == 1)
	{

		Dprintf("Error!!!! Failed >>(Repeated Roll_No: %d) \n", num);
		return ;
	}
	Dprintf("Enter Student First Name: \n");
	scanf("%s",new_Student.first_name);
	Dprintf("Enter Student Last Name: \n");
	scanf("%s",new_Student.last_name);

	Dprintf("Enter Student GPA: \n");
	scanf("%f",&new_Student.GPA);

	for(int i =0 ; i < COURSES_NUMBER ;i++)
	{
		Dprintf("Enter Student course: %d ID \n",i+1);
		scanf( "%d",& new_Student.course_id[i]);

	}
	if((FIFO_Enqueue(students_queue ,  new_Student) == FIFO_NO_ERROR))
	{
		Dprintf("Student: %d added successfully \n" , new_Student.roll_number);
	}
	else
	{
		Dprintf("Student: %d Failed to be added  \n" , new_Student.roll_number)
	}
}

// Get student date by its roll number
void find_student_by_roll(FIFO_Buf_t *students_queue)
{
	int num = 0;
	Dprintf("Enter Student Roll Number: \n");
	scanf("%d",&num);

	Item Temp_item;
	if (FIFO_Search_With_Roll(students_queue , &Temp_item , num) == 1)
	{
		Dprintf("Student with Roll_No: %d Exists in the list \n",num);
		Dprintf("Student Name: %s %s \n",Temp_item.first_name , Temp_item.last_name);
		Dprintf("Student GPA: %0.2f \n",Temp_item.GPA);
		Dprintf("Student Courses IDs: ");
		for(int i = 0 ;i<COURSES_NUMBER ;i++)
		{
			Dprintf(" %d,",Temp_item.course_id[i]);
		}
	}
	else
		Dprintf("Student with Roll_No: %d DOESNOT Exist in the list \n",num);

}

// Get student date by its first name
void find_student_by_firstname(FIFO_Buf_t *students_queue)
{

	char temp [20];
	Item Temp_item;
	Dprintf("Enter Student First Name: \n");
	scanf("%s",temp);
	if(FIFO_Search_With_Fname(students_queue , & Temp_item , temp))
	{
		Dprintf("Student with First Name: %s Exists in the list \n",Temp_item.first_name);
		Dprintf("Student Name: %s %s \n",Temp_item.first_name , Temp_item.last_name);
		Dprintf("Student Roll_No: %d \n",Temp_item.roll_number);
		Dprintf("Student GPA: %0.2f \n",Temp_item.GPA);
		Dprintf("Student Courses IDs: ");
		for(int i = 0 ;i<COURSES_NUMBER ;i++)
		{
			Dprintf(" %d,",Temp_item.course_id[i]);
		}
	}
	else
		Dprintf("Student with First Name: %s DOESNOT Exist in the list \n",temp);
}

//int Search_By_Courese(FIFO_Buf_t* queue ,FIFO_DATA_TYPE* item ,int arr [])
//{
//	FIFO_DATA_TYPE * temp = queue->tail;
//	int i=0 , flag=0;
//	while(i<queue->count)
//	{
//		for(int i =0 ;i<queue->count ;i++)
//		{
//			if(arr[i] != temp->course_id[i])
//			{
//				flag =0;
//				break;
//			}
//			else
//			{
//				flag = 1;
//			}
//
//		}
//
//		if(flag)
//		{
//			*item = *temp;
//			return 1;
//		}
//
//		else
//			temp--;
//
//	}
//
//	return 0;
//}

// Get student date by its course
void find_student_by_course(FIFO_Buf_t *students_queue)
{
	int arr [5];
	Dprintf("Enter Student Courses: \n");
	for(int i = 0;i<5 ;i++)
	{
		scanf("%d",&arr[i]);
	}





	FIFO_DATA_TYPE * temp = students_queue->tail --;
	int k=0 , flag=0;
	while(k <= students_queue->count)
	{
		for(int i =0 ;i<COURSES_NUMBER ;i++)
		{
			if(arr[i] != temp->course_id[i])
			{
				flag =0;
			}
			else
			{
				flag = 1;
			}
		}

		if(flag == 1)
		{
			Dprintf("Student  with Courses IDs: ");
			for(int i = 0 ;i<5 ;i++)
			{
				Dprintf(" ,%d",temp->course_id[i]);
			}
			Dprintf(" Exist in the list\n");
			Dprintf("Student Name: %s %s \n",temp->first_name , temp->last_name);
			Dprintf("Student Roll_No: %d \n",temp->roll_number);
			Dprintf("Student GPA: %0.2f \n",temp->GPA);
			Dprintf("====================================== \n");
		}

		temp--;
		k++;

	}

}

// Get students number in queue
void print_students_count(FIFO_Buf_t *students_queue)
{
	Dprintf("The number of students in the list is: %d",students_queue->count );
}

// Delete student from the queue
void delete_student_by_roll(FIFO_Buf_t *students_queue)
{
	int num = 0;
	Dprintf("Enter Student Roll Number: \n");
	scanf("%d",&num);
	Item* temp = students_queue->head;
	int i=0 , flag =0;
	for( ;i<students_queue->count ;i++)
	{
		if(temp[i].roll_number == num)
		{
			flag =1;
			students_queue->count--;
			for(int j = i ; j< students_queue->count ; j++)
			{
				temp[j]= temp[j+1];
			}

			break;
		}
	}
	if(flag ==1)
	{

		if(students_queue->tail == students_queue->base)
			students_queue->tail = (students_queue->base + (students_queue->length *sizeof(FIFO_DATA_TYPE)));
		else
			students_queue->tail--;

		Dprintf("Deleted Successfully \n");

	}


}

// Update a specific data in queue
void update_student_by_roll(FIFO_Buf_t *students_queue)
{
	int num = 0;
	Dprintf("Enter Student Roll Number: \n");
	scanf("%d",&num);

	Item* temp =students_queue->head ;
	Item student;
	for( int i=0;i<students_queue->count ;i++)
	{
		if(temp[i].roll_number == num)
		{
			Dprintf("Enter Student Roll Number: \n");
			scanf("%d",&student.roll_number);
			Dprintf("Enter Student First Name: \n");
			scanf("%s",temp[i].first_name);
			Dprintf("Enter Student Last Name: \n");
			scanf("%s",temp[i].last_name);

			Dprintf("Enter Student GPA: \n");
			scanf("%f",&student.GPA);

			for(int j =0 ; j < COURSES_NUMBER ;j++)
			{
				Dprintf("Enter Student course: %d ID \n",i+1);
				scanf( "%d",& student.course_id[j]);
				temp[i].course_id[j]= student.course_id[j];

			}

			temp[i].roll_number= student.roll_number;
			temp[i].GPA = student.GPA;

			Dprintf("Updated Successfully \n");
			return ;
		}

	}

	Dprintf("Failed To Update \n");


}


// View students data
void view_all(FIFO_Buf_t *students_queue)
{
	if (! students_queue ||! students_queue->base || ! students_queue->head || ! students_queue->tail)
	{
		printf("FIFO IS NULL\n");
		return;
	}
	else if(students_queue->count == 0)
	{
		printf("FIFO IS EMPTY \n");
		return;
	}
	FIFO_DATA_TYPE * temp;
	temp = students_queue->head;
	for(int i = 0;i< students_queue->count;i++)
	{
		Dprintf("Student Name: %s %s \n",temp->first_name , temp->last_name);
		Dprintf("Student Roll_No: %d \n",temp->roll_number);
		Dprintf("Student GPA: %0.2f \n",temp->GPA);
		Dprintf("Student Courses IDs: ");
		for(int i = 0 ;i<5 ;i++)
		{
			Dprintf(" %d,",temp->course_id[i]);
		}
		Dprintf("\n");
		Dprintf("=============================================== \n")
		if(temp == (students_queue->base + (students_queue->length *sizeof(FIFO_DATA_TYPE))))
			temp= students_queue->base;
		else
			temp++;
	}
}






int FIFO_Search_With_Roll(FIFO_Buf_t* students_queue ,Item* item ,int n)
{
	FIFO_DATA_TYPE * temp = students_queue->tail;
	int i=0;
	while(i < students_queue->count)
	{
		if(temp->roll_number == n)
		{
			*item = *temp;
			return 1;
		}
		temp--;
		i++;
	}

	return 0;
}

int FIFO_Search_With_Fname(FIFO_Buf_t* students_queue ,Item* item ,char str [])
{
	FIFO_DATA_TYPE * temp = students_queue->tail;
	int i=0;
	while(i<students_queue->count)
	{
		if( ! strcmp(temp->first_name , str))
		{
			*item =* temp;
			return 1;
		}
		temp--;
		i++;
	}

	return 0;
}








