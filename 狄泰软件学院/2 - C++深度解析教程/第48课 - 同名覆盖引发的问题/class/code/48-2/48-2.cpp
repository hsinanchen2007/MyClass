#include <iostream>
#include <string>

using namespace std;

class Parent
{
public:
    int mi;

    void add(int i)
    {
        mi += i;
    }

    void add(int a, int b)
    {
        mi += (a + b);
    }

    // Here is the key. If there is no virtual, it will 
    // call Parent's print() as the given function parameter
    // is Parent's pointer, not Child
    // When we add "virtual" before void below, it will
    // make the print() to check whether given parameter
    // is realy Parent or Child 
    void print()
    {
        cout << "I'm Parent." << endl;
    }
};

class Child : public Parent
{
public:
    int mv;

    void add(int x, int y, int z)
    {
        mv += (x + y + z);
    }

    void print()
    {
        cout << "I'm Child." << endl;
    }
};

// Common way to demonstrate Parent/Child
// and with or without "virtual" keyword
// set in the Parent member function
void how_to_print(Parent* p)
{
    p->print();
}

int main()
{
    Parent p;
    Child c;

    how_to_print(&p);    // Expected to print: I'm Parent.
    how_to_print(&c);    // Expected to print: I'm Child, but not if no virtual keyword set in the Parent member function

    return 0;
}