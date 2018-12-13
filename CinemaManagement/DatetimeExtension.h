#pragma once
#include <windows.h>

class DatetimeExtension
{
public:
	DatetimeExtension();
	~DatetimeExtension();
	WORD GetDayOfMonth();

	static WORD GetDayOfMonth(SYSTEMTIME *st);
	static WORD GetWeekOfMonth(SYSTEMTIME  *st);
};

