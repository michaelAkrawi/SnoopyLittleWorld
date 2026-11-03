#include "Display.h"

void Display::begin() {
    screen.init();
    screen.setRotation(1);

    // Match RGB565 byte order for pushImage()
    screen.setSwapBytes(true);

    screen.fillScreen(TFT_BLACK);
}

TFT_eSPI& Display::tft() {
    return screen;
}