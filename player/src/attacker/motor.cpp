#include "motor.h"

Motor motorA(9, 8, 7);
Motor motorB(3, 5, 4);

void motorSetup() {
    motorA.setup();
    motorB.setup();
}

void motorLoop() {
    motorA.setSpeed(28);
    motorB.setSpeed(28);
    motorA.setDirection(false);
    motorB.setDirection(false);
}
