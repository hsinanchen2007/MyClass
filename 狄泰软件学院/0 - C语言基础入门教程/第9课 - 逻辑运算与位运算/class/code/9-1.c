#include <stdio.h>

int main()
{
    int a = 1;
    int b = 2;
    int c = 0;

    c = a && b;

    printf("c = %d\n", c);

    c = !(a - b) || (c < b);

    printf("c = %d\n", c);

    c = 10000;
    c = !!c;

    printf("c = %d\n", c);

    return 0;
}
