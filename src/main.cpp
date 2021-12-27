//importing the libraries:
#include <Arduino.h>
#include <ultrasonic.h>
#include <turret.h>
#include <shooter.h>
#include <LED.h>
#include <Servo.h>
#include <Controls.h>
//creating all of the objects:
UltraSonic ultrasonic;
Turret turret;
Shooter shooter;
LED led;
Servo shooterServo;
Controls controls;

//defining all of the pins:
const int shootButtonPin = 0;    //digital in
const int potenPin = A0;         //analog in
const int trigPin = 3;           //pwm
const int echoPin = 2;           //analog in
const int turretForwardPin = 10; //pwm
const int turretReversePin = 11; //pwm
const int shooterPin = 5;        //pwm
const int redPin = 0;            //digital out
const int greenPin = 0;          //digital out
const int bluePin = 0;           //digital out
const int servoPin = 0;          //pwm

//shooter:
double shooterPower;
const double shooterMagicNumber = 0;
bool lastButtonState;

//Timing vars:
double shooterWheelsStartTime;
const double shooterWheelsDelayTime = 4000;

double timeSinceLastSwitch = 5000; //TODO: need to check this logic
const double switchDelay = 4000;

int turretCurrentPin;
double turretPower;

double currentDistance;
double lastDistanceMeasured;
double targetDistance;
bool detectedPossibleTarget = false;
int targetCount = 0;

void setup()
{
  // put your setup code here, to run once:
  delay(2000);
  Serial.begin(9600);
  ultrasonic.UltraSonicInit(trigPin, echoPin);
  turret.turretInit(turretForwardPin, turretReversePin);
  shooter.ShooterInit(shooterPin);
  led.ledInit(redPin, greenPin, bluePin);
  shooterServo.attach(servoPin);
  controls.ControlsInit(shootButtonPin, potenPin);
  led.setColor(led.BLUE);
}

void loop()
{
  while (1)
  {
    shooter.ShooterMovement(200);
  }

  // put your main code here, to run repeatedly
  if (millis() - timeSinceLastSwitch <= switchDelay)
  {
    if (turretCurrentPin == turretForwardPin)
    {
      turretCurrentPin = turretReversePin;
    }
    else
    {
      turretCurrentPin = turretForwardPin;
    }
  }
  turret.turretMovement(turretCurrentPin, turretPower);
  if (controls.getButton(shootButtonPin) && lastButtonState)
  {
    currentDistance = ultrasonic.getDistance();
    if (abs(currentDistance - lastDistanceMeasured) > 100)
    {
      detectedPossibleTarget = true;
    }
    if (abs(targetDistance - currentDistance) < 20)
    {
      targetCount++;
    }
    if (detectedPossibleTarget && targetCount >= 10)
    {
      targetCount = 0;
      led.setColor(led.RED);
      shooter.ShooterMovement(80);
      shooterWheelsStartTime = millis();
    }
    if (millis() - shooterWheelsStartTime <= shooterWheelsDelayTime)
    {
      led.setColor(led.GREEN);
    }
    lastDistanceMeasured = currentDistance;
    lastButtonState = controls.getButton(shootButtonPin);
  }
}