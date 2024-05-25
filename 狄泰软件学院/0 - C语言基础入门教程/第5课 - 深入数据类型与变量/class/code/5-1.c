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

    b = a;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("\n");

    b = 30000;
    a = b;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("\n");
    printf("\n");

    printf("i = %d\n", i);
    printf("f = %f\n", f);
    printf("\n");

    f = 3.14f;
    i = f;

    printf("i = %d\n", i);
    printf("f = %f\n", f);

    return 0;
}
