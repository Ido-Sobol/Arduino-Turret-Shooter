#include <Arduino.h>
#include <LED.h>

void LED::ledInit(int RED, int GREEN, int BLUE)
{
    _RED = RED;
    _BLUE = BLUE;
    _GREEN = GREEN;
    pinMode(_RED, OUTPUT);
    pinMode(_GREEN, OUTPUT);
    pinMode(_BLUE, OUTPUT);
}

void LED::setColor(Color color)
{
    switch (color)
    {
    case RED:
        digitalWrite(_RED, HIGH);
        digitalWrite(_GREEN, LOW);
        digitalWrite(_BLUE, LOW);
        break;
    case GREEN:
        digitalWrite(_RED, LOW);
        digitalWrite(_GREEN, HIGH);
        digitalWrite(_BLUE, LOW);
        break;
    case BLUE:
        digitalWrite(_RED, LOW);
        digitalWrite(_GREEN, LOW);
        digitalWrite(_BLUE, HIGH);
        break;
    case YELLOW:
        digitalWrite(_RED, HIGH);
        digitalWrite(_GREEN, HIGH);
        digitalWrite(_BLUE, LOW);
    case MAGENTA:
        digitalWrite(_RED, HIGH);
        digitalWrite(_GREEN, LOW);
        digitalWrite(_BLUE, HIGH);
    case WHITE:
        digitalWrite(_RED, HIGH);
        digitalWrite(_GREEN, HIGH);
        digitalWrite(_BLUE, HIGH);
        break;
    case NOTHING:
        digitalWrite(_RED, LOW);
        digitalWrite(_GREEN, LOW);
        digitalWrite(_BLUE, LOW);
        break;
    default:
        break;
    }
}