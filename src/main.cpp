//importing the libraries:
#include <Arduino.h>
#include <Joystick.h>
#include <ultrasonic.h>
#include <turret.h>
#include <shooter.h>
#include <LED.h>
#include <Servo.h>

//creating all of the objects:
Joystick joystick;
UltraSonic ultrasonic;
Turret turret;
Shooter shooter;
LED led;
Servo shooterServo;

//defining all of the pins:
const int buttonPin = 0;        //digital in
const int yPin = 0;             //analog in
const int xPin = 0;             //analog in
const int trigPin = 0;          //pwm
const int echoPin = 0;          //analog in
const int turretForwardPin = 0; //pwm
const int turretReversePin = 0; //pwm
const int shooterPin = 0;       //pwm
const int redPin = 0;           //digital out
const int greenPin = 0;         //digital out
const int bluePin = 0;          //digital out
const int servoPin = 0;         //pwm

//turret:
bool isTurretReversed = false;
int turretCurrentPin;

//shooter:
double shooterPower;
const double shooterMagicNumber = 0;

bool joystickButtonLastState;

const int servoBlockPosition = 0;
const int servoFreePosition = 0;

//Timing vars:
double shooterWheelsStartTime;
const double shooterWheelsDelayTime;

double servoMovingTime = 0;
const double servoMovingDelayTime = 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  joystick.JoystickInit(xPin, yPin, buttonPin);
  ultrasonic.UltraSonicInit(trigPin, echoPin);
  turret.turretInit(turretForwardPin, turretReversePin);
  shooter.ShooterInit(shooterPin);
  led.ledInit(redPin, greenPin, bluePin);
  shooterServo.attach(servoPin);
}

void loop()
{
  // put your main code here, to run repeatedly

  shooterServo.write(servoBlockPosition);
  shooter.ShooterMovement(0);
  led.setColor(led.BLUE);

  //deciding which pin to use:
  isTurretReversed = joystick.getX() > 0 ? false : true;
  turretCurrentPin = isTurretReversed ? turretReversePin : turretForwardPin;

  turret.turretMovement(turretCurrentPin, joystick.getX());

  if (!joystick.getButton() && joystickButtonLastState)
  {
    shooterWheelsStartTime = millis();
    while (millis() - shooterWheelsStartTime <= shooterWheelsDelayTime)
    {
      shooter.ShooterMovement(ultrasonic.getDistance() * shooterMagicNumber);
      led.setColor(led.RED);
    }

    servoMovingTime = millis();
    while (millis() - servoMovingTime <= servoMovingDelayTime)
    {

      led.setColor(led.GREEN);
      shooterServo.write(servoFreePosition);
      shooter.ShooterMovement(ultrasonic.getDistance() * shooterMagicNumber);
    }
  }
  joystickButtonLastState = joystick.getButton();
}