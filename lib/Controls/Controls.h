#ifndef Controls_h
#define Controls_h

#include <Arduino.h>

class Controls
{
public:
  void ControlsInit(int rightButton, int leftButton, int shootbutton, int potenPin);
  bool getButton(int pin);
  double getPotentiometer(int pin);

private:
};
#endif