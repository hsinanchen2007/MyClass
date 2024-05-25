#include <stdio.h>

int main()
{
    short s = 32767;
    int i = 2147483647;

    short ss = -32768;
    int ii = -2147483648;

    printf("s = %d\n", s);
    printf("i = %d\n", i);

    s = s + 1;
    i = i + 1;

    printf("s = %d\n", s);
    printf("i = %d\n", i);

    printf("ss = %d\n", ss);
    printf("ii = %d\n", ii);

    ss = ss - 1;
    ii = ii - 1;

    printf("ss = %d\n", ss);
    printf("ii = %d\n", ii);

    return 0;
}
