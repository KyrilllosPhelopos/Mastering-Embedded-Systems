/*
 * ex4.c
 *
 *  Created on: Jul 25, 2022
 *      Author: phelp
 */

// Array of structs
#include<stdio.h>

struct S_student{

	char m_name[50];
	int m_rollNum ;
	float m_GPA ;
};

int main()
{
	struct S_student ArrStudents [4];

	for(int i =0;i<4;i++)
	{
		printf("Enter %d student data (^_^)",i+1);
		printf("\nName: ");
		fflush(stdout);
		gets(ArrStudents[i].m_name);
		fflush(stdin);
		printf("roll: ");
		fflush(stdout);
		scanf("%d",&ArrStudents[i].m_rollNum);
		fflush(stdin);
		printf("GPA: ");
		fflush(stdout);
		scanf("%f",&ArrStudents[i].m_GPA);
		fflush(stdin);
		printf("*******************************************\n");
		fflush(stdout);
	}

	for(int i=0;i<4;i++)
	{
		printf("Displaying information of student %d\n",i+1);
		printf("Name: %s\n",ArrStudents[i].m_name);
		printf("Roll: %d\n",ArrStudents[i].m_rollNum);
		printf("GPA: %0.2f\n",ArrStudents[i].m_GPA);

	}
}
