#include <iostream>
#include <string>

using namespace std;

class Parent
{
    // private members of partent
    // child class object cannot
    // access this directly
    int mv;
public:
    Parent()
    {
        cout << "Parent()" << endl;
        mv = 100;
    }
    void method()
    {
        cout << "mv = " << mv << endl;
    }
};

// Below ": public Parent" tells compiler
// that the current class inherits the 
// specific parent class
class Child : public Parent
{
public:
    // create this method where parent class 
    // didn't have it
    void hello()
    {
        cout << "I'm Child calss!" << endl;
    }
};

int main()
{
    Child c;

    c.hello();
    c.method();

    // Below code, we assign child object
    // directly to parent object
    // By default, compiler will do a simple
    // copy by value
    Parent p = c;
    p.method();

    // However, as p is being declared as parent
    // where partent didn't have such hello()
    // member function, so it cannot work below
    // p.hello(); 

    return 0;
}
