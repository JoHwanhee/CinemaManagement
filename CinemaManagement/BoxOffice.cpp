#include "BoxOffice.h"
#include <iostream>
#include "CustomerManager.h"
#include <Windows.h>

using namespace std;

BoxOffice::BoxOffice()
{
	_movieManager = new MovieManager();
	_is_run_movie_manage = false;
}

BoxOffice::~BoxOffice()
{

}

void BoxOffice::book_movie()
{
	cout << "\n��ȭ ����\n";
	cout << "\n�� ��ȭ��ȣ ���ڸ�? ";
	int custormer_id = 0;
	cin >> custormer_id;

	cout << "��ȭ ������ȣ : ";
	int movie_id = 0;
	cin >> movie_id;

	if (check_booking(custormer_id))
	{
		cout << custormer_id << "�� ���� �̹� ������ �ֽ��ϴ�. \n";
		return;
	}

	if (_movieManager->search_movie(movie_id))
	{
		_booking_by_userId[custormer_id] = _movieManager->get_movie(movie_id);
		cout << "���� �Ǿ����ϴ�.\n";

		CustomerManager::instance().add_customer_point(custormer_id, _booking_by_userId[custormer_id].get_price() / 100 * 5);
		cout << "����Ʈ+" << _booking_by_userId[custormer_id].get_price() / 100 * 5 << "\n";
		printf("%d �� ���� �ܿ� ����Ʈ�� %.0f�� �Դϴ�.\n", custormer_id, CustomerManager::instance().get_customer_point(custormer_id));
	}
	else
	{
		cout << "�ش��ϴ� ��ȭ�� �����ϴ�.\n";
	}
}

void BoxOffice::check_booking()
{
	cout << "\n��ȭ Ȯ��\n";
	cout << "������ �� ��ȭ��ȣ ���ڸ�? ";
	int custormer_id = 0;
	cin >> custormer_id;

	if (check_booking(custormer_id))
	{
		cout << " ----------------------------------------\n";
		cout << " �� ���� ����.\n\n";
		cout << " ������ȣ" << "\t\t\t����" << "\t\t\t����" << "\t\t\t����ȣ" << "\n";
		_booking_by_userId[custormer_id].print_movie_info_with_id(custormer_id);
		cout << " ----------------------------------------\n";
	}
	else
	{
		cout << "���� ������ �����ϴ�.";
	}
}

bool BoxOffice::check_booking(int id)
{
	map<int, Movie>::iterator it = _booking_by_userId.find(id);
	if (it != _booking_by_userId.end())
	{
		return true;
	}
	return false;
}

void BoxOffice::cancel_booking()
{
	cout << "\n���� ���\n";
	cout << "������ �� ��ȭ��ȣ ���ڸ�? ";
	int custormer_id = 0;
	cin >> custormer_id;

	map<int, Movie>::iterator it = _booking_by_userId.find(custormer_id);
	if (it != _booking_by_userId.end())
	{
		cout << " ----------------------------------------\n";
		cout << " ���� ��ȭ�� ����մϴ�.\n\n";
		cout << " ������ȣ" << "\t\t\t����" << "\t\t\t����" << "\t\t\t����ȣ" << "\n";
		_booking_by_userId[custormer_id].print_movie_info_with_id(custormer_id);

		CustomerManager::instance().add_customer_point(custormer_id, -(_booking_by_userId[custormer_id].get_price() / 100 * 5));
		cout << "����Ʈ-" << _booking_by_userId[custormer_id].get_price() / 100 * 5 << "\n";
		print_customer_info(custormer_id);
		cout << " ----------------------------------------\n";
		_booking_by_userId.erase(it);
	}
	else
	{
		cout << "���� ������ �����ϴ�.\n";
	}
}

void BoxOffice::show_booking_history()
{
	cout << " ----------------------------------------\n";
	cout << " ��ü ���� ����\n";
	cout << " ������ȣ" << "\t\t\t����" << "\t\t\t����" << "\t\t\t����ȣ" << "\n";
	for (const auto& kv : _booking_by_userId) {
		_booking_by_userId[kv.first].print_movie_info_with_id(kv.first);
	}
	cout << " ----------------------------------------\n";
}

// �ܿ� ����Ʈ �˻�
void BoxOffice::check_user_point()
{
	cout << "\n�� ��ȭ��ȣ ���ڸ�? ";
	int custormer_id = 0;
	cin >> custormer_id;

	print_customer_info(custormer_id);
}

// �ܿ� ����Ʈ �˻�
void BoxOffice::print_customer_info(int id)
{
	printf("%d�� ���� �ܿ� ����Ʈ�� %.0f�� �Դϴ�.\n", id, CustomerManager::instance().get_customer_point(id));
}

// util
int BoxOffice::get_operation()
{

	int inputnumber = 0;
	cin >> inputnumber;

	if (cin.fail() || cin.bad() || cin.eof())
	{
		cout << "���ڸ� �Է��ϼ���.\n";
		cin.clear();
		inputnumber = 9;
		cin.ignore(INT32_MAX, '\n');
	}

	return inputnumber;

}

// �������
void BoxOffice::manage_movie()
{
	_is_run_movie_manage = true;

	while (_is_run_movie_manage)
	{
		_movieManager->print_manage_menu();
		cout << "��� ���� : ";
		
		const int operationCode = get_operation();
		switch (operationCode)
		{
		case 1:
			_movieManager->regist_movie();
			break;
		case 2:
			_movieManager->show_movies();
			break;
		case 3:
			_movieManager->get_movie();
			break;
		case 4:
			_movieManager->remove_movie();
			break;
		case 0:
			stop();
			break;
		default:
			printf("�������� �ʴ� ����Դϴ�.");
			break;
		}

		
	}
}

// ������� ��ž
void BoxOffice::stop()
{
	_is_run_movie_manage = false;
}

// ������ɿ��� ������ ��ȭ��� ���� ���� ����Ʈ ����ȭ ��Ű�� �Լ�
void BoxOffice::sync_movie()
{
	list<map<int, Movie>::iterator> removeTargets;
	for (const auto& kv : _booking_by_userId) {
		int user_id = kv.first;
		int movie_id = _booking_by_userId[user_id].get_id();

		if (!_movieManager->search_movie(movie_id))
		{
			map<int, Movie>::iterator it = _booking_by_userId.find(user_id);
			removeTargets.push_front(it);
		}
	}

	if (removeTargets.size() > 0)
	{
		for (const auto remove_target : removeTargets)
		{
			if (remove_target != _booking_by_userId.end())
			{
				_booking_by_userId.erase(remove_target);
			}
		}
	}

	
}

