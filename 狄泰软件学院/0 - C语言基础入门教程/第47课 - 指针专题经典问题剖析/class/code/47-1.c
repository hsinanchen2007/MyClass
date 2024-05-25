#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0;
    int b = 1;

    int* p = &a;
    int** pp = &p;

    **pp = 2;   // a = 2;

    *pp = &b;   // p = &b;

    *p = 3;     // b = 3;

    printf("a = %d, b = %d\n", a, b);

    return 0;
}
