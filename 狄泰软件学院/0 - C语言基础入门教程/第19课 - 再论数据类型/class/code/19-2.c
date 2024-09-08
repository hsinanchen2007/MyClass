#include <stdio.h>

int main()
{
    long l = -1l;
    long long ll = 21474836481ll;

    printf("l = %ld\n", l);     // l = -1
    printf("sizeof(long) = %d\n", sizeof(long));    // sizeof(long) = 4

    printf("ll = %lld\n", ll);  // ll = 21474836481
    printf("sizeof(long long) = %d\n", sizeof ll);  // sizeof(long long) = 8

    return 0;
}
