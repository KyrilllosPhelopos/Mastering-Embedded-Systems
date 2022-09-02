/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Kyrillos Sawiris
 * @brief          : Main program body
 ******************************************************************************/

// RCC Registers
#define RCC_BASE 0x40021000
#define RCC_APB2ENR      (*(volatile int *)(RCC_BASE + 0x18 ))

//GPIOA Registers
#define GPIOA_BASE  0x40010800
#define GPIOA_CRL        (*(volatile int *)(GPIOA_BASE + 0x00 ))
#define GPIOA_CRH        (*(volatile int *)(GPIOA_BASE + 0x04 ))
#define GPIOA_IDR        (*(volatile int *)(GPIOA_BASE + 0x08 ))
#define GPIOA_BSRR       (*(volatile int *)(GPIOA_BASE + 0x10 ))
#define GPIOA_ODR       (*(volatile int *)(GPIOA_BASE + 0x0c ))


// GPIOB Registers
#define GPIOB_BASE  0x40010C00
#define GPIOB_CRL        (*(volatile int *)(GPIOB_BASE + 0x00 ))
#define GPIOB_CRH        (*(volatile int *)(GPIOB_BASE + 0x04 ))
#define GPIOB_IDR        (*(volatile int *)(GPIOB_BASE + 0x08 ))
#define GPIOB_ODR        (*(volatile int *)(GPIOB_BASE + 0x0c ))
#define GPIOB_BSRR       (*(volatile int *)(GPIOB_BASE + 0x10 ))


void clock_init()
{
	//enable clock for GPIOA
	RCC_APB2ENR |=(1<<2);
	//enable clock for GPIOB
	RCC_APB2ENR |=(1<<3);

}

void GPIO_init()
{

	GPIOA_CRL = 0x00;
	GPIOA_CRH = 0x00;
	GPIOA_ODR = 0x00;
	GPIOB_CRL = 0x00;
	GPIOB_CRH = 0x00;
	/*==================================================
	 *		 configure GPIOA PIN 1 as INPUT Floating pin
	 *==============================================*/



	//00: Input mode (reset state)on bits (4,5)
	GPIOA_CRL &=~(0b11<<4);
	//to be floating ->   01: Floating input (reset state) on bits (6,7)
	GPIOA_CRL |=(0b01<<6);

	/*==================================================
	 *		 configure GPIOA PIN 13 as INPUT Floating pin
	 *==================================================*/


	//00: Input mode (reset state)on bits (20,21)
	GPIOA_CRH &=~(0b11<<20);
	//to be floating ->   01: Floating input (reset state) on bits (22,23)
	GPIOA_CRH |=(0b01<<22);




	/*==================================================
	 *		 configure GPIOB PIN 1 as AN OUTPUT pin
	 *==================================================*/

	//01: Output mode, max speed 10 MHz. on bits (4,5)
	GPIOB_CRL |=(0b10<<4);
	//00: General purpose output push-pull on bits (6,7)
	GPIOB_CRL &=~(0b11<<6);

	/*==================================================
	 *		 configure GPIOB PIN 13 as AN OUTPUT pin
	 *==================================================*/

	//01: Output mode, max speed 10 MHz. on bits (20,21)
	GPIOB_CRH |=(0b10<<20);
	// 00: General purpose output push-pull on bits (22,23)
	GPIOB_CRH &=~(0b11<<22);

}

void delay(int x)
{
	for(int i =0 ; i<256 ; i++)
	{
		for(int j  =0 ; j< x ; j++);
	}
}

int main()
{
	clock_init();
	GPIO_init();

	while(1)
	{
		if(((GPIOA_IDR&(1<<1))>>1)==0)//single press
		{
			GPIOB_ODR ^=(1<<1); //toggling the led
			while(((GPIOA_IDR&(1<<1))>>1)==0); // stay as kong as the level doesnot change
		}

		if(((GPIOA_IDR&(1<<13))>>13) == 1)//multiple press
		{
			GPIOB_ODR ^=(1<<13); //toggling the led
		}
		delay(1);

	}
}
