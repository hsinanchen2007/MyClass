#include <stdio.h>

class Test
{
private:
    const int ci;
    int i = 10;
public:
    // To give a value of a const variable, it required to set
    // its initial value from argument list
    Test(): ci(10)
    {
        // below statement will not work as we cannot
        // assign a new value to const variable here
        //ci = 10;
    }
    Test(int v) : ci(v), i(v)
    {
        // below statement will not work as we cannot
        // assign a new value to const variable here
        //ci = 10;
    }
    int getCI() const
    {
        return ci;
    }
    int getI() const
    {
        return i;
    }
};


int main()
{
    // use default constructor, specify ci to 10
    Test t1;
    printf("t1.ci = %d\n", t1.getCI());

    // use parameter constructor, specify ci to whatever it set
    Test t2(99);
    printf("t2.ci = %d\n", t2.getCI());

    Test t3(9999);
    printf("t3.ci = %d, t3.i = %d\n", t3.getCI(), t3.getI());

    return 0;
}
