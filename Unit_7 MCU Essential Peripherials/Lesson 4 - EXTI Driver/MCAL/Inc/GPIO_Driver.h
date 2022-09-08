/*
 * GPIO.h
 *
 *  Created on: Sep 6, 2022
 *      Author: Kyrillos Sawiris
 */

#ifndef GPIO_H_
#define GPIO_H_

/*========================================================
 	 	 	 	 	 	 includes
 *========================================================*/
#include "stm32f103c6.h"





typedef struct
{
	uint16_t pinNumber ; //specifies the GPIO PIN to be Configured
	// this parameter can be a value @ref GPIO_PIN_DEF


	uint8_t GPIO_MODE;//specifies the operating mode of the selected pin
	// this parameter can be a value @ref GPIO_MODE_DEF


	uint8_t GPIO_OUTPUT_SPEED;//specifies the OUTPUT speed  of the selected pin
	// this parameter can be a value @ref GPIO_OUTPUT_SPEED_DEF
}GPIO_PinConfig_t;

/*======================================================================
 * 						@ref GPIO_PIN_DEF
 *=======================================================================*/

#define GPIO_PIN_0						((uint16_t)0x0001) /* Pin 0 selected */
#define GPIO_PIN_1						((uint16_t)0x0002) /* Pin 1 selected */
#define GPIO_PIN_2						((uint16_t)0x0004) /* Pin 2 selected */
#define GPIO_PIN_3						((uint16_t)0x0008) /* Pin 3 selected */
#define GPIO_PIN_4						((uint16_t)0x0010) /* Pin 4 selected */
#define GPIO_PIN_5						((uint16_t)0x0020) /* Pin 5 selected */
#define GPIO_PIN_6						((uint16_t)0x0040) /* Pin 6 selected */
#define GPIO_PIN_7						((uint16_t)0x0080) /* Pin 7 selected */
#define GPIO_PIN_8						((uint16_t)0x0100) /* Pin 8 selected */
#define GPIO_PIN_9						((uint16_t)0x0200) /* Pin 9 selected */
#define GPIO_PIN_10						((uint16_t)0x0400) /* Pin 10 selected */
#define GPIO_PIN_11						((uint16_t)0x0800) /* Pin 11 selected */
#define GPIO_PIN_12						((uint16_t)0x1000) /* Pin 12 selected */
#define GPIO_PIN_13						((uint16_t)0x2000) /* Pin 13 selected */
#define GPIO_PIN_14						((uint16_t)0x4000) /* Pin 14 selected */
#define GPIO_PIN_15						((uint16_t)0x8000) /* Pin 15 selected */
#define GPIO_PIN_16						((uint16_t)0xFFFF) /* All pins selected */


/*======================================================================
 * 						@ref GPIO_MODE_DEF
 *=======================================================================*/
/*PIN MODE
0: Analog mode
1: Floating input (reset state)
2: Input with pull-up
3: Input with pull-down
4: General purpose output push-pull
5: General purpose output Open-drain
6: Alternate function output Push-pull
7: Alternate function output Open-drain
8: Alternate function input*/

#define GPIO_MODE_ANALOG		 0x0 //Analog mode
#define GPIO_MODE_INPUT_FLO		 0x1 //floating input (reset state)
#define GPIO_MODE_INPUT_PU		 0x2 //Input with pull-up
#define GPIO_MODE_INPUT_PD 		 0x3 // Input with pull-down
#define GPIO_MODE_OUTPUT_PP	 	 0x4 //General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD		 0x5 //General purpose output Open-drain
#define GPIO_MODE_AFIO_OUT_PP	 0x6 //Alternate function output Push-pull
#define GPIO_MODE_AFIO_OUT_OD  	 0x7 //Alternate function output Open-drain
#define GPIO_MODE_AFIO_IN  		 0x8 //Alternate function input


/*======================================================================
 * 						@ref GPIO_OUTPUT_SPEED_DEF
 *=======================================================================*/
/*
1: Output mode, max speed 10 MHz.
2: Output mode, max speed 2 MHz.
3: Output mode, max speed 50 MHz.*/
#define OUTPUT_SPEED_10		0x0//Output mode, max speed 10 MHz.
#define OUTPUT_SPEED_2		0x1//Output mode, max speed 2 MHz.
#define OUTPUT_SPEED_50 	0x2//Output mode, max speed 50 MHz

/*======================================================================
 * 							@ref GPIO_PIN_state
 *=======================================================================*/
#define GPIO_PIN_SET		0x1
#define GPIO_PIN_RESET		0x0

/*======================================================================
 * 							@ref GPIO_RETURN_LOCK
 *=======================================================================*/
#define GPIO_RETURN_LOCK_Enable		0x1
#define GPIO_RETURN_LOCK_ERROR		0x1
/*======================================================================
 * 							GPIO_APIS
 *=======================================================================*/

void MCAL_GPIO_Init (GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx);

uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx);

void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber, uint8_t Value);
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16_t Value);

void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);

uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);

#endif /* GPIO_H_ */
