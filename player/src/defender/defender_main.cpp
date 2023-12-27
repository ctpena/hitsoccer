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

int convertValue(int originalValue) {
    if (originalValue <= 127) {
        return map(originalValue, 0, 127, 100, 0);
    } else {
        return map(originalValue, 128, 255, -1, -100);
    }
}

int leftStickY;
int rightStickY;

void loop() {
    controller.loop();
    if (controller.isButton(PSB_L1) || controller.isButton(PSB_R1)) {
        leftStickY = convertValue(controller.isAnalogValue(PSS_LY));
        rightStickY = convertValue(controller.isAnalogValue(PSS_RY));
        //Serial.print(leftStickY);
        //Serial.print(" , ");
        //Serial.println(rightStickY);
    }
    motor1.setSpeed(leftStickY);
    motor2.setSpeed(rightStickY);
}
