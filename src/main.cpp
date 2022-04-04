// importing the libraries:
#include <Arduino.h>
#include <ultrasonic.h>
#include <turret.h>
#include <shooter.h>
#include <LED.h>
#include <Servo.h>
// creating all of the objects:
const int led = 7;        // TODO: define it
const int red = 8;        // TODO: define it
const int rightTrig = A1; // TODO: define it
const int rightEcho = 9;  // TODO: define it
const int leftTrig = A0;  // TODO: define it
const int leftEcho = 10;  // TODO: define it

const int distToBlinkRight = 27; // * in cm
const int distToBlinkLeft = 15;

UltraSonic left;
UltraSonic right;
void setup()
{
  // put your setup code here, to run once:
  delay(2000);
  Serial.begin(9600);
  left.UltraSonicInit(leftTrig, leftEcho);
  right.UltraSonicInit(rightTrig, rightEcho);
  pinMode(led, OUTPUT);
  pinMode(red, OUTPUT);
}
void loop()
{
  // put your main code here, to run repeatedly
  digitalWrite(led, HIGH);
  if (left.getDistance() < distToBlinkLeft || right.getDistance() < distToBlinkRight)
  {
    digitalWrite(red, HIGH);
    delay(5000);
  }
  else
  {
    digitalWrite(red, LOW);
  }
}