#pragma once
#include<string>

// 영화 데이터 모델
class Movie
{
public:
	Movie();
	~Movie();
	Movie(int id, std::string name, float price);

	std::string get_name() const;
	int get_id() const;
	float get_price() const;

	
	void print_movie_info() const; // 자기 자신 정보 출력
	void print_movie_info_with_id(int id) const; // 자기 자신 정보와 사용자 id 함께 출력
	bool operator == (const Movie& s) const { return _id == s._id; } // 객체 비교연산 오버라이딩, id로 비교 함
	bool operator != (const Movie& s) const { return !operator==(s); }
private:
	int _id;
	std::string _name;
	float _price;
};

