// 4-3-2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

namespace COMP_POS
{
    enum { CLERK, SENIOR, ASSIST, MANAGER };

    void ShowPositionInfo(int pos)      // enum-label 간 변환도 동일한 네임스페이스에서 정의함
    {
        switch (pos)
        {
        case CLERK:
            cout << "사원";
            break;
        case SENIOR:
            cout << "주임";
            break;
        case ASSIST:
            cout << "대리";
            break;
        case MANAGER:
            cout << "과장";
            break;
        }
    }
}

class NameCard
{
private:
    char* name;
    char* comp;
    char* phone;
    int pos;
public:
    NameCard(const char* myname, const char* mycomp, const char* myphone, int mypos)
        : pos(mypos)
    {
        name = new char[strlen(myname) + 1];
        strcpy(name, myname);
        comp = new char[strlen(mycomp) + 1];
        strcpy(comp, mycomp);
        phone = new char[strlen(myphone) + 1];
        strcpy(phone, myphone);
    }
    void ShowNameCardInfo()
    {
        cout << "이름: " << name << endl;
        cout << "회사: " << comp << endl;
        cout << "전화번호: " << phone << endl;
        cout << "직업: ", COMP_POS::ShowPositionInfo(pos), cout << endl << endl;
    }
    ~NameCard()
    {
        delete[]name;
        delete[]comp;
        delete[]phone;
    }
};

int main()
{
    NameCard manClerk("Choco", "YeomComp", "010-5461-0645", COMP_POS::CLERK);
    NameCard manSenior("Ponyo", "AppleComp", "010-4983-7173", COMP_POS::SENIOR);
    NameCard manAssist("Gom", "ParkComp", "010-7561-0645", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSenior.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
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
