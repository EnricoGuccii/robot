#include <Arduino.h>
#include "settings.h"
#include "rgb.h"
#include "oled.h"
#include "Buzzer.h"
#include "motors.h"

#include "animations.h"

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
    delay(3000);
}

void loop()
{
    oled.showAnimation(animacja1[0], animacja1FrameCount , animacja1Width, animacja1Height,300);
    //oled.showAnimation(animacja1[0], animacja1FrameCount , animacja1Width+ 20, animacja1Height,50); // fajny efekt
    oled.showAnimation(animacja2[0], animacja2FrameCount , animacja2Width, animacja2Height,300);
}