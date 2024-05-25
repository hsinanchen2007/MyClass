#include <stdio.h>

int main()
{
    short a = 1;
    short b = 2;
    int c = a - b;

    c = c >> 4;

    printf("c = %d\n", c);

    c = c * -1 * 16 >> 4;

    printf("c = %d\n", c);

    printf("c = %d\n", 16 << 2);

    return 0;
}
