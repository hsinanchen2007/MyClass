#include <stdio.h>

int main()
{
    int sum = 0;
    int i = 1;

    for(; i <= 100; )
    {
        sum = sum + i;
        i = i + 1;
    }

    printf("sum = %d\n", sum);

    return 0;
}
