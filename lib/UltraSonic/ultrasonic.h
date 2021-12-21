#ifndef UltraSonic_h
#define UltraSonic_h

#include <Arduino.h>

class UltraSonic
{
public:
  void UltraSonicInit(int trigPin, int echoPin);
  double getDistance();

private:
  int _trigPin;
  int _echoPin;
  long duration;
};
#endif