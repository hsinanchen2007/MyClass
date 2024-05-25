#include <stdio.h>

int main()
{
    int a[3][3];
    int i = 0;
    int j = 0;

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("Input a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Matrix:\n");

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d    ", a[i][j]);
        }

        printf("\n");
    }

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if( i < j )
            {
                int t = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = t;
            }
        }
    }

    printf("Matrix-T:\n");

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d    ", a[i][j]);
        }

        printf("\n");
    }

    return 0;
}
