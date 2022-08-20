

#include"US_Sensor.h"

 void (* US_state)();

//module variables
 static  unsigned int distance;
 enum US_status  US_state_id;

 int generate_random(int l ,int r , int count)
 {
	 int i;
	 for(i =0 ;i<count ; i++)
	 {
		 int rand_num = (rand() % (r-1 +l))+1;
		 return rand_num;
	 }
	 return 0;

 }

 void US_init()
 {
	 printf("DC_init");
 }

 STATE_define(US_busy)
 {
	 //state action
	 US_state_id = US_busy;
	 //read from US
	 distance = generate_random(45,55,1);

	 printf("US_busy STATE: distance = %d \n",distance);
	 US_distance_set(distance);
	 US_state= STATE(US_busy);
 }
