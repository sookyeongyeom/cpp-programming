// 11-1-1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class Gun
{
    int bullet;     // 장전된 총알의 수
public:
    Gun(int bnum) : bullet(bnum) {}
    void Shot()
    {
        cout << "BBANG!" << endl;
        bullet--;
    }
};

class Police
{
    int handcuffs;      // 소유한 수갑의 수
    Gun* pistol;        // 소유하고 있는 권총
public:
    Police(int bnum, int bcuff) : handcuffs(bcuff)
    {
        cout << "생성자 호출" << endl;
        if (bnum > 0)
            pistol = new Gun(bnum);
        else
            pistol = NULL;
    }
    Police(const Police& src) : handcuffs(src.handcuffs)
    {
        cout << "복사 생성자 호출" << endl;
        if (src.pistol != NULL)
            pistol = new Gun(*(src.pistol));      // Gun의 디폴트 복사 생성자 호출
        else
            pistol = NULL;
    }
    Police& operator=(const Police& src)        // 대입 연산자 정의
    {
        cout << "대입 연산자 호출" << endl;
        if (pistol != NULL)
            delete pistol;      // 메모리 누수 방지 (기존 힙 해제)
        
        if (src.pistol != NULL)
            pistol = new Gun(*(src.pistol));
        else
            pistol = NULL;

        handcuffs = src.handcuffs;      // 생성자 아니므로 이니셜라이저로 초기화 불가
        return *this;
    }
    void PutHandcuff()
    {
        cout << "SNAP!" << endl;
        handcuffs--;
    }
    void Shot()
    {
        if (!pistol)
            cout << "~No Gun~" << endl;
        else
            pistol->Shot();
    }
    ~Police()
    {
        cout << "destructor called!" << endl;
        if (pistol)
            delete pistol;
    }
};

int main()
{
    Police plc1(5, 10);
    Police plc2 = plc1;     // 복사 생성자 호출
    plc1.PutHandcuff();
    plc2.Shot();

    Police plc3(100, 200);
    plc3 = plc1;            // 대입 연산자 호출
    plc3.PutHandcuff();
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
