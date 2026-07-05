#include "STM32_DevBoard.h"

int main(){
    
    STM32_DevBoard_HAL_Init();

    RGB_Off();

    rgb_led_color color = BLACK;

    while(1){
        color = (color + 1) % RGB_LED_COLOR_COUNT;
        RGB_SetColor(color);

        for (volatile uint32_t i = 0; i != 0x000FFFFF; i++);
        
    }

}

