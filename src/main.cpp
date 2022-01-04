//importing the libraries:
#include <Arduino.h>
#include <ultrasonic.h>
#include <turret.h>
#include <shooter.h>
#include <LED.h>
#include <Controls.h>
//creating all of the objects:
UltraSonic ultrasonic;
Turret turret;
Shooter shooter;
LED led;
Controls controls;

//defining all of the pins:
const int shootButtonPin = 0;    //digital in
const int potenPin = A0;         //analog in
const int trigPin = 3;           //pwm
const int echoPin = 2;           //digital out
const int turretForwardPin = 10; //pwm
const int turretReversePin = 11; //pwm
const int shooterPin = 6;        //pwm
const int redPin = 8;            //digital out
const int greenPin = 12;         //digital out
const int bluePin = 13;          //digital out

//shooter:
const double shooterPower = 200;
double shooterStartTime;
int targetCount = 0;
bool isShooting;
bool lastIsShooting;
int noTargetCount;

void setup()
{
  // put your setup code here, to run once:
  delay(2000);
  Serial.begin(9600);
  ultrasonic.UltraSonicInit(trigPin, echoPin);
  turret.turretInit(turretForwardPin, turretReversePin);
  shooter.ShooterInit(shooterPin);
  led.ledInit(redPin, greenPin, bluePin);
  controls.ControlsInit(shootButtonPin, potenPin);
  led.setColor(led.BLUE);
}

void loop()
{
  // put your main code here, to run repeatedly
  if (ultrasonic.getDistance() < 150)
  {
    noTargetCount = 0;
    isShooting = true;
    shooterStartTime = millis();
    led.setColor(millis() - shooterStartTime >= 1000 ? led.GREEN : led.BLUE);
    shooter.ShooterMovement(shooterPower);
    Serial.println("shooting");
  }
  if (ultrasonic.getDistance() >= 150)
  {
    isShooting = false;
    if (isShooting && !lastIsShooting)
    {
      noTargetCount++;
    }
    if (noTargetCount >= 20)
    {
      led.setColor(led.RED);
      shooter.ShooterMovement(0);
      Serial.println("not shooting");
    }
    Serial.print("current Distance: ");
    Serial.println(ultrasonic.getDistance());
    lastIsShooting = isShooting;
  }
}