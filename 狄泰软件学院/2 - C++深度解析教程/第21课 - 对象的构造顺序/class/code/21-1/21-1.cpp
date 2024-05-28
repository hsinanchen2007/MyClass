#include <stdio.h>

class Test
{
private:
    int mi;
public:
    // constructor with one parameter
    Test(int i)
    {
        mi = i;
        printf("Test(int i): %d\n", mi);
    }
    // Basic copy constructor
    Test(const Test& obj)
    {
        mi = obj.mi;
        printf("Test(const Test& obj): %d\n", mi);
    }
};

int main()
{
    int i = 0;
    Test a1 = i;

    while (i < 3)
    {
        Test a2 = ++i;
    }

    if (i < 4)
    {
        Test a = a1;
    }
    else
    {
        Test a(100);
    }

    return 0;
}
