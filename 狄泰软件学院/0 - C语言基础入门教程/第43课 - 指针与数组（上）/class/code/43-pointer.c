#include <stdio.h>

int main()
{
    int a[] = {1, 2, 3, 4, 0};
    int* p = a;  // a 的类型为 int*, &a[0] ==> int*
    int (*pa) [5] = &a;

    printf("%p, %p\n", p, a);

    p++;

    *p = 100;  // a[1] = 100;

    printf("%d, %d\n", *p, a[1]);
    printf("%p, %p\n", &a, a);

    p = pa;   // WARNING  !!!!

    p = a;

    while( *p )
    {
        printf("%d\n", *p);

        p++;
    }

    return 0;
}
