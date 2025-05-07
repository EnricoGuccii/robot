#pragma once

#include "settings.h"
#include <Arduino.h>

class RGB
{
public:
    RGB();
    void setColorRGB(uint8_t red, uint8_t green, uint8_t blue);
    void fadeColor(uint8_t red, uint8_t green, uint8_t blue, int duration);
    void blinkColor(uint8_t red, uint8_t green, uint8_t blue, int duration);
    void breatheColor(uint8_t red, uint8_t green, uint8_t blue, int duration);
    void rainbowCycle(int duration);

private:
    int scaleColor(uint8_t val);
};

