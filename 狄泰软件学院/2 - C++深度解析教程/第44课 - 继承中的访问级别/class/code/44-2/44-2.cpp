#include <iostream>
#include <string>

using namespace std;

class Parent
{
protected:
    // Child class object can also
    // access this member
    int mv;
public:
    Parent()
    {
        mv = 100;
    }

    int value()
    {
        return mv;
    }
};

class Child : public Parent
{
public:
    int addValue(int v)
    {
        // mv now is a protected member
        // the child object can also access
        // it while other objects or outside
        // cannot access mv
        mv = mv + v;
        return mv;
    }
};

int main()
{
    Parent p;

    cout << "p.mv = " << p.value() << endl;

    // p.mv = 1000;    // error, outside object cannot access private or protected member

    Child c;

    cout << "c.mv = " << c.value() << endl;

    c.addValue(50);

    cout << "c.mv = " << c.value() << endl;

    // c.mv = 10000;  // error

    return 0;
}
