#include <stdio.h>

int main()
{
    int sum = 0;
    int i = 1;

    while( i <= 100 )
    {
        sum = sum + i;
        i = i + 1;
    }

    printf("sum = %d\n", sum);
    printf("i = %d\n", i);

    return 0;
}
