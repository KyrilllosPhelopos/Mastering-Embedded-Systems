/*
 ============================================================================
 Name        : Ex1.c
 Author      : Kyrillos Sawiris
 Version     :
 ============================================================================
 */

#include <stdio.h>



int main(void) {

	int m = 29;
	int* ab;
	printf("Address of m: %p\n",&m);
	fflush(stdout);
	printf("Value of m: %d\n\n", m);
	fflush(stdout);

	ab =&m;
	printf("Now ab is assigned with the address of m.\n");
	fflush(stdout);
	printf("Address of pointer ab: %p\n",ab);
	fflush(stdout);
	printf("Content of pointer ab :%d\n\n",*ab);
	fflush(stdout);

	*ab = 34;
	printf("The value of m assigned to 34 now.\n");
	fflush(stdout);
	printf("Address of pointer ab: %p\n",ab);
	fflush(stdout);
	printf("Content of pointer ab :%d\n\n",*ab);
	fflush(stdout);

	*ab = 7;
	printf("The pointer variable ab is assigned with the value 7 now.\n");
	fflush(stdout);
	printf("Address of pointer ab: %p\n",ab);
	fflush(stdout);
	printf("Content of pointer ab :%d\n\n",*ab);
	fflush(stdout);

}
