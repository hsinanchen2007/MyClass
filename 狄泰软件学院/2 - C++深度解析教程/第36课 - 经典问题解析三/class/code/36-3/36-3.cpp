#include <iostream>
#include <string>

using namespace std;

int main()
{
    const char* p = "12345";
    string s = "";

    // reserve 10 characters first
    s.reserve(10);

    for (int i = 0; i < 5; i++)
    {
        // We cannot use below [] assignment way
        // because string won't know its real size
        // However, string has append() and puch_back()
        // functions to update the string
        //s[i] = p[i];

        s.append(1, p[i]);
        s.push_back(p[i]);
    }

    cout << s << endl;

    return 0;
}
