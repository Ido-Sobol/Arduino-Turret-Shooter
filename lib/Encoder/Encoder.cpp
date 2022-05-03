#include <Arduino.h>
#include <Encoder.h>

void Encoder::encoderInit(int encoderPin)
{
    _encoderPin = encoderPin;
}

double Encoder::getTicks()
{
    return ticks;
}

void Encoder::update()
{
    encoderState = digitalRead(_encoderPin);
    if (encoderState != lastEncoderState)
    {
        ticks++;
    }
    lastEncoderState = encoderState;
}