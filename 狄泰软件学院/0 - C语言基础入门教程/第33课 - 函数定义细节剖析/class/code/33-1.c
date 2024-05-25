#include <stdio.h>

int pow2(int a);

int main()
{
    int a = 3;

    printf("call pow2(%d): %d\n", a, pow2(a));

    return 0;
}

int pow2(int a)
{
    return a * a;
}
