#pragma once
#ifndef __NORMAL_H__
#define __NORMAL_H__

#include "Account.h"
#include "../OOP9/String.h"

/*
클래스 이름: NormalAccount
클래스 유형: 보통예금계좌 클래스
*/

class NormalAccount : public Account
{
	int ratio;
public:
	NormalAccount(int id, String name, int balance, int ratio) : Account(id, name, balance), ratio(ratio) {}
	virtual void Deposit(int money)
	{
		Account::Deposit(money);		// 원금추가
		Account::Deposit(money * (ratio / 100.0));	// 이자추가
	}
};

#endif // !__NORMAL_H__
