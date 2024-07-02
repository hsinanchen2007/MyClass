#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
    // constructor can NOT be a virtual function
    Base()
    {
        cout << "Base()" << endl;

        func();
    }

    virtual void func()
    {
        cout << "Base::func()" << endl;
    }

    // destructor can be a virtual function

    // If base class destructor is "virtual":
    //   Base()
    //   Base::func()
    //   Derived()
    //   Derived::func()
    //   Derived::func()
    //   ~Derived()
    //   Base::func()
    //   ~Base()

    // If base class destructor is NOT "virtual":
    //   Base()
    //   Base::func()
    //   Derived()
    //   Derived::func()
    //   Base::func()
    //   ~Base()

    virtual ~Base()
    {
        func();

        cout << "~Base()" << endl;
    }
};


class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived()" << endl;

        func();
    }

    virtual void func()
    {
        cout << "Derived::func()" << endl;
    }

    ~Derived()
    {
        func();

        cout << "~Derived()" << endl;
    }
};


int main()
{
    Base* p = new Derived();

    // ...

    delete p;

    return 0;
}
