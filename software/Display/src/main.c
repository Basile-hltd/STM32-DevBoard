#include "STM32_DevBoard.h"

int main(){
    
    STM32_DevBoard_HAL_Init();

    for (char c = '0'; c <= '9'; c++){
        draw_char(1+c-'0', 1, c);
    }

    while(1){

    }

}

