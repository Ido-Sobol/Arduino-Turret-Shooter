#include <Arduino.h>
#include <Encoder.h>

int currentTicks;
int lastTicks;
float lastTimeMeasured = 0;
bool lastDirection;

Encoder::Encoder(int ticksPerRound, int counterPin, int directionPin)
{
    pinMode(counterPin, OUTPUT);
    pinMode(directionPin, OUTPUT);
    _counterPin = counterPin;
    _directionPin = directionPin;
    _ticksPerRound = ticksPerRound;
}

int Encoder::getTicks()
{
    lastTicks = currentTicks;
    const bool direction = digitalRead(_directionPin); // Reads the "current" state of the outputA
    // If the previous and the current state of the outputA are different, that means a Pulse has occured
    if (direction != lastDirection)
    {
        // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
        if (digitalRead(_counterPin) != direction)
        {
            currentTicks++;
        }
        else
        {
            currentTicks--;
        }
    }
    lastTimeMeasured = millis();
    lastDirection = direction; // Updates the previous state of the outputA with the current state
    return currentTicks;
}

float Encoder::getVelocity()
{
    return (abs(getTicks() - lastTicks)) / (millis() - lastTimeMeasured);
}