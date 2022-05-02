// PostOpndOverloading.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class Point
{
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point& operator++()     // 전위증가 멤버함수
    {
        xpos += 1;
        ypos += 1;
        return *this;
    }
    friend Point& operator--(Point&);       // 전위감소 전역함수
    const Point operator++(int)     // 후위증가 멤버함수
    {
        const Point backup(xpos, ypos);     // 함수 내 복사본 변경 방지, const Point backup(*this); 이렇게 복사생성자 호출해줘도됨
        xpos++;
        ypos++;
        return backup;
    }
    friend const Point operator--(Point&, int);    // 후위감소 전역함수
};

Point& operator--(Point& pos)       // 전위감소 전역함수
{
    pos.xpos -= 1;
    pos.ypos -= 1;
    return pos;
}

const Point operator--(Point& pos, int)     // 후위감소 전역함수
{
    const Point backup(pos.xpos, pos.ypos);         // 함수 내 복사본 변경 방지, const Point backup(pos);
    pos.xpos--;
    pos.ypos--;
    return backup;
}

int main()
{
    Point pos(3, 5);
    Point dest;
    dest = pos--;            // 후위감소 (dest에는 변경 전 저장, pos에는 변경사항 반영)
    dest.ShowPosition();     // [3, 5]
    pos.ShowPosition();     // [2, 4]

    dest = pos++;            // 후위증가 (dest에는 변경 전 저장, pos에는 변경사항 반영)
    dest.ShowPosition();     // [2. 4]
    pos.ShowPosition();     // [3, 5]
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
