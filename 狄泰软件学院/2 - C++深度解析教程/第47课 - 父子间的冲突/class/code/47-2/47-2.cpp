#include <iostream>
#include <string>

using namespace std;

namespace A
{
    int g_i = 0;
}

namespace B
{
    int g_i = 1;
}

class Parent
{
public:
    int mi;

    Parent()
    {
        mi = 0;
        cout << "Parent() : " << "&mi = " << &mi << endl;
    }
};

class Child : public Parent
{
public:
    int mi;

    Child()
    {
        mi = 0;
        cout << "Child() : " << "&mi = " << &mi << endl;
    }
};

int main()
{
    Child c;

    c.mi = 100;

    c.Parent::mi = 1000;

    // Below code demonstrates that two mi members
    // are actually at different location in memory
    //
    // Parent() : &mi = 000000E1206FFB58
    // Child() : &mi = 000000E1206FFB5C
    // & c.mi = 000000E1206FFB5C
    // c.mi = 100
    // & c.Parent::mi = 000000E1206FFB58
    // c.Parent::mi = 1000

    cout << "&c.mi = " << &c.mi << endl;
    cout << "c.mi = " << c.mi << endl;

    cout << "&c.Parent::mi = " << &c.Parent::mi << endl;
    cout << "c.Parent::mi = " << c.Parent::mi << endl;

    return 0;
}