// ObjArr.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person
{
private:
    char* name;
    int age;
public:
    Person(const char* myname, int myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];       // 불필요한 메모리 공간의 낭비 또는 부족을 막기 위해 문자열의 길이만큼 메모리 공간을 동적 할당함
        strcpy(name, myname);
        age = myage;
    }
    Person()
    {
        name = NULL;
        age = 0;
        cout << "Person() called!" << endl;
    }
    void SetPersonInfo(char* myname, int myage)
    {
        name = myname;
        age = myage;
    }
    void ShowPersonInfo() const
    {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }
    ~Person()
    {
        delete[]name;       // 생성자에서 할당한 메모리 공간을 소멸시킴
        cout << "destructor called!" << endl;
    }
};

int main()
{
    Person parr[3];     // Person 객체를 여러개 담은 배열
    char namestr[100];      // 이름을 받을 임시 바구니
    char* strptr;       // 필요한 만큼의 공간을 동적 할당해서 임시 바구니에 받아둔 이름을 복사한 후 매개변수로 넘겨줄 포인터 변수
    int age;

    for (int i = 0; i < 3; i++)
    {
        cout << "이름: ", cin >> namestr;     // 일단 바구니에 받음
        cout << "나이: ", cin >> age;
        strptr = new char[strlen(namestr) + 1];     // 필요한 만큼의 메모리 공간을 동적 할당
        strcpy(strptr, namestr);        // 할당한 공간에 바구니에 저장된 값을 복사
        parr[i].SetPersonInfo(strptr, age);     // 할당한 공간의 주소를 넘겨줌
    }

    for (int i = 0; i < 3; i++)
    {
        parr[i].ShowPersonInfo();
    }
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
