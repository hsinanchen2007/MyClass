#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Test
{
    int* mp;
public:
    Test()
    {
        cout << "Test::Test()" << endl;

        mp = new int(100);

        cout << *mp << endl;
    }
    ~Test()
    {
        delete mp;

        cout << "~Test::Test()" << endl;
    }
};

int main()
{
    // will call class constructor
    Test* pn = new Test;

    // will NOT call class constructor
    Test* pm = (Test*)malloc(sizeof(Test));

    // will call class destructor
    delete pn;

    // will NOT call class destructor
    // also, free() cannot free another data 
    // created in heap in the current data 
    free(pm);

    return 0;
}
