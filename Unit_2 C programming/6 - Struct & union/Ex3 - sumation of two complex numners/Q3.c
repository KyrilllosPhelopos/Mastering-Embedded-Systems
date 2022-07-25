/*
 ============================================================================
 Name        : Q3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

/*
 * ex3.c
 *
 *  Created on: Jul 25, 2022
 *      Author: phelp
 */
// sumation of two complex numners

#include<stdio.h>

struct S_complex
{
	float real ;
	float imag;
};

struct S_complex add(struct S_complex n1 , struct S_complex n2 );
int main()
{
	struct S_complex d1, d2 , res;

	printf("Enter 1st Number:");
	fflush(stdout);

	printf("\nEnter Real part: ");
	fflush(stdout);
	scanf("%f",&d1.real);
	fflush(stdin);

	printf("Enter imag part: ");
	fflush(stdout);

	scanf("%f",&d1.imag);

	fflush(stdin);

	printf("Enter 2nd Number:");
	printf("\nEnter Real part: ");
	fflush(stdout);
	scanf("%f",&d2.real);
	fflush(stdin);

	printf("Enter imag part: ");
	fflush(stdout);
	scanf("%f",&d2.imag);
	fflush(stdin);


	res = add(d1, d2);

	printf("Result = %0.2f + %0.2f i",res.real , res.imag);

}


struct S_complex add(struct S_complex n1 , struct S_complex n2 )
{
	struct S_complex res;
	res.real = n1.real + n2.real;
	res.imag = n1.imag + n2.imag;
	return res;
}


