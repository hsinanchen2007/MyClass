#include <stdio.h>

int sum (int n)
{
    int r = 0;
    int i = 0;

    for(i=1; i<=n; i++)
    {
        r += i;
    }

    return r;
}

int main()
{
    int o[10] = {10, 20, 30, 40, 50, 100};
    int r[10];
    int i = 0;

    for(i=0; i<10; i++)
    {
        r[i] = sum(o[i]);
    }

    for(i=0; i<10; i++)
    {
        printf("sum(%d) = %d\n", o[i], r[i]);
    }

    return 0;
}
