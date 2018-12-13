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
			cout << "�������� �ʴ� ����Դϴ�.\n\n";
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
	cout << "��� ���� : ";
	int inputnumber = 0;
	cin >> inputnumber;

	if (cin.fail() || cin.bad() || cin.eof())
	{
		cout << "���ڸ� �Է��ϼ���.\n";
		cin.clear();
		cin.ignore(INT32_MAX, '\n');
		inputnumber = 9;
	}

	return inputnumber;
}

void Cinema::display_menu()
{
	cout << "\n*** ��ȭ ���� ���α׷� *** \n";
	cout << "1. ��ȭ ���� \n";
	cout << "2. ���� Ȯ�� \n";
	cout << "3. ���� ��� \n";
	cout << "4. ���� ���� \n";
	cout << "5. ���� ����Ʈ Ȯ�� \n";
	cout << "6. ������� \n";
	cout << "0. �����ϱ� \n\n";
}
