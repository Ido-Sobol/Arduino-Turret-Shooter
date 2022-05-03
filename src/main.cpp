// importing the libraries:
#include <Arduino.h>
#include <ultrasonic.h>
#include <turret.h>
#include <shooter.h>
#include <LED.h>
#include <Servo.h>
#include <Encoder.h>
// creating all of the objects:
UltraSonic ultrasonic;
Turret turret;
Shooter shooter;
LED led;
Encoder encoder;

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
const int encoderPin = 10;

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

const double wantedVel = 0.3;
const double kp = 1.6;
const double pConstant = 0.2;
double vel = 0;
double err;
double lastTime = 0;
double lastTicks = 0;
double lastCheck = 0;

void setup()
{
  // put your setup code here, to run once:
  delay(2000);
  Serial.begin(9600);
  ultrasonic.UltraSonicInit(trigPin, echoPin);
  turret.turretInit(turretForwardPin, turretReversePin);
  shooter.ShooterInit(shooterPin);
  led.ledInit(redPin, greenPin, bluePin);
  encoder.encoderInit(encoderPin);
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
            turret.turretMovement(!turretPin, 110);
          }
          while (true)
          {
            turret.stop();
            if (((err * kp + pConstant) * 255) >= 163)
            {
              digitalWrite(redPin, HIGH);
              digitalWrite(greenPin, LOW);
              digitalWrite(bluePin, HIGH);
            }
            else
            {
              led.setColor(led.GREEN);
            }

            shooter.ShooterMovement(((err * kp + pConstant) * 255));
            encoder.update();
            if (millis() - lastCheck >= 100)
            {
              vel = (encoder.getTicks() - lastTicks) / (millis() - 100);
              err = wantedVel - vel;
            }

            // Serial.print("ticks: ");
            // Serial.print(encoder.getTicks());
            // Serial.print(" last ticks: ");
            Serial.println((err * kp + pConstant) * 255);
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