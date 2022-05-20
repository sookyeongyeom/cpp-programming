#pragma once
#ifndef __POINT_T_H__
#define __POINT_T_H__

template <typename T>
class Point
{
    T xpos, ypos;
public:
    Point(T x = 0, T y = 0);
    void ShowPosition() const;
};

#endif // !__POINT_T_H__
