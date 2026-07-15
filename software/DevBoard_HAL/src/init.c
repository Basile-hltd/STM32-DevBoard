#include "STM32_DevBoard.h"

void STM32_DevBoard_HAL_Init(void){

    //========== Flash init ==========

    FLASH_ACR |= 0x00000001;        // xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxx1
    while ((FLASH_ACR & 0x00000001) == 0);

    //========== END Flash init ==========

    //========== Clock init ==========

    RCC_CR &= ~0x00003800;             // xxxxxxxx xxxxxxxx xx000xxx xxxxxxxx
    while ((RCC_CR & 0x00003800) >= 1);

    RCC_APBENR1 |= 0x00000001;      // xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxx1
    while ((RCC_APBENR1 & 0x00000001) == 0);

    //========== END Clock init ==========

    //========== RGB_Led init ==========

    RCC_IOPENR |=  0x0000002F;      // xxxxxxxx xxxxxxxx xxxxxxxx xx1x1111 

    GPIOF_MODER &=  ~0x000000CF;    // xxxxxxxx xxxxxxxx xxxxxxxx 00xx0000 
    GPIOF_MODER |=  0x00000045;     // xxxxxxxx xxxxxxxx xxxxxxxx 01xx0101
    
    GPIOF_OTYPER |= 0x0000000B;     // xxxxxxxx xxxxxxxx xxxxxxxx xxxx1011

    //========== END RGB_Led init ==========
    
    //========== Delay init ==========

    TIM2_PSC = 48000 - 1;           // (PSC+1) = 48 → 48MHz/48000 = 1kHz → tick = 1ms
    TIM2_ARR = 0xFFFFFFFF;
    TIM2_CR1 |= 0x0084;             // xxxx0x00 10000100 

    TIM2_EGR |= 0x0001;
    TIM2_SR &= ~0x0001;

    TIM2_CR1 |= 0x0001;             // xxxxxxxx xxxxxxx1 

    TIM2_CNT = 0;

    //========== END Delay init ========== 
}