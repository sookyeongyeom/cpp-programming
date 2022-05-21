#pragma once
#ifndef __BOUND_T_H__
#define __BOUND_T_H__

#include "String.h"

template <class T>
class BoundCheckArray
{
    T* arr;
    int arrlen;
    BoundCheckArray(const BoundCheckArray&) {}
    BoundCheckArray& operator=(const BoundCheckArray&) {}
public:
    BoundCheckArray(int len = 100);
    T& operator[](int);
    T operator[](int) const;
    int GetArrLen() const;
    ~BoundCheckArray();
};

template <class T>
BoundCheckArray<T>::BoundCheckArray(int len) : arrlen(len)
{
    arr = new T[len];
}

template <class T>
T& BoundCheckArray<T>::operator[](int idx)
{
    if (idx < 0 || idx >= arrlen)
    {
        cout << "Array index out of bound exception" << endl;
        exit(1);
    }
    return arr[idx];
}

template <class T>
T BoundCheckArray<T>::operator[](int idx) const
{
    if (idx < 0 || idx >= arrlen)
    {
        cout << "Array index out of bound exception" << endl;
        exit(1);
    }
    return arr[idx];
}

template <class T>
int BoundCheckArray<T>::GetArrLen() const
{
    return arrlen;
}

template <class T>
BoundCheckArray<T>::~BoundCheckArray()
{
    delete[]arr;
}

#endif // !__BOUND_T_H__