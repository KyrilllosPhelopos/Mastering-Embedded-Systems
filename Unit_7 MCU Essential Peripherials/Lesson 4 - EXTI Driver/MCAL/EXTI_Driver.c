/*---------------------------------------------------------------------------------
 * EXTRI_Driver.c
 *
 *  Created on: Sep 7, 2022
 *      Author: Kyrillos Sawiris
----------------------------------------------------------------------------------- */

/*=============================================================================
 * 							INCLUDES
 * ===========================================================================*/
#include "EXTRI_Driver.h"


/*=============================================================================
 * 							Generic Variables
 * ===========================================================================*/

void (* GP_IRQ_CallBack[15])(void); // Array Of 15 Pointer To Functions Take void And Return Nothing

/*=============================================================================
 * 							Generic Macros
 * ===========================================================================*/
//to replace the GPIO PORT with the value corresponding
//0000: PA[x] pin
//0001: PB[x] pin
//0010: PC[x] pin
//0011: PD[x] pin
#define AFIO_GPIO_EXTI_Mapping(x) (	(x == GPIOA)?0:\
		(x == GPIOB)?1:\
				(x == GPIOC)?2:\
						(x == GPIOD)?3:0 )

/*=============================================================================
 * 							Local functions
 * ===========================================================================*/

static void Enable_NVIC (uint16_t IRQ)
{
	//according to the IRQ value enable the corresponding INT in the IVT
	switch(IRQ)
	{
	case 0: NVIC_IRQ6_EXTI0_EN(); break;
	case 1: NVIC_IRQ7_EXTI1_EN(); break;
	case 2: NVIC_IRQ8_EXTI2_EN(); break;
	case 3:	NVIC_IRQ9_EXTI3_EN(); break;
	case 4: NVIC_IRQ10_EXTI4_EN(); break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9: NVIC_IRQ23_EXTI5_9_EN(); break;//Because EXTI 5-9  has the same IRQ
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15: NVIC_IRQ40_EXTI10_15_EN(); break;//Because EXTI 10-15  has the same IRQ
	}
}

static void Disable_NVIC (uint16_t IRQ)
{
	//according to the IRQ value disable the corresponding INT in the IVT
	switch(IRQ)
	{
	case 0: NVIC_IRQ6_EXTI0_DI(); break;
	case 1: NVIC_IRQ7_EXTI1_DI(); break;
	case 2: NVIC_IRQ8_EXTI2_DI(); break;
	case 3:	NVIC_IRQ9_EXTI3_DI(); break;
	case 4: NVIC_IRQ10_EXTI4_DI(); break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9: NVIC_IRQ23_EXTI5_9_DI(); break;//Because EXTI 5-9  has the same IRQ
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15: NVIC_IRQ40_EXTI10_15_DI(); break;//Because EXTI 10-15  has the same IRQ
	}
}


static void update_EXTI(EXTI_PinConfig_t * EXTI_Config)
{
	//1- Configure GPIO TO BE AF input Floating

	GPIO_PinConfig_t PinCfg;

	PinCfg.pinNumber = EXTI_Config->EXTI_PIN.GPIO_PIN;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;

	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_PORT, &PinCfg);

	//---------------------------------------------------------------
	//2- update between AFIO to route between EXTI Lines ports A,B,C,D

		uint8_t AFIO_EXTICR_index = EXTI_Config->EXTI_PIN.ETI_INPUTLineNumber / 4; //which EXTICR 0 or 1 or 2 or 3
		uint8_t AFIO_EXTICR_position = (EXTI_Config->EXTI_PIN.ETI_INPUTLineNumber % 4) * 4;//at which position in the register

		AFIO->EXTICR[AFIO_EXTICR_index] &=~(0xf<<AFIO_EXTICR_position);//reset it
		//set it with the corresponding PORT Value
		//using a global macro
		AFIO->EXTICR[AFIO_EXTICR_index] |=((AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_PIN.GPIO_PORT) & 0xf)<<AFIO_EXTICR_position);//set it


	//------------------------------------------------------------------------------------------------------------------------------------------
	//3- update rising or falling registers

	//reset the corresponding values on rising and falling registers
	EXTI->RTSR &=~(1<<EXTI_Config->EXTI_PIN.ETI_INPUTLineNumber );
	EXTI->FTSR &=~(1<<EXTI_Config->EXTI_PIN.ETI_INPUTLineNumber );

	//check its trigger case
	if(EXTI_Config->Triger_Case == EXTI_TRAGGER_RISSING_EDGE)
		EXTI->RTSR |=(1<<EXTI_Config->EXTI_PIN.ETI_INPUTLineNumber);
	else if(EXTI_Config->Triger_Case == EXTI_TRAGGER_FALLING_EDGE)
		EXTI->FTSR |=(1<<EXTI_Config->EXTI_PIN.ETI_INPUTLineNumber);
	else if (EXTI_Config->Triger_Case == EXTI_TRAGGER_RISSING_AND_FALLING_EDGE)
	{
		EXTI->RTSR &=~(1<<EXTI_Config->EXTI_PIN.ETI_INPUTLineNumber);
		EXTI->FTSR &=~(1<<EXTI_Config->EXTI_PIN.ETI_INPUTLineNumber);
	}


	//----------------------------------------------------------------------------------------------
	//4- update IRQ Handler Callback

	//assign the call_backFunction to the corresponding pointer in the array
	GP_IRQ_CallBack[EXTI_Config->EXTI_PIN.ETI_INPUTLineNumber] = EXTI_Config->P_IRQ_CallBack;


	//-----------------------------------------------------------------------------------------
	//5- Enable / Disable IRQ

	//check if he want to enable or disable the EXTI
	if(EXTI_Config->IRQ_Enable == EXTI_IRQ_ENABLE)
	{
		EXTI->IMR |= (1<<EXTI_Config->EXTI_PIN.ETI_INPUTLineNumber);//enable the IMR
		//enable the corresponding NVIC
		//using a local function Enable_NVIC
		Enable_NVIC(EXTI_Config->EXTI_PIN.ETI_INPUTLineNumber);
	}
	else
	{
		//disable the IMR
		EXTI->IMR &= ~(1<<EXTI_Config->EXTI_PIN.ETI_INPUTLineNumber);
		//disable the corresponding NVIC
		//using a local function Disable_NVIC
		Disable_NVIC(EXTI_Config->EXTI_PIN.ETI_INPUTLineNumber);
	}


}


/*=============================================================================================
 * 						GLOBAL  FUNCTIONS Definitions
==========================================================================================*/

/******************************************************************************
 * \Name            : MCAL_EXTI_GPIO_DeInit
 * \Description     : deinitialize all the EXTI Registers and disable all NVIC_IRQ
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/

void MCAL_EXTI_GPIO_DeInit(void)
{
	EXTI->IMR	= 0x0;
	EXTI->EMR	= 0x0;
	EXTI->RTSR	= 0x0;
	EXTI->FTSR	= 0x0;
	EXTI->SWIER = 0x0;
	//cleared by writing 1
	EXTI->PR    = 0xffffffff;

	//Disable EXTRI FROM NVIC
	NVIC_IRQ6_EXTI0_DI();
	NVIC_IRQ7_EXTI1_DI();
	NVIC_IRQ8_EXTI2_DI();
	NVIC_IRQ9_EXTI3_DI();
	NVIC_IRQ10_EXTI4_DI();
	NVIC_IRQ23_EXTI5_9_DI();
	NVIC_IRQ40_EXTI10_15_DI();
}

/******************************************************************************
 * \Name            : MCAL_EXTI_GPIO_Init
 * \Description     :initialize the Corresponding EXTI Registers and enable the corresponding NVIC_IRQ
 * \Parameters (in) :- EXTI_Config contain all the configuration parameters of the EXTI
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t * EXTI_Config)
{
	//calling a local function inside the file
	update_EXTI(EXTI_Config);
}

/******************************************************************************
 * \Name            : MCAL_EXTI_GPIO_Update
 * \Description     :update the Corresponding EXTI Registers
 * \Parameters (in) :- EXTI_Config contain all the configuration parameters of the EXTI
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t * EXTI_Config)
{
	//calling a local function inside the file
	update_EXTI(EXTI_Config);
}


/* ===========================================================================================
							ISR Functions
============================================================================================== */

// EXTI0
void EXTI0_IRQHandler (void)
{
	/* Clear By Writing "1" into the bit Pending Register (EXTI_PR) */
	EXTI->PR |= 1 << 0;

	/* Call IRQ_CallBack */
	GP_IRQ_CallBack[0]();

}

// EXTI1
void EXTI1_IRQHandler (void)
{
	/* Clear By Writing "1" into the bit Pending Register (EXTI_PR) */
	EXTI->PR |= 1 << 1;

	/* Call IRQ_CallBack */
	GP_IRQ_CallBack[1]();

}

// EXTI2
void EXTI2_IRQHandler (void)
{
	/* Clear By Writing "1" into the bit Pending Register (EXTI_PR) */
	EXTI->PR |= 1 << 2;

	/* Call IRQ_CallBack */
	GP_IRQ_CallBack[2]();

}

// EXTI3
void EXTI3_IRQHandler (void)
{
	/* Clear By Writing "1" into the bit Pending Register (EXTI_PR) */
	EXTI->PR |= 1 << 3;

	/* Call IRQ_CallBack */
	GP_IRQ_CallBack[3]();

}

// EXTI4
void EXTI4_IRQHandler (void)
{
	/* Clear By Writing "1" into the bit Pending Register (EXTI_PR) */
	EXTI->PR |= 1 << 4;

	/* Call IRQ_CallBack */
	GP_IRQ_CallBack[4]();

}

// EXTI5 ---> EXTI9
void EXTI9_5_IRQHandler (void)
{
	//according to the INT 5-9 value clear the corresponding pending register and call the corresponding callBack function
	if (EXTI->PR & 1<<5)	{EXTI->PR |= (1<<5); GP_IRQ_CallBack[5]();}
	if (EXTI->PR & 1<<6)	{EXTI->PR |= (1<<6); GP_IRQ_CallBack[6]();}
	if (EXTI->PR & 1<<7)	{EXTI->PR |= (1<<7); GP_IRQ_CallBack[7]();}
	if (EXTI->PR & 1<<8)	{EXTI->PR |= (1<<8); GP_IRQ_CallBack[8]();}
	if (EXTI->PR & 1<<9)	{EXTI->PR |= (1<<9); GP_IRQ_CallBack[9]();}
}

// EXTI10 ---> EXTI15
void EXTI15_10_IRQHandler (void)
{
	//according to the INT 10-15 value clear the corresponding pending register and call the corresponding callBack function

	if (EXTI->PR & 1<<10)	{EXTI->PR |= (1<<10); GP_IRQ_CallBack[10]();}
	if (EXTI->PR & 1<<11)	{EXTI->PR |= (1<<11); GP_IRQ_CallBack[11]();}
	if (EXTI->PR & 1<<12)	{EXTI->PR |= (1<<12); GP_IRQ_CallBack[12]();}
	if (EXTI->PR & 1<<13)	{EXTI->PR |= (1<<13); GP_IRQ_CallBack[13]();}
	if (EXTI->PR & 1<<14)	{EXTI->PR |= (1<<14); GP_IRQ_CallBack[14]();}
	if (EXTI->PR & 1<<15)	{EXTI->PR |= (1<<15); GP_IRQ_CallBack[15]();}
}


