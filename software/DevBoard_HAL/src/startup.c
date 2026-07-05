extern int main(void);

void reset_handler(void){
    main();
}

void default_handler(void){ 
    while(1){} 
}

__attribute__((section(".vectors")))
void (* const vectors[])(void) = {
    (void (*)(void))0x20002000,  // sommet de la pile - stack pointer 
    reset_handler,               // reset
    default_handler,             // NMI
    default_handler,             // HardFault
    0, 0, 0, 0, 0, 0, 0          // reserved
};