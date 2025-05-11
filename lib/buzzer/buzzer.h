#include <Arduino.h>
#include "settings.h"

#pragma once

class BUZZER
{
public:
    BUZZER();

    void playTone(uint16_t frequency, uint32_t duration = 0);
    void stop();
    void playMelody(const uint16_t melody[][2], size_t length);
};
