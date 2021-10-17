#include <Arduino.h>
#include <shooter.h>

void Shooter::ShooterInit(int ShooterPin)
{
    _ShooterPin = ShooterPin;
    pinMode(_ShooterPin , OUTPUT);
    Serial.println("shooter initialized!");
}

void Shooter::ShooterMovement(int power)
{
digitalWrite(_ShooterPin , power);
}