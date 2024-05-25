#include <stdio.h>

int main()
{
    long l = -1l;
    long long ll = 21474836481ll;

    printf("l = %ld\n", l);
    printf("sizeof(long) = %d\n", sizeof(long));

    printf("ll = %lld\n", ll);
    printf("sizeof(long long) = %d\n", sizeof ll);

    return 0;
}
