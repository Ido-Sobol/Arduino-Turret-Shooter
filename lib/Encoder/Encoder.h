#ifndef Encoder_h
#define Encoder_h

#include <Arduino.h>

class Encoder
{
public:
    void EncoderInit();
    int getTicks();
    bool switchDirection();

private:
};
#endif