#ifndef Shooter_h
#define Shooter_h

#include <Arduino.h>

class Shooter
{
  public:
   void ShooterInit(int ShooterPin); 
   void ShooterMovement (int power);
  private:
    int _ShooterPin;
};
#endif