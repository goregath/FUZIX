#include "picosdk.h"
#include <pico/multicore.h>
#include <u8g2.h>
#include <hardware/spi.h>

#include "ssd1320z2.h"

static u8g2_t u8g2;

static uint8_t u8x8_byte_pico_hw_spi(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr) {
    uint8_t *data;
    switch (msg) {
        case U8X8_MSG_BYTE_SEND:
            data = (uint8_t *)arg_ptr;
            spi_write_blocking(VT_SPI_MOD, data, arg_int);
            break;
        case U8X8_MSG_BYTE_INIT:
            u8x8_gpio_SetCS(u8x8, u8x8->display_info->chip_disable_level);
            break;
        case U8X8_MSG_BYTE_SET_DC:
            u8x8_gpio_SetDC(u8x8, arg_int);
            break;
        case U8X8_MSG_BYTE_START_TRANSFER:
            u8x8_gpio_SetCS(u8x8, u8x8->display_info->chip_enable_level);
            u8x8->gpio_and_delay_cb(u8x8, U8X8_MSG_DELAY_NANO,u8x8->display_info->post_chip_enable_wait_ns, NULL);
            break;
        case U8X8_MSG_BYTE_END_TRANSFER:
            u8x8->gpio_and_delay_cb(u8x8, U8X8_MSG_DELAY_NANO, u8x8->display_info->pre_chip_disable_wait_ns, NULL);
            u8x8_gpio_SetCS(u8x8, u8x8->display_info->chip_disable_level);
            break;
        default:
            return 0;
    }
    return 1;
}

static uint8_t u8x8_gpio_and_delay_pico(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr) {
    switch (msg) {
        case U8X8_MSG_GPIO_AND_DELAY_INIT: 
            spi_init(VT_SPI_MOD, VT_SPI_SPEED);
            gpio_init(VT_SCL);
            gpio_init(VT_SDA);
            gpio_init(VT_RES);
            gpio_init(VT_DC);
            gpio_init(VT_CS1);
            gpio_init(VT_CS2);
            gpio_set_function(VT_SCL, GPIO_FUNC_SPI);
            gpio_set_function(VT_SDA, GPIO_FUNC_SPI);
            gpio_set_function(VT_RES, GPIO_FUNC_SIO);
            gpio_set_function(VT_DC, GPIO_FUNC_SIO);
            gpio_set_function(VT_CS1, GPIO_FUNC_SIO);
            gpio_set_function(VT_CS2, GPIO_FUNC_SIO);
            gpio_set_dir(VT_RES, true);
            gpio_set_dir(VT_DC, true);
            gpio_set_dir(VT_CS1, true);
            gpio_set_dir(VT_CS2, true);
            gpio_put(VT_RES, 1);
            gpio_put(VT_CS1, 1);
            gpio_put(VT_CS2, 0);
            gpio_put(VT_DC, 0);
            break;
        case U8X8_MSG_DELAY_NANO: // delay arg_int * 1 nano second
            sleep_us(arg_int); // 1000 times slower, though generally fine in practice given rp2040 has no `sleep_ns()`
            break;
        case U8X8_MSG_DELAY_100NANO: // delay arg_int * 100 nano seconds
            sleep_us(arg_int);
            break;
        case U8X8_MSG_DELAY_10MICRO: // delay arg_int * 10 micro seconds
            sleep_us(arg_int * 10);
            break;
        case U8X8_MSG_DELAY_MILLI: // delay arg_int * 1 milli second
            sleep_ms(arg_int);
            break;
        case U8X8_MSG_GPIO_CS: // CS (chip select) pin: Output level in arg_int
            gpio_put(VT_CS1, arg_int);
            break;
        case U8X8_MSG_GPIO_DC: // DC (data/cmd, A0, register select) pin: Output level
            gpio_put(VT_DC, arg_int);
            break;
        case U8X8_MSG_GPIO_RESET: // Reset pin: Output level in arg_int
            gpio_put(VT_RES, arg_int);  // printf("U8X8_MSG_GPIO_RESET %d\n", arg_int);
            break;
        default:
            u8x8_SetGPIOResult(u8x8, 1); // default return value
            break;
    }
    return 1;
}

static void draw_display() {
    char hey[12] = "Hello world";
    u8g2_ClearBuffer(&u8g2);
    u8g2_ClearDisplay(&u8g2);
    u8g2_SetDrawColor(&u8g2, 1);
    u8g2_SetFont(&u8g2, u8g2_font_5x8_tf);
    u8g2_DrawStr(&u8g2, 10, 10, hey);
    u8g2_UpdateDisplay(&u8g2);
}

void display_init() {
    u8g2_Setup_ssd1320_160x132_f(&u8g2, U8G2_R0, u8x8_byte_pico_hw_spi, u8x8_gpio_and_delay_pico);
    u8g2_InitDisplay(&u8g2); // send init sequence to the display, display is in sleep mode after this,
    u8g2_SetPowerSave(&u8g2, 0);
    draw_display();
}
