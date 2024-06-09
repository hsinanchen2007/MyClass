#include <iostream>
#include <string>

using namespace std;

class Object
{
public:
    Object(string s)
    {
        cout << "Object(string s) : " << s << endl;
    }
};

class Parent : public Object
{
public:
    Parent() : Object("Default")
    {
        cout << "Parent()" << endl;
    }
    Parent(string s) : Object(s)
    {
        cout << "Parent(string s) : " << s << endl;
    }
};

class Child : public Parent
{
    Object mO1;
    Object mO2;
public:
    Child() : mO1("Default 1"), mO2("Default 2")
    {
        cout << "Child()" << endl;
    }
    Child(string s) : Parent(s), mO1(s + " 1"), mO2(s + " 2")
    {
        cout << "Child(string s) : " << s << endl;
    }
};

int main()
{
    // Object(string s) : cc
    // Parent(string s) : cc
    // Object(string s) : cc 1
    // Object(string s) : cc 2
    // Child(string s) : cc

    // Parent class's is inherited from object
    // so object is the 1st parent, then parent
    // In child class, it also has two members,
    // m01 and m02, which is the object class
    // as well, so it will call parent constructor
    // first, then these two object constructors,
    // then finally child class constructor itself
    // 
    // The order of constructor will be:
    //   1. Parent class
    //   2. Other class members within same child class
    //   3. Child class itself
    Child cc("cc");

    return 0;
}
