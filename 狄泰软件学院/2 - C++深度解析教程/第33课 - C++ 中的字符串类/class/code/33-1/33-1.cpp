#include <iostream>

// Need to include string header
// if we need to use "string" type
// C++ itself natvely didn't have
// such "string" type. This is from
// C++ STL!!
#include <string>

using namespace std;

void string_sort(string a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (a[i] > a[j])
            {
                // C++ STL string has such "swap" function
                // https://en.cppreference.com/w/cpp/string/basic_string/swap
                swap(a[i], a[j]);
            }
        }
    }
}

string string_add(string a[], int len)
{
    string ret = "";

    for (int i = 0; i < len; i++)
    {
        // C cannot do this "+" way
        // as it didn't have such overload
        // operation function
        ret += a[i] + "; ";
    }

    return ret;
}

int main()
{
    // use string type directly
    string sa[7] =
    {
        "Hello World",
        "D.T.Software",
        "C#",
        "Java",
        "C++",
        "Python",
        "TypeScript"
    };

    // C style to define C++ string
    const char * sb[7] = {
        "Hello World",
        "D.T.Software",
        "C#",
        "Java",
        "C++",
        "Python",
        "TypeScript"
    };

    // perform string operations
    // directly
    string_sort(sa, 7);

    // will not work below because 
    // C didn't have such "swap" function
    // and it cannot do string1 + string2
    // operations
    // string_sort(sb, 7);

    for (int i = 0; i < 7; i++)
    {
        cout << sa[i] << endl;
    }

    cout << endl;

    cout << string_add(sa, 7) << endl;

    return 0;
}
