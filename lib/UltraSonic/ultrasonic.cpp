#include <Arduino.h>
#include <ultrasonic.h>

void UltraSonic::UltraSonicInit(int echoPin , int trigPin)
{
    pinMode(trigPin , OUTPUT);
    pinMode(echoPin , INPUT);
    Serial.println("ultrasonic initialized!");
    _trigPin = trigPin;
    _echoPin = echoPin;
}

double UltraSonic::getDistance(){
 digitalWrite(_trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(_echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  return distance;
}