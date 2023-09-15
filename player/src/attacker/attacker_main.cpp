#include "controller.h"
#include "motor.h"

void setup() {
    controllerSetup();
    motorSetup();
}

void loop() {
    controllerLoop();
    motorLoop();
}
