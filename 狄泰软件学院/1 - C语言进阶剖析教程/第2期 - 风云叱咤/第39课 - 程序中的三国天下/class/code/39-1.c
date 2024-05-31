#include <stdio.h>

int* g()
{
    int a[10] = {0};
    
    return a;
}

void f()
{
    int* pointer = g();
}

int main()
{
    f();
    
    return 0;
}
