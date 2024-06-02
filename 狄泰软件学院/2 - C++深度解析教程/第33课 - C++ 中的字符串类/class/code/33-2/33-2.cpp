// By using "sstream", we can convert
// string to int, or int to string
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#define TO_NUMBER(s, n) (istringstream(s) >> n)
#define TO_STRING(n) (((ostringstream&)(ostringstream() << n)).str())

int main()
{

    double n = 0;

    if (TO_NUMBER("234.567", n))
    {
        cout << n << endl;
    }

    string s = TO_STRING(12345);

    cout << s << endl;

    // Use C++ string's utility functions
    // strtod() will convert a string into
    // a double number
    // Note that it required a "end" parameter
    // otherwise it can't work. Why do we need
    // that "end" parameter?
    // Note that the first parameter can be
    // only const char *
    // https://en.cppreference.com/w/cpp/string/byte/strtof
    char* end =NULL;
    cout << strtod("987.654", &end) << endl;

    const char * myTest1 = "567.890";
    cout << strtod(myTest1, &end) << endl;

    const char* myTest2 = "12345.67890";
    cout << strtof(myTest2, &end) << endl;

    // Use to_string() utility to convert
    // double into string
    // https://en.cppreference.com/w/cpp/string/basic_string/to_string
    // It basically can convert all basic type 
    // into C++ string
    string myTest3 = to_string(123.456);
    cout << myTest3 << endl;

    return 0;
}
