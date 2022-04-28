#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Account
{
private:
	int id;
	char* name;
	int balance;
public:
	Account(int id, char* name, int balance) : id(id), balance(balance)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	int GetID() const
	{
		return id;
	}
	char* GetName() const
	{
		return name;
	}
	int GetBalance() const
	{
		return balance;
	}
	void SetBalance(int money)
	{
		balance += money;
	}
	void ShowInfo() const
	{
		cout << id << ' ' << name << ' ' << balance << endl;
	}
};

Account* allData[50];
int index = 0;
enum { CREATE=1, DEPOSIT, WITHDRAW, SHOWALL, EXIT };

void Create()
{
	int id, balance;
	char name[100];
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ", cin >> id;
	cout << "이름: ", cin >> name;
	cout << "입금액: ", cin >> balance;
	allData[index] = new Account(id, name, balance);
	index++;
}

void DW(int menu)
{
	int id, money;
	switch (menu)
	{
	case DEPOSIT:
		cout << "[입 금]" << endl;
		cout << "계좌ID: ", cin >> id;
		cout << "입금액: ", cin >> money;
		break;
	case WITHDRAW:
		cout << "[출 금]" << endl;
		cout << "계좌ID: ", cin >> id;
		cout << "출금액: ", cin >> money;
		money *= -1;
		break;
	}
	for (int i = 0; i < index; i++)
	{
		if (allData[i]->GetID() == id)
		{
			allData[i]->SetBalance(money);
			cout << "정상 처리되었습니다." << endl;
			return;
		}
	}
	cout << "존재하지 않는 계좌정보입니다." << endl;
	return;
}

void ShowAll()
{
	cout << "[계좌정보 전체 출력]" << endl;
	for (int i = 0; i < index; i++)
	{
		cout << allData[i]->GetID() << ' ';
		cout << allData[i]->GetName() << ' ';
		cout << allData[i]->GetBalance() << endl;
	}
}

void ShowMenu()
{
	int menu;
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ", cin >> menu;
	cout << endl;
	
	switch (menu)
	{
	case CREATE:
		Create();
		break;
	case DEPOSIT:
		DW(DEPOSIT);
		break;
	case WITHDRAW:
		DW(WITHDRAW);
		break;
	case SHOWALL:
		ShowAll();
		break;
	case EXIT:
		cout << "프로그램이 종료됩니다." << endl;
		exit(0);
	}
}

int main()
{
	while (1)
	{
		ShowMenu();
		cout << endl;
	}
}