#include <stdio.h>

int Min(int a[], int b, int e)
{
    int r = b;
    int i = 0;

    for(i=b; i<=e; i++)
        if( a[r] > a[i] )
            r = i;

    return r;
}

void Sort(int a[], int n)
{
    int i = 0;
    int j = 0;
    int k = 0;

    for(i=0; i<n; i++)
    {
        j = Min(a, i, n-1);

        if( i != j )
        {
            k = a[i];
            a[i] = a[j];
            a[j] = k;
        }
    }
}

void Print(int a[], int n)
{
    int i = 0;

    while( i < n )
        printf("%d ", a[i++]);

    printf("\n");
}

int main()
{
    int a[5] = {20, 30, 10, 40, 50};

    printf("Origin: \n");

    Print(a, 5);

    Sort(a, 5);

    printf("After: \n");

    Print(a, 5);

    return 0;
}
