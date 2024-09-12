#include <stdio.h>
#include <string.h>

int main()
{
    struct { int a, b; } v1;
    struct { int a, b; } v2;
    struct { int a, b; }*pv;

    v1.a = 1;
    v1.b = 2;

    // ERROR: v1 and v2 are noname struct, they cannot assign to each other
    // v2 = v1;

    // ERROR: v2 and pv are also considered different type as they are noname struct
    // pv = &v2;

    return 0;
}

