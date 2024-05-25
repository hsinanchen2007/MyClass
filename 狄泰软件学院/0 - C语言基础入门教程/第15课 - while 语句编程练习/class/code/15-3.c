#include <stdio.h>

int main()
{
    int i = 2;

    while( i <= 100 )
    {
        int flag = 0;
        int j = 2;

        while( j < i )
        {
            if( i%j == 0 )
            {
                flag = flag + 1;
            }

            j = j + 1;
        }

        if( flag == 0 )
        {
            printf("%d, ", i);
        }

        i = i + 1;
    }

    printf("\n");

    return 0;
}
