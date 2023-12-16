#include "mservo.h"

ServoMotor::ServoMotor(int pin) : servoPin(pin) {}

void ServoMotor::attach() {
    servo.attach(servoPin);
}

void ServoMotor::rotate(int angle) {
    servo.write(angle);
}