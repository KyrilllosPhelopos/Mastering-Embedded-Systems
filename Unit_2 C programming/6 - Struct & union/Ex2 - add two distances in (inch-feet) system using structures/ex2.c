/*
 * ex2.c
 *
 *  Created on: Jul 25, 2022
 *      Author: phelp
 */


/*
 * ex2.c
 *
 *  Created on: Jul 25, 2022
 *      Author: phelp
 */

// add two distances in (inch-feet) system using structures


#include<stdio.h>
struct S_distance{
	int m_feet;
	float m_inch;
};

struct S_distance addDist(struct S_distance d1 , struct S_distance d2 );

int main()
{
	struct S_distance d1, d2 , res;

	printf("Enter 1st distance:");
	printf("\nFeet: ");
	fflush(stdout);
	scanf("%d",&d1.m_feet);
	printf("Inch: ");
	fflush(stdout);
	scanf("%f",&d1.m_inch);

	printf("Enter 2nd distance:");
	printf("\nFeet: ");
	fflush(stdout);
	scanf("%d",&d2.m_feet);
	printf("Inch: ");
	fflush(stdout);
	scanf("%f",&d2.m_inch);

	res = addDist(d1, d2);

	printf ("\nThe SUM of the distances is: %d',-%.1f\".", res.m_feet, res.m_inch);



}

struct S_distance addDist(struct S_distance d1 , struct S_distance d2 )
{
	struct S_distance res ;
	res.m_feet = d1.m_feet + d2.m_feet;
	res.m_inch = d1.m_inch + d2.m_inch;

	while(res.m_inch > 12)
	{
		res.m_inch -=12;
		res.m_feet++;
	}

	return res;
}

