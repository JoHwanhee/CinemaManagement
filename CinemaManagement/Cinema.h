#pragma once
#include "MovieManager.h"
#include "BoxOffice.h"

class Cinema
{
public:
	Cinema();
	~Cinema();

	void run(); // ��ȭ�� ���� ���� ����
	
private:
	
	BoxOffice* _boxOfficer;
	
	void stop(); // ��ȭ�� ����

	static int get_operation();
	static void display_menu();
	bool _is_run;
};

