#ifndef Turret_h
#define Turret_h

#include <Arduino.h>

class Turret
{
  public:
   void turretInit(int forwardPin, int reversePin); 
   void turretMovement(int pin , int power);
  private:
    int _forwardPin;
    int _reversePin;
};
#endif