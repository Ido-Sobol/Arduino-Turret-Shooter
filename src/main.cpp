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
const int turretForwardPin = 9; //pwm
const int turretReversePin = 5; //pwm
const int shooterPin = 6;        //pwm
const int redPin = 8;            //digital out
const int greenPin = 12;         //digital out
const int bluePin = 13;          //digital out
//shooter:
double shooterPower;
const double shooterMagicNumber = 0;
bool lastButtonState;
int cycleCounter = 0;

//Timing vars:

double switchTime = 0;
const double switchDelay = 3000;


bool turretPin = false;

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
//  analogWrite(turretForwardPin , 120);
//  delay(500);
led.setColor(led.BLUE);
turret.turretMovement(turretPin, 110);
if (millis() - switchTime >= switchDelay)
{
  turretPin = !turretPin;
  switchTime = millis();
}
if (ultrasonic.getDistance() < 200) // * in cm
{
  cycleCounter++;
  if(cycleCounter > 5){
  while (true)
  {
    led.setColor(led.GREEN);
    turret.stop();
    shooter.ShooterMovement(200);
  }
  }
}else{
  cycleCounter = 0;
}
}