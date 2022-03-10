#include <Arduino.h>
#include <motor.h>

Motor::Motor(const int forwardPin, const int reversedPin, String motorName)
{
    _forwardPin = forwardPin;
    _reversePin = reversedPin;
    pinMode(_forwardPin, OUTPUT);
    pinMode(_reversePin, OUTPUT);
    Serial.println("motor " + motorName + " initialized!");
}

void Motor::percentOutput(float power) // from -1 to 1
{
    if (power == 0)
    {
        stop();
    }
    else
    {
        analogWrite(power > 0 ? _forwardPin : _reversePin, abs(power) * 255);
    }
}

void Motor::stop()
{
    analogWrite(_forwardPin, 0);
    analogWrite(_reversePin, 0);
}