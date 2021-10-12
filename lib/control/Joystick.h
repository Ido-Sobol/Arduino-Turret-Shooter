#ifndef Joystick_h
#define Joystick_h

#include <Arduino.h>

class Joystick
{
  public:
   void JoystickInit(int VRx , int VRy , int SW);
    double getX();
    double getY();
    bool getButton();
  private:
    int _VRx;
    int _VRy;
    int _SW;
};
#endif