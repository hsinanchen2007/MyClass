#include <stdio.h>

int main()
{
    int sum = 0;
    int i = 1;
    int an = 0;

    while( sum < 10000 )
    {
        an = (2*i) * (2*i);
        sum = sum + an;
        i = i + 1;
    }

    i = i - 1;

    printf("sum = %d\n", sum);
    printf("an = %d\n", an);
    printf("i = %d\n", i);

    return 0;
}
