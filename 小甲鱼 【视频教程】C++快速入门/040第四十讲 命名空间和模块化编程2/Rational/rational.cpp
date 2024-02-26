#include "rational.h"
#include <iostream>
#include <stdlib.h>

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

std::ostream& operator<<(std::ostream& os, Rational f)
{
    os << f.numerator << "/" << f.denominator;
    return os;
}
