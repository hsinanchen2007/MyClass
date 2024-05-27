#include <stdio.h>

struct A
{
    // defualt to public
    int i;
    // defualt to public
    int getI()
    {
        return i;
    }
};

class B
{
    // To make this code works, we need to make below "public:"
    // so both i and getI() can work, as class by default is 
    // private, while struct by default is public
    public:
     
    // defualt to private
    int i;
    // defualt to private
    int getI()
    {
        return i;
    }
};

int main()
{
    A a;
    B b;

    a.i = 4;

    printf("a.getI() = %d\n", a.getI());

    // Need to change class and make them public
    // otherwise below b.i and b.getI() will not work
    b.i = 4;
    printf("b.getI() = %d\n", b.getI());

    return 0;
}
