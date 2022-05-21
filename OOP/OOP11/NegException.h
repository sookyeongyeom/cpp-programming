#pragma once
#ifndef __NEG_E_H__
#define __NEG_E_H__

#include <iostream>
using namespace std;

class NegException
{
public:
	void ShowReason()
	{
		cout << "[예외 메시지: 입력하신 값이 0보다 작습니다.]" << endl;
	}
};

#endif // !__NEG_E_H__
