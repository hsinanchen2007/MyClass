#include <stdio.h>

class Test
{
private:
    // This mCount belongs to the individual class object
    // while we need a counter which belongs to whole class
    int mCount;
public:
    Test() : mCount(0)
    {
        mCount++;
    }
    ~Test()
    {
        --mCount;
    }
    int getCount()
    {
        return mCount;
    }
};

Test gTest;

int main()
{
    // total two class objects, but it shows 1 
    Test t1;
    Test t2;

    printf("count = %d\n", gTest.getCount());
    printf("count = %d\n", t1.getCount());
    printf("count = %d\n", t2.getCount());

    return 0;
}
