#include <Arduino.h>
#include "settings.h"
#include "rgb.h"
#include <math.h>

#define RED_CHANNEL 0
#define GREEN_CHANNEL 1
#define BLUE_CHANNEL 2

#define PWM_FREQ 5000
#define PWM_RES 10

int RGB::scaleColor(uint8_t val)
{
  return map(val, 0, 255, 0, (1 << PWM_RES) - 1);
}
RGB::RGB()
    : currentR(0), currentG(0), currentB(0)
{
}

void RGB::init()
{
  ledcSetup(RED_CHANNEL, PWM_FREQ, PWM_RES);
  ledcAttachPin(RED_PIN, RED_CHANNEL);

  ledcSetup(GREEN_CHANNEL, PWM_FREQ, PWM_RES);
  ledcAttachPin(GREEN_PIN, GREEN_CHANNEL);

  ledcSetup(BLUE_CHANNEL, PWM_FREQ, PWM_RES);
  ledcAttachPin(BLUE_PIN, BLUE_CHANNEL);
}

void RGB::setColorRGB(uint8_t red, uint8_t green, uint8_t blue, bool saveColor = true)
{
  ledcWrite(RED_CHANNEL, scaleColor(red));
  ledcWrite(GREEN_CHANNEL, scaleColor(green));
  ledcWrite(BLUE_CHANNEL, scaleColor(blue));

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

void RGB::breathe(int cycles, int period)
{
  const int steps = 128;
  int stepDelay = period / (steps * 2);

  uint8_t baseR = currentR;
  uint8_t baseG = currentG;
  uint8_t baseB = currentB;

  for (int c = 0; c < cycles; ++c)
  {
    for (int i = 0; i <= steps; ++i)
    {
      float scale = (float)i / steps;
      setColorRGB(baseR * scale, baseG * scale, baseB * scale, false);
      delay(stepDelay);
    }

    for (int i = steps; i >= 0; --i)
    {
      float scale = (float)i / steps;
      setColorRGB(baseR * scale, baseG * scale, baseB * scale, false);
      delay(stepDelay);
    }
  }

  setColorRGB(baseR, baseG, baseB);
}

void RGB::rainbowCycle(int duration, float speed)
{
  // speed (0.1 – slow, 1.0 – normal, 2.0 – fast)
  const int steps = 256;

  for (int i = 0; i < steps; i++)
  {
    float angle = i * speed * 0.024;
    int red = sin(angle) * 127 + 128;
    int green = sin(angle + 2) * 127 + 128;
    int blue = sin(angle + 4) * 127 + 128;

    setColorRGB(red, green, blue, false);
    delay(duration / steps);
  }

  setColorRGB(currentR, currentG, currentB, false);
}
