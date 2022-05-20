#include <iostream>
#include "ArrayTemplate.h"
#include "Point.h"
using namespace std;

int main()
{
	// int형 정수 저장
	BoundCheckArray<int> iarr(5);
	for (int i = 0; i < 5; i++)
		iarr[i] = (i + 1) * 11;
	for (int i = 0; i < 5; i++)
		cout << iarr[i] << endl;
	cout << endl;

	// Point 객체 저장
	BoundCheckArray<Point> oarr(3);
	oarr[0] = Point(3, 4);
	oarr[1] = Point(5, 6);
	oarr[2] = Point(7, 8);
	for (int i = 0; i < oarr.GetArrLen(); i++)
		cout << oarr[i];
	cout << endl;

	// Point 객체의 포인터 저장
	typedef Point* POINT_PTR;
	BoundCheckArray<POINT_PTR> parr(2);
	parr[0] = new Point(10, 20);
	parr[1] = new Point(30, 40);
	for (int i = 0; i < parr.GetArrLen(); i++)
		cout << *(parr[i]);

	delete parr[0];
	delete parr[1];
	delete parr[2];
	return 0;
}