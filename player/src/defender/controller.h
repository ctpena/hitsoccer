#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <PS2X_lib.h>

class Controller {
public:
    Controller();

    void setup();

    void loop();

    bool isButtonPressed(int button);

    bool isButton(int button);

    int isAnalogValue(int analogButton);

private:
    PS2X ps2x{};
    int error;
    byte type;
    byte vibrate;

    static const int PS2_DAT = 2;
    static const int PS2_CMD = 3;
    static const int PS2_SEL = 4;
    static const int PS2_CLK = 5;

    static const bool pressures = false;
    static const bool rumble = false;

    void readGuitarHeroController();

    void readDualShockController();

    bool noise{};
};


#endif //PLAYER_CONTROLLER_H
