#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "a1b2c3d4e";
    int n = 0;

    for (int i = 0; i < s.length(); i++)
    {
        // By using C++ STL string, we can still
        // access each individual character by
        // array and index way [i]
        // isdigit() will check if the given object
        // is a digital or not
        if (isdigit(s[i]))
        {
            n++;
        }
    }

    cout << n << endl;

    return 0;
}
