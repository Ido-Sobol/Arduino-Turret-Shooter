#include <Arduino.h>
#include <LED.h>

LED::LED(int RED, int GREEN, int BLUE)
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
    if (color == RED)
    {
        digitalWrite(_RED, HIGH);
        digitalWrite(_GREEN, LOW);
        digitalWrite(_BLUE, LOW);
    }
    else if (color == GREEN)
    {
        digitalWrite(_RED, LOW);
        digitalWrite(_GREEN, HIGH);
        digitalWrite(_BLUE, LOW);
    }
    else if (color == BLUE)
    {
        digitalWrite(_RED, LOW);
        digitalWrite(_GREEN, LOW);
        digitalWrite(_BLUE, HIGH);
    }
    else if (color == YELLOW)
    {
        digitalWrite(_RED, HIGH);
        digitalWrite(_GREEN, HIGH);
        digitalWrite(_BLUE, LOW);
    }
    else if (color == MAGENTA)
    {
        digitalWrite(_RED, HIGH);
        digitalWrite(_GREEN, LOW);
        digitalWrite(_BLUE, HIGH);
    }
    else if (color == WHITE)
    {
        digitalWrite(_RED, HIGH);
        digitalWrite(_GREEN, HIGH);
        digitalWrite(_BLUE, HIGH);
    }
    else if (color == NOTHING)
    {
        digitalWrite(_RED, LOW);
        digitalWrite(_GREEN, LOW);
        digitalWrite(_BLUE, LOW);
    }
}