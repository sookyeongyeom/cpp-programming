#include <iostream>

int main()
{
    char name[100], lang[200];

    std::cout << "이름 = ";
    std::cin >> name;

    std::cout << "좋아하는 프로그래밍 언어 = ";
    std::cin >> lang;

    std::cout << "내 이름은 " << name << "입니다.\n";
    std::cout << "제일 좋아하는 언어는 " << lang << "입니다." << std::endl;
    return 0;
}
