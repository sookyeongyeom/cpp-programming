// UsefulThisPtr.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class TwoNumber
{
private:
    int num1;
    int num2;
public:
    TwoNumber(int num1, int num2)       // 매개변수의 이름이 멤버변수의 이름과 동일하게 선언된 경우, 해당 함수내에서는 멤버변수가 가려지게 된다.
    {
        this->num1 = num1;      // this 포인터를 사용하면 매개변수에 의해 가려진 상황에서도 멤버변수에 접근할 수 있다.
        this->num2 = num2;
    }
    //TwoNumber(int num1, int num2) : num1(num1), num2(num2) {}   // 이니셜라이저에서는 this를 사용할 수 없으나, 틀은 멤버변수로, 값은 매개변수로 인식하므로 이와 같은 문장 구성이 가능하다.
    void ShowTwoNumber()
    {
        cout << this->num1 << endl;
        cout << num2 << endl;
    }
};

int main()
{
    TwoNumber two(2, 4);
    two.ShowTwoNumber();
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
