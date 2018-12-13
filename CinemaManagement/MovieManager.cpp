#include "MovieManager.h"
#include <iostream>

using namespace std;

MovieManager::MovieManager()
{
}

MovieManager::~MovieManager()
{
}

void MovieManager::regist_movie()
{
	cout << "영화 고유번호 ? ";
	int movie_id = 0;
	cin >> movie_id;
	getchar();

	cout << "영화 이름 ? ";
	char tmp[101];
	cin.getline(tmp, 100, '\n');
	const string movie_name = tmp;

	cout << "영화 가격 ? ";
	float movie_price = 0;
	cin >> movie_price;

	Movie movie = Movie(movie_id, movie_name, movie_price);
	if (!search_movie(movie_id))
	{
		_movies.push_front(movie);
	}
	else
	{
		cout << " ----------------------------------------\n";
		cout << " 다음 영화는 이미 등록되어 있습니다.\n\n";
		cout << " 고유번호" << "\t\t\t제목" << "\t\t\t가격" << "\n";
		movie.print_movie_info();
		cout << " ----------------------------------------\n\n";
	}
}

void MovieManager::show_movies()
{
	cout << " ----------------------------------------\n";
	cout << " 다음 영화들이 등록되어 있습니다.\n\n";
	cout << " 고유번호" << "\t\t\t제목" << "\t\t\t가격" << "\n";
	for (Movie movie : _movies)
	{
		movie.print_movie_info();
	}
	cout << " ----------------------------------------\n\n";
}

bool MovieManager::search_movie(int id)
{
	for (Movie movie : _movies)
	{
		if (movie.get_id() == id)
		{
			return true;
		}
	}

	return false;
}

void MovieManager::get_movie()
{
	cout << "영화 고유번호 : ";
	int movie_id = 0;
	cin >> movie_id;

	Movie movie = get_movie(movie_id);

	cout << " ----------------------------------------\n";
	cout << " 검색 결과.\n\n";
	cout << " 고유번호" << "\t\t\t제목" << "\t\t\t가격 : " << "\n";
	movie.print_movie_info();
	cout << " ----------------------------------------\n\n";
}

Movie MovieManager::get_movie(int id)
{
	for (Movie movie : _movies)
	{
		if (movie.get_id() == id)
		{
			return movie;
		}
	}

	Movie movie;
	return movie;
}

void MovieManager::remove_movie()
{
	cout << "영화 고유번호 : ";
	int movie_id = 0;
	cin >> movie_id;

	if (search_movie(movie_id))
	{
		_movies.remove(get_movie(movie_id));
	}
	else
	{
		cout << "해당하는 영화는 없습니다. 관리 메뉴에서 추가 해주세요. \n\n";
	}
}

void MovieManager::print_manage_menu()
{
	cout << "\n *** 영화 관리 기능 *** \n";
	cout << "1. 영화 등록 \n";
	cout << "2. 영화 목록 \n";
	cout << "3. 영화 검색 \n";
	cout << "4. 영화 삭제 \n";
	cout << "0. 돌아가기 \n\n";
}
