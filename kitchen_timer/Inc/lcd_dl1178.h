/**
 * DL1178 lcd screen found in generic large screen kitchen timers like this:
 * https://www.amazon.co.uk/Mudder-Magnetic-Digital-Kitchen-Display/dp/B016EHCJFG
 * Datasheet is in the docs folder.
 *
 * 3V, 1/4 Duty, 1/2 Bias
 *
 *

           A
      ----------
      |         |
     F|         |B
      |         |
      -----G-----
      |         |
     E|         |C
      |         |    _   _
      -----------   |_| |_|COLON (colon is AM PM)
           D


 *
 */

#ifndef __lcd_dl1178_H
#define __lcd_dl1178_H
#ifdef __cplusplus
 extern "C" {
#endif


#define LCD_SEG_1 0b00000000000000000000000000000001
#define LCD_SEG_2 0b00000000000000000000000000000010
#define LCD_SEG_3 0b00000000000000000000000000000100
#define LCD_SEG_4 0b00000000000000000000000000001000
#define LCD_SEG_5 0b00000000000000000000000000010000
#define LCD_SEG_6 0b00000000000000000000000000100000
#define LCD_SEG_7 0b00000000000000000000000001000000
#define LCD_SEG_8 0b00000000000000000000000010000000

/*
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

/**
 * Digit number, number to display, COM
 */
uint32_t lcd_digits[4][11][4] = {
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
    { /* Digit 2 */
        {LCD_SEG_5, 0, LCD_SEG_5, 0}, /* 1 */
    },
};


void LCD_display(LCD_HandleTypeDef *hlcd, uint16_t num);
uint32_t LCD_digit1(uint8_t num);
uint32_t LCD_digit2(uint8_t num);
uint32_t LCD_digit3(uint8_t num);


#ifdef __cplusplus
}
#endif
#endif /*__lcd_dl1178_H */

