#include <iostream>
#include "FruitBuyer.h"
using namespace std;

void FruitBuyer::InitMembers(int money)
{
    myMoney = money;
    numOfApples = 0;
}

bool FruitBuyer::BuyApples(FruitSeller& seller, int money)
{
    if (money < 0)
    {
        cout << "잘못된 구매 금액 전달 → ";
        return false;
    }
    numOfApples += seller.SaleApples(money);
    myMoney -= money;
    return true;
}

void FruitBuyer::ShowBuyResult() const
{
    cout << "현재 잔액: " << myMoney << endl;
    cout << "사과 개수: " << numOfApples << endl;
}