#include "Freenove_4WD_Car_For_ESP32.h"

void setup()
{
  PCA9685_Setup();       //Initializes the chip that controls the motor
}

void loop()
{
    for (int i = 0; i <= 2000; i += 500) {
        Motor_Move(2200, 2200, -i, 0);
        delay(6000);
        Motor_Move(0, 0, 0, 0);
        delay(2000);
    }
    Motor_Move(0, 0, 0, 0);
    delay(5000);
    for (int i = 0000; i <= 4000; i += 1000) {
        Motor_Move(i, i, -1000, 0);
        delay(6000);
        Motor_Move(0, 0, 0, 0);
        delay(2000);
    }
    Motor_Move(0, 0, 0, 0);
    delay(5000);
}
