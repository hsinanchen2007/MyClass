#include <stdio.h>


void demo(void i)   // no such void type function parameter
{
    return i;
}


int main()
{
    void v;         // no such void type variable declaration
    void x = v;     // void type variable assignment
 
    demo(x);

    return 0;
}
