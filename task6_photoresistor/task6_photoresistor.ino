#include "motors.h"

#define PHOTOSENSITIVE_PIN 33 //Define the pins that ESP32 reads photosensitive
int photosensitiveADC;        //Defines a variable to store ADC values

void setup()
{
  PCA9685_Setup();
  pinMode(PHOTOSENSITIVE_PIN, INPUT);//Configure the pins for input mode
  Serial.begin(115200);              //Initialize the serial port and set the baud rate to 115200
}

void loop()
{
  Motor_Move(0, 0, 0, 0);

  int light = analogRead(PHOTOSENSITIVE_PIN);
  int direction = (2048 - light) * 1.5;

  if (direction >= -128 && direction <= 128) {
    Motor_Move(1024, 1024, 1024, 1024);
  } else if (direction > 0) {
    if (direction > 128 && direction < 1024) {
      direction = 1024;
    }
    if (direction > 2048) {
      direction = 2048;
    }
  
    Motor_Move(0, std::round(- (float) direction / 1.2), direction, direction);
  } else {
    if (direction < -128 && direction > -1024) {
      direction = -1024;
    }
    if (direction < -2048) {
      direction = -2048;
    }
  
    Motor_Move(-direction, -direction, 0, std::round((float) direction / 1.2));
  }
  
  delay(10);
}
