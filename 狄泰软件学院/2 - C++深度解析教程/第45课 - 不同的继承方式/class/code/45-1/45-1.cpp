#include <iostream>
#include <string>

using namespace std;

// Within parent and child classes, 
// child class can access public and 
// protected members, but for objects,
// they can still access public ones
class Parent
{
private:
    int m_private;
protected:
    int m_protected;
public:
    int m_public;

    Parent(int v1, int v2, int v3) {
        m_private = v1;
        m_protected = v2;
        m_public = v3;
    }
};

// All access remains same in Parent
class Child_A : public Parent
{
public:
    Child_A() : Parent(1, 2, 3)
    {}
    // public inhert, parent class
    // remain its original access level
    void Test(void) {
        // m_private = 4; cannot access
        m_protected = 5;
        m_public = 6;
        return;
    }
};

// Highest access of Parent now is protected 
class Child_B : protected Parent
{
public:
    Child_B() : Parent(1, 2, 3)
    {}
    // protected inhert, parent class
    // can access its public and protected
    // access level
    void Test(void) {
        // m_private = 4; cannot access
        m_protected = 5;
        m_public = 6;
        return;
    }
};

// Highest access of Parent now is private
class Child_C : private Parent
{
public:
    Child_C() : Parent(1, 2, 3)
    {}
    // private inhert, parent class
    // can access its public and protected
    // access level
    void Test(void) {
        // m_private = 4; cannot access
        m_protected = 5;
        m_public = 6;
        return;
    }
};

int main()
{
    Child_A a;
    a.m_public = 100;           // still public in a
    // a.m_protected = 100;
    // a.m_private = 100;       

    Child_B b;
    // b.m_public = 100;        // become protected in b
    // b.m_protected = 100;
    // b.m_private = 100;

    Child_C c;
    // c.m_public = 100;        // become private in c
    // c.m_protected = 100;
    // c.m_private = 100;

    return 0;
}
