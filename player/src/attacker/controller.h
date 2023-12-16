#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <Arduino.h>
#include <PS2X_lib.h>  //for v1.6

#define PS2_DAT        30  //14
#define PS2_CMD        31  //15
#define PS2_SEL        33  //16
#define PS2_CLK        32  //17

#define pressures   false
#define rumble      false

class Controller {
private:
    PS2X ps2x{};
    int error = 0;
    byte type = 0;
    byte vibrate = 0;

    unsigned long previousControllerMillis = 0;
    const long controllerInterval = 50;

    static int joystickValueConversion(int joystickValue, int buffer[], int &index);

    // button
    int pss_RY = 0;
    int pss_LY = 0;
public:
    Controller();

    void setup();

    void loop();

    int getPSS_LY() const { return pss_LY; }

    int getPSS_RY() const { return pss_RY; }
};

#endif //PLAYER_CONTROLLER_H
