#include "motor.h"

Motor motorA(5, 4, 7);
Motor motorB(6, 2, 3);

void motorSetup() {
    motorA.setup();
    motorB.setup();
}

// original loop
void motorLoop() {
}