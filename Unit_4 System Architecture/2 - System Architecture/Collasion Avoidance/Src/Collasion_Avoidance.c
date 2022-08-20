/*
 * Collasion_Avoidance.c
 *
 *  Created on: Aug 17, 2022
 *      Author: phelp
 */


#include "Collasion_Avoidance.h"

// Global Variable
static int CA_speed = 0;
static int CA_distance = 0;
static int CA_threshold = 50;
enum CA_status CA_state_id;

// STATE Pointer to function
 void (*CA_state)();

void US_distance_set(int distance)
{
	CA_distance = distance;
	(CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	Dprintf("US --------- distance = %d -------> CA \n", CA_distance);

}

// STATE Functions
STATE_define(CA_waiting)
{
	// State_Name

	CA_state = CA_waiting;
	Dprintf("CA_	wating State: distance = %d, speed = %d\n", CA_distance, CA_speed);

	// State_Action
	CA_speed = 0;
	DC_Motor(CA_speed);

	// Event_Check
	// Automatic because have function
	// Ultrasonic_Get_Distance(CA_distance)
}

STATE_define(CA_driving)
{
	// State_Name
	 CA_state_id = CA_driving;
	Dprintf("CA_driving State: distance = %d, speed = %d\n", CA_distance, CA_speed);

	// State_Action
	CA_speed = 30;
	DC_Motor(CA_speed);

	// Event_Check
	// Automatic because have function
	// Ultrasonic_Get_Distance(CA_distance)
}
