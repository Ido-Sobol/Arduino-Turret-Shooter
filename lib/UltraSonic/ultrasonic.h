#ifndef UltraSonic_h
#define UltraSonic_h

#include <Arduino.h>

class UltraSonic
{
public:
  UltraSonic(const int trigPin, const int echoPin);
  double getDistance();

private:
  int _trigPin;
  int _echoPin;
  long duration;
};
#endif