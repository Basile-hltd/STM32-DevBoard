#include <stdint.h>

#define RCC             (*(volatile uint32_t *)0x40021000UL)
#define RCC_IOPENR      (*(volatile uint32_t *)0x40021034UL)

#define GPIOF           (*(volatile uint32_t *)0x50001400UL)
#define GPIOF_MODER     (*(volatile uint32_t *)0x50001400UL)
#define GPIOF_OTYPER    (*(volatile uint32_t *)0x50001404UL)
#define GPIOF_PUPDR     (*(volatile uint32_t *)0x5000140CUL)
#define GPIOF_ODR       (*(volatile uint32_t *)0x50001414UL)

int main();

void reset_handler(void){
    main();
}

void default_handler(void){ while(1){} }

// Table des vecteurs — placée en 0x08000000 par le linker
__attribute__((section(".vectors")))
void (* const vectors[])(void) = {
    (void (*)(void))0x20002000,  // sommet de la pile (SRAM = 0x20000000 + 8KB)
    reset_handler,               // reset
    default_handler,             // NMI
    default_handler,             // HardFault
};

int main(){
    
    RCC_IOPENR |=  0x0000002F; // xxxxxxxx xxxxxxxx xxxxxxxx xx1x1111 

    GPIOF_MODER &=  ~0x00000003; // xxxxxxxx xxxxxxxx xxxxxxxx xxxxxx01 
    GPIOF_MODER |=  0x00000001; // xxxxxxxx xxxxxxxx xxxxxxxx xxxxxx01
    
    GPIOF_OTYPER |= 0x00000001; // xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxx1 

    while(1){
        GPIOF_ODR = GPIOF_ODR ^ 0x00000001;
    }

}

