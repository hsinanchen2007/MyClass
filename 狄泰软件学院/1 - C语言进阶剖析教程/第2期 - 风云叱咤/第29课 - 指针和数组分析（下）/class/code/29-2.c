// This example needed to compile with ext.c which has only one line:
// 
// int a[] = {1, 2, 3, 4, 5};
//
// 數組和指針不同，數組名是常量，不能被賦值，不能被修改 
#include <stdio.h>

int main()
{
    // use extern to declare a variable in another file
    // but below code will cause error because a is an array
    // while extern is used to declare a variable
    // extern int* a;

    // If we want to use extern to declare an array in another file,
    // we should use below code
    // extern int a[];
    
    int a[10];

    printf("&a = %p\n", &a);
    printf("a = %p\n", a);
    printf("*a = %d\n", *a);

    return 0;
}
