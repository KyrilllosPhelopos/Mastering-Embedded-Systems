/*
startup.c file 
Kyrillos Sawiris 
*/

#include<stdint.h>





/*definnig the stack in the .bss section by making it static unintialized */
static unsigned long stack_top[256];

/*declaring used functions*/
extern int main(void);

void Rest_Handler();

void Default_Handler()
{
	Rest_Handler();
}

void NMI_Handler()__attribute__((weak , alias ("Default_Handler")));;
void Hard_Fault_Handler()__attribute__((weak , alias ("Default_Handler")));;
void MM_Fault_Handler()__attribute__((weak , alias ("Default_Handler")));;
void Bus_Fault_Handler()__attribute__((weak , alias ("Default_Handler")));;
void Usage_Fault_Handler()__attribute__((weak , alias ("Default_Handler")));;


void (* const g_p_fn_vectors[])() __attribute__((section(".vectors"))) = {
	(void(*)())  ((unsigned long)stack_top + sizeof(stack_top)),
	&Rest_Handler,
	&NMI_Handler,
	&Hard_Fault_Handler,
	&MM_Fault_Handler,
	&Bus_Fault_Handler,
	&Usage_Fault_Handler	
};

/*
definnig symbols as a variables to be used to initialize sections
*/
extern uint32_t _E_TEXT;
extern uint32_t _S_DATA ;
extern uint32_t _E_DATA;
extern uint32_t _S_BSS;
extern uint32_t _E_BSS;

void Rest_Handler()
{
	unsigned int data_size = (unsigned char*) &_E_DATA - (unsigned char*) &_S_DATA ;
	unsigned char* P_src = (unsigned char*)&_E_TEXT;
	unsigned char* P_dest = (unsigned char*)&_S_DATA;
	int i;
	for(i=0 ; i<data_size ; i++ )
	{
		*((unsigned char*) P_dest++) = *((unsigned char*) P_src++);
	}
	
	unsigned int bss_size = (unsigned char*) &_E_BSS - (unsigned char*) &_S_BSS ;
	P_dest = (unsigned char*)&_S_BSS;
		for(i=0 ; i<bss_size ; i++ )
	{
		*((unsigned char*)P_dest++) = 0;
	}
	
	
	main();
}


