#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "settings.h"
#include "oled.h"


OLED::OLED()
: display(OLED_WIDTH, OLED_HEIGHT, &Wire, -1) {}

void OLED::init() {
    Wire.begin(SDA_PIN, SCL_PIN);
    display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
}

void OLED::showMessage(const String& msg, int size, int x, int y) {
    display.clearDisplay();
    display.setCursor(x, y);
    display.setTextSize(size);
    display.setTextColor(SSD1306_WHITE);
    display.println(msg);
    display.display();
}

void OLED::drawBitmap(const uint8_t* bitmap) {
    display.clearDisplay();
    display.drawBitmap(0, 0, bitmap, OLED_WIDTH, OLED_HEIGHT, SSD1306_WHITE);
    display.display();
}

void OLED::showAnimation(const uint8_t* animation[], int frames, int delayTime) {
    for (int i = 0; i < frames; i++) {
        drawBitmap(animation[i]);
        delay(delayTime);
    }
}

void OLED::clear() {
    display.clearDisplay();
    display.display();
}
