/**
 * Using the HAL library
 */

#include "stm32l0xx.h"
#include "stm32l0xx_nucleo.h"

int
main (void)
{

  HAL_Init();
  BSP_LED_Init(LED2);

  while (1)
    {
      BSP_LED_Toggle(LED2);
      HAL_Delay(500);
    }

}
