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
		cout << "[���� �޽���: �Է��Ͻ� ���� 0���� �۽��ϴ�.]" << endl;
	}
};

#endif // !__NEG_E_H__
