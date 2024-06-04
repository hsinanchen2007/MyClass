#include <iostream>
#include <string>

using namespace std;

class Test
{
    int mValue;
public:
    Test(int v)
    {
        cout << "Test(int v)" << endl;
        mValue = v;
    }
    int value() const
    {
        cout << "int value() const" << endl;
        return mValue;
    }
};

// && operator overload, global function
bool operator && (const Test& l, const Test& r)
{
    cout << "bool operator && (const Test& l, const Test& r)" << endl;
    return l.value() && r.value();
}

// || operator overload, global function
bool operator || (const Test& l, const Test& r)
{
    cout << "bool operator || (const Test& l, const Test& r)" << endl;
    return l.value() || r.value();
}

Test func(Test i)
{
    cout << "Test func(Test i) : i.value() = " << i.value() << endl;

    return i;
}

int main()
{
    Test t0(0);
    Test t1(1);

    // Note that now it will have to test both returns of func()
    // The reason is that the func() return type is "Test", not
    // simple bool or int value. The && condition will need to 
    // call its && operator overload, get its "mValue" to see
    // if the condition is true or false.
    // In short, the returned type "Test" cannot tell it's true
    // or false. 
    if (func(t0) && func(t1))
    {
        cout << "Result is true!" << endl;
    }
    else
    {
        cout << "Result is false!" << endl;
    }

    cout << endl;

    // Same as above, below || now needed to perform two checks
    // and ensure its true/false value of each func()
    if (func(1) || func(0))
    {
        cout << "Result is true!" << endl;
    }
    else
    {
        cout << "Result is false!" << endl;
    }

    return 0;
}
