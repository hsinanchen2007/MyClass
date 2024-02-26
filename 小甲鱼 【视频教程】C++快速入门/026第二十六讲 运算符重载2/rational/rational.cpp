#include <iostream>
#include <string>
#include <stdlib.h>

class Rational
{
public:
    Rational(int num, int denom);  // num = ����, denom = ��ĸ

    Rational operator+(Rational rhs); // rhs == right hand side
    Rational operator-(Rational rhs);
    Rational operator*(Rational rhs);
    Rational operator/(Rational rhs);

    void print();

private:
    void normalize(); // ����Է����ļ򻯴���

    int numerator;    // ����
    int denominator;  // ��ĸ
};

Rational::Rational(int num, int denom)
{
    numerator = num;
    denominator = denom;

    normalize();
}

// normalize() �Է������м򻯲���������
// 1. ֻ�������Ϊ�����������ĸΪ������Ѹ���Ų�����Ӳ��֣��� 1/-2 == -1/2
// 2. ����ŷ������㷨��շת����ԭ�����������м򻯣�2/10 => 1/5
void Rational::normalize()
{
    // ȷ����ĸΪ��
    if( denominator < 0 )
    {
        numerator = -numerator;
        denominator = -denominator;
    }

    // ŷ������㷨
    int a = abs(numerator);
    int b = abs(denominator);

    // ������Լ��
    while( b > 0 )
    {
        int t = a % b;
        a = b;
        b = t;
    }

    // ���ӡ���ĸ�ֱ�������Լ���õ���򻯷���
    numerator /= a;
    denominator /= a;
}

// a   c   a*d   c*b   a*d + c*b
// - + - = --- + --- = ---------
// b   d   b*d   b*d =    b*d
Rational Rational::operator+(Rational rhs)
{
    int a = numerator;
    int b = denominator;
    int c = rhs.numerator;
    int d = rhs.denominator;

    int e = a*b + c*d;
    int f = b*d;

    return Rational(e, f);
}

// a   c   a   -c
// - - - = - + --
// b   d   b   d
Rational Rational::operator-(Rational rhs)
{
    rhs.numerator = -rhs.numerator;

    return operator+(rhs);
}

// a   c   a*c
// - * - = ---
// b   d   b*d
Rational Rational::operator*(Rational rhs)
{
    int a = numerator;
    int b = denominator;
    int c = rhs.numerator;
    int d = rhs.denominator;

    int e = a*c;
    int f = b*d;

    return Rational(e, f);
}

// a   c   a   d
// - / - = - * -
// b   d   b   c
Rational Rational::operator/(Rational rhs)
{
    int t = rhs.numerator;
    rhs.numerator = rhs.denominator;
    rhs.denominator = t;

    return operator*(rhs);
}

void Rational::print()  // 1/8
{
    if( numerator % denominator == 0 )
        std::cout << numerator / denominator;
    else
        std::cout << numerator << "/" << denominator;
}

int main()
{
    Rational f1(2, 16);
    Rational f2(7, 8);

    // �����������ӷ�����
    Rational res = f1 + f2;
    f1.print();
    std::cout << " + ";
    f2.print();
    std::cout << " = ";
    res.print();
    std::cout << "\n";

    // ������������������
    res = f1 - f2;
    f1.print();
    std::cout << " - ";
    f2.print();
    std::cout << " = ";
    res.print();
    std::cout << "\n";

    // �����������˷�����
    res = f1 * f2;
    f1.print();
    std::cout << " * ";
    f2.print();
    std::cout << " = ";
    res.print();
    std::cout << "\n";

    // ������������������
    res = f1 / f2;
    f1.print();
    std::cout << " / ";
    f2.print();
    std::cout << " = ";
    res.print();
    std::cout << "\n";

    return 0;
}
