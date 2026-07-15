
typedef enum rgb_led_color
{
    WHITE = 0,
    CYAN = 1,
    PURPLE = 2,
    BLUE = 3,
    YELLOW = 4,
    GREEN = 5,
    RED = 6,
    BLACK = 7,

    RGB_LED_COLOR_COUNT

} rgb_led_color;

void RGB_Off(void);
void RGB_SetColor(rgb_led_color color_arg);