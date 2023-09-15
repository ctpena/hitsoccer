#include <Arduino.h>
#include <PS2X_lib.h>  //for v1.6

#define PS2_DAT        13  //14
#define PS2_CMD        11  //15
#define PS2_SEL        10  //16
#define PS2_CLK        12  //17

#define pressures   false
#define rumble      false

PS2X ps2x; // create PS2 Controller Class

//right now, the library does NOT support hot pluggable controllers, meaning
//you must always either restart your Arduino after you connect the controller,
//or call config_gamepad(pins) again after connecting the controller.

int error = 0;
byte type = 0;
byte vibrate = 0;

void setup() {
    Serial.begin(57600);
    delay(300);
    error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);

    if (error == 0) {
        Serial.println("コントローラを見つけ、設定に成功しました");
        Serial.print("pressures = ");
        if (pressures) {
            Serial.println("true");
        } else {
            Serial.println("false");
        }
        Serial.print("rumble = ");
        if (rumble) {
            Serial.println("true");
        } else {
            Serial.println("false");
        }
    } else if (error == 1)
        Serial.println(
                "コントローラーが見つかりません、配線を確認してください");

    else if (error == 2)
        Serial.println(
                "コントローラーは検出されましたが、コマンドを受け付けていません");

    else if (error == 3)
        Serial.println("コントローラーは「Pressuresモード」に入るのを拒否しています");

    type = ps2x.readType();
    switch (type) {
        default:
            Serial.println("コントローラータイプを識別できません");
            break;
        case 0:
            Serial.println("不明なコントローラータイプが見つかりました");
            break;
        case 1:
            Serial.println("DualShockコントローラーが見つかりました");
            break;
        case 2:
            Serial.println("GuitarHeroコントローラーが見つかりました");
            break;
        case 3:
            Serial.println("無線のSony DualShockコントローラーが見つかりました");
            break;
    }
}

void loop() {
    if (error == 1) //skip loop if no controller found
        return;

    if (type != 2) {
        ps2x.read_gamepad();
        /* note
         * ps2x.Button - will be TRUE as long as button is pressed
         * ps2x.ButtonPressed - will be TRUE if button was JUST pressed
         * ps2x.NewButtonState - will be TRUE if button was JUST pressed OR released
         * ps2x.ButtonReleased - will be TRUE if button was JUST released
        */
    }
    delay(50);
}
