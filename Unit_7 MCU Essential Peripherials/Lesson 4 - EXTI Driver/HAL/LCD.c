/*
 * LCD.c
 *
 * Created: 9/4/2022 10:09:32 PM
 *  Author: Kyrillos Sawiris
 */
#include "LCD.h"


/*==============================================
					LCD_kick()
common function to be used
it enable the LCD then disabled it
==============================================*/

GPIO_PinConfig_t PinConfig;

static void delay(int delay)
{
	uint32_t i,j;

	for (i = 0; i < delay; i++)
	{
		for(j = 0; j < 255 ; j++);
	}
}

void LCD_kick(){
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_SET);
	delay(50);
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_RESET);
}
/*========================================================
						LCD_INIT()
	to init the LCD
			Wait for more than 15 ms
			config the 3 control pins as output
			turn of all the control pins
			config lcd port as output
			wait of 15 ms
			write command to config it as eigther 8 bit mode or 4 bit mode
====================================================================*/

void LCD_INIT(){
	delay(20);


	//set control pins to be output
	PinConfig.pinNumber = EN_SWITCH;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.pinNumber = RS_SWITCH;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.pinNumber = RW_SWITCH;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);


	//set the data pins to be output
	PinConfig.pinNumber = GPIO_PIN_0;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.pinNumber = GPIO_PIN_1;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.pinNumber = GPIO_PIN_2;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.pinNumber = GPIO_PIN_3;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.pinNumber = GPIO_PIN_4;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.pinNumber = GPIO_PIN_5;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.pinNumber = GPIO_PIN_6;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);

	PinConfig.pinNumber = GPIO_PIN_7;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(LCD_CTRL, &PinConfig);



	//DataDir_LCD_CTRL |= (1<<EN_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH);

	MCAL_GPIO_WritePin(LCD_CTRL ,EN_SWITCH , GPIO_PIN_RESET );
	MCAL_GPIO_WritePin(LCD_CTRL ,RS_SWITCH , GPIO_PIN_RESET );
	MCAL_GPIO_WritePin(LCD_CTRL ,RW_SWITCH , GPIO_PIN_RESET );


	delay(15);
	LCD_clear_screen();



	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

/*=================================================================================
						LCD_WRITE_COMMAND(unsigned char command)
	to write a command on the lcd

				�set the port direction as output so you can send information to the LCD.
				�turn RW off so you can write.
				�turn RS off for command mode.
				�Write the commandon D0�D7
				�turn on the enable and then turn it off.(delay ~500ns)
				�The LCD will magically perform the command.
======================================================================================*/
void LCD_WRITE_COMMAND(unsigned char command){
	/*
	the first three steps done in *LCD_check_lcd_isbusy()* ;
	 */


	MCAL_GPIO_WritePort(LCD_CTRL, command);


	MCAL_GPIO_WritePin(LCD_CTRL ,RW_SWITCH , GPIO_PIN_RESET );
	MCAL_GPIO_WritePin(LCD_CTRL ,RS_SWITCH , GPIO_PIN_RESET );
	delay(1);
	LCD_kick();//turn on the enable and then turn it off

}



/*=========================================================
				LCD_GOTO_XY(...)
function to specify the position of the cursor
======================================================*/
void LCD_GOTO_XY(unsigned char line, unsigned char position){
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW+position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW+position);
		}
	}
}

/*==============================================
			 LCD_WRITE_CHAR
	function to write a char on the lcd
===================================================*/
void LCD_WRITE_CHAR(unsigned char character){


	//LCD_CTRL = character;
	MCAL_GPIO_WritePort(LCD_CTRL , character );
	//	LCD_CTRL &= ~(1 << RW_SWITCH);
	//	LCD_CTRL |= (1 << RS_SWITCH);

	MCAL_GPIO_WritePin(LCD_CTRL ,RW_SWITCH , GPIO_PIN_RESET );
	MCAL_GPIO_WritePin(LCD_CTRL ,RS_SWITCH , GPIO_PIN_SET );
	delay(1);
	LCD_kick();



}


/*==========================================================================
			 LCD_WRITE_STRING(char* string)
take am array of chars and loop througth it and write them one by one on the lcd
====================================================================*/

void LCD_WRITE_STRING(char* string){
	int count = 0;
	while (*string > 0){
		count++;
		LCD_WRITE_CHAR(*string++);
		if (count == 16)
		{
			LCD_GOTO_XY(2,0);
		}
		else if (count == 32)
		{
			LCD_clear_screen();
			LCD_GOTO_XY(1,0);
			count = 0;
		}
	}
}

void LCD_clear_screen(){
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}
