#pragma once
#ifndef __HANDLER_H__
#define __HANDLER_H__

#include "Account.h"
#include "BoundCheckArray.h"

/*
Ŭ���� �̸�: AccountHandler
Ŭ���� ����: ��Ʈ��(Control) Ŭ����
*/

class AccountHandler
{
	BoundCheckArray<Account*> allData;
	int index;
public:
	AccountHandler();
	void Create();
	void Deposit();
	void Withdraw();
	void ShowAll();
	void ShowMenu();
	~AccountHandler();
protected:
	void CreateNormal();
	void CreateHigh();
};

#endif // !__HANDLER_H__