/**********************************************************************
  Product     : Freenove 4WD Car for ESP32
  Description : Use WS2812.
  Auther      : www.freenove.com
  Modification: 2020/12/18
**********************************************************************/

#include "Freenove_WS2812_Lib_for_ESP32.h"

#define LEDS_COUNT  12    //Define the count of WS2812
#define LEDS_PIN  	32    //Define the pin number for ESP32
#define CHANNEL	    0     //Define the channels that control WS2812

Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL, TYPE_GRB);

void setup() {
  strip.begin();		  //Initialize WS2812
  strip.setBrightness(10);//Set the brightness of WS2812
}

void bright() {
  strip.setBrightness(255);
  strip.setLedColorData(1, 50, 50, 255);
  strip.setLedColorData(4, 50, 50, 255);
  strip.setLedColorData(7, 50, 50, 255);
  strip.setLedColorData(10, 50, 50, 255);
  strip.show();
}

void not_so_bright() {
  strip.setBrightness(96);
  strip.setLedColorData(1, 50, 50, 255);
  strip.setLedColorData(4, 50, 50, 255);
  strip.setLedColorData(7, 50, 50, 255);
  strip.setLedColorData(10, 50, 50, 255);
  strip.show();
}

void off() {
  strip.setLedColorData(1, 0, 0, 0);
  strip.setLedColorData(4, 0, 0, 0);
  strip.setLedColorData(7, 0, 0, 0);
  strip.setLedColorData(10, 0, 0, 0);
  strip.show();
}

void turn_left() {
  for (int i = 0; i < 4; i++) {
    strip.setLedColorData(5, 50, 255, 50);
    strip.setLedColorData(6, 50, 255, 50);
    strip.show();
    delay(500);
    strip.setLedColorData(5, 0, 0, 0);
    strip.setLedColorData(6, 0, 0, 0);
    strip.show();
    delay(500);
  }
}

void turn_right() {
  for (int i = 0; i < 4; i++) {
    strip.setLedColorData(0, 50, 255, 50);
    strip.setLedColorData(11, 50, 255, 50);
    strip.show();
    delay(500);
    strip.setLedColorData(0, 0, 0, 0);
    strip.setLedColorData(11, 0, 0, 0);
    strip.show();
    delay(500);
  }
}

void brake() {
  strip.setLedColorData(2, 255, 50, 50);
  strip.setLedColorData(3, 255, 50, 50);
  strip.setLedColorData(8, 255, 50, 50);
  strip.setLedColorData(9, 255, 50, 50);
  strip.show();
}

void off_brake() {
  strip.setLedColorData(2, 0, 0, 0);
  strip.setLedColorData(3, 0, 0, 0);
  strip.setLedColorData(8, 0, 0, 0);
  strip.setLedColorData(9, 0, 0, 0);
  strip.show();
}

void loop() {
  not_so_bright();
  delay(2000);
  // my front of car is near batteries, because I'm scared of crashes into the sensors
  turn_left();
  delay(2000);
  turn_right();
  delay(2000);
  brake();
  delay(2000);
  bright();
  delay(2000);
  turn_left();
  delay(2000);
  off();
  delay(2000);
  turn_right();
  delay(2000);
  off_brake();
  delay(2000);
}
