#include <iostream>
#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "BankingCommonDecl.h"
using namespace std;

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