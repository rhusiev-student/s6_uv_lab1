#include <Arduino.h>
#include "Freenove_4WD_Car_For_ESP32.h"

char field[26][51];
float sins[34];
float coss[34];

void setup() {
  Serial.begin(115200);//Open the serial port and set the baud rate to 115200
  Ultrasonic_Setup();  //Ultrasonic module initialization
  PCA9685_Setup();       //Servo motor initialization
  Servo_1_Angle(90);   //Set the initial value of Servo 1 to 90 degrees
  Servo_2_Angle(90);   //Set the initial value of Servo 2 to 90 degrees
  for (int i = 0; i <= 34; ++i) {
    float angle = i * 5 * PI / 180.0;
    sins[i] = sin(angle);
    coss[i] = cos(angle);
  }
  for (int j = 0; j < 26; ++j) {
    field[j][50] = '\0';
  }
  for (int i = 0; i < 50; ++i) {
    field[25][i] = '_';
  }
  delay(500);          //Wait for the servo to arrive at the specified location
}

void loop() {
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 25; j++) {
      field[j][i] = ' ';
    }
  }
  for (int i = 0; i < 34; ++i) {
    int angle = i * 5;
    Servo_1_Angle(angle);
    delay(20);
    float distance = Get_Sonar() / 12;
    int x = 25 + distance * coss[i];
    int y = distance * sins[i];
    if (x >= 0 && x < 50 && y >= 0 && y < 25) {
      field[y][x] = '#';
    }
  }
  field[0][25] = '8';
  for (int j = 25; j >= 0; --j) {
    Serial.print('|');
    Serial.print(field[j]);
    Serial.println('|');
    delay(10);
  }
  delay(5000);
}
