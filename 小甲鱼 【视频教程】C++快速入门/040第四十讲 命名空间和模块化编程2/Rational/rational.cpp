#include "rational.h"
#include <iostream>
#include <stdlib.h>

Rational::Rational(int num, int denom)
{
    numerator = num;
    denominator = denom;

    normalize();
}

// normalize() 对分数进行简化操作包括：
// 1. 只允许分子为负数，如果分母为负数则把负数挪到分子部分，如 1/-2 == -1/2
// 2. 利用欧几里德算法（辗转求余原理）将分数进行简化：2/10 => 1/5
void Rational::normalize()
{
    // 确保分母为正
    if( denominator < 0 )
    {
        numerator = -numerator;
        denominator = -denominator;
    }

    // 欧几里德算法
    int a = abs(numerator);
    int b = abs(denominator);

    // 求出最大公约数
    while( b > 0 )
    {
        int t = a % b;
        a = b;
        b = t;
    }

    // 分子、分母分别除以最大公约数得到最简化分数
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
