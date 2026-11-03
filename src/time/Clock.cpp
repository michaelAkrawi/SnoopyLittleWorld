#include "Clock.h"

namespace {
    const char* NTP_SERVER = "pool.ntp.org";

    // Israel / Jerusalem
    // Handles IST (UTC+2) and IDT (UTC+3) automatically.
    const char* TIMEZONE =
        "IST-2IDT,M3.4.4/26,M10.5.0";
}

void Clock::begin() {
    configTzTime(TIMEZONE, NTP_SERVER);

    Serial.println("[Clock] NTP configured");
    Serial.println("[Clock] Timezone: Israel");
}

bool Clock::getTimeInfo(struct tm& timeInfo) const {
    return getLocalTime(&timeInfo, 100);
}

bool Clock::isReady() const {
    struct tm timeInfo;
    return getTimeInfo(timeInfo);
}

int Clock::hour() const {
    struct tm timeInfo;

    if (!getTimeInfo(timeInfo)) {
        return -1;
    }

    return timeInfo.tm_hour;
}

int Clock::minute() const {
    struct tm timeInfo;

    if (!getTimeInfo(timeInfo)) {
        return -1;
    }

    return timeInfo.tm_min;
}

String Clock::timeString() const {
    struct tm timeInfo;

    if (!getTimeInfo(timeInfo)) {
        return "--:--";
    }

    char buffer[6];
    strftime(buffer, sizeof(buffer), "%H:%M", &timeInfo);

    return String(buffer);
}

String Clock::dateString() const {
    struct tm timeInfo;

    if (!getTimeInfo(timeInfo)) {
        return "--- -- ---";
    }

    char buffer[16];
    strftime(buffer, sizeof(buffer), "%a %d %b", &timeInfo);

    return String(buffer);
}