
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "../OOP9/String.h"
using namespace std;

String::String()
{
    str = NULL;
}

String::String(const char* str)         // 생성자
{
    this->str = new char[strlen(str) + 1];
    strcpy(this->str, str);
}

String::String(const String& ref)       // 복사생성자
{
    str = new char[strlen(ref.str) + 1];
    strcpy(str, ref.str);
}

String& String::operator=(const String& ref)        // 대입연산자
{
    delete[]str;
    str = new char[strlen(ref.str) + 1];
    strcpy(str, ref.str);
    return *this;
}

String::~String()       // 소멸자
{
    if (str != NULL)
        delete[]str;
}

String String::operator+(const String& ref)
{
    char* newStr = new char[strlen(str) + strlen(ref.str) + 1];
    strcpy(newStr, str);        // NULL 상태에서는 strcpy부터 해주어야 함
    strcat(newStr, ref.str);
    String temp(newStr);
    delete[]newStr;
    return temp;
}

String& String::operator+=(const String& ref)
{
    char* newStr = new char[strlen(str) + strlen(ref.str) + 1];
    strcpy(newStr, str);
    strcat(newStr, ref.str);
    if (str != NULL)
        delete[]str;
    str = newStr;
    return *this;
}

bool String::operator==(const String& ref)
{
    if (!strcmp(str, ref.str))
        return true;
    else
        return false;
}

ostream& operator<<(ostream& os, const String& ref)
{
    os << ref.str;
    return os;
}

istream& operator>>(istream& is, String& ref)
{
    char str[100];
    is >> str;
    ref = String(str);
    return is;
}