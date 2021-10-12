#include <Arduino.h>
#include <Joystick.h>

void Joystick::JoystickInit(int VRx , int VRy , int SW)
{
   pinMode(VRx, INPUT);
   pinMode(VRy, INPUT);
   pinMode(SW, INPUT_PULLUP); 
   _VRx = VRx;
   _VRy = VRy;
   _SW = SW;
       Serial.println("joystick initialized!");
}

double Joystick::getX()
{
    return map(analogRead(_VRx) , 0, 1023, 0, 255);
}

double Joystick::getY()
{
    return map(analogRead(_VRy) , 0, 1023, 0, 255);
}

bool Joystick::getButton()
{
    return digitalRead(_SW);
}