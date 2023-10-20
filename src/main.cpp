#include <Adafruit_GFX.h> // Core graphics library
#include <Adafruit_ILI9341.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <SPI.h>
#include <TimeLib.h>
#include <WiFiManager.h>
#include <WiFiUdp.h>
#include <image.h>

#define TFT_CS 0
#define TFT_DC 15

#define XN 2  // can be a digital pin
#define XP 16 // can be a digital pin
#define YN 12 // can be a digital pin
#define YP 17 // must be analog

int SCREEN_WIDTH = 240;
int SCREEN_HEIGHT = 320;
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);


unsigned long first_met = 1634717088;
unsigned long first_official = 1634717088;

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

#define MODE_TIME 0
#define MODE_MET 1
#define MODE_TOGEHTER 2

int mode = MODE_TIME;
unsigned long last_draw = 0;
unsigned long in_card = 0;

unsigned long last_touch_check = 0;

boolean last_touch_status = false;

void clear_screen() { tft.fillScreen(ILI9341_BLACK); }

void write_text(char *text, int px, int py, int size) {
  tft.setCursor(px, py);
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
  tft.setTextSize(size);
  tft.print(text);
}
void write_text(String text, int px, int py, int size) {
  tft.setCursor(px, py);
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
  tft.setTextSize(size);
  tft.print(text);
}

void setup() {
  tft.begin();
  clear_screen();
  write_text("Starting...", 0, 10, 4);

  Serial.begin(115200);

  WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP
  WiFiManager wm;

  // wm.resetSettings(); // Enable this to reset the settings
  bool res;
  res = wm.autoConnect("ScreenAP"); // password protected ap

  if (!res) {
    Serial.println("Failed to connect");
    // ESP.restart();
  } else {
    // if you get here you have connected to the WiFi
    Serial.println("connected...yeey :)");

    clear_screen();
    write_text("Connected!", 0, 10, 4);
  }

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
  }
  Serial.println();
  Serial.println(F("WiFi connected"));

  // Print the IP address
  Serial.println(WiFi.localIP());

  timeClient.begin();
  // // GMT +1 = 3600

  timeClient.setTimeOffset(3600);
  timeClient.forceUpdate();

  clear_screen();
}

int check_touched() {
  /*
        Check touch from only one axies, it is a bit hacky since Adafruit Huzzar only has one ADC pin, should be easier with the screen V2
  */
  unsigned long diff = millis() - last_touch_check;
  if (diff > 100) {
    pinMode(XP, OUTPUT);
    pinMode(XN, OUTPUT);
    digitalWrite(XP, HIGH);
    digitalWrite(XN, LOW);

    pinMode(YP, INPUT);
    pinMode(YN, INPUT);
    digitalWrite(YP, LOW);
    digitalWrite(YN, LOW);
    last_touch_check = millis();
    int result = (1023 - analogRead(YP));
    if (result < 300)
      return 1;
    return 0;
  }
  return -1;
}

void get_total(float *result, unsigned long diff) {
  /*
      Calculate Years, days, hours and minutes out of the different dates   
  */
  float days = 0;
  if (diff > 86400) {
    days = ceil(diff / 86400);
    diff = diff - (days * 86400);
  }
  float years = days / 365;
  float hours = diff / 3600;
  diff = diff - (hours * 3600);

  float minutes = diff / 60;
  result[0] = years;
  result[1] = days;
  result[2] = hours;
  result[3] = minutes;
}

void draw_time() {
  /*
    Simple draw time from the current timestamp 
  */
  int hours = timeClient.getHours();
  int minutes = timeClient.getMinutes();
  int seconds = timeClient.getSeconds();

  String current_time = "";
  if (hours < 10)
    current_time = "0";
  current_time += String(hours) + ":";
  if (minutes < 10)
    current_time += "0";
  current_time += String(minutes) + ":";
  if (seconds < 10)
    current_time += "0";
  current_time += String(seconds);

  write_text(current_time, 20, 150, 4);
}

void draw_met_time() {
  /*
    Draw graphic time since timestamp MET
  */
  unsigned long diff_met = timeClient.getEpochTime() - first_met;
  float result[] = {0.0, 0.0, 0.0, 0.0};
  get_total(result, diff_met);

  clear_screen();

  tft.drawBitmap(10, 10, epd_bitmap_talk, 64, 64, ILI9341_WHITE);

  write_text("Met", 140, 30, 3);

  write_text("Years", 20, 130, 3);
  write_text(String(result[0]), 40, 170, 2);

  write_text("Days", 150, 130, 3);
  write_text(String((int)result[1]), 170, 170, 2);

  write_text("Hours", 20, 230, 3);
  write_text(String((int)result[2]), 50, 270, 2);

  write_text("Mins", 150, 230, 3);
  write_text(String((int)result[3]), 170, 270, 2);
}

void draw_togheter_time() {
  /*
    Draw graphic time since timestamp OFFICIAL
  */
  unsigned long diff_met = timeClient.getEpochTime() - first_official;
  float result[] = {0.0, 0.0, 0.0, 0.0};
  get_total(result, diff_met);
  clear_screen();

  tft.drawBitmap(10, 10, epd_bitmap_deal, 64, 64, ILI9341_WHITE);

  write_text("Together", 90, 30, 3);

  write_text("Years", 20, 130, 3);
  write_text(String(result[0]), 40, 170, 2);

  write_text("Days", 150, 130, 3);
  write_text(String((int)result[1]), 170, 170, 2);

  write_text("Hours", 20, 230, 3);
  write_text(String((int)result[2]), 50, 270, 2);

  write_text("Mins", 150, 230, 3);
  write_text(String((int)result[3]), 170, 270, 2);
}

void switch_card() {
  /*
    Trigger switch card 
  */
  if (mode == MODE_TIME) {
    draw_met_time();
    mode = MODE_MET;
    in_card = millis();
  } else if (mode == MODE_MET) {
    mode = MODE_TOGEHTER;
    draw_togheter_time();
    in_card = millis();
  } else if (mode == MODE_TOGEHTER) {
    clear_screen();
    draw_time();
    mode = MODE_TIME;
  }
  last_draw = millis();
}

void check_timeout() {
  /*
    Allow to timeout and return to the current time
  */
  if (mode == MODE_MET || mode == MODE_TOGEHTER) {
    unsigned long diff = millis() - in_card;
    if (diff > 10000) {
      clear_screen();
      draw_time();
      mode = MODE_TIME;
    }
  }
}

void loop() {

  int status_touch = check_touched();
  if (status_touch == 1 && !last_touch_status)
    switch_card();

  // This part is only needed because the current touch reading is a bit hacky due to have only one ADC on the board
  if (status_touch == 1)
    last_touch_status = true;
  else if (status_touch == 0)
    last_touch_status = false;

  check_timeout();

  //Draw logic, we dont want to re-draw too often some cards
  unsigned long diff = millis() - last_draw;
  if (mode == MODE_TIME) {
    if (diff > 1000) {
      draw_time();
      last_draw = millis();
    }
  } else if (mode == MODE_MET) {
    if (diff > 15000) {
      draw_met_time();
      last_draw = millis();
    }

  } else if (mode == MODE_TOGEHTER) {
    if (diff > 15000) {
      draw_togheter_time();
      last_draw = millis();
    }
  }
}
