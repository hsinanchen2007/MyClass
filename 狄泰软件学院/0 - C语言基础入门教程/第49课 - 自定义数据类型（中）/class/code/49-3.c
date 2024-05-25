#include <stdio.h>
#include <string.h>

int main()
{
    struct { int a, b; } v1;
    struct { int a, b; } v2;
    struct { int a, b; }*pv;

    v1.a = 1;
    v1.b = 2;

    v2 = v1;

    pv = &v2;

    return 0;
}

