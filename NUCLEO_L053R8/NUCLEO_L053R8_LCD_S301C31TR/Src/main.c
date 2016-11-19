/**
  *
  * Drive the 3 digit 7 segment LCD display LCD-S301C31TR at ~50Hz
  * http://uk.farnell.com/lumex/lcd-s301c31tr/lcd-3-digit-0-31-7-87mm-reflective/dp/1838930
  *
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32l0xx_hal.h"
#include "lcd.h"
#include "gpio.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void Error_Handler(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_LCD_Init();

  /* USER CODE BEGIN 2 */

  /*

             A
        ----------
        |         |
       F|         |B
        |         |
        -----G-----
        |         |
       E|         |C
        |         |  _
        ----------- |_|DP
             D

   */

    /* Segment pin mappings */
    /* Digit 1 */
    const uint32_t seg_e1  = 0b00000000000000000000000000100000; /* LCD_SEG5 */
    const uint32_t seg_d1  = 0b00000000000000000000000001000000; /* LCD_SEG6 */
    const uint32_t seg_c1  = 0b00000000000000000000000010000000; /* LCD_SEG7 */
    const uint32_t seg_dp1 = 0b00000000000000000000000100000000; /* LCD_SEG8 */
    const uint32_t seg_b1  = 0b00000000000000000000001000000000; /* LCD_SEG9 */
    const uint32_t seg_g1  = 0b00000000000000000000010000000000; /* LCD_SEG10 */
    const uint32_t seg_f1  = 0b00000000000000000000100000000000; /* LCD_SEG11 */
    const uint32_t seg_a1  = 0b00000000000000000001000000000000; /* LCD_SEG12 */
    /* Digit 2 */
    const uint32_t seg_e2  = 0b00000000000000000010000000000000; /* LCD_SEG13 */
    const uint32_t seg_d2  = 0b00000000000000000100000000000000; /* LCD_SEG14 */
    const uint32_t seg_c2  = 0b00000000000000001000000000000000; /* LCD_SEG15 */
    const uint32_t seg_dp2 = 0b00000000000000010000000000000000; /* LCD_SEG16 */
    const uint32_t seg_b2  = 0b00000000000000100000000000000000; /* LCD_SEG17 */
    const uint32_t seg_g2  = 0b00000000000001000000000000000000; /* LCD_SEG18 */
    const uint32_t seg_f2  = 0b00000000000010000000000000000000; /* LCD_SEG19 */
    const uint32_t seg_a2  = 0b00000000000100000000000000000000; /* LCD_SEG20 */
    /* Digit 3 */
    const uint32_t seg_e3  = 0b00000000001000000000000000000000; /* LCD_SEG21 */
    const uint32_t seg_d3  = 0b00000000010000000000000000000000; /* LCD_SEG22 */
    const uint32_t seg_c3  = 0b00000000100000000000000000000000; /* LCD_SEG23 */
    const uint32_t seg_b3  = 0b00000001000000000000000000000000; /* LCD_SEG24 */
    const uint32_t seg_g3  = 0b00000010000000000000000000000000; /* LCD_SEG25 */
    const uint32_t seg_f3  = 0b00000100000000000000000000000000; /* LCD_SEG26 */
    const uint32_t seg_a3  = 0b00001000000000000000000000000000; /* LCD_SEG27 */

    const uint32_t character_map[32] = {
        seg_a1 | seg_b1 | seg_c1 | seg_d1 | seg_e1 | seg_f1,          /* 0 */
        seg_b1 | seg_c1,                                              /* 1 */
        seg_a1 | seg_b1 | seg_g1 | seg_e1 | seg_d1,                   /* 2 */
        seg_a1 | seg_b1 | seg_g1 | seg_c1 | seg_d1,                   /* 3 */
        seg_f1 | seg_b1 | seg_g1 | seg_c1,                            /* 4 */
        seg_a1 | seg_f1 | seg_g1 | seg_c1 | seg_d1,                   /* 5 */
        seg_f1 | seg_e1 | seg_g1 | seg_c1 | seg_d1,                   /* 6 */
        seg_a1 | seg_b1 | seg_c1,                                     /* 7 */
        seg_a1 | seg_b1 | seg_c1 | seg_d1 | seg_e1 | seg_f1 | seg_g1, /* 8 */
        seg_a1 | seg_b1 | seg_c1 | seg_f1 | seg_g1,                   /* 9 */
        seg_dp1,                                                      /* . */

        seg_a2 | seg_b2 | seg_c2 | seg_d2 | seg_e2 | seg_f2,          /* 0 */
        seg_b2 | seg_c2,                                              /* 1 */
        seg_a2 | seg_b2 | seg_g2 | seg_e2 | seg_d2,                   /* 2 */
        seg_a2 | seg_b2 | seg_g2 | seg_c2 | seg_d2,                   /* 3 */
        seg_f2 | seg_b2 | seg_g2 | seg_c2,                            /* 4 */
        seg_a2 | seg_f2 | seg_g2 | seg_c2 | seg_d2,                   /* 5 */
        seg_f2 | seg_e2 | seg_g2 | seg_c2 | seg_d2,                   /* 6 */
        seg_a2 | seg_b2 | seg_c2,                                     /* 7 */
        seg_a2 | seg_b2 | seg_c2 | seg_d2 | seg_e2 | seg_f2 | seg_g2, /* 8 */
        seg_a2 | seg_b2 | seg_c2 | seg_f2 | seg_g2,                   /* 9 */
        seg_dp2,                                                      /* . */

        seg_a3 | seg_b3 | seg_c3 | seg_d3 | seg_e3 | seg_f3,          /* 0 */
        seg_b3 | seg_c3,                                              /* 1 */
        seg_a3 | seg_b3 | seg_g3 | seg_e3 | seg_d3,                   /* 2 */
        seg_a3 | seg_b3 | seg_g3 | seg_c3 | seg_d3,                   /* 3 */
        seg_f3 | seg_b3 | seg_g3 | seg_c3,                            /* 4 */
        seg_a3 | seg_f3 | seg_g3 | seg_c3 | seg_d3,                   /* 5 */
        seg_f3 | seg_e3 | seg_g3 | seg_c3 | seg_d3,                   /* 6 */
        seg_a3 | seg_b3 | seg_c3,                                     /* 7 */
        seg_a3 | seg_b3 | seg_c3 | seg_d3 | seg_e3 | seg_f3 | seg_g3, /* 8 */
        seg_a3 | seg_b3 | seg_c3 | seg_f3 | seg_g3,                   /* 9 */
    };

  int count = 0;


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

      LCD->RAM[LCD_RAM_REGISTER0] = character_map[count];
      //LCD->RAM[LCD_RAM_REGISTER0] = seg_a3;
      HAL_LCD_UpdateDisplayRequest(&hlcd);
      HAL_Delay(1000);

      count++;
      if (count > 31) {
          count = 0;
      }

  }
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_5;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

