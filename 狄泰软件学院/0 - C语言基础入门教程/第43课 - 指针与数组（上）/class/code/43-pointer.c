#include <stdio.h>

int main()
{
    int a[] = {1, 2, 3, 4, 0};
    int* p = a;  // a ������Ϊ int*, &a[0] ==> int*
    int (*pa) [5] = &a;

    printf("%p, %p\n", p, a);       // 00AFFDDC, 00AFFDDC

    p++;

    *p = 100;  // a[1] = 100;

    printf("%d, %d\n", *p, a[1]);   // 100, 100
    printf("%p, %p\n", &a, a);      // 00AFFDDC, 00AFFDDC

    // '=': 'int *' differs in levels of indirection from 'int (*)[5]'cpp(C4047)
    p = pa;   // WARNING  !!!!

    p = a;

    // 1
    // 100
    // 3
    // 4
    while( *p )
    {
        printf("%d\n", *p);

        p++;
    }

    return 0;
}
