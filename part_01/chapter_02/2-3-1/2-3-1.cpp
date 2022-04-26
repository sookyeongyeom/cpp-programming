// 2-3-1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

typedef struct
{
    int xpos;
    int ypos;
} Point;

Point &PntAdder(const Point &p1, const Point &p2) // 함수의 원형을 보고 매개변수로 전달한 변수의 값이 변경되는지 여부를 판단할 수 있도록 참조자를 통해 변수에 할당된 값이 변경되지 않는 경우 const 키워드를 추가해준다.
{
    Point *sum = new Point;
    sum->xpos = p1.xpos + p2.xpos;
    sum->ypos = p1.ypos + p2.ypos;
    return *sum; // * 연산으로 포인터가 가리키는 변수를 직접 전달
}

int main()
{
    Point *pnt1 = new Point;
    Point *pnt2 = new Point;

    pnt1->xpos = 1, pnt1->ypos = 1;
    pnt2->xpos = 10, pnt2->ypos = 10;

    Point &pref = PntAdder(*pnt1, *pnt2); // * 연산으로 포인터가 가리키는 변수를 직접 전달, 반환값을 참조자형으로 받아주기

    cout << "두 점의 합 = [" << pref.xpos << ", " << pref.ypos << "]" << endl;

    delete pnt1;
    delete pnt2;
    delete &pref; // 참조자 pref가 동적 할당한 포인터 변수 sum을 참조하고 있으므로 delete 해줌
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
