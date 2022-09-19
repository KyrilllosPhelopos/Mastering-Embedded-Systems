/*
 * stm32f103c6.h
 *
 *  Created on: Sep 6, 2022
 *      Author: Kyrillos Sawiris
 */

#ifndef STM32F103C6_H_
#define STM32F103C6_H_

#include <stdint.h>

/*==========================================================
 	 	 Base addresses for Memories
 ==========================================================*/

#define FLASH_BASE 			0x08000000UL
#define SRAM_BASE			0x20000000UL
#define PERIPHERALS_BASE	0x40000000UL

#define APB1_BUS_BASE     	(PERIPHERALS_BASE)
#define APB2_BUS_BASE     	(PERIPHERALS_BASE + 0x00010000UL)
#define AHB_BUS_BASE      	(PERIPHERALS_BASE + 0x00020000UL)

/*==========================================================
 	 	NVIC ( Non-Vectored Interrupt Controller )
 ==========================================================*/

#define NVIC_BASE_ADDRESS	0xE000E100UL
#define NVIC_ISER0			*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x00)
#define NVIC_ISER1			*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x04)
#define NVIC_ISER2			*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x08)
#define NVIC_ICER0			*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x80)
#define NVIC_ICER1			*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x84)
#define NVIC_ICER2			*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x88)

/*==========================================================
 	 	 Base addresses for AHB Peripherals
 ==========================================================*/
#define RCC_BASE      		0x40021000

/*====================================================
 	 	 base addresses for APB2 Peripherals
==================================================== */
//GPIO A , B Fully included in LQFP48

#define GPIOA_BASE    		0x40010800

#define GPIOB_BASE    		0x40010C00

//GPIO C , D Partially  included in LQFP48

#define GPIOC_BASE    		0x40011000

#define GPIOD_BASE    		0x40011400

//GPIO E,F,G NOT included in LQFP48

#define GPIOE_BASE     		0x40011800

#define GPIOF_BASE     		0x40011C00

#define GPIOG_BASE    		0x40012000

//AFIO
#define AFIO_BASE      		0x40010000
//EXTI
#define EXTI_BASE      		0x40010400

#define USART1_BASE         (APB2_BUS_BASE + 0x3800)
#define USART2_BASE         (APB1_BUS_BASE + 0x4400)
#define USART3_BASE         (APB1_BUS_BASE + 0x4800)
//#define USART1_BASE         0x40013BFF
//#define USART2_BASE         0x400047FF
//#define USART3_BASE         0x40004BFF

/*===================================================================
 * Peripheral Registers: RCC
 ===================================================================*/

typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
}RCC_TypeDef;

/*===================================================================
 * Peripheral Registers: GPIO
 ===================================================================*/

typedef struct
{
	volatile uint32_t   CRL;
	volatile uint32_t   CRH;
	volatile uint32_t   IDR;
	volatile uint32_t   ODR;
	volatile uint32_t   BSRR;
	volatile uint32_t   BRR;
	volatile uint32_t   LCKR;
}GPIO_TypeDef;

/*===================================================================
 * Peripheral Registers: AFIO
 ===================================================================*/

typedef struct
{
	volatile uint32_t	EVCR ;
	volatile uint32_t	MAPR ;
	volatile uint32_t	EXTICR [4] ;
	volatile uint32_t	RESERVED;
	volatile uint32_t	MAPR2;

}AFIO_TypeDef;


/*===================================================================
 * Peripheral Registers: EXTI
 ===================================================================*/

typedef struct
{
	volatile uint32_t	IMR ;
	volatile uint32_t	EMR ;
	volatile uint32_t	RTSR;
	volatile uint32_t	FTSR ;
	volatile uint32_t	SWIER ;
	volatile uint32_t	PR;

}EXTI_TypeDef;

/*===================================================================
 * Peripheral Registers: USART
 ===================================================================*/

typedef struct
{
	volatile uint32_t	SR ;
	volatile uint32_t	DR ;
	volatile uint32_t	BRR;
	volatile uint32_t	CR1 ;
	volatile uint32_t	CR2 ;
	volatile uint32_t	CR3 ;
	volatile uint32_t	GTPR;

}USART_TypeDef;
/*===================================================================
 * Peripheral Instants
 ===================================================================*/

#define GPIOA			((GPIO_TypeDef*)GPIOA_BASE)
#define GPIOB			((GPIO_TypeDef*)GPIOB_BASE)
#define GPIOC			((GPIO_TypeDef*)GPIOC_BASE)
#define GPIOD			((GPIO_TypeDef*)GPIOD_BASE)
#define GPIOE			((GPIO_TypeDef*)GPIOE_BASE)

#define RCC				((RCC_TypeDef*)RCC_BASE)

#define EXTI			((EXTI_TypeDef*)EXTI_BASE)

#define AFIO			((AFIO_TypeDef*)AFIO_BASE)

//USART
#define USART1			((USART_TypeDef*)USART1_BASE)
#define USART2			((USART_TypeDef*)USART2_BASE)
#define USART3			((USART_TypeDef*)USART3_BASE)


/*===================================================================
 *clock enable Macros: Peripheral Instants
 ===================================================================*/

/*
 * Enable clock for Ports A, B, C, D, E
 */
#define RCC_GPIOA_CLK_EN()	(RCC->APB2ENR |= 1 << 2)  //IOPA enable is in bit 2
#define RCC_GPIOB_CLK_EN()	(RCC->APB2ENR |= 1 << 3)  //IOPB enable is in bit 3
#define RCC_GPIOC_CLK_EN()	(RCC->APB2ENR |= 1 << 4)  //IOPC enable is in bit 4
#define RCC_GPIOD_CLK_EN()	(RCC->APB2ENR |= 1 << 5)  //IOPD enable is in bit 5
#define RCC_GPIOE_CLK_EN()	(RCC->APB2ENR |= 1 << 6)  //IOPE enable is in bit 6
/*
 * Enable clock for AFIO
 */
#define RCC_AFIO_CLK_EN()	(RCC->APB2ENR |= 1 << 0)  //AFIO enable is in bit 0


// Enable clock for USART
//USART1
#define RCC_USART1_CLK_EN()	(RCC->APB2ENR |= 1 << 14)  //USART1 enable is in bit 14
//USART2
#define RCC_USART2_CLK_EN()	(RCC->APB1ENR |= 1 << 17)  //USART2 enable is in bit 17
//USART3
#define RCC_USART3_CLK_EN()	(RCC->APB1ENR |= 1 << 18)  //USART3 enable is in bit 18


/*===================================
 * Disable clock For USARTx
 *==================================*/
#define RCC_USART1_CLK_DI()	(RCC->APB2RSTR |= 1 << 14) //USART1 disable is in bit 14
#define RCC_USART2_CLK_DI()	(RCC->APB1RSTR |= 1 << 17) //USART1 disable is in bit 17
#define RCC_USART3_CLK_DI()	(RCC->APB1RSTR |= 1 << 18) //USART1 disable is in bit 18

/*===================================================================
 *Interrupt Vector Table:
 ===================================================================*/

/*
 * EXTI
 */
#define EXTI0_IRQ		6
#define EXTI1_IRQ		7
#define EXTI2_IRQ		8
#define EXTI3_IRQ		9
#define EXTI4_IRQ		10
#define EXTI5_IRQ		23
#define EXTI6_IRQ		23
#define EXTI7_IRQ		23
#define EXTI8_IRQ		23
#define EXTI9_IRQ		23
#define EXTI10_IRQ		40
#define EXTI11_IRQ		40
#define EXTI12_IRQ		40
#define EXTI13_IRQ		40
#define EXTI14_IRQ		40
#define EXTI15_IRQ		40


//USART
#define USART1_IRQ		37
#define USART2_IRQ		38
#define USART3_IRQ		39



/*===================================================================
 * Enable Interrupt Requests
 ===================================================================*/
/* We Started From IRQ6 Due To DataSheet
 ISER : Interrupt Set Register*/

#define NVIC_IRQ6_EXTI0_EN()			(NVIC_ISER0 |= 1<<6)				// EXTI0 ---> PIN6 in NVIC
#define NVIC_IRQ7_EXTI1_EN()			(NVIC_ISER0 |= 1<<7)				// EXTI1 ---> PIN7 in NVIC
#define NVIC_IRQ8_EXTI2_EN()			(NVIC_ISER0 |= 1<<8)				// EXTI2 ---> PIN8 in NVIC
#define NVIC_IRQ9_EXTI3_EN()			(NVIC_ISER0 |= 1<<9)				// EXTI3 ---> PIN9 in NVIC
#define NVIC_IRQ10_EXTI4_EN()			(NVIC_ISER0 |= 1<<10)				// EXTI4 ---> PIN10 in NVIC
#define NVIC_IRQ23_EXTI5_9_EN()			(NVIC_ISER0 |= 1<<23)				// EXTI5, EXTI6, EXTI7, EXTI8, EXTI9 ---> PIN23 in NVIC

// 40 - 32 = 8
#define NVIC_IRQ40_EXTI10_15_EN()		(NVIC_ISER1 |= 1<<8)				// EXTI10, EXTI11, EXTI12, EXTI13, EXTI14, EXTI15

//USART
#define NVIC_IRQ37_USART1_EN()		(NVIC_ISER1 |= 1<<(USART1_IRQ - 32)) // enable NVIC FOR USART1
#define NVIC_IRQ38_USART2_EN()		(NVIC_ISER1 |= 1<<(USART2_IRQ - 32)) // enable NVIC FOR USART2
#define NVIC_IRQ39_USART3_EN()		(NVIC_ISER1 |= 1<<(USART3_IRQ - 32)) // enable NVIC FOR USART3

/*===================================================================
 *Disable Interrupt Requests
 ===================================================================*/

/* We Started From IRQ6 Due To DataSheet
ICER : Interrupt Clear Register*/

#define NVIC_IRQ6_EXTI0_DI()			(NVIC_ICER0 |= 1<<6)				// EXTI0 ---> PIN6 in NVIC
#define NVIC_IRQ7_EXTI1_DI()			(NVIC_ICER0 |= 1<<7)				// EXTI1 ---> PIN7 in NVIC
#define NVIC_IRQ8_EXTI2_DI()			(NVIC_ICER0 |= 1<<8)				// EXTI2 ---> PIN8 in NVIC
#define NVIC_IRQ9_EXTI3_DI()			(NVIC_ICER0 |= 1<<9)				// EXTI3 ---> PIN9 in NVIC
#define NVIC_IRQ10_EXTI4_DI()			(NVIC_ICER0 |= 1<<10)				// EXTI4 ---> PIN10 in NVIC
#define NVIC_IRQ23_EXTI5_9_DI()			(NVIC_ICER0 |= 1<<23)				// EXTI5, EXTI6, EXTI7, EXTI8, EXTI9 ---> PIN23 in NVIC

// 40 - 32 = 8
#define NVIC_IRQ40_EXTI10_15_DI()		(NVIC_ICER1 |= 1<<8)				// EXTI10, EXTI11, EXTI12, EXTI13, EXTI14, EXTI15
																			//  ---> PIN40 in NVIC

// USART
#define NVIC_IRQ37_USART1_DI()		(NVIC_ICER1 |= 1<<(USART1_IRQ - 32)) // disable NVIC FOR USART1
#define NVIC_IRQ38_USART2_DI()		(NVIC_ICER1 |= 1<<(USART2_IRQ - 32)) // disable NVIC FOR USART2
#define NVIC_IRQ39_USART3_DI()		(NVIC_ICER1 |= 1<<(USART3_IRQ - 32)) // disable NVIC FOR USART3

#endif /* STM32F103C6_H_ */
