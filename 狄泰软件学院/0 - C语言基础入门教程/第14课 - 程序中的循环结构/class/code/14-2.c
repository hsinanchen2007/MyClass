#include <stdio.h>

int main()
{
    int sum = 0;
    int i = 1;

    while( i <= 1000 )
    {
        if( (i % 3) == 0 )
        {
            sum = sum + i;

            printf("i = %d\n", i);
        }

        i = i + 1;
    }

    printf("sum = %d\n", sum);

    return 0;
}
