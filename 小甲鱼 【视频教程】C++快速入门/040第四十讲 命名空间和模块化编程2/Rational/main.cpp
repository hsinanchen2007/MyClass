#include "rational.h"
#include <iostream>

int main()
{
    Rational f1(2, 16);
    Rational f2(7, 8);

    // 测试有理数加法运算
    std::cout << f1 << " + " << f2 << " == " << (f1+f2) << "\n";

    // 测试有理数减法运算
    std::cout << f1 << " - " << f2 << " == " << (f1-f2) << "\n";

    // 测试有理数乘法运算
    std::cout << f1 << " * " << f2 << " == " << (f1*f2) << "\n";

    // 测试有理数除法运算
    std::cout << f1 << " / " << f2 << " == " << (f1/f2) << "\n";

    return 0;
}
