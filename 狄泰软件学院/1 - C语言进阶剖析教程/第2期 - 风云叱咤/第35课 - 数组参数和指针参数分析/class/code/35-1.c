#include <stdio.h>

void access(int a[][3], int row)
{
    int col = sizeof(*a) / sizeof(int);
    int i = 0;
    int j = 0;
    
    printf("sizeof(a) = %d\n", sizeof(a));
    printf("sizeof(*a) = %d\n", sizeof(*a));
    
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%d\n", a[i][j]);
        }
    }
    
    printf("\n");
}

void access_ex(int b[][2][3], int n)
{
    int i = 0;
    int j = 0;
    int k = 0;
    
    printf("sizeof(b) = %d\n", sizeof(b));
    printf("sizeof(*b) = %d\n", sizeof(*b));
    
    for(i=0; i<n; i++)
    {
        for(j=0; j<2; j++)
        {
            for(k=0; k<3; k++)
            {
                printf("%d\n", b[i][j][k]);
            }
        }
    }
    
    printf("\n");
}

int main()
{
    int a[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    int aa[2][2] = {0};
    int b[1][2][3] = {0};
    
    access(a, 3);
    access(aa, 2);
    access_ex(b, 1);
    access_ex(aa, 2);
    
    return 0;
}

