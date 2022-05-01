// OOP6.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

enum { CREATE = 1, DEPOSIT, WITHDRAW, SHOWALL, EXIT };

/*
클래스 이름: Account
클래스 유형: Entity 클래스
*/

class Account
{
private:
	int id;
	char* name;
	int balance;
public:
	Account(int id, char* name, int balance);
	Account(const Account& src);
	int GetID() const;
	char* GetName() const;
	int GetBalance() const;
	virtual void Deposit(int);
	void Withdraw(int);
	~Account();
};

Account::Account(int id, char* name, int balance) : id(id), balance(balance)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Account::Account(const Account& src) : id(src.id), balance(src.balance)
{
	name = new char[strlen(src.name) + 1];
	strcpy(name, src.name);
}

int Account::GetID() const
{
	return id;
}

char* Account::GetName() const
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

Account::~Account()
{
	delete[]name;
}

/*
클래스 이름: NormalAccount
클래스 유형: 보통예금계좌 클래스
*/

class NormalAccount : public Account
{
	int ratio;
public:
	NormalAccount(int id, char* name, int balance, int ratio) : Account(id, name, balance), ratio(ratio) {}
	virtual void Deposit(int money)
	{
		Account::Deposit(money);		// 원금추가
		Account::Deposit(money * (ratio/100.0));	// 이자추가
	}
};

/*
클래스 이름: HighCreditAccount
클래스 유형: 신용신뢰계좌 클래스
*/

enum { RANK_A = 7, RANK_B = 4, RANK_C = 2 };

class HighCreditAccount : public NormalAccount
{
	int rank;
public:
	HighCreditAccount(int id, char* name, int balance, int ratio, int rank) : NormalAccount(id, name, balance, ratio), rank(rank) {}
	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);			// 원금+이자추가
		Account::Deposit(money * (rank/100.0));		// 특별이자추가
	}
};

/*
클래스 이름: AccountHandler
클래스 유형: 컨트롤(Control) 클래스
*/

class AccountHandler
{
	Account* allData[50];
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

void AccountHandler::Create()
{
	int menu;
	cout << "[계좌종류선택]" << endl;
	cout << "1. 보통예금계좌	2. 신용신뢰계좌" << endl;
	cout << "선택: ";
	cin >> menu;
	cout << endl;
	switch (menu)
	{
	case 1:
		CreateNormal();
		break;
	case 2:
		CreateHigh();
		break;
	default:
		break;
	}
}

void AccountHandler::CreateNormal()
{
	int id, balance, ratio;
	char name[100];
	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID: ", cin >> id;
	cout << "이름: ", cin >> name;
	cout << "입금액: ", cin >> balance;
	cout << "이자율: ", cin >> ratio;
	allData[index++] = new NormalAccount(id, name, balance, ratio);
	cout << name << "님의 보통예금계좌가 개설되었습니다!" << endl;
}

void AccountHandler::CreateHigh()
{
	int id, balance, ratio, rank;
	char name[100];
	cout << "[신용신뢰계좌 개설]" << endl;
	cout << "계좌ID: ", cin >> id;
	cout << "이름: ", cin >> name;
	cout << "입금액: ", cin >> balance;
	cout << "이자율: ", cin >> ratio;
	cout << "신용등급(1forA, 2forB, 3forC): ", cin >> rank;
	switch (rank)
	{
	case 1:
		allData[index++] = new HighCreditAccount(id, name, balance, ratio, RANK_A);
		break;
	case 2:
		allData[index++] = new HighCreditAccount(id, name, balance, ratio, RANK_B);
		break;
	case 3:
		allData[index++] = new HighCreditAccount(id, name, balance, ratio, RANK_C);
		break;
	default:
		break;
	}
	cout << name << "님의 신용신뢰계좌가 개설되었습니다!" << endl;
}

void AccountHandler::Deposit()
{
	int id, money;
	cout << "[입 금]" << endl;
	cout << "계좌ID: ", cin >> id;
	for (int i = 0; i < index; i++)
	{
		if (allData[i]->GetID() == id)
		{
			cout << "이름: " << allData[i]->GetName() << endl;
			cout << "입금액: ", cin >> money;
			allData[i]->Deposit(money);
			cout << "잔액: " << allData[i]->GetBalance() << endl;
			cout << "입금이 정상 처리되었습니다." << endl;
			return;
		}
	}
	cout << "존재하지 않는 계좌정보입니다." << endl;
	return;
}

void AccountHandler::Withdraw()
{
	int id, money;
	cout << "[출 금]" << endl;
	cout << "계좌ID: ", cin >> id;
	for (int i = 0; i < index; i++)
	{
		if (allData[i]->GetID() == id)
		{
			cout << "이름: " << allData[i]->GetName() << endl;
			cout << "출금액: ", cin >> money;
			allData[i]->Withdraw(money);
			cout << "잔액: " << allData[i]->GetBalance() << endl;
			cout << "출금이 정상 처리되었습니다." << endl;
			return;
		}
	}
	cout << "존재하지 않는 계좌정보입니다." << endl;
	return;
}

void AccountHandler::ShowAll()
{
	cout << "[계좌정보 전체 출력]" << endl;
	for (int i = 0; i < index; i++)
	{
		cout << allData[i]->GetID() << ' ';
		cout << allData[i]->GetName() << ' ';
		cout << allData[i]->GetBalance() << endl;
	}
}

void AccountHandler::ShowMenu()
{
	int menu;
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

AccountHandler::AccountHandler() : index(0) {}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < index; i++)
	{
		delete allData[i];
	}
}

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

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
