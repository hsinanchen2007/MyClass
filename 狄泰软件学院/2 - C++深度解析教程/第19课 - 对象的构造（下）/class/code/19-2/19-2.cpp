#include <stdio.h>

class Test
{
private:
    int i;
    int j;

    // As this is a pointer, it is required to create a seperate
    // copy constructor to create a heap memory for this p, otherwise
    // the p will be done by system's default copy constructor, which 
    // will just copy address to new one. When we intend to release
    // the heap memory used by one of class objects, it may cause 
    // unexpected behavior
    int* p;

public:
    int getI()
    {
        return i;
    }
    int getJ()
    {
        return j;
    }
    int* getP()
    {
        return p;
    }
    Test(const Test& t)
    {
        i = t.i;
        j = t.j;
        p = new int;

        *p = *t.p;
    }
    Test(int v)
    {
        i = 1;
        j = 2;
        p = new int;

        *p = v;
    }
    void free()
    {
        delete p;
    }
};

int main()
{
    // specify 3 as p's value

    // specify a value "3" as its p's value
    Test t1(3);

    // if we don't create seperate heap memory for
    // t2's p, it will be shared w/ t1's p, then 
    // when we need to free the heap memory, it will
    // cause double free issue
    Test t2(t1);

    printf("t1.i = %d, t1.j = %d, *t1.p = %d\n", t1.getI(), t1.getJ(), *t1.getP());
    printf("t2.i = %d, t2.j = %d, *t2.p = %d\n", t2.getI(), t2.getJ(), *t2.getP());

    t1.free();
    t2.free();

    return 0;
}
