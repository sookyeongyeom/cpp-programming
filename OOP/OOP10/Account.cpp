#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"
using namespace std;

Account::Account(int id, String name, int balance) : id(id), name(name), balance(balance) {}

int Account::GetID() const
{
	return id;
}

String Account::GetName() const
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