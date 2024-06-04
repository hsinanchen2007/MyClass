#include <iostream>
#include <string>

using namespace std;

class Test
{
    int mValue;
public:
    Test(int i)
    {
        mValue = i;
    }
    int value()
    {
        return mValue;
    }
};

// , operator overload
// Note that it will return second object's 
// reference, and we need to call 
// const_cast<type&>(second) to make , operator
// work properly
Test& operator , (const Test& a, const Test& b)
{
    return const_cast<Test&>(b);
}

Test func(Test& i)
{
    cout << "func() : i = " << i.value() << endl;

    return i;
}

int main()
{
    Test t0(0);
    Test t1(1);

    // Note that here, the order of func() calls 
    // will not be a fixed order, it may call 
    // t0 first then t1
    // That means if the we do NOT use default
    // , operator, the order of below calls will
    // not same as what we expected
    // At real work, it is suggested NOT overload
    // , operator as it may have different order
    // within parameter calls
    Test tt = (func(t0), func(t1));         // Test tt = func(t1);

    cout << tt.value() << endl; // 1

    return 0;
}
