#include <Arduino.h>
#include "controller.h"
#include "motor.h"

Controller controller;

Motor motor1(3, 2);
Motor motor2(5, 4);

void setup() {
    pinMode(7, OUTPUT);
    digitalWrite(7, HIGH);
    controller.setup();
}

void loop() {
    controller.loop();
    motor1.setSpeed(255);
}
