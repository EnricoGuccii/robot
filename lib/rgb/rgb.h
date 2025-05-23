#pragma once

#include "settings.h"
#include <Arduino.h>

class RGB
{
public:
    uint8_t currentR;
    uint8_t currentG;
    uint8_t currentB;

    RGB();
    void init();
    void setColorRGB(uint8_t red, uint8_t green, uint8_t blue, bool saveColor);
    void fadeColor(uint8_t red, uint8_t green, uint8_t blue, int duration);
    void blink(int cycles, int interval);
    void breathe(int cycles, int period);
    void rainbowCycle(int duration, float speed);

private:
    int scaleColor(uint8_t val);
};
