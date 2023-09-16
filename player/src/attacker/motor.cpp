#include "motor.h"

Motor motorA(9, 8, 7);
Motor motorB(3, 5, 4);

void motorSetup() {
    motorA.setup();
    motorB.setup();
}

// original loop
void motorLoop() {
    /*
    motorA.setSpeed(0);
    motorB.setSpeed(0);
    motorA.setDirection(false);
    motorB.setDirection(false);
     */
}
