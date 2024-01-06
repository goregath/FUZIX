// vim: sw=4:ts=4

#include "picosdk.h"
#include <pico/time.h>
#include <hardware/spi.h>

#include <kernel.h>
#include <vt.h>

#include "config.h"
#include "ssd1320z2.h"

#define COMREG true
#define PIXBUF false

#define HIGH true
#define LOW false

static const uint8_t m4[] = {
    0x00, 0x00,
    0x00, 0xf0,
    0x00, 0x0f,
    0x00, 0xff,
    0xf0, 0x00,
    0xf0, 0xf0,
    0xf0, 0x0f,
    0xf0, 0xff,
    0x0f, 0x00,
    0x0f, 0xf0,
    0x0f, 0x0f,
    0x0f, 0xff,
    0xff, 0x00,
    0xff, 0xf0,
    0xff, 0x0f,
    0xff, 0xff,
};

static uint8_t deltay = 0;

static void rawsetall(bool dc, uint8_t b0) {
    gpio_put(VT_DC, !dc);
    gpio_put(VT_CS1, LOW);
    gpio_put(VT_CS2, LOW);
    spi_write_blocking(VT_SPI_MOD, &b0, 1);
    gpio_put(VT_CS1, HIGH);
    gpio_put(VT_CS2, HIGH);
    gpio_put(VT_DC, HIGH);
}

static void rawset(bool dc, unsigned int cs, uint8_t b0) {
    gpio_put(VT_DC, !dc);
    gpio_put(cs, LOW);
    spi_write_blocking(VT_SPI_MOD, &b0, 1);
    gpio_put(cs, HIGH);
    gpio_put(VT_DC, HIGH);
}

static void clear(uint8_t color) {
    rawsetall(COMREG, 0x21);
    rawsetall(COMREG, 0);
    rawsetall(COMREG, 79);
    rawsetall(COMREG, 0x22);
    rawsetall(COMREG, 0);
    rawsetall(COMREG, 159);
    gpio_put(VT_CS1, LOW);
    gpio_put(VT_CS2, LOW);
    for (int i = 0; i < 80 * 160; i++) {
        spi_write_blocking(VT_SPI_MOD, &color, 1);
    }
    gpio_put(VT_CS1, HIGH);
    gpio_put(VT_CS2, HIGH);
}

void display_init() {
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
    gpio_set_function(VT_DC,  GPIO_FUNC_SIO);
    gpio_set_function(VT_CS1, GPIO_FUNC_SIO);
    gpio_set_function(VT_CS2, GPIO_FUNC_SIO);
    gpio_set_dir(VT_RES, true);
    gpio_set_dir(VT_DC,  true);
    gpio_set_dir(VT_CS1, true);
    gpio_set_dir(VT_CS2, true);
    gpio_put(VT_RES, 1);
    gpio_put(VT_CS1, 1);
    gpio_put(VT_CS2, 1);
    gpio_put(VT_DC,  1);
    sleep_ms(1);
    // Display OFF
    rawsetall(COMREG, 0xae);
    // Set Command Lock
    rawsetall(COMREG, 0xfd); rawsetall(COMREG, 0x12);
    // Set Memory Addressing Mode
    rawsetall(COMREG, 0x20); rawsetall(COMREG, 0x00); // horizontal
    // Set Portrait Addressing Mode
    rawsetall(COMREG, 0x25); rawsetall(COMREG, 0x00); // normal
    // Set Contrast Control
    rawsetall(COMREG, 0x81); rawsetall(COMREG, 0x6b);
    // Set Segment Remap
    rawset(COMREG, VT_CS1, 0xa0); // column address 0  is mapped to SEG0
    rawset(COMREG, VT_CS2, 0xa1); // column address 97 is mapped to SEG0
    // Set Display Start Line
    rawsetall(COMREG, 0xa2); rawsetall(COMREG, deltay);
    // Resume to RAM content display
    rawsetall(COMREG, 0xa4);
    // Disable Panorama Mode
    rawsetall(COMREG, 0xa6);
    // Set MUX Ratio
    rawsetall(COMREG, 0xa8); rawsetall(COMREG, 0x83); // 1/132 duty
    // rawsetall(COMREG, 0xa8); rawsetall(COMREG, 0x10); // 1/132 duty
    // Select external or internal IREF
    rawsetall(COMREG, 0xad); rawsetall(COMREG, 0x10); // internal IREF during display ON
    // Set Pre-charge voltage
    rawsetall(COMREG, 0xbc); rawsetall(COMREG, 0x1e); // 0.5*VCC (reset)
    // Linear LUT
    rawsetall(COMREG, 0xbf);
    // Set COM Output Scan Direction
    rawset(COMREG, VT_CS1, 0xc8); // scan from COM[n-1] to COM[0]
    rawset(COMREG, VT_CS2, 0xc0); // scan from COM[0] to COM[n-1]
    // Set Display Offset (vertical shift by COM)
    rawsetall(COMREG, 0xd3);
    rawset(COMREG, VT_CS1, 0x0e);
    rawset(COMREG, VT_CS2, 0x92);
    // Set Display Clock Divide Ratio/Oscillator Frequency
    rawsetall(COMREG, 0xd5); rawsetall(COMREG, 0xc2); // 85Hz
    // Set Pre-charge Period
    rawsetall(COMREG, 0xd9); rawsetall(COMREG, 0x72);
    // Set SEG Pins Hardware Configuration
    rawsetall(COMREG, 0xda); rawsetall(COMREG, 0x12); // enable SEG left/right remap
    // rawsetall(COMREG, 0xda); rawsetall(COMREG, 0x32); // alternative odd/even, enable SEG left/right remap
    // Set VP
    rawsetall(COMREG, 0xbd); rawsetall(COMREG, 0x03);
    // Set VCOMH
    rawsetall(COMREG, 0xdb); rawsetall(COMREG, 0x30);
    // clear(0x00);
    // Display on
    rawsetall(COMREG, 0xaf);
}

#define GLYPH(c) (fontdata + (c >= 32 && c < 128 ? (size_t) ((c << 3) - 256) : 0))
#define MEMY(y) ((y * 8 + deltay) % 160)

extern unsigned char fontdata[];

uint8_t vtattr_cap = VTA_INVERSE | VTA_UNDERLINE;

void clear_lines(int8_t y, int8_t ct) {
    for (uint8_t i = 0; i < ct; i++) {
        clear_across(y+i, 0, VT_RIGHT + 1);
    }
}

void clear_across(int8_t y, int8_t x, int16_t l) {
    // TODO rewrite
    uint8_t x2 = x + l;
    for (size_t i = 0; i < l; i++) {
        plot_char(y, x+i, 0x20);
    }
}

void cursor_off(void) {}

void cursor_on(int8_t y, int8_t x) {}
void cursor_disable(void) {}

void scroll_up(void) {
    deltay = (deltay + 8) % 160;
    rawsetall(COMREG, 0xa2);
    rawsetall(COMREG, deltay);
}

void scroll_down(void) {
    deltay = (deltay + 160 - 8) % 160;
    rawsetall(COMREG, 0xa2);
    rawsetall(COMREG, deltay);
}

void do_beep(void) {}
void vtattr_notify(void) {}

void plot_char(int8_t y, int8_t x, uint16_t c) {
    static uint8_t cmd[6] = { 0x21, 0, 0, 0x22, 0, 159 };
    uint16_t *m4g16 = (uint16_t *) m4;
    uint16_t raw[16];
    unsigned int cs;
    x *= 4;
    if (x < 79) {
        cs = VT_CS1;
    } else {
        x -= 80;
        cs = VT_CS2;
    }
    cmd[1] = x;
    cmd[2] = x + 3;
    cmd[4] = MEMY(y);
    gpio_put(VT_DC, LOW);
    gpio_put(cs, LOW);
    spi_write_blocking(VT_SPI_MOD, cmd, 6);
    gpio_put(VT_DC, HIGH);
    uint8_t *bmp = GLYPH(c);
    for (size_t i = 0; i < 16; i+=2, bmp++) {
        size_t un = ((*bmp) & 0xf0) >> 4;
        size_t ln = (*bmp) & 0x0f;
        raw[i] = m4g16[un];
        raw[i + 1] = m4g16[ln];
    }
    spi_write_blocking(VT_SPI_MOD, (uint8_t *) raw, 32);
    gpio_put(cs, HIGH);
}

// uint8_t vtattr;
// uint8_t vtattr_cap;
// uint8_t vtink;
// uint8_t vtpaper;
// struct vt_repeat keyrepeat;

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
        case U8X8_MSG_BYTE_START_TRAlenafortgirlNSFER:
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

