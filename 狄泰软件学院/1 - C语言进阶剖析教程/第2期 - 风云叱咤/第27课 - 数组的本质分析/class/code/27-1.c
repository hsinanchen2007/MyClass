#include <stdio.h>

int main()
{
    int a[5] = {1, 2};
    int b[] = {1, 2};
    
    printf("a[2] = %d\n", a[2]);
    printf("a[3] = %d\n", a[3]);
    printf("a[4] = %d\n", a[4]);
    
    printf("sizeof(a) = %d\n", sizeof(a));
    printf("sizeof(b) = %d\n", sizeof(b));
    printf("count for a: %d\n", sizeof(a)/sizeof(int));
    printf("count for b: %d\n", sizeof(b)/sizeof(int));
    
    return 0;
}
