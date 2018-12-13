#include "DatetimeExtension.h"
#include <windows.h>

DatetimeExtension::DatetimeExtension()
{
}


DatetimeExtension::~DatetimeExtension()
{
}

WORD DatetimeExtension::GetDayOfMonth(SYSTEMTIME *st)
{
	WORD dayofweek;
	WORD day;

	dayofweek = st->wDayOfWeek;
	day = st->wDay;
	while (day > 1)
	{
		day--;
		if (dayofweek == 0)
		{
			dayofweek = 6;
		}
		else
		{
			dayofweek--;
		}
	}
	return dayofweek;
}

WORD DatetimeExtension::GetWeekOfMonth(SYSTEMTIME  *st)
{
	WORD firstSunday_day; //매월 첫째주 일요일의 날짜 
	WORD first_dayofweek;
	WORD week;
	WORD day;
	WORD dayofweek;

	//----------------------- 
	//이번달 1일의 요일을 구한다. 
	first_dayofweek = GetDayOfMonth(st);
	//------------------------ 
	//매월 첫번째 일요일의 날짜 구하기 
	firstSunday_day = 1;
	dayofweek = first_dayofweek;
	while (dayofweek != 0)
	{
		firstSunday_day++;
		if (dayofweek == 6)
		{
			dayofweek = 0;
		}
		else
		{
			dayofweek++;
		}
	}
	//------------------------ 
	//오늘이 몇번째 주인지 판단 
	week = 1;
	day = firstSunday_day;
	while (day < st->wDay)
	{
		day += 7;
		week++;
	}
	return week;
}

