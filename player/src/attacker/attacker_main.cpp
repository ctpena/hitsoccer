#include "controller.h"
#include "motor.h"

Controller myController;

// main setup
void setup() {
    myController.setup();
    motorSetup();
}

// main loop
void loop() {
    myController.loop();
    //motorA.setSpeed(30);
    //motorA.setDirection(true);
    //motorB.setSpeed(30);
    //motorB.setDirection(true);
}
