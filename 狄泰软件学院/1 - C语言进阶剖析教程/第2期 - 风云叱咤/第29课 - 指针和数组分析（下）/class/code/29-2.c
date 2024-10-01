#include <stdio.h>

// Or, need to compile with ext.c file together
// so we can use extern int *a to declare it

int main()
{
    // use extern to declare a variable in another file
    // but below code will cause error because a is an array
    // while extern is used to declare a variable
    // extern int* a;
    
    int a[10];

    printf("&a = %p\n", &a);
    printf("a = %p\n", a);
    printf("*a = %d\n", *a);

    return 0;
}
