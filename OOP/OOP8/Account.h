#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

/*
Ŭ���� �̸�: Account
Ŭ���� ����: Entity Ŭ����
*/

#include "../OOP9/String.h"

class Account
{
private:
	int id;
	String name;
	int balance;
public:
	Account(int, String, int);
	Account(const Account&);
	Account& operator=(const Account&);
	int GetID() const;
	String GetName() const;
	int GetBalance() const;
	virtual void Deposit(int);
	void Withdraw(int);
};

#endif // !__ACCOUNT_H__