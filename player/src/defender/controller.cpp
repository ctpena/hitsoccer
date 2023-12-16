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
    if (ps2x.ButtonPressed(GREEN_FRET))
        Serial.println("Green Fret Pressed");
    if (ps2x.ButtonPressed(RED_FRET))
        Serial.println("Red Fret Pressed");
    if (ps2x.ButtonPressed(YELLOW_FRET))
        Serial.println("Yellow Fret Pressed");
    if (ps2x.ButtonPressed(BLUE_FRET))
        Serial.println("Blue Fret Pressed");
    if (ps2x.ButtonPressed(ORANGE_FRET))
        Serial.println("Orange Fret Pressed");

    if (ps2x.ButtonPressed(STAR_POWER))
        Serial.println("Star Power Command");

    if (ps2x.Button(UP_STRUM))          //will be TRUE as long as button is pressed
        Serial.println("Up Strum");
    if (ps2x.Button(DOWN_STRUM))
        Serial.println("DOWN Strum");

    if (ps2x.Button(PSB_START))         //will be TRUE as long as button is pressed
        Serial.println("Start is being held");
    if (ps2x.Button(PSB_SELECT))
        Serial.println("Select is being held");

    if (ps2x.Button(ORANGE_FRET)) {     // print stick value IF TRUE
        Serial.print("Wammy Bar Position:");
        Serial.println(ps2x.Analog(WHAMMY_BAR), DEC);
    }
}

void Controller::readDualShockController() {
    ps2x.read_gamepad(false, vibrate); //read controller and set large motor to spin at 'vibrate' speed

    if (ps2x.Button(PSB_START))         //will be TRUE as long as button is pressed
        Serial.println("Start is being held");
    if (ps2x.Button(PSB_SELECT))
        Serial.println("Select is being held");

    if (ps2x.Button(PSB_PAD_UP)) {      //will be TRUE as long as button is pressed
        Serial.print("Up held this hard: ");
        Serial.println(ps2x.Analog(PSAB_PAD_UP), DEC);
    }
    if (ps2x.Button(PSB_PAD_RIGHT)) {
        Serial.print("Right held this hard: ");
        Serial.println(ps2x.Analog(PSAB_PAD_RIGHT), DEC);
    }
    if (ps2x.Button(PSB_PAD_LEFT)) {
        Serial.print("LEFT held this hard: ");
        Serial.println(ps2x.Analog(PSAB_PAD_LEFT), DEC);
    }
    if (ps2x.Button(PSB_PAD_DOWN)) {
        Serial.print("DOWN held this hard: ");
        Serial.println(ps2x.Analog(PSAB_PAD_DOWN), DEC);
    }

    vibrate = ps2x.Analog(
            PSAB_CROSS);  //this will set the large motor vibrate speed based on how hard you press the blue (X) button
    if (ps2x.NewButtonState()) {        //will be TRUE if any button changes state (on to off, or off to on)
        if (ps2x.Button(PSB_L3))
            Serial.println("L3 pressed");
        if (ps2x.Button(PSB_R3))
            Serial.println("R3 pressed");
        if (ps2x.Button(PSB_L2))
            Serial.println("L2 pressed");
        if (ps2x.Button(PSB_R2))
            Serial.println("R2 pressed");
        if (ps2x.Button(PSB_TRIANGLE))
            Serial.println("Triangle pressed");
    }

    if (ps2x.ButtonPressed(PSB_CIRCLE))               //will be TRUE if button was JUST pressed
        Serial.println("Circle just pressed");
    if (ps2x.NewButtonState(PSB_CROSS))               //will be TRUE if button was JUST pressed OR released
        Serial.println("X just changed");
    if (ps2x.ButtonReleased(PSB_SQUARE))              //will be TRUE if button was JUST released
        Serial.println("Square just released");

    if (ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1)) { //print stick values if either is TRUE
        Serial.print("Stick Values:");
        Serial.print(ps2x.Analog(PSS_LY), DEC); //Left stick, Y axis. Other options: LX, RY, RX
        Serial.print(",");
        Serial.print(ps2x.Analog(PSS_LX), DEC);
        Serial.print(",");
        Serial.print(ps2x.Analog(PSS_RY), DEC);
        Serial.print(",");
        Serial.println(ps2x.Analog(PSS_RX), DEC);
    }
}
