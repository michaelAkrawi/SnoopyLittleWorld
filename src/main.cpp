#include <Arduino.h>
#include "app/SnoopyApp.h"

SnoopyApp app;

void setup() {
    app.begin();
}

void loop() {
    app.update();
}