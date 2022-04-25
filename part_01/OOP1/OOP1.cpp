#include <iostream>
using namespace std;

typedef struct
{
    int id;
    char name[50];
    int balance;
} Data;

Data list[50];
int index = 0;

void Create()
{
    Data data;
    cout << "[계좌개설]" << endl;
    cout << "계좌ID: ", cin >> data.id;
    cout << "이름: ", cin >> data.name;
    cout << "입금액: ", cin >> data.balance;
    cout << endl;
    list[index] = data;
    index++;
}

void Deposit(Data *data)
{
    int money;
    cout << "[입 금]" << endl;
    cout << "입금액: ", cin >> money;
    data->balance += money;
    cout << "잔액: " << data->balance << endl;
    cout << "입금이 완료되었습니다." << endl;
    cout << endl;
}

void Withdraw(Data *data)
{
    int money;
    cout << "[출 금]" << endl;
    cout << "출금액: ", cin >> money;
    data->balance -= money;
    cout << "잔액: " << data->balance << endl;
    cout << "출금이 완료되었습니다." << endl;
    cout << endl;
}

void GetData(int num)
{
    int id, isExist=0;
    cout << "[계좌확인]" << endl;
    cout << "계좌ID: ", cin >> id;
    for (int i = 0; i < index; i++)
    {
        if (list[i].id == id)
        {
            cout << list[i].name << "님, 환영합니다." << endl << endl;
            num == 2 ? Deposit(&list[i]) : Withdraw(&list[i]);
            isExist = 1;
        }
    }
    if(!isExist) cout << "등록되지 않은 계좌입니다." << endl << endl;
}

void ShowAll()
{
    cout << "[계좌정보 전체 출력]" << endl;
    for (int i = 0; i < index; i++)
    {
        cout << list[i].id << ' ' << list[i].name << ' ' << list[i].balance << endl;
    }
    cout << endl;
}

void SelectMenu()
{
    int menu;
    cout << "선택: ", cin >> menu, cout << endl;
    switch (menu)
    {
    case 1:
        Create();
        break;
    case 2:
        GetData(2);
        break;
    case 3:
        GetData(3);
        break;
    case 4:
        ShowAll();
        break;
    case 5:
        cout << "프로그램이 종료됩니다.";
        exit(0);
    }
}

void ShowMenu()
{
    cout << "-----Menu-----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
    SelectMenu();
}

int main()
{
    while (1)
    {
        ShowMenu();
    }
}
