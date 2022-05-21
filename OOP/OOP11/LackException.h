#pragma once
#ifndef __LACK_E_H__
#define __LACK_E_H__

#include <iostream>
using namespace std;

class LackException
{
public:
	void ShowReason()
	{
		cout << "[예외 메시지: 잔액이 부족합니다.]" << endl;
	}
};

#endif // !__LACK_E_H__
