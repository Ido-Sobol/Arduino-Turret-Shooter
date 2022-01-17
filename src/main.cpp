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
Servo shooterServo;

//defining all of the pins:
const int rightButtonPin = 7;    //digital in
const int leftButtonPin = 6;     //digital in
const int shootButtonPin = 0;    //digital in
const int potenPin = A0;         //analog in
const int trigPin = 0;           //pwm
const int echoPin = 0;           //analog in
const int turretForwardPin = 10; //pwm
const int turretReversePin = 11; //pwm
const int shooterPin = 0;        //pwm
const int redPin = 0;            //digital out
const int greenPin = 0;          //digital out
const int bluePin = 0;           //digital out
const int servoPin = 0;          //pwm

//shooter:
double shooterPower;
const double shooterMagicNumber = 0;

const int servoBlockPosition = 0;
const int servoFreePosition = 0;

//Timing vars:
double shooterWheelsStartTime;
const double shooterWheelsDelayTime = 0;
bool shootButtonLastState;

int turretCurrentPin;
double turretPower;

double servoMovingTime = 0;
const double servoMovingDelayTime = 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  ultrasonic.UltraSonicInit(trigPin, echoPin);
  turret.turretInit(turretForwardPin, turretReversePin);
  shooter.ShooterInit(shooterPin);
  led.ledInit(redPin, greenPin, bluePin);
  shooterServo.attach(servoPin);
}

void loop()
{
  // put your main code here, to run repeatedly
}