#ifndef SSD1320Z2_H
#define SSD1320Z2_H

#define VT_SPI_MOD spi1
#define VT_SPI_SPEED 62500000
#define VT_SCL 10
#define VT_SDA 11
#define VT_RES 12
#define VT_DC 13
#define VT_CS1 14
#define VT_CS2 15

extern void display_init(void);

#endif
