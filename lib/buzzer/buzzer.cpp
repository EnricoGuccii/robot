#include <Arduino.h>
#include "settings.h"
#include "buzzer.h"

#define BUZZER_CHANNEL 3
#define BUZZER_RESOLUTION 8
#define BUZZER_FREQ 2000

BUZZER::BUZZER()
{
}

void BUZZER::init()
{
    ledcSetup(BUZZER_CHANNEL, BUZZER_FREQ, BUZZER_RESOLUTION);
    ledcAttachPin(BUZZER_PIN, BUZZER_CHANNEL);
}

void BUZZER::playTone(uint16_t frequency, uint32_t duration)
{
    ledcWriteTone(BUZZER_CHANNEL, frequency);
    if (duration > 0)
    {
        delay(duration);
        stop();
    }
}

void BUZZER::playMelody(const uint16_t melody[][2], size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        playTone(melody[i][0], melody[i][1]);
        delay(50);
    }
}

void BUZZER::stop()
{
    ledcWriteTone(BUZZER_CHANNEL, 0);
}