#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"
#include "LackException.h"
#include "NegException.h"
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
	if (money < 0)
		throw NegException();

	balance += money;
}

void Account::Withdraw(int money)
{
	if (money < 0)
		throw NegException();

	if (balance < money)
		throw LackException();

	balance -= money;
}