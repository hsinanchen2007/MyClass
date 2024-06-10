#include <iostream>
#include <string>

using namespace std;

class Parent
{
public:
    // After adding "virtual", it makes this print() 
    // member function becomes Polymorphism
    // So depends on which real object is given, program
    // will choose either Parent or Child print()
    // accordingly
    virtual void print()
    {
        cout << "I'm Parent." << endl;
    }
};

class Child : public Parent
{
public:
    void print()
    {
        cout << "I'm Child." << endl;
    }
};

// The parameter is another key
// Parent pointer is given, depends on 
// the real class object, it will 
// choose corresponding member function
void how_to_print(Parent* p)
{
    p->print();     // 展现多态的行为
}

int main()
{
    // by pointer
    Parent p;
    Child c;

    how_to_print(&p);    // Expected to print: I'm Parent.
    how_to_print(&c);    // Expected to print: I'm Child.

    // by reference
    Child cc;
    Parent &pp = cc;
    how_to_print(&pp);    // Expected to print: I'm Child.

    return 0;
}