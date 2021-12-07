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
const int rightButtonPin = 0;    //digital in
const int leftButtonPin = 0;     //digital in
const int shootButtonPin = 0;    //digital in
const int potenPin = 0;          //analog in
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
const double shooterWheelsDelayTime;

bool shootButtonLastState;

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
  controls.ControlsInit(rightButtonPin, leftButtonPin, shootButtonPin, potenPin);
}

void loop()
{
  // put your main code here, to run repeatedly
  shooterServo.write(servoBlockPosition);
  shooter.ShooterMovement(0);
  led.setColor(led.BLUE);

  turret.turretMovement(!controls.getButton(rightButtonPin) ? rightButtonPin : !controls.getButton(leftButtonPin) ? leftButtonPin
                                                                                                                  : -1 //pin that does nothing
                        ,
                        controls.getPotentiometer(potenPin) * (1023 / 255));

  if (!controls.getButton(shootButtonPin) && shootButtonLastState)
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
  shootButtonLastState = controls.getButton(shootButtonPin);
}