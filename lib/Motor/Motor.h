#ifndef Motor_h
#define Motor_h

#include <Arduino.h>

class Motor
{
public:
    Motor(const int forwardPin, const int reversePin, String motorName);
    void percentOutput(float power);
    void stop();

private:
    int _forwardPin;
    int _reversePin;
};
#endif