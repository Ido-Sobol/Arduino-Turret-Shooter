#include <Arduino.h>
#include <turret.h>

void Turret::turretInit(int forwardPin, int reversedPin)
{
    _forwardPin = forwardPin;
    _reversePin = reversedPin;
    pinMode(_forwardPin, OUTPUT);
    pinMode(_reversePin, OUTPUT);
    Serial.println("turret initialized!");
}

void Turret::turretMovement(bool forward, int power)
{
    if (forward)
    {
        analogWrite(_forwardPin, power);
        analogWrite(_reversePin, 0);
    }else{
        analogWrite(_reversePin, power);
        analogWrite(_forwardPin, 0);
    }
    
}

void Turret::stop(){
    analogWrite(_forwardPin, 0);
    analogWrite(_reversePin, 0);
}