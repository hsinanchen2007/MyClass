#include <stdio.h>

int main()
{
    int a[10] = {0};            // int[10]
    int b[5] = {1, 2, 3, 4, 5}; // int[5]
    int i = 0;

    printf("sizeof(int[5]) = %d\n", sizeof(int[5]));
    printf("sizeof(int[10]) = %d\n", sizeof(int[10]));
    printf("sizeof(a) = %d\n", sizeof a);

    for(i=0; i<5; i++)
    {
        a[i] = b[i];
    }

    for(i=0; i<10; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }


    return 0;
}
