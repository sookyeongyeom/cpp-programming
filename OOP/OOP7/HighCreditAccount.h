#pragma once
#ifndef __HIGH_H__
#define __HIGH_H__

#include "NormalAccount.h"

/*
Ŭ���� �̸�: HighCreditAccount
Ŭ���� ����: �ſ�ŷڰ��� Ŭ����
*/

class HighCreditAccount : public NormalAccount
{
	int rank;
public:
	HighCreditAccount(int id, char* name, int balance, int ratio, int rank) : NormalAccount(id, name, balance, ratio), rank(rank) {}
	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);			// ����+�����߰�
		Account::Deposit(money * (rank / 100.0));		// Ư�������߰�
	}
};

#endif // !__HIGH_H__
