// BoundArrayMain.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "ArrayTemplate.h"
#include "PointTemplate.h"
using namespace std;

int main()
{
	BoundCheckArray<Point<int>> oarr1(3);
	oarr1[0] = Point<int>(3, 4);
	oarr1[1] = Point<int>(5, 6);
	oarr1[2] = Point<int>(7, 8);

	for (int i = 0; i < oarr1.GetArrLen(); i++)
		oarr1[i].ShowPosition();

	BoundCheckArray<Point<double>> oarr2(3);
	oarr2[0] = Point<double>(3.14, 4.31);
	oarr2[1] = Point<double>(5.09, 6.07);
	oarr2[2] = Point<double>(7.82, 8.54);

	for (int i = 0; i < oarr2.GetArrLen(); i++)
		oarr2[i].ShowPosition();

	typedef Point<int>* POINT_PTR;
	BoundCheckArray<POINT_PTR> oparr(3);
	oparr[0] = new Point<int>(11, 22);
	oparr[1] = new Point<int>(33, 44);
	oparr[2] = new Point<int>(55, 66);

	for (int i = 0; i < oparr.GetArrLen(); i++)
		oparr[i]->ShowPosition();

	delete oparr[0], oparr[1], oparr[2];
	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
