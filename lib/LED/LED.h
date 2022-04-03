#ifndef LED_h
#define LED_h

#include <Arduino.h>

class LED
{
public:
    LED(int RED, int green, int blue);
    enum Color
    {
        RED,
        GREEN,
        BLUE,
        WHITE,
        MAGENTA,
        NOTHING,
        YELLOW,
    };
    Color color;
    void setColor(Color color);

private:
    int _RED;
    int _GREEN;
    int _BLUE;
    Color _color;
};
#endif