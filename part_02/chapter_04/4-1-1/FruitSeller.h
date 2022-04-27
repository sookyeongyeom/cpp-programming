#pragma once
#ifndef __SELLER_H__
#define __SELLER_H__

class FruitSeller
{
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;
public:
    void InitMembers(int price, int num, int money);
    int SaleApples(int money);
    void ShowSalesResult() const;
};

#endif // !__SELLER_H__