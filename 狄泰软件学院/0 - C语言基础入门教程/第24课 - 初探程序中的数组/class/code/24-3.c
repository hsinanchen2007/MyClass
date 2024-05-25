#include <stdio.h>

int main()
{
    int n = 0;
    int flag = 0;

    int sum[101];

    sum[0] = 0;

    for(n=1; n<=100; n++)
    {
        sum[n] = sum[n-1] + n;    // sum[1] = sum[0] + 1;
                                  // sum[2] = sum[1] + 2;
                                  // ......
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
