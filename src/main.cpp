//importing the libraries:
#include <Arduino.h>
#include <ultrasonic.h>
#include <turret.h>
#include <shooter.h>
#include <LED.h>
#include <Servo.h>
//creating all of the objects:
UltraSonic ultrasonic;
Turret turret;
Shooter shooter;
LED led;

//defining all of the pins:
const int shootButtonPin = 0;    //digital in
const int potenPin = A0;         //analog in
const int trigPin = 3;           //pwm
const int echoPin = 2;           //digital out
const int turretForwardPin = 10; //pwm
const int turretReversePin = 11; //pwm
const int shooterPin = 5;        //pwm
const int redPin = 8;            //digital out
const int greenPin = 12;         //digital out
const int bluePin = 13;          //digital out
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
}

void loop()
{
  // put your main code here, to run repeatedly
}