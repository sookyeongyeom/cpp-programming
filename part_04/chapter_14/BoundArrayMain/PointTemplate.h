#pragma once
#ifndef __POINT_T_H__
#define __POINT_T_H__

template <class T>
class Point
{
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0);
	void ShowPosition() const;
};

template <class T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y) {}

template <class T>
void Point<T>::ShowPosition() const
{
	cout << '[' << xpos << ", " << ypos << ']' << endl;
}

#endif // !__POINT_T_H__
