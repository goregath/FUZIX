/**
 *  VT52 Driver for dual Solomon SSD1320Z OLED Modules.
 *
 *  ER-OLEDM0383-1: 3.83" OLED Module 320x132 SPI 16-Level Grayscale.
 */

// vim: sw=4:ts=4

#include "picosdk.h"
#include <hardware/spi.h>

#include <kernel.h>
#include <vt.h>

#include "config.h"
#include "ssd1320z2.h"

#ifndef VT_WIDTH
#define VT_WIDTH (VT_RIGHT + 1)
#endif

#ifndef VT_HEIGHT
#define VT_HEIGHT (VT_BOTTOM + 1)
#endif

#define COMS 80
#define SEGS 160

#define WIDTH  (COMS * 2)
#define HEIGHT 132

#define TOTAL_WIDTH  (WIDTH * 2)
#define TOTAL_HEIGHT HEIGHT

#define ADDRX(col) (col * FONT_WIDTH / 2 % COMS)
#define ADDRY(row) ((row * FONT_HEIGHT + lineaddr) % SEGS)
#define CHIP(col)  (col < VT_WIDTH / 2 ? VT_CS1 : VT_CS2)

#define COMREG true

#define HIGH true
#define LOW  false

#define FONT_WIDTH  4
#define FONT_HEIGHT 8

// TODO bitmasking ?
#define GLYPH(c) ((c > 31 && c < 127 ? fontdata + (size_t) ((c - 32) * FONT_WIDTH) : invalidchar))

#define COLORMASK(a) (a & 0x8 ? -1 : 0x8888)

// Font 4x8 monochrome horizontal
extern unsigned char fontdata[];
const unsigned char invalidchar[] = { 0x0e, 0xaa, 0xaa, 0xae };

// VT52 capabilities
uint8_t vtattr_cap = 0; // VTA_INVERSE | VTA_UNDERLINE;

// Line offset in display memory
static uint8_t lineaddr = 0;

// Map 4 monochrome pxels to 4x4 bit grayscale
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

/**
 *  Send command to all display controllers.
 */
static void rawsetall(bool dc, uint8_t b0) {
    gpio_put(VT_DC, !dc);
    gpio_put(VT_CS1, LOW);
    gpio_put(VT_CS2, LOW);
    spi_write_blocking(VT_SPI_MOD, &b0, 1);
    gpio_put(VT_CS1, HIGH);
    gpio_put(VT_CS2, HIGH);
    gpio_put(VT_DC, HIGH);
}

/**
 *  Send command to a specific controller.
 */
static void rawset(bool dc, unsigned int cs, uint8_t b0) {
    gpio_put(VT_DC, !dc);
    gpio_put(cs, LOW);
    spi_write_blocking(VT_SPI_MOD, &b0, 1);
    gpio_put(cs, HIGH);
    gpio_put(VT_DC, HIGH);
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
    rawsetall(COMREG, 0x81); rawsetall(COMREG, 0x40);
    // Set Segment Remap
    rawset(COMREG, VT_CS1, 0xa0); // column address 0  is mapped to SEG0
    rawset(COMREG, VT_CS2, 0xa1); // column address 97 is mapped to SEG0
    // Set Display Start Line
    rawsetall(COMREG, 0xa2); rawsetall(COMREG, lineaddr);
    // Resume to RAM content display
    rawsetall(COMREG, 0xa4);
    // Normal display mode
    rawsetall(COMREG, 0xa6);
    // Set MUX Ratio
    rawsetall(COMREG, 0xa8); rawsetall(COMREG, 0x83); // 1/132 duty
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
    // Display on
    rawsetall(COMREG, 0xaf);
}

/**
 *  Clear num lines starting at line y. They are cleared for the full width for the display. A request to clear zero
 *  lines should be handled.
 */
void clear_lines(int8_t y, int8_t ct) {
    // TODO slow - rewrite
    for (uint8_t i = 0; i < ct; i++) {
        clear_across(y+i, 0, VT_RIGHT + 1);
    }
}

/**
 *  Clear num characters across from y,x. The request will never span more than the one line. The normal case is from x
 *  to the right hand side of the display. A request to clear zero characters should be handled.
 */
void clear_across(int8_t y, int8_t x, int16_t l) {
    // TODO slow - rewrite
    uint8_t x2 = x + l;
    for (size_t i = 0; i < l; i++) {
        plot_char(y, x+i, 0x20);
    }
}

/**
 *  Hide the cursor, whether in hardware or software. If necessary restore any characters or attributes changed by
 *  cursor_on(). This routine can be a no-op if there is a hardware cursor and updating the display does not affect it.
 */
void cursor_off(void) { }

/**
 *  Turn the cursor back on at x,y. Ensure that any data that is needed to restore the display is saved so that
 *  cursor_off() can use it.
 *
 *  The following methods will only be invoked between a cursor_off() and a cursor_on()
 */
void cursor_on(int8_t y, int8_t x) { }

/**
 *  Disable the cursor even if it is a hardware cursor. This is used to indicate that the user has specifically disabled
 *  the cursor, rather than indicating a request to hide the cursor for a display update.
 */
void cursor_disable(void) { }

/**
 *  Scroll the screen up (normal scroll). The bottom line does not need to be cleared. Hardware scrolling can be used if
 *  present.
 */
void scroll_up(void) {
    clear_lines(0, 1);
    lineaddr = (lineaddr + FONT_HEIGHT) % SEGS;
    rawsetall(COMREG, 0xa2);
    rawsetall(COMREG, lineaddr);
}

/**
 *  Scroll the screen down (reverse scroll). The top line does not need to be cleared. Hardware scrolling can be used if
 *  present.
 */
void scroll_down(void) {
    lineaddr = (lineaddr + SEGS - FONT_HEIGHT) % SEGS;
    rawsetall(COMREG, 0xa2);
    rawsetall(COMREG, lineaddr);
}

/**
 *  Make a beep noise, or perform a visual bell (eg inverting the display momentarily if the hardware supports it).
 */
void do_beep(void) {}

/**
 *  Notify on VT52 mode events.
 */
void vtattr_notify(void) {}

/**
 *  Plot a character onto the display at y,x. Currently c is in the range 0-255 but that may change in future to
 *  accomodate non-ascii displays and systems with additional graphic ranges.
 */
void plot_char(int8_t row, int8_t col, uint16_t c) {
    static uint8_t txbuf[FONT_WIDTH * FONT_HEIGHT * 4 / 8]; // grayscale
    const uint8_t *bmp = GLYPH(c);  // monochrome
    uint16_t msk = COLORMASK(vtink);
    uint8_t x = ADDRX(col);
    uint8_t y = ADDRY(row);
    uint8_t cs = CHIP(col);
    uint8_t cmd[6] = {
        (/* COMADDR */ 0x21), x, x + FONT_WIDTH / 2 - 1,
        (/* SEGADDR */ 0x22), y, 159
    };
    gpio_put(VT_DC, LOW);
    gpio_put(cs, LOW);
    spi_write_blocking(VT_SPI_MOD, cmd, 6);
    gpio_put(VT_DC, HIGH);
    uint16_t *m4g16 = (uint16_t *) m4;
    uint16_t *u16 = (uint16_t *) txbuf;
    uint16_t *l16 = 1 + (uint16_t *) txbuf;
    for (size_t i = FONT_WIDTH * FONT_HEIGHT / 8; i > 0; --i, ++bmp, u16+=2, l16+=2) {
        // convert monochrome to 4-bit grayscale
        // do this by transposing the nibbles
        *u16 = m4g16[(*bmp & 0xf0) >> 4] & msk;
        *l16 = m4g16[*bmp & 0x0f] & msk;
    }
    spi_write_blocking(VT_SPI_MOD, txbuf, sizeof(txbuf));
    gpio_put(cs, HIGH);
}
