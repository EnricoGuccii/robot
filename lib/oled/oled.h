#pragma once
#include <Adafruit_SSD1306.h>
#include "settings.h"


class OLED {
public:
    OLED();

    void init();
    void showMessage(const String& msg,int size = 1 ,int x = 0, int y = 0);
    void drawBitmap(const uint8_t* bitmap);
    void showAnimation(const uint8_t* animation[], int frames, int delayTime);
    void clear();

private:
    Adafruit_SSD1306 display;
};
