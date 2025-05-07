#include <Arduino.h>
#include "settings.h"
#include "rgb.h"

int RGB::scaleColor(uint8_t val)
{
  return map(val, 0, 255, 0, 1023);
}


RGB::RGB()
{
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}


void RGB::setColorRGB(uint8_t red, uint8_t green, uint8_t blue)
{
  analogWrite(RED_PIN, scaleColor(red));
  analogWrite(GREEN_PIN, scaleColor(green));
  analogWrite(BLUE_PIN, scaleColor(blue));
}


void RGB::fadeColor(uint8_t red, uint8_t green, uint8_t blue, int duration)
{
  for (int i = 0; i <= 255; i++)
  {
    setColorRGB(red * i / 255, green * i / 255, blue * i / 255);
    delay(duration / 255);
  }
  for (int i = 255; i >= 0; i--)
  {
    setColorRGB(red * i / 255, green * i / 255, blue * i / 255);
    delay(duration / 255);
  }
}


void RGB::blinkColor(uint8_t red, uint8_t green, uint8_t blue, int duration)
{
  setColorRGB(red, green, blue);
  delay(duration);
  setColorRGB(0, 0, 0);
  delay(duration);
}


void RGB::breatheColor(uint8_t red, uint8_t green, uint8_t blue, int duration)
{
  for (int i = 0; i <= 255; i++)
  {
    setColorRGB(red * i / 255, green * i / 255, blue * i / 255);
    delay(duration / 255);
  }
  for (int i = 255; i >= 0; i--)
  {
    setColorRGB(red * i / 255, green * i / 255, blue * i / 255);
    delay(duration / 255);
  }
}


void RGB::rainbowCycle(int duration)
{
  for (int i = 0; i < 256; i++)
  {
    int red = sin(i * 0.024) * 127 + 128;
    int green = sin(i * 0.024 + 2) * 127 + 128;
    int blue = sin(i * 0.024 + 4) * 127 + 128;
    setColorRGB(red, green, blue);
    delay(duration / 256);
  }
}
