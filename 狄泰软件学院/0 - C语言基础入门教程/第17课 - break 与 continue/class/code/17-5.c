#include <stdio.h>

int main()
{
    int i = 0;
    int n = 0;

    for(i=1; i<1000; i=i+1)
    {
        if( i % 7 )
            continue;

        printf("%d ", i);

        n = n + 1;
    }

    printf("\n");
    printf("Count: %d\n", n);

    return 0;
}
