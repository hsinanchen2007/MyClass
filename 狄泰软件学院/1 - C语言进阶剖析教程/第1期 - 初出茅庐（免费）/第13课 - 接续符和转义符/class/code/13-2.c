#include <stdio.h>

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
    
    printf("a = %d, b = %d\n", a, b);
    
    SWAP(b,c);
    
    printf("b = %d, c = %d\n", b, c);
    
    return 0;
}

