// vim: sw=4:ts=4

#include "picosdk.h"
#include <hardware/spi.h>

#include "ssd1320z2.h"

#define OLED_CMD true
#define OLED_DATA false

#define OLED_X_MAXPIXEL 320
#define OLED_Y_MAXPIXEL 132

#define WIDTH (256 / 4)
#define HEIGHT 132

#define HIGH true
#define LOW false

static void bootstrap() {
    // Display OFF
    rawsetall(OLED_CMD, 0xae);
    // Set Command Lock
    rawsetall(OLED_CMD, 0xfd); rawsetall(OLED_CMD, 0x12);
    // Set Memory Addressing Mode
    rawsetall(OLED_CMD, 0x20); rawsetall(OLED_CMD, 0x00); // horizontal
    // Set Portrait Addressing Mode
    rawsetall(OLED_CMD, 0x25); rawsetall(OLED_CMD, 0x00); // normal
    // Set Contrast Control
    rawsetall(OLED_CMD, 0x81); rawsetall(OLED_CMD, 0x6b);
    // Set Segment Remap
    rawset(OLED_CMD, OLED_CS1, 0xa0); // column address 0  is mapped to SEG0
    rawset(OLED_CMD, OLED_CS2, 0xa1); // column address 97 is mapped to SEG0
    // Set Display Start Line
    rawsetall(OLED_CMD, 0xa2); rawsetall(OLED_CMD, 0x00);
    // Resume to RAM content display
    rawsetall(OLED_CMD, 0xa4);
    // Disable Panorama Mode
    rawsetall(OLED_CMD, 0xa6);
    // Set MUX Ratio
    rawsetall(OLED_CMD, 0xa8); rawsetall(OLED_CMD, 0x9f); // default
    // rawsetall(OLED_CMD, 0xa8); rawsetall(OLED_CMD, 0x9f); // 1/132 duty
    // Select external or internal IREF
    rawsetall(OLED_CMD, 0xad); rawsetall(OLED_CMD, 0x10); // internal IREF during display ON
    // Set Pre-charge voltage
    rawsetall(OLED_CMD, 0xbc); rawsetall(OLED_CMD, 0x1e); // 0.5*VCC (reset)
    // Linear LUT
    rawsetall(OLED_CMD, 0xbf);
    // Set COM Output Scan Direction
    rawset(OLED_CMD, OLED_CS1, 0xc8); // scan from COM[n-1] to COM[0]
    rawset(OLED_CMD, OLED_CS2, 0xc0); // scan from COM[0] to COM[n-1]
    // Set Display Offset (vertical shift by COM)
    rawsetall(OLED_CMD, 0xd3);
    rawset(OLED_CMD, OLED_CS1, 0x0e);
    rawset(OLED_CMD, OLED_CS2, 0x92);
    // Set Display Clock Divide Ratio/Oscillator Frequency
    rawsetall(OLED_CMD, 0xd5); rawsetall(OLED_CMD, 0xc2); // 85Hz
    // Set Pre-charge Period
    rawsetall(OLED_CMD, 0xd9); rawsetall(OLED_CMD, 0x72);
    // Set SEG Pins Hardware Configuration
    rawsetall(OLED_CMD, 0xda); rawsetall(OLED_CMD, 0x32); // enable SEG left/right remap
    // Set VP
    rawsetall(OLED_CMD, 0xbd); rawsetall(OLED_CMD, 0x03);
    // Set VCOMH
    rawsetall(OLED_CMD, 0xdb); rawsetall(OLED_CMD, 0x30);
    OLED_Clear(0, 0, 320, 132, 0x00);
    // Display on
    rawsetall(OLED_CMD, 0xaf);
}

static void rawsetall(bool dc, uint8_t b0) {
    gpio_put(OLED_DC, !cmd);
    gpio_put(OLED_CS1, LOW);
    gpio_put(OLED_CS2, LOW);
    spi_write_blocking(VT_SPI_MOD, &b0, 1);
    gpio_put(OLED_CS1, HIGH);
    gpio_put(OLED_CS2, HIGH);
    gpio_put(OLED_DC, HIGH);
}

static void rawset(bool dc, bool cs, uint8_t b0) {
    gpio_put(OLED_DC, !cmd);
    gpio_put(cs, LOW);
    spi_write_blocking(VT_SPI_MOD, &data, 1);
    gpio_put(cs, HIGH);
    gpio_put(OLED_DC, HIGH);
}

static void setcaret(uint8_t x, uint8_t y) {

}

static void setaddr(uint8_t cs, uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2) {
    // 0x21,start,end (set column address)
    // 0x22,start,end (set row address)
    if(x2 < 80) {
        rawset(OLED_CMD, cs, 0x21);
        rawset(OLED_CMD, cs, x1);
        rawset(OLED_CMD, cs, x2);
        rawset(OLED_CMD, cs, 0x22);
        rawset(OLED_CMD, cs, y1);
        rawset(OLED_CMD, cs, y2);
    } else {
        rawset(OLED_CMD, OLED_CS1, 0x21);
        rawset(OLED_CMD, OLED_CS1, x1);
        rawset(OLED_CMD, OLED_CS1, 79);
        rawset(OLED_CMD, OLED_CS1, 0x22);
        rawset(OLED_CMD, OLED_CS1, y1);
        rawset(OLED_CMD, OLED_CS1, y2);
        rawset(OLED_CMD, OLED_CS2, 0x21);
        rawset(OLED_CMD, OLED_CS2, 0);
        rawset(OLED_CMD, OLED_CS2, x2 - 80);
        rawset(OLED_CMD, OLED_CS2, 0x22);
        rawset(OLED_CMD, OLED_CS2, y1);
        rawset(OLED_CMD, OLED_CS2, y2);
    }
}

/*
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
//    char hey[12] = "Hello world";
//    u8g2_ClearBuffer(&u8g2);
//    u8g2_ClearDisplay(&u8g2);
//    u8g2_SetDrawColor(&u8g2, 1);
//    u8g2_SetFont(&u8g2, u8g2_font_5x8_tf);
//    u8g2_DrawStr(&u8g2, 10, 10, hey);
//    u8g2_UpdateDisplay(&u8g2);
}

void display_init() {
    u8g2_Setup_ssd1320_160x132_f(&u8g2, U8G2_R0, u8x8_byte_pico_hw_spi, u8x8_gpio_and_delay_pico);
    u8g2_SetFont(&u8g2, u8g2_font_5x8_mr);
    // u8g2_InitDisplay(&u8g2); // send init sequence to the display, display is in sleep mode after this,
    // u8g2_SetPowerSave(&u8g2, 0);
    // draw_display();
}
*/

