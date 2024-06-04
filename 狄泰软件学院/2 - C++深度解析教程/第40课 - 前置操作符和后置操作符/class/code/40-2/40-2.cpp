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

    // pre ++ operator overload
    Test& operator ++ ()
    {
        ++mValue;

        // Note that it returns itself
        // so the return type will be 
        // "type &"
        return *this;
    }

    // post ++ operator overload
    // Note that for this one (post),
    // it will require a (int) to
    // differentiate the pre/post
    Test operator ++ (int)
    {
        // need to save it current 
        // value first as return
        Test ret(mValue);

        mValue++;

        // Note that it returns a
        // new created Test object
        // so the return type is 
        // "type ", not "type &"
        return ret;
    }
};

int main()
{
    Test t(0);

    t++;
    cout << t.value() << endl;

    ++t;
    cout << t.value() << endl;

    return 0;
}
