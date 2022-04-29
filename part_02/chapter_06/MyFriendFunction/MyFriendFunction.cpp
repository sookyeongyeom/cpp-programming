// MyFriendFunction.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class Point;        // Point가 클래스의 이름임을 선언

class PointOP
{
    int opcnt;
public:
    PointOP() : opcnt(0) {}
    Point PointAdd(const Point&, const Point&);     // 선언부와 정의부를 분리할 시 선언부의 매개변수 이름은 생략해도 됨
    Point PointSub(const Point&, const Point&);
    ~PointOP()
    {
        cout << "Operation times: " << opcnt << endl;
    }
};

class Point
{
    int x;
    int y;
public:
    Point(const int& xpos, const int& ypos) : x(xpos), y(ypos) {}
    friend Point PointOP::PointAdd(const Point&, const Point&);     // PointOP 클래스의 PointAdd 함수에 멤버변수에 대한 접근권한 부여
    friend Point PointOP::PointSub(const Point&, const Point&);     // PointOP 클래스의 PointSub 함수에 멤버변수에 대한 접근권한 부여
    friend void ShowPointPos(const Point&);     // ShowPointPos 함수에 멤버변수에 대한 접근권한 부여, 함수 원형 선언
};

Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2)       // friend로 선언되어 Point 클래스의 private 변수에 접근 가능
{
    opcnt++;
    return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);     // 덧셈한 정보로 새로운 객체 생성하여 반환
}

Point PointOP::PointSub(const Point& pnt1, const Point& pnt2)       // friend로 선언되어 Point 클래스의 private 변수에 접근 가능
{
    opcnt++;
    return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);     // 뺄셈한 정보로 새로운 객체 생성하여 반환
}

void ShowPointPos(const Point& pos)     // friend로 선언되어 Point 클래스의 private 변수에 접근 가능
{
    cout << "x: " << pos.x << ", " << "y: " << pos.y << endl;
}

int main()
{
    Point pos1(1, 2);
    Point pos2(2, 4);
    PointOP op;

    ShowPointPos(op.PointAdd(pos1, pos2));
    ShowPointPos(op.PointSub(pos2, pos1));
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
