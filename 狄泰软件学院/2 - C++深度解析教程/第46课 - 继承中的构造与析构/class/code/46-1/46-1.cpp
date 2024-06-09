#include <iostream>
#include <string>

using namespace std;

class Parent
{
public:
    Parent()
    {
        cout << "Parent()" << endl;
    }
    Parent(string s)
    {
        cout << "Parent(string s) : " << s << endl;
    }
};

class Child : public Parent
{
public:
    // No initialization list with default parent class
    Child()
    {
        cout << "Child()" << endl;
    }
    // initialization list with string parent class
    Child(string s) : Parent(s)
    {
        cout << "Child(string s) : " << s << endl;
    }
};

int main()
{
    Child c;
    Child cc("cc");

    return 0;
}
