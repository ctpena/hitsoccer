#include <Arduino.h>
#include "controller.h"
#include "motor.h"

Controller controller;

Motor motor1(9, 11);
Motor motor2(10, 12);

void setup() {
    pinMode(8, OUTPUT);
    digitalWrite(8, HIGH);
    motor1.setup();
    motor2.setup();
    controller.setup();
}

void loop() {
    controller.loop();
    int leftStickY = controller.isAnalogValue(PSS_LY);
    int rightStickY = controller.isAnalogValue(PSS_RY);
    Serial.print(leftStickY);
    Serial.print(" , ");
    Serial.println(rightStickY);
    motor1.setSpeed(10);
    motor2.setSpeed(10);
}
