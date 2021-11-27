#include <Arduino.h>
#include <Joystick.h>

void Joystick::JoystickInit(int VRx, int VRy, int SW)
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
    return analogRead(_VRx);
}

double Joystick::getY()
{
    return analogRead(_VRy);
}

bool Joystick::getButton()
{
    return digitalRead(_SW);
}