#include <stdio.h>

class Value
{
private:
    int mi;
public:
    Value(int i)
    {
        printf("i = %d\n", i);
        mi = i;
    }
    int getI()
    {
        return mi;
    }
};

class Test
{
private:
    const int ci;
    Value m2;
    Value m3;
    Value m1;
public:
    // Note that the initialization order should be
    // ci, m2, m3, m1
    // Also, initialization list will be executed before
    // the class object itself during constructor
    Test() : m1(1), m2(2), m3(3), ci(100)
    {
        printf("Test::Test()\n");
    }
    int getCI()
    {
        return ci;
    }
    void setCI(int v)
    {
        // make ci can be modified by const_cast<>
        // where is only available via pointer/reference
        // so we need to do such "<int*>(&ci)" way
        int* p = const_cast<int*>(&ci);
        *p = v;
        printf("ci is being set to new value %d\n", v);
    }
};


int main()
{
    Test t;

    printf("t.ci = %d\n", t.getCI());

    t.setCI(10);

    printf("t.ci = %d\n", t.getCI());

    return 0;
}
