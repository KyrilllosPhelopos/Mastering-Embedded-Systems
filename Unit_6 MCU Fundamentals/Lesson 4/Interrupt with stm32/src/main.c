


//GPIO PORTA REGISTIERS
#define PORTA_BASE 	0x40010800

#define GPIO_CRL		*(volatile unsigned int*)(PORTA_BASE + 0x00)
#define GPIOA_CRH		*(volatile unsigned int*)(PORTA_BASE + 0x04)
#define GPIOA_ODR	    *((volatile unsigned int*)(PORTA_BASE + 0x0c))

// CLOCK (RCC) REGISTERS
#define RCC_BASE 	0x40021000
#define RCC_APB2ENR 	*(volatile unsigned int*)(RCC_BASE + 0x18)

// External Interrupt Register
#define EXTI_BASE  0x40010400
#define EXTI_IMR 	*(volatile unsigned int*)(EXTI_BASE + 0x0)
#define EXTI_EMR 	*(volatile unsigned int*)(EXTI_BASE + 0x4)
#define EXTI_RTSR 	*(volatile unsigned int*)(EXTI_BASE + 0x8)
#define EXTI_FTSR 	*(volatile unsigned int*)(EXTI_BASE + 0x0c)
#define EXTI_SWIER 	*(volatile unsigned int*)(EXTI_BASE + 0x10)
#define EXTI_PR 	*(volatile unsigned int*)(EXTI_BASE + 0x14)

#define NVIC_ISER0  *(volatile unsigned int*)(0xE000E100)

// AFIO REGisters

#define AFIO_BASE 0x40010000
#define AFIO_EXTICR1   *(volatile unsigned int*)(AFIO_BASE + 0x08)


void clock_init()
{
	//enable clock for GPIO PORT A

	/*Bit 2 IOPARST: IO port A reset
	Set and cleared by software.
	0: No effect
	1: Reset IO port A*/

	RCC_APB2ENR |=(1<<2);

	// Enable clock for AFOL

	/*Bit 0 AFIORST: Alternate function IO reset
	Set and cleared by software.
	0: No effect
	1: Reset Alternate Function*/

	RCC_APB2ENR |=(1<<0);

}

void GPIO_init()
{
	GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00200000;

	//set port a pin 0 to be flotting
	GPIO_CRL |=(1<<2);
	//select port A for EXTI
	AFIO_EXTICR1 = 0x0;

}

void IRQ_init()
{
	/*To configure the 20 lines as interrupt sources, use the following procedure:
	• Configure the mask bits of the 20 Interrupt lines (EXTI_IMR)
	• Configure the Trigger Selection bits of the Interrupt lines (EXTI_RTSR and
	EXTI_FTSR)
	• Configure the enable and mask bits that control the NVIC IRQ channel mapped to the
	External Interrupt Controller (EXTI) so that an interrupt coming from one of the 20 lines
	can be correctly acknowledged.	*/

	// Config rising edge

	EXTI_RTSR |=(1<<0);
	//set line interrupt line
	EXTI_IMR |=(1<<0);
	 //Enable NVIC
	NVIC_ISER0 |=(1<<6);



}


int main(void) {

	clock_init();
	GPIO_init();
	IRQ_init();

	while(1){
	}
	return 0;
}

void EXTI0_IRQHandler(void)
{
	EXTI_PR |=(1<<0);

	GPIOA_ODR ^=(1<<13);
}




