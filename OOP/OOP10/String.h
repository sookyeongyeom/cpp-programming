#pragma once

#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
using namespace std;

class String
{
    char* str;
public:
    String();
    String(const char* str);
    String(const String& ref);
    String& operator=(const String& ref);
    ~String();
    String operator+(const String& ref);
    String& operator+=(const String& ref);
    bool operator==(const String& ref);
    friend ostream& operator<<(ostream&, const String&);
    friend istream& operator>>(istream&, String&);
};

#endif // !__STRING_H__