#include <iostream>
#include <string>

using namespace std;

class BaseA
{
    int ma;
public:
    BaseA(int a)
    {
        ma = a;
    }
    int getA()
    {
        return ma;
    }
    virtual void print()
    {
        cout << "BaseA" << getA() << endl;
    }
};

class BaseB
{
    int mb;
public:
    BaseB(int b)
    {
        mb = b;
    }
    int getB()
    {
        return mb;
    }
    virtual void print()
    {
        cout << "BaseB" << getB() << endl;
    }
};

class Derived : public BaseA, public BaseB
{
    int mc;
public:
    Derived(int a, int b, int c) : BaseA(a), BaseB(b)
    {
        mc = c;
    }
    int getC()
    {
        return mc;
    }
    void print()
    {
        cout << "ma = " << getA() << ", "
             << "mb = " << getB() << ", "
             << "mc = " << mc << endl;
    }
};

int main()
{
    cout << "sizeof(Derived) = " << sizeof(Derived) << endl;    // 12

    Derived d(1, 2, 3);

    d.print();

    cout << "d.getA() = " << d.getA() << endl;
    cout << "d.getB() = " << d.getB() << endl;
    cout << "d.getC() = " << d.getC() << endl;

    cout << endl;

    BaseA* pa = &d;
    BaseB* pb = &d;

    cout << "pa->getA() = " << pa->getA() << endl;
    cout << "pb->getB() = " << pb->getB() << endl;

    // Here is the Polymorphism
    // If parent class has "virtual", below will call print from "derived" class
    // If parent class has no "virtual", below will call print from BaseA or BaseB 
    pa->print();
    pb->print();

    cout << endl;

    void* paa = pa;
    void* pbb = pb;

    if (paa == pbb)
    {
        cout << "Pointer to the same object!" << endl;
    }
    else
    {
        cout << "Error" << endl;
    }

    cout << "pa = " << pa << endl;
    cout << "pb = " << pb << endl;
    cout << "paa = " << paa << endl;
    cout << "pbb = " << pbb << endl;

    return 0;
}
