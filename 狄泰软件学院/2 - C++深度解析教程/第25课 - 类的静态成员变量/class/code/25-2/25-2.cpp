#include <stdio.h>

class Test
{
private:
    // Now this variable is defined as static
    // which means it will belong to the whole
    // class while all class object will be able
    // to access it and share
    // static members will be created in a seperate 
    // memory location and global area
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

// For static object members, they always needed to 
// be initialized at the beginning of program start
// as it will be used during whole program.
int Test::cCount = 0;

Test gTest;

int main()
{
    // Now the counter will be for all class objects
    Test t1;
    Test t2;

    printf("count = %d\n", gTest.getCount());
    printf("count = %d\n", t1.getCount());
    printf("count = %d\n", t2.getCount());

    Test* pt = new Test();

    printf("count = %d\n", pt->getCount());

    delete pt;

    printf("count = %d\n", gTest.getCount());

    return 0;
}
