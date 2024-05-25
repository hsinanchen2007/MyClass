#include <stdio.h>


void demo(void i)
{
    return i;
}


int main()
{
    void v;
    void x = v;

    demo(x);

    return 0;
}
