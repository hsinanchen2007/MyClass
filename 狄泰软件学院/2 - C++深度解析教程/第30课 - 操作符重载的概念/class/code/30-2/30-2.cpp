#include <stdio.h>

class Complex
{
    int a;
    int b;
public:
    Complex(int a = 0, int b = 0)
    {
        this->a = a;
        this->b = b;
    }

    int getA()
    {
        return a;
    }

    int getB()
    {
        return b;
    }

    // define another same functionality operator +
    // within class, and by default, C++ compiler
    // will try to find the operator overload function
    // inside class first, if no, then outside global
    // one, so for this example, global overload
    // function will not be called
    Complex operator + (const Complex& p1) {
        Complex result;

        printf("Using class Complex operator + (const Complex& p1)\n");
        result.a = this->a + p1.a;
        result.b = this->b + p1.b;

        return result;
    }

    // still friend function, but use a global operator + way
    // Complex Add(const Complex& p1, const Complex& p2);
    // we replace Add to "operator +", that's it.
    // syntax: return operator + (const type& v1, const type& v2)
    friend Complex operator + (const Complex& p1, const Complex& p2);
};

// Complex Add(const Complex& p1, const Complex& p2);
Complex operator + (const Complex& p1, const Complex& p2)
{
    Complex ret;

    printf("Using global Complex operator + (const Complex& p1, const Complex& p2)\n");
    ret.a = p1.a + p2.a;
    ret.b = p1.b + p2.b;

    return ret;
}

int main()
{
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3 = c1 + c2; // operator + (c1, c2)

    printf("c3.a = %d, c3.b = %d\n", c3.getA(), c3.getB());

    return 0;
}
