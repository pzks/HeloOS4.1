#include "../stdlib.h"
#include "../apilib.h"

#define MAXLEN 128

void HariMain(void)
{
	char *days[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
	int second = api_rtc(RTC_SECOND);
	int minute = api_rtc(RTC_MINUTE);
	int hour = api_rtc(RTC_HOURS);
	int weekday = api_rtc(RTC_WEEKDAY);
	int day = api_rtc(RTC_DAY_OF_MONTH);
	int month = api_rtc(RTC_MONTH);
	int year = api_rtc(RTC_YEAR);
	int century = api_rtc(RTC_CENTURY);
	printf("%d-%d-%d %s %d:%02d:%02d\n", century*100+year, month, day, days[weekday], hour, minute, second);
	exit(0);
}