
#include "STM32_DevBoard.h"

void Delay(uint32_t ms){
    TIM2_CNT = 0;

    while (TIM2_CNT < ms);
    
}