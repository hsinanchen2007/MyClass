#include <stdio.h>

int main()
{
    int sum = 0;
    int i = 1;

    while( 1 )
    {
        sum = sum + i;

        if( i == 100 )
            break;

        i = i + 1;
    }

    printf("sum = %d\n", sum);
    printf("i = %d\n", i);

    return 0;
}
