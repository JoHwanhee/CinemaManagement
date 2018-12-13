#pragma once
#include "Movie.h"
#include <list>
#include <map>
#include "MovieManager.h"

class BoxOffice
{
public:
	BoxOffice();
	~BoxOffice();
	void book_movie();

	void check_booking(); // ���� Ȯ��
	bool check_booking(int id);
	void cancel_booking(); // ���� ���
	void show_booking_history(); // ���� ����
	static void check_user_point(); // ���� ����Ʈ Ȯ��
	static void print_customer_info(int id);
	static int get_operation();
	void stop();
	void sync_movie();
	void manage_movie();

private:
	std::map<int, Movie> _booking_by_userId;
	MovieManager* _movieManager;
	bool _is_run_movie_manage;
};

