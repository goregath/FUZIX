// vim: sw=4:ts=4

#include <kernel.h>
#include <kdata.h>
#include <printf.h>
#include <stdbool.h>
#include <vt.h>
#include <tty.h>
#include "picosdk.h"
#include <pico/multicore.h>
#include "core1.h"
#include "ssd1320z2.h"

static uint8_t ttybuf[TTYSIZ];

struct s_queue ttyinq[NUM_DEV_TTY+1] = { /* ttyinq[0] is never used */
	{ 0,         0,         0,         0,      0, 0        },
	{ ttybuf,    ttybuf,    ttybuf,    TTYSIZ, 0, TTYSIZ/2 },
};

tcflag_t termios_mask[NUM_DEV_TTY+1] = { 0, _CSYS };

/* Output for the system console (kprintf etc) */
void kputchar(uint_fast8_t c) {
    if (c == '\n') kputchar('\r');
    usbconsole_putc_blocking(c);
    vtoutput(&c, 1);
}

void tty_putc(uint_fast8_t minor, uint_fast8_t c) {
	kputchar(c);
}

ttyready_t tty_writeready(uint_fast8_t minor) {
    return usbconsole_is_writable() ? TTY_READY_NOW : TTY_READY_SOON;
}

/* For the moment */
int tty_carrier(uint_fast8_t minor) {
    return 1;
}

void tty_sleeping(uint_fast8_t minor) {}
void tty_data_consumed(uint_fast8_t minor) {}

void tty_setup(uint_fast8_t minor, uint_fast8_t flags) {
    if (minor == 0) {
        display_init();
        vtinit();
    }
}

uint8_t vtattr_cap = VTA_INVERSE | VTA_UNDERLINE;

void clear_lines(int8_t y, int8_t ct) {}
void clear_across(int8_t y, int8_t x, int16_t l) {}
void cursor_off(void) {}
void cursor_on(int8_t y, int8_t x) {}
void cursor_disable(void) {}
void scroll_up(void) {}
void scroll_down(void) {}
void plot_char(int8_t y, int8_t x, uint16_t c) {}
void do_beep(void) {}
void vtattr_notify(void) {}
// uint8_t vtattr;
// uint8_t vtattr_cap;
// uint8_t vtink;
// uint8_t vtpaper;
// struct vt_repeat keyrepeat;
