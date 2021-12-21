#include <Arduino.h>
#include <Controls.h>

void Controls::ControlsInit(int shootbutton, int potenPin)
{
    pinMode(shootbutton, INPUT_PULLUP);
    pinMode(potenPin, INPUT);
    Serial.println("Controls initialized!");
}

bool Controls ::getButton(int pin)
{
    return digitalRead(pin);
}
double Controls::getPotentiometer(int potenPin)
{
    return analogRead(potenPin);
}