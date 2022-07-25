/*
 * Ex1.c
 *
 *  Created on: Jul 25, 2022
 *      Author: phelp
 */

// struct to store student info

#include<stdio.h>

struct S_student{

	char m_name[50];
	int m_rollNum ;
	float m_GPA ;
};

int main()
{
	struct S_student s1;
	printf("Enter information of student:");
	printf("\nName: ");
	fflush(stdout);
	gets(s1.m_name);
	printf("roll: ");
	fflush(stdout);
	scanf("%d",&s1.m_rollNum);
	printf("GPA: ");
	fflush(stdout);
	scanf("%f",&s1.m_GPA);

printf("#####################################\n");
printf("Displaying information\n");
printf("Name: %s\n",s1.m_name);
printf("Roll: %d\n",s1.m_rollNum);
printf("GPA: %0.2f\n",s1.m_GPA);

}
