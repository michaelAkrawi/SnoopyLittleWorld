#include "SnoopyApp.h"
#include <Arduino.h>

void SnoopyApp::begin() {
    Serial.begin(115200);

    Serial.println();
    Serial.println("Snoopy's Little World");

    display.begin();

    animationPlayer.begin(display);
    clock.begin();

    animationPlayer.play("/snoopy_typing.gif");
}



void SnoopyApp::update()
{
    animationPlayer.update();
}

void SnoopyApp::updateScene(TimeOfDay timeOfDay) {
    switch (timeOfDay) {
        case TimeOfDay::MORNING:
            animationPlayer.play("/morning/snoopy.gif");
            break;

        case TimeOfDay::DAY:
            animationPlayer.play("/day/snoopy_typing.gif");
            break;

        case TimeOfDay::EVENING:
            animationPlayer.play("/evening/snoopy.gif");
            break;

        case TimeOfDay::NIGHT:
            animationPlayer.play("/night/snoopy.gif");
            break;

        case TimeOfDay::SLEEP:
            animationPlayer.play("/sleep/snoopy.gif");
            break;
    }
}