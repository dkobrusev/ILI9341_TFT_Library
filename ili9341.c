/* Includes ------------------------------------------------------------------*/

#include "ili9341.h"
#include "ili9341_driver.h"

/* Defines ------------------------------------------------------------------*/

// Command list
#define ILI9341_COMMAND_SWRESET 0x01 // Software Reset
//
#define ILI9341_COMMAND_SPLIN           0x10 // Enter Sleep Mode (100ds)
#define ILI9341_COMMAND_SLPOUT          0x11 // Sleep Out
//
#define ILI9341_COMMAND_DISPOFF         0x28 // Display OFF
#define ILI9341_COMMAND_DISPON          0x29 // Display ON
#define ILI9341_COMMAND_CASET           0x2A // Column Address Set
#define ILI9341_COMMAND_PASET           0x2B // Page Address Set
#define ILI9341_COMMAND_RAMWR           0x2C // Memory Write
//
#define ILI9341_COMMAND_MADCTL          0x36 // Memory Access Control (127ds)
//#define ILI9341_COMMAND_
//#define ILI9341_COMMAND_
//#define ILI9341_COMMAND_

/* Functions ------------------------------------------------------------------*/

void ili9341_init(void)
{
  
  ili9341_driver_spi_init();
  
  ILI9341_CS_SELECT;
  ILI9341_RST_RESET;
  HAL_Delay(10);
  ILI9341_RST_WORK;
  
  // SOFTWARE RESET
  ili9341_driver_send_command(ILI9341_COMMAND_SWRESET);
  HAL_Delay(1000);
  
  //  // POWER CONTROL A
  //  ili9341_driver_send_command(0xCB);
  //  {
  //    uint8_t data[] = { 0x39, 0x2C, 0x00, 0x34, 0x02 };
  //    ili9341_driver_send_data(data, sizeof(data));
  //  }
  //  
  //  // POWER CONTROL B
  //  ili9341_driver_send_command(0xCF);
  //  {
  //    uint8_t data[] = { 0x00, 0xC1, 0x30 };
  //    ili9341_driver_send_data(data, sizeof(data));
  //  }
  //  
  //  // DRIVER TIMING CONTROL A
  //  ili9341_driver_send_command(0xE8);
  //  {
  //    uint8_t data[] = { 0x85, 0x00, 0x78 };
  //    ili9341_driver_send_data(data, sizeof(data));
  //  }
  //  
  //  // DRIVER TIMING CONTROL B
  //  ili9341_driver_send_command(0xEA);
  //  {
  //    uint8_t data[] = { 0x00, 0x00 };
  //    ili9341_driver_send_data(data, sizeof(data));
  //  }
  //  
  //  // POWER ON SEQUENCE CONTROL
  //  ili9341_driver_send_command(0xED);
  //  {
  //    uint8_t data[] = { 0x64, 0x03, 0x12, 0x81 };
  //    ili9341_driver_send_data(data, sizeof(data));
  //  }
  //  
  //  // PUMP RATIO CONTROL
  //  ili9341_driver_send_command(0xF7);
  //  {
  //    uint8_t data[] = { 0x20 };
  //    ili9341_driver_send_data(data, sizeof(data));
  //  }
  //  
  //  // POWER CONTROL,VRH[5:0]
  //  ili9341_driver_send_command(0xC0);
  //  {
  //    uint8_t data[] = { 0x23 };
  //    ili9341_driver_send_data(data, sizeof(data));
  //  }
  //  
  //  // POWER CONTROL,SAP[2:0];BT[3:0]
  //  ili9341_driver_send_command(0xC1);
  //  {
  //    uint8_t data[] = { 0x10 };
  //    ili9341_driver_send_data(data, sizeof(data));
  //  }
  //  
  //  // VCM CONTROL
  //  ili9341_driver_send_command(0xC5);
  //  {
  //    uint8_t data[] = { 0x3E, 0x28 };
  //    ili9341_driver_send_data(data, sizeof(data));
  //  }
  //  
  //  // VCM CONTROL 2
  //  ili9341_driver_send_command(0xC7);
  //  {
  //    uint8_t data[] = { 0x86 };
  //    ili9341_driver_send_data(data, sizeof(data));
  //  }
  //  
  //  // MEMORY ACCESS CONTROL
  //  ili9341_driver_send_command(0x36);
  //  {
  //    uint8_t data[] = { 0x48 };
  //    ili9341_driver_send_data(data, sizeof(data));
  //  }
  
  // PIXEL FORMAT
  ili9341_driver_send_command(0x3A);
  ili9341_driver_send_data(0x55);
  
  //  // FRAME RATIO CONTROL, STANDARD RGB COLOR
  //  ili9341_driver_send_command(0xB1);
  //  {
  //    uint8_t data[] = { 0x00, 0x18 };
  //    ili9341_driver_send_data(data, sizeof(data));
  //  }
  //  
  //  // DISPLAY FUNCTION CONTROL
  //  ili9341_driver_send_command(0xB6);
  //  {
  //    uint8_t data[] = { 0x08, 0x82, 0x27 };
  //    ili9341_driver_send_data(data, sizeof(data));
  //  }
  //  
  //  // 3GAMMA FUNCTION DISABLE
  //  ili9341_driver_send_command(0xF2);
  //  {
  //    uint8_t data[] = { 0x00 };
  //    ili9341_driver_send_data(data, sizeof(data));
  //  }
  //  
  //  // GAMMA CURVE SELECTED
  //  ili9341_driver_send_command(0x26);
  //  {
  //    uint8_t data[] = { 0x01 };
  //    ili9341_driver_send_data(data, sizeof(data));
  //  }
  //  
  //  // POSITIVE GAMMA CORRECTION
  //  ili9341_driver_send_command(0xE0);
  //  {
  //    uint8_t data[] = { 0x0F, 0x31, 0x2B, 0x0C, 0x0E, 0x08, 0x4E, 0xF1,
  //    0x37, 0x07, 0x10, 0x03, 0x0E, 0x09, 0x00 };
  //    ili9341_driver_send_data(data, sizeof(data));
  //  }
  //  
  //  // NEGATIVE GAMMA CORRECTION
  //  ili9341_driver_send_command(0xE1);
  //  {
  //    uint8_t data[] = { 0x00, 0x0E, 0x14, 0x03, 0x11, 0x07, 0x31, 0xC1,
  //    0x48, 0x08, 0x0F, 0x0C, 0x31, 0x36, 0x0F };
  //    ili9341_driver_send_data(data, sizeof(data));
  //  }
    
    // EXIT SLEEP
    ili9341_driver_send_command(ILI9341_COMMAND_SLPOUT);
    HAL_Delay(120);
    
    // TURN ON DISPLAY
    ili9341_driver_send_command(ILI9341_COMMAND_DISPON);
    
    // MADCTL
    ili9341_driver_send_command(ILI9341_COMMAND_MADCTL);
    ili9341_driver_send_data(0b00001000); // BGR ON
  
  ILI9341_CS_UNSELECT;
}

void ili9341_set_area_address(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
  ili9341_driver_send_command(ILI9341_COMMAND_CASET);
  ili9341_driver_send_data((uint8_t)(x0 >> 8));
  ili9341_driver_send_data((uint8_t)(x0 & 0xFF));
  ili9341_driver_send_data((uint8_t)(x1 >> 8));
  ili9341_driver_send_data((uint8_t)(x1 & 0xFF));
  
  ili9341_driver_send_command(ILI9341_COMMAND_PASET);
  ili9341_driver_send_data((uint8_t)(y0 >> 8));
  ili9341_driver_send_data((uint8_t)(y0 & 0xFF));
  ili9341_driver_send_data((uint8_t)(y1 >> 8));
  ili9341_driver_send_data((uint8_t)(y1 & 0xFF));
  
  ili9341_driver_send_command(ILI9341_COMMAND_RAMWR);
  
}

void ili9341_draw_filled_rectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color)
{
  ILI9341_CS_SELECT;
  ili9341_set_area_address(x0, y0, x1, y1);
  uint32_t count = (x1 - x0 + 1 ) * (y1 - y0 + 1);
  while (count--)
  {
    ili9341_driver_send_color565(color);
  }  
  ILI9341_CS_UNSELECT;
}

