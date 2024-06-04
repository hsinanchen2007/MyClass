#include <iostream>
#include <string>

using namespace std;

int main()
{
    short s = 'a';
    unsigned int ui = 1000;
    int i = -2000;
    double d = i;

    cout << "d = " << d << endl;
    cout << "ui = " << ui << endl;

    // unsigned int + int, the root cause
    // is mainly due to i is a nagative value,
    // when it is converted to unsigned int,
    // the value will become unexpected value
    cout << "ui + i = " << ui + i << endl;
    cout << "(unsigned int)i" << (unsigned int)i << endl;

    if ((ui + i) > 0)
    {
        cout << "Positive" << endl;
    }
    else
    {
        cout << "Negative" << endl;
    }

    cout << "sizeof(s + 'b') = " << sizeof(s + 'b') << endl;

    return 0;
}
