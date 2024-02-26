#include "rational.h"
#include <iostream>


int main()
{
    myMath::Rational f1(2, 16);
    myMath::Rational f2(7, 8);

    // �����������ӷ�����
    std::cout << f1 << " + " << f2 << " == " << (f1+f2) << "\n";

    // ������������������
    std::cout << f1 << " - " << f2 << " == " << (f1-f2) << "\n";

    // �����������˷�����
    std::cout << f1 << " * " << f2 << " == " << (f1*f2) << "\n";

    // ������������������
    std::cout << f1 << " / " << f2 << " == " << (f1/f2) << "\n";

    return 0;
}
