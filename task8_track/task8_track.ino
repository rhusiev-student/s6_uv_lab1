#include <Arduino.h>
#include "Freenove_4WD_Car_For_ESP32.h"

void setup() {
  PCA9685_Setup();
  Track_Setup();
  Motor_Move(0, 0, 0, 0);
}

void loop() {
  Track_Read();
  if (sensorValue[0] && !sensorValue[2]) {
    Motor_Move(2000, 2000, 0, -1500);
  } else if (!sensorValue[0] && sensorValue[1]) {
    Motor_Move(0, -1500, 2000, 2000);
  } else {
    Motor_Move(2000, 2000, 2000, 2000);
  }
  delay(50);
}
