// SortFunctor.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class SortRule      // 추상클래스
{
public:
    virtual bool operator()(int num1, int num2) const = 0;
};

class AscendingSort : public SortRule       // 오름차순
{
public:
    bool operator()(int num1, int num2) const
    {
        if (num1 > num2)
            return true;
        else
            return false;
    }
};

class DescendingSort : public SortRule      // 내림차순
{
public:
    bool operator()(int num1, int num2) const
    {
        if (num1 < num2)
            return true;
        else
            return false;
    }
};

class DataStorage       // int형 정수의 저장소
{
    int* arr;
    int idx;
    const int MAX_LEN;
public:
    DataStorage(int arrlen) : idx(0), MAX_LEN(arrlen)
    {
        arr = new int[MAX_LEN];
    }
    void AddData(int num)
    {
        if (MAX_LEN <= idx)
        {
            cout << "더 이상 저장이 불가능합니다." << endl;
            return;
        }
        arr[idx++] = num;
    }
    void ShowAllData()
    {
        for (int i = 0; i < idx; i++)
            cout << arr[i] << ' ';
        cout << endl;
    }
    void SortData(const SortRule& functor)          // 버블정렬 (뒷자리부터 확정된다고 생각하면 됨)
    {
        for(int i=0; i<(idx-1); i++)
            for(int j=0; j<(idx-1)-i; j++)
                if (functor(arr[j], arr[j + 1]))
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
    }
};

int main()
{
    DataStorage storage(5);
    storage.AddData(40);
    storage.AddData(30);
    storage.AddData(50);
    storage.AddData(80);
    storage.AddData(90);
    storage.AddData(120);
    cout << endl;

    cout << "오름차순 정렬" << endl;
    storage.SortData(AscendingSort());
    storage.ShowAllData();
    cout << endl;

    cout << "내림차순 정렬" << endl;
    storage.SortData(DescendingSort());
    storage.ShowAllData();
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
