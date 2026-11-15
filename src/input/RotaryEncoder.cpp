
#include "RotaryEncoder.h"

volatile bool RotaryEncoder::rotationDetected = false;

void RotaryEncoder::begin()
{
    pinMode(ENCODER_PIN, INPUT_PULLUP);

    attachInterrupt(
        digitalPinToInterrupt(ENCODER_PIN),
        onRotation,
        FALLING
    );

    Serial.println("[Encoder] Ready");
}

void IRAM_ATTR RotaryEncoder::onRotation()
{
    rotationDetected = true;
}

void RotaryEncoder::update()
{
    if (rotationDetected)
    {
        rotationDetected = false;
        lastTurnAt = millis();
        hasTurned = true;
    }
}

bool RotaryEncoder::isTurning() const
{
    return hasTurned &&
           (millis() - lastTurnAt < TURN_TIMEOUT);
}
