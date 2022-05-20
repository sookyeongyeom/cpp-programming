#pragma once
#ifndef __NORMAL_H__
#define __NORMAL_H__

#include "Account.h"
#include "../OOP9/String.h"

/*
Ŭ���� �̸�: NormalAccount
Ŭ���� ����: ���뿹�ݰ��� Ŭ����
*/

class NormalAccount : public Account
{
	int ratio;
public:
	NormalAccount(int id, String name, int balance, int ratio) : Account(id, name, balance), ratio(ratio) {}
	virtual void Deposit(int money)
	{
		Account::Deposit(money);		// �����߰�
		Account::Deposit(money * (ratio / 100.0));	// �����߰�
	}
};

#endif // !__NORMAL_H__
