#include "STM32_DevBoard.h"

static inline void cs_low(void)    { GPIOD_BSRR = (1U << 16); }      // PD0 = 0
static inline void cs_high(void)   { GPIOD_BSRR = (1U << 0);  }      // PD0 = 1

static inline void dc_cmd(void)    { GPIOD_BSRR = (1U << 18); }      // PD2 = 0 (commande)
static inline void dc_data(void)   { GPIOD_BSRR = (1U << 2);  }      // PD2 = 1 (donnée)

static inline void rst_low(void)   { GPIOD_BSRR = (1U << 19); }      // PD3 = 0
static inline void rst_high(void)  { GPIOD_BSRR = (1U << 3);  }      // PD3 = 1

static uint8_t spi1_transfer(uint8_t data) {
    RGB_SetColor(RED);
    while (!(SPI1_SR & (1U << 1)));   // attendre TXE
    *(volatile uint8_t *)&SPI1_DR = data;
    while (!(SPI1_SR & (1U << 0)));   // attendre RXNE
    uint8_t rx = *(volatile uint8_t *)&SPI1_DR;
    RGB_SetColor(GREEN);
    return rx;
}

static void spi1_write_cmd(uint8_t cmd) {
    dc_cmd();
    cs_low();
    spi1_transfer(cmd);
    cs_high();
}

static void spi1_write_data(uint8_t data) {
    dc_data();
    cs_low();
    spi1_transfer(data);
    cs_high();
}

void st7735_init(void) {

    // Reset matériel
    rst_low();
    Delay(20);
    rst_high();
    Delay(150);

    spi1_write_cmd(0x01);  // SWRESET
    Delay(150);

    spi1_write_cmd(0x11);  // SLPOUT (sortie veille)
    Delay(150);

    spi1_write_cmd(0x3A);  // COLMOD
    spi1_write_data(0x05); // 16 bits/pixel (RGB565)
    Delay(10);

    spi1_write_cmd(0x36);  // MADCTL (orientation)
    spi1_write_data(0x00);

    spi1_write_cmd(0x29);  // DISPON
    Delay(100);

}

#define ST7735_WIDTH  160
#define ST7735_HEIGHT 80

void st7735_fill_red(void) {
    // Définir la fenêtre = tout l'écran
    spi1_write_cmd(0x2A); // CASET (column address)
    spi1_write_data(0x00);
    spi1_write_data(0x00);
    spi1_write_data(0x00);
    spi1_write_data(ST7735_WIDTH - 1);

    spi1_write_cmd(0x2B); // RASET (row address)
    spi1_write_data(0x00);
    spi1_write_data(0x00);
    spi1_write_data(0x00);
    spi1_write_data(ST7735_HEIGHT - 1);

    spi1_write_cmd(0x2C); // RAMWR (écriture mémoire)

    // Rouge pur en RGB565 = 0xF800
    dc_data();
    cs_low();
    for (uint32_t i = 0; i < (uint32_t)ST7735_WIDTH * ST7735_HEIGHT; i++) {
        spi1_transfer(0xF8); // octet haut
        spi1_transfer(0x00); // octet bas
    }
    cs_high();
}

int main(){
    
    STM32_DevBoard_HAL_Init();

    RGB_Off();

    st7735_init();
    st7735_fill_red();

    while(1){

    }

}

