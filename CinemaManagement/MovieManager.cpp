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
	cout << "��ȭ ������ȣ ? ";
	int movie_id = 0;
	cin >> movie_id;
	getchar();

	cout << "��ȭ �̸� ? ";
	char tmp[101];
	cin.getline(tmp, 100, '\n');
	const string movie_name = tmp;

	cout << "��ȭ ���� ? ";
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
		cout << " ���� ��ȭ�� �̹� ��ϵǾ� �ֽ��ϴ�.\n\n";
		cout << " ������ȣ" << "\t\t\t����" << "\t\t\t����" << "\n";
		movie.print_movie_info();
		cout << " ----------------------------------------\n\n";
	}
}

void MovieManager::show_movies()
{
	cout << " ----------------------------------------\n";
	cout << " ���� ��ȭ���� ��ϵǾ� �ֽ��ϴ�.\n\n";
	cout << " ������ȣ" << "\t\t\t����" << "\t\t\t����" << "\n";
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
	cout << "��ȭ ������ȣ : ";
	int movie_id = 0;
	cin >> movie_id;

	Movie movie = get_movie(movie_id);

	cout << " ----------------------------------------\n";
	cout << " �˻� ���.\n\n";
	cout << " ������ȣ" << "\t\t\t����" << "\t\t\t���� : " << "\n";
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
	cout << "��ȭ ������ȣ : ";
	int movie_id = 0;
	cin >> movie_id;

	if (search_movie(movie_id))
	{
		_movies.remove(get_movie(movie_id));
	}
	else
	{
		cout << "�ش��ϴ� ��ȭ�� �����ϴ�. ���� �޴����� �߰� ���ּ���. \n\n";
	}
}

void MovieManager::print_manage_menu()
{
	cout << "\n *** ��ȭ ���� ��� *** \n";
	cout << "1. ��ȭ ��� \n";
	cout << "2. ��ȭ ��� \n";
	cout << "3. ��ȭ �˻� \n";
	cout << "4. ��ȭ ���� \n";
	cout << "0. ���ư��� \n\n";
}
