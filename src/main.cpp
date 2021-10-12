//importing the libraries:
#include <Arduino.h>
#include <Joystick.h>
#include <ultrasonic.h>

//creating all of the objects:
  Joystick joystick;
  UltraSonic ultrasonic;


  //defining all of the pins:
  const int buttonPin = 0;
  const int yPin = 0;
  const int xPin = 0;
  const int trigPin = 0;
  const int echoPin = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  joystick.JoystickInit(xPin , yPin , buttonPin);
  ultrasonic.UltraSonicInit(trigPin , echoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
}