#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <PS2X_lib.h>

class Controller {
public:
    Controller();

    void setup();

    void loop();

private:
    PS2X ps2x;
    int error;
    byte type;
    byte vibrate;

    static const int PS2_DAT = 13;
    static const int PS2_CMD = 12;
    static const int PS2_SEL = 11;
    static const int PS2_CLK = 10;

    static const bool pressures = false;
    static const bool rumble = false;

    void readGuitarHeroController();

    void readDualShockController();
};


#endif //PLAYER_CONTROLLER_H
