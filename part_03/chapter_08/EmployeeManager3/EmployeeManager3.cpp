// EmployeeManager3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Employee
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
        cout << "salary: " << GetPay() << endl << endl;         // SalesWorker의 GetPay() 호출
    }
};

class TemporaryWorker : public Employee
{
    int workTime;
    int payPerHour;
public:
    TemporaryWorker(const char* name, int pay) : Employee(name), workTime(0), payPerHour(pay) {}
    void AddWorkTime(int time)
    {
        workTime += time;
    }
    int GetPay() const
    {
        return workTime * payPerHour;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
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
        /*for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();*/
    }
    void ShowTotalSalary() const                // 이번 달 급여의 총액 출력
    {
        int sum = 0;
        /*for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();*/
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
    // 직원관리를 목적으로 설계된 컨트롤 클래스의 객체 생성
    EmployeeHandler handler;    

    // 정규직 등록
    handler.AddEmployee(new PermanentWorker("Choco", 1000));
    
    // 임시직 등록
    TemporaryWorker* alba = new TemporaryWorker("Ponyo", 500);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);

    // 영업직 등록
    SalesWorker* seller = new SalesWorker("Gom", 3000, 0.1);
    seller->AddSalesResult(10000);
    handler.AddEmployee(seller);

    // 이번 달에 지불해야 할 급여 정보
    handler.ShowAllSalaryInfo();    

    // 이번 달에 지불해야 할 급여 총합
    handler.ShowTotalSalary();      
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
