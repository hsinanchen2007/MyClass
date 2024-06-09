#include <iostream>
#include <string>

using namespace std;

// Below example demonstrates when both parent and child have same
// member name defined, which one will be used in child class
class Parent
{
public:
    int mi;
    int value() const{ return mi; }
};

class Child : public Parent
{
public:
    int mi;
    int value() const { return mi; }
};

int main()
{
    Child c;

    // when both members are same name, current member has higher priority
    c.mi = 100;

    // If we need to specify to parent member, need to specify scope resolution
    // by "Parent_Name::Same_Member_Name"
    c.Parent::mi = 999;

    cout << c.mi << endl;
    cout << c.Parent::mi << endl;

    return 0;
}