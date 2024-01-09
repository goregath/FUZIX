// vim: sw=4:ts=4

#include <kernel.h>
#include <kdata.h>
#include <printf.h>
#include <stdbool.h>
#include <vt.h>
#include <tty.h>
#include "picosdk.h"
#include <hardware/uart.h>
#include <hardware/irq.h>
#include "ssd1320z2.h"

static uint8_t ttybuf[TTYSIZ];
static unsigned char cr = '\r';

struct s_queue ttyinq[NUM_DEV_TTY+1] = { /* ttyinq[0] is never used */
	{ 0,         0,         0,         0,      0, 0        },
	{ ttybuf,    ttybuf,    ttybuf,    TTYSIZ, 0, TTYSIZ/2 },
};

tcflag_t termios_mask[NUM_DEV_TTY+1] = { 0, _CSYS };

/* Output for the system console (kprintf etc) */
void kputchar(uint_fast8_t c) {
    if (c == '\n') vtoutput(&cr, 1);
    vtoutput(&c, 1);
    uart_putc(uart_default, c);
}

void tty_putc(uint_fast8_t minor, uint_fast8_t c) {
    kputchar(c);
}

ttyready_t tty_writeready(uint_fast8_t minor) {
    return uart_is_writable(uart_default) ? TTY_READY_NOW : TTY_READY_SOON;
}

/* For the moment */
int tty_carrier(uint_fast8_t minor) {
    return 1;
}

void tty_sleeping(uint_fast8_t minor) {}
void tty_data_consumed(uint_fast8_t minor) {}
void tty_setup(uint_fast8_t minor, uint_fast8_t flags) {}

static void tty_isr(void) {
    extern int dump;
    while (uart_is_readable(uart_default)) {
        uint8_t b = uart_get_hw(uart_default)->dr;
        vt_inproc(minor(BOOT_TTY), b);
    }
}

void tty_rawinit(void) {
    uart_init(uart_default, PICO_DEFAULT_UART_BAUD_RATE);
    gpio_set_function(PICO_DEFAULT_UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(PICO_DEFAULT_UART_RX_PIN, GPIO_FUNC_UART);
    uart_set_translate_crlf(uart_default, true);
    // FIXME Freezes when on uart: char<backspace>
    // uart_set_fifo_enabled(uart_default, false);
    // TODO Investigate why this fixes the freeze
    // TODO Messes up boot message echo
    uart_set_fifo_enabled(uart_default, true);

    int irq = (uart_default == uart0) ? UART0_IRQ : UART1_IRQ;
    irq_set_exclusive_handler(irq, tty_isr);
    irq_set_enabled(irq, true);
    uart_set_irq_enables(uart_default, true, false);

    display_init();
    vtinit();
}
