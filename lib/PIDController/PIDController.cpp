#include <Arduino.h>
#include <PIDController.h>

float PIDController::execute(float kp, float ki, float kd, float actual, float wanted,
                             double prevTime, double lastError, double cumError)
{

    const double currentTime = millis();                         // get current time
    const double elapsedTime = (double)(currentTime - prevTime); // compute time elapsed from previous computation

    const double error = wanted - actual;                       // determine error
    cumError += error * elapsedTime;                            // compute integral
    const double rateError = (error - lastError) / elapsedTime; // compute derivative

    double out = kp * error + ki * cumError + kd * rateError; // PID output

    lastError = error;      // remember current error
    prevTime = currentTime; // remember current time

    return out; // have function return the PID output
}