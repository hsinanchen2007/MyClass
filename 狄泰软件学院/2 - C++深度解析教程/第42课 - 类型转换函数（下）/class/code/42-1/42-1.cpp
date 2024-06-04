#include <iostream>
#include <string>

using namespace std;

class Test
{
    int mValue;
public:
    Test(int i = 0)
    {
        mValue = i;
    }
    int value()
    {
        return mValue;
    }

    // This is the special class converter 
    // that will convert this given class to 
    // an integer.
    // Note that there is no return type
    // here so it is NOT operator overload
    operator int()
    {
        return mValue;
    }
};

int main()
{
    Test t(100);

    // Below statement is like 
    // int i = t.operator int();
    // so it will try to convert
    // Test class object t to an
    // integer
    int i = t;

    cout << "t.value() = " << t.value() << endl;
    cout << "i = " << i << endl;

    return 0;
}
