#include <stdio.h>

class Test
{
private:
    int i;
    int j;
public:
    int getI() { return i; }
    int getJ() { return j; }
};

Test gt;

int main()
{
    // For global one, its members will be initialized
    // to 0 automatically
    printf("gt.i = %d\n", gt.getI());
    printf("gt.j = %d\n", gt.getJ());

    Test t1;

    // For normal local variable/class, they will be
    // random numbers if they are not initialized
    // accordingly
    printf("t1.i = %d\n", t1.getI());
    printf("t1.j = %d\n", t1.getJ());

    Test* pt = new Test;

    // In Windows, for members in heap memory, they will 
    // be random numbers if they are not initialized accordingly
    // In Linux, below should be random numbers, but somehow 
    // they are always 0
    printf("pt->i = %d\n", pt->getI());
    printf("pt->j = %d\n", pt->getJ());

    delete pt;

    return 0;
}
