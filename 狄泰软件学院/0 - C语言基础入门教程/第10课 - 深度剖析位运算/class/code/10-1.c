#include <stdio.h>

int main()
{
    short a = 1;
    short b = 2;
    int c = a - b;

    printf("c = %d\n", c);          // -1

    // 1001 >> 4 = 1100 -> 1110 -> 1111 -> 1111
    c = c >> 4;

    printf("c = %d\n", c);          // -1

    c = c * -1 * 16 >> 4;

    printf("c = %d\n", c);          // 1

    printf("c = %d\n", 16 << 2);    // 64

    return 0;
}
