#ifdef __SAMD21__
#ifndef __RTC_SAMD21_H__
#define __RTC_SAMD21_H__
#include "DateTime.h"

// Default date & time after reset
#define DEFAULT_YEAR 2000 // 2000..2063
#define DEFAULT_MONTH 1   // 1..12
#define DEFAULT_DAY 1     // 1..31
#define DEFAULT_HOUR 0    // 1..23
#define DEFAULT_MINUTE 0  // 0..59
#define DEFAULT_SECOND 0  // 0..59

class RTC_SAMD21
{
public:
    enum Alarm_Match : uint8_t // Should we have this enum or just use the identifiers from /component/rtc.h ?
    {
        MATCH_OFF = RTC_MODE2_MASK_SEL_OFF_Val,                  // Never
        MATCH_SS = RTC_MODE2_MASK_SEL_SS_Val,                    // Every Minute
        MATCH_MMSS = RTC_MODE2_MASK_SEL_MMSS_Val,                // Every Hour
        MATCH_HHMMSS = RTC_MODE2_MASK_SEL_HHMMSS_Val,            // Every Day
        MATCH_DHHMMSS = RTC_MODE2_MASK_SEL_DDHHMMSS_Val,         // Every Month
        MATCH_MMDDHHMMSS = RTC_MODE2_MASK_SEL_MMDDHHMMSS_Val,    // Every Year
        MATCH_YYMMDDHHMMSS = RTC_MODE2_MASK_SEL_YYMMDDHHMMSS_Val // Once, on a specific date and a specific time
    };

    boolean begin();
    void adjust(const DateTime &dt);
    DateTime now();

private:
    void config32kOSC(void);
    void configureClock(void);
    void RTCreadRequest();
    bool RTCisSyncing(void);
    void RTCdisable();
    void RTCenable();
    void RTCreset();
    void RTCresetRemove();
};
#endif
#endif