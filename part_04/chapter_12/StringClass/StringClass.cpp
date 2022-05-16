// StringClass.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class String
{
    char* str;
public:
    String()
    {
        str = NULL;
    }
    String(const char* str)         // 생성자
    {
        this->str = new char[strlen(str) + 1];
        strcpy(this->str, str);
    }
    String(const String& ref)       // 복사생성자
    {
        str = new char[strlen(ref.str) + 1];
        strcpy(str, ref.str);
    }
    String& operator=(const String& ref)        // 대입연산자
    {
        delete[]str;
        str = new char[strlen(ref.str) + 1];
        strcpy(str, ref.str);
        return *this;
    }
    ~String()       // 소멸자
    {
        if (str != NULL)
            delete[]str;
    }

    String operator+(const String& ref)
    {
        char* newStr = new char[strlen(str) + strlen(ref.str) + 1];
        strcpy(newStr, str);        // NULL 상태에서는 strcpy부터 해주어야 함
        strcat(newStr, ref.str);
        String temp(newStr);
        delete[]newStr;
        return temp;
    }

    String& operator+=(const String& ref)
    {
        char* newStr = new char[strlen(str) + strlen(ref.str) + 1];
        strcpy(newStr, str);
        strcat(newStr, ref.str);
        if (str != NULL)
            delete[]str;
        str = newStr;
        return *this;
    }

    bool operator==(const String& ref)
    {
        if (!strcmp(str, ref.str))
            return true;
        else
            return false;
    }

    friend ostream& operator<<(ostream&, const String&);
    friend istream& operator>>(istream&, String&);
};

ostream& operator<<(ostream& os, const String& ref)
{
    os << ref.str;
    return os;
}

istream& operator>>(istream& is, String& ref)
{
    char str[100];
    is >> str;
    ref = String(str);
    return is;
}

int main()
{
    String str1 = "I like ";
    String str2 = "string class!";
    String str3 = str1 + str2;

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    str1 += str2;
    if (str1 == str3)
        cout << "동일 문자열!" << endl;
    else
        cout << "동일하지 않은 문자열!" << endl;

    String str4;
    cout << "문자열 입력: ";
    cin >> str4;
    cout << "입력한 문자열: " << str4 << endl;
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
