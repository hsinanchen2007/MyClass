#include <stdio.h>

class Test
{
private:
    int i;
    int j;
public:
    int getI() { return i; }
    int getJ() { return j; }

    // rely on this initialize() function each time
    // when class objects are created, not good
    void initialize()
    {
        i = 1;
        j = 2;
    }
};

Test gt;

int main()
{
    gt.initialize();

    printf("gt.i = %d\n", gt.getI());
    printf("gt.j = %d\n", gt.getJ());

    Test t1;

    //t1.initialize();

    printf("t1.i = %d\n", t1.getI());
    printf("t1.j = %d\n", t1.getJ());

    // this "initialize()" should be called
    // immediately after creating
    t1.initialize();

    Test* pt = new Test;

    pt->initialize();

    printf("pt->i = %d\n", pt->getI());
    printf("pt->j = %d\n", pt->getJ());

    delete pt;

    return 0;
}
