#include <stdio.h>

int main()
{
    unsigned char uc = 128;
    char c = 128;

    unsigned ui = 2147483648;
    signed i = 2147483648;

    printf("uc = %u\n", uc);
    printf("c = %d\n", c);

    printf("ui = %u\n", ui);
    printf("i = %d\n", i);

    return 0;
}
