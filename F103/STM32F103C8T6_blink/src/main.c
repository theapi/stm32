/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f1xx.h"
#include "stm32f1xx_nucleo.h"

void waitForAMoment(int moment) {
	volatile int i, j;
	for (i = 0; i < moment; ++i) {
		j++;
	}
}

static void MX_GPIO_Init(void) {

	GPIO_InitTypeDef GPIO_InitStruct;

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE()
	;

	/*Configure GPIO pin LED 1: PC13 */
	GPIO_InitStruct.Pin = GPIO_PIN_13;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}

int main(void) {

	//HAL_Init();

	MX_GPIO_Init();

	while (1) {
		// Turn off the led
		GPIOC->BSRR |= GPIO_BSRR_BS13;

		// Delay
		waitForAMoment(100000);
		//HAL_Delay(50); //@todo configure clock as this is slowwww

		// Turn on the led
		GPIOC->BRR |= GPIO_BRR_BR13;

		// Delay
		waitForAMoment(200000);
		//HAL_Delay(50);

	}
}
