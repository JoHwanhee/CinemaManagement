#include "Cinema.h"
#include <iostream>

using namespace std;

Cinema::Cinema()
{
	_boxOfficer = new BoxOffice();
	_is_run = true;
}

Cinema::~Cinema()
{
}

void Cinema::run()
{
	while (_is_run)
	{
		display_menu();
		_boxOfficer->sync_movie();

		const int operationCode = get_operation();
		switch (operationCode)
		{
		case 1:
			_boxOfficer->book_movie();
			break;
		case 2:
			_boxOfficer->check_booking();
			break;
		case 3:
			_boxOfficer->cancel_booking();
			break;
		case 4:
			_boxOfficer->show_booking_history();
			break;
		case 5:
			_boxOfficer->check_user_point();
			break;
		case 6:
			_boxOfficer->manage_movie();
			break;
		case 0:
			stop();
			break;
		default:
			cout << "지원하지 않는 기능입니다.\n\n";
			break;
		}
	}
}

void Cinema::stop()
{
	_is_run = false;
}

int Cinema::get_operation()
{
	cout << "기능 선택 : ";
	int inputnumber = 0;
	cin >> inputnumber;

	if (cin.fail() || cin.bad() || cin.eof())
	{
		cout << "숫자만 입력하세요.\n";
		cin.clear();
		cin.ignore(INT32_MAX, '\n');
		inputnumber = 9;
	}

	return inputnumber;
}

void Cinema::display_menu()
{
	cout << "\n*** 영화 예매 프로그램 *** \n";
	cout << "1. 영화 예매 \n";
	cout << "2. 예매 확인 \n";
	cout << "3. 예매 취소 \n";
	cout << "4. 예매 내역 \n";
	cout << "5. 누적 포인트 확인 \n";
	cout << "6. 관리기능 \n";
	cout << "0. 종료하기 \n\n";
}
