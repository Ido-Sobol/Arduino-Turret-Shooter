#ifndef Encoder_h
#define Encoder_h

#include <Arduino.h>

class Encoder
{
public:
    void encoderInit(int encoderPin);
    double getTicks();
    void update();

private:
    int ticks;
    bool encoderState;
    bool lastEncoderState;
    int _encoderPin;
};
#endif