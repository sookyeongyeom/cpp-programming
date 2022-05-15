#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

/*
클래스 이름: Account
클래스 유형: Entity 클래스
*/

class Account
{
private:
	int id;
	char* name;
	int balance;
public:
	Account(int, char*, int);
	Account(const Account&);
	Account& operator=(const Account&);
	int GetID() const;
	char* GetName() const;
	int GetBalance() const;
	virtual void Deposit(int);
	void Withdraw(int);
	~Account();
};

#endif // !__ACCOUNT_H__