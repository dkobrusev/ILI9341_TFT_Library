#include "ili9341_driver.h"

// SPI Init
void ili9341_driver_spi_init(void)
{
  SET_BIT(ILI9341_SPI->CR1, SPI_CR1_SPE); // Enable SPI
}

// SPI Send
void ili9341_driver_spi_send_byte(uint8_t data)
{
  WRITE_REG(ILI9341_SPI->DR, data);
  while (READ_BIT(ILI9341_SPI->SR, SPI_SR_TXE) == 0);
  while (READ_BIT(ILI9341_SPI->SR, SPI_SR_BSY) != 0);
}

// Send Command
void ili9341_driver_send_command(uint8_t command)
{
  ILI9341_DC_COMMAND;
  ili9341_driver_spi_send_byte(command);
}

// Send Data
void ili9341_driver_send_data(uint8_t data)
{
  ILI9341_DC_DATA;
  ili9341_driver_spi_send_byte(data);
}

// Send N Data
void ili9341_driver_send_n_data(uint8_t data, uint32_t size)
{
  ILI9341_DC_DATA;
  while (size--)
  {
    ili9341_driver_spi_send_byte(data);
  }
}

// Send Buffer
void ili9341_driver_send_buffer(uint8_t* bufer, uint32_t size)
{
  ILI9341_DC_DATA;
  for(uint32_t i = 0; i < size; i++)
  {
    ili9341_driver_spi_send_byte(bufer[i]);//??
  }
}

// Send Color RGB565 (16bit)
void ili9341_driver_send_color565(uint16_t color)
{
  ILI9341_DC_DATA;
  ili9341_driver_spi_send_byte((uint8_t)(color >> 8));
  ili9341_driver_spi_send_byte((uint8_t)(color & 0xFF));
}