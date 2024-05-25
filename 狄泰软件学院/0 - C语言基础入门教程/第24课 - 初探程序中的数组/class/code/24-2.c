#include <stdio.h>

int main()
{
    int n = 0;
    int i = 0;
    int flag = 0;

    int sum[101];

    for(n=0; n<=100; n++)
    {
        sum[n] = 0;

        for(i=0; i<=n; i++)
        {
            sum[n] += i;
        }
    }

    do
    {
        printf("Input: ");

        scanf("%d", &n);

        flag = ((0 <= n) && (n <= 100));

        if( flag )
        {
            printf("Sum = %d\n", sum[n]);
        }
    } while( flag );

    return 0;
}
