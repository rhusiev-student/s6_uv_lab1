/**********************************************************************
  Product     : Freenove 4WD Car for ESP32
  Description : Use buzzer
  Auther      : www.freenove.com
  Modification: 2020/12/18
**********************************************************************/
#include "Freenove_4WD_Car_For_ESP32.h"

void setup() {
  Buzzer_Setup();    //Buzzer initialization function
  Buzzer_Wiu(600, 784);
  Buzzer_Wiu(600, 880);
  Buzzer_Wiu(400, 587);

  Buzzer_Wiu(600, 880);
  Buzzer_Wiu(600, 988);
  Buzzer_Wiu(100, 1175);
  Buzzer_Wiu(100, 1047);
  Buzzer_Wiu(200, 988);

  Buzzer_Wiu(600, 784);
  Buzzer_Wiu(600, 880);
  Buzzer_Wiu(1000, 587);
}

void loop() {
  Buzzer_WiiII(1000, 587, 880);
  Buzzer_WiiII(1000, 880, 587);
}
