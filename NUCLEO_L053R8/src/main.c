/**
 * Hello world
 *
 * From https://www.youtube.com/watch?v=GSqrT7t1vAc&index=8&list=PL6PplMTH29SHgRPDufZhfMRoFwRAIrzOp
 * with changes for the STM32LO53
 */

#include "stm32l0xx.h"
#include "stm32l0xx_nucleo.h"

void
waitForAMoment (int moment)
{
  volatile int i, j;
  for (i = 0; i < moment; ++i)
    {
      j++;
    }
}

int
main (void)
{
  // Enable GPIOA clock
  RCC->IOPENR |= RCC_IOPENR_IOPAEN;
  // Pin 5 output mode: 01
  // - first set as: 00
  GPIOA->MODER &= ~(GPIO_MODER_MODE5);
  // - then set: 01
  GPIOA->MODER |= GPIO_MODER_MODE5_0;
  // Output type Push/Pull
  GPIOA->OTYPER &= ~(GPIO_OTYPER_OT_5);
  // Pin speed - low speed: 00 (inverse of 11)
  GPIOA->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEED5);
  // No pull up nor pull down
  GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD5);

  while (1)
    {
      // Turn on the led
      GPIOA->BSRR |= GPIO_BSRR_BS_5;

      // Delay
      waitForAMoment(200000);

      // Turn off the led
      GPIOA->BRR |= GPIO_BRR_BR_5;

      // Delay
      waitForAMoment(100000);

    }
}
