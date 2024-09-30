#include <stdio.h>

int main()
{
    int a[5] = { 0 };

    printf("a = %p\n", a);          // a = 012FFD2C
    printf("&a = %p\n", &a);        // &a = 012FFD2C
    printf("&a[0] = %p\n", &a[0]);  // &a[0] = 012FFD2C
    
    return 0;
}
