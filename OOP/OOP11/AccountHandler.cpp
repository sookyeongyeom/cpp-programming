#include <iostream>
#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "BankingCommonDecl.h"
#include "../OOP9/String.h"
#include "LackException.h"
#include "NegException.h"
using namespace std;

void AccountHandler::Create()
{
	int menu;
	cout << "[������������]" << endl;
	cout << "1. ���뿹�ݰ���	2. �ſ�ŷڰ���" << endl;
	cout << "����: ";
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
	String name;
	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID: ", cin >> id;
	cout << "�̸�: ", cin >> name;
	cout << "�Աݾ�: ", cin >> balance;
	cout << "������: ", cin >> ratio;
	allData[index++] = new NormalAccount(id, name, balance, ratio);
	cout << name << "���� ���뿹�ݰ��°� �����Ǿ����ϴ�!" << endl;
}

void AccountHandler::CreateHigh()
{
	int id, balance, ratio, rank;
	String name;
	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "����ID: ", cin >> id;
	cout << "�̸�: ", cin >> name;
	cout << "�Աݾ�: ", cin >> balance;
	cout << "������: ", cin >> ratio;
	cout << "�ſ���(1forA, 2forB, 3forC): ", cin >> rank;
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
	cout << name << "���� �ſ�ŷڰ��°� �����Ǿ����ϴ�!" << endl;
}

void AccountHandler::Deposit()
{
	int id, money;
	cout << "[�� ��]" << endl;
	cout << "����ID: ", cin >> id;
	for (int i = 0; i < index; i++)
	{
		if (allData[i]->GetID() == id)
		{
			cout << "�̸�: " << allData[i]->GetName() << endl;
			while (1)
			{
				try
				{
					cout << "�Աݾ�: ", cin >> money;
					allData[i]->Deposit(money);
					break;
				}
				catch (NegException& expn)
				{
					expn.ShowReason();
				}
			}
			cout << "�ܾ�: " << allData[i]->GetBalance() << endl;
			cout << "�Ա��� ���� ó���Ǿ����ϴ�." << endl;
			return;
		}
	}
	cout << "�������� �ʴ� ���������Դϴ�." << endl;
	return;
}

void AccountHandler::Withdraw()
{
	int id, money;
	cout << "[�� ��]" << endl;
	cout << "����ID: ", cin >> id;
	for (int i = 0; i < index; i++)
	{
		if (allData[i]->GetID() == id)
		{
			cout << "�̸�: " << allData[i]->GetName() << endl;
			while (1)
			{
				try
				{
					cout << "��ݾ�: ", cin >> money;
					allData[i]->Withdraw(money);
					break;
				}
				catch (NegException& expn)
				{
					expn.ShowReason();
				}
				catch (LackException& expn)
				{
					expn.ShowReason();
				}
			}
			cout << "�ܾ�: " << allData[i]->GetBalance() << endl;
			cout << "����� ���� ó���Ǿ����ϴ�." << endl;
			return;
		}
	}
	cout << "�������� �ʴ� ���������Դϴ�." << endl;
	return;
}

void AccountHandler::ShowAll()
{
	cout << "[�������� ��ü ���]" << endl;
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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

AccountHandler::AccountHandler() : index(0) {}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < index; i++)
	{
		delete allData[i];
	}
}