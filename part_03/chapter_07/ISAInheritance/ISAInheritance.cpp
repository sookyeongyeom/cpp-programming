// ISAInheritance.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Computer
{
    char owner[50];
public:
    Computer(const char* name)
    {
        strcpy(owner, name);
    }
    void Calculate()
    {
        cout << "요청 내용을 계산합니다." << endl;
    }
};

class NotebookComp : public Computer
{
    int Battery;
public:
    NotebookComp(const char* name, int initChag) : Computer(name), Battery(initChag) {}
    void Charging() { Battery += 5; }
    void UseBattery() { Battery -= 1; }
    void MovingCal()
    {
        if (GetBatteryInfo() < 1)
        {
            cout << "충전이 필요합니다." << endl;
            return;
        }
        cout << "이동하면서 ";
        Calculate();
        UseBattery();
    }
    int GetBatteryInfo() { return Battery; }
};

class TabletNotebook : public NotebookComp
{
    char regstPenModel[50];
public:
    TabletNotebook(const char* name, int initChag, const char* pen) : NotebookComp(name, initChag)
    {
        strcpy(regstPenModel, pen);
    }
    void Write(const char* penInfo)
    {
        if (GetBatteryInfo() < 1)
        {
            cout << "충전이 필요합니다." << endl;
            return;
        }
        if (strcmp(regstPenModel, penInfo))
        {
            cout << "등록된 펜이 아닙니다.";
            return;
        }
        cout << "필기 내용을 처리합니다." << endl;
        UseBattery();
    }
};

int main()
{
    NotebookComp nc("Choco", 10);
    TabletNotebook tn("Ponyo", 10, "PONYO-PEN-1117");
    nc.MovingCal();
    tn.Write("PONYO-PEN-1117");
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
