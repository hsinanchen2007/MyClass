#include <stdio.h>

// This Value class is used to demonstrate the order
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
    // Note that the order of their definition is m2, m3, m1
    // Use Value class to demonstrate the order of its initialization list
    Value m2;
    Value m3;
    Value m1;
public:
    // Note that even the order is m1, m2, m3 below, the order
    // of initialization is still m2, m3, m1 as their definition
    // is this order
    Test() : m1(1), m2(2), m3(3)
    {
        printf("Test::Test()\n");
    }
};

int main()
{
    Test t;

    return 0;
}
