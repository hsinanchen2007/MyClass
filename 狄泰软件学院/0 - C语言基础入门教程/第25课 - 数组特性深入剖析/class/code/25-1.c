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

    // arr[1.5] = 15;   ERROR: array size must be integer
    // arr = a;         ERROR: arr name is const, cannot be changed

    for(i=0; i<len; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    return 0;
}
