#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"
using namespace std;

Account::Account(int id, char* name, int balance) : id(id), balance(balance)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Account::Account(const Account& src) : id(src.id), balance(src.balance)
{
	name = new char[strlen(src.name) + 1];
	strcpy(name, src.name);
}

Account& Account::operator=(const Account& src)			// 대입연산자
{
	id = src.id;
	balance = src.balance;

	delete[] name;
	name = new char[strlen(src.name) + 1];
	strcpy(name, src.name);
	return *this;
}

int Account::GetID() const
{
	return id;
}

char* Account::GetName() const
{
	return name;
}

int Account::GetBalance() const
{
	return balance;
}

void Account::Deposit(int money)
{
	balance += money;
}

void Account::Withdraw(int money)
{
	balance -= money;
}

Account::~Account()
{
	delete[]name;
}