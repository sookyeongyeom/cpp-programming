// StablePointPtrArray.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class Point
{
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
    os << "[" << pos.xpos << ", " << pos.ypos << "]" << endl;
    return os;
}

typedef Point* POINT_PTR;

class BoundCheckPointPtrArray
{
    POINT_PTR* arr;
    int arrlen;
    BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) {}
    BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& arr) {}
public:
    BoundCheckPointPtrArray(int len) : arrlen(len)
    {
        arr = new POINT_PTR[len];
    }
    POINT_PTR& operator[](int idx)
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }
    POINT_PTR& operator[](int idx) const
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }
    int GetArrLen() const { return arrlen; }
    ~BoundCheckPointPtrArray()
    {
        delete[]arr;
    }
};

int main()
{
    BoundCheckPointPtrArray arr(3);
    arr[0] = new Point(3, 4);       // 동적할당한 Point 객체의 주소값을 저장하므로 얕은/깊은 복사 문제를 신경쓰지 않아도 된다.
    arr[1] = new Point(5, 6);
    arr[2] = new Point(7, 8);

    for (int i = 0; i < arr.GetArrLen(); i++)
        cout << *arr[i];

    delete arr[0];
    delete arr[1];
    delete arr[2];
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
