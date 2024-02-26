#include <iostream>

// 演示对运算符"+"进行重载达到目的！

class Complex
{
public:
    Complex();
    Complex(double r, double i);
    friend Complex operator+(Complex &c, Complex &d);
    void print();

private:
    double real;
    double imag;
};

Complex::Complex()
{
    real = 0;
    imag = 0;
}

Complex::Complex(double r, double i)
{
    real = r;
    imag = i;
}

// 注意，这里作为友元函数，不属于Complex，记得别写 :: 咯!
Complex operator+(Complex &c, Complex &d)
{
    return Complex(c.real+d.real, c.imag+d.imag);
}

void Complex::print()
{
    std::cout << "(" << real << ", " << imag << "i)\n";
}

int main()
{
    Complex c1(3, 4), c2(5, -10), c3;

    c3 = c1 + c2;

    std::cout << "c1 = ";
    c1.print();
    std::cout << "c2 = ";
    c2.print();
    std::cout << "c1 + c2 = ";
    c3.print();

    return 0;
}
