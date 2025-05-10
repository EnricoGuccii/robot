// #include <Arduino.h>
// #include <Wire.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>
// #include "settings.h"
// #include "oled.h"


// OLED::OLED() : display(OLED_WIDTH, OLED_HEIGHT, &Wire, -1)
// {
//     // Najpierw uruchom I2C
//     Wire.begin(SDA_PIN, SCL_PIN);

//     // Potem dopiero inicjalizuj OLED
//     if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
//         Serial.println("OLED init failed!");
//     }

//     display.clearDisplay();
//     display.display();
// }


// void OLED::print(const String &text, int x, int y)
// {
//     display.setTextSize(1);
//     display.setTextColor(WHITE);
//     display.setCursor(x, y);
//     display.println(text);
//     display.display();
// }

// void OLED::clear()
// {
//     display.clearDisplay();
//     display.display();
// }

// void OLED::drawBox()
// {
//     display.drawRect(0, 0, 128, 64, WHITE);
//     display.display();
// }
