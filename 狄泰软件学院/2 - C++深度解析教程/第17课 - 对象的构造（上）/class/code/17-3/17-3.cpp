#include <stdio.h>

class Test
{
private:
    int i;
    int j;
public:
    int getI() { return i; }
    int getJ() { return j; }

    // By using class constructor, we can initialize 
    // data members automatically every time when it
    // is created, best solution
    // Note that constructor has no return and its name
    // should be same as class name. They can be also
    // defined as overload functions
    Test()
    {
        printf("Test() Begin\n");

        i = 1;
        j = 2;

        printf("Test() End\n");
    }
};

Test gt;

int main()
{
    // No need to specially initialize data members
    // in all class objects, no matter they are global,
    // or created in stack or heap memory
    printf("gt.i = %d\n", gt.getI());
    printf("gt.j = %d\n", gt.getJ());

    Test t1;

    printf("t1.i = %d\n", t1.getI());
    printf("t1.j = %d\n", t1.getJ());

    Test* pt = new Test;

    printf("pt->i = %d\n", pt->getI());
    printf("pt->j = %d\n", pt->getJ());

    delete pt;

    return 0;
}
