#pragma once
#ifndef __CAL_H__
#define __CAL_H__

class Calculator
{
private:
    int add_cnt;
    int sub_cnt;
    int mul_cnt;
    int div_cnt;
public:
    void Init();
    double Add(double x, double y);
    double Sub(double x, double y);
    double Mul(double x, double y);
    double Div(double x, double y);
    void ShowOpCount();
};

#endif