/*
 * lcd.h
 *
 *  Created on: 28 cze 2021
 *      Author: mateo
 */

#include "stm32f3xx_hal.h"

#define PCD8544_FUNCTION_SET		0x20
#define PCD8544_DISP_CONTROL		0x08
#define PCD8544_DISP_NORMAL			0x0c
#define PCD8544_SET_Y				0x40
#define PCD8544_SET_X				0x80
#define PCD8544_H_TC				0x04
#define PCD8544_H_BIAS				0x10
#define PCD8544_H_VOP				0x80

#define LCD_BUFFER_SIZE			(84 * 48 / 8)

#ifndef INC_LCD_H_
#define INC_LCD_H_

enum color{white, black};

void lcd_reset();
void lcd_cmd(uint8_t cmd);
void lcd_send(void);
void lcd_setup(void);
void lcd_clear(void);
void lcd_draw_bitmap(const uint8_t* data);
void lcd_draw_text(int row, int col, const char* text, int color);
void lcd_paint_line(int row);
void paint_game(uint8_t game_map);

#endif /* INC_LCD_H_ */
