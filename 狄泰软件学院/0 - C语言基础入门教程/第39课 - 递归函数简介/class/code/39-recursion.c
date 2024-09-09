#include <stdio.h>

int sum(int n)
{
    int ret = 0;

    if( n == 1 )
        ret = 1;
    else
        ret = n + sum(n-1);

    return ret;
}

int fac(int n)
{
    int ret = 0;

    if( n == 1 )
        ret = 1;
    else if( n == 2 )
        ret = 1;
    else if( n >= 3 )
        ret = fac(n-1) + fac(n-2);
    else
        ret = -1;

    return ret;
}

int main()
{
    int i = 0;

    printf("sum(1) = %d\n", sum(1));        // sum(1) = 1
    printf("sum(10) = %d\n", sum(10));      // sum(10) = 55
    printf("sum(100) = %d\n", sum(100));    // sum(100) = 5050

    // 1, 1, 2, 3, 5, 8, 13, 21, 34, 55,
    for(i=1; i<=10; i++)
    {
        printf("%d, ", fac(i));
    }

    printf("\n");

    return 0;
}
