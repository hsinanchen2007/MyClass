#include <stdio.h>

int main()
{
    int a = 50000;
    short b = 0;

    int i = 0;
    float f = 0.2;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("\n");

    // a is int, b is short, max value of b is 32767, overflow
    b = a;

    printf("a = %d\n", a);
    printf("b = %d\n", b);  // -15536, unexpected
    printf("\n");

    // b = 30000, smaller than its max value, now it's ok
    b = 30000;
    a = b;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("\n");
    printf("\n");

    printf("i = %d\n", i);
    printf("f = %f\n", f);
    printf("\n");

    // assign float to int, the 0.14 is be gone 
    f = 3.14f;
    i = f;

    printf("i = %d\n", i);
    printf("f = %f\n", f);

    return 0;
}
