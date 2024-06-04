#include <iostream>
#include <string>

using namespace std;

class Test
{
    int mValue;
public:
    Test()
    {
        mValue = 0;
    }

    // the "explicit" tells compiler that
    // do NOT convert the class object
    // automatically, for example,
    // "Test t = 15" this won't work
    // Only "Test t(15)" will work
    explicit Test(int i)
    {
        mValue = i;
    }

    Test operator + (const Test& p)
    {
        Test ret(mValue + p.mValue);

        return ret;
    }

    int value()
    {
        return mValue;
    }
};

int main()
{
    Test t;

    t = static_cast<Test>(5);    // t = Test(5);

    Test r;

    r = t + static_cast<Test>(10);   // r = t + Test(10);

    cout << r.value() << endl;

    // Below won't work because of "explicit" keyword
    // Test s = 15;
    //
    // Below will work as it completely match constructor
    // https://en.cppreference.com/w/cpp/language/explicit
    //
    Test s(15);

    return 0;
}
