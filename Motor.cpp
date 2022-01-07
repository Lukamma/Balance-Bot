/******************************************************************************************************
 * Projekt:       BalanceBot
 * Erstelldatum:  10.12.21
 * Beteiligt:     Lukas Ammann und Philipp Lichtleitner
 * Funktion:      Motor Klasse
 *                Parameter werden als private gespeichert und müssen nicht immer übergeben werden.
 *****************************************************************************************************/


//***********************************************************************************************
//Klassendefinition
//***********************************************************************************************
class MotorController
{
  private:
    uint8_t Pin_Dir;
    uint8_t Pin_Step;
  public:
    MotorController(uint8_t pinDir; uint8_t pinStep);

};

//***********************************************************************************************
//Hinzufügen der einzlenen Funktionen
//***********************************************************************************************

//Konstruktor
MotorController::MotorController(uint8_t pinDir; uint8_t pinStep)
{
  MotorController::Pin_Dir = pinDir;
  MotorController::Pin_Step = pinStep;
  pinMode(pinDir,OUTPUT);
  pinMode(pinStep,OUTPUT);
}


//Evtl CCW und CW tauschen, benötigt test
void MotorController::ChangeDirCW(void)
{
  digitalWrite(MotorController::Pin_Dir,LOW);
}

//Evtl CCW und CW tauschen, benötigt test
void MotorController::ChangeDirCCW(void)
{
  digitalWrite(MotorController::Pin_Dir,HIGH);
}
