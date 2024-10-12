#include <stdio.h>

int main()
{
    int a[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};

    printf("size of 2D array = %d\n", sizeof(a));       // size of 2D array = 36, 4 * 9 = 36
    printf("size of 1D array = %d\n", sizeof(*a));      // size of 1D array = 12. 4 * 3 = 12

    printf("address of 2D array = %p\n", a);            // address of 2D array = 006FFC00
    printf("address of 1D array = %p\n", *a);           // address of 2D array = 006FFC00
    printf("address of 1D array = %p\n", &(a[0][0]));   // address of 2D array = 006FFC00
    printf("address of 2D array = %p\n", &a);           // address of 2D array = 006FFC00

    return 0;
}