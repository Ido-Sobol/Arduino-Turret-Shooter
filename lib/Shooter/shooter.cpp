#include <Arduino.h>
#include <shooter.h>

void Shooter::ShooterInit(int ShooterPin)
{
    _ShooterPin = ShooterPin;
    pinMode(_ShooterPin , OUTPUT);
}

void Shooter::ShooterMovement(int power)
{
digitalWrite(_ShooterPin , power);
}