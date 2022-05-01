// 8-1-1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

namespace RISK_LEVEL
{
    enum {
        RISK_A,
        RISK_B,
        RISK_C
    };
}

class Employee      // 추상클래스
{
private:
    char name[100];
public:
    Employee(const char* name)
    {
        strcpy(this->name, name);
    }
    void ShowYourName() const
    {
        cout << "name: " << name << endl;
    }
    virtual int GetPay() const = 0;       // 순수가상함수로 선언
    virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker : public Employee       // 데이터적 성격이 강한 클래스
{
private:
    int salary;
public:
    PermanentWorker(const char* name, int money) : Employee(name), salary(money) {}
    int GetPay() const
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << salary << endl << endl;
    }
};

class SalesWorker : public PermanentWorker
{
    int salesResult;
    double bonusRatio;
public:
    SalesWorker(const char* name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {}
    void AddSalesResult(int value)
    {
        salesResult += value;
    }
    int GetPay() const      // 함수 오버라이딩
    {
        return PermanentWorker::GetPay() + (int)salesResult * bonusRatio;       // PermanentWorker의 GetPay() 호출
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl;         // SalesWorker의 GetPay() 호출
    }
};

class ForeignSalesWorker : public SalesWorker
{
    const int RISK;
public:
    ForeignSalesWorker(const char* name, int money, double ratio, int RISK) : SalesWorker(name, money, ratio), RISK(RISK) {}
    int GetRiskPay() const
    {
        switch (RISK)
        {
        case RISK_LEVEL::RISK_A:
            return SalesWorker::GetPay() * 0.3;
            break;
        case RISK_LEVEL::RISK_B:
            return SalesWorker::GetPay() * 0.2;
            break;
        case RISK_LEVEL::RISK_C:
            return SalesWorker::GetPay() * 0.1;
            break;
        }
    }
    int GetPay() const
    {
        return SalesWorker::GetPay() + GetRiskPay();
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << SalesWorker::GetPay() << endl;
        cout << "risk pay: " << GetRiskPay() << endl;
        cout << "sum: " << GetPay() << endl << endl;
    }
};

class EmployeeHandler        // 컨트롤 클래스(핸들러 클래스), 기능의 처리를 실제로 담당
{
private:
    Employee* empList[50];
    int empNum;
public:
    EmployeeHandler() : empNum(0) {}
    void AddEmployee(Employee* emp)      // 새로운 직원정보 등록
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
    EmployeeHandler handler;

    ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Choco", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000);
    handler.AddEmployee(fseller1);

    ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Ponyo", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller2->AddSalesResult(7000);
    handler.AddEmployee(fseller2);

    ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Gom", 1000, 0.1, RISK_LEVEL::RISK_C);
    fseller3->AddSalesResult(7000);
    handler.AddEmployee(fseller3);

    handler.ShowAllSalaryInfo();
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
