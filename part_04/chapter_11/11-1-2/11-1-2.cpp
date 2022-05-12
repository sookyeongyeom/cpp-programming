// 11-1-2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Book
{
    char* title;
    char* isbn;
    int price;

public:
    Book(const char* title, const char* isbn, int price) : price(price)
    {
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
        this->isbn = new char[strlen(isbn) + 1];
        strcpy(this->isbn, isbn);
    }
    Book(const Book& src) : price(src.price)
    {
        title = new char[strlen(src.title) + 1];
        isbn = new char[strlen(src.isbn) + 1];
        strcpy(title, src.title);
        strcpy(isbn, src.isbn);
    }
    Book& operator=(const Book& src)
    {
        delete[]title;
        delete[]isbn;

        title = new char[strlen(src.title) + 1];
        isbn = new char[strlen(src.isbn) + 1];
        strcpy(title, src.title);
        strcpy(isbn, src.isbn);
        price = src.price;
        return *this;
    }
    void ShowBookInfo()
    {
        cout << "제목: " << title << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "가격: " << price << endl;
    }
    ~Book()
    {
        delete[]title;
        delete[]isbn;
    }
};

class EBook : public Book
{
    char* DRMKey;

public:
    EBook(const char* title, const char* isbn, int price, const char* DRMKey) : Book(title, isbn, price)
    {
        this->DRMKey = new char[strlen(DRMKey) + 1];
        strcpy(this->DRMKey, DRMKey);
    }
    EBook(const EBook& src) : Book(src)
    {
        DRMKey = new char[strlen(src.DRMKey) + 1];
        strcpy(DRMKey, src.DRMKey);
    }
    EBook& operator=(const EBook& src)
    {
        delete[]DRMKey;

        Book::operator=(src);
        DRMKey = new char[strlen(src.DRMKey) + 1];
        strcpy(DRMKey, src.DRMKey);
        return *this;
    }
    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout << "인증키: " << DRMKey << endl;
    }
    ~EBook()
    {
        delete[]DRMKey;
    }
};

int main()
{
    Book b1("좋은 C++", "555-12345-890-0", 20000);
    Book b2 = b1;       // 복사 생성자 호출
    b2.ShowBookInfo();
    cout << endl;

    Book b3("b3", "0", 0);
    b3 = b2;            // 대입 연산자 호출
    b3.ShowBookInfo();
    cout << endl;

    EBook e1("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    EBook e2 = e1;      // 복사 생성자 호출
    e2.ShowEBookInfo();
    cout << endl;

    EBook e3("e3", "0", 0, "0");
    e3 = e2;            // 대입 연산자 호출
    e3.ShowEBookInfo();
    cout << endl;

    return 0;
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
