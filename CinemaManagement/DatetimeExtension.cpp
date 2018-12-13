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
	WORD firstSunday_day; //�ſ� ù°�� �Ͽ����� ��¥ 
	WORD first_dayofweek;
	WORD week;
	WORD day;
	WORD dayofweek;

	//----------------------- 
	//�̹��� 1���� ������ ���Ѵ�. 
	first_dayofweek = GetDayOfMonth(st);
	//------------------------ 
	//�ſ� ù��° �Ͽ����� ��¥ ���ϱ� 
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
	//������ ���° ������ �Ǵ� 
	week = 1;
	day = firstSunday_day;
	while (day < st->wDay)
	{
		day += 7;
		week++;
	}
	return week;
}

