#include <stdio.h>

int main()
{
    extern int* a;
    
    printf("&a = %p\n", &a);
    printf("a = %p\n", a);
    printf("*a = %d\n", *a);

    
    return 0;
}
