#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <Arduino.h>
#include <PS2X_lib.h>  //for v1.6

#define PS2_DAT        13  //14
#define PS2_CMD        11  //15
#define PS2_SEL        10  //16
#define PS2_CLK        12  //17

#define pressures   false
#define rumble      false

void controllerSetup();

void controllerLoop();

#endif //PLAYER_CONTROLLER_H
