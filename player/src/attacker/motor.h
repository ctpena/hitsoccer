#ifndef PLAYER_MOTOR_H
#define PLAYER_MOTOR_H

#include <Arduino.h>

class Motor {
private:
    int enPin; //pwm
    int inPin1;
    int inPin2;

public:
    Motor(int en, int in1, int in2)
            : enPin(en), inPin1(in1), inPin2(in2) {}

    void setup() const {
        pinMode(enPin, OUTPUT);
        pinMode(inPin1, OUTPUT);
        pinMode(inPin2, OUTPUT);
        stop();
    }

    void setSpeed(int speed) const {
        analogWrite(enPin, speed);
    }

    void setDirection(bool pn) const {
        if (pn) {
            digitalWrite(inPin1, HIGH);
            digitalWrite(inPin2, LOW);
        } else {
            digitalWrite(inPin1, LOW);
            digitalWrite(inPin2, HIGH);
        }
    }

    void stop() const {
        digitalWrite(inPin1, LOW);
        digitalWrite(inPin2, LOW);
    }
};

extern Motor motorA;
extern Motor motorB;

void motorSetup();

void motorLoop();


#endif //PLAYER_MOTOR_H
