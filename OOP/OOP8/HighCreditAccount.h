#pragma once
#ifndef __HIGH_H__
#define __HIGH_H__

#include "NormalAccount.h"

/*
클래스 이름: HighCreditAccount
클래스 유형: 신용신뢰계좌 클래스
*/

class HighCreditAccount : public NormalAccount
{
	int rank;
public:
	HighCreditAccount(int id, char* name, int balance, int ratio, int rank) : NormalAccount(id, name, balance, ratio), rank(rank) {}
	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);			// 원금+이자추가
		Account::Deposit(money * (rank / 100.0));		// 특별이자추가
	}
};

#endif // !__HIGH_H__
