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

    // array passed to function is already lost its size
    // it has only array pointer (first element address)
    printf("sizeof(a[]) = %d, %p, %p\n", sizeof(a), &(a[0]), a);

    // now, change the first element of array to 999
    a[0] = 999;

    return ret;
}

int main()
{
    int arr1[10] = {0, 1, 2, 3, 4};      // arr1[0] -> 0
    int arr2[10] = {0, 10, 20, 30, 40}; // arr2[0] -> 0

    demo(arr1);
    demo(arr2);

    printf("arr1[0] = %d\n", arr1[0]);          // arr1[0] = 50
    printf("arr2[0] = %d\n", arr2[0]);          // arr2[0] = 50

    printf("sum(arr1) = %d, first element now is %d\n", sum(arr1, 10), arr1[0]);   
                                                // note below sizeof(a) is always 4, no matter
                                                // how many elements in the given array
                                                // address of a and &a[0] are same
                                                // sizeof(a[]) = 4, 0055FE58, 0055FE58
                                                // sum(arr1) = 60, first element now is 50

    printf("sum(arr2) = %d, first element now is %d\n", sum(arr2, 10), arr2[0]);  
                                                // note below sizeof(a) is always 4, no matter
                                                // how many elements in the given array
                                                // address of a and &a[0] are same
                                                // sizeof(a[]) = 4, 0055FE30, 0055FE30
                                                // sum(arr2) = 150, first element now is 50

    // very interesting question. Above two output still show arr1[0]/arr2[0] as 50
    // but below two now show 999
    // https://stackoverflow.com/questions/54560843/what-is-the-order-of-excecution-of-printf-parameters
    printf("arr1[0] = %d\n", arr1[0]);          // arr1[0] = 999
    printf("arr2[0] = %d\n", arr2[0]);          // arr2[0] = 999

    return 0;
}
