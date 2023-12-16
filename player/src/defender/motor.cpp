#include "motor.h"
#include <Arduino.h>

Motor::Motor(int pwmPin, int dirPin) : pwmPin(pwmPin), dirPin(dirPin) {}

void Motor::setup() const {
    pinMode(pwmPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
    stop();
}

void Motor::setSpeed(int speed) const {
    digitalWrite(dirPin, LOW);
    analogWrite(pwmPin, 0);
}

void Motor::brake() const {
    digitalWrite(dirPin, HIGH);
    digitalWrite(pwmPin, HIGH);
}

void Motor::stop() const {
    digitalWrite(dirPin, LOW);
    digitalWrite(pwmPin, LOW);
}