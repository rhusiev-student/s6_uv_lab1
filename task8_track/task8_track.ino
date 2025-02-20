#include <Arduino.h>
#include "Freenove_4WD_Car_For_ESP32.h"

void setup() {
  PCA9685_Setup();
  Track_Setup();
  Motor_Move(0, 0, 0, 0);
}

bool left = true;

void loop() {
  Track_Read();
  if (sensorValue[2] && !sensorValue[0]) {
    Motor_Move(1500, 1500, -2000, -4000);
    left = true;
  } else if (!sensorValue[2] && sensorValue[0]) {
    Motor_Move(-2000, -4000, 1500, 1500);
    left = false;
  } else if (!sensorValue[2] && !sensorValue[0] && !sensorValue[1]) {
    if (left) {
      Motor_Move(1500, 1500, -2000, -4000);
    } else {
      Motor_Move(-2000, -4000, 1500, 1500);
    }
  } else {
    Motor_Move(2500, 2500, 2500, 2500);
  }
  delay(10);
}
