// PublicStaticMember.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class Simple
{
public:
    static int simCnt;      // public으로 선언함
public:     // 불필요하지만 변수와 함수의 구분을 목적으로 삽입함
    Simple()
    {
        simCnt++;
    }
};
int Simple::simCnt = 0;     // static 멤버변수는 항상 이렇게 초기화함

int main()
{
    cout << Simple::simCnt << "번째 Simple 객체" << endl;       // 객체를 생성하지 않아도 접근 가능
    Simple sim1;
    Simple sim2;

    // 다음 세 문장은 동일한 변수에 접근하여 동일한 출력을 보인다.
    cout << Simple::simCnt << "번째 Simple 객체" << endl;
    cout << sim1.simCnt << "번째 Simple 객체" << endl;      // 이러한 형태의 접근은 멤버변수에 접근하는 것과 같은 오해를 불러일으키므로 지양한다.
    cout << sim2.simCnt << "번째 Simple 객체" << endl;
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
