#ifndef __ILI9341_DRIVER_H__
#define __ILI9341_DRIVER_H__


/* Includes ------------------------------------------------------------------*/

#include "main.h"

/* Defines ------------------------------------------------------------------*/

#define ILI9341_SPI SPI1

#define PIN_SET(GPIOx, PINx) SET_BIT(GPIOx->BSRR, PINx);
#define PIN_RESET(GPIOx, PINx) SET_BIT(GPIOx->BSRR, (uint32_t)PINx << 16U);

//#define TFT_CS_Pin GPIO_PIN_2
//#define TFT_CS_GPIO_Port GPIOE
//#define TFT_RST_Pin GPIO_PIN_3
//#define TFT_RST_GPIO_Port GPIOE
//#define TFT_DC_Pin GPIO_PIN_4
//#define TFT_DC_GPIO_Port GPIOE

#define ILI9341_CS_UNSELECT PIN_SET(TFT_CS_GPIO_Port, TFT_CS_Pin);
#define ILI9341_CS_SELECT PIN_RESET(TFT_CS_GPIO_Port, TFT_CS_Pin);
#define ILI9341_RST_WORK PIN_SET(TFT_RST_GPIO_Port, TFT_RST_Pin);
#define ILI9341_RST_RESET PIN_RESET(TFT_RST_GPIO_Port, TFT_RST_Pin);
#define ILI9341_DC_DATA PIN_SET(TFT_DC_GPIO_Port, TFT_DC_Pin);
#define ILI9341_DC_COMMAND PIN_RESET(TFT_DC_GPIO_Port, TFT_DC_Pin);

/* Prototypes ------------------------------------------------------------------*/

void ili9341_driver_spi_init(void);
//void ili9341_driver_spi_send_byte(uint8_t data);
void ili9341_driver_send_command(uint8_t command);
void ili9341_driver_send_data(uint8_t data);
void ili9341_driver_send_n_data(uint8_t data, uint32_t size);
void ili9341_driver_send_buffer(uint8_t* bufer, uint32_t size);
void ili9341_driver_send_color565(uint16_t color);

#endif /* __ILI9341_DRIVER_H__ */

