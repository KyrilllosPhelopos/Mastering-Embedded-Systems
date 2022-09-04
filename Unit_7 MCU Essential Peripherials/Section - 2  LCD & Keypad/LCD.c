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
 
void LCD_kick(){
	LCD_CTRL |= (1 << EN_SWITCH);
	_delay_ms(50);
	LCD_CTRL &= ~(1 << EN_SWITCH);
}
/**************************************************
					LCD_check_lcd_isbusy()
to make sure the LCD is not busy
			a. set the port to receive data on the micro controller (Data direction as input).
			b. put the LCD in read mode (RW on).
			c. put the LCD in command mode (RS off)
			D. enables the lcd then disabled it 
			E. put the direction to be output
			F. make it in read mode 
==================================================================*/
void LCD_check_lcd_isbusy(){
	DataDir_LCD_PORT = (0xff<<DATA_shift);
	LCD_CTRL |= (1 << RW_SWITCH);//make it in write mode
	LCD_CTRL &= ~(1 << RS_SWITCH);//RS off
	LCD_kick(); //enables the lcd then disabled it 
	DataDir_LCD_PORT |= (0xff<<DATA_shift); //put the direction to be output
	LCD_CTRL &= ~(1 << RW_SWITCH); //make it in write mode 
	
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
	_delay_ms(20);
	DataDir_LCD_CTRL |= (1<<EN_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH);
	LCD_CTRL &= ~ (1<<EN_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH);
	DataDir_LCD_PORT = 0xFF;
	_delay_ms(15);
	LCD_clear_screen();
	
	
	#ifdef EIGHT_BIT_MODE
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	#endif
	#ifdef FOUR_BIT_MODE

	LCD_WRITE_COMMAND(0x02);
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
	#endif
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

/*=================================================================================
						LCD_WRITE_COMMAND(unsigned char command)
	to write a command on the lcd

				不et the port direction as output so you can send information to the LCD.
				付urn RW off so you can write.
				付urn RS off for command mode.
				標rite the commandon D0�D7
				付urn on the enable and then turn it off.(delay ~500ns)
				謬he LCD will magically perform the command.
======================================================================================*/
void LCD_WRITE_COMMAND(unsigned char command){
	/*
	the first three steps done in *LCD_check_lcd_isbusy()* ;
	*/
	#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();//contain the first 3 steps
	LCD_PORT = command;  // writing command
	LCD_CTRL &= ~((1 << RS_SWITCH) | (1<<RW_SWITCH));
	_delay_ms(1);
	LCD_kick();//turn on the enable and then turn it off
	#endif
	#ifdef FOUR_BIT_MODE
	LCD_check_lcd_isbusy();
	LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);//writing command to highest 4 bit 
	LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
	LCD_kick ();
	LCD_PORT = (LCD_PORT & 0x0F) | (command << 4);//writing the rest of the command
	LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
	LCD_kick();
	#endif
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
	
	#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();
	LCD_PORT = character;
	LCD_CTRL &= ~(1 << RW_SWITCH);
	LCD_CTRL |= (1 << RS_SWITCH);
	_delay_ms(1);
	LCD_kick();
	#endif
	
	#ifdef FOUR_BIT_MODE
	//LCD_check_lcd_isbusy();
	LCD_PORT = (LCD_PORT & 0x0F) | (character & 0xF0);
	LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
	LCD_kick();
	LCD_PORT = (LCD_PORT & 0x0F) | (character << 4);
	LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
	LCD_kick ();
	#endif
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
