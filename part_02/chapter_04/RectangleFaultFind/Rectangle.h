#pragma once
#ifndef __REC_H__
#define __REC_H__

#include "Point.h"

class Rectangle
{
	Point upLeft;
	Point lowRight;
public:
	bool InitMembers(const Point& ul, const Point& lr);
	void ShowRecInfo() const;
};

#endif