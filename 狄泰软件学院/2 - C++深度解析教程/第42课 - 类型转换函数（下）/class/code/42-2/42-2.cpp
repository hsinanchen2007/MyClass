#include <iostream>
#include <string>

using namespace std;

class Test;

class Value
{
    int vv;
public:
    // Modify below constructor that can take
    // mValue from Test class object, then
    // do something changed in Value class object
    Value(int v) : vv(v)
    {
        cout << "Value(int v) : vv(v)" << endl;
        vv = vv + 1;
        cout << vv << endl;
    }
    explicit Value(Test& t)
    {
        cout << "explicit Value(Test& t)" << endl;
    }
};

class Test
{
    int mValue;
public:
    Test(int i = 0)
    {
        cout << "Test(int i = 0)" << endl;
        mValue = i;
    }
    int value()
    {
        cout << "int value()" << endl;
        return mValue;
    }

    // the common syntax of converter:
    //    operator type()
    // No return, no argument
    operator Value()
    {
        cout << "operator Value()" << endl;
        Value ret(mValue);
        return ret;
    }
};

int main()
{
    Test t(100);

    // Here, we are trying to convert
    // Test class object t to another
    // class object Value v, below 
    // statement will be like:
    // Value v = t.operator Value();
    // Inside operator Value(), it will
    // then create a ret of Value, and
    // return ret
    // Note that there is no return 
    // type here, like type converter 
    // function
    Value v = t;

    return 0;
}
