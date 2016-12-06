/*
 * lcd_dl1178.c
 *
 *
 *

Display: HH  MM
Digits:  12  34

8 = A B C D E F G

1 = B C

 Multiplexing:
 1 = B C
     Digit 1 = COM1:SEG7, COM3:SEG7
     Digit 2 = COM1:SEG5, COM3:SEG5
     Digit 3 = COM1:SEG3, COM3:SEG3
     Digit 4 = COM1:SEG1, COM3:SEG1
 2 = A B D E G
     Digit 1 = COM1:SEG8, COM1:SEG7, COM4:SEG7, COM3:SEG8, COM2:SEG7
 ...

 *
 */

#include "lcd_dl1178.h"

/**
 * Digit number, number to display, COM
 */
const uint32_t lcd_digits[4][11][4] = {
    /* Digit 1 */
    {
        /* 1 */
        {LCD_SEG_7, 0, LCD_SEG_7, 0},
        /* 2 */
        {
             LCD_SEG_7 | LCD_SEG_8, /* COM1 */
             LCD_SEG_7,             /* COM2 */
             LCD_SEG_8,             /* COM3 */
             LCD_SEG_7              /* COM4 */
        },
    },
    /* Digit 2 */
    {
        /* 1 */
        {LCD_SEG_5, 0, LCD_SEG_5, 0},
        /* 2 */
        {
             LCD_SEG_5 | LCD_SEG_6, /* COM1 */
             LCD_SEG_5,             /* COM2 */
             LCD_SEG_6,             /* COM3 */
             LCD_SEG_5              /* COM4 */
        },
    },
    /* Digit 3 */
    {
        /* 1 */
        {LCD_SEG_3, 0, LCD_SEG_3, 0},
        /* 2 */
        {
             LCD_SEG_3 | LCD_SEG_4, /* COM1 */
             LCD_SEG_3,             /* COM2 */
             LCD_SEG_4,             /* COM3 */
             LCD_SEG_3              /* COM4 */
        },
    },
    /* Digit 4 */
    {
        /* 1 */
        {LCD_SEG_1, 0, LCD_SEG_1, 0},
        /* 2 */
        {
             LCD_SEG_1 | LCD_SEG_2, /* COM1 */
             LCD_SEG_1,             /* COM2 */
             LCD_SEG_2,             /* COM3 */
             LCD_SEG_1              /* COM4 */
        },
    },
};

void LCD_display(LCD_HandleTypeDef *hlcd, uint16_t num) {

    /* First digit */
    LCD->RAM[LCD_RAM_REGISTER0] = lcd_digits[0][num][0];
    LCD->RAM[LCD_RAM_REGISTER2] = lcd_digits[0][num][1];
    LCD->RAM[LCD_RAM_REGISTER4] = lcd_digits[0][num][2];
    LCD->RAM[LCD_RAM_REGISTER6] = lcd_digits[0][num][3];

    /* Second digit */
    LCD->RAM[LCD_RAM_REGISTER0] = lcd_digits[1][num][0];
    LCD->RAM[LCD_RAM_REGISTER2] = lcd_digits[1][num][1];
    LCD->RAM[LCD_RAM_REGISTER4] = lcd_digits[1][num][2];
    LCD->RAM[LCD_RAM_REGISTER6] = lcd_digits[1][num][3];

    /* Third digit */
    LCD->RAM[LCD_RAM_REGISTER0] = lcd_digits[2][num][0];
    LCD->RAM[LCD_RAM_REGISTER2] = lcd_digits[2][num][1];
    LCD->RAM[LCD_RAM_REGISTER4] = lcd_digits[2][num][2];
    LCD->RAM[LCD_RAM_REGISTER6] = lcd_digits[2][num][3];

    /* Forth digit */
    LCD->RAM[LCD_RAM_REGISTER0] = lcd_digits[3][num][0];
    LCD->RAM[LCD_RAM_REGISTER2] = lcd_digits[3][num][1];
    LCD->RAM[LCD_RAM_REGISTER4] = lcd_digits[3][num][2];
    LCD->RAM[LCD_RAM_REGISTER6] = lcd_digits[3][num][3];

    HAL_LCD_UpdateDisplayRequest(hlcd);
}
