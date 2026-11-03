#pragma once

#include <Arduino.h>
#include <time.h>

class Clock {
public:
    void begin();

    bool isReady() const;

    int hour() const;
    int minute() const;

    String timeString() const;
    String dateString() const;

private:
    bool getTimeInfo(struct tm& timeInfo) const;
};