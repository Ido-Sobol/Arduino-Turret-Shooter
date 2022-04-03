#ifndef PIDController_h
#define PIDController_h

#include <Arduino.h>

class PIDController
{
public:
    static float execute(float kp, float ki, float kd, float actual, float wanted,
                         double prevTime, double lastError, double cumError);

private:
};
#endif