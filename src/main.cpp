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
const int buttonPin = 5;         //digital in
const int yPin = A0;             //analog in
const int xPin = A1;             //analog in
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

  turret.turretMovement(joystick.getX() > 512
                        ? turretForwardPin,
                        (joystick.getX() - 512) * (255 / 1023)
                        : turretReversePin,
                        joystick.getX() * (255 / 1023));

  if (!joystick.getButton() && joystickButtonLastState)
  {
    Serial.println("State change detection!");
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