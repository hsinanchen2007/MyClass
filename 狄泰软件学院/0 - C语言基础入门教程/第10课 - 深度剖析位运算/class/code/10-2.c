#include <stdio.h>

int main()
{
    char c = 'A';
    short a = c;
    int b = c;

    printf("c = %c\n", c);
    printf("c = %d\n", c);
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    c = 0x40;

    printf("c = %x\n", c);
    printf("c = %d\n", c);

    c = c << 1;

    printf("c = %d\n", c);

    c = c << 1;

    printf("c = %d\n", c);

    return 0;
}
