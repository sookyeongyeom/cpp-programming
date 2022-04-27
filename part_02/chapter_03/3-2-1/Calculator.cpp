#include <iostream>
#include "Calculator.h"
using namespace std;

void Calculator::Init()
{
    add_cnt = sub_cnt = mul_cnt = div_cnt = 0;
}

double Calculator::Add(double x, double y)
{
    add_cnt++;
    return x + y;
}

double Calculator::Sub(double x, double y)
{
    sub_cnt++;
    return x - y;
}

double Calculator::Mul(double x, double y)
{
    mul_cnt++;
    return x * y;
}

double Calculator::Div(double x, double y)
{
    div_cnt++;
    return x / y;
}

void Calculator::ShowOpCount()
{
    cout << "µ¡¼À: " << add_cnt << " ";
    cout << "»¬¼À: " << sub_cnt << " ";
    cout << "°ö¼À: " << mul_cnt << " ";
    cout << "³ª´°¼À: " << div_cnt;
}