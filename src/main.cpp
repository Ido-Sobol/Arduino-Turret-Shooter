// importing the libraries:
#include <Arduino.h>
#include <ultrasonic.h>
#include <turret.h>
#include <shooter.h>
#include <LED.h>
#include <Servo.h>
// creating all of the objects:
const int white1 = 0;    // TODO: define it
const int white2 = 0;    // TODO: define it
const int white3 = 0;    // TODO: define it
const int red1 = 0;      // TODO: define it
const int red2 = 0;      // TODO: define it
const int rightTrig = 0; // TODO: define it
const int rightEcho = 0; // TODO: define it
const int leftTrig = 0;  // TODO: define it
const int leftEcho = 0;  // TODO: define it

const int distToBlinkRight = 27;
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
  pinMode(white1, OUTPUT);
  pinMode(white2, OUTPUT);
  pinMode(white3, OUTPUT);
  pinMode(red1, OUTPUT);
  pinMode(red2, OUTPUT);
}
void loop()
{
  // put your main code here, to run repeatedly
  digitalWrite(white1, HIGH);
  digitalWrite(white2, HIGH);
  digitalWrite(white3, HIGH);
  if (left.getDistance() < distToBlinkLeft || right.getDistance() < distToBlinkRight)
  {
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);
    delay(5000);
  }
  else
  {
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
  }
}