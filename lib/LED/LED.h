#ifndef LED_h
#define LED_h

#include <Arduino.h>

class LED
{
public:
    enum Color
    {
        RED,
        GREEN,
        BLUE,
        WHITE,
        NOTHING
    };
    Color color;
    void ledInit(int RED, int GREEN, int BLUE);
    void setColor(Color color);

private:
    int _RED;
    int _GREEN;
    int _BLUE;
    Color _color;
};
#endif