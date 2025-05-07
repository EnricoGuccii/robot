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

void RGB::setColorRGB(uint8_t red, uint8_t green, uint8_t blue, bool saveColor = true)
{
  analogWrite(RED_PIN, scaleColor(red));
  analogWrite(GREEN_PIN, scaleColor(green));
  analogWrite(BLUE_PIN, scaleColor(blue));
  if (saveColor)
  {
    currentR = red;
    currentG = green;
    currentB = blue;
  }
}

void RGB::fadeColor(uint8_t red, uint8_t green, uint8_t blue, int duration)
{
  int startR = currentR;
  int startG = currentG;
  int startB = currentB;

  for (int i = 0; i <= duration; i++)
  {
    uint8_t newR = startR + ((red - startR) * i) / duration;
    uint8_t newG = startG + ((green - startG) * i) / duration;
    uint8_t newB = startB + ((blue - startB) * i) / duration;

    setColorRGB(newR, newG, newB, false);
    delay(1);
  }

  setColorRGB(red, green, blue);
}

void RGB::blink(int cycles, int interval)
{
  for (int i = 0; i < cycles; i++)
  {
    setColorRGB(0, 0, 0, false);
    delay(interval);
    setColorRGB(currentR, currentG, currentB, false);
    delay(interval);
  }
}

void RGB::breathe(int cycles, int interval)
{
  uint8_t baseR = currentR;
  uint8_t baseG = currentG;
  uint8_t baseB = currentB;

  for (int c = 0; c < cycles; ++c)
  {
    for (int i = 0; i <= 255; ++i)
    {
      setColorRGB(baseR * i / 255, baseG * i / 255, baseB * i / 255, false);
      delay(interval / 510);
    }

    for (int i = 255; i >= 0; --i)
    {
      setColorRGB(baseR * i / 255, baseG * i / 255, baseB * i / 255, false);
      delay(interval / 510);
    }
  }

  setColorRGB(baseR, baseG, baseB);
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
  setColorRGB(currentR, currentG, currentB, false);
}
