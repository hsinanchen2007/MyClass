#include <iostream>
#include <string>

using namespace std;

// Base class
class Base
{
protected:
    int mi;
public:
    Base(int i)
    {
        mi = i;
    }
    int getI()
    {
        return mi;
    }
    bool equal(Base* obj)
    {
        return (this == obj);
    }
};

// Interface1, real implementation is at derived class
class Interface1
{
public:
    virtual void add(int i) = 0;
    virtual void minus(int i) = 0;
};

// Interface2, real implementation is at derived class
class Interface2
{
public:
    virtual void multiply(int i) = 0;
    virtual void divide(int i) = 0;
};

class Derived : public Base, public Interface1, public Interface2
{
public:
    Derived(int i) : Base(i)
    {
    }
    void add(int i)
    {
        mi += i;
    }
    void minus(int i)
    {
        mi -= i;
    }
    void multiply(int i)
    {
        mi *= i;
    }
    void divide(int i)
    {
        if (i != 0)
        {
            mi /= i;
        }
    }
};

int main()
{
    Derived d(100);
    Derived* p = &d;
    Interface1* pInt1 = &d;
    Interface2* pInt2 = &d;

    cout << "p->getI() = " << p->getI() << endl;    // 100

    // ((100 + 10) / 11 - 5) * 8 = 40
    pInt1->add(10);
    pInt2->divide(11);
    pInt1->minus(5);
    pInt2->multiply(8);

    cout << "p->getI() = " << p->getI() << endl;    // 40

    cout << endl;

    // use dynamic_case<> to convert class object, works and returns 1
    cout << "pInt1 == p : " << p->equal(dynamic_cast<Base*>(pInt1)) << endl;
    cout << "pInt2 == p : " << p->equal(dynamic_cast<Base*>(pInt2)) << endl;

    // by using C style conversion, it doesn't work so it returns 0 
    cout << "pInt1 == p : " << p->equal((Base*)(pInt1)) << endl;
    cout << "pInt2 == p : " << p->equal((Base*)(pInt2)) << endl;

    return 0;
}
