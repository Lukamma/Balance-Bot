#include "gy521.h"

//Variabeln definieren
int16_t Y_Winkel_Ist;
  

void setup() {                                                      //setup code here, to run once:

  gyro_Init();
  Serial.begin(115200);
}

void loop() {                                                       //main code here, to run repeatedly:
  
  Y_Winkel = gyro_GetY();                                           //Winkel einlesen
  Serial.println(Y);Serial.print(" ");
  delay(500);                                                       //kurze Pause in ms
}
