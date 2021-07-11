/*
 * main_menu.c
 *
 *  Created on: 10 lip 2021
 *      Author: mateo
 */

#include "main_menu.h"
#include "bitmaps.h"
#include "lcd.h"

void menu_screen()
{
	lcd_clear();
	lcd_send();

	HAL_Delay(2000);

	lcd_draw_bitmap(game_icon);
	lcd_send();

	HAL_Delay(2000);

	lcd_clear();
	lcd_paint_line(1);
	lcd_draw_text(1, 27, "Snake",black);
	lcd_draw_text(2, 24, "Tetris",white);
	lcd_draw_text(3, 0, "Space invaders",white);
	lcd_draw_text(4, 8, "Brick braker",white);
	lcd_send();

}
