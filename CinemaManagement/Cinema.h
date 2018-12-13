#pragma once
#include "MovieManager.h"
#include "BoxOffice.h"

class Cinema
{
public:
	Cinema();
	~Cinema();

	void run(); // 영화관 메인 로직 시작
	
private:
	
	BoxOffice* _boxOfficer;
	
	void stop(); // 영화관 종료

	static int get_operation();
	static void display_menu();
	bool _is_run;
};

