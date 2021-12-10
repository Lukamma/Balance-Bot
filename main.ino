/******************************************************************************************************
 * Projekt:       BalanceBot
 * Erstelldatum:  05.11.21
 * Beteiligt:     Lukas Ammann und Philipp Lichtleitner
 * Funktion:      Mainfile, verbinet die einzelnen Funktionen
 *****************************************************************************************************/

#include "gy521.h"
#include "PID.h"

//Variabeln definieren
int16_t Y_Winkel;
int16_t Stellwert;
  
PID_Regler PID(1, 0, 0, 2);

void setup() {                                                      //setup code here, to run once:

  gyro_Init();

  Serial.begin(115200);
}

void loop() {                                                       //main code here, to run repeatedly:
  
  Y_Winkel = gyro_GetY();                                           //Winkel einlesen
  Stellwert = PID.Regler(Y_Winkel);
  Serial.println(Stellwert);
  delay(500);                                                       //kurze Pause in ms
}
