#include <stdio.h>

void demo(int a[3])
{
    a[0] = 50;
}

int sum(int a[], int len)
{
    int ret = 0;
    int i = 0;

    while( i < len )
    {
        ret += a[i];
        i++;
    }

    return ret;
}

int main()
{
    int arr1[5] = {0, 1, 2, 3, 4};      // arr1[0] -> 0
    int arr2[10] = {0, 10, 20, 30, 40}; // arr2[0] -> 0

    demo(arr1);
    demo(arr2);

    printf("arr1[0] = %d\n", arr1[0]);
    printf("arr2[0] = %d\n", arr2[0]);

    printf("sum(arr1) = %d\n", sum(arr1, 5));
    printf("sum(arr2) = %d\n", sum(arr2, 10));

    return 0;
}
