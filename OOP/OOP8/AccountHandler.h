#pragma once
#ifndef __HANDLER_H__
#define __HANDLER_H__

#include "Account.h"
#include "AccountArray.h"

/*
클래스 이름: AccountHandler
클래스 유형: 컨트롤(Control) 클래스
*/

class AccountHandler
{
	AccountArray allData;
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