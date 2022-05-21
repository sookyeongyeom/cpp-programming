// ATMSim2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class AccountException
{
public:
    virtual void ShowExceptionReason() = 0;         // 순수가상함수
};

class DepositException : public AccountException
{
    int reqDep;
public:
    DepositException(int money) : reqDep(money) {}
    void ShowExceptionReason()
    {
        cout << "[예외 메시지: " << reqDep << "원은 입금 불가]" << endl;
    }
};

class WithdrawException : public AccountException
{
    int balance;
public:
    WithdrawException(int money) : balance(money) {}
    void ShowExceptionReason()
    {
        cout << "[예외 메시지: 잔액 " << balance << "원, 잔액 부족]" << endl;
    }
};

class Account
{
    char accNum[50];
    int balance;
public:
    Account(const char* acc, int money) : balance(money)
    {
        strcpy(accNum, acc);
    }
    void Deposit(int money) throw (AccountException)
    {
        if (money < 0)
            throw DepositException(money);
        balance += money;
    }
    void Withdraw(int money) throw (AccountException)
    {
        if (money > balance)
            throw WithdrawException(balance);
        balance -= money;
    }
    void ShowMyMoney()
    {
        cout << "잔고: " << balance << endl << endl;
    }
};

int main()
{
    Account myAcc("12345-67890", 5000);

    try
    {
        myAcc.Deposit(2000);
        myAcc.Deposit(-500);
    }
    catch (AccountException& expn)
    {
        expn.ShowExceptionReason();
    }
    myAcc.ShowMyMoney();

    try
    {
        myAcc.Withdraw(3500);
        myAcc.Withdraw(4500);
    }
    catch (AccountException& expn)
    {
        expn.ShowExceptionReason();
    }
    myAcc.ShowMyMoney();
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
