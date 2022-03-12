#ifndef Encoder_h
#define Encoder_h

#include <Arduino.h>

class Encoder
{
public:
    Encoder(int _ticksPerRound, int counterPin, int directionPin);
    int getTicks();
    float getVelocity();

private:
    int _ticksPerRound;
    int _counterPin;
    int _directionPin;
};
#endif