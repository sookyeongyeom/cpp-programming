#pragma once
#ifndef __REC_H__
#define __REC_H__

#include "Point.h"

class Rectangle
{
	Point upLeft;
	Point lowRight;
public:
	Rectangle(const int& x1, const int& y1, const int& x2, const int& y2);
	void ShowRecInfo() const;
};

#endif