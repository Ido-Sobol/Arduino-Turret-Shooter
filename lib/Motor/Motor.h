#ifndef Motor_h
#define Motor_h

#include <Arduino.h>
#include <Encoder.h>

class Motor
{
public:
    Motor(const int forwardPin, const int reversePin, Encoder encoder, String motorName);
    void percentOutput(float power);
    void positionControl();
    void velocityControl();
    void stop();

private:
    int _forwardPin;
    int _reversePin;
    Encoder _encoder;
};
#endif