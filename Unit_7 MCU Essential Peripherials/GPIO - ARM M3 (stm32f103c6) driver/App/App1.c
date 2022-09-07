/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Kyrillos Sawiris
 * @brief          : Main program body
 ******************************************************************************/
#include<stm32f103c6.h>
#include "GPIO.h"

void clock_init()
{
	// Enable clock GPIOA
	RCC->APB2ENR |=(1<<2);

	// Enable clock GPIOB
	RCC->APB2ENR |=(1<<3);
}

void GPIO_init()
{
	GPIO_PinConfig_t PinConfig;

    // Configure PA1 as input floating
	PinConfig.pinNumber = GPIO_PIN_1;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinConfig);

    // Configure PA13 as input floating
	PinConfig.pinNumber = GPIO_PIN_13;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinConfig);

    // Configure PB1 as output push-pull
	PinConfig.pinNumber = GPIO_PIN_1;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(GPIOB, &PinConfig);

    // Configure PB13 as output push-pull
	PinConfig.pinNumber = GPIO_PIN_13;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(GPIOB, &PinConfig);
}

void delay(int delay)
{
	uint32_t i,j;

	for (i = 0; i < delay; i++)
	{
		for(j = 0; j < 255 ; j++);
	}
}

int main(void)
{
	clock_init();
	GPIO_init();

	while(1)
	{
		if (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0) // Press
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			while (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0); // Single-press
		}

		if (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1) // Multi-presses
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		}
		delay(1);
	}
}
