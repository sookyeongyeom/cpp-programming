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
		cout << "[���� �޽���: �ܾ��� �����մϴ�.]" << endl;
	}
};

#endif // !__LACK_E_H__
