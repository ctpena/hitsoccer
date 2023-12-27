#include "motor.h"
#include <Arduino.h>

Motor::Motor(int pwmPin, int dirPin) : pwmPin(pwmPin), dirPin(dirPin) {}

void Motor::setup() const {
    pinMode(pwmPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
    stop();
}

void Motor::setSpeed(int speed) const {
    if (speed > 0) {
        digitalWrite(dirPin, LOW);
        int pwmValue = static_cast<int>(map(speed, 0, 100, 100, 255));
        analogWrite(pwmPin, pwmValue);
    } else if (speed < 0) {
        digitalWrite(dirPin, HIGH);
        int pwmValue = static_cast<int>(map(abs(speed), 0, 100, 155, 0));
        analogWrite(pwmPin, pwmValue);
    } else {
        digitalWrite(dirPin, LOW);
        digitalWrite(pwmPin, LOW);
    }
}

void Motor::brake() const {
    digitalWrite(dirPin, HIGH);
    digitalWrite(pwmPin, HIGH);
}

void Motor::stop() const {
    digitalWrite(dirPin, LOW);
    digitalWrite(pwmPin, LOW);
}
