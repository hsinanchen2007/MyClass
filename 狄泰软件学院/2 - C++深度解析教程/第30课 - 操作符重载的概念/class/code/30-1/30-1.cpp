#include <stdio.h>

class Complex
{
    // private members
    int a;
    int b;
public:
    // constructor
    Complex(int a = 0, int b = 0)
    {
        // use "this" pointer as its argument names are 
        // same as their private member names
        this->a = a;
        this->b = b;
    }

    int getA() const
    {
        return a;
    }

    int getB() const
    {
        return b;
    }

    // use friend function as solution
    friend Complex Add(const Complex& p1, const Complex& p2);
};

// use friend function as solution
// advantage is that it can access members and functions
// within class, but this will break C++'s concept
Complex Add(const Complex& p1, const Complex& p2)
{
    Complex ret;

    ret.a = p1.a + p2.a;
    ret.b = p1.b + p2.b;

    return ret;
}

int main()
{
    // for c3, use friend global function
    // to calculate and return the result
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3 = Add(c1, c2); // c1 + c2

    printf("c3.a = %d, c3.b = %d\n", c3.getA(), c3.getB());

    return 0;
}
