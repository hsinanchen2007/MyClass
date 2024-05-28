#include <stdio.h>

class Test
{
    int mi;
public:
    // constructor
    Test(int i)
    {
        mi = i;
        printf("Test(): %d\n", mi);
    }
    // destructor
    ~Test()
    {
        printf("~Test(): %d\n", mi);
    }
};

int main()
{
    Test t(1);

    // create pt in heap memory
    // always use new/delete pair in code
    Test* pt = new Test(2);
    delete pt;

    // t object in stack memory will be 
    // deleted at the end of program
    return 0;
}
