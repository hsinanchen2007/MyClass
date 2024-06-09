#include <iostream>
#include <string>

using namespace std;

class Parent
{
public:
    int mi;

    Parent()
    {
        mi = 0;
    }

    void add(int i)
    {
        mi += i;
    }

    void add(int a, int b)
    {
        mi += (a + b);
    }
};

class Child : public Parent
{
public:
    int mv;

    Child()
    {
        mv = 0;
    }

    void add(int x, int y, int z)
    {
        mv += (x + y + z);
    }
};

int main()
{
    Parent p;
    Child c;

    // Child class object contains all
    // members in Parent class object
    p = c;
    Parent p1(c);

    // When Child class object is pointed or
    // reference to Parent class
    Parent& rp = c;
    Parent* pp = &c;

    // Child class object as Parent reference
    // and can access Parent's mi as Child class
    // object will include it as well
    rp.mi = 100;

    // Call Parent member functions as Child
    // class object inherits from Parent so 
    // Child class object has access to Parent's
    // public member functions
    rp.add(5);     
    rp.add(10, 10); 

    // cannot do below as pp is declared as Parent
    // It cannot access Child's member functions
    // pp->mv = 1000;
    // pp->add(1, 10, 100);
    // rp.mv = 1000;
    // rp.add(1, 10, 100);

    return 0;
}