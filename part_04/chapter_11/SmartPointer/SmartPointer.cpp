// SmartPointer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class Point
{
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    {
        cout << "Point 객체 생성" << endl;
    }
    ~Point()
    {
        cout << "Point 객체 소멸" << endl;
    }
    void SetPos(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
    friend ostream& operator<<(ostream&, const Point&);
};

ostream& operator<<(ostream& os, const Point& pos)
{
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}

class Smartptr
{
    Point* posptr;
public:
    Smartptr(Point* ptr) : posptr(ptr) {}

    Point& operator*() const
    {
        return *posptr;             // posptr의 참조값 반환
    }
    Point* operator->() const
    {
        return posptr;              // posptr의 주소값 반환
    }
    ~Smartptr()
    {
        delete posptr;              // 생성자의 인자로 전달되는 주소값이 동적할당된 객체의 주소값일 것이라는 가정이 깔려있음
    }
};

int main()
{
    Smartptr sptr1(new Point(1, 2));
    Smartptr sptr2(new Point(3, 4));
    Smartptr sptr3(new Point(5, 6));
    cout << *sptr1;
    cout << *sptr2;
    cout << *sptr3;

    sptr1->SetPos(10, 20);
    sptr2->SetPos(30, 40);
    sptr3->SetPos(50, 60);
    cout << *sptr1;
    cout << *sptr2;
    cout << *sptr3;
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
