#pragma once

#include "../animation/AnimationPlayer.h"
#include "../time/Clock.h"
#include "../time/TimeOfDay.h"
#include "../display/Display.h"
#include "../input/RotaryEncoder.h"

class SnoopyApp {
public:
    void begin();
    void update();

private:
    AnimationPlayer animationPlayer;
    Clock clock;

    TimeOfDay currentTimeOfDay = TimeOfDay::DAY;

    void updateScene(TimeOfDay timeOfDay);    
    Display display;

    RotaryEncoder encoder;

    bool walking = false;
};