#include <stdio.h>

int demo(int arr[], int len)  // int demo(int* arr, int len)
{
    int ret = 0;
    int i = 0;

    printf("demo: sizeof(arr) = %d\n", sizeof(arr));

    while( i < len )
    {
        ret += *arr++;

        i++;
    }

    return ret;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};

    // int v = *a++;

    printf("return value: %d\n", demo(a, 5));

    return 0;
}
