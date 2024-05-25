#include <stdio.h>

int test(int n);

int main()
{
    int i = 3;
    int j = test(i);

    printf("i = %d, j = %d\n", i, j);

    return 0;
}

int test(int n)
{
    n = n * 10;

    return n;
}
