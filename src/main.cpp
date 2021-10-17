//importing the libraries:
#include <Arduino.h>
#include <Joystick.h>
#include <ultrasonic.h>
#include <turret.h>
#include <shooter.h>
//creating all of the objects:
  Joystick joystick;
  UltraSonic ultrasonic;
  Turret turret;
  Shooter shooter;

  //defining all of the pins:
  const int buttonPin = 0;
  const int yPin = 0;
  const int xPin = 0;
  const int trigPin = 0;
  const int echoPin = 0;
  const int turretForwardPin = 0;
  const int turretReversePin = 0;
  const int shooterPin = 0;


  //turret:
  bool isTurretReversed = false;
  int turretCurrentPin;

  //shooter:
  double shooterPower;
  const double shooterMagicNumber = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  joystick.JoystickInit(xPin , yPin , buttonPin);
  ultrasonic.UltraSonicInit(trigPin , echoPin);
  turret.turretInit(turretForwardPin,turretReversePin);
  shooter.ShooterInit(shooterPin);
}

void loop() {
  // put your main code here, to run repeatedly:


    //deciding which pin to use:
    isTurretReversed = joystick.getX() > 0 ? false : true;
    turretCurrentPin = isTurretReversed ? turretReversePin : turretForwardPin;


    shooter.ShooterMovement(ultrasonic.getDistance() * shooterMagicNumber);
    turret.turretMovement(turretCurrentPin , joystick.getX()); 

}