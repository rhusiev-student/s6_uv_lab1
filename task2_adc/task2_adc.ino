/**********************************************************************
  Product     : Freenove 4WD Car for ESP32
  Description : Read battery voltage.
  Auther      : www.freenove.com
  Modification: 2020/12/18
**********************************************************************/
#include "Freenove_4WD_Car_For_ESP32.h"

void setup() {
  Serial.begin(115200);                     //Set the Serial Baud rate
}

void loop() {
  Serial.print("Joystick X, Y : ");
  Serial.print(joystick_read_x());
  Serial.print(" ");
  Serial.println(joystick_read_y());
  delay(300);
}
