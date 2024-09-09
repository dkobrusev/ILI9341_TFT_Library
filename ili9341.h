#ifndef __ILI9341_H__
#define __ILI9341_H__


/* Includes ------------------------------------------------------------------*/

#include "main.h"

//#define ILI9341_DRIVER_ASSERT
#ifdef ILI9341_DRIVER_ACCESS
#include "ili9341_driver.h"
#endif

/* Defines ------------------------------------------------------------------*/

#define ILI9341_SCREEN_WIDTH 240
#define ILI9341_SCREEN_HEIGHT 320

/* Prototypes ------------------------------------------------------------------*/

void ili9341_init(void);

//void ili9341_set_area_address(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1); // - access only in ili9341.c

void ili9341_draw_filled_rectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color);

#endif /* __ILI9341_H__ */