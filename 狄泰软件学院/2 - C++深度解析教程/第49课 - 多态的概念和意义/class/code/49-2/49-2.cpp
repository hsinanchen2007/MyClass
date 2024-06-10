#include <iostream>
#include <string>

using namespace std;

class Parent
{
public:
    virtual void func()
    {
        cout << "Parent void func()" << endl;
    }

    virtual void func(int i)
    {
        cout << "Parent void func(int i) : " << i << endl;
    }

    virtual void func(int i, int j)
    {
        cout << "Parent void func(int i, int j) : " << "(" << i << ", " << j << ")" << endl;
    }
};

class Child : public Parent
{
public:
    void func(int i, int j)
    {
        cout << "Child void func(int i, int j) : " << i + j << endl;
    }

    void func(int i, int j, int k)
    {
        cout << "Child void func(int i, int j, int k) : " << i + j + k << endl;
    }
};

void run(Parent* p)
{
    // Polymorphism
    p->func(1, 2);     
}


int main()
{
    Parent p;

    p.func();         // static 
    p.func(1);        // static
    p.func(1, 2);     // static

    cout << endl;

    Child c;

    c.func(1, 2);     // static

    cout << endl;

    run(&p);          // dynmastic
    run(&c);          // dynmastic

    return 0;
}
