#include <stdio.h>

#define size 8
int a[size];

int main()
{
    int arr[] = { 5, 4, 3, 2, 1 };
    int i = 0;
    int len = sizeof(arr)/sizeof(arr[0]);

    printf("sizeof(arr) = %d\n", sizeof(arr));
    printf("len(arr) = %d\n", len);

    // arr[1.5] = 15;
    // arr = a;

    for(i=0; i<len; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    return 0;
}
