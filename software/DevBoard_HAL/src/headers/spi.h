void st7735_cs_low(void);
void st7735_cs_high(void);

uint8_t spi1_transfer(uint8_t data);

void st7735_spi_write_cmd(uint8_t cmd);
void st7735_spi_write_data(uint8_t data);