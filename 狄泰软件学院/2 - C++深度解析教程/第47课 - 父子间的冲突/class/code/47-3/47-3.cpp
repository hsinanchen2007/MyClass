#include <iostream>
#include <string>

using namespace std;

class Parent
{
public:
    int mi;

    void add(int v)
    {
        cout << "Parent void add(int v)" << endl;
        mi += v;
    }

    void add(int a, int b)
    {
        cout << "Parent void add(int a, int b)" << endl;
        mi += (a + b);
    }
};

class Child : public Parent
{
public:
    int mi;

    void add(int v)
    {
        cout << "Child void add(int v)" << endl;
        mi += v;
    }

    void add(int a, int b)
    {
        cout << "Child void add(int a, int b)" << endl;
        mi += (a + b);
    }

    void add(int x, int y, int z)
    {
        cout << "Child void add(int x, int y, int z)" << endl;
        mi += (x + y + z);
    }
};

int main()
{
    Child c;

    c.mi = 100;

    c.Parent::mi = 1000;

    cout << "c.mi = " << c.mi << endl;

    cout << "c.Parent::mi = " << c.Parent::mi << endl;

    // Child will hide parent's add() member functions
    // We should NOT say Child will "overload" Parent's 
    // member function, as add() are in different scopes
    // in Child and Parent class
    c.add(1);
    c.add(2, 3);

    // only child class has this add() with three parameters
    c.add(4, 5, 6);

    cout << "c.mi = " << c.mi << endl;

    cout << "c.Parent::mi = " << c.Parent::mi << endl;

    // Now, try to call Parent's add() by specifying
    // Parent::add() way
    c.Parent::add(1, 9);
    cout << "c.Parent::mi = " << c.Parent::mi << endl;

    return 0;
}