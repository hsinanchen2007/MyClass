#include <stdio.h>

// macro is a preprocessor directive, not a function
// so when this macro is called, it will be replaced by the code in the macro
// so the values in the macro are not passed by value, but by reference
#define SWAP(a,b)      \
{                      \
    int temp = a;      \
    a = b;             \
    b = temp;          \
}

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    
    SWAP(a,b);
    
    printf("a = %d, b = %d\n", a, b);   // a = 2, b = 1
    
    SWAP(b,c);
    
    printf("b = %d, c = %d\n", b, c);   // b = 3, c = 1
    
    return 0;
}

