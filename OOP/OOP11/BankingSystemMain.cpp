#include <iostream>
#include "Account.h"
#include "AccountHandler.h"
#include "BankingCommonDecl.h"
using namespace std;

int main()
{
	int menu;
	AccountHandler handler;

	while (1)
	{
		handler.ShowMenu();
		cout << "선택: ";
		cin >> menu;
		cout << endl;

		switch (menu)
		{
		case CREATE:
			handler.Create();
			break;
		case DEPOSIT:
			handler.Deposit();
			break;
		case WITHDRAW:
			handler.Withdraw();
			break;
		case SHOWALL:
			handler.ShowAll();
			break;
		case EXIT:
			cout << "프로그램이 종료됩니다." << endl;
			return 0;
		default:
			break;
		}
		cout << endl;
	}
}