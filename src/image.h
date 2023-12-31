#include <Arduino.h>

// 'deal', 64x64px
const unsigned char epd_bitmap_deal[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x06, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c,
    0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x30, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x30, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60,
    0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x06, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x80, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00,
    0x01, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0xe0, 0x00, 0x00,
    0x00, 0x00, 0x0c, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0xd8, 0x00,
    0x00, 0x38, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x1f, 0x80, 0x00,
    0x00, 0x07, 0x70, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x06, 0x38, 0x00,
    0x00, 0x1c, 0xe0, 0x00, 0x00, 0x0c, 0x1c, 0x00, 0x00, 0x38, 0x70, 0x00,
    0x00, 0x0c, 0x0e, 0x00, 0x00, 0x70, 0x30, 0x00, 0x00, 0x0e, 0x07, 0x00,
    0x00, 0xe0, 0x30, 0x00, 0x01, 0xff, 0x03, 0x80, 0x01, 0xc0, 0x7c, 0x00,
    0x1f, 0xf3, 0x81, 0xc0, 0x03, 0x80, 0xff, 0xe0, 0x7c, 0x01, 0xc0, 0xe0,
    0x07, 0x01, 0x83, 0xfc, 0xe0, 0x00, 0xe0, 0x73, 0xce, 0x03, 0x00, 0x1f,
    0xc0, 0x00, 0x70, 0x3e, 0xfc, 0x00, 0x00, 0x07, 0x80, 0x00, 0x38, 0x1c,
    0x78, 0x00, 0x00, 0x07, 0x0c, 0x00, 0x1c, 0x0c, 0x30, 0x18, 0x00, 0x0e,
    0x1c, 0x00, 0x0e, 0x0c, 0x30, 0x30, 0x00, 0x0c, 0x38, 0x00, 0x07, 0x18,
    0x38, 0x60, 0x00, 0x0c, 0x78, 0x00, 0x03, 0xb0, 0x1c, 0xc0, 0x00, 0x0e,
    0xf8, 0x00, 0x03, 0xe0, 0x0f, 0xc0, 0x00, 0x07, 0xcc, 0x00, 0x07, 0xc0,
    0x07, 0xc0, 0x00, 0x01, 0x06, 0x00, 0x06, 0x00, 0x00, 0x60, 0x00, 0x00,
    0x03, 0x00, 0x0c, 0x00, 0x00, 0x60, 0x00, 0x00, 0x01, 0x00, 0x0c, 0x00,
    0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x30, 0x00, 0x00,
    0x00, 0x20, 0x08, 0x00, 0x00, 0x30, 0x78, 0x00, 0x00, 0x38, 0x18, 0x00,
    0x00, 0x19, 0xfc, 0x00, 0x08, 0x1c, 0x18, 0x00, 0x00, 0x1b, 0x8e, 0x00,
    0x0c, 0x0e, 0x30, 0x00, 0x00, 0x1f, 0x06, 0x00, 0x0e, 0x07, 0x70, 0x00,
    0x00, 0x0e, 0x0f, 0x80, 0x07, 0x03, 0xe0, 0x00, 0x00, 0x06, 0x0f, 0xc0,
    0x03, 0x81, 0xc0, 0x00, 0x00, 0x06, 0x18, 0xe0, 0xc1, 0xc1, 0x80, 0x00,
    0x00, 0x06, 0x70, 0x60, 0xe0, 0xe1, 0x80, 0x00, 0x00, 0x03, 0xe0, 0x78,
    0x70, 0x73, 0x80, 0x00, 0x00, 0x01, 0xe0, 0xfc, 0x38, 0x3f, 0x00, 0x00,
    0x00, 0x00, 0x61, 0x8e, 0x1c, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x63, 0x06,
    0x0c, 0x18, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x07, 0x87, 0x30, 0x00, 0x00,
    0x00, 0x00, 0x1e, 0x0f, 0xc3, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x06, 0x18,
    0xe3, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x06, 0x30, 0x61, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x03, 0xe0, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0,
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0xfe, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x63, 0xb0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f,
    0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x70, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

// 'talk', 64x64px
const unsigned char epd_bitmap_talk[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x03, 0xff,
    0xff, 0x80, 0x0f, 0xe0, 0x0f, 0xfc, 0x03, 0xff, 0xff, 0x80, 0x3f, 0xf0,
    0x1c, 0x0e, 0x06, 0x00, 0x01, 0xc0, 0x70, 0x38, 0x38, 0x06, 0x06, 0x00,
    0x00, 0xc0, 0x60, 0x1c, 0x30, 0x07, 0x06, 0x3f, 0xf8, 0xc0, 0xe0, 0x0c,
    0x30, 0x03, 0x06, 0x3f, 0xf8, 0xc0, 0xc0, 0x0c, 0x30, 0x03, 0x06, 0x00,
    0x00, 0xc0, 0xc0, 0x0c, 0x30, 0x03, 0x06, 0x1f, 0x00, 0xc0, 0xc0, 0x0c,
    0x30, 0x03, 0x06, 0x3f, 0x00, 0xc0, 0xc0, 0x0c, 0x38, 0x06, 0x06, 0x00,
    0x00, 0xc0, 0x60, 0x1c, 0x1c, 0x0e, 0x06, 0x00, 0x00, 0xc0, 0x70, 0x38,
    0x0e, 0x3c, 0x06, 0x00, 0x01, 0x80, 0x3c, 0x70, 0x07, 0xf8, 0x06, 0x3f,
    0xff, 0x80, 0x1f, 0xe0, 0x01, 0xe0, 0x06, 0x7f, 0xfe, 0x00, 0x07, 0x80,
    0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xc0,
    0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x1f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x1c, 0xe0, 0x00, 0x00,
    0x00, 0x00, 0x07, 0xf8, 0x30, 0x60, 0x00, 0x00, 0x00, 0x00, 0x06, 0x1c,
    0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0e, 0x30, 0x38, 0x00, 0x00,
    0x00, 0x00, 0x1c, 0x06, 0x30, 0x18, 0x00, 0x00, 0x00, 0x00, 0x18, 0x06,
    0x30, 0x1c, 0x01, 0xf0, 0x00, 0x00, 0x38, 0x06, 0x70, 0x0c, 0x07, 0xfc,
    0x00, 0x00, 0x30, 0x06, 0x60, 0x06, 0x3f, 0x0c, 0x00, 0x00, 0x60, 0x06,
    0x60, 0x07, 0xf8, 0x0e, 0x00, 0x00, 0xe0, 0x06, 0x60, 0x03, 0xe0, 0x06,
    0x00, 0x00, 0xc0, 0x06, 0x61, 0x01, 0x00, 0x06, 0x00, 0x07, 0x80, 0x86,
    0x63, 0x80, 0x00, 0x0c, 0x03, 0xff, 0x81, 0xc6, 0x61, 0x80, 0x00, 0x3c,
    0x1f, 0xf8, 0x01, 0x86, 0x61, 0xc0, 0x00, 0xf8, 0x3c, 0x00, 0x03, 0x86,
    0x60, 0xc0, 0x07, 0xe0, 0x30, 0x00, 0x03, 0x06, 0x60, 0x60, 0x1f, 0x00,
    0x30, 0x00, 0x06, 0x07, 0x60, 0x70, 0xfc, 0x00, 0x70, 0x00, 0x0e, 0x03,
    0x60, 0x3f, 0xe0, 0x00, 0x30, 0x00, 0xfc, 0x03, 0x60, 0x3f, 0x87, 0xff,
    0xf8, 0x3f, 0xfc, 0x03, 0x60, 0x34, 0x07, 0xff, 0xff, 0xff, 0xec, 0x03,
    0xc0, 0x30, 0x00, 0x03, 0x8f, 0xe0, 0x0c, 0x03, 0xc0, 0x3f, 0x00, 0x03,
    0x00, 0x00, 0xfc, 0x03, 0xc0, 0x3f, 0xf8, 0x03, 0x00, 0x1f, 0xfc, 0x03,
    0xc0, 0x01, 0xfc, 0x03, 0x00, 0x3f, 0x80, 0x03, 0xc0, 0x00, 0x0e, 0x03,
    0x00, 0x70, 0x00, 0x03, 0xc0, 0x00, 0x07, 0x03, 0x00, 0xe0, 0x00, 0x03,
    0xc0, 0x00, 0x03, 0x03, 0x00, 0xc0, 0x00, 0x03, 0xc0, 0x00, 0x03, 0x03,
    0x00, 0xc0, 0x00, 0x03, 0xe0, 0x00, 0x03, 0x03, 0x00, 0xc0, 0x00, 0x07,
    0x70, 0x00, 0x03, 0x03, 0x00, 0xc0, 0x00, 0x0e, 0x3f, 0x80, 0x03, 0x03,
    0x00, 0xc0, 0x01, 0xfc, 0x1f, 0xfc, 0x03, 0x03, 0x00, 0xc0, 0x3f, 0xf8,
    0x00, 0xfc, 0x03, 0x03, 0x00, 0xc0, 0x3e, 0x00, 0x00, 0x0c, 0x03, 0x03,
    0x00, 0xc0, 0x30, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x00, 0xc0, 0x30, 0x00,
    0x00, 0x0c, 0x03, 0x03, 0x00, 0xc0, 0x30, 0x00, 0x00, 0x0c, 0x03, 0x03,
    0x00, 0xc0, 0x30, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x00, 0xc0, 0x30, 0x00,
    0x00, 0x0c, 0x03, 0x03, 0x00, 0xc0, 0x30, 0x00, 0x00, 0x0c, 0x03, 0x03,
    0x00, 0xc0, 0x30, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x00, 0xc0, 0x30, 0x00,
    0x00, 0x0c, 0x03, 0x03, 0x00, 0xc0, 0x30, 0x00, 0x00, 0x0c, 0x03, 0x03,
    0x00, 0xc0, 0x30, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x00, 0xc0, 0x30, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};