#include <iostream>
#include <string>

using namespace std;

int func(int i)
{
    cout << "int func(int i) : i = " << i << endl;

    return i;
}

int main()
{
    // In below && condition, the first func(0) is already false
    // so it will not even call func(1) as the result will be false
    // no matter it's func(0) or func(1)
    if (func(0) && func(1))
    {
        cout << "Result is true!" << endl;
    }
    else
    {
        cout << "Result is false!" << endl;
    }

    cout << endl;

    // In below condition, func(0) is false, but as it is ||
    // condition, we cannot tell the final result until we
    // also know func(1) is true
    if (func(0) || func(1))
    {
        cout << "Result is true!" << endl;
    }
    else
    {
        cout << "Result is false!" << endl;
    }

    return 0;
}
