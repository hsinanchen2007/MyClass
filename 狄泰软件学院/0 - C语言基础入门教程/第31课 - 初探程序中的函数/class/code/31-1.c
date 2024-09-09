#include <stdio.h>

int func_demo( int x )
{
    int y = 0;

    y = 2 * x  - 1;

    return y;
}

int main()
{
    int r1 = func_demo(1);
    int r2 = func_demo(5);
    int r3 = func_demo(10);

    printf("r1 = %d\n", r1);    // r1 = 1
    printf("r2 = %d\n", r2);    // r2 = 9
    printf("r3 = %d\n", r3);    // r3 = 19

    return 0;
}
