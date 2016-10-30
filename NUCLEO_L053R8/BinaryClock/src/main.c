/**
 * Binary Clock
 */

#include "stm32l0xx.h"
#include "stm32l0xx_nucleo.h"

/**
 * Initialise 12 pins of port B as outputs.
 * Pins: 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4
 * NB: not pin 3 as that is SWO
 */
void leds_init() {
	// Enable GPIOB
	RCC->IOPENR |= RCC_IOPENR_IOPBEN;

	// All outputs except the the first 4 which are set to the reset value.
	// 01010101 01010101 01010101 11111111
	GPIOB->MODER = 0x555555FF;

	// Output type Push/Pull (the reset value)
	GPIOB->OTYPER = 0x00000000;

	// Pin speed - low speed (the reset value)
	GPIOB->OSPEEDR = 0x00000000;

	// No pull up nor pull down (the reset value)
	GPIOB->PUPDR = 0x00000000;

	// Turn on all the leds (1111111111110000).
	GPIOB->BSRR = 0xFFF0;
}

/**
 * Initialise the on board USER button: PORT C, PIN 13
 */
void button_init() {
	// Enable GPIOC
	RCC->IOPENR |= RCC_IOPENR_IOPCEN;
	// Input mode: 00
	GPIOC->MODER &= ~(GPIO_MODER_MODE13);
	// Hard wired as a pull up.
}

void dumbDelay(int cycles) {
	volatile int i, j;
	for (i = 0; i < cycles; ++i) {
		j++;
	}
}

char press_handled = 0;
char hours = 0;
char minutes = 0;

int main(void) {

	leds_init();
	button_init();

	while (1) {

		dumbDelay(10000);
		minutes++;

		if (minutes == 60) {
			hours++;
			minutes = 0;
		}
		if (hours == 24) {
			hours = 0;

		}

		// hours = pins 8, 7, 6, 5, 4
		// shift the hours over 4 places.
		// minutes = pins 15, 14, 13, 12, 11, 10
		// shift the minutes over 4 places.
		GPIOB->ODR = (hours << 4) | (minutes << 10);

	}

}

