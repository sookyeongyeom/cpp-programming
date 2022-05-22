// DynamicCasting.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class Car
{
    int fuelGauge;
public:
    Car(int fuel):fuelGauge(fuel) {}
    void ShowCarState() { cout << "잔여 연료량: " << fuelGauge << endl; }
};

class Truck : public Car
{
    int freightWeight;
public:
    Truck(int fuel, int weight) : Car(fuel), freightWeight(weight) {}
    void ShowTruckState()
    {
        ShowCarState();
        cout << "화물의 무게: " << freightWeight << endl;
    }
};

int main()
{
    // Truck을 가리키는 Car포인터를 Truck포인터로 (이런 경우 static_cast를 사용해야함)
    Car* pcar1 = new Truck(80, 200);
    //Truck* ptruck1 = dynamic_cast<Truck*>(pcar1);       // 컴파일 에러

    // Car를 가리키는 Car포인터를 Truck포인터로 (의도적으로라도 하면 안됨)
    Car* pcar2 = new Car(120);
    //Truck* ptruck2 = dynamic_cast<Truck*>(pcar2);       // 컴파일 에러

    // Truck을 가리키는 Truck포인터를 Car포인터로
    Truck* ptruck3 = new Truck(70, 150);
    Car* pcar3 = dynamic_cast<Car*>(ptruck3);       // 컴파일 OK!
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
