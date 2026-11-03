#include "TimeOfDay.h"

TimeOfDay TimeOfDayResolver::resolve(int hour) {
    if (hour >= 7 && hour < 10) {
        return TimeOfDay::MORNING;
    }

    if (hour >= 10 && hour < 18) {
        return TimeOfDay::DAY;
    }

    if (hour >= 18 && hour < 21) {
        return TimeOfDay::EVENING;
    }

    if (hour >= 21) {
        return TimeOfDay::NIGHT;
    }

    return TimeOfDay::SLEEP;
}

const char* TimeOfDayResolver::toString(TimeOfDay state) {
    switch (state) {
        case TimeOfDay::MORNING: return "MORNING";
        case TimeOfDay::DAY:     return "DAY";
        case TimeOfDay::EVENING: return "EVENING";
        case TimeOfDay::NIGHT:   return "NIGHT";
        case TimeOfDay::SLEEP:   return "SLEEP";
        default:                 return "UNKNOWN";
    }
}