#include <iostream>
#include <string>

using namespace std;

class Test
{
    int i;
public:
    Test(int i)
    {
        cout << "Test(int i)" << endl;
        this->i = i;
    }
    int value()
    {
        cout << "value()" << endl;
        return i;
    }
    ~Test()
    {
        cout << "~Test()" << endl;
    }
};

class Pointer
{
    Test* mp;
public:
    Pointer(Test* p = NULL)
    {
        cout << "Pointer(Test* p = NULL)" << endl;
        mp = p;
    }
    // copy constructor
    Pointer(const Pointer& obj)
    {
        // copy "mp" from source to destination
        // and set "mp" in destination to NULL
        cout << "Pointer(const Pointer& obj)" << endl;
        mp = obj.mp;
        const_cast<Pointer&>(obj).mp = NULL;
    }
    // assignment operator overload
    Pointer& operator = (const Pointer& obj)
    {
        if (this != &obj)
        {
            cout << "Pointer& operator = (const Pointer& obj)" << endl;
            delete mp;
            mp = obj.mp;
            const_cast<Pointer&>(obj).mp = NULL;
        }

        return *this;
    }
    Test* operator -> ()
    {
        cout << "Test* operator -> ()" << endl;
        return mp;
    }
    Test& operator * ()
    {
        cout << "Test& operator * ()" << endl;
        return *mp;
    }
    bool isNull()
    {
        cout << "bool isNull()" << endl;
        return (mp == NULL);
    }
    ~Pointer()
    {
        cout << "~Pointer()" << endl;
        delete mp;
    }
};

int main()
{
    Pointer p1 = new Test(888);

    cout << p1->value() << endl;

    Pointer p2 = p1;

    cout << p1.isNull() << endl;

    cout << p2->value() << endl;

    // My testing code, to test assignment 
    // operator overload
    Pointer p3;
    p3 = p2;
    cout << p3->value() << endl;

    // Note that based on above code, we will
    // call destructor twice for Pointer, but 
    // for Test, it will be called only once
    // as above code will always ensure only
    // one valid copy of Test existed in the 
    // program controlled by Pointer
    return 0;
}
