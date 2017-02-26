//#include <SPI.h>
#include <MFRC522.h>
#include "ManufacturerInfo.h"
#include <EEPROMex.h>
#include <Button.h>
//graphics
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Adafruit_RA8875.h>

//wps button
#define WPS_BUTTON_PIN 30
#define PULLUP true
#define INVERT true
#define DEBOUNCE_MS 20
#define WPS_LED_PIN 31
#define LONG_PRESS 1250
#define BLINK_INTERVAL 100

//category buttons
#define NFC_RST_PIN         49
#define NFC_SS_PIN          53
#define CATEGORY_BUTTON_PIN A0

#define TABLES_PRESENT_ADDRESS  0
#define TAG_TABLE_ADDRESS  1
#define CONTROL_PANEL_ADDRESS 1011

#define TABLES_PRESENT 18 //random indicator number

//graphics
#define RA8875_INT 21
#define RA8875_CS 22
#define RA8875_RESET 23

//colours for the tags
#define Light_Grey 0xe6e7e7
#define Grey 0xb3b3b3
#define Red 0xf58e74
#define Orange 0xf9a853
#define Yellow 0xfbe137
#define Green 0xa5c74b
#define Purple 0x6c63a7
#define Pink 0xc084b5
#define Light_pink 0xffabab

 /*
 * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno           Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             49         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 * */
  
