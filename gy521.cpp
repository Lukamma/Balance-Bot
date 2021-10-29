#include <Wire.h>
#define MPU_I2C_address 0x68

void gyro_Init(void)
{
  Wire.begin();
  Wire.beginTransmission(0x68);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);
  //Serial.begin(9600);
}

uint16_t gyro_GetY(void)
{
  int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
  Wire.beginTransmission(0x68);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(0x68,12,true);  
  AcX=Wire.read()<<8|Wire.read();    
  AcY=Wire.read()<<8|Wire.read();  
  AcZ=Wire.read()<<8|Wire.read();  
  GyX=Wire.read()<<8|Wire.read();  
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read();  
  return(AcY*90./16384.);
}
