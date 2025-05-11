#include <Arduino.h>
#include "settings.h"
#include "motors.h"

#define LEFT_CHANNEL 4
#define RIGHT_CHANNEL 5

#define MOTOR_FREQ 5000
#define MOTOR_RES 10

int MOTORS::scaleSpeed(int speed)
{
    return map(speed, 0, 100, 0, (1 << MOTOR_RES) - 1);
}

MOTORS::MOTORS()
{
}

void MOTORS::stop()
{
    ledcWrite(LEFT_CHANNEL, 0);
    ledcWrite(RIGHT_CHANNEL, 0);
}

void MOTORS::leftStop()
{
    ledcWrite(LEFT_CHANNEL, 0);
}

void MOTORS::rightStop()
{
    ledcWrite(RIGHT_CHANNEL, 0);
}

void MOTORS::init()
{
    ledcSetup(RIGHT_CHANNEL, MOTOR_FREQ, MOTOR_RES);
    ledcAttachPin(EN34, RIGHT_CHANNEL);

    ledcSetup(LEFT_CHANNEL, MOTOR_FREQ, MOTOR_RES);
    ledcAttachPin(EN12, LEFT_CHANNEL);

    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}

void MOTORS::leftForward(int speed, int duration)
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    ledcWrite(LEFT_CHANNEL, scaleSpeed(speed));

    if (duration > 0)
    {
        delay(duration);
        stop();
    }
}

void MOTORS::leftBackward(int speed, int duration)
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    ledcWrite(LEFT_CHANNEL, scaleSpeed(speed));

    if (duration > 0)
    {
        delay(duration);
        stop();
    }
}

void MOTORS::rightForward(int speed, int duration)
{
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    ledcWrite(RIGHT_CHANNEL, scaleSpeed(speed));
    ledcWrite(LEFT_CHANNEL, 0);

    if (duration > 0)
    {
        delay(duration);
        stop();
    }
}

void MOTORS::rightBackward(int speed, int duration)
{
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    ledcWrite(RIGHT_CHANNEL, scaleSpeed(speed));
    ledcWrite(LEFT_CHANNEL, 0);

    if (duration > 0)
    {
        delay(duration);
        stop();
    }
}

void MOTORS::forward(int speed, int duration)
{
    rightForward(speed);
    leftForward(speed);
    if (duration > 0)
    {
        delay(duration);
        stop();
    }
}

void MOTORS::backward(int speed, int duration)
{
    rightBackward(speed);
    leftBackward(speed);
    if (duration > 0)
    {
        delay(duration);
        stop();
    }
}

void MOTORS::rightTurn(int speed, int duration)
{
    rightForward(speed);
    leftBackward(speed);
    if (duration > 0)
    {
        delay(duration);
        stop();
    }
}

void MOTORS::leftTurn(int speed, int duration)
{
    rightBackward(speed);
    leftForward(speed);
    if (duration > 0)
    {
        delay(duration);
        stop();
    }
}