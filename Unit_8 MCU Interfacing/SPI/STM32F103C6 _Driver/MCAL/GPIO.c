/*
 * GPIO.c
 *
 *  Created on: Sep 6, 2022
 *      Author: Kyrillos Sawiris
 */
/*===================================================
 	 	 	 	 	INCLUDES
==================================================== */
#include "GPIO.h"


/*=============================================================================================
 * 						  FUNCTIONS Definitions
==========================================================================================*/
//
///******************************************************************************
// * \Name            : Pin_Bit_Shift
// * \Description     : specifies the the shift amount to the pin to be configured
// * \Parameters (in) : PinNumber
// * \Parameters (out): None
// * \Return value:   : (uint8_t) the amount of shift
// *******************************************************************************/
static uint8_t Pin_Bit_Shift(uint16_t PinNumber)
{
	switch (PinNumber)
	{
	case GPIO_PIN_0:
		return 0;
		break;

	case GPIO_PIN_1:
		return 4;
		break;

	case GPIO_PIN_2:
		return 8;
		break;

	case GPIO_PIN_3:
		return 12;
		break;

	case GPIO_PIN_4:
		return 16;
		break;

	case GPIO_PIN_5:
		return 20;
		break;

	case GPIO_PIN_6:
		return 24;
		break;

	case GPIO_PIN_7:
		return 28;
		break;

	case GPIO_PIN_8:
		return 0;
		break;

	case GPIO_PIN_9:
		return 4;
		break;

	case GPIO_PIN_10:
		return 8;
		break;

	case GPIO_PIN_11:
		return 12;
		break;

	case GPIO_PIN_12:
		return 16;
		break;

	case GPIO_PIN_13:
		return 20;
		break;

	case GPIO_PIN_14:
		return 24;
		break;

	case GPIO_PIN_15:
		return 28;
		break;

	default:
		break;
	}
	return -1;
}
/******************************************************************************
 * \Name            : MCAL_GPIO_Init
 * \Description     : initialize GPIO
 * \Parameters (in) : - GPIOx  where x can be replaced by A, B, C, D ..
                     - PinConfig which contain the configuration of the bin
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/

void MCAL_GPIO_Init (GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig)
{
	volatile uint32_t * config_Register = (uint32_t *) 0 ;// To store which register for the input pin number

	uint16_t pinNumber = Pin_Bit_Shift(PinConfig->pinNumber);//the shift amount
	uint8_t PIN_CONFIG = 0 ; // To store the pin configuration

	//select CRL for pin 0 .. 7 and CRH for pins 8..15
	config_Register = (PinConfig->pinNumber > GPIO_PIN_7 ) ? &GPIOx->CRH : &GPIOx->CRL;

	//clear mode , CNF bits
	*config_Register &= ~(0xF << pinNumber);


	if((PinConfig->GPIO_MODE == GPIO_MODE_AFIO_OUT_OD)||(PinConfig->GPIO_MODE == GPIO_MODE_AFIO_OUT_PP)||(PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD)||(PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP))
	{
		// Set CNF8[1:0] MODE8[1:0]
		PIN_CONFIG = ((((PinConfig->GPIO_MODE - 4) << 2)|(PinConfig->GPIO_OUTPUT_SPEED)) & 0x0F); // "-4" > for definition on .h file  and "& 0x0F" > for neglect all remaining bits
		(*config_Register) |= (PIN_CONFIG << Pin_Bit_Shift(PinConfig->pinNumber));
	}
	// If pin is input
	else //00: Input mode (reset state)
	{
		if((PinConfig->GPIO_MODE == GPIO_MODE_ANALOG)||(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO))
		{
			// Set CNF8[1:0] MODE8[1:0] 00
			(*config_Register) |= (((((PinConfig->GPIO_MODE) << 2)))<<pinNumber); // "-4" > for definition on .h file  and "& 0x0F" > for neglect all remaining bits
		}
		else if (PinConfig->GPIO_MODE == GPIO_MODE_AFIO_IN) // Considered that GPIO_MODE_AFIO_IN = GPIO_MODE_INPUT_FLO in data sheet
		{
			(*config_Register) |= (((((GPIO_MODE_INPUT_FLO) << 2)))<<pinNumber); // "-4" > for definition on .h file  and "& 0x0F" > for neglect all remaining bits
		}
		else // Pull-up / Pull-Down Input
		{
			// GPIO_MODE_INPUT_PU == 0b10 as Table 20. Port bit configuration table
			(*config_Register) |= (((((GPIO_MODE_INPUT_PU) << 2)))<<pinNumber); // "-4" > for definition on .h file  and "& 0x0F" > for neglect all remaining bits

			if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
			{
				// PxODR = 1 Input pull-up: Table 20. Port bit configuration table
				GPIOx->ODR |= PinConfig->pinNumber;
			}
			else
			{
				// PxODR = 0 Input pull-down: Table 20. Port bit configuration table
				GPIOx->ODR &= ~(PinConfig->pinNumber);
			}
		}
	}
}


/******************************************************************************
 * \Name            : MCAL_GPIO_DeInit
 * \Description     : denitialize GPIO
 * \Parameters (in) : - GPIOx  where x can be replaced by A, B, C, D ..

 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx)
{
	//RCC_APB2RSTR
	//	Set and cleared by software.
	//	0: No effect
	//	1: Reset TIM11 timer


	if(GPIOx ==GPIOA)
	{
		RCC->APB2RSTR |=(1<<2);//reset the peripheral
		RCC->APB2RSTR &=~(1<<2);//set it to be 0
	}
	else if(GPIOx == GPIOB)
	{
		RCC->APB2RSTR |=(1<<3);
		RCC->APB2RSTR &=~(1<<3);
	}
	else if(GPIOx ==GPIOC)
	{
		RCC->APB2RSTR |=(1<<4);
		RCC->APB2RSTR &=~(1<<4);
	}
	else if(GPIOx ==GPIOD)
	{
		RCC->APB2RSTR |=(1<<5);
		RCC->APB2RSTR &=~(1<<5);
	}
	else if(GPIOx ==GPIOE)
	{
		RCC->APB2RSTR |=(1<<6);
		RCC->APB2RSTR &=~(1<<6);
	}

}

/******************************************************************************
 * \Name            : MCAL_GPIO_ReadPin
 * \Description     : get the pin value
 * \Parameters (in) : - GPIOx  where x can be replaced by A, B, C, D ..
                     - PinNumber which contain the bin number
 * \Parameters (out): None
 * \Return value:   :  The input pin value (two values based on @ref GPIO_PIN_state)
 *******************************************************************************/
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber)
{
	uint8_t pinStatus ;
	if(((GPIOx->IDR) & PinNumber) != GPIO_PIN_RESET)
		pinStatus = GPIO_PIN_SET;
	else
		pinStatus = GPIO_PIN_RESET;
	return pinStatus;
}
/******************************************************************************
 * \Name            : MCAL_GPIO_ReadPort
 * \Description     : Read IDR register value
 * \Parameters (in) : - GPIOx  where x can be replaced by A, B, C, D ..

 * \Parameters (out): None
 * \Return value:   : (uint16_t) the value of IDR Register
 *******************************************************************************/
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx)
{
	return ((uint16_t)(GPIOx->IDR));
}

/******************************************************************************
 * \Name            : MCAL_GPIO_WritePin
 * \Description     : write a specific value on a specific pin on a specific GPIO
 * \Parameters (in) : - GPIOx  where x can be replaced by A, B, C, D ..
                      - PinNumber which contain the number of the pin
                      - Value the value to be written on the pin (two values based on @ref GPIO_PIN_state)
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber, uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
		GPIOx->ODR |=PinNumber;
	else
		GPIOx->ODR &=~(PinNumber);
}
/******************************************************************************
 * \Name            : MCAL_GPIO_WritePort
 * \Description     : write a specific value on a specific GPIO ODR register
 * \Parameters (in) : - GPIOx  where x can be replaced by A, B, C, D ..
                      - Value the value to be written on the ODR Register
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16_t Value)
{
	GPIOx->ODR = (uint32_t)Value;
}
/******************************************************************************
 * \Name            : MCAL_GPIO_TogglePin
 * \Description     : toggle a specific pin in  GPIO ODR register
 * \Parameters (in) : - GPIOx  where x can be replaced by A, B, C, D ..
                     - PinConfig which contain the configuration of the bin
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber)
{
	GPIOx->ODR ^=PinNumber;
}
/******************************************************************************
 * \Name            : MCAL_GPIO_LockPin
 * \Description     : to lock a specific pin in a specific port
 * \Parameters (in) : - GPIOx  where x can be replaced by A, B, C, D ..
                     - PinNumber the pin to be locked
 * \Parameters (out): None
 * \Return value:   : OK if pin configure is locked Or ERROR if pin is not locked (OK & ERROR are defined @ref GPIO_RETURN_LOCK)
 *******************************************************************************/
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber)
{
	//	Bit 16 LCKK[16]: Lock key
	//	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	//	0: Port configuration lock key not active
	//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	//	LOCK key writing sequence:
	//	Write 1
	//	Write 0
	//	Write 1
	//	Read 0
	//	Read 1 (this read is optional but confirms that the lock is active)

	//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	//	Any error in the lock sequence will abort the lock.
	//	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	//	These bits are read write but can only be written when the LCKK bit is 0.
	//	0: Port configuration not locked
	//	1: Port configuration locked.

	volatile uint32_t temp = 1<<16;//to set the 16-bit

	//Set the LCKy
	temp |= PinNumber; //its contain 1 at bit 16 and 1 at pinNumber

	//Write 1
	GPIOx->LCKR = temp;

	//Write 0
	GPIOx->LCKR = PinNumber;//reset the 16-bit while holding the pinNumber bit

	//Write 1
	GPIOx->LCKR = temp;

	//Read 0
	temp = GPIOx->LCKR;

	//Read 1 (this read is optional but confirms that the lock is active)
	if((uint32_t)GPIOx->LCKR & 1<<16)
	{
		return GPIO_RETURN_LOCK_Enable;
	}
	else
	{
		return GPIO_RETURN_LOCK_ERROR;
	}
}
