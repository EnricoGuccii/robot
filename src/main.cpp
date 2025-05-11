#include <Arduino.h>
#include "settings.h"
#include "rgb.h"
#include "oled.h"
#include "Buzzer.h"
#include "motors.h"

RGB rgb;
BUZZER buzzer;
MOTORS motors; // speed 80 is prefered, because of higher input voltage (5V -> 3.7V after H-bridge), motor is rated for 3V
// in practice, speed below 70 dosn't even work.
OLED oled;

void setup()
{
    rgb.init();
    buzzer.init();
    motors.init();
    oled.init();
    oled.showMessage("czesc");
    //oled.drawBitmap(Logo);
}

void loop()
{
    
}