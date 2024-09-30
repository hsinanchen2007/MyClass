#include <stdio.h>

int main()
{
    int a[5] = {1, 2};
    int b[] = {1, 2};
    
    printf("a[2] = %d\n", a[2]);    // a[2] = 0
    printf("a[3] = %d\n", a[3]);    // a[3] = 0
    printf("a[4] = %d\n", a[4]);    // a[4] = 0
    
    printf("sizeof(a) = %d\n", sizeof(a));  // sizeof(a) = 20
    printf("sizeof(b) = %d\n", sizeof(b));  // sizeof(b) = 8 
    printf("count for a: %d\n", sizeof(a)/sizeof(int)); // count for a: 5
    printf("count for b: %d\n", sizeof(b)/sizeof(int)); // count for b: 2
    
    return 0;
}
