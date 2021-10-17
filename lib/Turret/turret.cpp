#include <Arduino.h>
#include <turret.h>


void Turret::turretInit(int forwardPin , int reversedPin)
{
_forwardPin = forwardPin;
_reversePin = reversedPin;
pinMode(_forwardPin , OUTPUT);
pinMode(_reversePin , OUTPUT);
    Serial.println("turret initialized!");
}

void Turret::turretMovement(int pin , int power)
{
digitalWrite(pin , power);
}