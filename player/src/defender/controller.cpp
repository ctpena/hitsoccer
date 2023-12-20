#include "controller.h"

Controller::Controller() : error(0), type(0), vibrate(0) {}

void Controller::setup() {
    Serial.begin(57600);
    delay(300);

    int retryCount = 0;
    const int maxRetries = 5;

    while (true) {
        error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);

        if (error == 0) {
            Serial.println("Found Controller, configured successful");
            break;
        } else {
            Serial.print("Error configuring PS2 controller. Error code: ");
            Serial.println(error);
            retryCount++;
            if (retryCount >= maxRetries) {
                Serial.println("Maximum retry attempts reached. Please check the hardware and restart.");
                break;
            }
            Serial.print("Retrying... Attempt ");
            Serial.println(retryCount);
            delay(1000);
        }
    }

    type = ps2x.readType();
    switch (type) {
        case 0:
            Serial.print("Unknown Controller type found ");
            break;
        case 1:
            Serial.print("DualShock Controller found ");
            break;
        case 2:
            Serial.print("GuitarHero Controller found ");
            break;
        case 3:
            Serial.print("Wireless Sony DualShock Controller found ");
            break;
    }
}

void Controller::loop() {
    if (error == 1) return;

    switch (type) {
        case 2:
            readGuitarHeroController();
            break;
        default:
            readDualShockController();
            break;
    }

    delay(50);
}

void Controller::readGuitarHeroController() {
    ps2x.read_gamepad();
    noise = (
            (ps2x.Analog(PSS_RY) == 255 || ps2x.Analog(PSS_RY) == 0) &&
            (ps2x.Analog(PSS_RX) == 255 || ps2x.Analog(PSS_RX) == 0) &&
            (ps2x.Analog(PSS_LY) == 255 || ps2x.Analog(PSS_LY) == 0) &&
            (ps2x.Analog(PSS_LX) == 255 || ps2x.Analog(PSS_LX) == 0)
    );
}

void Controller::readDualShockController() {
    ps2x.read_gamepad(false, vibrate);
    noise = (
            (ps2x.Analog(PSS_RY) == 255 || ps2x.Analog(PSS_RY) == 0) &&
            (ps2x.Analog(PSS_RX) == 255 || ps2x.Analog(PSS_RX) == 0) &&
            (ps2x.Analog(PSS_LY) == 255 || ps2x.Analog(PSS_LY) == 0) &&
            (ps2x.Analog(PSS_LX) == 255 || ps2x.Analog(PSS_LX) == 0)
    );
}

bool Controller::isButtonPressed(int button) {
    return ps2x.ButtonPressed(button);
}

bool Controller::isButton(int button) {
    return ps2x.Button(button);
}

int Controller::isAnalogValue(int analogButton) {
    if (!noise) {
        return ps2x.Analog(analogButton);
    }
}
