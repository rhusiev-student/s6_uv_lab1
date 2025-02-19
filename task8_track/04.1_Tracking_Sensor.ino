#include <Arduino.h>
#include "Freenove_4WD_Car_For_ESP32.h"

void setup() {
  PCA9685_Setup();
  Track_Setup();
}

void loop() {
  Motor_Move(0, 0, 0, 0);
  Track_Read();
  if (sensorValue[0] && !sensorValue[2]) {
    Motor_Move(1500, 1500, 0, -1000);
  } else if (!sensorValue[0] && sensorValue[1]) {
    Motor_Move(0, -1000, 1500, 1500);
  } else {
    Motor_Move(1500, 1500, 1500, 1500);
  }
  delay(50);
}
