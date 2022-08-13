/*
toggling led in TM4C123

@author : Kyrillos Sawiris 
*/
#define SYSCTL_RCGC2_R     (*((volatile unsigned long *)0x400fe108))
#define GPIO_PORTF_DIR_R   (*((volatile unsigned long *) 0x40025400 ))
#define GPIO_PORTF_DEN_R   (*((volatile unsigned long *) 0x4002551c ))
#define GPIO_PORTF_DATA_R  (*((volatile unsigned long *) 0x400253fc ))

int main()
{
	
	volatile unsigned long delay_counter;
	SYSCTL_RCGC2_R = 0x20;
	for(delay_counter = 0; delay_counter <200 ; delay_counter++);
	GPIO_PORTF_DIR_R |=(1<<3);
	GPIO_PORTF_DEN_R |=(1<<3);
	
	while(1)
	{
		GPIO_PORTF_DATA_R |=(1<<3);
		for(delay_counter = 0; delay_counter <200000 ; delay_counter++);
		GPIO_PORTF_DATA_R &=~(1<<3);
		for(delay_counter = 0; delay_counter <200000 ; delay_counter++);
	}
	return 0;
}