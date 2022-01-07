/******************************************************************************************************
 * Projekt:       BalanceBot
 * Erstelldatum:  05.11.21
 * Beteiligt:     Lukas Ammann und Philipp Lichtleitner
 * Funktion:      PID-Regler Klasse
 *                Parameter werden als private gespeichert und müssen nicht immer übergeben werden.
 *                               
 * Erweiterungsmöglichkeit: dynamisches anpassen der Parameter während dem Betrieb
 *****************************************************************************************************/


//***********************************************************************************************
//Klassendefinition
//***********************************************************************************************
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

//***********************************************************************************************
//Hinzufügen der einzlenen Funktionen
//***********************************************************************************************

//Konstruktor
PID_Regler::PID_Regler(float P, float I, float D, float Offset)
{
  PID_Regler::P_Wert = P;
  PID_Regler::I_Wert = I;
  PID_Regler::D_Wert = D;
  PID_Regler::Offset_Wert = Offset;
  PID_Regler::Summe=0;
  PID_Regler::Abweichung_alt=0;
}

//Regelfunktion
int PID_Regler::Regler(int IST)
{
  int Stellwert, Delta;
  // = SOLL - IST, SOLL immer 0
  Delta = 0 - IST;
  Summe += Delta;
  //               P-Teil                I-Teil                          D-Teil
  Stellwert = (int)((Delta * PID_Regler::P_Wert) + (PID_Regler::Summe * PID_Regler::I_Wert) + ((PID_Regler::Abweichung_alt- PID_Regler::Abweichung_alt) * PID_Regler::D_Wert));
  PID_Regler::Abweichung_alt = Delta;
  return(Stellwert);
}
