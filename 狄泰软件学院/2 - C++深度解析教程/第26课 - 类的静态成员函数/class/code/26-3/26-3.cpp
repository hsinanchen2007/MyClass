#include <stdio.h>

class Test
{
private:
    // Now private static member can be 
    // access outside class by static
    // member function without any object
    // is created
    static int cCount;

    // another none static member
    int myTest;
public:
    Test(): myTest(0)
    {
        cCount++;
    }
    ~Test()
    {
        --cCount;
    }
    // can access this counter without 
    // any class object is created
    static int GetCount()
    {
        // Note that static member function can
        // only access static members, not regular 
        // members, so below, we cannot access
        // "myTest"
        //myTest++;
        return cCount;
    }
};

// Same, always needed to initialize 
// static members first
int Test::cCount = 0;

int main()
{
    printf("count = %d\n", Test::GetCount());

    Test t1;
    Test t2;

    printf("count = %d\n", t1.GetCount());
    printf("count = %d\n", t2.GetCount());

    Test* pt = new Test();

    printf("count = %d\n", pt->GetCount());

    delete pt;

    printf("count = %d\n", Test::GetCount());

    return 0;
}
