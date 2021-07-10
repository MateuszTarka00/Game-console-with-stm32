/*
 * lcd.c
 *
 *  Created on: 28 cze 2021
 *      Author: mateo
 */

#include <string.h>
#include "lcd.h"
#include "spi.h"
#include "gpio.h"
#include "font.h"

static uint8_t lcd_buffer[LCD_BUFFER_SIZE];

void lcd_reset()
{
	HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_SET);
}

void lcd_cmd(uint8_t cmd)
{
	HAL_GPIO_WritePin(GPIOA, CE_Pin|DC_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi2, &cmd, 1, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(GPIOA, CE_Pin|DC_Pin, GPIO_PIN_SET);
}

void lcd_send(void)
{
	HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DC_GPIO_Port, DC_Pin, GPIO_PIN_SET);
	HAL_SPI_Transmit(&hspi2, lcd_buffer, LCD_BUFFER_SIZE, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, GPIO_PIN_SET);
}

void lcd_setup(void)
{
	HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_SET);

	lcd_cmd(PCD8544_FUNCTION_SET | 1);
	lcd_cmd(PCD8544_H_BIAS | 4);
	lcd_cmd(PCD8544_H_VOP | 0x2f);
	lcd_cmd(PCD8544_FUNCTION_SET);
	lcd_cmd(PCD8544_DISP_NORMAL);
}

void lcd_clear(void)
{
	memset(lcd_buffer, 0, LCD_BUFFER_SIZE);
}

void lcd_draw_bitmap(const uint8_t* data)
{
	memcpy(lcd_buffer, data, LCD_BUFFER_SIZE);
}

void lcd_draw_text(int row, int col, const char* text)
{
	int i;
	uint8_t* pbuf = &lcd_buffer[row*84 + col];

	while ((*text) && (pbuf < &lcd_buffer[LCD_BUFFER_SIZE - 6]))
	{
		int ch = *text++;
		const uint8_t* font = &font_ASCII[ch - ' '][0];
		for (i = 0; i < 5; i++)
			*pbuf++ = *font++;

		*pbuf++ = 0;
	}

}




