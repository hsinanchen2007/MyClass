// Rational.h
// Create by С����

// ���ͷ�ļ��������������ࣨRational class��
// ����߶���������������أ���ʵ�ַ�������

#include <iostream>

class Rational
{
public:
    Rational(int num, int denom);  // num = ����, denom = ��ĸ

    Rational operator+(Rational rhs); // rhs == right hand side
    Rational operator-(Rational rhs);
    Rational operator*(Rational rhs);
    Rational operator/(Rational rhs);

private:
    void normalize(); // ����Է����ļ򻯴���

    int numerator;    // ����
    int denominator;  // ��ĸ

    friend std::ostream& operator<<(std::ostream& os, Rational f);
};