/*
 * snake_game.c
 *
 *  Created on: 24 sie 2021
 *      Author: mateo
 */

#include "snake_game.h"
#include "lcd.h"
#include "stm32f3xx_hal.h"

static uint8_t buffer[LCD_BUFFER_SIZE];
static uint8_t snake_length = 2;
static uint8_t snake_positions[2][252];
static uint8_t food_position[2];

void paint_snake()
{
	if(snake_positions[1][snake_length-1] % 2 == 1)
	{
		uint8_t memory[4];
		for(int i; i<4; i++)
		{
			memory[i] = buffer;
		}
	}
}

void snake()
{

}
