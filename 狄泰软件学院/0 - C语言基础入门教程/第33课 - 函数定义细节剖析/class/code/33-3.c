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
    f();
    f(1, 2);

    g();
    g(1);   // ERROR

    return 0;
}
