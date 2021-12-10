/******************************************************************************************************
 * Projekt:       BalanceBot
 * Erstelldatum:  05.11.21
 * Beteiligt:     Lukas Ammann und Philipp Lichtleitner
 * Funktion:      PID-Regler header
 *****************************************************************************************************/
#ifndef PID_H 
#define PID_H 

class PID_Regler
{
  private:
    float P_Wert;
    float I_Wert;
    float D_Wert;
    float Offset_Wert;
    float Summe;
    float Abweichung_alt;
  public:
    PID_Regler(float P, float I, float D, float Offset);
    int Regler(int IST);
};

#endif
