
#pragma once

#include <Arduino.h>

class RotaryEncoder
{
public:
    void begin();
    void update();

    bool isTurning() const;

private:
    static constexpr int ENCODER_PIN = 22;
    static constexpr unsigned long TURN_TIMEOUT = 500;

    static volatile bool rotationDetected;

    static void IRAM_ATTR onRotation();

    unsigned long lastTurnAt = 0;
    bool hasTurned = false;
};
