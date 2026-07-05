
#include "STM32_DevBoard.h"

void RGB_Off(void){
    GPIOF_ODR = GPIOF_ODR | 0x0000000B; //00000000 00000000 00000000 00001011  
}

void RGB_SetColor(rgb_led_color color_arg){

    uint8_t color = 0x00;

    color = color | (color_arg & 0x03);
    color = color | ((color_arg & 0x04) << 1);
    
    GPIOF_ODR = (GPIOF_ODR & ~0x0B) | color;
}