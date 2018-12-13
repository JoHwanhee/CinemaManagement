#include "Movie.h"
#include <iostream>
#include "DatetimeExtension.h"

using namespace std;

Movie::Movie()
{
	_id = 0;
	_name = "";
	_price = 0.0;
}

Movie::~Movie()
{
}

Movie::Movie(const int id, const string name, const float price)
{
	_id = id;
	_name = name;
	_price = price;
}

string Movie::get_name() const
{
	return _name;
}

int Movie::get_id() const
{
	return _id;
}

float Movie::get_price() const
{
	DatetimeExtension datetime_extension;
	SYSTEMTIME st;
	GetSystemTime(&st);
	WORD week = datetime_extension.GetWeekOfMonth(&st);
	WORD day = st.wDayOfWeek;

	// 넷째주 목요일
	if(week == 4 && day == 4)
	{
		return _price / 2;
	}

	return _price;
}

void Movie::print_movie_info() const
{
	cout << " " << _id << "\t\t\t" << _name << "\t\t\t" << _price << "\n";
}

void Movie::print_movie_info_with_id(int id) const
{
	cout << " " << _id << "\t\t\t" << _name << "\t\t\t" << _price << "\t\t\t" << id << "\n";
}