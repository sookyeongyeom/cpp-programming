// EmployeeManager1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class PermanentWorker       // 데이터적 성격이 강한 클래스
{
private:
    char name[100];
    int salary;
public:
    PermanentWorker(const char* name, int money) : salary(money)
    {
        strcpy(this->name, name);
    }
    int GetPay() const
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        cout << "name: " << name << endl;
        cout << "salary: " << salary << endl << endl;
    }
};

class EmployeeHandler        // 컨트롤 클래스(핸들러 클래스), 기능의 처리를 실제로 담당
{
private:
    PermanentWorker* empList[50];
    int empNum;
public:
    EmployeeHandler() : empNum(0) {}
    void AddEmployee(PermanentWorker* emp)      // 새로운 직원정보 등록
    {
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const              // 모든 직원의 이번 달 급여정보 출력
    {
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }
    void ShowTotalSalary() const                // 이번 달 급여의 총액 출력
    {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();
        cout << "salary sum: " << sum << endl;
    }
    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

int main()
{
    EmployeeHandler handler;    // 직원관리를 목적으로 설계된 컨트롤 클래스의 객체 생성

    handler.AddEmployee(new PermanentWorker("Choco", 1000));    // 직원 등록
    handler.AddEmployee(new PermanentWorker("Ponyo", 2000));
    handler.AddEmployee(new PermanentWorker("Gom", 3000));

    handler.ShowAllSalaryInfo();    // 이번 달에 지불해야 할 급여 정보
    handler.ShowTotalSalary();      // 이번 달에 지불해야 할 급여 총합
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
