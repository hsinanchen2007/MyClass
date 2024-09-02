#include <stdio.h>

int main()
{
    int a = 50000;
    short b = 0;

    int i = 0;
    float f = 0.2;

    i = 40000;

    // b is short so its max is still 32767, 40000 is larger than its max value
    b = (short)i;

    printf("i = %d\n", i);
    printf("b = %d\n", b);
    printf("\n");

    // float to int
    f = 3.1415f;
    a = (int)f;

    printf("f = %f\n", f);
    printf("a = %d\n", a);

    return 0;
}
