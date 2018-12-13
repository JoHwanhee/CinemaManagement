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
	cout << "\n영화 예매\n";
	cout << "\n고객 전화번호 뒷자리? ";
	int custormer_id = 0;
	cin >> custormer_id;

	cout << "영화 고유번호 : ";
	int movie_id = 0;
	cin >> movie_id;

	if (check_booking(custormer_id))
	{
		cout << custormer_id << "번 고객은 이미 예약이 있습니다. \n";
		return;
	}

	if (_movieManager->search_movie(movie_id))
	{
		_booking_by_userId[custormer_id] = _movieManager->get_movie(movie_id);
		cout << "예매 되었습니다.\n";

		CustomerManager::instance().add_customer_point(custormer_id, _booking_by_userId[custormer_id].get_price() / 100 * 5);
		cout << "포인트+" << _booking_by_userId[custormer_id].get_price() / 100 * 5 << "\n";
		printf("%d 번 고객의 잔여 포인트는 %.0f원 입니다.\n", custormer_id, CustomerManager::instance().get_customer_point(custormer_id));
	}
	else
	{
		cout << "해당하는 영화는 없습니다.\n";
	}
}

void BoxOffice::check_booking()
{
	cout << "\n영화 확인\n";
	cout << "예약한 고객 전화번호 뒷자리? ";
	int custormer_id = 0;
	cin >> custormer_id;

	if (check_booking(custormer_id))
	{
		cout << " ----------------------------------------\n";
		cout << " 고객 예약 정보.\n\n";
		cout << " 고유번호" << "\t\t\t제목" << "\t\t\t가격" << "\t\t\t고객번호" << "\n";
		_booking_by_userId[custormer_id].print_movie_info_with_id(custormer_id);
		cout << " ----------------------------------------\n";
	}
	else
	{
		cout << "예약 내역이 없습니다.";
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
	cout << "\n예매 취소\n";
	cout << "예약한 고객 전화번호 뒷자리? ";
	int custormer_id = 0;
	cin >> custormer_id;

	map<int, Movie>::iterator it = _booking_by_userId.find(custormer_id);
	if (it != _booking_by_userId.end())
	{
		cout << " ----------------------------------------\n";
		cout << " 다음 영화를 취소합니다.\n\n";
		cout << " 고유번호" << "\t\t\t제목" << "\t\t\t가격" << "\t\t\t고객번호" << "\n";
		_booking_by_userId[custormer_id].print_movie_info_with_id(custormer_id);

		CustomerManager::instance().add_customer_point(custormer_id, -(_booking_by_userId[custormer_id].get_price() / 100 * 5));
		cout << "포인트-" << _booking_by_userId[custormer_id].get_price() / 100 * 5 << "\n";
		print_customer_info(custormer_id);
		cout << " ----------------------------------------\n";
		_booking_by_userId.erase(it);
	}
	else
	{
		cout << "예약 내역이 없습니다.\n";
	}
}

void BoxOffice::show_booking_history()
{
	cout << " ----------------------------------------\n";
	cout << " 전체 예약 내역\n";
	cout << " 고유번호" << "\t\t\t제목" << "\t\t\t가격" << "\t\t\t고객번호" << "\n";
	for (const auto& kv : _booking_by_userId) {
		_booking_by_userId[kv.first].print_movie_info_with_id(kv.first);
	}
	cout << " ----------------------------------------\n";
}

// 잔여 포인트 검색
void BoxOffice::check_user_point()
{
	cout << "\n고객 전화번호 뒷자리? ";
	int custormer_id = 0;
	cin >> custormer_id;

	print_customer_info(custormer_id);
}

// 잔여 포인트 검색
void BoxOffice::print_customer_info(int id)
{
	printf("%d번 고객의 잔여 포인트는 %.0f원 입니다.\n", id, CustomerManager::instance().get_customer_point(id));
}

// util
int BoxOffice::get_operation()
{

	int inputnumber = 0;
	cin >> inputnumber;

	if (cin.fail() || cin.bad() || cin.eof())
	{
		cout << "숫자만 입력하세요.\n";
		cin.clear();
		inputnumber = 9;
		cin.ignore(INT32_MAX, '\n');
	}

	return inputnumber;

}

// 관리기능
void BoxOffice::manage_movie()
{
	_is_run_movie_manage = true;

	while (_is_run_movie_manage)
	{
		_movieManager->print_manage_menu();
		cout << "기능 선택 : ";
		
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
			printf("지원하지 않는 기능입니다.");
			break;
		}

		
	}
}

// 관리기능 스탑
void BoxOffice::stop()
{
	_is_run_movie_manage = false;
}

// 관리기능에서 삭제된 영화들과 현재 예매 리스트 동기화 시키는 함수
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

