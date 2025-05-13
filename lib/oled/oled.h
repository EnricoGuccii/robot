#pragma once
#include <Adafruit_SSD1306.h>
#include "settings.h"


class OLED {
public:
    OLED();

    void init();
    void showMessage(const String& msg,int size = 1 ,int x = 0, int y = 0);
    void drawFullBitmap(const uint8_t* bitmap);
    void showAnimation(const byte* frames, int frameCount, int frameWidth, int frameHeight, int frameDelay);
    void clear();

private:
    Adafruit_SSD1306 display;
};
