#include <stdio.h>

class Test
{
    int mi;
public:
    Test(int i)
    {
        printf("Test(int i) : %d\n", i);
        mi = i;
    }
    Test(const Test& t)
    {
        printf("Test(const Test& t) : %d\n", t.mi);
        mi = t.mi;
    }
    Test()
    {
        printf("Test()\n");
        mi = 0;
    }
    void print()
    {
        printf("mi = %d\n", mi);
        return;
    }
    ~Test()
    {
        printf("~Test()\n");
    }
};

Test func()
{
    return Test(20);
}

int main()
{
    // Below example is to demonstrate that compiler will
    // try to NOT creating a temporary object and call 
    // copy constructor. Instead, it will try to optimize 
    // the intention/code and call constructor directly 
    // to new object "t" and "tt"

    // It will not create a temporary Test(10) object then
    // call copy constructor again to create it. Instead, it
    // will call constructor directly to "t" with value 10
    Test t = Test(10); // ==> Test t = 10;

    // It will not create a temporay object inside func() with
    // value 20, then call copy constructor to new object "tt".
    // Instead, it will just call constructor directly to "tt". 
    // That will save one copy constructor call from func() 
    // back to outside
    Test tt = func();  // ==> Test tt = Test(20); ==> Test tt = 20;

    t.print();
    tt.print();

    return 0;
}
