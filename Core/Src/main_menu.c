/*
 * main_menu.c
 *
 *  Created on: 10 lip 2021
 *      Author: mateo
 */

#include "main_menu.h"
#include "bitmaps.h"
#include "lcd.h"
#include "stm32f3xx_hal.h"

uint8_t game_switch[4] = {black, white, white, white};
uint8_t game_choose = 0;

void start_console()
{
	lcd_clear();
	lcd_send();

	HAL_Delay(2000);

	lcd_draw_bitmap(game_icon);
	lcd_send();

	HAL_Delay(2000);
}

void main_menu_down_button()
{
	if( game_choose == 3)
		game_choose = 0;
	else
		game_choose++;

	for(int i=0; i<4; i++)
	{
		if(i == game_choose)
			game_switch[i] = black;
		else
			game_switch[i] = white;
	}

}

int main_menu_right_button()
{
	return game_choose;
}

void main_menu_up_button()
{
	if( game_choose == 0)
		game_choose = 3;
	else
		game_choose--;

	for(int i=0; i<4; i++)
	{
		if(i == game_choose)
			game_switch[i] = black;
		else
			game_switch[i] = white;
	}

}

void menu_screen()
{
	lcd_clear();
	lcd_paint_line(game_choose+1);
	lcd_draw_text(1, 27, "Snake", game_switch[0]);
	lcd_draw_text(2, 24, "Tetris", game_switch[1]);
	lcd_draw_text(3, 0, "Space invaders", game_switch[2]);
	lcd_draw_text(4, 8, "Brick braker", game_switch[3]);
	lcd_send();

}
