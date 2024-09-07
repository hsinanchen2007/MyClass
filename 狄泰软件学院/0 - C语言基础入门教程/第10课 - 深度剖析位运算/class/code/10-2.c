#include <stdio.h>

int main()
{
    char c = 'A';
    short a = c;
    int b = c;

    printf("c = %c\n", c);  // A
    printf("c = %d\n", c);  // 65
    printf("a = %d\n", a);  // 65
    printf("b = %d\n", b);  // 65

    c = 0x40;

    printf("c = %x\n", c);  // 40
    printf("c = %d\n", c);  // 64

    // char's range is -128 ~ 127, as the "c << 1" will become 128, which is over its char range
    // so the value will become -128 instead
    c = c << 1;

    printf("c = %d\n", c);  // -128

    c = c << 1;

    printf("c = %d\n", c);  // 0

    return 0;
}
