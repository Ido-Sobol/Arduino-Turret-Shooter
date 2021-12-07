#include <Arduino.h>
#include <Controls.h>

void Controls::ControlsInit(int rightButton, int leftButton, int shootbutton, int potenPin)
{
    pinMode(rightButton, INPUT_PULLUP);
    pinMode(leftButton, INPUT_PULLUP);
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