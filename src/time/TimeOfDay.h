#pragma once

enum class TimeOfDay {
    MORNING,
    DAY,
    EVENING,
    NIGHT,
    SLEEP
};

class TimeOfDayResolver {
public:
    static TimeOfDay resolve(int hour);
    static const char* toString(TimeOfDay state);
};