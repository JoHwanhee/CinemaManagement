#include <iostream>
#include "Cinema.h"

using namespace std;

int main(int argc, char* args)
{
	cout << "영화관 관리 프로그램을 시작합니다.";

	Cinema cinema;
	cinema.run();

	cout << "영화관 관리 프로그램이 종료 되었습니다. 아무키나 누르세요.";
	getchar();
	getc(stdin);

	return 0;
}
