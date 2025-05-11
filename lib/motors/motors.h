#include <Arduino.h>
#include "settings.h"

#pragma once

class MOTORS
{
public:
    MOTORS();
    void init();

    void forward(int speed, int duration = 0);
    void backward(int speed, int duration = 0);

    void leftForward(int speed, int duration = 0);
    void leftBackward(int speed, int duration = 0);
    void rightForward(int speed, int duration = 0);
    void rightBackward(int speed, int duration = 0);

    void leftTurn(int speed, int duration = 0);
    void rightTurn(int speed, int duration = 0);

    void leftStop();
    void rightStop();
    void stop();

private:
    int scaleSpeed(int speed);
};