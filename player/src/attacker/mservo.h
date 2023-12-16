#ifndef SERVO_MOTOR_H
#define SERVO_MOTOR_H

#include <Arduino.h>
#include <Servo.h>

class ServoMotor {
public:
    explicit ServoMotor(int pin);
    void attach();
    void rotate(int angle);

private:
    Servo servo;
    int servoPin;
};

#endif // SERVO_MOTOR_H