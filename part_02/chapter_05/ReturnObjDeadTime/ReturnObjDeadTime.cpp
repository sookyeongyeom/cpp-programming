// ReturnObjDeadTime.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) : num(n)
    {
        cout << "New Object: " << this << endl;
    }
    SoSimple(const SoSimple& src) : num(src.num)
    {
        cout << "New Dest: " << this << endl;
    }
    ~SoSimple()
    {
        cout << "Destroy Object: " << this << endl;
    }
};

SoSimple SimpleFuncObj(SoSimple ob)
{
    cout << "Param Address: " << &ob << endl;
    return ob;
}

int main()
{
    SoSimple obj(7);
    SimpleFuncObj(obj);
    cout << endl;

    SoSimple tempRef = SimpleFuncObj(obj);      // 메모리 효율을 위해 대입연산을 하지 않고 반환되는 임시객체에 tempRef라는 이름을 붙여준다.
    cout << "Return obj: " << &tempRef << endl;
    return 0;
}

//New Object : 000000565133F8E4         → obj 생성
//New Dest : 000000565133F9E4           → 매개변수 ob의 복사 생성자 호출 (src=obj)
//Param Address : 000000565133F9E4      → ob 주소
//New Dest : 000000565133FA24           → 반환하며 임시객체의 복사 생성자 호출 (src=ob)
//Destroy Object : 000000565133F9E4     → 함수 빠져나오며 ob 소멸
//Destroy Object : 000000565133FA24     → 다음 행으로 넘어가며 임시객체 소멸
//
//New Dest : 000000565133FA44           → 매개변수 ob의 복사 생성자 호출 (src=obj)
//Param Address : 000000565133FA44      → ob 주소
//New Dest : 000000565133F904           → 반환하며 임시객체의 복사 생성자 호출 (src=ob)
//Destroy Object : 000000565133FA44     → 함수 빠져나오며 ob 소멸
//Return obj : 000000565133F904         → tempRef 주소 == 임시객체 주소 (반환된 임시객체에 tempRef를 이름으로 붙여줌 - 메모리 낭비 방지)
//Destroy Object : 000000565133F904     → main 빠져나오며 tempRef 소멸
//Destroy Object : 000000565133F8E4     → main 빠져나오며 obj 소멸 (스택이므로 선입후출)