#include "Freenove_WS2812_Lib_for_ESP32.h"

#define LEDS_COUNT  12    //Define the count of WS2812
#define LEDS_PIN  	32    //Define the pin number for ESP32
#define CHANNEL	    0     //Define the channels that control WS2812

Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL, TYPE_GRB);

void setup() {
  strip.begin();		  //Initialize WS2812
  strip.setBrightness(255);//Set the brightness of WS2812
}

void back() {
  strip.setLedColorData(6, 50, 0, 0);
  strip.setLedColorData(7, 50, 0, 0);
  strip.setLedColorData(8, 50, 0, 0);
  strip.setLedColorData(9, 50, 0, 0);
  strip.setLedColorData(10, 50, 0, 0);
  strip.setLedColorData(11, 50, 0, 0);
  strip.show();
}

void brake() {
  strip.setLedColorData(6, 255, 0, 0);
  strip.setLedColorData(7, 255, 0, 0);
  strip.setLedColorData(8, 255, 0, 0);
  strip.setLedColorData(9, 255, 0, 0);
  strip.setLedColorData(10, 255, 0, 0);
  strip.setLedColorData(11, 255, 0, 0);
  strip.show();
}

void front() {
  strip.setLedColorData(0, 255, 255, 255);
  strip.setLedColorData(1, 255, 255, 255);
  strip.setLedColorData(2, 255, 255, 255);
  strip.setLedColorData(3, 255, 255, 255);
  strip.setLedColorData(4, 255, 255, 255);
  strip.setLedColorData(5, 255, 255, 255);
  strip.show();
}

void off_front() {
  strip.setLedColorData(0, 0, 0, 0);
  strip.setLedColorData(1, 0, 0, 0);
  strip.setLedColorData(2, 0, 0, 0);
  strip.setLedColorData(3, 0, 0, 0);
  strip.setLedColorData(4, 0, 0, 0);
  strip.setLedColorData(5, 0, 0, 0);
  strip.show();
}

void off_back() {
  strip.setLedColorData(6, 0, 0, 0);
  strip.setLedColorData(7, 0, 0, 0);
  strip.setLedColorData(8, 0, 0, 0);
  strip.setLedColorData(9, 0, 0, 0);
  strip.setLedColorData(10, 0, 0, 0);
  strip.setLedColorData(11, 0, 0, 0);
  strip.show();
}

void turn_left(bool front, bool back, bool brake) {
  strip.setLedColorData(2, 200, 30, 0);
  strip.setLedColorData(9, 200, 30, 0);
  strip.show();
  delay(100);
  strip.setLedColorData(1, 200, 30, 0);
  strip.setLedColorData(10, 200, 30, 0);
  strip.show();
  delay(100);
  strip.setLedColorData(0, 200, 30, 0);
  strip.setLedColorData(11, 200, 30, 0);
  strip.show();
  delay(500);
  int color1, color2, color3;
  color1 = 0;
  color2 = 0;
  color3 = 0;
  if (front) {
    color1 = 255;
    color2 = 255;
    color3 = 255;
  }
  int color4, color5, color6;
  color4 = 0;
  color5 = 0;
  color6 = 0;
  if (back) {
    color4 = 100;
  }
  if (brake) {
    color4 = 255;
  }
  strip.setLedColorData(2, color1, color2, color3);
  strip.setLedColorData(9, color4, color5, color6);
  strip.show();
  delay(100);
  strip.setLedColorData(1, color1, color2, color3);
  strip.setLedColorData(10, color4, color5, color6);
  strip.show();
  delay(100);
  strip.setLedColorData(0, color1, color2, color3);
  strip.setLedColorData(11, color4, color5, color6);
  strip.show();
}

void turn_right(bool front, bool back, bool brake) {
  strip.setLedColorData(3, 200, 30, 0);
  strip.setLedColorData(8, 200, 30, 0);
  strip.show();
  delay(100);
  strip.setLedColorData(4, 200, 30, 0);
  strip.setLedColorData(7, 200, 30, 0);
  strip.show();
  delay(100);
  strip.setLedColorData(5, 200, 30, 0);
  strip.setLedColorData(6, 200, 30, 0);
  strip.show();
  delay(500);
  int color1, color2, color3;
  color1 = 0;
  color2 = 0;
  color3 = 0;
  if (front) {
    color1 = 255;
    color2 = 255;
    color3 = 255;
  }
  int color4, color5, color6;
  color4 = 0;
  color5 = 0;
  color6 = 0;
  if (back) {
    color4 = 100;
  }
  if (brake) {
    color4 = 255;
  }
  strip.setLedColorData(3, color1, color2, color3);
  strip.setLedColorData(8, color4, color5, color6);
  strip.show();
  delay(100);
  strip.setLedColorData(4, color1, color2, color3);
  strip.setLedColorData(7, color4, color5, color6);
  strip.show();
  delay(100);
  strip.setLedColorData(5, color1, color2, color3);
  strip.setLedColorData(6, color4, color5, color6);
  strip.show();
}

void loop() {
  bool bfront = false;
  bool bback = false;
  bool bbrake = false;
  front();
  bfront = true;
  delay(2000);
  back();
  bback = true;
  delay(2000);
  // my front of car is near batteries, because I'm scared of crashes into the sensors
  for (int i = 0; i < 4; i++) {
    turn_left(bfront, bback, bbrake);
    delay(500);
  }
  delay(2000);
  for (int i = 0; i < 4; i++) {
    turn_right(bfront, bback, bbrake);
    delay(500);
  }
  delay(2000);
  brake();
  bbrake = true;
  delay(2000);
  for (int i = 0; i < 4; i++) {
    turn_left(bfront, bback, bbrake);
    delay(500);
  }
  delay(2000);
  off_front();
  bfront = false;
  delay(2000);
  for (int i = 0; i < 4; i++) {
    turn_right(bfront, bback, bbrake);
    delay(500);
  }
  delay(2000);
  off_back();
  bback = false;
  bbrake = false;
  delay(2000);
}
