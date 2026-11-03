#pragma once

#include <Arduino.h>
#include <AnimatedGIF.h>
#include <FS.h>
#include <LittleFS.h>

#include "../display/Display.h"

class AnimationPlayer {
public:
    void begin(Display& display);
    void play(const char* filename);
    void stop();
    void update();
    bool isPlaying() const;

private:
    AnimatedGIF gif;
    Display* display = nullptr;

    bool playing = false;
    String currentFile;
};