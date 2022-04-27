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
        cout << "�߸��� ���� �ݾ� ���� �� ";
        return false;
    }
    numOfApples += seller.SaleApples(money);
    myMoney -= money;
    return true;
}

void FruitBuyer::ShowBuyResult() const
{
    cout << "���� �ܾ�: " << myMoney << endl;
    cout << "��� ����: " << numOfApples << endl;
}