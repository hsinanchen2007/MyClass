#include <stdio.h>

class Test
{
public:
    // static member, shared by class, 
    // not its class object
    // Note that if above is private,
    // not public, this static member
    // will not be able to be access 
    // outside class
    static int cCount;
public:
    Test()
    {
        cCount++;
    }
    ~Test()
    {
        --cCount;
    }
    int getCount()
    {
        return cCount;
    }
};

// always needed to initialize static member
// at the beginning of program
int Test::cCount = 0;

int main()
{
    printf("count = %d\n", Test::cCount);

    // access static member without any
    // class object created
    // Note that the static member now
    // is defined as public, when it is 
    // defined as private, there is no way
    // to access it like this. We will
    // need another static member function
    // to access private members
    Test::cCount = 1000;

    printf("count = %d\n", Test::cCount);

    return 0;
}
