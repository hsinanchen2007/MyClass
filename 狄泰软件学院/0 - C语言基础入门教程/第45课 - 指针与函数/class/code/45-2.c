#include <stdio.h>

int demo(int arr[], int len)  // int demo(int* arr, int len)
{
    int ret = 0;
    int i = 0;

    // when pass assary a[] to demo(), arr[] her becomes an integer pointer
    // so its size will be 4, lost its array size
    printf("demo: sizeof(arr) = %d\n", sizeof(arr));    // demo: sizeof(arr) = 4

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

    // before a[] is being passed to demo(), we can get array size as 20 
    // (int size 4 * 5 elements = 20 bytes)    
    printf("sizeof(a) = %d\n", sizeof(a));      // sizeof(a) = 20

    // int v = *a++;
    printf("return value: %d\n", demo(a, 5));   // return value: 15

    return 0;
}
