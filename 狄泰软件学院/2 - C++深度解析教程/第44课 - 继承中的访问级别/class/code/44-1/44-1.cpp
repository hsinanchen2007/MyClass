#include <iostream>
#include <string>

using namespace std;

class Parent
{
private:
    // "private" means private, only 
    // Parent itself can access its
    // private members
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

    // To allow access private member,
    // from child class object, it required
    // a public or protected member function 
    // to achieve the purpose
    void setParentMv(int v) {
        mv = v;
    }
};

class Child : public Parent
{
public:
    // The original code is trying to demonstrate
    // that child class object cannot access private
    // member of Parent class
    int addValue(int v)
    {
        // mv is private member of parent
        // mv = mv + v;    

        // We can create a new member function
        // in parent class which can access the
        // private members
        setParentMv(value() + v);

        return value();
    }
    int reportValue()
    {
        return value();
    }
};

int main()
{
    Child c;

    c.addValue(99);
    cout << c.reportValue() << endl;

    return 0;
}
