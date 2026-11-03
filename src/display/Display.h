#pragma once

#include <TFT_eSPI.h>

class Display {
public:
    void begin();

    TFT_eSPI& tft();

private:
    TFT_eSPI screen;
};