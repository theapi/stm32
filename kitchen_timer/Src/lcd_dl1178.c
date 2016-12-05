/*
 * lcd_dl1178.c
 */

#include "lcd_dl1178.h"
#include "gpio.h"

LCD_HandleTypeDef hlcd;

void LCD_display(LCD_HandleTypeDef *hlcd, uint16_t num) {



    /* First digit */
    LCD->RAM[LCD_RAM_REGISTER0] = lcd_digits[0][num][0];
    LCD->RAM[LCD_RAM_REGISTER1] = lcd_digits[0][num][1];
    LCD->RAM[LCD_RAM_REGISTER2] = lcd_digits[0][num][2];
    LCD->RAM[LCD_RAM_REGISTER3] = lcd_digits[0][num][3];


    HAL_LCD_UpdateDisplayRequest(hlcd);
}
