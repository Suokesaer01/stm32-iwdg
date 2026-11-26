#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Key.h"
int main(void)
{
	
	OLED_Init();	
  Key_Init();
	
  OLED_ShowString(3,3,"STOP");
	Delay_ms(300);
	OLED_ShowString(3,3,"     ");
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
  IWDG_SetPrescaler(IWDG_Prescaler_16);
  IWDG_SetReload(2499);
  IWDG_ReloadCounter();
  IWDG_Enable();
	
	
	while (1)
	{
		Key_GetNum();
		
	  IWDG_ReloadCounter();
		OLED_ShowNum(4, 1, GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1), 1);
    OLED_ShowNum(4, 3, GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11), 1);
		OLED_ShowString(2,3,"FEED");
		Delay_ms(300);
		OLED_ShowString(2,3,"     ");
		Delay_ms(300);
	}
}