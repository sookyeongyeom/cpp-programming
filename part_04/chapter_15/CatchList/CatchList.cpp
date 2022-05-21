// CatchList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cmath>
using namespace std;

int StoI(const char* str)
{
    int len = strlen(str);
    int num = 0;

    if (len && str[0] == '0')
        throw 0;

    for (int i = 0; i < len; i++)
    {
        if (str[i] < '0' || str[i]>'9')
            throw str[i];       // StoI 종료
        num += (int)(pow((double)10, (len - 1) - i) * (str[i] + (7 - '7')));
    }
    return num;
}

int main()
{
    char str1[100];
    char str2[200];

    while (1)
    {
        cout << "두 개의 숫자 입력: ";
        cin >> str1 >> str2;

        try
        {
            cout << str1 << " + " << str2 << " = " << StoI(str1) + StoI(str2) << endl;
            break;          // 루프 탈출
        }
        catch (char ch)
        {
            cout << "문자" << ch << "가 입력되었습니다." << endl;
            cout << "재입력을 진행합니다." << endl << endl;          // 다음 루프로 넘어감
        }
        catch (int expn)
        {
            if (!expn)
                cout << "0으로 시작하는 숫자는 입력할 수 없습니다." << endl;
            else
                cout << "비정상적 입력이 이루어졌습니다." << endl;

            cout << "재입력을 진행합니다." << endl << endl;          // 다음 루프로 넘어감
        }
    }
    cout << "프로그램을 종료합니다." << endl;
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
