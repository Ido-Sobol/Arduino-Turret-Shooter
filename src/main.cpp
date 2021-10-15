//importing the libraries:
#include <Arduino.h>
#include <Joystick.h>
#include <ultrasonic.h>
#include <turret.h>

//creating all of the objects:
  Joystick joystick;
  UltraSonic ultrasonic;
  Turret turret;


  //defining all of the pins:
  const int buttonPin = 0;
  const int yPin = 0;
  const int xPin = 0;
  const int trigPin = 0;
  const int echoPin = 0;
  const int turretForwardPin = 0;
  const int turretReversePin = 0;


  //turret:
  bool isTurretReversed = false;
  int turretCurrentPin;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  joystick.JoystickInit(xPin , yPin , buttonPin);
  ultrasonic.UltraSonicInit(trigPin , echoPin);
  turret.turretInit(turretForwardPin,turretReversePin);
}

void loop() {
  // put your main code here, to run repeatedly:
    isTurretReversed = joystick.getX() > 0 ? false : true;
    turretCurrentPin = isTurretReversed ? turretReversePin : turretForwardPin;
    turret.turretMovement(turretCurrentPin , joystick.getX());
    
    
}