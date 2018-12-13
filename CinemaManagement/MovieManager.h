#pragma once
#include <list>
#include "Movie.h"

class MovieManager
{
public:
	MovieManager();
	~MovieManager();

	void regist_movie(); // 영화 등록
	void show_movies(); // 예약된 영화 목록 보여주기
	bool search_movie(int id); // 영화 검색
	Movie get_movie(int id); //
	void get_movie();
	void remove_movie();

	static void print_manage_menu();
private:
	std::list<Movie> _movies;
};