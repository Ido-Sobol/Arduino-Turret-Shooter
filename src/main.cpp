// importing the libraries:
#include <Arduino.h>
#include <ultrasonic.h>
#include <LED.h>
#include <Motor.h>
#include <Encoder.h>
// creating all of the objects:
UltraSonic ultrasonic(echoPin, trigPin);
Motor turret(turretForwardPin, turretReversePin, "turret");
Motor shooter(shooterPin, -1, "shooter wheels");
LED led(redPin, greenPin, bluePin);
// defining all of the pins:
const int shootButtonPin = 0;   // digital in
const int potenPin = A0;        // analog in
const int trigPin = 3;          // pwm
const int echoPin = 2;          // digital out
const int turretForwardPin = 9; // pwm
const int turretReversePin = 5; // pwm
const int shooterPin = 6;       // pwm
const int redPin = 8;           // digital out
const int greenPin = 12;        // digital out
const int bluePin = 13;         // digital out

int cycleCounter = 0;
int notSeeingTargetCycleCounter = 0;

// Timing vars:

const double switchDelay = 3000;
double switchTime = 0;

const double wheelsAccDelay = 2000;
double shooterWheelsStartTime = 0;

double seeingTargetTime;
double noLongerSeeingTargetTime;
double targetTime = 0;
double halfTargetTime;
double changeDirectionTime;

bool turretPin = false;

void setup()
{
  // put your setup code here, to run once:
  delay(2000);
  Serial.begin(9600);
}
void loop()
{
  // put your main code here, to run repeatedly
  //  analogWrite(turretForwardPin , 120);
  //  delay(500);
  led.setColor(led.BLUE);
  turret.percentOutput(0.43f);
  if (millis() - switchTime >= switchDelay)
  {
    turretPin = !turretPin;
    switchTime = millis();
  }
  if (ultrasonic.getDistance() < 200) // * in cm
  {
    cycleCounter++;
    if (cycleCounter > 5)
    {
      shooterWheelsStartTime = millis();
      seeingTargetTime = millis();
      while (true)
      {
        led.setColor(led.MAGENTA);
        if (ultrasonic.getDistance() > 400) // in cm
        {
          notSeeingTargetCycleCounter++;
        }
        else
        {
          notSeeingTargetCycleCounter = 0;
        }
        if (notSeeingTargetCycleCounter >= 5)
        {
          noLongerSeeingTargetTime = millis();

          targetTime = noLongerSeeingTargetTime - seeingTargetTime;
          halfTargetTime = targetTime / 2;
          changeDirectionTime = millis();
          while (millis() - changeDirectionTime <= halfTargetTime * 2)
          {
            turret.percentOutput(0.43f);
          }
          while (true)
          {
            turret.stop();
            shooter.percentOutput(0.8f);
            led.setColor(led.GREEN);
          }
        }
      }
    }
  }
  else
  {
    cycleCounter = 0;
  }
}