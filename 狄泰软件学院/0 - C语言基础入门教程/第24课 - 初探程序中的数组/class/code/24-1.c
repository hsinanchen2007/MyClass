#include <stdio.h>

int main()
{
    int n = 0;
    int i = 0;
    int flag = 0;
    int sum = 0;

    do
    {
        printf("Input: ");

        scanf("%d", &n);

        flag = ((0 <= n) && (n <= 100));

        if( flag )
        {
            sum = 0;

            for(i=0; i<=n; i++)
            {
                sum += i;
            }

            printf("Sum = %d\n", sum);
        }
    } while( flag );

    return 0;
}
