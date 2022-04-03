// importing the libraries:
#include <Arduino.h>
#include <ultrasonic.h>
#include <LED.h>
#include <Motor.h>
#include <Encoder.h>
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

// creating all of the objects:
UltraSonic ultrasonic(echoPin, trigPin);
Motor turret(turretForwardPin, turretReversePin, "turret");
Motor shooter(shooterPin, -1, "shooter wheels");
LED led(redPin, greenPin, bluePin);

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
  led.setColor(led.RED);
  delay(250);
  led.setColor(led.GREEN);
  delay(250);
  led.setColor(led.BLUE);
  delay(250);
  Serial.begin(9600);
  led.setColor(led.NOTHING);
  delay(1000);
}
void loop()
{
  // put your main code here, to run repeatedly
  led.setColor(led.BLUE);
  turret.percentOutput(0.4f);
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
          led.setColor(led.WHITE);
        }
        else
        {
          notSeeingTargetCycleCounter = 0;
          turret.percentOutput(0.4);
        }
        if (notSeeingTargetCycleCounter >= 10)
        {
          noLongerSeeingTargetTime = millis();
          led.setColor(led.YELLOW);
          targetTime = noLongerSeeingTargetTime - seeingTargetTime;
          halfTargetTime = targetTime / 2;
          changeDirectionTime = millis();
          while (millis() - changeDirectionTime <= halfTargetTime * 2)
          {
            turret.percentOutput(-0.4);
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