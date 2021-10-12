#include <Arduino.h>
#include <Joystick.h>
  
  Joystick joystick;
  
  const int buttonPin = 0;
  const int yPin = 0;
  const int xPin = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  joystick.JoystickInit(xPin , yPin , buttonPin);
}

void loop() {
  // put your main code here, to run repeatedly:
}