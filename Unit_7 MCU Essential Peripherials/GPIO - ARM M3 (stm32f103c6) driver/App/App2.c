///**
// ******************************************************************************
// * @file           : main.c
// * @author         : Kyrillos Sawiris 
// * @brief          : Main program body
// ******************************************************************************



#include "stm32f103c6.h"
#include "GPIO.h"
#include "LCD.h"
#include "Keypad.h"


#define ZERO 0x01
#define ONE 0x79
#define TWO 0x24
#define THREE 0x30
#define FOUR 0x4C
#define FIVE 0x12
#define SIX 0x02
#define SEVEN 0x19
#define EIGHT 0x00
#define NINE 0x10



void clock_init()
{
	// Enable clock GPIOA
	RCC->APB2ENR |=(1<<2);

	// Enable clock GPIOB
	RCC->APB2ENR |=(1<<3);
}
void GPIO_init() {

	GPIO_PinConfig_t PinCfg;

	//PB1 (output PUSH pull Mode)
	//01: Output mode, max speed 10 MHz.
	//CNF 00: General purpose output push-pull
	PinCfg.pinNumber = GPIO_PIN_9;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.pinNumber = GPIO_PIN_10;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.pinNumber = GPIO_PIN_11;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.pinNumber = GPIO_PIN_12;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.pinNumber = GPIO_PIN_13;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	//============================

	//PA13 input HighZ Floating input (reset state)
	PinCfg.pinNumber = GPIO_PIN_14;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	//PB13 (output PUSH pull Mode)
	PinCfg.pinNumber = GPIO_PIN_15;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

}
void wait_ms(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++)
			;
}
int main(void) {

	clock_init();
	LCD_INIT();
	unsigned char key_pressed;
	LCD_WRITE_STRING("HEY");
	wait_ms(30);
	LCD_clear_screen();
	GPIO_init();
	unsigned char LCD_DISPLAY [11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
	unsigned char DISPLAY [11] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO};
	for (unsigned char i = 0; i < 11; i++) {
		LCD_WRITE_CHAR(LCD_DISPLAY[i]);
		MCAL_GPIO_WritePort(GPIOB, DISPLAY[i] << 9); /* write data on to the LED port */
		wait_ms(100);
		/* wait for 1 second */
	}
	LCD_clear_screen();
	Keypad_init();
	LCD_WRITE_STRING("Keypad is ready");
	wait_ms(30);
	LCD_clear_screen();

	while (1) {

		key_pressed = Keypad_getkey();
		switch (key_pressed) {
		case 'A':
			break;
		case '?':
			LCD_clear_screen();
			break;
		default:
			LCD_WRITE_CHAR(key_pressed);
			break;
		}

	}
}

