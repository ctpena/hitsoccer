#include "controller.h"
#include "motor.h"
#include "mservo.h"

Controller myController;
ServoMotor servo1(9);
ServoMotor servo2(8);

// main setup
void setup() {
    myController.setup();
    motorSetup();
    servo1.attach();
    servo2.attach();
}

// TODO Simplify the process
int remapValue(int value) {
    int absoluteValue = abs(value);
    // max 120
    return static_cast<int>(map(absoluteValue, 0, 100, 50, 255));
}

// main loop
void loop() {
    myController.loop();
    //
    if (myController.getPSS_RY() < 0) {
        motorA.setDirection(false);
    } else if (myController.getPSS_RY() == 0) {
        motorA.stop();
    } else {
        motorA.setDirection(true);
    }

    if (myController.getPSS_LY() < 0) {
        motorB.setDirection(false);
    } else if (myController.getPSS_LY() == 0) {
        motorB.stop();
    } else {
        motorB.setDirection(true);
    }
    motorA.setSpeed(remapValue(myController.getPSS_LY()));
    motorB.setSpeed(remapValue(myController.getPSS_RY()));
    //
    servo2.rotate(90);
    servo1.rotate(0);
}
