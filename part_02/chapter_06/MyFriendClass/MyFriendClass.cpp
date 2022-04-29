// MyFriendClass.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Girl;     // 13행이 같은 역할을 수행하므로 생략 가능함

class Boy
{
    int height;
    friend class Girl;      // Girl 클래스에 대한 friend 선언, Girl이 클래스 이름임을 알리는 역할도 담당함
public:
    Boy(int len) : height(len) {}
    void ShowYourFriendInfo(Girl& frn);
};

class Girl
{
    char phNum[20];
public:
    Girl(const char* num)
    {
        strcpy(phNum, num);
    }
    void ShowYourFriendInfo(Boy& frn);
    friend class Boy;       // 클래스 내부 아무 곳에나 선언 가능
};

void Boy::ShowYourFriendInfo(Girl& frn)
{
    cout << "Her phone number: " << frn.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy& frn)
{
    cout << "His height: " << frn.height << endl;
}

int main()
{
    Boy boy(175);
    Girl girl("010-5461-0645");
    boy.ShowYourFriendInfo(girl);
    girl.ShowYourFriendInfo(boy);
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
