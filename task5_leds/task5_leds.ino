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
  strip.setLedColorData(8, 100, 0, 0);
  strip.setLedColorData(9, 100, 0, 0);
  strip.show();
}

void front() {
  strip.setLedColorData(2, 255, 255, 255);
  strip.setLedColorData(3, 255, 255, 255);
  strip.show();
}

void off_front() {
  strip.setLedColorData(2, 0, 0, 0);
  strip.setLedColorData(3, 0, 0, 0);
  strip.show();
}

void off_back() {
  strip.setLedColorData(8, 0, 0, 0);
  strip.setLedColorData(9, 0, 0, 0);
  strip.show();
}

void turn_left() {
  strip.setLedColorData(1, 255, 100, 50);
  strip.setLedColorData(10, 255, 100, 50);
  strip.show();
  delay(100);
  strip.setLedColorData(0, 255, 100, 50);
  strip.setLedColorData(11, 255, 100, 50);
  strip.show();
  delay(500);
  strip.setLedColorData(1, 0, 0, 0);
  strip.setLedColorData(10, 0, 0, 0);
  strip.show();
  delay(100);
  strip.setLedColorData(0, 0, 0, 0);
  strip.setLedColorData(11, 0, 0, 0);
  strip.show();
}

void turn_right() {
  strip.setLedColorData(4, 255, 100, 50);
  strip.setLedColorData(7, 255, 100, 50);
  strip.show();
  delay(100);
  strip.setLedColorData(5, 255, 100, 50);
  strip.setLedColorData(6, 255, 100, 50);
  strip.show();
  delay(500);
  strip.setLedColorData(4, 0, 0, 0);
  strip.setLedColorData(7, 0, 0, 0);
  strip.show();
  delay(100);
  strip.setLedColorData(5, 0, 0, 0);
  strip.setLedColorData(6, 0, 0, 0);
  strip.show();
}

void brake() {
  strip.setLedColorData(8, 255, 0, 0);
  strip.setLedColorData(9, 255, 0, 0);
  strip.show();
}

void loop() {
  front();
  delay(2000);
  back();
  delay(2000);
  // my front of car is near batteries, because I'm scared of crashes into the sensors
  for (int i = 0; i < 4; i++) {
    turn_left();
    delay(500);
  }
  delay(2000);
  for (int i = 0; i < 4; i++) {
    turn_right();
    delay(500);
  }
  delay(2000);
  brake();
  delay(2000);
  for (int i = 0; i < 4; i++) {
    turn_left();
    delay(500);
  }
  delay(2000);
  off_front();
  delay(2000);
  for (int i = 0; i < 4; i++) {
    turn_right();
    delay(500);
  }
  delay(2000);
  off_back();
  delay(2000);
}
