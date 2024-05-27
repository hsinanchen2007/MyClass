#include <stdio.h>

class Test
{
private:
    int i;
    int j;
public:
    int getI()
    {
        return i;
    }
    int getJ()
    {
        return j;
    }

    // By default, if we don't have constructor and
    // copy constructor, C++ will create these by default
    // which has nothing, but if we need to create
    // an owned copy constructor, the constructor must
    // be created as well, cannot from default constructor
    // Without below constructor and copy constructor,
    // g++ can work, but under Windows, VC 2022 cannot work,
    // because line 41 is trying to assign an uninitialized
    // object t1 to t2
    // Copy constructor syntax:
    //     className(const className & Name) {...}
    Test(const Test& t)
    {
        i = t.i;
        j = t.j;
        printf("Copy constructor\n");
    }
    Test()
    {
        i = 0;
        j = 0;
        printf("Default constructor\n");
    }
};

int main()
{
    Test t1;
    Test t2 = t1;
    Test t3(t1);

    // Below "t4 = t1" is assignment, not copy constructor
    // Copy constructor should happen at the beginning
    // when the class object is created
    Test t4;
    t4 = t1;

    printf("t1.i = %d, t1.j = %d\n", t1.getI(), t1.getJ());
    printf("t2.i = %d, t2.j = %d\n", t2.getI(), t2.getJ());

    return 0;
}
