﻿// 7-1-2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyFriendInfo
{
    char* name;
    int age;
public:
    MyFriendInfo(const char* name, int age) : age(age)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    void ShowMyFriendInfo()
    {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }
    ~MyFriendInfo()
    {
        delete[]name;
        cout << "기초 클래스 소멸자 호출" << endl;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
    char* addr;
    char* phone;
public:
    MyFriendDetailInfo(const char* name, int age, const char* addr, const char* phone) : MyFriendInfo(name, age)
    {
        this->addr = new char[strlen(addr) + 1];
        strcpy(this->addr, addr);
        this->phone = new char[strlen(phone) + 1];
        strcpy(this->phone, phone);
    }
    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        cout << "주소: " << addr << endl;
        cout << "전화번호: " << phone << endl << endl;
    }
    ~MyFriendDetailInfo()
    {
        delete[]addr;
        delete[]phone;
        cout << "유도 클래스 소멸자 호출" << endl;
    }
};

int main()
{
    MyFriendDetailInfo choco("Choco", 25, "UiWang", "010-5461-0645");
    MyFriendDetailInfo ponyo("Ponyo", 22, "UiWang", "010-4983-7173");
    choco.ShowMyFriendDetailInfo();
    ponyo.ShowMyFriendDetailInfo();
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
