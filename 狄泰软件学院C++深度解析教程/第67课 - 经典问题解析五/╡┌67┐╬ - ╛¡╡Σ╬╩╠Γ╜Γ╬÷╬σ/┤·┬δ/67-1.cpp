#include <iostream>
#include <string>

using namespace std;

class Test
{
public:
    Test()
    {
    }
    virtual ~Test()
    {
    }
};

template
<typename T>
char IsPtr(T* v) // match pointer
{
    return 'd';
}

int IsPtr(...)  // match non-pointer
{
    return 0;
}

#define ISPTR(p) (sizeof(IsPtr(p)) == sizeof(char))

int main(int argc, char *argv[])
{
    int i = 0;
    int* p = &i;
    
    cout << "p is a pointer: " << ISPTR(p) << endl;    // true
    cout << "i is a pointer: " << ISPTR(i) << endl;    // false
    
    Test t;
    Test* pt = &t;
    
    cout << "pt is a pointer: " << ISPTR(pt) << endl;    // true
    cout << "t is a pointer: " << ISPTR(t) << endl;    // false
    
    return 0;
}

