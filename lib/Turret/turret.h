#ifndef Turret_h
#define Turret_h

#include <Arduino.h>

class Turret
{
  public:
   void turretInit(int forwardPin, int reversePin); 
   void turretMovement(bool forward , int power);
   void stop();
  private:
    int _forwardPin;
    int _reversePin;
};
#endif