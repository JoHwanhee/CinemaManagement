#pragma once
#include <list>
#include "Movie.h"

class MovieManager
{
public:
	MovieManager();
	~MovieManager();

	void regist_movie(); // ��ȭ ���
	void show_movies(); // ����� ��ȭ ��� �����ֱ�
	bool search_movie(int id); // ��ȭ �˻�
	Movie get_movie(int id); //
	void get_movie();
	void remove_movie();

	static void print_manage_menu();
private:
	std::list<Movie> _movies;
};