#include <stdio.h>


void f( )
{
    printf("void f() \n");
}

void g(void)
{

}

int main()
{
    // function f() didn't specify any void, that allows
    // C programming language calls with any number of 
    // parameter into f()
    f();
    f(1, 2);    // OK

    // as g() has put void in the parameter part, it cannot
    // allow any parameter into this g()
    g();
    // g(1);    // ERROR

    return 0;
}
