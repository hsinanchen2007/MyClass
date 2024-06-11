#include <iostream>
#include <string>

using namespace std;

class Demo
{
protected:
    int mi;
    int mj;
public:
    virtual void print()
    {
        cout << "mi = " << mi << ", "
             << "mj = " << mj << endl;
    }
};

class Derived : public Demo
{
    int mk;
public:
    Derived(int i, int j, int k)
    {
        mi = i;
        mj = j;
        mk = k;
    }

    void print()
    {
        cout << "mi = " << mi << ", "
             << "mj = " << mj << ", "
             << "mk = " << mk << endl;
    }
};

struct Test
{
    void* p;
    int mi;
    int mj;
    int mk;
};

int main()
{
    cout << "sizeof(Demo) = " << sizeof(Demo) << endl;
    cout << "sizeof(Derived) = " << sizeof(Derived) << endl;

    Derived d(1, 2, 3);

    // convert class object into struct object
    // where their data member in memory are same
    // in order and location
    Test* p = reinterpret_cast<Test*>(&d);

    cout << "Before changing ..." << endl;

    d.print();

    // Note that we change values to struct object
    // where mi/mj/mk should NOT be accessible
    // within class object as they are not public
    // data members, however, in struct object,
    // they are all accessible as struct by default
    // is public and by using reinterpret_cast<>,
    // the data members in class object is converted
    // into struct object
    p->mi = 10;
    p->mj = 20;
    p->mk = 30;

    cout << "After changing ..." << endl;

    d.print();

    return 0;
}
