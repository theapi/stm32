/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32l0xx.h"
#include "stm32l0xx_nucleo.h"
			

int main(void)
{
	HAL_Init();

	// Output the clock to PA8
	HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_SYSCLK, RCC_MCODIV_1);

	while(1) {

	}
}
