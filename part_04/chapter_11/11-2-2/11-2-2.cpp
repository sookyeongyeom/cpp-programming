// 11-2-2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class BoundCheckIntArray
{
    int* arr;
    int arrlen;
public:
    BoundCheckIntArray(int len) : arrlen(len)
    {
        arr = new int[len];
    }
    int& operator[](int idx)
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }
    ~BoundCheckIntArray()
    {
        delete[]arr;
    }
};

class BoundCheck2DIntArray
{
    BoundCheckIntArray** arr;
    int arrlen;
public:
	BoundCheck2DIntArray(int row, int col) : arrlen(row)
	{
		arr = new BoundCheckIntArray*[row];
		for (int i = 0; i < row; i++)
			arr[i] = new BoundCheckIntArray(col);
	}
    BoundCheckIntArray& operator[](int idx)
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return *arr[idx];
    }
    ~BoundCheck2DIntArray()
    {
        for (int i = 0; i < arrlen; i++)
            delete arr[i];
        delete[]arr;
    }
};

int main()
{
	BoundCheck2DIntArray arr(3, 4);

    for (int n = 0; n < 3; n++)
        for (int m = 0; m < 4; m++)
            arr[n][m] = n + m;

    for (int n = 0; n < 3; n++)
    {
        for (int m = 0; m < 4; m++)
            cout << arr[n][m] << ' ';
        cout << endl;
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
