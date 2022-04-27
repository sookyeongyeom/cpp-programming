#pragma once
#ifndef __BUYER_H__
#define __BUYER_H__

#include "FruitSeller.h"

class FruitBuyer
{
    int myMoney;
    int numOfApples;
public:
    void InitMembers(int money);
    bool BuyApples(FruitSeller& seller, int money);
    void ShowBuyResult() const;
};

#endif // !__BUYER_H__