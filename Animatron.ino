#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define ScreenWidth 128
#define ScreenHeight 64

unsigned long previousMillis = 0;
const long interval = random(2000,3000);

Adafruit_SSD1306 display(ScreenWidth,ScreenHeight,&Wire,-1);

// 'Layer 1_sprite_1', 128x64px
const unsigned char MataMarah [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x03, 0xff, 0xfe, 
	0x7f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x03, 0xff, 0xfe, 
	0x7f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 
	0x7f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x07, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xe0, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x00, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0x00, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x30, 0x1f, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xf8, 0x0c, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3e, 0x01, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0x80, 0x7c, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xc0, 0x3f, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xfc, 0x03, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x07, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xe0, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0x80, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0x01, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xf0, 0x1f, 0xfe, 0x1f, 0xf8, 0x7f, 0xf8, 0x0f, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xfe, 0x01, 0xfe, 0x1f, 0xf8, 0x7f, 0x80, 0x7f, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xc0, 0x3e, 0x1f, 0xf8, 0x7c, 0x03, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xfc, 0x06, 0x1f, 0xf8, 0x60, 0x3f, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0x80, 0x1f, 0xf8, 0x01, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xf0, 0x1f, 0xf8, 0x0f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x00, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x00, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x00, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x00, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x00, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x00, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x00, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x00, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x3c, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x3c, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x3c, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x3c, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x3c, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x3c, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x3c, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x3c, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x00, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x00, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x00, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x00, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x00, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x00, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x00, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x00, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 
	0x7f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 
	0x7f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x03, 0xff, 0xfe, 
	0x7f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x03, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'Layer 1_sprite_2', 128x64px
const unsigned char Mata100 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x03, 0xff, 0xfe, 
	0x7f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x03, 0xff, 0xfe, 
	0x7f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 
	0x7f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x00, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x00, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x00, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x00, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x00, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x00, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x00, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x00, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x3c, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x3c, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x3c, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x3c, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x3c, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x3c, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x3c, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x3c, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x00, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x00, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x00, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x00, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x00, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x00, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xfc, 0x00, 0x3f, 0xfe, 0x1f, 0xf8, 0x7f, 0xfc, 0x00, 0x3f, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xfe, 
	0x7f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 
	0x7f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 
	0x7f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x03, 0xff, 0xfe, 
	0x7f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x03, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'Layer 1_sprite_3', 128x64px
const unsigned char Mata50 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xc1, 0xff, 0xff, 0xff, 0xf0, 0x7f, 0xff, 0x83, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xfe, 
	0x7f, 0xff, 0x81, 0xff, 0xff, 0xff, 0xf0, 0x3f, 0xff, 0x03, 0xff, 0xff, 0xff, 0xe0, 0x7f, 0xfe, 
	0x7f, 0xff, 0x01, 0xff, 0xff, 0xff, 0xf0, 0x1f, 0xfe, 0x03, 0xff, 0xff, 0xff, 0xe0, 0x3f, 0xfe, 
	0x7f, 0xfe, 0x18, 0x7f, 0xff, 0xff, 0xc3, 0x0f, 0xfc, 0x30, 0xff, 0xff, 0xff, 0x86, 0x1f, 0xfe, 
	0x7f, 0xfe, 0x18, 0x7f, 0xff, 0xff, 0xc3, 0x0f, 0xfc, 0x30, 0xff, 0xff, 0xff, 0x86, 0x1f, 0xfe, 
	0x7f, 0xfe, 0x1e, 0x1f, 0xff, 0xff, 0x0f, 0x0f, 0xfc, 0x3c, 0x3f, 0xff, 0xfe, 0x1e, 0x1f, 0xfe, 
	0x7f, 0xfe, 0x1e, 0x1f, 0xff, 0xff, 0x0f, 0x0f, 0xfc, 0x3c, 0x3f, 0xff, 0xfe, 0x1e, 0x1f, 0xfe, 
	0x7f, 0xfe, 0x1f, 0x81, 0xff, 0xf0, 0x3f, 0x0f, 0xfc, 0x3f, 0x03, 0xff, 0xe0, 0x7e, 0x1f, 0xfe, 
	0x7f, 0xfe, 0x1f, 0x81, 0xff, 0xf0, 0x3f, 0x0f, 0xfc, 0x3f, 0x03, 0xff, 0xe0, 0x7e, 0x1f, 0xfe, 
	0x7f, 0xfe, 0x1f, 0xf8, 0x00, 0x03, 0xff, 0x0f, 0xfc, 0x3f, 0xf0, 0x00, 0x07, 0xfe, 0x1f, 0xfe, 
	0x7f, 0xfe, 0x1f, 0xf8, 0x00, 0x03, 0xff, 0x0f, 0xfc, 0x3f, 0xf0, 0x00, 0x07, 0xfe, 0x1f, 0xfe, 
	0x7f, 0xfe, 0x1f, 0xfe, 0x1e, 0x1f, 0xff, 0x0f, 0xfc, 0x3f, 0xfc, 0x3c, 0x3f, 0xfe, 0x1f, 0xfe, 
	0x7f, 0xfe, 0x1f, 0xfe, 0x1e, 0x1f, 0xff, 0x0f, 0xfc, 0x3f, 0xfc, 0x3c, 0x3f, 0xfe, 0x1f, 0xfe, 
	0x7f, 0xfe, 0x1f, 0xfe, 0x00, 0x1f, 0xff, 0x0f, 0xfc, 0x3f, 0xfc, 0x00, 0x3f, 0xfe, 0x1f, 0xfe, 
	0x7f, 0xfe, 0x1f, 0xfe, 0x00, 0x1f, 0xff, 0x0f, 0xfc, 0x3f, 0xfc, 0x00, 0x3f, 0xfe, 0x1f, 0xfe, 
	0x7f, 0xfe, 0x1f, 0xfe, 0x00, 0x1f, 0xff, 0x0f, 0xfc, 0x3f, 0xfc, 0x00, 0x3f, 0xfe, 0x1f, 0xfe, 
	0x7f, 0xfe, 0x1f, 0xfe, 0x00, 0x1f, 0xff, 0x0f, 0xfc, 0x3f, 0xfc, 0x00, 0x3f, 0xfe, 0x1f, 0xfe, 
	0x7f, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xfe, 
	0x7f, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xfe, 
	0x7f, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xfe, 
	0x7f, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xfe, 
	0x7f, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xfe, 
	0x7f, 0xfe, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xfe, 
	0x7f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 
	0x7f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 
	0x7f, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x01, 0xff, 0xfe, 
	0x7f, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x01, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'Layer 1_sprite_4', 128x64px
const unsigned char Mata0 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xc1, 0xff, 0xff, 0xff, 0xf0, 0x7f, 0xff, 0x83, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xfe, 
	0x7f, 0xff, 0x81, 0xff, 0xff, 0xff, 0xf0, 0x3f, 0xff, 0x03, 0xff, 0xff, 0xff, 0xe0, 0x7f, 0xfe, 
	0x7f, 0xff, 0x81, 0xff, 0xff, 0xff, 0xf0, 0x3f, 0xff, 0x03, 0xff, 0xff, 0xff, 0xe0, 0x7f, 0xfe, 
	0x7f, 0xff, 0x88, 0x7f, 0xff, 0xff, 0xc2, 0x3f, 0xff, 0x10, 0xff, 0xff, 0xff, 0x84, 0x7f, 0xfe, 
	0x7f, 0xff, 0x88, 0x7f, 0xff, 0xff, 0xc2, 0x3f, 0xff, 0x10, 0xff, 0xff, 0xff, 0x84, 0x7f, 0xfe, 
	0x7f, 0xff, 0x8e, 0x1f, 0xff, 0xff, 0x0e, 0x3f, 0xff, 0x1c, 0x3f, 0xff, 0xfe, 0x1c, 0x7f, 0xfe, 
	0x7f, 0xff, 0xce, 0x1f, 0xff, 0xff, 0x0e, 0x7f, 0xff, 0x9c, 0x3f, 0xff, 0xfe, 0x1c, 0xff, 0xfe, 
	0x7f, 0xff, 0xcf, 0x81, 0xff, 0xf0, 0x3e, 0x7f, 0xff, 0x9f, 0x03, 0xff, 0xe0, 0x7c, 0xff, 0xfe, 
	0x7f, 0xff, 0xe7, 0x81, 0xff, 0xf0, 0x3c, 0xff, 0xff, 0xcf, 0x03, 0xff, 0xe0, 0x79, 0xff, 0xfe, 
	0x7f, 0xff, 0xe3, 0xf8, 0x00, 0x03, 0xf8, 0xff, 0xff, 0xc7, 0xf0, 0x00, 0x07, 0xf1, 0xff, 0xfe, 
	0x7f, 0xff, 0xf1, 0xf8, 0x00, 0x03, 0xf1, 0xff, 0xff, 0xe3, 0xf0, 0x00, 0x07, 0xe3, 0xff, 0xfe, 
	0x7f, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xe3, 0xff, 0xff, 0xf1, 0xff, 0xff, 0xff, 0xc7, 0xff, 0xfe, 
	0x7f, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0xc7, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xfe, 
	0x7f, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0x1f, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0x1f, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xfe, 0x3f, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0x8f, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff, 0x1f, 0xff, 0xfc, 0x7f, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xe0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x01, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void setup() {
  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

}

void loop() {
  int analogValue = analogRead(A0);

  Serial.print("Analog reading: ");
  Serial.print(analogValue);

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    display.clearDisplay();
    display.drawBitmap(0,0,Mata0,128,64,1);
    display.display();
  }

  if (analogValue < 100) {
    Serial.println(" - Dark");
    display.clearDisplay();
    display.drawBitmap(0,0,Mata0,128,64,1);
    display.display();
  } else if (analogValue < 200) {
    Serial.println(" - Dim");
    display.clearDisplay();
    display.drawBitmap(0,0,Mata50,128,64,1);
    display.display();
  } else if (analogValue < 700) {
    Serial.println(" - Light");
    display.clearDisplay();
    display.drawBitmap(0,0,Mata100,128,64,1);
    display.display();
    display.clearDisplay();
  } else {
    Serial.println(" - Very bright");
    display.clearDisplay();
    display.drawBitmap(0,0,MataMarah,128,64,1);
    display.display();
  }

  delay(5);
}
