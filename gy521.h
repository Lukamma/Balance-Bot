/******************************************************************************************************
 * Projekt:       BalanceBot
 * Erstelldatum:  05.11.21
 * Beteiligt:     Lukas Ammann und Philipp Lichtleitner
 * Funktion:      Header für den Sensor gy521
 *****************************************************************************************************/

#ifndef GY521_H 
#define GY521_H 
   
void gyro_Init(void);

uint16_t gyro_GetY(void); 

#endif 
