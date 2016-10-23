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

int main(void) {

	leds_init();

	while (1) {

	}
}
