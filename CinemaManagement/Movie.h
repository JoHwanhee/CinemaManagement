#pragma once
#include<string>

// ��ȭ ������ ��
class Movie
{
public:
	Movie();
	~Movie();
	Movie(int id, std::string name, float price);

	std::string get_name() const;
	int get_id() const;
	float get_price() const;

	
	void print_movie_info() const; // �ڱ� �ڽ� ���� ���
	void print_movie_info_with_id(int id) const; // �ڱ� �ڽ� ������ ����� id �Բ� ���
	bool operator == (const Movie& s) const { return _id == s._id; } // ��ü �񱳿��� �������̵�, id�� �� ��
	bool operator != (const Movie& s) const { return !operator==(s); }
private:
	int _id;
	std::string _name;
	float _price;
};

