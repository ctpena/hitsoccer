#include "motor.h"

Motor motorA(5, 7, 4);
Motor motorB(6, 3, 2);

void motorSetup() {
    motorA.setup();
    motorB.setup();
}

// original loop
void motorLoop() {
}