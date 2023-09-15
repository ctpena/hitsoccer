#include "led.h"
#include "subled.h"

void setup() {
    ledSetup();
    subledSetup();
}

void loop() {
    ledLoop();
    subledLoop();
}
