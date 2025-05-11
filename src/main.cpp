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



void setup()
{
    rgb.init();
    buzzer.init();
    motors.init();
    
}

void loop()
{
    rgb.setColorRGB(0, 255, 0, true);
    motors.forward(100, 2000);
    delay(1000);
    rgb.setColorRGB(255, 0, 0, true);
    motors.backward(100, 2000);
    delay(1000);
    rgb.setColorRGB(0, 255, 255, true);
    motors.leftTurn(100, 2000);
    delay(1000);
    rgb.setColorRGB(255, 255, 0, true);
    motors.rightTurn(100, 2000);
    delay(1000);

    motors.rightForward(100, 2000);
    delay(1000);
    motors.rightBackward(100, 2000);
    delay(1000);
    motors.leftForward(100, 2000);
    delay(1000);
    motors.leftBackward(100, 2000);
    delay(1000);

  // buzzer.playMelody(happy, 8);
  // delay(1000);
  // buzzer.playMelody(anger, 8);
  // delay(1000);
  // buzzer.playMelody(alaarm, 9);
  // delay(1000);
  // buzzer.playMelody(surprise, 9);
  // delay(1000);

  //buzzer.playMelody(melody, 8);                  
  // rgb.setColorRGB(255, 0, 0, true);
  // delay(1000);
  // rgb.fadeColor(0, 255, 0, 1000);
  // delay(1000);
  // rgb.blink(3, 500);
  // delay(1000);
  // rgb.breathe(4, 1000);
  // rgb.rainbowCycle(8000, 1.0);
  // rgb.setColorRGB(0, 0, 0, true);
  // delay(1000);
  // rgb.rainbowCycle(8000, 1);
  // rgb.setColorRGB(0, 0, 0, true);
  // delay(1000);
  // rgb.rainbowCycle(8000, 2);
}